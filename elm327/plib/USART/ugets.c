#include <p18cxxx.h>
#include <usart.h>

/********************************************************************
*    Function Name:  getsUSART                                      *
*    Return Value:   void                                           *
*    Parameters:     buffer: pointer to string                      *
*                    len: length of characters to receive           *
*    Description:    This routine receives a string of characters   *
*                    from the USART of length specified by len.     *
********************************************************************/
#if defined (AUSART_V1) || defined (EAUSART_V3) || defined (EAUSART_V4) || defined (EAUSART_V5)

void getsUSART(char *buffer, unsigned char len)
{
  char i;    // Length counter
  unsigned char data;

  for(i=0;i<len;i++)  // Only retrieve len characters
  {
    while(!DataRdyUSART());// Wait for data to be received

    data = getcUSART();    // Get a character from the USART
                           // and save in the string
    *buffer = data;
    buffer++;              // Increment the string pointer
  }
}

#endif
