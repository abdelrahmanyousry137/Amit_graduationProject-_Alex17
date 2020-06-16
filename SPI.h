/* 
 * File:   SPI.h
 * Author: guest-da526931-c29e-47ef-a67b-fe90a0e66e27@transim.com
 *
 * Created on 5/17/2020 8:50:30 AM UTC
 * "Created in MPLAB Xpress"
 */

#ifndef SPI_H
#define	SPI_H

void SPI_Masterinit();
void SPI_MasterTransmit(char Data);
void SPI_Slaveinit();
unsigned char SPI_SlaveReceive();


#endif	/* SPI_H */
