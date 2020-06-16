/*
 * File:   SPI.c
 * Author: guest-da526931-c29e-47ef-a67b-fe90a0e66e27@transim.com
 *
 * Created on 5/17/2020 8:50:50 AM UTC
 * "Created in MPLAB Xpress"
 */

#include "Kitconfig.h"

void SPI_Masterinit()
{
    DDRB=(1<<MOSI)|(1<<SS)|(1<<SCK);
    SPCR=(1<<SPE)|(1<<MSTR)|(1<<SPR0)|(1<<SPR1);
}

void SPI_MasterTransmit(char Data)
{
    SPDR=Data;
    while(!(SPSR&(1<<SPIF)));
}

void SPI_Slaveinit()
{
    DDRB=(1<<MISO);
    SPCR=(1<<SPE);
}

unsigned char SPI_SlaveReceive()
{
    while(!(SPSR&(1<<SPIF)));
    
    return SPDR;
}