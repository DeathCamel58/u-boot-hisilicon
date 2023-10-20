/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2015 Linaro
 * Peter Griffin <peter.griffin@linaro.org>
 */

#ifndef __ASM_ARM_ARCH_PERIPH_H
#define __ASM_ARM_ARCH_PERIPH_H

/*
 * Peripherals required for pinmux configuration. List will
 * grow with support for more devices getting added.
 * Numbering based on interrupt table.
 *
 */
enum periph_id {
    PERIPH_ID_SPI1,
    PERIPH_ID_SPI2,

    PERIPH_ID_NONE = -1,
};

#endif /* __ASM_ARM_ARCH_PERIPH_H */
