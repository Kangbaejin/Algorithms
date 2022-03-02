/* 
 * baekjoon 2110
 * 
 * 공유기 설치
 * 
 * https://www.acmicpc.net/problem/2110
 * 
 * 
 * 
 * 스택 두개로 중간값을 유지했던 커서 문제와 비슷한 형태로 풀 수 있었다.
 * 
 * 해당 문제는 우선순위 큐에서 index 접근이 불가능 하기 때문에,
 * 큐 2개를 선언하여 중간값을 계속 top 에 위치하도록 만들어 주게 된다.
 * 
 */



#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;


int N;
priority_queue<int, vector<int>, less<int>> front;
priority_queue<int, vector<int>, greater<int>> back;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    
    int x = 0;
    for(int i=0;i<N;i++){
        cin >> x;

        if(front.size()==0){
            front.push(x);
        }
        else{
            if(front.size()>back.size()){
                back.push(x);
            }
            else{
                front.push(x);
            }

            if(front.top()>back.top()){
                int temp_front = front.top();
                int temp_back = back.top();

                front.pop();
                back.pop();

                front.push(temp_back);
                back.push(temp_front);
            }
        }

        cout << front.top() << '\n';
    }

    return 0;
}
