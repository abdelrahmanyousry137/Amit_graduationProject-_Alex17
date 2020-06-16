/*
 * File:   main.c
 * Author: Abdelrahman yousry ibrahim   phone number : 01112212898
 *
 * Created on 5/17/2020 9:08:11 AM UTC
 * "Created in MPLAB Xpress"
 */


#define T    1  // T for Transmitt only UART
#define R    2  // R for Recieve only UART
#define T_R  3  //T_R for Transmitt & Recieve UART 

#include <xc.h>
#include <avr/interrupt.h>
#include "Kitconfig.h"  //KIT configuratiin file
#include "UART.h"      //UART header file 
#include "SPI.h"      //SPI header file 

//Global varuble to recieve the order from the blutooth
unsigned char Blutooth_Data;

int main(void) {
    
    //intiate UART to Read 
    UART_init(R);
    //iniate SPI as master 
    SPI_Masterinit();

    while(1)
    {
     //Read the blutooth insturction    
     Blutooth_Data=UART_Read();
     //transmitt the blutooth instructuion through SPI to the slave 
     SPI_MasterTransmit(Blutooth_Data);

    }
    
    return 0;
}