// The DDRC base address and size
#define DDRC_BASE 0x20110000
#define DDRC_SIZE 0x1000

// The DDRC registers and bit settings
#define DDRC_STATUS 0x0

#define DDRC_SREFCTRL 0x4

#define DDRC_INITCTRL 0x8

#define DDRC_CTRL 0x10

#define DDRC_EMRS01 0x14

#define DDRC_EMRS23 0x18

#define DDRC_CONFIG0 0x1c

#define DDRC_CONFIG1 0x20

#define DDRC_CMDCFG 0x24

#define DDRC_CMDEXE 0x28

#define DDRC_RNKCFG 0x2c

#define DDRC_BASEADDR 0x40

#define DDRC_TIMING0 0x50

#define DDRC_TIMING1 0x54

#define DDRC_TIMING2 0x58

#define DDRC_TIMING3 0x5c

#define DDRC_DTRCTRL 0xac

#define DDRC_AXISTATUS 0xf0

#define DDRC_ODTCFG 0xf4

#define DDRC_QOSCFG0 0x100

#define DDRC_QOSCFG1 0x104

// DDRC_QOS 0x150 + ( 0x4 * id0s )

// DDRC_FLUX 0x200 + ( 0x4 * ports )

#define DDRC_TEST0 0x240

#define DDRC_TEST7 0x260

#define DDRC_TEST8 0x264

#define DDRC_TEST9 0x268

#define DDRC_TEST10 0x26c

#define DDRC_TEST12 0x280

#define DDRC_PHYSRST 0x400

#define DDRC_PHYSTATUS 0x404

#define DDRC_PHYCTRL 0x408

#define DDRC_PHY_REG1 0x800

#define DDRC_PHY_REG2 0x808
#define DDRC_PHY_REG2_CAL_START BIT(0)
#define DDRC_PHY_REG2_CAL_MODE BIT(1)
#define DDRC_PHY_REG2_PHY_MEM_DDR2 BIT(6)

#define DDRC_PHY_REG3 0x804
#define DDRC_PHY_REG3_BURST8 BIT(0)

#define DDRC_PHY_REG4 0x824

#define DDRC_PHY_REG4A 0x838
#define DDRC_PHY_REG4A_PHY_AL(_n) ((_n & 0x7) << 0 )
#define DDRC_PHY_REG4A_PHY_CL(_n) ((_n & 0x7) << 4 )

#define DDRC_PHY_REG4B 0x83c

#define DDRC_PHY_REG6 0x8d4
#define DDRC_PHY_REG6_PHY_LTXDQDLL_DLY(_n) ((_n & 0x3) << 0 )
#define DDRC_PHY_REG6_PHY_LTXDQDLL_EN BIT(3)
#define DDRC_PHY_REG6_PHY_LTXDQDLL_BYPH BIT(4)

#define DDRC_PHY_REG7 0x8d8

#define DDRC_PHY_REG8 0x8e0

#define DDRC_PHY_REG9 0x914
#define DDRC_PHY_REG9_PHY_RTXDQDLL_DLY(_n) ((_n & 0x3) << 0 )
#define DDRC_PHY_REG9_PHY_RTXDQDLL_EN BIT(3)
#define DDRC_PHY_REG9_PHY_RTXDQDLL_BYPH BIT(4)

#define DDRC_PHY_REG10 0x918

#define DDRC_PHY_REG11 0x920
#define DDRC_PHY_REG11_PHY_RRXDQSDLL_DLY(_n) ((_n & 0x1) << 0)
#define DDRC_PHY_REG11_PHY_RRXDQSDLL_EN BIT(2)
#define DDRC_PHY_REG11_PHY_RDQSSQDLL_DLY(_n) ((_n & 0x3) << 3)
#define DDRC_PHY_REG11_PHY_RDQSSQDLL_EN BIT(6)

#define DDRC_PHY_REG12 0x840
#define DDRC_PHY_REG12_PHY_CMD0PD_STR(_n) ((_n & 0x7) << 0 )
#define DDRC_PHY_REG12_PHY_CMD0PU_STR(_n) ((_n & 0x7) << 4 )

#define DDRC_PHY_REG13 0x844
#define DDRC_PHY_REG13_PHY_CMD0FSL(_n) ((_n & 0x7) << 0 )
#define DDRC_PHY_REG13_PHY_CMD0RSL(_n) ((_n & 0x7) << 4 )

#define DDRC_PHY_REG14 0x848
#define DDRC_PHY_REG14_PHY_CMD0PD_MSB BIT(0)
#define DDRC_PHY_REG14_PHY_CMD0PU_MSB BIT(1)
#define DDRC_PHY_REG14_PHY_CMD0_PD BIT(2)
#define DDRC_PHY_REG14_PHY_CMD0_PU BIT(3)
#define DDRC_PHY_REG14_PHY_RSTN_PD BIT(4)
#define DDRC_PHY_REG14_PHY_RSTN_PU BIT(5)
#define DDRC_PHY_REG14_PHY_CMD0DLY_EN BIT(6)
#define DDRC_PHY_REG14_PHY_CMD0SDLL_LPEN BIT(7)

#define DDRC_PHY_REG15 0x84c

#define DDRC_PHY_REG16 0x854
#define DDRC_PHY_REG16_PHY_CMD1PD_STR(_n) ((_n & 0x7) << 0 )
#define DDRC_PHY_REG16_PHY_CMD1PU_STR(_n) ((_n & 0x7) << 4 )

#define DDRC_PHY_REG17 0x858
#define DDRC_PHY_REG17_PHY_CMD1FSL(_n) ((_n & 0x7) << 0 )
#define DDRC_PHY_REG17_PHY_CMD1RSL(_n) ((_n & 0x7) << 4 )

#define DDRC_PHY_REG18 0x85c
#define DDRC_PHY_REG18_PHY_CMD0PD_MSB BIT(0)
#define DDRC_PHY_REG18_PHY_CMD0PU_MSB BIT(1)
#define DDRC_PHY_REG18_PHY_CMD0_PD BIT(2)
#define DDRC_PHY_REG18_PHY_CMD0_PU BIT(3)
#define DDRC_PHY_REG18_PHY_RSTN_PD BIT(4)
#define DDRC_PHY_REG18_PHY_RSTN_PU BIT(5)
#define DDRC_PHY_REG18_PHY_CMD0DLY_EN BIT(6)
#define DDRC_PHY_REG18_PHY_CMD0SDLL_LPEN BIT(7)

#define DDRC_PHY_REG19 0x860

#define DDRC_PHY_REG20 0x864

#define DDRC_PHY_REG21 0x868

#define DDRC_PHY_REG22 0x870
#define DDRC_PHY_REG22_PHY_CKPD_STR(_n) ((_n & 0x7) << 0 )
#define DDRC_PHY_REG22_PHY_CKPU_STR(_n) ((_n & 0x7) << 4 )

#define DDRC_PHY_REG23 0x874
#define DDRC_PHY_REG23_PHY_CK_FSL(_n) ((_n & 0x7) << 0 )
#define DDRC_PHY_REG23_PHY_CK_RSL(_n) ((_n & 0x7) << 4 )

#define DDRC_PHY_REG24 0x878
#define DDRC_PHY_REG24_PHY_CKPD_MSB BIT(0)
#define DDRC_PHY_REG24_PHY_CKPU_MSB BIT(1)

#define DDRC_PHY_REG25 0x880
#define DDRC_PHY_REG22_PHY_DQPD_STR(_n) ((_n & 0x7) << 0 )
#define DDRC_PHY_REG22_PHY_DQPU_STR(_n) ((_n & 0x7) << 4 )

#define DDRC_PHY_REG26 0x884
#define DDRC_PHY_REG26_PHY_DQ_FSL(_n) ((_n & 0x7) << 0 )
#define DDRC_PHY_REG26_PHY_DQ_RSL(_n) ((_n & 0x7) << 4 )

#define DDRC_PHY_REG27 0x888
#define DDRC_PHY_REG27_PHY_DQPD_ODT(_n) ((_n & 0x3) << 0 )
#define DDRC_PHY_REG27_PHY_DQPU_ODT(_n) ((_n & 0x3) << 3 )

#define DDRC_PHY_REG28 0x88c
#define DDRC_PHY_REG28_PHY_DQPD_ODTMSB BIT(0)
#define DDRC_PHY_REG28_PHY_DQPU_ODTMSB BIT(1)
#define DDRC_PHY_REG28_PHY_DQPD_EN BIT(2)
#define DDRC_PHY_REG28_PHY_DQPU_EN BIT(3)
#define DDRC_PHY_REG28_PHY_DQPU_MSB BIT(4)
#define DDRC_PHY_REG28_PHY_DQPD_MSB BIT(5)

#define DDRC_PHY_REG29 0x9c0

#define DDRC_PHY_REG30 0xac4
#define DDRC_PHY_REG30_PHY_SKEW_A0(_n) ((_n & 0x3) << 0 )
#define DDRC_PHY_REG30_PHY_SKEW_A1(_n) ((_n & 0x3) << 3 )

#define DDRC_PHY_REG31 0xac8
#define DDRC_PHY_REG31_PHY_SKEW_A2(_n) ((_n & 0x3) << 0 )
#define DDRC_PHY_REG31_PHY_SKEW_A3(_n) ((_n & 0x3) << 3 )

#define DDRC_PHY_REG32 0xacc
#define DDRC_PHY_REG32_PHY_SKEW_A4(_n) ((_n & 0x3) << 0 )
#define DDRC_PHY_REG32_PHY_SKEW_A5(_n) ((_n & 0x3) << 3 )

#define DDRC_PHY_REG33 0xad0
#define DDRC_PHY_REG33_PHY_SKEW_A6(_n) ((_n & 0x3) << 0 )
#define DDRC_PHY_REG33_PHY_SKEW_A7(_n) ((_n & 0x3) << 3 )

#define DDRC_PHY_REG34 0xad4
#define DDRC_PHY_REG34_PHY_SKEW_A8(_n) ((_n & 0x3) << 0 )
#define DDRC_PHY_REG34_PHY_SKEW_A9(_n) ((_n & 0x3) << 3 )

#define DDRC_PHY_REG35 0xad8
#define DDRC_PHY_REG35_PHY_SKEW_A10(_n) ((_n & 0x3) << 0 )
#define DDRC_PHY_REG35_PHY_SKEW_A11(_n) ((_n & 0x3) << 3 )

#define DDRC_PHY_REG36 0xadc
#define DDRC_PHY_REG35_PHY_SKEW_A12(_n) ((_n & 0x3) << 0 )
#define DDRC_PHY_REG35_PHY_SKEW_A13(_n) ((_n & 0x3) << 3 )

#define DDRC_PHY_REG37 0xae0
#define DDRC_PHY_REG37_PHY_SKEW_B0(_n) ((_n & 0x3) << 0 )
#define DDRC_PHY_REG37_PHY_SKEW_B1(_n) ((_n & 0x3) << 3 )

#define DDRC_PHY_REG38 0xae4
#define DDRC_PHY_REG38_PHY_SKEW_B2(_n) ((_n & 0x3) << 0 )
#define DDRC_PHY_REG38_PHY_SKEW_RASB(_n) ((_n & 0x3) << 3 )

#define DDRC_PHY_REG39 0xae8
#define DDRC_PHY_REG39_PHY_SKEW_CASB(_n) ((_n & 0x3) << 0 )
#define DDRC_PHY_REG39_PHY_SKEW_WEB(_n) ((_n & 0x3) << 3 )

#define DDRC_PHY_REG40 0xaec
#define DDRC_PHY_REG40_PHY_SKEW_CK1(_n) ((_n & 0x3) << 0 )
#define DDRC_PHY_REG40_PHY_SKEW_CKB1(_n) ((_n & 0x3) << 3 )

#define DDRC_PHY_REG41 0xaf0
#define DDRC_PHY_REG41_PHY_SKEW_ODT(_n) ((_n & 0x3) << 0 )
#define DDRC_PHY_REG41_PHY_SKEW_CKE(_n) ((_n & 0x3) << 3 )

#define DDRC_PHY_REG42 0xaf4
#define DDRC_PHY_REG42_PHY_SKEW_RSTN(_n) ((_n & 0x3) << 0 )

#define DDRC_PHY_REG43 0xaf8
#define DDRC_PHY_REG43_PHY_TXSKEW_DM0(_n) ((_n & 0x3) << 0 )
#define DDRC_PHY_REG43_PHY_TXSKEW_DM1(_n) ((_n & 0x3) << 3 )

// DDRC_PHY_TXDQSE 0xafc + ( 0x4 * dq_hf )

#define DDRC_PHY_REG52 0xb1c
#define DDRC_PHY_REG52_PHY_TXSKEW_DQS0(_n) ((_n & 0x3) << 0 )
#define DDRC_PHY_REG52_PHY_TXSKEW_DQS1(_n) ((_n & 0x3) << 3 )

#define DDRC_PHY_REG53 0xb20
#define DDRC_PHY_REG53_PHY_SKEW_A14(_n) ((_n & 0x3) << 0 )

#define DDRC_PHY_REG54 0xb24
#define DDRC_PHY_REG54_PHY_SKEW_CK0(_n) ((_n & 0x3) << 0 )
#define DDRC_PHY_REG54_PHY_SKEW_CKB0(_n) ((_n & 0x3) << 3 )

#define DDRC_PHY_REG55 0xb28
#define DDRC_PHY_REG55_PHY_RXSKEW_DM0(_n) ((_n & 0x3) << 0 )
#define DDRC_PHY_REG55_PHY_RXSKEW_DM1(_n) ((_n & 0x3) << 3 )

// DDRC_PHY_RXDQSK 0xb2c + ( 0x4 * dq_hf )

#define DDRC_PHY_REG5E 0xb4c
#define DDRC_PHY_REG55_PHY_RXSKEW_DQS0(_n) ((_n & 0x3) << 0 )
#define DDRC_PHY_REG55_PHY_RXSKEW_DQS1(_n) ((_n & 0x3) << 3 )

// DDRC_PHY_REG60 0xbe0 + ( 0x4 * white )

#define DDRC_PHY_REG61 0xbe8
#define DDRC_PHY_REG61_PHY_CAL_DONE_L BIT(0)
#define DDRC_PHY_REG61_PHY_CAL_DONE_H BIT(1)

#define DDRC_PHY_REG62 0xbc4
#define DDRC_PHY_REG61_PHY_IDQS_L BIT(0)
#define DDRC_PHY_REG61_PHY_IDQE_H BIT(1)
