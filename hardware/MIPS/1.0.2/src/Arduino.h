#ifndef Arduino_h
#define Arduino_h

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
// Weak empty variant initialization function.
// May be redefined by variant files.
extern void initVariant() __attribute__((weak));

#define HIGH	0x1
#define LOW		0x0

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))

extern void setup(void) ;
extern void loop(void) ;

void yield(void);
#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#endif // Arduino_h