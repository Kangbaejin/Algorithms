/* 
 * baekjoon 2609
 * 
 * 최대공약수와 최소공배수
 * 
 * https://www.acmicpc.net/problem/2609
 * 
 */

#include <iostream>

using namespace std;


int gcd(int a, int b){//최대공약수
    int temp;
    if(a<b){
        temp = a;
        a = b;
        b = temp;
    }

    while(b!=0){
        temp = a % b;
        a = b;
        b = temp;
    }

    return a;
}


int main(){
    int x,y;
    cin >> x >> y;

    int temp;
    temp = gcd(x,y);
    //x * y = 최소공배수 * 최대공약수 관계임
    cout << temp << '\n' << (x*y)/temp;
}