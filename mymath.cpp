//
// Created by cooler on 20-12-30.
//

#include "mymath.h"

float mymath::constrain_float(float val, float min, float max){
    if(val<min) return min;
    if(val>max) return max;
    return val;

}
