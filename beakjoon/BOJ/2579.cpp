/* 
 * baekjoon 2576
 * 
 * 계단 오르기
 * 
 * https://www.acmicpc.net/problem/2576
 * 
 * 
 */

#include <iostream>
#define MAX 300
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

    for(int i=0; i<N;i++){
        cin >> value[i];
    }

    result[0] = value[0];
    result[1] = value[0]+value[1];
    result[2] = maxi(value[0]+value[2], value[1]+value[2]);

    for(int i=3; i<N; i++){
        result[i] = maxi(value[i] + result[i-2], value[i] + value[i-1] + result[i-3]);
    }

    cout << result[N-1];

    return 0;
}