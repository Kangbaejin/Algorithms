/* 
 * baekjoon 2156
 * 
 * 포도주 시식
 * 
 * https://www.acmicpc.net/problem/2156
 * 
 * 
 * 
 * https://yabmoons.tistory.com/18
 * 
 * 연속된 3개의 잔 중에서 1+2, 1+3, 2+3, 중 최댓값을 계속 기록
 * 
 */

#include <iostream>
#define MAX 10001
#define maxi(a,b) (a>b ? a : b)
using namespace std;

int value[MAX+1]={0,};
int result[MAX+1] = {0,};



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    for(int i=1; i<=N;i++){
        cin >> value[i];
    }

    result[0] = value[0] = 0;
    result[1] = value[1];
    result[2] = value[1] + value[2];

    for(int i=3; i<=N; i++){
        int a = value[i] + value[i-1] + result[i-3];     //N-3번째 최대값 + N-1 + N (1+3 경우)
        int b = value[i] + result[i-2];                  //N-2번째 최대값 + N       (2+3 경우)
        int c = result[i-1];                             //N-1번째 최대값           (1+2 경우)
        result[i] = maxi(a,maxi(b,c));
    }

    int max = 0;
    
    for(int i=0;i<=N;i++){
        if(result[i] > max)
            max = result[i];
    }

    cout << max;

    return 0;
}