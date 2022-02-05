/* 
 * baekjoon 1932
 * 
 * 정수 삼각형
 * 
 * https://www.acmicpc.net/problem/1932
 * 
 * 
 */

#include <iostream>
#define MAX 501
#define maxi(a,b) (a>b ? a : b)
using namespace std;

int value[MAX][MAX] = {0,};
int result[MAX][MAX] = {0,};



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=i;j++){
            cin >> value[i][j];
        }
    }

    result[1][1] = value[1][1];

    for(int i=2;i<=N;i++){
        for(int j=1;j<=i;j++){
            result[i][j] = maxi(result[i-1][j-1],result[i-1][j]) + value[i][j];
        }
    }


    int answer = 0;

    for(int i=1;i<=N;i++){
        if(answer < result[N][i])
            answer = result[N][i];
    }

    cout << answer;

    return 0;
}