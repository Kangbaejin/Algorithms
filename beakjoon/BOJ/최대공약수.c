#include <stdio.h>

int gcd(int a, int b){
    int temp;
    if(a<b){
        temp = a;
        a = b;
        b = temp;
    }

    while(b!=0){
        temp = a%b;
        a = b;
        b = temp;
    }

    return a;

}
