/* 
 * baekjoon 11052
 * 
 * 카드 구매하기
 * 
 * https://www.acmicpc.net/problem/11052
 * 
 * 
 * 
 */

#include <iostream>
#include <algorithm>

#define MAX 10002
#define maxi(a,b) (a>b ? a : b)
using namespace std;

int N;

int value[MAX]={0,};
int result[MAX]={0,};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i=1;i<=N;i++){
        cin >> value[i];
    }

    result[1] = value[1];

    for(int i=2;i<=N;i++){
        for(int j=1;j<=i;j++){
            result[i] = maxi(result[i],result[i-j]+value[j]);
        }
    }
    cout << result[N];

    return 0;
}