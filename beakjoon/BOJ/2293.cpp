/* 
 * baekjoon 2293
 * 
 * 동전
 * 
 * https://www.acmicpc.net/problem/2293
 * 
 * 
 */

#include <iostream>
#include <algorithm>

using namespace std;

int N, K, cnt;

int ary[101];

void solve(int a, int level){
    if(a>K) return;
    if(a == K){
        cnt++;
        return;
    }
    for(int i=level;i<N;i++){
        solve(a+ary[i], i);
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    for(int i=0;i<N;i++){
        cin >> ary[i];
    }

    cnt = 0;
    for(int i=0;i<N;i++){    
        solve(ary[i], i);
    }

    cout << cnt;
    return 0;
}
