#pragma once
#include "mbed.h"
#include <cstdint>

#define ONES_DATA_LEN 8

class Dual_Seven_Seg{
    protected:
        BusOut arrayBus;
        const uint8_t SEVEN_SEG_0_DATA      = 0b00001000;   
        const uint8_t SEVEN_SEG_1_DATA      = 0b01011011;   
        const uint8_t SEVEN_SEG_2_DATA      = 0b00100010;
        const uint8_t SEVEN_SEG_3_DATA      = 0b00010010;
        const uint8_t SEVEN_SEG_4_DATA      = 0b01010001;
        const uint8_t SEVEN_SEG_5_DATA      = 0b00010100;
        const uint8_t SEVEN_SEG_6_DATA      = 0b00000100;
        const uint8_t SEVEN_SEG_7_DATA      = 0b01011010;
        const uint8_t SEVEN_SEG_8_DATA      = 0b00000000;
        const uint8_t SEVEN_SEG_9_DATA      = 0b00010000;
        const uint8_t SEVEN_SEG_NULL_DATA   = 0b01111111;

        uint8_t tenths_data = SEVEN_SEG_NULL_DATA;
        uint8_t ones_data   = SEVEN_SEG_NULL_DATA;
        uint16_t combined_data = (1 << 16) - 1; // initalise to all ones, display off by default
    public: 

        enum Dual_Seven_Seg_Error{
            kDualSevenSegOk            = 0,
            kDualSevenSegOutOfRangeErr = -100
        };

        //@param Seven_seg_1 - Corresponds to the pin 1 on the dual 7 Segment Display
        //@param Seven_seg_2 - Corresponds to the pin 2 on the dual 7 Segment Display
        //@param Seven_seg_3 - Corresponds to the pin 3 on the dual 7 Segment Display
        //@param Seven_seg_5 - Corresponds to the pin 5 on the dual 7 Segment Display
        //@param Seven_seg_6 - Corresponds to the pin 6 on the dual 7 Segment Display
        //@param Seven_seg_7 - Corresponds to the pin 7 on the dual 7 Segment Display
        //@param Seven_seg_8 - Corresponds to the pin 8 on the dual 7 Segment Display
        //@param Seven_seg_10 - Corresponds to the pin 10 on the dual 7 Segment Display
        //@param Seven_seg_11 - Corresponds to the pin 11 on the dual 7 Segment Display
        //@param Seven_seg_12 - Corresponds to the pin 12 on the dual 7 Segment Display
        //@param Seven_seg_15 - Corresponds to the pin 15 on the dual 7 Segment Display
        //@param Seven_seg_16 - Corresponds to the pin 16 on the dual 7 Segment Display
        //@param Seven_seg_17 - Corresponds to the pin 17 on the dual 7 Segment Display
        Dual_Seven_Seg(  
                    PinName Seven_seg_1, 
                    PinName Seven_seg_2,
                    PinName Seven_seg_3,
                    PinName Seven_seg_5,
                    PinName Seven_seg_6,
                    PinName Seven_seg_7,
                    PinName Seven_seg_8,
                    PinName Seven_seg_10,
                    PinName Seven_seg_11,
                    PinName Seven_seg_12,
                    PinName Seven_seg_15,
                    PinName Seven_seg_16,
                    PinName Seven_seg_17,
                    PinName Seven_seg_18
                    );
        
        ~Dual_Seven_Seg();

        //@param value - The value to be displayed on the dual 7 segment display
        //@return - Returns kDualSevenSegOutOfRangeErr(-100) if the value is greater than 99, else returns kDualSevenSegOk(0)
        int write(uint8_t value);

        int clear();
};