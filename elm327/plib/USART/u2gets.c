#include <p18cxxx.h>
#include <usart.h>

/********************************************************************
*    Function Name:  gets2USART                                      *
*    Return Value:   void                                           *
*    Parameters:     buffer: pointer to string                      *
*                    len: length of characters to receive           *
*    Description:    This routine receives a string of characters   *
*                    from the USART of length specified by len.     *
********************************************************************/
#if defined (AUSART_V2) || defined (EAUSART_V6)|| defined (EAUSART_V7) ||\
    defined (EAUSART_V8) || defined (EAUSART_V9) || defined (EAUSART_V11) \
	|| defined (EAUSART_V12)

void gets2USART(char *buffer, unsigned char len)
{
  char i;    // Length counter
  unsigned char data;

  for(i=0;i<len;i++)  // Only retrieve len characters
  {
    while(!DataRdy2USART());// Wait for data to be received

    data = getc2USART();    // Get a character from the USART
                           // and save in the string
    *buffer = data;
    buffer++;              // Increment the string pointer
  }
}

#endif
