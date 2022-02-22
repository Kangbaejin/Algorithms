/* 
 * baekjoon 11047
 * 
 * 동전 0
 * 
 * https://www.acmicpc.net/problem/11047
 * 
 * 
 * 
 * 3 12
 * 1 4 5 
 * 위 처럼 단위가 배수가 아닌 경우라면 5 5 1 1 이 아니라 4 4 4 가 답이 될 것이다.
 * 
 * 하지만 조건에 Ai 는 Ai-1 의 배수라고 했기 때문에,
 * 큰 값부터 나누어 떨어지는 만큼 빼면서 진행해도 위와 같은 예외가 발생하지 않는다.
 * 
 * 
 */

#include <iostream>
#include <algorithm>

using namespace std;

int N, K;

int ary[11];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    int remain = K;
    int cnt = 0;

    for(int i=0;i<N;i++){
        cin >> ary[i];
    }


    int temp = 0;
    for(int i=N-1;i>=0;i--){
        temp = remain/ary[i];
        cnt += temp;
        remain = remain%ary[i];

        if(remain == 0){
            cout << cnt;
            break;
        }
    }



    return 0;
}
