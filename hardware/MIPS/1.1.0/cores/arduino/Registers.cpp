
/// <summary>
/// Write one bit to the specific position of a register
/// </summary>
/// <param name="reg">Register with 32bit address, always in hex form</param>
/// <param name="pos">Position of the bit</param>
/// <param name="value">Binary value to be written</param>
void RegBitWrite(unsigned long reg, char pos, char value)
{
    unsigned long mask = (~(1u << pos));
    unsigned long* regp = (unsigned long*)(reg);
    *regp = ((*regp & mask) | (value << pos));
}

/// <summary>
/// Write hex value to a register
/// </summary>
/// <param name="reg">Register with 32bit address, always in hex form</param>
/// <param name="value">Value in hex form</param>
void RegWrite(unsigned long reg, unsigned long value)
{
    unsigned long* regp = (unsigned long*)(reg);
    *regp = value;
}

/// <summary>
/// Read value from a register
/// </summary>
/// <param name="reg">Register with 32bit address, always in hex form</param>
/// <returns>Value in register</returns>
unsigned long RegRead(unsigned long reg)
{
    return (*(unsigned long*)(reg));
}

/// <summary>
/// Read one bit from the register
/// </summary>
/// <param name="reg">Register with 32bit address, always in hex form</param>
/// <param name="pos">Position of the bit</param>
/// <returns>Binary value from the position of the register</returns>
char RegBitRead(unsigned long reg, unsigned long pos)
{
    return (((*(unsigned long*)(reg)) >> pos) & 1u);
}
