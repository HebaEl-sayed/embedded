#include"STD_TYPES.h"


void delay_ms(u16 milliseconds) {
   
    for (u16 i = 0; i < milliseconds; i++) {
        
        for (u16 j = 0; j < 800 ; j++) {
            asm volatile("nop");
        }
    }
}