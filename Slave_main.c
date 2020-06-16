/*
 * File:   main.c
 * Author: Abdelrahman yousry ibrahim   phone number : 01112212898
 *
 * Created on 5/17/2020 9:37:21 AM UTC
 * "Created in MPLAB Xpress"
 */


#include <xc.h>
#include <avr/interrupt.h>
#include "Kitconfig.h"
#include "SPI.h"

// Global variable to recieve the data from Master SPI 
unsigned char Finale_Data;

int main(void) {
    
    //Initiate SPI Slave device
    SPI_Slaveinit();
    
    //Set LED0 & LED1 at PORTC as O/P
    DDRC |=(1<<LED0)|(1<<LED1);
    
    //Set LED2 at PORTD as O/P
    DDRD |=(1<<LED2);

    while(1)
    {
      //Save the recived data from the master SPI into the global variable "Finale_Data"  
     Finale_Data = SPI_SlaveReceive(); 
     
     //check for the recived Data 
     
     // If we recieve 'a' open LED0  if 'b' close LED0
     if(Finale_Data=='a')
     {
        PORTC |=(1<<LED0);
     }
     
    else if(Finale_Data=='b')
    {
        PORTC &= ~(1<<LED0);
    }
    
     // If we recieve 'c' open LED1  if 'd' close LED1
    else if(Finale_Data=='c')
     {
        PORTC |=(1<<LED1);
     }
     
    else if(Finale_Data=='d')
    {
        PORTC &= ~(1<<LED1);
    }
    
     // If we recieve 'e' open LED2  if 'f' close LED2
    else if(Finale_Data=='e')
     {
        PORTD |=(1<<LED2);
     }
     
    else if(Finale_Data=='f')
    {
        PORTD &= ~(1<<LED2);
    }


    }
    
    return 0;
}