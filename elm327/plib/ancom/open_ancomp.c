#include <p18cxxx.h>
#include <ancomp.h>

#if defined (ANCOM_V1)
/*************************************************************************************
Function :       void Open_ancomp(unsigned char config)

Overview :    This routine configures Reference Voltage level and Comparator module.

Parameters :  config - This contains the parameters to be configured in the CVRCON & CMxCON   
                         Registers.

Returns :        None

Remarks :     This function configures comparator with channel of selection for positive and negetive
		input terminals,  configures interrupts, reference voltage module is configured based on input
		parameters.            
***************************************************************************************/ 
void Open_ancomp(unsigned char config)
{
	PIE2bits.CMIE = 0;	
	CMCON = (0b00111111 & config);
	PIR2bits.CMIF = 0;
	if(config & 0b10000000)
		PIE2bits.CMIE = 1;
	
	//check for Analog IP and OP
	config &= 0b00000111; 	
	if(config == 1)		{TRISDbits.TRISD1 = 1;TRISDbits.TRISD0 = 1;TRISEbits.TRISE1 = 0;}
	else if(config == 2){TRISDbits.TRISD1 = 1;TRISDbits.TRISD0 = 1;TRISDbits.TRISD3 = 1;TRISDbits.TRISD2 = 1;}
	else if(config == 3){TRISDbits.TRISD1 = 1;TRISDbits.TRISD0 = 1;TRISEbits.TRISE1 = 0;
						 TRISDbits.TRISD3 = 1;TRISDbits.TRISD2 = 1;TRISEbits.TRISE2 = 0;}
	else if(config == 4){TRISDbits.TRISD1 = 1;TRISDbits.TRISD0 = 1;TRISDbits.TRISD3 = 1;}
	else if(config == 5){TRISDbits.TRISD1 = 1;TRISDbits.TRISD0 = 1;TRISEbits.TRISE1 = 0;
						 TRISDbits.TRISD3 = 1;TRISEbits.TRISE2 = 0;}
	else if(config == 6)
		{
		if(CMCON & 0b00001000)
				{TRISDbits.TRISD0 = 1;TRISDbits.TRISD2 = 1;}
		else 	{TRISDbits.TRISD1 = 1;TRISDbits.TRISD3 = 1;}
		}
}
#elif defined (ANCOM_V2)
/*************************************************************************************
Function :       void Open_ancomp(unsigned char config)

Overview :    This routine configures Reference Voltage level and Comparator module.

Parameters :  config - This contains the parameters to be configured in the CVRCON & CMxCON   
                         Registers.

Returns :        None

Remarks :     This function configures comparator with channel of selection for positive and negetive
		input terminals,  configures interrupts, reference voltage module is configured based on input
		parameters.            
***************************************************************************************/ 
void Open_ancomp(unsigned char config)
{
	PIE2bits.CMIE = 0;	
	CMCON = (0b00111111 & config);
	PIR2bits.CMIF = 0;
	if(config & 0b10000000)
		PIE2bits.CMIE = 1;
	//check for Analog IP and OP
	config &= 0b00000111; 	
	if(config == 1)		{TRISFbits.TRISF6 = 1;TRISFbits.TRISF5 = 1;TRISFbits.TRISF2 = 0;}
	else if(config == 2){TRISFbits.TRISF6 = 1;TRISFbits.TRISF5 = 1;TRISFbits.TRISF4 = 1;TRISFbits.TRISF3 = 1;}
	else if(config == 3){TRISFbits.TRISF6 = 1;TRISFbits.TRISF5 = 1;TRISFbits.TRISF2 = 0;
						 TRISFbits.TRISF4 = 1;TRISFbits.TRISF3 = 1;TRISFbits.TRISF1 = 0;}
	else if(config == 4){TRISFbits.TRISF6 = 1;TRISFbits.TRISF5 = 1;TRISFbits.TRISF4 = 1;}
	else if(config == 5){TRISFbits.TRISF6 = 1;TRISFbits.TRISF5 = 1;TRISFbits.TRISF2 = 0;
						 TRISFbits.TRISF4 = 1;TRISFbits.TRISF1 = 0;}
	else if(config == 6)
		{
		if(CMCON & 0b00001000)
				{TRISFbits.TRISF5 = 1;TRISFbits.TRISF3 = 1;}
		else 	{TRISFbits.TRISF6 = 1;TRISFbits.TRISF4 = 1;}
		}
}

#elif defined (ANCOM_V3)
/*************************************************************************************
Function :       void Open_ancomp(unsigned char config)

Overview :    This routine configures Reference Voltage level and Comparator module.

Parameters :  config - This contains the parameters to be configured in the CVRCON & CMxCON   
                         Registers.

Returns :        None

Remarks :     This function configures comparator with channel of selection for positive and negetive
		input terminals,  configures interrupts, reference voltage module is configured based on input
		parameters.            
***************************************************************************************/ 
void Open_ancomp(unsigned char config)
{
	PIE2bits.CMIE = 0;	
	CMCON = (0b00111111 & config);
	PIR2bits.CMIF = 0;
	if(config & 0b10000000)
		PIE2bits.CMIE = 1;
	//check for Analog IP and OP
	config &= 0b00000111; 	
	if(config == 1)		{TRISAbits.TRISA0 = 1;TRISAbits.TRISA3 = 1;TRISAbits.TRISA4 = 0;}
	else if(config == 2){TRISAbits.TRISA0 = 1;TRISAbits.TRISA3 = 1;TRISAbits.TRISA1 = 1;TRISAbits.TRISA2 = 1;}
	else if(config == 3){TRISAbits.TRISA0 = 1;TRISAbits.TRISA3 = 1;TRISAbits.TRISA4 = 0;
						 TRISAbits.TRISA1 = 1;TRISAbits.TRISA2 = 1;TRISAbits.TRISA5 = 0;}
	else if(config == 4){TRISAbits.TRISA0 = 1;TRISAbits.TRISA3 = 1;TRISAbits.TRISA1 = 1;}
	else if(config == 5){TRISAbits.TRISA0 = 1;TRISAbits.TRISA3 = 1;TRISAbits.TRISA4 = 0;
						 TRISAbits.TRISA1 = 1;TRISAbits.TRISA5 = 0;}
	else if(config == 6)
		{
		if(CMCON & 0b00001000)
				{TRISAbits.TRISA3 = 1;TRISAbits.TRISA2 = 1;}
		else 	{TRISAbits.TRISA0 = 1;TRISAbits.TRISA1 = 1;}
		}
}

#elif defined (ANCOM_V4)
/*************************************************************************************
Function :       void Open_ancomp(unsigned char config)

Overview :    This routine configures Reference Voltage level and Comparator module.

Parameters :  config - This contains the parameters to be configured in the CVRCON & CMxCON   
                         Registers.

Returns :        None

Remarks :     This function configures comparator with channel of selection for positive and negetive
		input terminals,  configures interrupts, reference voltage module is configured based on input
		parameters.            
***************************************************************************************/ 
void Open_ancomp(unsigned char config)
{
	PIE2bits.CMIE = 0;	
	CMCON = (0b00111111 & config);
	PIR2bits.CMIF = 0;
	if(config & 0b10000000)
		PIE2bits.CMIE = 1;
	//check for Analog IP and OP
	config &= 0b00000111; 	
	if(config == 1)		{TRISAbits.TRISA0 = 1;TRISAbits.TRISA3 = 1;TRISBbits.TRISB5 = 0;}
	else if(config == 2){TRISAbits.TRISA0 = 1;TRISAbits.TRISA3 = 1;TRISAbits.TRISA1 = 1;TRISAbits.TRISA2 = 1;}
	else if(config == 3){TRISAbits.TRISA0 = 1;TRISAbits.TRISA3 = 1;TRISBbits.TRISB5 = 0;
						 TRISAbits.TRISA1 = 1;TRISAbits.TRISA2 = 1;TRISAbits.TRISA5 = 0;}
	else if(config == 4){TRISAbits.TRISA0 = 1;TRISAbits.TRISA3 = 1;TRISAbits.TRISA1 = 1;}
	else if(config == 5){TRISAbits.TRISA0 = 1;TRISAbits.TRISA3 = 1;TRISBbits.TRISB5 = 0;
						 TRISAbits.TRISA1 = 1;TRISAbits.TRISA5 = 0;}
	else if(config == 6)
		{
		if(CMCON & 0b00001000)
				{TRISAbits.TRISA3 = 1;TRISAbits.TRISA2 = 1;}
		else 	{TRISAbits.TRISA0 = 1;TRISAbits.TRISA1 = 1;}
		}
}

//------New comparator module 1 ------------  

#elif defined (ANCOM_V5) 
/*************************************************************************************
Function :       void Open_ancomp1(unsigned char config)

Overview :    This routine configures Reference Voltage level and Comparator module.

Parameters :  config - This contains the parameters to be configured in the CVRCON & CMxCON   
                         Registers.

Returns :        None

Remarks :     This function configures comparator with channel of selection for positive and negetive
		input terminals,  configures interrupts, reference voltage module is configured based on input
		parameters.            
***************************************************************************************/ 
void Open_ancomp1(unsigned char config)
{
	PIE2bits.C1IE = 0;
	CM1CON0 = (0b00111111 & config);
	if(config & 0b01000000) 
		CM2CON1 &= 0b11011111;
	else  
		CM2CON1 |= 0b00100000;

    
	PIR2bits.C1IF = 0;
	if(config & 0b10000000)
		PIE2bits.C1IE = 1;
	//check for Analog IP and OP
	config &= 0b00000011;
	if(config == 0){TRISAbits.TRISA0 = 1;}
	else if(config == 1){TRISAbits.TRISA1 = 1;}
 	else if(config == 2){TRISBbits.TRISB1 = 1;}
	else if(config == 3){TRISBbits.TRISB3 = 1;}
	if(!CM1CON0bits.C1R){TRISAbits.TRISA3 = 1;}
	if(CM1CON0bits.C1OE){TRISAbits.TRISA4 = 0;}
	CM1CON0bits.C1ON=1;
}

/*************************************************************************************
Function :       void Open_ancomp2(unsigned char config)

Overview :    This routine configures Reference Voltage level and Comparator module.

Parameters :  config - This contains the parameters to be configured in the CVRCON & CMxCON   
                         Registers.

Returns :        None

Remarks :     This function configures comparator with channel of selection for positive and negetive
		input terminals,  configures interrupts, reference voltage module is configured based on input
		parameters.            
***************************************************************************************/ 
void Open_ancomp2(unsigned char config)
{
	PIE2bits.C2IE = 0;
	CM2CON0 = (0b00111111 & config);
	if(config & 0b01000000) 
		CM2CON1 &= 0b11101111;
	else  
		CM2CON1 |= 0b00010000;

	PIR2bits.C2IF = 0;
	if(config & 0b10000000)
		PIE2bits.C2IE = 1;
	//check for Analog IP and OP
	config &= 0b00000011;
	if(config == 0){TRISAbits.TRISA0 = 1;}
	else if(config == 1){TRISAbits.TRISA1 = 1;}
 	else if(config == 2){TRISBbits.TRISB1 = 1;}
	else if(config == 3){TRISBbits.TRISB3 = 1;}
	if(!CM2CON0bits.C2R){TRISAbits.TRISA2 = 1;}
	if(CM2CON0bits.C2OE){TRISAbits.TRISA5 = 0;}
	CM2CON0bits.C2ON=1;
}

//------New comparator module 2 ------------  

#elif defined (ANCOM_V6) 
/*************************************************************************************
Function :       void Open_ancomp1(unsigned char config)

Overview :    This routine configures Reference Voltage level and Comparator module.

Parameters :  config - This contains the parameters to be configured in the CVRCON & CMxCON   
                         Registers.

Returns :        None

Remarks :     This function configures comparator with channel of selection for positive and negetive
		input terminals,  configures interrupts, reference voltage module is configured based on input
		parameters.            
***************************************************************************************/ 
void Open_ancomp1(unsigned char config)
{
	PIE2bits.CM1IE = 0;
	CM1CON = (0b01111111 & config);
	PIR2bits.CM1IF = 0;
	if(config & 0b10000000)
		PIE2bits.CM1IE = 1;
	//check for Analog IP and OP
	config &= 0x03;
	#if defined ANCOMP_IO_V1	// 64 pin devices
		{		
			if(config == 0) {TRISFbits.TRISF5 = 1;}
		}
	#else //80 pin devices
		{
			if(config == 0) {TRISFbits.TRISF5 = 1;}
			else if(config == 1){TRISHbits.TRISH6 = 1;}
		}	
	#endif
		if(CM1CONbits.CREF == 0){TRISFbits.TRISF6 = 1;}
		if(CM1CONbits.COE) {TRISFbits.TRISF2 = 0;}
	CM1CONbits.CON=1;
}

/*************************************************************************************
Function :       void Open_ancomp2(unsigned char config)

Overview :    This routine configures Reference Voltage level and Comparator module.

Parameters :  config - This contains the parameters to be configured in the CVRCON & CMxCON   
                         Registers.

Returns :        None

Remarks :     This function configures comparator with channel of selection for positive and negetive
		input terminals,  configures interrupts, reference voltage module is configured based on input
		parameters.            
***************************************************************************************/ 
void Open_ancomp2(unsigned char config)
{
	PIE2bits.CM2IE = 0;
	CM2CON = (0b01111111 & config);
	PIR2bits.CM2IF = 0;
	if(config & 0b10000000)
		PIE2bits.CM2IE = 1;
	//check for Analog IP and OP
	config &= 0x03;
	#if defined ANCOMP_IO_V1	// 64 pin devices
		{		
			if(config == 0) {TRISFbits.TRISF3 = 1;}
		}
	#else //80 pin devices
		{
			if(config == 0) {TRISFbits.TRISF3 = 1;}
			else if(config == 1){TRISHbits.TRISH4 = 1;}
			else if(config == 2){TRISHbits.TRISH5 = 1;}
		}
	#endif
	if(CM2CONbits.CREF == 0){TRISFbits.TRISF4 = 1;}
	if(CM2CONbits.COE) {TRISFbits.TRISF1 = 0;}
	CM2CONbits.CON=1;
}

#elif defined (ANCOM_V7) 
/*************************************************************************************
Function :       void Open_ancomp1(unsigned char config)

Overview :    This routine configures Reference Voltage level and Comparator module.

Parameters :  config - This contains the parameters to be configured in the CVRCON & CMxCON   
                         Registers.

Returns :        None

Remarks :     This function configures comparator with channel of selection for positive and negetive
		input terminals,  configures interrupts, reference voltage module is configured based on input
		parameters.            
***************************************************************************************/ 
void Open_ancomp1(unsigned char config)
{
	PIE2bits.CM1IE = 0;
	CM1CON = (0b01111111 & config);
	PIR2bits.CM1IF = 0;
	if(config & 0b10000000)
		PIE2bits.CM1IE = 1;
    config &= 0x03;		
	#if defined ANCOMP_IO_V2// 64 pin devices
		{		
			if(config == 0) {TRISFbits.TRISF5 = 1;}
		}
	#else //80 pin devices
		{
			if(config == 0) {TRISFbits.TRISF5 = 1;}
			else if(config == 1){TRISHbits.TRISH6 = 1;}
		}
	#endif
	if(CM1CONbits.CREF == 0){TRISFbits.TRISF6 = 1;}
	if(CM1CONbits.COE) {TRISFbits.TRISF7 = 0;}
	CM1CONbits.CON=1;
}

/*************************************************************************************
Function :       void Open_ancomp2(unsigned char config)

Overview :    This routine configures Reference Voltage level and Comparator module.

Parameters :  config - This contains the parameters to be configured in the CVRCON & CMxCON   
                         Registers.

Returns :        None

Remarks :     This function configures comparator with channel of selection for positive and negetive
		input terminals,  configures interrupts, reference voltage module is configured based on input
		parameters.            
***************************************************************************************/ 
void Open_ancomp2(unsigned char config)
{
	PIE2bits.CM2IE = 0;
	CM2CON = (0b01111111 & config);
	PIR2bits.CM2IF = 0;
	if(config & 0b10000000)
		PIE2bits.CM2IE = 1;
	//check for Analog IP and OP
	config &= 0x03;
	#if defined ANCOMP_IO_V2	// 64 pin devices
		{		
			if(config == 0) {TRISFbits.TRISF2 = 1;}
		}
	#else //80 pin devices
		{
			if(config == 0) {TRISFbits.TRISF2 = 1;}
			else if(config == 1){TRISHbits.TRISH4 = 1;}
			else if(config == 2){TRISHbits.TRISH5 = 1;}
		}
	#endif
	if(CM2CONbits.CREF == 0){TRISFbits.TRISF5 = 1;}
	if(CM2CONbits.COE) {TRISCbits.TRISC5 = 0;} // TODO reverfy
	CM2CONbits.CON=1;
}

#elif defined  (ANCOM_V8)
/*************************************************************************************
Function :       void Open_ancomp1(unsigned char config)

Overview :    This routine configures Reference Voltage level and Comparator module.

Parameters :  config - This contains the parameters to be configured in the CVRCON & CMxCON   
                         Registers.

Returns :        None

Remarks :     This function configures comparator with channel of selection for positive and negetive
		input terminals,  configures interrupts, reference voltage module is configured based on input
		parameters.            
***************************************************************************************/ 
void Open_ancomp1(unsigned char config)
{
	PIE2bits.C1IE = 0;

	CM1CON0 = (0b00011111 & config);
	
	if(config & 0b01000000) 
		CM2CON1 |= 0b00100000;
	else
		CM2CON1 &= 0b11011111;	
			
	// Since both comparators C1, C2 shared same output (RC4/C12OUT) , the following condition is required to bring C1OUT to RC4 
	if(config & 0b00100000) 
		CM1CON0bits.C1OE = 1;
    else
		CM1CON0bits.C1OE = 0;
	
	PIR2bits.C1IF = 0;
	if(config & 0b10000000)
		PIE2bits.C1IE = 1;
		
	//Comparator C1 Channel Select bits (inverting input)
	config &= 0b00000011;
	if(config == 1) {TRISCbits.TRISC1 = 1;}
	else if(config == 2) {TRISCbits.TRISC2 = 1;}
	else if(config == 3) {TRISCbits.TRISC3 = 1;}
	if(!CM1CON0bits.C1R) {TRISCbits.TRISC0 = 1;}
	if(CM1CON0bits.C1OE) {TRISCbits.TRISC4 = 0;}
	CM1CON0bits.C1ON=1;
}

/*************************************************************************************
Function :       void Open_ancomp2(unsigned char config)

Overview :    This routine configures Reference Voltage level and Comparator module.

Parameters :  config - This contains the parameters to be configured in the CVRCON & CMxCON   
                         Registers.

Returns :        None

Remarks :     This function configures comparator with channel of selection for positive and negetive
		input terminals,  configures interrupts, reference voltage module is configured based on input
		parameters.            
***************************************************************************************/ 
void Open_ancomp2(unsigned char config)
{
	PIE2bits.C2IE = 0;

	
	CM2CON0 = (0b00011111 & config);
	
	if(config & 0b01000000) 
		CM2CON1 |= 0b00010000;
	else
		CM2CON1 &= 0b11101111;
		
	// Since both comparators C1, C2 shared same output (RC4/C12OUT) , the following condition is required to bring C2OUT to RC4 
	if(config & 0b00100000) 
		CM2CON0bits.C2OE = 1;
	else
		CM2CON0bits.C2OE = 0;
		
	PIR2bits.C2IF = 0;	
	if(config & 0b10000000)
		PIE2bits.C2IE = 1;
		
	//Comparator C1 Channel Select bits (inverting input)
	config &= 0b00000011;
	if(config == 1) {TRISCbits.TRISC1 = 1;}
	else if(config == 2) {TRISCbits.TRISC2 = 1;}
	else if(config == 3) {TRISCbits.TRISC3 = 1;}
	if(!CM2CON0bits.C2R) {TRISCbits.TRISC0 = 1;}
	if(CM2CON0bits.C2OE){TRISCbits.TRISC4 = 0;}
	CM2CON0bits.C2ON=1;
}

#elif defined  (ANCOM_V8_1)
/*************************************************************************************
Function :       void Open_ancomp1(unsigned char config)

Overview :    This routine configures Reference Voltage level and Comparator module.

Parameters :  config - This contains the parameters to be configured in the CVRCON & CMxCON   
                         Registers.

Returns :        None

Remarks :     This function configures comparator with channel of selection for positive and negetive
		input terminals,  configures interrupts, reference voltage module is configured based on input
		parameters.            
***************************************************************************************/ 
void Open_ancomp1(unsigned char config)
{
	PIE2bits.C1IE = 0;

	CM1CON0 = (0b00011111 & config);
	
	if(config & 0b01000000) 
		CM2CON1 |= 0b00100000;
	else
		CM2CON1 &= 0b11011111;	
			
	// Since both comparators C1, C2 shared same output (RC4/C12OUT) , the following condition is required to bring C1OUT to RC4 
	if(config & 0b00100000) 
		CM1CON0bits.C1OE = 1;
    else
		CM1CON0bits.C1OE = 0;
	
	PIR2bits.C1IF = 0;
	if(config & 0b10000000)
		PIE2bits.C1IE = 1;
		
	//Comparator C1 Channel Select bits (inverting input)
	config &= 0b00000011;
	if(config == 1) {TRISAbits.TRISA1 = 1;}
	else if(config == 2) {TRISBbits.TRISB3 = 1;}
	else if(config == 3) {TRISBbits.TRISB1 = 1;}
	if(!CM1CON0bits.C1R) {TRISAbits.TRISA3 = 1;}
	if(CM1CON0bits.C1OE) {TRISAbits.TRISA4 = 0;}
	CM1CON0bits.C1ON=1;
}

/*************************************************************************************
Function :       void Open_ancomp2(unsigned char config)

Overview :    This routine configures Reference Voltage level and Comparator module.

Parameters :  config - This contains the parameters to be configured in the CVRCON & CMxCON   
                         Registers.

Returns :        None

Remarks :     This function configures comparator with channel of selection for positive and negetive
		input terminals,  configures interrupts, reference voltage module is configured based on input
		parameters.            
***************************************************************************************/ 
void Open_ancomp2(unsigned char config)
{
	PIE2bits.C2IE = 0;

	
	CM2CON0 = (0b00011111 & config);
	
	if(config & 0b01000000) 
		CM2CON1 |= 0b00010000;
	else
		CM2CON1 &= 0b11101111;
		
	// Since both comparators C1, C2 shared same output (RC4/C12OUT) , the following condition is required to bring C2OUT to RC4 
	if(config & 0b00100000) 
		CM2CON0bits.C2OE = 1;
	else
		CM2CON0bits.C2OE = 0;
		
	PIR2bits.C2IF = 0;	
	if(config & 0b10000000)
		PIE2bits.C2IE = 1;
		
	//Comparator C1 Channel Select bits (inverting input)
	config &= 0b00000011;
	if(config == 1) {TRISAbits.TRISA1 = 1;}
	else if(config == 2) {TRISBbits.TRISB3 = 1;}
	else if(config == 3) {TRISBbits.TRISB1 = 1;}
	if(!CM2CON0bits.C2R) {TRISAbits.TRISA2 = 1;}
	if(CM2CON0bits.C2OE){TRISAbits.TRISA5 = 0;}
	CM2CON0bits.C2ON=1;
}

#elif defined (ANCOM_V9) 
/*************************************************************************************
Function :       void Open_ancomp1(unsigned char config)

Overview :    This routine configures Reference Voltage level and Comparator module.

Parameters :  config - This contains the parameters to be configured in the CVRCON & CMxCON   
                         Registers.

Returns :        None

Remarks :     This function configures comparator with channel of selection for positive and negetive
		input terminals,  configures interrupts, reference voltage module is configured based on input
		parameters.            
***************************************************************************************/ 
void Open_ancomp1(unsigned char config)
{
	PIE2bits.CM1IE = 0;
	CM1CON1 = (0b01111111 & config);
	PIR2bits.CM1IF = 0;
	if(config & 0b10000000)
		PIE2bits.CM1IE = 1; // Enable interrupt	
	CM1CON1bits.CON=1;// enable comparator
}
/*************************************************************************************
Function :       void Open_ancomp2(unsigned char config)

Overview :    This routine configures Reference Voltage level and Comparator module.

Parameters :  config - This contains the parameters to be configured in the CVRCON & CMxCON   
                         Registers.

Returns :        None

Remarks :     This function configures comparator with channel of selection for positive and negetive
		input terminals,  configures interrupts, reference voltage module is configured based on input
		parameters.            
***************************************************************************************/ 
void Open_ancomp2(unsigned char config)
{
	PIE2bits.CM2IE = 0;
	CM2CON1= (0b01111111 & config);
	PIR2bits.CM2IF = 0;
	if(config & 0b10000000)
		PIE2bits.CM2IE = 1; // Enable interrupt
	CM2CON1bits.CON=1;// enable comparator
}

#elif defined (ANCOM_V10) || defined (ANCOM_V10_2) || defined (ANCOM_V10_3) || defined (ANCOM_V11)
/*************************************************************************************
Function :       void Open_ancomp1(unsigned char config)

Overview :    This routine configures Reference Voltage level and Comparator module.

Parameters :  config - This contains the parameters to be configured in the CVRCON & CMxCON   
                         Registers.

Returns :        None

Remarks :     This function configures comparator with channel of selection for positive and negetive
		input terminals,  configures interrupts, reference voltage module is configured based on input
		parameters.            
***************************************************************************************/ 
void Open_ancomp1(unsigned char config)
{
	CMP1_IE = 0;
	CM1CON = (0b01111111 & config);

	CMP1_IF = 0;

	
	if(config & 0b10000000)
	CMP1_IE = 1; 		// Enable interrupt


#if defined (ANCOM_V10)	
	if(config & 0x40){TRISFbits.TRISF2 = 0;}
	
		config &= 0b00000011;
	if(config == 0){TRISFbits.TRISF6 = 1; TRISFbits.TRISF5 = 1;}
	#if defined(ANCOM_V10_IO_V1)
	else if(config == 1){TRISFbits.TRISF6 = 1; TRISHbits.TRISH6 = 1;}
	#endif
 	else if(config == 2){TRISFbits.TRISF6 = 1; TRISFbits.TRISF3 = 1;}
	else if(config == 3){TRISFbits.TRISF6 = 1;}		
#elif defined (ANCOM_V10_2)	|| defined (ANCOM_V10_3)
	if(config & 0x40){C1OUT_PIN = 0;}
	
		config &= 0b00000011;
	if(config == 0){C1INA_PIN = 1; C1INB_PIN = 1;}
	else if(config == 1){C1INA_PIN = 1; C1INC_PIN = 1;}
 	else if(config == 2){C1INA_PIN = 1; C2INB_PIN = 1;}
	else if(config == 3){C1INA_PIN = 1;}	
#elif defined (ANCOM_V11)	
	if(config & 0x40)
	
		config &= 0b00000011;
	if(config == 0){TRISFbits.TRISF6 = 1; TRISFbits.TRISF5 = 1;}
	#if defined(ANCOM_V11_IO_V1)
	else if(config == 1){TRISFbits.TRISF6 = 1; TRISHbits.TRISH6 = 1;}
	#endif
 	else if(config == 2){TRISFbits.TRISF6 = 1; TRISFbits.TRISF2 = 1;}
	else if(config == 3){TRISFbits.TRISF6 = 1;}		
#endif	
	
	CM1CONbits.CON=1;			// enable comparator
}
/*************************************************************************************
Function :       void Open_ancomp2(unsigned char config)

Overview :    This routine configures Reference Voltage level and Comparator module.

Parameters :  config - This contains the parameters to be configured in the CVRCON & CMxCON   
                         Registers.

Returns :        None

Remarks :     This function configures comparator with channel of selection for positive and negetive
		input terminals,  configures interrupts, reference voltage module is configured based on input
		parameters.            
***************************************************************************************/ 
void Open_ancomp2(unsigned char config)
{
	CMP2_IE = 0;
	CM2CON= (0b01111111 & config);

	CMP2_IF = 0;

	if(config & 0b10000000)
	CMP2_IE = 1; 		// Enable interrupt

	
#if defined (ANCOM_V10)		
	if(config & 0x40){TRISFbits.TRISF1 = 0;}
	
		config &= 0b00000011;
	if(config == 0){TRISFbits.TRISF4 = 1; TRISFbits.TRISF3 = 1;}
	#if defined(ANCOM_V10_IO_V1)
	else if(config == 1){TRISFbits.TRISF4 = 1; TRISHbits.TRISH4 = 1;}
	else if(config == 2){TRISFbits.TRISF4 = 1; TRISHbits.TRISH5 = 1;}
	#endif
	else if(config == 3){TRISFbits.TRISF4 = 1;}	
#elif defined (ANCOM_V10_2)	|| defined (ANCOM_V10_3)
	if(config & 0x40){C2OUT_PIN = 0;}
	
		config &= 0b00000011;
	if(config == 0){C2INA_PIN = 1; C2INB_PIN = 1;}
	else if(config == 1){C2INA_PIN = 1; C2INC_PIN = 1;}
 	else if(config == 2){C2INA_PIN = 1; C1INB_PIN = 1;}
	else if(config == 3){C2INA_PIN = 1;}	
#elif defined (ANCOM_V11)	
	if(config & 0x40)
	
	config &= 0b00000011;
	if(config == 0){TRISAbits.TRISA5 = 1; TRISFbits.TRISF2 = 1;}
	#if defined(ANCOM_V11_IO_V1)
	else if(config == 1){TRISAbits.TRISA5 = 1; TRISHbits.TRISH4 = 1;}
	else if(config == 2){TRISAbits.TRISA4 = 1; TRISHbits.TRISH5 = 1;}
	#endif
	else if(config == 3){TRISAbits.TRISA4 = 1;}		
#endif

	CM2CONbits.CON=1;			// enable comparator
}

#endif

#if defined (ANCOM_V10) || defined (ANCOM_V11)
/*************************************************************************************
Function :       void Open_ancomp3(unsigned char config)

Overview :    This routine configures Reference Voltage level and Comparator module.

Parameters :  config - This contains the parameters to be configured in the CVRCON & CMxCON   
                         Registers.

Returns :        None

Remarks :     This function configures comparator with channel of selection for positive and negetive
		input terminals,  configures interrupts, reference voltage module is configured based on input
		parameters.            
***************************************************************************************/ 
void Open_ancomp3(unsigned char config)
{
	CMP3_IE = 0;
	CM3CON= (0b01111111 & config);
	CMP3_IF = 0;
	if(config & 0b10000000)
	CMP3_IE = 1; 		// Enable interrupt
	
	#if defined (ANCOM_V10)
	if(config & 0x40){TRISGbits.TRISG1 = 0;}
	#else
	if(config & 0x40)
	#endif
		config &= 0b00000011;
	if(config == 0){TRISGbits.TRISG2 = 1; TRISGbits.TRISG3 = 1;}
	else if(config == 1){TRISGbits.TRISG2 = 1; TRISGbits.TRISG4 = 1;}
	#if defined (ANCOM_V10) 
	else if(config == 2){TRISGbits.TRISG2 = 1; TRISFbits.TRISF3 = 1;}
	#else
 	else if(config == 2){TRISGbits.TRISG2 = 1; TRISFbits.TRISF2 = 1;}
	#endif
	else if(config == 3){TRISGbits.TRISG2 = 1;}	
	
	CM3CONbits.CON=1;			// enable comparator
}

#elif  defined (ANCOM_V10_1)
/*************************************************************************************
Function :       void Open_ancomp1(unsigned char config)

Overview :    This routine configures Reference Voltage level and Comparator module.

Parameters :  config - This contains the parameters to be configured in the CVRCON & CMxCON   
                         Registers.

Returns :        None

Remarks :     This function configures comparator with channel of selection for positive and negetive
		input terminals,  configures interrupts, reference voltage module is configured based on input
		parameters.            
***************************************************************************************/ 
void Open_ancomp1(unsigned char config)
{
	PIE2bits.CM1IE = 0;
	CM1CON = (0b01111111 & config);
	PIR2bits.CM1IF = 0;
	if(config & 0b10000000)
	PIE2bits.CM1IE = 1; 		// Enable interrupt

		config &= 0b00000011;
	if(config == 0){C1INA_PIN = 1; C1INB_PIN = 1;}
	else if(config == 1){C1INA_PIN = 1; C1INB_PIN = 1;}
 	else if(config == 2){C1INA_PIN = 1; C1INC_PIN = 1;}
	else if(config == 3){C1INA_PIN = 1;}		
	
	CM1CONbits.CON=1;			// enable comparator
}
/*************************************************************************************
Function :       void Open_ancomp2(unsigned char config)

Overview :    This routine configures Reference Voltage level and Comparator module.

Parameters :  config - This contains the parameters to be configured in the CVRCON & CMxCON   
                         Registers.

Returns :        None

Remarks :     This function configures comparator with channel of selection for positive and negetive
		input terminals,  configures interrupts, reference voltage module is configured based on input
		parameters.            
***************************************************************************************/ 
void Open_ancomp2(unsigned char config)
{
	PIE2bits.CM2IE = 0;
	CM2CON= (0b01111111 & config);
	PIR2bits.CM2IF = 0;
	if(config & 0b10000000)
	PIE2bits.CM2IE = 1; 		// Enable interrupt

		config &= 0b00000011;
	if(config == 0){C2INA_PIN = 1; C2INB_PIN = 1;}
	else if(config == 1){C2INA_PIN = 1; C2INB_PIN = 1;}
 	else if(config == 2){C2INA_PIN = 1; C2INC_PIN = 1;}
	else if(config == 3){C2INA_PIN = 1;}	
	
	CM2CONbits.CON=1;			// enable comparator
}

/*************************************************************************************
Function :       void Open_ancomp3(unsigned char config)

Overview :    This routine configures Reference Voltage level and Comparator module.

Parameters :  config - This contains the parameters to be configured in the CVRCON & CMxCON   
                         Registers.

Returns :        None

Remarks :     This function configures comparator with channel of selection for positive and negetive
		input terminals,  configures interrupts, reference voltage module is configured based on input
		parameters.            
***************************************************************************************/ 
void Open_ancomp3(unsigned char config)
{
	PIE5bits.CM3IE = 0;
	CM3CON= (0b01111111 & config);
	PIR5bits.CM3IF = 0;
	if(config & 0b10000000)
	PIE5bits.CM3IE = 1; 		// Enable interrupt
	
		config &= 0b00000011;
	if(config == 0){C3INA_PIN = 1; C3INB_PIN = 1;}
	else if(config == 1){C3INA_PIN = 1; C3INB_PIN = 1;}
 	else if(config == 2){C3INA_PIN = 1; C3INC_PIN = 1;}
	else if(config == 3){C3INA_PIN = 1;}		
	
	CM3CONbits.CON=1;			// enable comparator
}

#endif
//---------------------------------------
