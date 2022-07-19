#include "Registers.h"

void SetBaudRate(unsigned int buadRate)
{
	char systemClcok = (((*(unsigned long*)(0x1F800702)) >> 12) & (0x3));
	unsigned int tmp = (6000000 << systemClcok) / buadRate;
	RegWrite(U0_BRP_REG,tmp << 1);
}

void Putch(char ch)
{
	while (RegRead(U0_BUSY_REG) == 1){}
	RegWrite(U0_WRITE_REG, ch);
}

void Puts(const char* str)
{
	char* tmp = str;
	while (*tmp)
	{
		while (RegBitRead(U0_BUSY_REG)==1){}
		(*(char*)(U0_WRITE_REG)) = *tmp;
		tmp++;
	}
}

char ReadChar()
{
	while (U0_Data_RDY_REG==0){}
	return (*(char*)(U0_READ_REG));
}