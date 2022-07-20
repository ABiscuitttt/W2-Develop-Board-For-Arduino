//This Head File Defined All the Registers On the Board

#define flashBaseAddress		0x10000000
#define falshSize				131072
#define flashBlockSize			512

#define SRAMBaseAddress			0x01000000
#define SRAMSize				8192

#define T0Base					0x1f800100
#define T0_CTL0_REG				0x1f800100
#define T0_REF_REG				0x1f800101
#define T0_READ_REG				0x1f800102
#define T0_CLRIRQ_REG			0x1f800103
#define T0_CLK_REG				0x1f800104
#define T0_CLRCNT_REG			0x1f800105
#define T0_PWMPH_REG			0x1f800106
#define T0_CLRPWM_REG			0x1f800107

#define T1Base					0x1f800800
#define T1_CTL0_REG				0x1f800800
#define T1_REF_REG				0x1f800801
#define T1_READ_REG				0x1f800802
#define T1_CLRIRQ_REG			0x1f800803
#define T1_CLK_REG				0x1f800804
#define T1_CLRCNT_REG			0x1f800805
#define T1_PWMPH_REG			0x1f800806
#define T1_CLRPWM_REG			0x1f800807

#define T4_CTL_REG				0x1f800b00
#define T4_REF0_REG				0x1f800b01
#define T4_REF1_REG				0x1f800b02
#define T4_CLRIRQ_REG			0x1f800b03
#define T4_WDTCNT_REG			0x1f800b04
#define T4_IO2_CTL_REG			0x1f800b05
#define T4_IO2_OUT_REG			0x1f800b06
#define T4_EF_LOCK_REG			0x1f800b07

#define C0_CTL_REG				0x1f800200
#define C0_PERI_REG				0x1f800201
#define C0_CONF_REG				0x1f800202
#define C0_CLRIRQ_REG			0x1f800203
#define C0_DT_REG				0x1f800204
#define C0_DUTY0_REG			0x1f800205
#define C0_DUTY1_REG			0x1f800206
#define C0_TRIG_REG				0x1f800207

#define C1_CTL_REG				0x1f800210
#define C1_PERI_REG				0x1f800211
#define C1_CONF_REG				0x1f800212
#define C1_CLRIRQ_REG			0x1f800213
#define C1_DT_REG				0x1f800214
#define C1_DUTY0_REG			0x1f800215
#define C1_DUTY1_REG			0x1f800216
#define C1_TRIG_REG				0x1f800217

#define C2_CTL_REG				0x1f800220
#define C2_PERI_REG				0x1f800221
#define C2_CONF_REG				0x1f800222
#define C2_CLRIRQ_REG			0x1f800223
#define C2_DT_REG				0x1f800224
#define C2_DUTY0_REG			0x1f800225
#define C2_DUTY1_REG			0x1f800226
#define C2_TRIG_REG				0x1f800227

#define MX_CTL_REG				0x1f800230
#define MX_DUTY_REG				0x1f800231
#define MX_CLRIRQ_REG			0x1f800233
#define MX_CLKDIV_REG			0x1f800234

#define EXINT_CTL0_REG			0x1f800500
#define EXINT_READ_REG			0x1f800501
#define EXINT_SET_REG			0x1f800502
#define EXINT_CLR_REG			0x1f800503

#define A_OPO_CMP_REG			0x1f800600
#define A_SAR_CTL_REG			0x1f800601
#define A_SAR_READ_REG			0x1f800602
#define A_CLR_REG				0x1f800603
#define A_SAR_CS_REG			0x1f800604
#define A_DAC_CTL_REG			0x1f800606

#define SYS_CTL0_REG			0x1f800700
#define SYS_CRL1_REG			0x1f800701
#define SYS_CRL2_REG			0x1f800702
#define SYS_GDR_REG				0x1f800703
#define SYS_IOCTL_REG			0x1f800704
#define SYS_GPIO0_REG			0x1f800705
#define SYS_GPIO1_REG			0x1f800706
#define SYS_IRQ_REG				0x1f800707

#define U0_READ_REG				0x1f800000
#define U0_BUSY_REG				0x1f800001
#define U0_WRITE_REG			0x1f800002
#define U0_CLRIRQ_REG			0x1f800003
#define U0_CTL0_REG				0x1f800004
#define U0_Data_RDY_REG			0x1f800005
#define U0_LINBRK_REG			0x1f800006
#define U0_BRP_REG				0x1f800007

#define U1_READ_REG				0x1f800010
#define U1_BUSY_REG				0x1f800011
#define U1_WRITE_REG			0x1f800012
#define U1_CLRIRQ_REG			0x1f800013
#define U1_CTL0_REG				0x1f800014
#define U1_Data_RDY_REG			0x1f800015
#define U1_LINBRK_REG			0x1f800016
#define U1_BRP_REG				0x1f800017

#define U2_READ_REG				0x1f800020
#define U2_BUSY_REG				0x1f800021
#define U2_WRITE_REG			0x1f800022
#define U2_CLRIRQ_REG			0x1f800023
#define U2_CTL0_REG				0x1f800024
#define U2_Data_RDY_REG			0x1f800025
#define U2_LINBRK_REG			0x1f800026
#define U2_BRP_REG				0x1f800027

#define SPI_WRITE_REG			0x1f800d02
#define SPI_READ_REG			0x1f800d00
#define SPI_DATARDY_REG			0x1f800d05
#define SPI_CTL_REG				0x1f800d04
#define SPI_CLRIRQ_REG			0x1f800d03
#define SPI_BUSY_REG			0x1f800d01

#define IM_WRITE_REG			0x1f800d32
#define IM_READ_REG				0x1f800d30
#define IM_DATARDY_REG			0x1f800d35
#define IM_START_STOP_REG		0x1f800d36
#define IM_CTL_REG				0x1f800d34
#define IM_CLRIRQ_REG			0x1f800d33
#define IM_BUSY_REG				0x1f800d31

#define IS_WRITE_REG			0x1f800d22
#define IS_READ_REG				0x1f800d20
#define IS_DATARDY_REG			0x1f800d25
#define IS_CTL_REG				0x1f800d24
#define IS_CLRIRQ_REG			0x1f800d23

#define DMI_DATA_REG			0x1f80-0d12
#define DMI_ADDR_REG			0x1f80-0d10
#define DMI_STATUS_REG			0x1f80-0d15
#define DMI_CTL_REG				0x1f80-0d14
#define DMI_CLRIRQ_REG			0x1f80-0d13
#define DMI_CMD_REG				0x1f80-0d11

#define SD_CTRL_REG				0x1f800c00
#define SD_CLRIRQ_REG			0x1f800c03
#define SD_BRK0_REG				0x1f800c04
#define SD_BRK1_REG				0x1f800c05

#define WK_READ_REG				0x1f800f00
#define WK_REF_REG				0x1f800f01
#define WK_CLR_REG				0x1f800f03


/*Functions that operate on registers*/
void RegBitWrite(unsigned long reg, char pos, char value);

void RegWrite(unsigned long reg, unsigned long value);

unsigned long RegRead(unsigned long reg);

char RegBitRead(unsigned long reg, unsigned long pos);
