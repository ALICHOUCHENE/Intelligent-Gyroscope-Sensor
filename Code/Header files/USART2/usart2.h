#ifndef USART2
#define USART2
// library start
#include "stm32f10x.h"                  // Device header
#include <stdbool.h>
#include <string.h>

void USART2_INIT(void);
void USART2_SET_BAUD(uint16_t baude, uint8_t Fck);
float USART2_AVAILABLE(void);
void USART2_CONFIG(char word_length, bool parity_control ,bool parity_selection );
void USART2_TRANSMITTER_ENABLE(bool state );
void USART2_RECEIVER_ENABLE(bool state );
void USART2_WRITE( char* ch);
char* USART2_READ(void);

void USART2_INIT(void)
{
RCC->APB2ENR  |=0x5;   		    													// Enabling APB2 Clock for GPIOA
RCC->APB1ENR  |=0x20000;   															// Enabling APB1 Clock for USART2 peripheral
GPIOA->CRL    |=0xA00;                                  // Setting PA2 as alternate function	(USART2_TX)
GPIOA->CRL    |=0x4000;                                 // Setting PA3 as alternate function	(USART2_RX)
}	

void USART2_SET_BAUD (uint16_t baud, uint8_t Fck)
{
	uint16_t x =0x0000;
	x=Fck/(baud*16) & 0xFFFF;
	USART2->BRR |=x;
}

float USART2_AVAILABLE(void)
{
	return ((USART2->CR1 & 0x20)==1); // check if the data is available
}

void USART2_CONFIG(char word_length, bool parity_control ,bool parity_selection )
{
	if(  word_length == 8 ) USART2->CR1 &=~ 0x1000;     // 1 Start bit, 8 Data bits, n Stop bit
	if(  word_length == 9 ) USART2->CR1 |=  0x1000;     // 1 Start bit, 9 Data bits, n Stop bit
	if(  parity_control)    USART2->CR1 |=  0x400;		  // Parity control enabled
	if( !parity_control)    USART2->CR1 &=~ 0x400;	    // Parity control disabled
	if(  parity_selection)  USART2->CR1 |=  0x200;		  // Odd parity
	if( !parity_selection)  USART2->CR1 &=~ 0x200;		  //Even parity
}

void USART2_TRANSMITTER_ENABLE(bool state )
{
	if(state) USART2->CR1 |= 0x4;  						  // Transmitter is enabled
	else USART2->CR1 &=~ 0x4;								  	// Transmitter is disabled
}
void USART2_RECEIVER_ENABLE(bool state )
{
	if(state) USART2->CR1 |= 0x2;								// Receiver is enabled and begins searching for a start bit
	else USART2->CR1 &=~ 0x2;										// Receiver is disabled
}
void USART2_WRITE( char* ch)
{
	for (uint8_t i=0; i < strlen(ch);i++)
	{
	while(!(USART2->SR & 0x0080)){}  // waiting  the Transmit data register to be empty
	USART2->DR = ch[i] & 0xFF;			//Sending the data
	}
}

char* USART2_READ(void)
{
	char* ch="";
	while(USART2->SR & 0x10  )
		ch+=(USART2->DR &0xEF);
	return ch;
}
#endif