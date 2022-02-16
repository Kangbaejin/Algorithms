/* 
 * baekjoon 11726
 * 
 * 2xn 타일링
 * 
 * https://www.acmicpc.net/problem/11726
 * 
 * 
 * 
 * i 번째의 경우는 , (i-1 번째에서 '|' 모양을 더한 경우) + (i-2 번째에서 '=' 모양을 더한 경우)
 * 따라서 ary[i] = ary[i-1] + ary[i-2] 이다.
 * 
 * 
 */

#include <iostream>
#include <algorithm>

#define MAX 1001

using namespace std;

int N;

int ary[MAX]={0,};

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    ary[1] = 1;
    ary[2] = 3;

    for(int i=3;i<MAX;i++){
        ary[i] = (ary[i-1] + ary[i-2]*2)%10007;
    }

    cout << ary[N];

    return 0;
}
