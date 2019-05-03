#include <p18cxxx.h>
#include <ancomp.h>


#if defined (ANCOM_V1) || defined (ANCOM_V2) || defined (ANCOM_V3) || defined (ANCOM_V4)
/*************************************************************************************
Function :       void Close_ancomp(void)

Overview :    This function turns off the Comparator module and disables the Comparator interrupts

Parameters :  None

Returns :        None

Remarks :     This function first disables the Comparator interrupt and then turns off the Comparator
		module.The Interrupt Flag bit (CMIF) is also cleared.
            
***************************************************************************************/ 
void Close_ancomp( void )
{
	CMCON |= 0b00000111;
	PIR2bits.CMIF = 0;
	PIE2bits.CMIE = 0;
}

#elif defined (ANCOM_V5)  || defined (ANCOM_V8) || defined (ANCOM_V8_1)
/*************************************************************************************
Function :       void Close_ancomp1(void)

Overview :    This function turns off the Comparator1 module and disables the Comparator1 interrupts

Parameters :  None

Returns :        None

Remarks :     This function first disables the Comparator1 interrupt and then turns off the Comparator1
		module.The Interrupt Flag bit (C1IF) is also cleared.
            
***************************************************************************************/ 
void Close_ancomp1( void )
{
	CM1CON0 &= 0b01111111;
	PIR2bits.C1IF = 0;
	PIE2bits.C1IE = 0;
} 

/*************************************************************************************
Function :       void Close_ancomp2(void)

Overview :    This function turns off the Comparator2 module and disables the Comparator2 interrupts

Parameters :  None

Returns :        None

Remarks :     This function first disables the Comparator2 interrupt and then turns off the Comparator2
		module.The Interrupt Flag bit (C2IF) is also cleared.
            
***************************************************************************************/ 
void Close_ancomp2( void )
{
	CM2CON0 &= 0b01111111;
	PIR2bits.C2IF = 0;
	PIE2bits.C2IE = 0;
} 

#elif defined (ANCOM_V6) || defined (ANCOM_V7) || defined (ANCOM_V9)
/*************************************************************************************
Function :       void Close_ancomp1(void)

Overview :    This function turns off the Comparator1 module and disables the Comparator1 interrupts

Parameters :  None

Returns :        None

Remarks :     This function first disables the Comparator1 interrupt and then turns off the Comparator1
		module.The Interrupt Flag bit (C1IF) is also cleared.
            
***************************************************************************************/ 
void Close_ancomp1( void )
{
	CM1CON &= 0b01111111;
	PIR2bits.CM1IF = 0;
	PIE2bits.CM1IE = 0;
} 
/*************************************************************************************
Function :       void Close_ancomp2(void)

Overview :    This function turns off the Comparator2 module and disables the Comparator2 interrupts

Parameters :  None

Returns :        None

Remarks :     This function first disables the Comparator2 interrupt and then turns off the Comparator2
		module.The Interrupt Flag bit (C2IF) is also cleared.
            
***************************************************************************************/ 
void Close_ancomp2( void )
{
	CM2CON &= 0b01111111;
	PIR2bits.CM2IF = 0;
	PIE2bits.CM2IE = 0;
} 

#elif defined (ANCOM_V10) || defined (ANCOM_V10_2) || defined (ANCOM_V10_3) || defined (ANCOM_V11)
/*************************************************************************************
Function :       void Close_ancomp1(void)

Overview :    This function turns off the Comparator1 module and disables the Comparator1 interrupts

Parameters :  None

Returns :        None

Remarks :     This function first disables the Comparator1 interrupt and then turns off the Comparator1
		module.The Interrupt Flag bit (CMP1IF) is also cleared.
            
***************************************************************************************/ 
void Close_ancomp1( void )
{
	CM1CON &= 0b01111111;
	
	CMP1_IF = 0;
	CMP1_IE = 0;

} 
/*************************************************************************************
Function :       void Close_ancomp2(void)

Overview :    This function turns off the Comparator2 module and disables the Comparator2 interrupts

Parameters :  None

Returns :        None

Remarks :     This function first disables the Comparator2 interrupt and then turns off the Comparator2
		module.The Interrupt Flag bit (CMP2IF) is also cleared.
            
***************************************************************************************/ 
void Close_ancomp2( void )
{
	CM2CON &= 0b01111111;
	CMP2_IF = 0;
	CMP2_IE = 0;
} 

#if defined (ANCOM_V10) || defined (ANCOM_V11)
/*************************************************************************************
Function :       void Close_ancomp3(void)

Overview :    This function turns off the Comparator2 module and disables the Comparator2 interrupts

Parameters :  None

Returns :        None

Remarks :     This function first disables the Comparator2 interrupt and then turns off the Comparator2
		module.The Interrupt Flag bit (CMP3IF) is also cleared.
            
***************************************************************************************/ 
void Close_ancomp3( void )
{
	CM3CON &= 0b01111111;
	CMP3_IF = 0;
	CMP3_IE = 0;
} 
#endif

#elif defined (ANCOM_V10_1)
/*************************************************************************************
Function :       void Close_ancomp1(void)

Overview :    This function turns off the Comparator1 module and disables the Comparator1 interrupts

Parameters :  None

Returns :        None

Remarks :     This function first disables the Comparator1 interrupt and then turns off the Comparator1
		module.The Interrupt Flag bit (CMP1IF) is also cleared.
            
***************************************************************************************/ 
void Close_ancomp1( void )
{
	CM1CON &= 0b01111111;
	PIR2bits.CM1IF = 0;
	PIE2bits.CM1IE = 0;
} 
/*************************************************************************************
Function :       void Close_ancomp2(void)

Overview :    This function turns off the Comparator2 module and disables the Comparator2 interrupts

Parameters :  None

Returns :        None

Remarks :     This function first disables the Comparator2 interrupt and then turns off the Comparator2
		module.The Interrupt Flag bit (CMP2IF) is also cleared.
            
***************************************************************************************/ 
void Close_ancomp2( void )
{
	CM2CON &= 0b01111111;
	PIR2bits.CM2IF = 0;
	PIE2bits.CM2IE = 0;
} 
/*************************************************************************************
Function :       void Close_ancomp3(void)

Overview :    This function turns off the Comparator2 module and disables the Comparator2 interrupts

Parameters :  None

Returns :        None

Remarks :     This function first disables the Comparator2 interrupt and then turns off the Comparator2
		module.The Interrupt Flag bit (CMP3IF) is also cleared.
            
***************************************************************************************/ 
void Close_ancomp3( void )
{
	CM3CON &= 0b01111111;
	PIR5bits.CM3IF = 0;
	PIE5bits.CM3IE = 0;
} 

#endif
//---------------------------------------
