/* 
 * baekjoon 2293
 * 
 * 동전
 * 
 * https://www.acmicpc.net/problem/2293
 * 
 * 
 * 큰 단위로는 작은 단위를 계산할 수 없으니 작은 단위부터 값을 반영해준 뒤, 큰 단위를 반영한다.
 * 1, 2, 5 인 경우라면 
 * 
 * 제일 먼저, 1로 계산 가능한 가짓수를 더한다.
 * result[1] = result[1] + result[0]  1은 아무것도 선택하지 않는 경우 + 1을 선택하는 경우 (아무것도 선택하지 않는 것은 result[0] = 1)
 * result[2] = result[1] + result[1]  2는 1을 선택하는 경우 + 1을 선택하는 경우
 * result[3] = result[2] + result[1]  3은 2를 선택하는 경우 + 1을 선택하는 경우 ...
 * 
 * 와 같이 연속적으로 단위만큼의 결과에 더해주며 최종적으로 result[K] 값을 구한다.
 * 
 */

#include <iostream>
#include <algorithm>

using namespace std;

int N, K;

int ary[101];
int result[100001]={0,};    //"result[a] = b" 의 의미는 a를 만들수 있는 경우의 수는 b 가지이다.


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    for(int i=0;i<N;i++){
        cin >> ary[i];
    }

    result[0] = 1;      //result[0] = 1   0을 만드는 경우의 수는 0 하나이기 때문이다.

    for(int i=0;i<N;i++){
        for(int j=ary[i]; j<=K; j++){
            result[j] = result[j] + result[j-ary[i]];
        }
    }


    cout << result[K];

    return 0;
}
