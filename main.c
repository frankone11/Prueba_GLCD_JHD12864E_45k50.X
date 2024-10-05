/*
 * File:   main.c
 * Author: frank
 *
 * Created on 5 de octubre de 2024, 06:57 AM
 */


#include <xc.h>
#include "glcd.h"

/* 5x7 Font including 1 space to display HELLO WORLD */
uint8_t H[]={0x7F, 0x08, 0x08, 0x08, 0x7F, 0x00};
uint8_t E[]={0x7F, 0x49, 0x49, 0x49, 0x41, 0x00};
uint8_t L[]={0x7F, 0x40, 0x40, 0x40, 0x40, 0x00};
uint8_t O[]={0x3E, 0x41, 0x41, 0x41, 0x3E, 0x00};

uint8_t W[]={0x3F, 0x40, 0x38, 0x40, 0x3F, 0x00};
uint8_t R[]={0x7F, 0x09, 0x19, 0x29, 0x46, 0x00};
uint8_t D[]={0x7F, 0x41, 0x41, 0x22, 0x1C, 0x00};

void GLCD_DisplayChar(uint8_t *ptr_array)
{
    int i;
    for(i=0;i<6;i++) // 5x7 font, 5 chars + 1 blankspace
        GLCD_DataWrite(ptr_array[i]);
}

void main(void) 
{
	ANSELB = 0;
	ANSELD = 0;
	PORTB = 0;
	PORTD = 0;
	TRISD = 0;
	TRISB = 0xC3U;
	
	GLCD_Init();
	
	GLCD_SelectPage0(); // Display HELLO on Page0, Line1
	GLCD_CmdWrite(GLCD_SETX_ADDRESS);
	GLCD_DisplayChar(H);
	GLCD_DisplayChar(E);
	GLCD_DisplayChar(L);
	GLCD_DisplayChar(L);
	GLCD_DisplayChar(O);

	GLCD_SelectPage1(); // Display WORLD on Page1, Last line
	GLCD_CmdWrite(GLCD_SETX_ADDRESS | GLCD_MASKX(3));
	GLCD_DisplayChar(W);
	GLCD_DisplayChar(O);
	GLCD_DisplayChar(R);
	GLCD_DisplayChar(L);
	GLCD_DisplayChar(D);
	
	while(1)
	{
		
	}
}
