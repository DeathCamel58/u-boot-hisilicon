#include <common.h>
#include <asm/io.h>

void sdelay(unsigned long loops)
{
    __asm__ volatile ("1:\n"
                      "subs %0, %1, #1\n"
                      "bne 1b" : "=r" (loops) : "0" (loops));
}
