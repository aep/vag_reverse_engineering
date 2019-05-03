#include <p18cxxx.h>
#include <timers.h>

/********************************************************************
*    Function Name:  OpenTimer5                                     *
*    Return Value:   void                                           *
*    Parameters:     config: bit definitions to configure Timer5    *
*    Description:    This routine first resets the Timer5 regs      *
*                    to the POR state and then configures the       *
*                    interrupt and clock source.                    *
*    Notes:          The bit definitions for config can be found    *
*                    in the timers.h file.                          *
********************************************************************/

#if defined (TMR_V5)

void OpenTimer5(unsigned char config,unsigned int t5pr)
{

  T5CON = (0xfe & config);  // Set all configuration values, but
                            // don't start timer yet
  TMR5H = TMR5L = 0;                 // Clear Timer5

  PR5L =   t5pr;
  PR5H =  (t5pr>>8);

  PIR3bits.TMR5IF = 0;

  if(config & 0x01)         // Enable timer interrupts?
    PIE3bits.TMR5IE = 1;
  else
    PIE3bits.TMR5IE = 0;

  T5CONbits.TMR5ON = 1; // Turn on Timer5
}
#endif


#if defined (TMR_V7) || defined (TMR_V7_1) || defined (TMR_V7_3) || defined (TMR_V7_4)
	 
void OpenTimer5(unsigned char config, unsigned char config1)
{
  T5GCON = (0XF3 & config1);
  
  T5CON = (0x7F & config) << 1 ;    
    	
  TMR5H=0;             // Clear out timer registers
  TMR5L=0;
  
  PIR5bits.TMR5IF=0;
  
#if defined (TMR_V7_1_INT_V1) || defined (TMR_V7_4_INT_V1)
  PIR5bits.TMR5GIF=0;
#else
  PIR3bits.TMR5GIF=0;
#endif  

	 


  if(config&0x80)      // Enable interrupts if selected
    PIE5bits.TMR5IE=1;
  else
    PIE5bits.TMR5IE=0;

	
#if defined (TMR_V7_1_INT_V1) || defined (TMR_V7_4_INT_V1)
  if(config1 & 0x04)
    PIE5bits.TMR5GIE=1;
  else
    PIE5bits.TMR5GIE=0;
#else
  if(config1 & 0x04)
    PIE3bits.TMR5GIE=1;
  else
    PIE3bits.TMR5GIE=0;
#endif
 
#if defined (TMR_V7_1)
  if(T5GCONbits.TMR5GE)	
      T5GCONbits.T5GGO_NOT_T5DONE = 1;
#else
  if(T5GCONbits.TMR5GE)	
      T5GCONbits.T5GGO = 1;
#endif 

  
  T5CONbits.TMR5ON = 1;  // Start Timer5
  
}
#endif 
