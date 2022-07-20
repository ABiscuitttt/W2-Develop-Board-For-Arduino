
#ifndef IrFuncPtr_
#define IrFuncPtr_

typedef void (*IrFuncPtr)(void);
#endif

extern void setup();
extern void loop();

IrFuncPtr iFP=0;

void  __attribute__((weak)) user_interrupt()//If user defined a user_interrupt function
{
	if (iFP != 0)
	{
		iFP();
	}
}

void attachInterrupt(IrFuncPtr p)
{
	iFP = p;
}

void main()
{
	setup();
	while (1)
	{
		loop();
	}
}