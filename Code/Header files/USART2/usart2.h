#ifndef USART2
#define USART2


#include "stm32f10x.h"    // Device header                                                            
#include <stdbool.h>
#include <string.h>


/*!
******************************************************************
*
* \ void USART2_INIT(void);
* initialising the USART2 peripheral by enabling the RCC and PA2 and PA3 alternate function.
* no arguments required for this function

* \ void USART2_SET_BAUD(uint32_t baude, uint8_t Fck);
* Setting the baude rate value 
* arguments :
* baude 					 : uint32_t parameter refer to the baude rate.
* Fck		                                 : uint8_t the frequency of the mcu.

* \ float USART2_AVAILABLE(void);
* Check if the data in the receiver buffer is available.
* return a boolean :
*										 - true  : available 
* 									 - false : not available


* / void USART2_CONFIG(char word_length, bool parity_control ,bool parity_selection );
* Configuer the USART data frame 
* arguments :  
* word_length      : char --> the lenght of the data frame ( 8 or 9 bits )
* parity_control   : bool	--> parity error detection         :
*																									  	        - true  : Parity control enabled
*																									  	        - false : Parity control disabled
* 
* parity_selection : bool --> parity selection (EVEN or ODD) :
*                                                             - true  : ODD parity 
*                                                             - false : EVEN parity
* 
* / void USART2_TRANSMITTER_ENABLE(bool state );
* Enabling the Transmitter
* arguments : 
* state            : bool --> Eabling or Disabling the Transmitter : 
*																																		- true  : Transmitter Enabled
*																																		- false : Transmitter Disabled
*
* / void USART2_RECEIVER_ENABLE(bool state );
* Enabling the Receiver
* arguments : 
* state            : bool --> Eabling or Disabling the Receiver : 
*																																		- true  : Receiver Enabled
*																																		- false : Receiver Disabled
*
*
* / void USART2_WRITE( char* ch);
* Sending data over the TX
* arguments : 
* ch*              : String 
*
*
/ void USART2_READ( void);
* Reading data from the RX
* arguments : no arguments passed to this function
* return a string 
*
*******************************************************************
*/


void USART2_INIT(void);
void USART2_SET_BAUD(uint32_t baude, uint8_t Fck);
float USART2_AVAILABLE(void);
void USART2_CONFIG(char word_length, bool parity_control ,bool parity_selection );
void USART2_TRANSMITTER_ENABLE(bool state );
void USART2_RECEIVER_ENABLE(bool state );
void USART2_WRITE( char* ch);
char* USART2_READ(void);

void USART2_INIT(void)
{
RCC->APB2ENR  |=0x5;   		    						           // Enabling APB2 Clock for GPIOA
RCC->APB1ENR  |=0x20000;   								   // Enabling APB1 Clock for USART2 peripheral
GPIOA->CRL    |=0xA00;                                                                     // Setting PA2 as alternate function	(USART2_TX)
GPIOA->CRL    |=0x4000;                                                                    // Setting PA3 as alternate function	(USART2_RX)
}	

void USART2_SET_BAUD (uint32_t baud, uint8_t Fck)
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
	if(  word_length == 8 ) USART2->CR1 &=~ 0x1000;    				   // 1 Start bit, 8 Data bits, n Stop bit
	if(  word_length == 9 ) USART2->CR1 |=  0x1000;    				   // 1 Start bit, 9 Data bits, n Stop bit
	if(  parity_control)    USART2->CR1 |=  0x400;					   // Parity control enabled
	if( !parity_control)    USART2->CR1 &=~ 0x400;	   				   // Parity control disabled
	if(  parity_selection)  USART2->CR1 |=  0x200;					   // Odd parity
	if( !parity_selection)  USART2->CR1 &=~ 0x200;					   // Even parity
}

void USART2_TRANSMITTER_ENABLE(bool state )
{
	if(state) USART2->CR1 |= 0x4;  						           // Transmitter is enabled
	else USART2->CR1 &=~ 0x4;						           // Transmitter is disabled
}
void USART2_RECEIVER_ENABLE(bool state )
{
	if(state) USART2->CR1 |= 0x2;							   // Receiver is enabled and begins searching for a start bit
	else USART2->CR1 &=~ 0x2;							   // Receiver is disabled
}
void USART2_WRITE( char* ch)
{
	for (uint8_t i=0; i < strlen(ch);i++)
	{
	while(!(USART2->SR & 0x0080)){}    					           // Waiting  the Transmit data register to be empty
	USART2->DR = ch[i] & 0xFF;		  				           // Sending the data
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
