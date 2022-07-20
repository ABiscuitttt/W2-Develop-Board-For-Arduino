#ifndef Arduino_h
#define Arduino_h

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#define HIGH	0x1
#define LOW		0x0

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))

#ifndef IrFuncPtr_
#define IrFuncPtr_
typedef void (*IrFuncPtr)(void);
#endif

extern void setup(void) ;
extern void loop(void) ;
extern void attachInterrupt(IrFuncPtr);

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#endif // Arduino_h