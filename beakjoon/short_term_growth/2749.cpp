/* 
 * baekjoon 2749
 * 
 * 피보나치 수 3
 * 
 * https://www.acmicpc.net/problem/2749
 * 
 */

#include <iostream>
#include <cstring>
#define div_n 1000000
using namespace std;

long long N;

long long A[2][2]={{1,1}, {1,0}};
long long ans[2][2];

void mat_mul(long long a[2][2], long long b[2][2]){
    long long temp[2][2];
    memset(temp, 0, sizeof(temp));
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                temp[i][j] += a[i][k]*b[k][j];
            }
            temp[i][j] = temp[i][j] % div_n;
        }
    }

    memcpy(a,temp,sizeof(temp));
}

void power(long long n){
    while(n>0){
        if(n%2==1){
            mat_mul(ans,A);
        }
        mat_mul(A,A);
        n /= 2;
    }
}


int main(){
    cin >> N;
    for(int i=0;i<2;i++){
        ans[i][i]=1;
    }
    power(N);
    cout << ans[1][0] % div_n;
    return 0;
}