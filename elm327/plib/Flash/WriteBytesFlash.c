#include "flash.h"

#ifdef _OMNI_CODE_
#pragma warning push
#pragma warning disable 1467
#pragma warning disable 359
#endif

/*********************************************************************
  Function:        	void WriteBytesFlash(unsigned long startaddr, unsigned long num_bytes, unsigned char *flash_array)

  PreCondition:    	None

  Input:           	startaddr - Strating address from which flash has to be written
  num_bytes - Number of bytes of flash to be written
 *flash_array - Pointer to array contents of which has to be written to flash

 Output:          	None

 Side Effects:    	None

 Overview:        	The function writes flash from starting address specified
 till number of bytes specified

 Note:            	1. Necessary to erase flash block (number of bytes specified in device data sheet) exclusively in application before writing 
 if application had written data into to this block of flash(after erasing followed by programming).
 2. Writing can be done directly without erase if these bytes of flash is being written for the first time after programming

 ********************************************************************/
#if defined (FLASH_V1_1) || defined (FLASH_V1_2) || defined (FLASH_V1_4) || defined (FLASH_V1_6)
void WriteBytesFlash(unsigned long startaddr, unsigned int num_bytes, unsigned char *flash_array)
{
	unsigned char write_byte=0,flag=0;
#ifndef _OMNI_CODE_
	DWORD_VAL flash_addr;
#else
	char *startptr,*saveptr;
	unsigned long saddress;
#if _ERRATA_TYPES & ERRATA_TBLWTINT
	unsigned char saved1,saved2,saved3,saved4;
#endif
#endif
#ifndef _OMNI_CODE_
	flash_addr.Val = startaddr;
#else
	saddress = startaddr;
#endif

	startaddr /= FLASH_WRITE_BLOCK ;	//Allign the starting address block
	startaddr *= FLASH_WRITE_BLOCK ;
	startaddr += FLASH_WRITE_BLOCK ;

#ifndef _OMNI_CODE_
	write_byte = startaddr - flash_addr.Val;
#else
	write_byte = startaddr - saddress;
#endif

	while(num_bytes)
	{
#ifndef _OMNI_CODE_
		TBLPTRU = flash_addr.byte.UB;						//Load the address to Address pointer registers
		TBLPTRH = flash_addr.byte.HB;	
		TBLPTRL	= flash_addr.byte.LB;
#else
		startptr = (const char *) saddress;
#if _ERRATA_TYPES & ERRATA_TBLWTINT
		/* Errata document (B3,B4,B5) advises that these devices need all *
		 * interrupt enable bits clear during TBLWT instruction.          *
		 * (That document mentions INTCON2 but it has no 'enable' bits.)  */
		saved1=INTCON; INTCON=0;	// Saving interrupt registers
		saved2=INTCON3; INTCON3=0;
		saved3=PIE1; PIE1=0;		
		saved4=PIE2; PIE2=0;		
#endif
#endif

		while(write_byte--)
		{
#ifndef _OMNI_CODE_
			TABLAT = *flash_array++;
			_asm  TBLWTPOSTINC 	_endasm
#else
			*startptr++ = *flash_array++;
#endif
			if(--num_bytes==0)	break;
		}

#if defined(_OMNI_CODE_) && (_ERRATA_TYPES & ERRATA_TBLWTINT)
		PIE1=saved3;		  // restore the interrupt registers
		PIE2=saved4; 	
		INTCON3=saved2;   
		INTCON=saved1;           
#endif
#ifndef _OMNI_CODE_
		TBLPTRU = flash_addr.byte.UB;	//Load the address to Address pointer registers
		TBLPTRH = flash_addr.byte.HB;	
		TBLPTRL	= flash_addr.byte.LB;
#else
		saveptr  = startptr; 
		startptr = (const char *) saddress;
#endif
		//*********** Flash write sequence ***********************************
		EECON1bits.EEPGD = 1;  // point to Flash program memory       
		EECON1bits.CFGS = 0;  // access Flash program memory   
		EECON1bits.WREN = 1;
		if(INTCONbits.GIE)
		{
			INTCONbits.GIE = 0;
			flag=1;
		}		  
		EECON2 = 0x55;
		EECON2 = 0xAA;
		EECON1bits.WR =1;
		EECON1bits.WREN = 0 ; 
		if(flag)
		{
			INTCONbits.GIE = 1;	
			flag=0;
		}
		write_byte = FLASH_WRITE_BLOCK;
#ifndef _OMNI_CODE_
		flash_addr.Val = flash_addr.Val + FLASH_WRITE_BLOCK;	//increment to one block of 64 bytes
#else
		saddress = (unsigned long)saveptr;
#endif
	}

}

#elif defined (FLASH_V1_3) || defined (FLASH_V1_5) || defined (FLASH_V2_1)  
void WriteBytesFlash(unsigned long startaddr, unsigned int num_bytes, unsigned char *flash_array)
{
	unsigned char write_byte=0,flag=0;
#ifndef _OMNI_CODE_
	DWORD_VAL flash_addr;
#else
	char *startptr,*saveptr;
	unsigned long saddress;
#if _ERRATA_TYPES & ERRATA_TBLWTINT
	unsigned char saved1,saved2,saved3,saved4;
#endif    
#endif

#ifndef _OMNI_CODE_
	flash_addr.Val = startaddr;
#else
	saddress = startaddr;
#endif

	startaddr /= FLASH_WRITE_BLOCK ;	//Allign the starting address block
	startaddr *= FLASH_WRITE_BLOCK ;
	startaddr += FLASH_WRITE_BLOCK ;

#ifndef _OMNI_CODE_
	write_byte = startaddr - flash_addr.Val;
#else
	write_byte = startaddr - saddress;
#endif

	while(num_bytes)
	{
#ifndef _OMNI_CODE_
		TBLPTRU = flash_addr.byte.UB;						//Load the address to Address pointer registers
		TBLPTRH = flash_addr.byte.HB;	
		TBLPTRL	= flash_addr.byte.LB;
#else
		startptr = (const char *) saddress;
#if _ERRATA_TYPES & ERRATA_TBLWTINT
		/* Errata document (B3,B4,B5) advises that these devices need all *
		 * interrupt enable bits clear during TBLWT instruction.          *
		 * (That document mentions INTCON2 but it has no 'enable' bits.)  */
		saved1=INTCON; INTCON=0;	// Saving interrupt registers
		saved2=INTCON3; INTCON3=0;
		saved3=PIE1; PIE1=0;		
		saved4=PIE2; PIE2=0;		
#endif
#endif

		while(write_byte--)
		{
#ifndef _OMNI_CODE_
			TABLAT = *flash_array++;
			_asm  TBLWTPOSTINC 	_endasm
#else
			*startptr++ = *flash_array++;
#endif
				if(--num_bytes==0)	break;
		}

#if defined(_OMNI_CODE_) && (_ERRATA_TYPES & ERRATA_TBLWTINT)
		PIE1=saved3;		  // restore the interrupt registers
		PIE2=saved4; 	
		INTCON3=saved2;   
		INTCON=saved1;           
#endif
#ifndef _OMNI_CODE_
		TBLPTRU = flash_addr.byte.UB;	//Load the address to Address pointer registers
		TBLPTRH = flash_addr.byte.HB;	
		TBLPTRL	= flash_addr.byte.LB;
#else
		saveptr  = startptr; 
		startptr = (const char *) saddress;
#endif
		//*********** Flash write sequence ***********************************
		EECON1bits.WREN = 1;
		if(INTCONbits.GIE)
		{
			INTCONbits.GIE = 0;
			flag=1;
		}		  
		EECON2 = 0x55;
		EECON2 = 0xAA;
		EECON1bits.WR =1;
		EECON1bits.WREN = 0 ; 
		if(flag)
		{
			INTCONbits.GIE = 1;	
			flag=0;
		}
		write_byte = FLASH_WRITE_BLOCK;
#ifndef _OMNI_CODE_
		flash_addr.Val = flash_addr.Val + FLASH_WRITE_BLOCK;	//increment to one block of 64 bytes
#else
		saddress = (unsigned long)saveptr;
#endif
	}

}

#endif

#ifdef _OMNI_CODE_
#pragma warning pop
#endif

