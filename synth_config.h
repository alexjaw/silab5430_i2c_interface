/*
 * Si5340 Rev D Configuration Register Export Header File
 *
 * This file represents a series of Silicon Labs Si5340 Rev D 
 * register writes that can be performed to load a single configuration 
 * on a device. It was created by a Silicon Labs ClockBuilder Pro
 * export tool.
 *
 * Part:		                                       Si5340 Rev D
 * Design ID:                                          5340EVB1
 * Includes Pre/Post Download Control Register Writes: Yes
 * Created By:                                         ClockBuilder Pro v2.28.1 [2018-09-24]
 * Timestamp:                                          2018-10-11 15:01:13 GMT+02:00
 *
 * A complete design report corresponding to this export is included at the end 
 * of this header file.
 *
 */

#ifndef SI5340_REVD_REG_CONFIG_HEADER
#define SI5340_REVD_REG_CONFIG_HEADER

#define SYNTH_REG_CONFIG_NUM_REGS				326

typedef struct
{
	unsigned int address; /* 16-bit register address */
	unsigned char value; /* 8-bit register data */

} synth_register_t;

synth_register_t const synth_registers[SYNTH_REG_CONFIG_NUM_REGS];

/*
 * Design Report
 *
 * Overview
 * ========
 * Part:               Si5340AB Rev D
 * Project File:       C:\Users\alexander\Documents\ClockBuilderFiles\Si5340-RevD-5340EVB1-001.slabtimeproj
 * Design ID:          5340EVB1
 * Created By:         ClockBuilder Pro v2.28.1 [2018-09-24]
 * Timestamp:          2018-10-11 15:01:13 GMT+02:00
 * 
 * Design Rule Check
 * =================
 * Errors:
 * - No errors
 * 
 * Warnings:
 * - OUT2 [22.5792 MHz] and OUT3 [24 MHz] may have coupling [1]
 * 
 * Footnotes:
 * [1] To avoid coupling in outputs, Silicon Labs recommends the following:
 * 
 * - Avoid adjacent frequency values that are close. CBPro uses an output's integration bandwidth (IBW) to determine whether two adjacent frequencies are too close. An IBW of 20 MHz is used for frequencies 80 MHz and larger. Lower frequencies will use IBW of Freq/4.
 * - Adjacent frequency values that are integer multiples of one another are okay and these outputs should be grouped accordingly. For example, a 155.52 MHz and 622.08 MHz (155.52 x 4) can be adjacent.
 * - Unused outputs can be used to separate clock outputs that might otherwise interfere with one another.
 * 
 * Silicon Labs recommends you validate your design's jitter performance using an Evaluation Board. You can request a custom phase noise report for your design from CBPro's design dashboard.
 * 
 * Device Grade
 * ============
 * Maximum Output Frequency: 24 MHz
 * Frequency Synthesis Mode: Fractional
 * Frequency Plan Grade:     B
 * Minimum Base OPN:         Si5340B*
 * 
 * Base       Output Clock         Supported Frequency Synthesis Modes
 * OPN Grade  Frequency Range      (Typical Jitter)
 * ---------  -------------------  --------------------------------------------
 * Si5340A    100 Hz to 1.028 GHz  Integer (< 100 fs) and fractional (< 150 fs)
 * Si5340B*   100 Hz to 350 MHz    "
 * Si5340C    100 Hz to 1.028 GHz  Integer only (< 100 fs)
 * Si5340D    100 Hz to 350 MHz    "
 * 
 * * Based on your calculated frequency plan, a Si5340B grade device is
 * sufficient for your design. For more in-system configuration flexibility
 * (higher frequencies and/or to enable fractional synthesis), consider
 * selecting device grade Si5340A when specifying an ordering part number (OPN)
 * for your application. See the datasheet Ordering Guide for more information.
 * 
 * Design
 * ======
 * Host Interface:
 *    I/O Power Supply: VDD (Core)
 *    SPI Mode: 4-Wire
 *    I2C Address Range: 116d to 119d / 0x74 to 0x77 (selected via A0/A1 pins)
 * 
 * Inputs:
 *    XAXB: 48 MHz
 *          Crystal Mode
 *     IN0: Unused
 *     IN1: Unused
 *     IN2: Unused
 *   FB_IN: Unused
 * 
 * Outputs:
 *    OUT0: 12.288 MHz [ 12 + 36/125 MHz ]
 *          Enabled, LVDS 2.5 V
 *    OUT1: 1.4112 MHz [ 1 + 257/625 MHz ]
 *          [ 44.1k*16*2 ]
 *          Enabled, LVDS 2.5 V
 *    OUT2: 22.5792 MHz [ 22 + 362/625 MHz ]
 *          [ 44.1k*512 ]
 *          Enabled, LVDS 2.5 V
 *    OUT3: 24 MHz
 *          Enabled, LVDS 2.5 V
 * 
 * Frequency Plan
 * ==============
 * Priority: maximize the number of low jitter outputs
 * 
 * Fpfd = 48 MHz
 * Fvco = 13.4120448 GHz [ 13 + 32191/78125 GHz ]
 * Fms0 = 406.4256 MHz [ 406 + 266/625 MHz ]
 * Fms1 = 73.728 MHz [ 73 + 91/125 MHz ]
 * Fms2 = 240 MHz
 * 
 * P dividers:
 *    P0  = Unused
 *    P1  = Unused
 *    P2  = Unused
 *    P3  = Unused
 *    Pxaxb = 1
 * 
 * M = 279.4176 [ 279 + 261/625 ]
 * N dividers:
 *    N0:
 *       Value: 33
 *       Skew:  0.000 s
 *       OUT1: 1.4112 MHz [ 1 + 257/625 MHz ]
 *       OUT2: 22.5792 MHz [ 22 + 362/625 MHz ]
 *    N1:
 *       Value: 181.9125 [ 181 + 73/80 ]
 *       Skew:  0.000 s
 *       OUT0: 12.288 MHz [ 12 + 36/125 MHz ]
 *    N2:
 *       Value: 55.88352 [ 55 + 2761/3125 ]
 *       Skew:  0.000 s
 *       OUT3: 24 MHz
 *    N3:
 *       Unused
 * 
 * R dividers:
 *    R0 = 6
 *    R1 = 288
 *    R2 = 18
 *    R3 = 10
 * 
 * Dividers listed above show effective values. These values are translated to register settings by ClockBuilder Pro. For the actual register values, see below. Refer to the Family Reference Manual for information on registers related to frequency plan.
 * 
 * Digitally Controlled Oscillator (DCO)
 * =====================================
 * Mode: FINC/FDEC
 * 
 * N0: DCO Disabled
 * 
 * N1: DCO Disabled
 * 
 * N2: DCO Disabled
 * 
 * N3: DCO Disabled
 * 
 * Estimated Power & Junction Temperature
 * ======================================
 * Assumptions:
 * 
 * Revision: D
 * VDD:      1.8 V
 * Ta:       70 °C
 * Airflow:  None
 * 
 * Total Power: 770 mW, On Chip Power: 746 mW, Tj: 87 °C
 * 
 *           Frequency  Format   Voltage   Current     Power
 *         -----------  ------  --------  --------  --------
 * VDD                             1.8 V  129.2 mA    232 mW
 * VDDA                            3.3 V  117.4 mA    387 mW
 * VDDO0    12.288 MHz  LVDS       2.5 V   15.0 mA     37 mW
 * VDDO1    1.4112 MHz  LVDS       2.5 V   14.9 mA     37 mW
 * VDDO2   22.5792 MHz  LVDS       2.5 V   15.1 mA     38 mW
 * VDDO3        24 MHz  LVDS       2.5 V   15.1 mA     38 mW
 *                                        --------  --------
 *                                 Total  306.5 mA    770 mW
 * 
 * Note:
 * 
 * -Total power includes on- and off-chip power. This is a typical value and estimate only.
 * -Use an EVB for a more exact power measurement
 * -On-chip power excludes power dissipated in external terminations.
 * -Tj is junction temperature. Tj must be less than 125 °C (on Si5340 Revision D) for device to comply with datasheet specifications.
 * 
 * Settings
 * ========
 * 
 * Location      Setting Name         Decimal Value      Hex Value        
 * ------------  -------------------  -----------------  -----------------
 * 0x0006[23:0]  TOOL_VERSION         0                  0x000000         
 * 0x000B[6:0]   I2C_ADDR             116                0x74             
 * 0x0017[0]     SYSINCAL_INTR_MSK    0                  0x0              
 * 0x0017[1]     LOSXAXB_INTR_MSK     0                  0x0              
 * 0x0017[2]     LOSREF_INTR_MSK      0                  0x0              
 * 0x0017[3]     LOL_INTR_MSK         0                  0x0              
 * 0x0017[5]     SMB_TMOUT_INTR_MSK   0                  0x0              
 * 0x0018[3:0]   LOSIN_INTR_MSK       15                 0xF              
 * 0x0021[0]     IN_SEL_REGCTRL       1                  0x1              
 * 0x0021[2:1]   IN_SEL               3                  0x3              
 * 0x0022[1]     OE                   0                  0x0              
 * 0x002B[3]     SPI_3WIRE            0                  0x0              
 * 0x002B[5]     AUTO_NDIV_UPDATE     0                  0x0              
 * 0x002C[3:0]   LOS_EN               0                  0x0              
 * 0x002C[4]     LOSXAXB_DIS          0                  0x0              
 * 0x002D[1:0]   LOS0_VAL_TIME        0                  0x0              
 * 0x002D[3:2]   LOS1_VAL_TIME        0                  0x0              
 * 0x002D[5:4]   LOS2_VAL_TIME        0                  0x0              
 * 0x002D[7:6]   LOS3_VAL_TIME        0                  0x0              
 * 0x002E[15:0]  LOS0_TRG_THR         0                  0x0000           
 * 0x0030[15:0]  LOS1_TRG_THR         0                  0x0000           
 * 0x0032[15:0]  LOS2_TRG_THR         0                  0x0000           
 * 0x0034[15:0]  LOS3_TRG_THR         0                  0x0000           
 * 0x0036[15:0]  LOS0_CLR_THR         0                  0x0000           
 * 0x0038[15:0]  LOS1_CLR_THR         0                  0x0000           
 * 0x003A[15:0]  LOS2_CLR_THR         0                  0x0000           
 * 0x003C[15:0]  LOS3_CLR_THR         0                  0x0000           
 * 0x0041[4:0]   LOS0_DIV_SEL         0                  0x00             
 * 0x0042[4:0]   LOS1_DIV_SEL         0                  0x00             
 * 0x0043[4:0]   LOS2_DIV_SEL         0                  0x00             
 * 0x0044[4:0]   LOS3_DIV_SEL         0                  0x00             
 * 0x009E[7:4]   LOL_SET_THR          0                  0x0              
 * 0x0102[0]     OUTALL_DISABLE_LOW   1                  0x1              
 * 0x0112[0]     OUT0_PDN             0                  0x0              
 * 0x0112[1]     OUT0_OE              1                  0x1              
 * 0x0112[2]     OUT0_RDIV_FORCE2     0                  0x0              
 * 0x0113[2:0]   OUT0_FORMAT          1                  0x1              
 * 0x0113[3]     OUT0_SYNC_EN         1                  0x1              
 * 0x0113[5:4]   OUT0_DIS_STATE       0                  0x0              
 * 0x0113[7:6]   OUT0_CMOS_DRV        0                  0x0              
 * 0x0114[3:0]   OUT0_CM              11                 0xB              
 * 0x0114[6:4]   OUT0_AMPL            3                  0x3              
 * 0x0115[2:0]   OUT0_MUX_SEL         1                  0x1              
 * 0x0115[5:4]   OUT0_VDD_SEL         2                  0x2              
 * 0x0115[3]     OUT0_VDD_SEL_EN      1                  0x1              
 * 0x0115[7:6]   OUT0_INV             0                  0x0              
 * 0x0117[0]     OUT1_PDN             0                  0x0              
 * 0x0117[1]     OUT1_OE              1                  0x1              
 * 0x0117[2]     OUT1_RDIV_FORCE2     0                  0x0              
 * 0x0118[2:0]   OUT1_FORMAT          1                  0x1              
 * 0x0118[3]     OUT1_SYNC_EN         1                  0x1              
 * 0x0118[5:4]   OUT1_DIS_STATE       0                  0x0              
 * 0x0118[7:6]   OUT1_CMOS_DRV        0                  0x0              
 * 0x0119[3:0]   OUT1_CM              11                 0xB              
 * 0x0119[6:4]   OUT1_AMPL            3                  0x3              
 * 0x011A[2:0]   OUT1_MUX_SEL         0                  0x0              
 * 0x011A[5:4]   OUT1_VDD_SEL         2                  0x2              
 * 0x011A[3]     OUT1_VDD_SEL_EN      1                  0x1              
 * 0x011A[7:6]   OUT1_INV             0                  0x0              
 * 0x0126[0]     OUT2_PDN             0                  0x0              
 * 0x0126[1]     OUT2_OE              1                  0x1              
 * 0x0126[2]     OUT2_RDIV_FORCE2     0                  0x0              
 * 0x0127[2:0]   OUT2_FORMAT          1                  0x1              
 * 0x0127[3]     OUT2_SYNC_EN         1                  0x1              
 * 0x0127[5:4]   OUT2_DIS_STATE       0                  0x0              
 * 0x0127[7:6]   OUT2_CMOS_DRV        0                  0x0              
 * 0x0128[3:0]   OUT2_CM              11                 0xB              
 * 0x0128[6:4]   OUT2_AMPL            3                  0x3              
 * 0x0129[2:0]   OUT2_MUX_SEL         0                  0x0              
 * 0x0129[5:4]   OUT2_VDD_SEL         2                  0x2              
 * 0x0129[3]     OUT2_VDD_SEL_EN      1                  0x1              
 * 0x0129[7:6]   OUT2_INV             0                  0x0              
 * 0x012B[0]     OUT3_PDN             0                  0x0              
 * 0x012B[1]     OUT3_OE              1                  0x1              
 * 0x012B[2]     OUT3_RDIV_FORCE2     0                  0x0              
 * 0x012C[2:0]   OUT3_FORMAT          1                  0x1              
 * 0x012C[3]     OUT3_SYNC_EN         1                  0x1              
 * 0x012C[5:4]   OUT3_DIS_STATE       0                  0x0              
 * 0x012C[7:6]   OUT3_CMOS_DRV        0                  0x0              
 * 0x012D[3:0]   OUT3_CM              11                 0xB              
 * 0x012D[6:4]   OUT3_AMPL            3                  0x3              
 * 0x012E[2:0]   OUT3_MUX_SEL         2                  0x2              
 * 0x012E[5:4]   OUT3_VDD_SEL         2                  0x2              
 * 0x012E[3]     OUT3_VDD_SEL_EN      1                  0x1              
 * 0x012E[7:6]   OUT3_INV             0                  0x0              
 * 0x013F[11:0]  OUTX_ALWAYS_ON       0                  0x000            
 * 0x0141[5]     OUT_DIS_LOL_MSK      0                  0x0              
 * 0x0141[7]     OUT_DIS_MSK_LOS_PFD  0                  0x0              
 * 0x0206[1:0]   PXAXB                0                  0x0              
 * 0x0208[47:0]  P0                   0                  0x000000000000   
 * 0x020E[31:0]  P0_SET               0                  0x00000000       
 * 0x0212[47:0]  P1                   0                  0x000000000000   
 * 0x0218[31:0]  P1_SET               0                  0x00000000       
 * 0x021C[47:0]  P2                   0                  0x000000000000   
 * 0x0222[31:0]  P2_SET               0                  0x00000000       
 * 0x0226[47:0]  P3                   0                  0x000000000000   
 * 0x022C[31:0]  P3_SET               0                  0x00000000       
 * 0x0235[43:0]  M_NUM                732476473344       0x0AA8B000000    
 * 0x023B[31:0]  M_DEN                2621440000         0x9C400000       
 * 0x0250[23:0]  R0_REG               2                  0x000002         
 * 0x0253[23:0]  R1_REG               143                0x00008F         
 * 0x025C[23:0]  R2_REG               8                  0x000008         
 * 0x025F[23:0]  R3_REG               4                  0x000004         
 * 0x026B[7:0]   DESIGN_ID0           53                 0x35             
 * 0x026C[7:0]   DESIGN_ID1           51                 0x33             
 * 0x026D[7:0]   DESIGN_ID2           52                 0x34             
 * 0x026E[7:0]   DESIGN_ID3           48                 0x30             
 * 0x026F[7:0]   DESIGN_ID4           69                 0x45             
 * 0x0270[7:0]   DESIGN_ID5           86                 0x56             
 * 0x0271[7:0]   DESIGN_ID6           66                 0x42             
 * 0x0272[7:0]   DESIGN_ID7           49                 0x31             
 * 0x0302[43:0]  N0_NUM               70866960384        0x01080000000    
 * 0x0308[31:0]  N0_DEN               2147483648         0x80000000       
 * 0x030C[0]     N0_UPDATE            0                  0x0              
 * 0x030D[43:0]  N1_NUM               488317648896       0x071B2000000    
 * 0x0313[31:0]  N1_DEN               2684354560         0xA0000000       
 * 0x0317[0]     N1_UPDATE            0                  0x0              
 * 0x0318[43:0]  N2_NUM               183119118336       0x02AA2C00000    
 * 0x031E[31:0]  N2_DEN               3276800000         0xC3500000       
 * 0x0322[0]     N2_UPDATE            0                  0x0              
 * 0x0323[43:0]  N3_NUM               0                  0x00000000000    
 * 0x0329[31:0]  N3_DEN               0                  0x00000000       
 * 0x032D[0]     N3_UPDATE            0                  0x0              
 * 0x0338[1]     N_UPDATE             0                  0x0              
 * 0x0339[4:0]   N_FSTEP_MSK          31                 0x1F             
 * 0x033B[43:0]  N0_FSTEPW            0                  0x00000000000    
 * 0x0341[43:0]  N1_FSTEPW            0                  0x00000000000    
 * 0x0347[43:0]  N2_FSTEPW            0                  0x00000000000    
 * 0x034D[43:0]  N3_FSTEPW            0                  0x00000000000    
 * 0x0359[15:0]  N0_DELAY             0                  0x0000           
 * 0x035B[15:0]  N1_DELAY             0                  0x0000           
 * 0x035D[15:0]  N2_DELAY             0                  0x0000           
 * 0x035F[15:0]  N3_DELAY             0                  0x0000           
 * 0x0802[15:0]  FIXREGSA0            0                  0x0000           
 * 0x0804[7:0]   FIXREGSD0            0                  0x00             
 * 0x0805[15:0]  FIXREGSA1            0                  0x0000           
 * 0x0807[7:0]   FIXREGSD1            0                  0x00             
 * 0x0808[15:0]  FIXREGSA2            0                  0x0000           
 * 0x080A[7:0]   FIXREGSD2            0                  0x00             
 * 0x080B[15:0]  FIXREGSA3            0                  0x0000           
 * 0x080D[7:0]   FIXREGSD3            0                  0x00             
 * 0x080E[15:0]  FIXREGSA4            0                  0x0000           
 * 0x0810[7:0]   FIXREGSD4            0                  0x00             
 * 0x0811[15:0]  FIXREGSA5            0                  0x0000           
 * 0x0813[7:0]   FIXREGSD5            0                  0x00             
 * 0x0814[15:0]  FIXREGSA6            0                  0x0000           
 * 0x0816[7:0]   FIXREGSD6            0                  0x00             
 * 0x0817[15:0]  FIXREGSA7            0                  0x0000           
 * 0x0819[7:0]   FIXREGSD7            0                  0x00             
 * 0x081A[15:0]  FIXREGSA8            0                  0x0000           
 * 0x081C[7:0]   FIXREGSD8            0                  0x00             
 * 0x081D[15:0]  FIXREGSA9            0                  0x0000           
 * 0x081F[7:0]   FIXREGSD9            0                  0x00             
 * 0x0820[15:0]  FIXREGSA10           0                  0x0000           
 * 0x0822[7:0]   FIXREGSD10           0                  0x00             
 * 0x0823[15:0]  FIXREGSA11           0                  0x0000           
 * 0x0825[7:0]   FIXREGSD11           0                  0x00             
 * 0x0826[15:0]  FIXREGSA12           0                  0x0000           
 * 0x0828[7:0]   FIXREGSD12           0                  0x00             
 * 0x0829[15:0]  FIXREGSA13           0                  0x0000           
 * 0x082B[7:0]   FIXREGSD13           0                  0x00             
 * 0x082C[15:0]  FIXREGSA14           0                  0x0000           
 * 0x082E[7:0]   FIXREGSD14           0                  0x00             
 * 0x082F[15:0]  FIXREGSA15           0                  0x0000           
 * 0x0831[7:0]   FIXREGSD15           0                  0x00             
 * 0x0832[15:0]  FIXREGSA16           0                  0x0000           
 * 0x0834[7:0]   FIXREGSD16           0                  0x00             
 * 0x0835[15:0]  FIXREGSA17           0                  0x0000           
 * 0x0837[7:0]   FIXREGSD17           0                  0x00             
 * 0x0838[15:0]  FIXREGSA18           0                  0x0000           
 * 0x083A[7:0]   FIXREGSD18           0                  0x00             
 * 0x083B[15:0]  FIXREGSA19           0                  0x0000           
 * 0x083D[7:0]   FIXREGSD19           0                  0x00             
 * 0x083E[15:0]  FIXREGSA20           0                  0x0000           
 * 0x0840[7:0]   FIXREGSD20           0                  0x00             
 * 0x0841[15:0]  FIXREGSA21           0                  0x0000           
 * 0x0843[7:0]   FIXREGSD21           0                  0x00             
 * 0x0844[15:0]  FIXREGSA22           0                  0x0000           
 * 0x0846[7:0]   FIXREGSD22           0                  0x00             
 * 0x0847[15:0]  FIXREGSA23           0                  0x0000           
 * 0x0849[7:0]   FIXREGSD23           0                  0x00             
 * 0x084A[15:0]  FIXREGSA24           0                  0x0000           
 * 0x084C[7:0]   FIXREGSD24           0                  0x00             
 * 0x084D[15:0]  FIXREGSA25           0                  0x0000           
 * 0x084F[7:0]   FIXREGSD25           0                  0x00             
 * 0x0850[15:0]  FIXREGSA26           0                  0x0000           
 * 0x0852[7:0]   FIXREGSD26           0                  0x00             
 * 0x0853[15:0]  FIXREGSA27           0                  0x0000           
 * 0x0855[7:0]   FIXREGSD27           0                  0x00             
 * 0x0856[15:0]  FIXREGSA28           0                  0x0000           
 * 0x0858[7:0]   FIXREGSD28           0                  0x00             
 * 0x0859[15:0]  FIXREGSA29           0                  0x0000           
 * 0x085B[7:0]   FIXREGSD29           0                  0x00             
 * 0x085C[15:0]  FIXREGSA30           0                  0x0000           
 * 0x085E[7:0]   FIXREGSD30           0                  0x00             
 * 0x085F[15:0]  FIXREGSA31           0                  0x0000           
 * 0x0861[7:0]   FIXREGSD31           0                  0x00             
 * 0x090E[0]     XAXB_EXTCLK_EN       0                  0x0              
 * 0x090E[1]     XAXB_PDNB            1                  0x1              
 * 0x091C[2:0]   ZDM_EN               4                  0x4              
 * 0x0943[0]     IO_VDD_SEL           0                  0x0              
 * 0x0949[3:0]   IN_EN                0                  0x0              
 * 0x0949[7:4]   IN_PULSED_CMOS_EN    0                  0x0              
 * 0x094A[7:4]   INX_TO_PFD_EN        0                  0x0              
 * 0x094E[11:0]  REFCLK_HYS_SEL       585                0x249            
 * 0x095E[0]     M_INTEGER            0                  0x0              
 * 0x0A02[4:0]   N_ADD_0P5            0                  0x00             
 * 0x0A03[4:0]   N_CLK_TO_OUTX_EN     7                  0x07             
 * 0x0A04[4:0]   N_PIBYP              1                  0x01             
 * 0x0A05[4:0]   N_PDNB               7                  0x07             
 * 0x0A14[3]     N0_HIGH_FREQ         0                  0x0              
 * 0x0A1A[3]     N1_HIGH_FREQ         0                  0x0              
 * 0x0A20[3]     N2_HIGH_FREQ         0                  0x0              
 * 0x0A26[3]     N3_HIGH_FREQ         0                  0x0              
 * 0x0B44[3:0]   PDIV_ENB             15                 0xF              
 * 0x0B4A[4:0]   N_CLK_DIS            8                  0x08             
 * 0x0B57[11:0]  VCO_RESET_CALCODE    270                0x10E
 * 
 *
 */

#endif