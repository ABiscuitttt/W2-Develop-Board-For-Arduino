#include "Registers.h"

void SetBaudRate(unsigned long buadRate)
{
	char systemClcok = (((*(unsigned long*)(0x1F800702)) >> 12) & (0x3));
	unsigned long tmp = (12000000 << systemClcok) / buadRate;
	RegWrite(U0_BRP_REG,tmp);
}

void Putch(char ch)
{
	while (RegRead(U0_BUSY_REG) == 1){}
	RegWrite(U0_WRITE_REG, ch);
}

void Puts(char const* str)
{
	char const* tmp = str;
	while (*tmp)
	{
		while (RegRead(U0_BUSY_REG)==1){}
		(*(char*)(U0_WRITE_REG)) = *tmp;
		tmp++;
	}
}

char* itoa(int num, char* str, int radix)
{
    char index[] = "0123456789ABCDEF";
    unsigned unum;
    int i = 0, j, k;
    if (radix == 10 && num < 0)
    {
        unum = (unsigned)-num;
        str[i++] = '-';
    }
    else unum = (unsigned)num;

    do
    {
        str[i++] = index[unum % (unsigned)radix];
        unum /= radix;
    } while (unum);
    str[i] = '\0';

    if (str[0] == '-')
        k = 1;
    else
        k = 0;

    for (j = k; j <= (i - 1) / 2; j++)
    {
        char temp;
        temp = str[j];
        str[j] = str[i - 1 + k - j];
        str[i - 1 + k - j] = temp;
    }
    return str;
}


int atoi(const char* str)
{
    int s = 0;
    bool sign = false;


    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = true;
        str++;
    }

    while (*str >= '0' && *str <= '9')
    {
        s = s * 10 + *str - '0';
        str++;
        if (s < 0)
        {
            s = 2147483647;
            break;
        }
    }

    return s * (sign ? -1 : 1);
}

char ReadChar()
{
	while (RegRead(U0_Data_RDY_REG)==0){}
	return (*(char*)(U0_READ_REG));
}