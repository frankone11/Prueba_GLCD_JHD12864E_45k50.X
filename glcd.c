#define _XTAL_FREQ 4000000UL

#include <xc.h>
#include "glcd.h"

#define DATA	PORTD
#define CONTROL	PORTB

#define RS	0x04U
#define EN	0x08U
#define CS1	0x10U
#define CS2	0x20U


void GLCD_SelectPage0(void)
{
	CONTROL &= ~CS2;
	CONTROL |= CS1;
}

void GLCD_SelectPage1(void)
{
	CONTROL &= ~CS1;
	CONTROL |= CS2;
}

void GLCD_CmdWrite(uint8_t cmd)
{
	DATA = cmd;
	CONTROL &= ~RS;
	CONTROL |= EN;
	__delay_ms(1);
	CONTROL &= ~EN;
	__delay_ms(1);
}

void GLCD_DataWrite(uint8_t dat)
{
	DATA = dat;
	CONTROL |= RS | EN;
	__delay_ms(1);
	CONTROL &= ~EN;
	__delay_ms(1);
}

void GLCD_Init(void)
{
	__delay_ms(10);
	GLCD_SelectPage0();
	GLCD_CmdWrite(GLCD_DISPLAY_ON);
	GLCD_SelectPage1();
	GLCD_CmdWrite(GLCD_DISPLAY_ON);
	__delay_ms(10);

	GLCD_SelectPage0();
	GLCD_CmdWrite(GLCD_SETZ_ADDRESS);
	GLCD_SelectPage1();
	GLCD_CmdWrite(GLCD_SETZ_ADDRESS);
	__delay_ms(10);
}
