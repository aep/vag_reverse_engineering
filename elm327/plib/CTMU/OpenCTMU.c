//#include <p18cxxx.h>
#include <ctmu.h>

/*************************************************************************************
Function            : void OpenCTMU(unsigned char config1, unsigned char config2, unsigned char config3)

Overview           : This function configures the CTMU.

Parameters        : config1 - This contains the parameters to be configured in the
                           CTMUCONH register as defined below


                            Enable/Disable bit
                                  *CTMU_ENABLE
 			  *CTMU_DISABLE

                            Idle Mode bit
			  *CTMU_IDLE_STOP
			  *CTMU_IDLE_CONTINUE

			Time Generation Enable bit 						 
			  *CTMU_TIME_GEN_ENABLE        
			  *CTMU_TIME_GEN_DISABLE      

			Edge Enable bit
			  *CTMU_EDGE_ENABLE
			  *CTMU_EDGE_DISABLE

			Edge sequence Enable bit
			  *CTMU_EDGE_SEQUENCE_ON
			  *CTMU_EDGE_SEQUENCE_OFF

			Analog Current Source Control bit
			  *CTMU_ANA_CURR_SOURCE_GND
			  *CTMU_ANA_CURR_SOURCE_NOT_GND

			Trigger Control bit
			  *CTMU_TRIG_OUTPUT_ENABLE
			  *CTMU_TRIG_OUTPUT_DISABLE
			  
			Enable/Disable  Interrupt  
             *CTMU_INT_ON
			 *CTMU_INT_OFF					 

			config2 - This contains the parameters to be configured in the
                           CTMUCONL register as defined below

			Edge2 Polarity select bit
			  *CTMU_EDGE2_POLARITY_POS
			  *CTMU_EDGE2_POLARITY_NEG

			Edge2 Source Select bit
			  *CTMU_EDGE2_SOURCE_CTED1
			  *CTMU_EDGE2_SOURCE_CTED2
			  *CTMU_EDGE2_SOURCE_OC1
			  *CTMU_EDGE2_SOURCE_TIMER1

			Edge1 Polarity Select bit
			  *CTMU_EDGE1_POLARITY_POS
			  *CTMU_EDGE1_POLARITY_NEG

			Edge1 Source Select bits
			  *CTMU_EDGE1_SOURCE_CTED1
			  *CTMU_EDGE1_SOURCE_CTED2
			  *CTMU_EDGE1_SOURCE_OC1
			  *CTMU_EDGE1_SOURCE_TIMER1

		 config3 - This contains the parameters to be configured in the
		 CTMU1CON register as defined below

			Current Source Trim bits
			  *CTMU_POS_CURR_TRIM_62
			  *CTMU_POS_CURR_TRIM_60
			  *....
			  *CTMU_POS_CURR_TRIM_4
			  *CTMU_POS_CURR_TRIM_2
			  *CTMU_NOMINAL_CURRENT
			  *CTMU_NEG_CURR_TRIM_2
			  *CTMU_NEG_CURR_TRIM_4
			  *...
			  *CTMU_NEG_CURR_TRIM_60
			  *CTMU_NEG_CURR_TRIM_62

			Current Source Range Select bits
			  *CTMU_CURR_RANGE_100_BASE_CURR
			  *CTMU_CURR_RANGE_10_BASE_CURR
			  *CTMU_CURR_RANGE_BASE_CURR
			  *CTUM_CURR_SOURCE_DISABLE


Returns           : None

Remarks           : This function configures the CTMU for the following parameters:
		       Operating mode, Sleep mode behavior, Edge Select,Delay generation,Current
		       source trim and current source range select.
************************************************************************************************/

#if	defined (CTMU_V1) || defined (CTMU_V1_1) 

void OpenCTMU(unsigned char config1,unsigned char config2,unsigned char config3)
{
   unsigned char i;

 /*Select the current source range and adjust the current source */
    CTMUICON= config3 ;

    CTMUCONHbits.IDISSEN = 1;  //discharge the connected circuit
    for(i=0;i<150;i++)
    Nop();
    CTMUCONHbits.IDISSEN = 0;

    CTMUCONHbits.CTMUEN = 0;
	
 /*Enable/Disable Interrupt*/
    if(config1 & 0b01000000)
	
	  {PIR3bits.CTMUIF = 0; 
	  INTCON |= 0x40; 
	  PIE3bits.CTMUIE = 1; 
	  }
	
	else
      PIE3bits.CTMUIE = 0;
	  
 /*Disable the current source*/
    CTMUCONLbits.EDG1STAT = 0;
    CTMUCONLbits.EDG2STAT = 0;

  /*Configure the CTMU*/
    CTMUCONH = (config1&0x3F);
    CTMUCONL = (config2&0xFC);

    CTMUCONHbits.CTMUEN = 1;  //enable CTMU
}

#endif

#if	defined (CTMU_V2) 
void OpenCTMU(unsigned char config1,unsigned char config2,unsigned char config3,unsigned char config4)
{
   unsigned char i;

 /*Select the current source range and adjust the current source */
    CTMUCON2= config4 ;
	CTMUCON1= config1;
	CTMUCON3= config2 ;
	CTMUCON4= config3;
	
    CTMUCON1bits.IDISSEN = 1;  //discharge the connected circuit
    for(i=0;i<150;i++)
    Nop();
    CTMUCON1bits.IDISSEN = 0;

    CTMUCON1bits.CTMUEN = 0;
	
 /*Enable/Disable Interrupt*/
    if(config1 & 0b01000000)
	
	  {PIR3bits.CTMUIF = 0; 
	  INTCON |= 0x40; 
	  PIE3bits.CTMUIE = 1; 
	  }
	
	else
      PIE3bits.CTMUIE = 0;
	  
 /*Disable the current source*/
    CTMUCON4bits.EDG1STAT = 0;
    CTMUCON4bits.EDG2STAT = 0;

  /*Configure the CTMU*/
    CTMUCON1 = (config1&0x3F);
    CTMUCON4 = (config2&0xFC);

    CTMUCON1bits.CTMUEN = 1;  //enable CTMU
}

#endif
