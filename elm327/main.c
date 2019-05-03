/* 
 * File:   ELMBridgeMain.c
 * Author: DrBobBob
 *
 * Created on July 23, 2014, 6:15 PM
 */

#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <pic18.h>
#include <usart.h>
#include <xc.h>
#include "Serial.h"

#include "./can/ECANPoll.h"


void alive(int j) {
    TRISB7 = 0;
    for(int i = 0; i<j; i++) {
        RB7 = 1;
        __delay_ms(50);
        RB7 = 0;
        __delay_ms(50);
    }
}


void uds_get_soc() {
    PutString("status: busy\n");
    BYTE msg[] = {0x03, 0x22, 0x1D, 0xD0, 0x55, 0x55, 0x55, 0x55};
    if (!ECANSendMessage(0x765, msg, 8, 0)) {
        PutString("error: can send failed\n");
    }
    
    unsigned long id = 0;
    BYTE len = 32;
    ECAN_RX_MSG_FLAGS flags = 0;
    BYTE msg2[32];
    BYTE buf[128];
    
    
    for(int i = 0; i < 100; i++) {
        __delay_ms(10);
        if (ECANReceiveMessage(&id,  msg2, &len, &flags)) {
            if (id == 0x7CF && msg2[0] == 0x04 && msg2[1] == 0x62) {
                sprintf(buf, "value soc: %.1f %%\n", (msg2[4] / 2.0));
                PutString(buf);
                return;
            }
        }
    }
    PutString("error: timeout\n");
}





void uds_get_vin() {
    PutString("status: busy\n");
    BYTE msg_start[] = {0x03, 0x22, 0xF1, 0x90, 0x55, 0x55, 0x55, 0x55};
    BYTE msg_continue[] = {0x30, 0xff, 0x01, 0x55, 0x55, 0x55, 0x55, 0x55};
    if (!ECANSendMessage(0x7E0, msg_start, 8, 0)) {
        PutString("error: can send failed\n");
    }
            
    unsigned long id = 0;
    BYTE len = 32;
    ECAN_RX_MSG_FLAGS flags = 0;
    BYTE msg2[32];
    BYTE buf[128];
    
    
    
    
    int total_size = 0;
    
    for(int i = 0; i < 100; i++) {
        __delay_ms(5);
        if (ECANReceiveMessage(&id,  msg2, &len, &flags)) {
            if (id == 0x7E8 && msg2[0] == 0x10 && msg2[2] == 0x62  && msg2[3] == 0xF1) {

                
                // tell gw we support long messages, and it should continue
                if (!ECANSendMessage(0x7E0, msg_continue, 8, 0)) {
                    PutString("\nerror: can send failed\n");
                }
                
                total_size = msg2[1] - 6;    
                
                PutString("value vin: ");
                Putchar(msg2[5]);
                Putchar(msg2[6]);
                Putchar(msg2[7]);
                goto ok1;
            }
        }
    }

    PutString("\nerror: timeout\n");
    return;    
    
ok1:
    
    for(int t = 0; t < 100; t++) {
        __delay_ms(5);
        if (ECANReceiveMessage(&id,  msg2, &len, &flags)) {
            if (id == 0x7E8 ) { 
                for (unsigned char i = 1; i < 8; i++) {
                    Putchar(msg2[i]);
                    total_size -= 1;
                    if (total_size <=0) {
                        goto ok2;
                    }                    
                }
            }
        }
    }
    
    PutString("\nerror: timeout\n");
    return;   
    
ok2:
    Putchar('\n');
    
}





char cmd  = 0;
char ctmp = 0;

__interrupt() void ISR(void)
{
    GIE=0;
    RCIE=0;
    if (DataRdy1USART()) {
        char c2 = Read1USART();
        if (c2 == '\n') {
            cmd = ctmp;
        }
        if (c2 != '\r' && c2 != '\n') {
            ctmp = c2;
        }
    }
    RCIE=1;
    GIE=1;
    
}



void shell() {
    if (cmd != 0) {
        alive(1);
        if (cmd == 's') {
            uds_get_soc();
        } else if (cmd == 'r') {
            RESET();               
        } else if (cmd == 'v') {
            uds_get_vin(0,1);
        } else {
            PutString("error: invalid cmd ");
            Putchar(cmd);
            Putchar('\n');
        }
        __delay_ms(1);
        RESET();         
    }

    cmd = 0;
}


int main(int argc, char** argv) {

    
    alive(2);
    ECANInitialize();

    // FOSC / (16 * (spbrg + 1)) = 16000000  / (16 * 26 + 1) = 38369
    Open1USART(USART_TX_INT_OFF & USART_RX_INT_ON & USART_ASYNCH_MODE & USART_EIGHT_BIT & USART_CONT_RX & USART_BRGH_HIGH , 26);
    alive(2);
    

    // global interrupt enable
    GIE=1;
    // peripheral interrupt enable
    PEIE=1;    
    
    
    PutString("status: ready\n");
    for (int i = 0; i < 10000; i++) {
        __delay_ms(1);
        shell();
    }
    RESET();
}

