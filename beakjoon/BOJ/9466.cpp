/* 
 * baekjoon 9466
 * 
 * 텀 프로젝트
 * 
 * https://www.acmicpc.net/problem/9466
 * 
 * 
 * 
 * 아래 링크의 코드를 참고하여 구현 했다.
 * https://jaimemin.tistory.com/674
 * 
 * memset을 이용한 초기화, for 문을 이용한 연결된 팀원 탐색,
 * DFS 사용등이 잘 정리되어 많은 것을 배울 수 있었다.
 * 
 */
#include <iostream>
#include <cstring> //memset 사용

#define MAX 100001

using namespace std;

int student, cnt;
int want[MAX];
bool visited[MAX];
bool done[MAX];

void DFS(int nodeNum){
    visited[nodeNum] = true;

    int next = want[nodeNum];
    if(!visited[next])
        DFS(next);
    //이미 방문 했지만 방문이 끝나지 않았다면, 사이클이 있는 경우이다.
    //팀으로 구성되는 경우를 의미한다.
    else if(!done[next]){
        //가르키는 팀원들을 for 문을 통해 계속 방문하며 센다.
        for(int i = next; i != nodeNum; i=want[i])
            cnt++;
        
        cnt++;//자기 자신을 센다.
    }

    done[nodeNum] = true;//더 이상 이 노드를 방문하지 않는다.
}




int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int test;
    cin >> test;

    for(int i=0;i<test;i++){
        cin >> student;
        //memset 을 이용하여 매 경우마다 bool array 초기화
        memset(visited, false, sizeof(visited));
        memset(done, false, sizeof(done));

        for(int j=1;j<=student;j++){
            cin >> want[j];
        }

        cnt = 0;
        for(int j=1;j<=student;j++){
            if(!visited[j])
                DFS(j); //입력받은 원하는 목록을 하나씩 DFS를 통해 탐색
        }

        cout << student - cnt << '\n';
    }


    return 0;
}
