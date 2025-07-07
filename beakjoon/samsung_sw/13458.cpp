/* 
 * baekjoon 13458
 * 
 * 시험 감독
 * 
 * https://www.acmicpc.net/problem/13458
 * 
 * N 시험장의 수
 * A 각 시험장의 응시자의 수
 * B 총 감독관의 감시 인원 수
 * C 부 감독관의 감시 인원 수
 * 
 * 
 */

#include <iostream>
#include <vector>
#define MAX 1000001
using namespace std;

int N,A[MAX],B,C;

void Input(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    cin >> B >> C;
}

void solve(){
    long long ans=N;
    for(int i=0;i<N;i++){
        A[i]-=B;
    }

    for(int i=0;i<N;i++){
        if(A[i] > 0){
            int q = A[i]/C;
            int r = A[i]%C;
            if(r==0){
                ans += q;
            }
            else ans+=(q+1);
        }
    }
    cout << ans;
}


int main(){
    Input();
    solve();

    return 0;
}