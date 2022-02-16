/* 
 * baekjoon 1912
 * 
 * 연속합
 * 
 * https://www.acmicpc.net/problem/1912
 * 
 * 
 * 연속적인 합을 구하면서 만약 합이 음수가 된다면, 더하는 부분에서의 최대를 구한 뒤,
 * 부분합을 새로 시작한다. 왜냐하면 앞쪽 부분합이 음수면 뒷쪽 부분합에 더할 이유가 없기 떄문이다.
 * 
 * 따라서 부분합(temp) 의 값이 음수가 된다면, temp 값을 0으로 초기화 해준 뒤, 다시 부분합을 구하기 시작한다.
 * 이때 부분합을 구하면서 최대인 부분합은 max 변수를 통해 계속 기록한다.
 * 
 */

#include <iostream>
#include <algorithm>

using namespace std;

int N;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    int max = -1001;
    int temp = 0;
    int x;

    for(int i=0;i<N;i++){
        cin >> x;
        temp += x;
        if(max < temp){
            max = temp;
        }
        if(temp < 0){
            temp = 0;
        }
    }

    cout << max;

    return 0;
}
