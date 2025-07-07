/* 
 * baekjoon 11066
 * 
 * 파일 합치기
 * 
 * https://www.acmicpc.net/problem/11066
 * 
 */

#include <iostream>
#include <algorithm>
#define INF 1000000000
using namespace std;

int sum[501], file[501], dp[501][501];

int main(){
    int T; cin >> T;
    while(T--){
        int t; cin >> t;
        for(int i=1; i<=t; i++){
            cin >> file[i];
            sum[i] = sum[i-1] + file[i];
        }

        for(int i=1; i<=t; i++){
            for(int j=1; j<=t-i; j++){
                dp[j][i+j] = INF;
                for(int k=j; k<i+j; k++){
                    dp[j][i+j] = min(dp[j][i+j], dp[j][k] + dp[k+1][i+j] + sum[i+j] - sum[j-1]);
                }
            }


        }
        cout << dp[1][t] << "\n";
    }
    return 0;
}