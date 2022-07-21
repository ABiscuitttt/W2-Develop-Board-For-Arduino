#define MemoryRead8(address)             (*(volatile unsigned char*)(address))
#define MemoryRead16(address)            (*(volatile unsigned short*)(address))
#define MemoryRead32(address)            (*(volatile unsigned long*)(address))
#define MemoryRead(address)              (*(volatile unsigned long*)(address))
#define MemoryWrite8(address,value)      (*(volatile unsigned char*)(address))=(value)
#define MemoryWrite16(address,value)     (*(volatile unsigned short*)(address))=(value)
#define MemoryWrite32(address,value)     (*(volatile unsigned long*)(address))=(value)
#define MemoryWrite(address,value)       MemoryWrite32(address,value)

#define MemoryOr8(address,value)         (*(volatile unsigned char*)(address)|=(value))
#define MemoryOr16(address,value)        (*(volatile unsigned short*)(address)|=(value))
#define MemoryOr32(address,value)        (*(volatile unsigned long*)(address)|=(value))
#define MemoryOr(address,value)          MemoryOr32(address,value)

#define MemoryAnd8(address,value)        (*(volatile unsigned char*)(address)&=(value))
#define MemoryAnd16(address,value)       (*(volatile unsigned short*)(address)&=(value))
#define MemoryAnd32(address,value)       (*(volatile unsigned long*)(address)&=(value))
#define MemoryAnd(address,value)         MemoryAnd32(address,value)


#define GetSysClock()                    (6000000 << (((*(unsigned long*)(0x1F800702)) >> 12) & (0x3)))
#define GetSysClockStatus()              (((*(unsigned long*)(0x1F800702)) >> 12) & (0x3))
#define SetSysClockStatus(sysClk)        (*(unsigned long*)(0x1F800702))=(((*(unsigned long*)(0x1F800702)) & (~(3 << 12))) | (sysClk << 12))

#define FlashWrite(address, data)        ((void (*)(int, int))0x260)(data, address)

#define FlashErase(address)              ((void (*)(int))0x294)(address)

#define JumpTo(address)                  ((void (*)())address)()