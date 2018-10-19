/* $NetBSD$ */

/*-
 * Copyright (c) 2018 Jared McNeill <jmcneill@invisible.ca>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef _RK3328_CRU_H
#define _RK3328_CRU_H

#define RK3328_PLL_APLL			1
#define RK3328_PLL_DPLL			2
#define RK3328_PLL_CPLL			3
#define RK3328_PLL_GPLL			4
#define RK3328_PLL_NPLL			5
#define RK3328_ARMCLK			6
#define RK3328_SCLK_RTC32K		30
#define RK3328_SCLK_SDMMC_EXT		31
#define RK3328_SCLK_SPI			32
#define RK3328_SCLK_SDMMC		33
#define RK3328_SCLK_SDIO		34
#define RK3328_SCLK_EMMC		35
#define RK3328_SCLK_TSADC		36
#define RK3328_SCLK_SARADC		37
#define RK3328_SCLK_UART0		38
#define RK3328_SCLK_UART1		39
#define RK3328_SCLK_UART2		40
#define RK3328_SCLK_I2S0		41
#define RK3328_SCLK_I2S1		42
#define RK3328_SCLK_I2S2		43
#define RK3328_SCLK_I2S1_OUT		44
#define RK3328_SCLK_I2S2_OUT		45
#define RK3328_SCLK_SPDIF		46
#define RK3328_SCLK_TIMER0		47
#define RK3328_SCLK_TIMER1		48
#define RK3328_SCLK_TIMER2		49
#define RK3328_SCLK_TIMER3		50
#define RK3328_SCLK_TIMER4		51
#define RK3328_SCLK_TIMER5		52
#define RK3328_SCLK_WIFI		53
#define RK3328_SCLK_CIF_OUT		54
#define RK3328_SCLK_I2C0		55
#define RK3328_SCLK_I2C1		56
#define RK3328_SCLK_I2C2		57
#define RK3328_SCLK_I2C3		58
#define RK3328_SCLK_CRYPTO		59
#define RK3328_SCLK_PWM			60
#define RK3328_SCLK_PDM			61
#define RK3328_SCLK_EFUSE		62
#define RK3328_SCLK_OTP			63
#define RK3328_SCLK_DDRCLK		64
#define RK3328_SCLK_VDEC_CABAC		65
#define RK3328_SCLK_VDEC_CORE		66
#define RK3328_SCLK_VENC_DSP		67
#define RK3328_SCLK_VENC_CORE		68
#define RK3328_SCLK_RGA			69
#define RK3328_SCLK_HDMI_SFC		70
#define RK3328_SCLK_HDMI_CEC		71
#define RK3328_SCLK_USB3_REF		72
#define RK3328_SCLK_USB3_SUSPEND	73
#define RK3328_SCLK_SDMMC_DRV		74
#define RK3328_SCLK_SDIO_DRV		75
#define RK3328_SCLK_EMMC_DRV		76
#define RK3328_SCLK_SDMMC_EXT_DRV	77
#define RK3328_SCLK_SDMMC_SAMPLE	78
#define RK3328_SCLK_SDIO_SAMPLE		79
#define RK3328_SCLK_EMMC_SAMPLE		80
#define RK3328_SCLK_SDMMC_EXT_SAMPLE	81
#define RK3328_SCLK_VOP			82
#define RK3328_SCLK_MAC2PHY_RXTX	83
#define RK3328_SCLK_MAC2PHY_SRC		84
#define RK3328_SCLK_MAC2PHY_REF		85
#define RK3328_SCLK_MAC2PHY_OUT		86
#define RK3328_SCLK_MAC2IO_RX		87
#define RK3328_SCLK_MAC2IO_TX		88
#define RK3328_SCLK_MAC2IO_REFOUT	89
#define RK3328_SCLK_MAC2IO_REF		90
#define RK3328_SCLK_MAC2IO_OUT		91
#define RK3328_SCLK_TSP			92
#define RK3328_SCLK_HSADC_TSP		93
#define RK3328_SCLK_USB3PHY_REF		94
#define RK3328_SCLK_REF_USB3OTG		95
#define RK3328_SCLK_USB3OTG_REF		96
#define RK3328_SCLK_USB3OTG_SUSPEND	97
#define RK3328_SCLK_REF_USB3OTG_SRC	98
#define RK3328_SCLK_MAC2IO_SRC		99
#define RK3328_SCLK_MAC2IO		100
#define RK3328_SCLK_MAC2PHY		101
#define RK3328_SCLK_MAC2IO_EXT		102
#define RK3328_DCLK_LCDC		120
#define RK3328_DCLK_HDMIPHY		121
#define RK3328_HDMIPHY			122
#define RK3328_USB480M			123
#define RK3328_DCLK_LCDC_SRC		124
#define RK3328_ACLK_AXISRAM		130
#define RK3328_ACLK_VOP_PRE		131
#define RK3328_ACLK_USB3OTG		132
#define RK3328_ACLK_RGA_PRE		133
#define RK3328_ACLK_DMAC		134
#define RK3328_ACLK_GPU			135
#define RK3328_ACLK_BUS_PRE		136
#define RK3328_ACLK_PERI_PRE		137
#define RK3328_ACLK_RKVDEC_PRE		138
#define RK3328_ACLK_RKVDEC		139
#define RK3328_ACLK_RKVENC		140
#define RK3328_ACLK_VPU_PRE		141
#define RK3328_ACLK_VIO_PRE		142
#define RK3328_ACLK_VPU			143
#define RK3328_ACLK_VIO			144
#define RK3328_ACLK_VOP			145
#define RK3328_ACLK_GMAC		146
#define RK3328_ACLK_H265		147
#define RK3328_ACLK_H264		148
#define RK3328_ACLK_MAC2PHY		149
#define RK3328_ACLK_MAC2IO		150
#define RK3328_ACLK_DCF			151
#define RK3328_ACLK_TSP			152
#define RK3328_ACLK_PERI		153
#define RK3328_ACLK_RGA			154
#define RK3328_ACLK_IEP			155
#define RK3328_ACLK_CIF			156
#define RK3328_ACLK_HDCP		157
#define RK3328_PCLK_GPIO0		200
#define RK3328_PCLK_GPIO1		201
#define RK3328_PCLK_GPIO2		202
#define RK3328_PCLK_GPIO3		203
#define RK3328_PCLK_GRF			204
#define RK3328_PCLK_I2C0		205
#define RK3328_PCLK_I2C1		206
#define RK3328_PCLK_I2C2		207
#define RK3328_PCLK_I2C3		208
#define RK3328_PCLK_SPI			209
#define RK3328_PCLK_UART0		210
#define RK3328_PCLK_UART1		211
#define RK3328_PCLK_UART2		212
#define RK3328_PCLK_TSADC		213
#define RK3328_PCLK_PWM			214
#define RK3328_PCLK_TIMER		215
#define RK3328_PCLK_BUS_PRE		216
#define RK3328_PCLK_PERI_PRE		217
#define RK3328_PCLK_HDMI_CTRL		218
#define RK3328_PCLK_HDMI_PHY		219
#define RK3328_PCLK_GMAC		220
#define RK3328_PCLK_H265		221
#define RK3328_PCLK_MAC2PHY		222
#define RK3328_PCLK_MAC2IO		223
#define RK3328_PCLK_USB3PHY_OTG		224
#define RK3328_PCLK_USB3PHY_PIPE	225
#define RK3328_PCLK_USB3_GRF		226
#define RK3328_PCLK_USB2_GRF		227
#define RK3328_PCLK_HDMIPHY		228
#define RK3328_PCLK_DDR			229
#define RK3328_PCLK_PERI		230
#define RK3328_PCLK_HDMI		231
#define RK3328_PCLK_HDCP		232
#define RK3328_PCLK_DCF			233
#define RK3328_PCLK_SARADC		234
#define RK3328_HCLK_PERI		308
#define RK3328_HCLK_TSP			309
#define RK3328_HCLK_GMAC		310
#define RK3328_HCLK_I2S0_8CH		311
#define RK3328_HCLK_I2S1_8CH		313
#define RK3328_HCLK_I2S2_2CH		313
#define RK3328_HCLK_SPDIF_8CH		314
#define RK3328_HCLK_VOP			315
#define RK3328_HCLK_NANDC		316
#define RK3328_HCLK_SDMMC		317
#define RK3328_HCLK_SDIO		318
#define RK3328_HCLK_EMMC		319
#define RK3328_HCLK_SDMMC_EXT		320
#define RK3328_HCLK_RKVDEC_PRE		321
#define RK3328_HCLK_RKVDEC		322
#define RK3328_HCLK_RKVENC		323
#define RK3328_HCLK_VPU_PRE		324
#define RK3328_HCLK_VIO_PRE		325
#define RK3328_HCLK_VPU			326
#define RK3328_HCLK_BUS_PRE		328
#define RK3328_HCLK_PERI_PRE		329
#define RK3328_HCLK_H264		330
#define RK3328_HCLK_CIF			331
#define RK3328_HCLK_OTG_PMU		332
#define RK3328_HCLK_OTG			333
#define RK3328_HCLK_HOST0		334
#define RK3328_HCLK_HOST0_ARB		335
#define RK3328_HCLK_CRYPTO_MST		336
#define RK3328_HCLK_CRYPTO_SLV		337
#define RK3328_HCLK_PDM			338
#define RK3328_HCLK_IEP			339
#define RK3328_HCLK_RGA			340
#define RK3328_HCLK_HDCP		341

#endif /* !_RK3328_CRU_H */