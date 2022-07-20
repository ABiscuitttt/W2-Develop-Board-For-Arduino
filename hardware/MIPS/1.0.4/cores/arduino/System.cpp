
inline unsigned char MemoryRead8(int address)
{
	return (*(volatile unsigned char*)(address));
}

inline unsigned short MemoryRead16(int address)
{
	return (*(volatile unsigned short*)(address));
}

inline unsigned long MemoryRead32(int address)
{
	return (*(volatile unsigned long*)(address));
}

inline unsigned long MemoryRead(int address)
{
	return (*(volatile unsigned long*)(address));
}

inline void MemoryWrite8(int address, unsigned char value)
{
	*(volatile unsigned char*)(address) = value;
}

inline void MemoryWrite16(int address, unsigned short value)
{
	*(volatile unsigned short*)(address) = value;
}

inline void MemoryWrite32(int address, unsigned long value)
{
	*(volatile unsigned long*)(address) = value;
}

inline void MemoryWrite(int address, unsigned long value)
{
	(*(volatile unsigned long*))(address) = value;
}

inline void MemoryOr8(int address, unsigned char value)
{
	(*(volatile unsigned char*)(address)) |= (value);
}

inline void MemoryOr16(int address, unsigned short value)
{
	(*(volatile unsigned short*)(address)) |= (value);
}

inline void MemoryOr32(int address, unsigned long value)
{
	(*(volatile unsigned long*)(address)) |= (value);
}

inline void MemoryOr(int address, unsigned long value)
{
	(*(volatile unsigned long*)(address)) |= (value);
}

inline void MemoryAnd8(int address, unsigned char value)
{
	(*(volatile unsigned char*)(address)) &= (value);
}

inline void MemoryAnd16(int address, unsigned short value)
{
	(*(volatile unsigned short*)(address)) &= (value);
}

inline void MemoryAnd32(int address, unsigned long value)
{
	(*(volatile unsigned long*)(address)) &= (value);
}

inline void MemoryAnd(int address, unsigned long value)
{
	(*(volatile unsigned long*)(address)) &= (value);
}

inline unsigned long GetSysClock()
{
	char systemClcok = (((*(unsigned long*)(0x1F800702)) >> 12) & (0x3));
	return 6000000 << systemClock;
}

inline unsigned char GetSysClockStatus()
{
	return (((*(unsigned long*)(0x1F800702)) >> 12) & (0x3));
}

inline void SetSysClockStatus(char sysClk)
{
	(*(unsigned long*)(0x1F800702)) = 
		(((*(unsigned long*)(0x1F800702)) & (~(3 << 12))) | (sysClk << 12));
}

inline void FlashWrite(int address, int data)
{
	((void (*)(int, int))0x260)(data, address);
}

inline void FlashErase(int address)
{
	((void (*)(int, int))0x294)(address);
}

inline void JumpTo(int address)
{
	((void (*)())address)();
}