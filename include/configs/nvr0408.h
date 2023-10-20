
/*
 * (C) Copyright 2009, HISILICON
 * Configuration settings for the hi3520d board.
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __CONFIG_HI3520D_H__
#define __CONFIG_HI3520D_H__

#include <asm/arch/platform.h>

/* cpu_init configuration */
/* if bit[3:2] = 11b, A9 : AXI = 1 : 1 *
 * else, A9 : AXI = 2 : 1 */
#define HW_REG(a) (*(unsigned long *)(a))
#define A9_AXI_SCALE_REG   0x20030028
#define get_bus_clk()({\
	unsigned long fbdiv, pstdiv1, pstdiv2, refdiv; \
	unsigned long tmp_reg, foutvco, busclk;\
	tmp_reg = HW_REG(REG_CRG0_OFFSET);\
	pstdiv1 = (tmp_reg >> 24) & 0x7;\
	pstdiv2 = (tmp_reg >> 27) & 0x7;\
	tmp_reg = HW_REG(REG_CRG1_OFFSET);\
	refdiv = (tmp_reg >> 12) & 0x3f;\
	fbdiv = tmp_reg & 0xfff;\
	foutvco = 24000000/refdiv;\
	foutvco *= fbdiv;\
	tmp_reg = HW_REG(A9_AXI_SCALE_REG);\
	if ((tmp_reg & 0xc) == 0xc) {\
		busclk = foutvco/2;\
	} else \
		busclk = foutvco/4;\
	busclk;\
})

/* cpu_init configuration */
#define CFG_CLK_BUS  get_bus_clk()
#define CFG_TIMER_PER 4		/* AXI:APB is 4:1 */
#define CFG_TIMER_CLK (CFG_CLK_BUS/CFG_TIMER_PER)

#define CONFIG_HI3520D		1

/*-----------------------------------------------------------------------
 * SPI Flash Configuration
 -----------------------------------------------------------------------*/
//#define CONFIG_CMD_SF				/* sf read\sf write\sf erase */
#define CONFIG_SPI_FLASH_HISFC350		1
#ifdef CONFIG_SPI_FLASH_HISFC350
#define CONFIG_HISFC350_BUFFER_BASE_ADDRESS	SFC_MEM_BASE
#define CONFIG_HISFC350_REG_BASE_ADDRESS	SFC_REG_BASE
#define CONFIG_HISFC350_PERIPHERY_REGBASE	CRG_REG_BASE
#define CONFIG_HISFC350_CHIP_NUM		2
#endif /* CONFIG_SPI_FLASH_HISFC350 */
/*-----------------------------------------------------------------------
 * for cpu/arm_cortexa9/start.S
 -----------------------------------------------------------------------*/
#define PHYS_SDRAM					DDR_MEM_BASE
#define PHYS_SDRAM_SIZE				SZ_1G

/*
 * Definitions for initial stack pointer and data area (in DPRAM)
 */
//#define CFG_SYS_INIT_RAM_ADDR DDR_MEM_BASE
#define CFG_SYS_SDRAM_BASE		PHYS_SDRAM
#define CFG_SYS_INIT_RAM_ADDR 0x81000000
//#define CFG_SYS_INIT_RAM_ADDR 0x04011000
#define CFG_SYS_INIT_RAM_SIZE		0x4000	/* Size of used area in internal SRAM */
#define CFG_SYS_INIT_SP_OFFSET	(CFG_SYS_INIT_RAM_SIZE - GENERATED_GBL_DATA_SIZE)

/*-----------------------------------------------------------------------
 * for timer configuration (udelay)	cpu/hi3520d/hi3520d/timer.c
*  enable timer				board/hi3520d/board.c
 -----------------------------------------------------------------------*/
#define CFG_SYS_TIMERBASE           TIMER0_REG_BASE
/* enable timer.32bit, periodic,mask irq,256 divider. */
#define CFG_TIMER_CTRL		0xCA
#define READ_TIMER		(*(volatile unsigned long *)\
					(CFG_TIMERBASE + REG_TIMER_VALUE))
/* how many ticks per second. show the precision of timer. */
#define CFG_SYS_HZ_CLOCK           (CFG_TIMER_CLK/256)
#define CFG_HZ			CFG_SYS_HZ_CLOCK

/*-----------------------------------------------------------------------
 * environment && bd_info  && global_data  configure
*     used in file
-----------------------------------------------------------------------*/
/* kernel parameter list phy addr */
#define CFG_BOOT_PARAMS			(PHYS_SDRAM+0x0100)

/*-----------------------------------------------------------------------
 *  Environment   Configuration
 ------------------------------------------------------------------------*/
#define CONFIG_BOOTARGS "mem=96M console=ttyAMA0,115200"
#define CONFIG_ETHADDR  00:00:23:34:45:66
/*-----------------------------------------------------------------------
 * for bootm linux
*  used in file  board/hi3520d/board.c
 -----------------------------------------------------------------------*/

#define CONFIG_ZERO_BOOTDELAY_CHECK 1   /*use ^c to interrupt*/
/*-----------------------------------------------------------------------
 * for  commond configure
 -----------------------------------------------------------------------*/

/* do_printenv  do_setenv common/cmd_nvedit.c */
#define CONFIG_SYS_BAUDRATE_TABLE { 9600, 19200, 38400, 57600, 115200 }

/*-----------------------------------------------------------------------
 * HIETH driver
 -----------------------------------------------------------------------*/
/* default is hieth-switch-fabric */
#define CONFIG_NET_HISFV300
#ifdef CONFIG_NET_HISFV300
	#define CONFIG_NET_HISFV300_HI3520D	1
	#define INNER_PHY
	#define INNER_PHY_ADDR_U		3
	#define INNER_PHY_ADDR_D		2
	#define HISFV_MII_MODE			0
	#define HISFV_RMII_MODE			1
	/* hi3520d support inner phy,  we can use both inner phy and phy
	 * on board. if we use inner phy, we must set it MII_MODE. if we use
	 * the phy on board, we set it default RMII_MODE.*/
	#define HIETH_MII_RMII_MODE_U		HISFV_MII_MODE
	#define HIETH_MII_RMII_MODE_D		HISFV_MII_MODE
	/* ETH phyid is 0x1, FE phy phyid is 3 which we set sysctl reg */
	#define HISFV_PHY_U			1
	#define HISFV_PHY_D			0
	#define HISFV_RESET_GPIO_EN /* hi3520d use it */
	#ifdef HISFV_RESET_GPIO_EN
		/* use gpio5_5 to control sfv reset */
		#define HISFV_RESET_GPIO_BASE	GPIO5_REG_BASE
		#define HISFV_RESET_GPIO_DIR	0x400
		#define HISFV_RESET_GPIO_BIT	5
		#define HISFV_RESET_GPIO_DIR_OUT 1
		/* 0-reset; 1-undo reset */
		#define HISFV_RESET_GPIO_DATA	0
	#endif /* HISFV_RESET_GPIO_EN */
#endif /* CONFIG_NET_HISFV300 */

/* no nor flash */
#define CONFIG_SYS_NO_FLASH

/*-----------------------------------------------------------------------
 * console display  Configuration
 ------------------------------------------------------------------------*/

#define CONFIG_VERSION_VARIABLE  1 /*used in common/main.c*/

#define CFG_BARGSIZE    CFG_CBSIZE      /* Boot Argument Buffer Size */
#undef  CFG_CLKS_IN_HZ              /* everything, incl board info, in Hz */
/* default load address */
#define CFG_LOAD_ADDR   (CFG_DDR_PHYS_OFFSET + 0x08000)
#define CFG_DDR_PHYS_OFFSET PHYS_SDRAM
#define CFG_DDR_SIZE		(256*1024*1024)

#define CONFIG_SYS_MEMTEST_START       \
	(CFG_DDR_PHYS_OFFSET + \
	sizeof(unsigned long))
#define CONFIG_SYS_MEMTEST_END         (CFG_DDR_PHYS_OFFSET + CFG_DDR_SIZE)
#define CONFIG_SYS_MEMTEST_SCRATCH     CFG_DDR_PHYS_OFFSET

#define CONFIG_CMDLINE_TAG      1   /* enable passing of ATAGs  */
#define CONFIG_INITRD_TAG       1   /* support initrd */
#define CONFIG_SETUP_MEMORY_TAGS    1
#define CONFIG_MISC_INIT_R      1   /* call misc_init_r during start up */

#undef CONFIG_SPIID_TAG

/* serial driver */
#define CONFIG_PL011_SERIAL 1

/* due to bootrom, hi3520d use APB bus clock
 * UART is on APB, and AXI : APB is 4 : 1, so
 * we set UART clock 1/4 AXI bus_clk, but default
 * is 2MHz. */
#define CONFIG_PL011_CLOCK	(CFG_CLK_BUS/4)
#define CONFIG_PL01x_PORTS	\
	{(void *)UART0_REG_BASE, (void *)UART1_REG_BASE, \
	(void *)UART2_REG_BASE, (void *)UART3_REG_BASE}
#define CONFIG_CONS_INDEX	0

/*-----------------------------------------------------------------------
 * bootrom Configuration
 -----------------------------------------------------------------------*/
#define CONFIG_BOOTROM_SUPPORT
#if defined(CONFIG_BOOTROM_SUPPORT) \
	&& (!defined(REG_START_FLAG) || !defined(CONFIG_START_MAGIC))
#  error Please define CONFIG_START_MAGIC and CONFIG_START_MAGIC first
#endif

#define __LITTLE_ENDIAN				1
//#define CONFIG_DOS_PARTITION			1

//#define CONFIG_CMD_FAT				1
//#define CONFIG_CMD_EXT2				1

/*-----------------------------------------------------------------------
 * usb
 * ----------------------------------------------------------------------*/
//#define CONFIG_CMD_USB			1
//#define CONFIG_USB_OHCI			1 /* FIXME: CONFIG_USB_OHCI_NEW */
//#define CONFIG_USB_STORAGE		1
//#define CONFIG_LEGACY_USB_INIT_SEQ

/*-----------------------------------------------------------------------
 * DDR Training
 * ----------------------------------------------------------------------*/
/*#define CONFIG_DDR_GATE_TRAINING*/

#define CONFIG_DDR_TRAINING_V200
#ifdef CONFIG_DDR_TRAINING_V200
#define DDRT_ENABLE_BYTE_TRAINING
#define DDRT_ENABLE_BIT_TRAINING

#endif

#define CONFIG_OSD_ENABLE
#endif	/* __CONFIG_H */
