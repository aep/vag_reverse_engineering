#include "flash.h"

 /*********************************************************************
 Function:        	void EraseFlash(unsigned long startaddr, unsigned long endaddr)

 PreCondition:    	None
                  
 Input:           	startaddr - Strating address from which flash has to be erased
			endaddr - End address till which flash has to be erased
 
 Output:          	None
 
 Side Effects:    	Flash will be erased in blocks of number of bytes specified in device data sheet
 
 Overview:        	The function erases flash from starting address in terms of number of bytes specified in device data sheet
			till end address or nearest multiple of number of bytes specified in device data sheet
                   
 Note:            	1. If number of bytes between strating and end address in not in multiples 
			    of number of bytes specified in device data sheet, then excessive memory is erased upto nearest next 
			    multiple of number of bytes specified in device data sheet
			2. The starting and end address has to be in blocks of number of bytes specified in device data sheet
			     else function will allign the address to nearest previous and next 
			     number of bytes specified in device data sheet alligned address respectively
 ********************************************************************/
#if defined (FLASH_V1_1) || defined (FLASH_V1_2) || defined (FLASH_V1_4) || defined (FLASH_V1_6) 
void EraseFlash(unsigned long startaddr, unsigned long endaddr)
{
unsigned char flag=0;
DWORD_VAL flash_addr;
		
		flash_addr.Val = startaddr;
		
		while(flash_addr.Val<endaddr)
		{
			TBLPTRU = flash_addr.byte.UB;						//Load the address to Address pointer registers
			TBLPTRH = flash_addr.byte.HB;	
			TBLPTRL	= flash_addr.byte.LB;
			//*********Flash Erase sequence*****************
			EECON1bits.EEPGD = 1;  // point to Flash program memory       
			EECON1bits.CFGS = 0;  // access Flash program memory          
			EECON1bits.WREN = 1;
			EECON1bits.FREE = 1;
			if(INTCONbits.GIE)
			{
				INTCONbits.GIE = 0;
				flag=1;
			}
			EECON2 = 0x55;
			EECON2 = 0xAA;
			EECON1bits.WR = 1;
			if(flag)
				INTCONbits.GIE = 1;
			
			flash_addr.Val = flash_addr.Val + FLASH_ERASE_BLOCK;
		}
}

#elif defined (FLASH_V1_3) || defined (FLASH_V1_5) || defined (FLASH_V2_1)  
void EraseFlash(unsigned long startaddr, unsigned long endaddr)
{
unsigned char flag=0;
DWORD_VAL flash_addr;

		flash_addr.Val = startaddr;
		
		while(flash_addr.Val<endaddr)
		{
			TBLPTRU = flash_addr.byte.UB;						//Load the address to Address pointer registers
			TBLPTRH = flash_addr.byte.HB;	
			TBLPTRL	= flash_addr.byte.LB;
			//*********Flash Erase sequence*****************
			EECON1bits.WREN = 1;
			EECON1bits.FREE = 1;
			if(INTCONbits.GIE)
			{
				INTCONbits.GIE = 0;
				flag=1;
			}
			EECON2 = 0x55;
			EECON2 = 0xAA;
			EECON1bits.WR = 1;
			if(flag)
				INTCONbits.GIE = 1;
			
			flash_addr.Val = flash_addr.Val + FLASH_ERASE_BLOCK;
		}
}

#endif

