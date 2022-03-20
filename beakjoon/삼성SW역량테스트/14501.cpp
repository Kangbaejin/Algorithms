/* 
 * baekjoon 14501
 * 
 * 퇴사
 * 
 * https://www.acmicpc.net/problem/14501
 * 
 * 
 * 
 * 구현 계획
 * 
 * 애초에 퇴사이후에 끝나는 일의 이익은 0으로 입력받음.
 * 해당 요일 이전에 끝나는 최대 이익 + 해당 요일의 금액 -> DP 형태의 max 값 출력 가능
 * 
 */


#include <iostream>
#include <algorithm>
#define max_Day 16

using namespace std;

int pay[max_Day];
int time[max_Day];
int dp[max_Day];
int N;


int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin >> N;
    int t, p;
    for(int i=1;i<=N;i++){
        cin >> time[i] >> pay[i];
        if(time[i]+i>N+1) pay[i] = 0;
        for(int j=0;j<i;j++){
            if(time[j]+j <= i){
                dp[i] = max(dp[i], dp[j]+pay[i]);
            }
        }
    }
    
    cout << *max_element(dp, dp+max_Day);

    return 0;
}