#include "Dual_Seven_Seg.h"

Dual_Seven_Seg::Dual_Seven_Seg(   
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
    PinName Seven_seg_18)
    :arrayBus(
        Seven_seg_11,
        Seven_seg_12,
        Seven_seg_10,
        Seven_seg_7,
        Seven_seg_5,
        Seven_seg_8,
        Seven_seg_6,
        NC,
        Seven_seg_16,
        Seven_seg_18,
        Seven_seg_15,
        Seven_seg_17,
        Seven_seg_1,
        Seven_seg_3,
        Seven_seg_2,
        NC
    ){
    arrayBus.write(this->combined_data);
};

Dual_Seven_Seg::~Dual_Seven_Seg(){
};

int Dual_Seven_Seg::write(uint8_t value){
    uint8_t tenths,ones;
    if(value > 99){
        return kDualSevenSegOutOfRangeErr;
    }
    tenths = value / 10;
    ones = value % 10;

    switch (tenths) {
        case 9:
            tenths_data = SEVEN_SEG_9_DATA;
            break;
        case 8:
            tenths_data = SEVEN_SEG_8_DATA;
            break;
        case 7:
            tenths_data = SEVEN_SEG_7_DATA;
            break;
        case 6:
            tenths_data = SEVEN_SEG_6_DATA;
            break;
        case 5:
            tenths_data = SEVEN_SEG_5_DATA;
            break;
        case 4:
            tenths_data = SEVEN_SEG_4_DATA;
            break;
        case 3:
            tenths_data = SEVEN_SEG_3_DATA;
            break;
        case 2:
            tenths_data = SEVEN_SEG_2_DATA;
            break;
        case 1:
            tenths_data = SEVEN_SEG_1_DATA;
            break;
        default:
            tenths_data = SEVEN_SEG_NULL_DATA;
    }

    switch (ones) {
        case 9:
            ones_data = SEVEN_SEG_9_DATA;
            break;
        case 8:
            ones_data = SEVEN_SEG_8_DATA;
            break;
        case 7:
            ones_data = SEVEN_SEG_7_DATA;
            break;
        case 6:
            ones_data = SEVEN_SEG_6_DATA;
            break;
        case 5:
            ones_data = SEVEN_SEG_5_DATA;
            break;
        case 4:
            ones_data = SEVEN_SEG_4_DATA;
            break;
        case 3:
            ones_data = SEVEN_SEG_3_DATA;
            break;
        case 2:
            ones_data = SEVEN_SEG_2_DATA;
            break;
        case 1:
            ones_data = SEVEN_SEG_1_DATA;
            break;
        default:
            ones_data = SEVEN_SEG_0_DATA;
    }

    this -> combined_data = tenths_data << ONES_DATA_LEN | ones_data;
    arrayBus.write(combined_data);
    return kDualSevenSegOk;
};

int Dual_Seven_Seg::clear(){
    tenths_data = SEVEN_SEG_NULL_DATA;
    ones_data   = SEVEN_SEG_NULL_DATA;
    this -> combined_data = tenths_data << ONES_DATA_LEN | ones_data;
    arrayBus.write(combined_data);
    return kDualSevenSegOk;
}

