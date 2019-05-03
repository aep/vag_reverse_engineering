#ifndef SERIAL_H
#define	SERIAL_H

void initEUSART (void);
void PutString (const char *mess);
unsigned char Getchar(void);
int HasData();
void Putchar ( char);
void hex_ascii(unsigned char display_data);

void U1RXInterrupt(void);


#endif	/* SERIAL_H */

