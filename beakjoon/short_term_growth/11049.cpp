/* 
 * baekjoon 11049
 * 
 * 행렬 곱셈 순서
 * 
 * https://www.acmicpc.net/problem/11049
 * 
 * 
 */

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n;
const int max_n = 501;
int m[max_n][2];

//dp[a][b] = k 의 의미는 a 부터 b 번째 행렬을 연산했을 때의 최솟값이 k임을 의미한다.
int dp[max_n][max_n];


int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> m[i][0] >> m[i][1];
    }

    /*
     * i : 곱셈 연산에 참여한 행렬 수
     * j : 곱셈 시작 행렬의 번호
     * k : 시작점 j 부터 i+j 위치까지 탐색을 위한 변수
     * 
     * 해당 for 문은 j 부터 시작하여 i+j 까지의 행렬의 곱셈의 최솟값을 구한다.
     * 
     * dp[j][i+j] 의 값은 아래의 연산을 통해 구해진다.
     * k 는 j 부터 j + i 까지 반복된다.
     * 
     * k 가 j 일 때, dp[j][j] + dp[j+1][i+j] + m[j][0]*m[k][1]*m[i+j][1] 와 비교
     * k 가 j + 1 일 때, dp[j][j+1] + dp[j+1+1][i+j] + m[j][0]*m[j+1][1]*m[i+j][1] 와 비교
     * k 가 j + 2 일 때, dp[j][j+2] + dp[j+2+1][i+j] + m[j][0]*m[j+2][1]*m[i+j][1] 와 비교
     * ...
     * k 가 j + i 일 때, dp[j][j+i] + dp[j+i+1][i+j] + m[j][0]*m[j+i][1]*m[i+j][1] 와 비교
     * 
     */
    for(int i=1; i<n; i++){
        for(int j=1; i+j<=n; j++){
            dp[j][i+j] = INT_MAX;
            for(int k=j; k<=i+j; k++){
                dp[j][i+j] = min(dp[j][i+j], dp[j][k] + dp[k+1][i+j] + m[j][0]*m[k][1]*m[i+j][1]);
            }
        }
    }

    cout << dp[1][n];

    return 0;
}