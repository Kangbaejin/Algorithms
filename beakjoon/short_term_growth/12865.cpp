/* 
 * baekjoon 12865
 * 
 * 평범한 배낭
 * 
 * https://www.acmicpc.net/problem/12865
 * 
 */

#include <iostream>
#include <algorithm>
using namespace std;


int N,K,W,V;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int dp[100001]={0};

    cin >> N >> K;
    for(int i=1;i<=N;i++){
        cin >> W >> V;
        for(int j=K; j>=W; j--){
            dp[j] = max((dp[j-W] + V), dp[j]);
        }
    }

    cout << dp[K];

    return 0;
}