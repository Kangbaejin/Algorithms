/* 
 * baekjoon 10830
 * 
 * 행렬 제곱
 * 
 * https://www.acmicpc.net/problem/10830
 * 
 */

#include <iostream>
#include <cstring>
using namespace std;

long long N,B;

long long A[5][5];
long long ans[5][5];

void mat_mul(long long a[5][5], long long b[5][5]){
    long long temp[5][5];
    memset(temp, 0, sizeof(temp));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                temp[i][j] += a[i][k]*b[k][j];
            }
            temp[i][j] = temp[i][j] % 1000;
        }
    }

    memcpy(a,temp,sizeof(temp));
}



int main(){
    cin >> N >> B;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> A[i][j];
        }
        ans[i][i]=1;
    }

    while(B>0){
        if(B%2==1){
            mat_mul(ans,A);
        }
        mat_mul(A,A);
        B /= 2;
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    

    return 0;
}
