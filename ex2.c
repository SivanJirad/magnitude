//
// Created by sivan Jhirad on 13/11/2021.
//

#include <stdio.h>
#include "ex2.h"
#include "math.h"

magnitude fromTwoComplementsToMagnitude(int x){
    int value = 0;
    for (int i =0; i < 31; i++){
        if (abs(x) % 2 == 1){
            value += pow(2, i);
        }
        x = x >> 1;
    }
    if (x & 1 == 1){
        value = -value;
    }
    return value;
}


int fromMagnitudeToTwoComplements(magnitude x) {
    x=-x;
    x -= 1;
    int result = 0;
    for (int i = 0; i < 31; i++) {
        if (abs(x) % 2 == 0) {
            result += pow(2, i);
        }
        x = x >> 1;
    }
    return -result;
}


magnitude add(magnitude a, magnitude b) {
    a = fromTwoComplementsToMagnitude(a);
    b = fromTwoComplementsToMagnitude(b);
    return fromMagnitudeToTwoComplements(a+b);





    /*
    int result = 0;
    int carry = 0;

    for (int i =0; i < 31; i++) {
        if (a % 2 == 0) {                          // lsb of a = 0
            if (b % 2 == 0 && carry == 1) {        // lsb of b = 0 and carry = 1
                    result += pow(2, i);
                    carry = 0;
            } else if(b % 2 == 1 && carry == 0) {  // lsb of b = 1 and carry = 0
                    result += pow(2, i);
            }
        } else {                                  // lsb of a = 1
            if (b % 2 == 0 && carry == 0) {       // lsb of b = 0 and carry = 0
                    result += pow(2, i);
            } else if (carry == 0){              // lsb of b = 1 && carry = 0
                    carry =1;
            } else if (carry == 1) {             // lsb of b = 1 && carry = 1
                    result += pow(2, i);
            }
        }
        a = a >> 1;
        b = b >> 1;
    }
    if (a == -1 || b == -1){
        result = - result;
    }
    return result;

    */
}

int print_magnitude(magnitude x){
    unsigned int mask = 0x7FFFFFFF, sign_mask = 0x80000000;
    int sign = (sign_mask & x) > 0 ? -1:1;
    return (int) ((x & mask) * sign);
}

/*
magnitude sub(magnitude a, magnitude b) {}
magnitude multi(magnitude a, magnitude b) {}

// true = 1, false = 0
int equal(magnitude a, magnitude b) {}
int greater(magnitude a, magnitude b) {}

*/
void maxMin() {
    int val = 0;
    //bit 1 until bit 31 is 1, bit 32 is sign
    for( int i = 0; i < 31; i++) {
        val += pow(2,i);
    }
    printf("%d", val);
}