#include "Registers.h"
#include "Serial.h"

void GPIOInputOpen(char pin)
{
	RegBitWrite(SYS_IOCTL_REG, pin, 1);
}

void GPIOPinOutPut(char pin,char value)
{
	if (RegBitRead(SYS_IOCTL_REG,pin)==0)
	{
		Puts("This pin is not turned to enable");
	}
	else
	{
		RegBitWrite(SYS_GPIO0_REG, pin, value);
	}
}

void GPIOOutPut(char value)
{
	RegWrite(SYS_GPIO0_REG, value);
}

char GPIOPinInput(char pin)
{
	return RegBitRead(SYS_GPIO1_REG, pin);
}

unsigned long GPIOInput()
{
	return RegRead(SYS_GPIO1_REG);
}