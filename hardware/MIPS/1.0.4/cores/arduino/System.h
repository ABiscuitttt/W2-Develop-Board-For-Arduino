
unsigned char MemoryRead8(int address);
unsigned short MemoryRead16(int address);
unsigned long MemoryRead32(int address);
unsigned long MemoryRead(int address);

void MemoryWrite8(int address, unsigned char value);
void MemoryWrite16(int address, unsigned short value);
void MemoryWrite32(int address, unsigned long value);
void MemoryWrite(int address, unsigned long value);

void MemoryOr8(int address, unsigned char value);
void MemoryOr16(int address, unsigned short value);
void MemoryOr32(int address, unsigned long value);
void MemoryOr(int address, unsigned long value);

void MemoryAnd8(int address, unsigned char value);
void MemoryAnd16(int address, unsigned short value);
void MemoryAnd32(int address, unsigned long value);
void MemoryAnd(int address, unsigned long value);

unsigned long GetSysClock();
unsigned char GetSysClockStatus();
void SetSysClockStatus(char sysClk);

void FlashWrite(int address, int data);
void FlashErase(int address);
void JumpTo(int address);