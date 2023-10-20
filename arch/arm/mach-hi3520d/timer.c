/*
 * (C) Copyright 2003
 * Texas Instruments <www.ti.com>
 *
 * (C) Copyright 2002
 * Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Marius Groeger <mgroeger@sysgo.de>
 *
 * (C) Copyright 2002
 * Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Alex Zuepke <azu@sysgo.de>
 *
 * (C) Copyright 2002-2004
 * Gary Jennejohn, DENX Software Engineering, <gj@denx.de>
 *
 * (C) Copyright 2004
 * Philippe Robin, ARM Ltd. <philippe.robin@arm.com>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

// This file seems to have been based on arch/arm/cpu/arm926ejs/omap/timer.c
// TODO: This may be able to be moved into the armv7 generic timer

#include <common.h>
#include <asm/proc-armv/ptrace.h>
#include <asm/arch/platform.h>
#include <asm/io.h>

#define TIMER_LOAD_VAL 0xffffffff

/* macro to read the 32 bit timer */
#define READ_TIMER (*(volatile ulong *)(CFG_SYS_TIMERBASE+4))

static ulong timestamp;
static ulong lastdec;


int timer_init(void)
{
    /*enable the reference clk. but we did not  find  the reset switch*/
    __raw_writel(__raw_readl(SYS_CTRL_REG_BASE + REG_SC_CTRL) |
                 (1<<16) | (1<<18) | (1<<20),
                 SYS_CTRL_REG_BASE + REG_SC_CTRL);

    /*
     *Under uboot, 0xffffffff is set to load register,
     * timer_clk = BUSCLK/2/256.
     * e.g. BUSCLK = 50M, it will roll back after 0xffffffff/timer_clk
     * = 43980s = 12hours
     */
    /* Start the decrementer ticking down from 0xffffffff */
    *((int32_t *) (CFG_SYS_TIMERBASE + REG_TIMER_CONTROL)) = 0;
    *((int32_t *) (CFG_SYS_TIMERBASE + REG_TIMER_RELOAD)) = ~0;

    /*32 bit, periodic,  256 divider.*/
    *((int32_t *) (CFG_SYS_TIMERBASE + REG_TIMER_CONTROL)) = CFG_TIMER_CTRL;

    /* init the timestamp and lastdec value */
    reset_timer_masked();

    return 0;
}

/*
 * timer without interrupts
 */
void reset_timer(void)
{
    reset_timer_masked();
}

ulong get_timer(ulong base)
{
    return get_timer_masked() - base;
}

void set_timer(ulong t)
{
    timestamp = t;
}

/* delay x useconds AND preserve advance timestamp value */
void __udelay(unsigned long usec)
{
    ulong tmo, tmp;

    if(usec >= 1000){		/* if "big" number, spread normalization to seconds */
        tmo = usec / 1000;	/* start to normalize for usec to ticks per sec */
        tmo *= CFG_SYS_HZ_CLOCK;	/* find number of "ticks" to wait to achieve target */
        tmo /= 1000;		/* finish normalize. */
    } else {
        /* else small number, don't kill it prior to HZ multiply */
        tmo = usec * CFG_SYS_HZ_CLOCK;
        tmo /= (1000 * 1000);
    }

    tmp = get_timer(0);		/* get current timestamp */
    if( (tmo + tmp + 1) < tmp )	/* if setting this fordward will roll time stamp */
        reset_timer_masked ();	/* reset "advancing" timestamp to 0, set lastdec value */
    else
        tmo += tmp;		/* else, set advancing stamp wakeup time */

    while (get_timer_masked () < tmo)/* loop till event */
        /*NOP*/;
}

void reset_timer_masked(void)
{
    /* reset time */
    lastdec = READ_TIMER;  /* capure current decrementer value time */
    timestamp = 0;	       /* start "advancing" time stamp from 0 */
}

ulong get_timer_masked(void)
{
    ulong now = READ_TIMER;		/* current tick value */

    if (lastdec >= now) {		/* normal mode (non roll) */
        /* normal mode */
        timestamp += lastdec - now; /* move stamp fordward with absoulte diff ticks */
    } else {			/* we have overflow of the count down timer */
        /* nts = ts + ld + (TLV - now)
         * ts=old stamp, ld=time that passed before passing through -1
         * (TLV-now) amount of time after passing though -1
         * nts = new "advancing time stamp"...it could also roll and cause problems.
         */
        timestamp += lastdec + TIMER_LOAD_VAL - now;
    }
    lastdec = now;

    return timestamp;
}

/* waits specified delay value and resets timestamp */
void udelay_masked(unsigned long usec)
{
    ulong tmo;
    ulong endtime;
    signed long diff;

    if (usec >= 1000) {		/* if "big" number, spread normalization to seconds */
        tmo = usec / 1000;	/* start to normalize for usec to ticks per sec */
        tmo *= CFG_SYS_HZ_CLOCK;		/* find number of "ticks" to wait to achieve target */
        tmo /= 1000;		/* finish normalize. */
    } else {			/* else small number, don't kill it prior to HZ multiply */
        tmo = usec * CFG_SYS_HZ_CLOCK;
        tmo /= (1000 * 1000);
    }

    endtime = get_timer_masked() + tmo;

    do {
        ulong now = get_timer_masked();
        diff = endtime - now;
    } while (diff >= 0);
}

/*
 * This function is derived from PowerPC code (read timebase as long long).
 * On ARM it just returns the timer value.
 */
unsigned long long get_ticks(void)
{
    return get_timer(0);
}

/*
 * This function is derived from PowerPC code (timebase clock frequency).
 * On ARM it returns the number of timer ticks per second.
 */
ulong get_tbclk(void)
{
    return CFG_SYS_HZ_CLOCK;
}
