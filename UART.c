/*
 * File:   main.c
 * Author: guest-3db9bf80-55a9-4f71-be52-bfd5dac152ba@transim.com
 *
 * Created on 5/5/2020 9:51:15 AM UTC
 * "Created in MPLAB Xpress"
 */

#define T       1
#define R       2
#define T_R     3

#define F_CPU  16000000UL
#include <xc.h>

void UART_init(int Enable){
    
    switch(Enable){
        
        case T:
        UCSRB |=(1<<TXEN);
        UCSRB &=~(1<<RXEN);
        break;
        
        case R:
        UCSRB |=(1<<RXEN);
        UCSRB &=~(1<<TXEN);
        break;
        
        case T_R:
        UCSRB |=(1<<TXEN);
        UCSRB |=(1<<RXEN);
        break;
        
    }
    
    UBRRL =103;
   // UCSRB |=(1<<UDRIE);
      
}

unsigned char UART_Read(){
    
   while ( !(UCSRA & (1<<RXC)) );
   
   return UDR;
   }
