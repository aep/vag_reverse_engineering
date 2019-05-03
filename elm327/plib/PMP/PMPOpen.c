 
#include "pmp.h"

#if defined (pmp_v1_1) || defined (pmp_v1_2) || defined (pmp_v1_3)
/******************************************************************************
  Function:        void PMPOpen(UINT control, UINT mode, UINT port, UINT addrs, BYTE interrupt_config)
 
  PreCondition:    None
 
  Side Effects:    Configures the PMP module as per the input data
  
  Overview:        Provides method for setting PMP registers using bit masks
                   provided in this header file.
 
  Input:           control - This contains the parameters to be configured in the 
                              PMCON register as defined below
							  
                              PMP Enable/Disable
                                *	BIT_PMP_ON
                                *	BIT_PMP_OFF
                              Idle mode operation
                                *	BIT_SIDL_ON
                                *	BIT_SIDL_OFF
                              Address/Data Mulitiplexing
                                *	BIT_ADDR_MUX_16_8
                                *	BIT_ADDR_MUX_8_8
                                *	BIT_ADDR_MUX_NONE 
                              Byte Enable
                                *	BIT_BE_ON
                                *	BIT_BE_OFF 
                              RD and WR Strobe Enable
                                *	BIT_RD_ON
                                *	BIT_WR_ON
                                *	BIT_RD_WR_ON
                                *	BIT_RD_WR_OFF
                              Chip Function select
                                *	BIT_USE_CS2_CS1
                                *	BIT_USE_CS2
                                *	BIT_USE_CS_OFF 
                              Address Latch Polarity
                                *	BIT_LATCH_HI
                                *	BIT_LATCH_LO
                              CS Polarity
                                *	BIT_CS2_HI
                                *	BIT_CS2_LO
                                *	BIT_CS1_HI
                                *	BIT_CS1_LO                                
                              Byte Enable Polarity
                                *	BIT_BE_HI
                                *	BIT_BE_LO 
                              RD and WR Polarity
                                *	BIT_WR_HI
                                *	BIT_WR_LO
                                *	BIT_RD_HI
                                *	BIT_RD_LO
                                *	BIT_RD_WR_HI
                                *	BIT_RD_WR_LO     
                                      
                    mode    - This contains the parameters to be configured in the 
                              PMMODE register as defined below
							  
                              Interrupt Request Mode
                                *	BIT_IRQ_BUF
                                *	BIT_IRQ_RW
                                *	BIT_IRQ_NONE
                              Increment Mode
                                *	BIT_INC_ADDR_AUTO
                                *	BIT_INC_ADDR_DEC
                                *	BIT_INC_ADDR_INC
                                *	BIT_INC_ADDR_NONE
                              8/16 Bit Mode
                                *	BIT_DATA_16
                                *	BIT_DATA_8
                              Parallel Port mode
                                *	BIT_MODE_MASTER_1
                                *	BIT_MODE_MASTER_2
                                *	BIT_MODE_SLAVE_ENH
                                *	BIT_MODE_SLAVE
                              Data Setup to Read/write wait Configuration
                                *	BIT_WAITB_4_TCY
                                *	BIT_WAITB_3_TCY
                                *	BIT_WAITB_2_TCY
                                *	BIT_WAITB_1_TCY
                              Read to Byter Enable Strobe wait configuration
                                *	BIT_WAITM_15_TCY
                                *	BIT_WAITM_14_TCY   
                                *	BIT_WAITM_13_TCY
                                *	BIT_WAITM_12_TCY  
                                *	BIT_WAITM_11_TCY  
                                *	BIT_WAITM_10_TCY
                                *	BIT_WAITM_9_TCY
                                *	BIT_WAITM_8_TCY
                                *	BIT_WAITM_7_TCY
                                *	BIT_WAITM_6_TCY
                                *	BIT_WAITM_5_TCY
                                *	BIT_WAITM_4_TCY
                                *	BIT_WAITM_3_TCY
                                *	BIT_WAITM_2_TCY
                                *	BIT_WAITM_1_TCY
                                *	BIT_WAITM_0_TCY
                              Data hold after strobe wait state configuration  
                                *	BIT_WAITE_4_TCY
                                *	BIT_WAITE_3_TCY
                                *	BIT_WAITE_2_TCY
                                *	BIT_WAITE_1_TCY                            
                                
                    port    - This contains the parameters to be configured in the
                              PMAEN register as defined below
                              Configure pins as PMA or I/O
                                *	BIT_P_ALL  
                                *	BIT_P_NONE 
                              Configure PMP address port enable bit
                                *	BIT_P15   
                                *	BIT_P14
                                *	BIT_P13
                                *	BIT_P12
                                *	BIT_P11
                                *	BIT_P10
                                *	BIT_P9
                                *	BIT_P8
                                *	BIT_P7
                                *	BIT_P6
                                *	BIT_P5
                                *	BIT_P4
                                *	BIT_P3
                                *	BIT_P2
                                *	BIT_P1
                                *	BIT_P0                          
 
                    addrs   - This contains the parameters to be configured in the
                              PMADDR register as defined below
							  
                              Chip Select 
                                *	BIT_CS2_ON
                                *	BIT_CS2_OFF 
                                *	BIT_CS1_ON 
                                *	BIT_CS1_OFF
                              Destination Address
                                *	BIT_A13
                                *	BIT_A12
                                *	BIT_A11
                                *	BIT_A10
                                *	BIT_A9
                                *	BIT_A8
                                *	BIT_A7
                                *	BIT_A6
                                *	BIT_A5
                                *	BIT_A4
                                *	BIT_A3
                                *	BIT_A2
                                *	BIT_A1
                                *	BIT_A0                                 
                    
                interrupt_config - PMP interrupt priority and enable/disable information 
                             as defined below
							 
                            PMP Interrupt enable/disable
			 *	BIT_INT_ON
			 *	BIT_INT_OFF
		       PMP Interrupt priority
                                *	BIT_INT_PRI_HIGH
                                *	BIT_INT_PRI_LOW
  
  Returns:          None           
 *****************************************************************************/
void PMPOpen(UINT control, UINT mode, UINT port, UINT addrs, BYTE interrupt_config)
{
    PMSTATH = 0;
	PMSTATL = 0;
    PIE1bits.PMPIE = 0;
    PIR1bits.PMPIF = 0;
    IPR1bits.PMPIP = 0;
    
    PMCONL = (BYTE) (0x00FF & control);
	PMCONH = (BYTE) ((0xFF00 & control)>>8);
    PMMODEL = (BYTE) (0x00FF & mode);
	PMMODEH = (BYTE) ((0xFF00 & mode)>>8);
    PMEL = (BYTE) (0x00FF & port);
	PMEH = (BYTE) ((0xFF00 &port)>>8);
    PMADDRL = (BYTE) (0x00FF & addrs);
	PMADDRH = (BYTE) ((0xFF00 &addrs)>>8);
    
    IPR1bits.PMPIP = interrupt_config & 0x01;     // mask just the pmp priority bits  
    PIE1bits.PMPIE = (interrupt_config & 0x02)>>1;         // mask just the pmp interrupt enable bit
    PMCONHbits.PMPEN = 1;        // last, enable the module
}

#endif


