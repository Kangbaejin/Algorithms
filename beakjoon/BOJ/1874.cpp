/* baekjoon 1874
 *
 * 스택수열
 * 
 * https://www.acmicpc.net/problem/1874
 * 
 * 
 * 자료구조, 스택
 * 
 * 
 * 생각보다 구현이 간단했다.
 * 참고 사이트
 * https://gaeunhan.tistory.com/16
 * 
 * NO인 경우를 판별하기 위한 조건을 너무 어렵게 생각했다. 
 * (각 입력 값 이후에 나오는 입력 값보다 작은 값들은 내림차순을 만족해야 한다고 생각했었다.)
 * 
 * 각 입력을 받으며 cursor 위치보다 큰 수이면 그만큼 stack 에 push 하고 그렇지 않으면 pop을 하는데,
 * pop을 할 때 입력받은 값과 stack 의 top 에 있는 값이 다르다면, 구현할 수 없는 수열이다.
 * 
 * 시간초과 참고 주석이 달린 문제
 * https://www.acmicpc.net/problem/15552
 */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int> s;
    vector<char> result;
    int cursor = 1;
    int N=0;
    cin >> N;

    int val=0;
    for(int i=0; i<N; i++){
        cin >> val;

        while(cursor <= val){
            s.push(cursor++);
            result.push_back('+');
        }
        if(s.top() == val){
            s.pop();
            result.push_back('-');
        }
        else{
            cout << "NO";
            return 0;
        }
    }

    for(int i=0; i<result.size(); i++){
        cout << result[i] << '\n';
    }

}