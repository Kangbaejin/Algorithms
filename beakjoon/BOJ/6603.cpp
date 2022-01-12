/* baekjoon 6603
 *
 * 로또
 * 
 * https://www.acmicpc.net/problem/6603
 * 
 * 
 * 
 * iostream 사용할 때
 * ios_base::sync_with_stdio(0);
 * cin.tie(0);
 * 와 함께 endl 대신에 '\n' 을 사용하여 시간을 줄여야한다.
 * 
 * https://www.acmicpc.net/board/view/44800
 * 
 * 출력하지 않을 부분을 순차적으로 선택하려는 알고리즘을 구현하여 풀려고 했었는데,
 * c++ algorithm 헤더에 prev_permutation, next_permutation
 * 함수 형태로 순열을 순차적으로 변경하는 함수가 있었다.
 * 링크(https://en.cppreference.com/w/cpp/algorithm/prev_permutation)
 * 
 * prev_permutation 예시
 * 초기 입력
 * 4 3 2 1
 * 
 * 변화 과정
 * 4 3 2 1
 * 4 3 1 2
 * 4 2 1 3
 * 4 2 3 1
 * ...
 * ...
 * 1 2 3 4
 * 
 * 
 * 
 * 이를 이용해, 표시할 값(1), 표시하지 않을 값(0) 을 이용한 순열을 만들고,
 * 이 순열을 위의 함수를 이용하여 순차적으로 변경하며 값을 출력하는 아이디어이다.
 * 
 * 
 */

#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, x, i;
    while(1){
        cin >> t;

        vector<int> v;
        v.clear();

        vector<int> temp;
        temp.clear();


        if(t==0)
            return 0;

        for(i=0;i<t;i++){
            cin >> x;
            v.push_back(x);
        }

        for(i=0;i<6;i++){
            temp.push_back(1);
        }

        for(i=0;i<t-6;i++){
            temp.push_back(0);
        }

        /* 
         * temp 에는 11111100... 형태의 값이 들어간다. 예를 들어 t=7 이라면 1111110 이다.
         * 이 temp 순열을 prev_permtation 을 통해 1111110 -> 1111101 -> 111011 .. 식으로 변경하며
         * 1인 부분에 해당하는 수를 출력하는 방식이다.
         */

        do{
            for(i=0;i<t;i++){
                if(temp[i]==1)
                    cout << v[i] << " ";
            }
            cout << "\n";
        }while(prev_permutation(temp.begin(),temp.end()));
        cout << "\n";
    }
}