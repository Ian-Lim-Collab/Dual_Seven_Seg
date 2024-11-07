#pragma once
#include "mbed.h"
#include <cstdint>

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

        enum Dual_Seven_Seg_Error{
            kDualSevenSegOk            = 0,
            kDualSevenSegOutOfRangeErr = -100
        };

        uint8_t tenths_data = SEVEN_SEG_NULL_DATA;
        uint8_t ones_data   = SEVEN_SEG_NULL_DATA;
        uint16_t combined_data = (1 << 16) - 1; // initalise to all ones, display off by default
    public: 
        Dual_Seven_Seg(  PinName Seven_seg_1, 
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

        int write(uint8_t value);
};