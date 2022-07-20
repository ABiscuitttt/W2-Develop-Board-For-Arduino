#include "Registers.h"
#include "Serial.h"

void GPIOInputOpen(char pin);

void GPIOPinOutPut(char pin, char value);

void GPIOOutPut(char value);

char GPIOPinInput(char pin);

unsigned long GPIOInput();