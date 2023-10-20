#include <config.h>
#include <common.h>
#include <asm/io.h>
#include <linux/sizes.h>
#include <asm/arch/platform.h>
#include <asm/global_data.h>
#include <asm/mach-types.h>

DECLARE_GLOBAL_DATA_PTR;

#if defined(CONFIG_SHOW_BOOT_PROGRESS)
void show_boot_progress(int progress)
{
	printf("Boot reached stage %d\n", progress);
}
#endif

#define COMP_MODE_ENABLE ((unsigned int)0x0000EAEF)

/*
 * Miscellaneous platform dependent initialisations
 */
int board_init(void)
{
	unsigned long reg;
	/* set uart clk from apb bus */
	reg = readl(CRG_REG_BASE + PERI_CRG57);
	reg &= ~UART_CKSEL_APB;
	writel(reg, CRG_REG_BASE + PERI_CRG57);

	DECLARE_GLOBAL_DATA_PTR;

	gd->bd->bi_arch_number = MACH_TYPE_HI3520D;
	gd->bd->bi_boot_params = CFG_BOOT_PARAMS;
	gd->flags = 0;

	return 0;
}

int misc_init_r(void)
{
#ifdef CONFIG_RANDOM_ETHADDR
	random_init_r();
#endif
//	setenv("verify", "n");

#ifdef CONFIG_AUTO_UPDATE
	extern int do_auto_update(void);
#ifdef CFG_MMU_HANDLEOK
	dcache_stop();
#endif
	do_auto_update();
#ifdef CFG_MMU_HANDLEOK
	dcache_start();
#endif
#endif

	return 0;

}

int dram_init(void)
{
    gd->ram_size = get_ram_size((void *)PHYS_SDRAM, SZ_1G);
    gd->bd->bi_dram[0].start = PHYS_SDRAM;
    gd->bd->bi_dram[0].size = gd->ram_size;

	return 0;
}

int dram_init_banksize(void)
{
    gd->bd->bi_dram[0].start = PHYS_SDRAM;
    gd->bd->bi_dram[0].size = gd->ram_size;

    return 0;
}
