//
// Created by ljx on 19-1-30.
//

#include "power_of_two.h"

bool isPowerOfTwo(int n) {
    if(n<1)
        return false;
    while(n>1){
        if(n%2!=0)
            return false;
        n/=2;
    }
    return true;
}
