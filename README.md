# Dual_Seven_Seg

# Example Code
```C++
#include "mbed.h"
#include "Dual_Seven_seg.h"

int main(){
    Dual_Seven_Seg seven_seg(   SEVEN_SEG_1_PIN,
                                SEVEN_SEG_2_PIN,
                                SEVEN_SEG_3_PIN,
                                SEVEN_SEG_5_PIN,
                                SEVEN_SEG_6_PIN,
                                SEVEN_SEG_7_PIN,
                                SEVEN_SEG_8_PIN,
                                SEVEN_SEG_10_PIN,
                                SEVEN_SEG_11_PIN,
                                SEVEN_SEG_12_PIN,
                                SEVEN_SEG_15_PIN,
                                SEVEN_SEG_16_PIN,
                                SEVEN_SEG_17_PIN,
                                SEVEN_SEG_18_PIN
                            );
    int i = 1;
    int sign = +1;
    while (true) {
        if(i >= 99 || i <= 0){
            sign = -sign;
        }

        if(seven_seg.write(i) == seven_seg.kDualSevenSegOutOfRangeErr){
            printf("Attempt to write value greater than 99");
            return -101;
        }
        i += sign;
        ThisThread::sleep_for(50ms);
    }
}
```