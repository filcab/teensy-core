#include "mk20dx128.h"

extern unsigned long _stext;
extern unsigned long _etext;
extern unsigned long _sdata;
extern unsigned long _edata;
extern unsigned long _sbss;
extern unsigned long _ebss;
extern unsigned long _estack;

extern int main(void);
void ResetHandler(void);
