// 209193481 Sivan Jhirad

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
    return result;
}

magnitude add(magnitude a, magnitude b) {
    a = fromTwoComplementsToMagnitude(a);
    b = fromTwoComplementsToMagnitude(b);
    int result = a + b;
    if (a < 0 || b < 0) {
        result = -fromMagnitudeToTwoComplements(result);
    }
    else if (result < 0 ) {
        result = fromMagnitudeToTwoComplements(result);
    }
    return result;

}

magnitude sub(magnitude a, magnitude b) {
    a = fromTwoComplementsToMagnitude(a);
    b = fromTwoComplementsToMagnitude(b);
    int result = a - b;
    if (a < b) {
        result = -fromMagnitudeToTwoComplements(result);
    }
    else if (result < 0 ) {
        result = fromMagnitudeToTwoComplements(result);
    }
    return result;
}

magnitude multi(magnitude a, magnitude b) {
    a = fromTwoComplementsToMagnitude(a);
    b = fromTwoComplementsToMagnitude(b);
    int result = a * b;
    if( (a > 0 && b> 0) ||(a <0 && b <0)){
        result = fromMagnitudeToTwoComplements(result);
    }else {
        result = -fromMagnitudeToTwoComplements(result);
    }
    return result;

}

int equal(magnitude a, magnitude b) {
    a = fromTwoComplementsToMagnitude(a);
    b = fromTwoComplementsToMagnitude(b);
    if (a == b) {return 1;}
    else {return 0;}
}

int greater(magnitude a, magnitude b) {
    a = fromTwoComplementsToMagnitude(a);
    b = fromTwoComplementsToMagnitude(b);
    if (a > b) {return 1;}
    else {return 0;}
}


