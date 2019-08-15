#include<euler/euler.h>
#include<exponent/exponent.h>

float GetE(int n){
    float base = 1 + (1.0 / n);
    float result = CalculateExponent(base, n);
    return result;
}