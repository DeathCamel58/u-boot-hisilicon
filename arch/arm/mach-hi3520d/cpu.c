#include <common.h>
#include <soc.h>
#include <asm/io.h>
#include <asm/arch/platform.h>
#include <dm.h>

#if CONFIG_DISPLAY_CPUINFO
int print_cpuinfo(void)
{
    struct udevice *soc;
    char name[64];
    int ret;

    printf("SoC:   ");

    ret = soc_get(&soc);
    if (ret) {
        printf("UNKNOWN: Device Tree Error: %d\n", ret);
        return 0;
    }

    ret = soc_get_family(soc, name, 64);
    if (!ret) {
        printf("%s ", name);
    }

    ret = soc_get_revision(soc, name, 64);
    if (!ret) {
        printf("%s ", name);
    }

    printf("\n");

    return 0;
}
#endif
