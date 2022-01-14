/* 
 * baekjoon 9095
 * 
 * 1, 2, 3 더하기
 * 
 * https://www.acmicpc.net/problem/9095
 * 
 */

#include <iostream>

using namespace std;


/*
 *
 * 7 = 1+1+1+1+1+1+1 이라고 했을때
 * 맨앞의 3개를 2개 이어붙이고 건너뛰기,
 * 1개 이어붙이고 건너뛰기,
 * 0개 이어붙이고 넌너뛰기 3가지로 생각할 수 있다.
 * 7 -> 3 + 4 / 2 + 5 / 1 + 6 케이스로 볼 수 있다.
 * 
 * 
 */

int solve(int n){
    if(n<1) return 0;
    else if(n==1)   return 1;
    else if(n==2)   return 2;
    else if(n==3)   return 4;
    else{
        return solve(n-1)+solve(n-2)+solve(n-3);
    }
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, n;

    int q,r;
    cin >> T;
    while(T--){
        cin >> n;
        cout  << solve(n) << '\n'; 
    }

    return 0;
}
