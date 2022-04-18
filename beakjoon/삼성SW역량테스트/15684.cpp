/* 
 * baekjoon 15684
 * 
 * 사다리 조작
 * 
 * https://www.acmicpc.net/problem/15684
 * 
 * 
 * N : 세로선
 * M : 가로선
 * H : 가로선을 놓을 수 있는 위치 갯수
 * 
 * 
 * 구현
 * 만약 하나를 추가했을때 풀린다면 return 1
 * 하나를 추가해도 풀리지 않는다면 해당 상황에서 하나를 더 추가하여 풀린다면 return 2
 * 
 * 그래도 풀리지 않는다면 return -1
 * 
 * 
 * 일단 사다리를 타며, 각 세로선의 위치에 도달하는지 확인하는 함수 구현
 * (중간에 세로선의 위치가 아닌 부분에 도착한다면 바로 종료 가능)
 * 
 * solve 내에서 모든 경우를 탐색할 수 있도록 구현 후 사다리 결과를 check 한다.
 * 
 * 
 * solve 내부에서 모든 경우를 탐색할 수 있도록 구현하는 방법은
 * dfs 방식으로 구현할 수 있을 것이다.
 * 모든 탐색되지 않은 ( input 시에 row 배열업데이트와 함께 visit 배열도 업데이트 해야 할 것이다.)
 * visit 배열을 통해 연결 가능한 node 를 연결한 뒤 다음 선택을 진행하고, 다시 그 연결을 원래로 되돌리는 방식으로 진행.
 * 
 * 
 * 아래의 블로그를 참고하였다.
 * https://yabmoons.tistory.com/47
 */

#include <iostream>
#define max_H 30
#define max_N 11
#define init_ans 300
#define min(a,b) ((a<b) ? a:b)
using namespace std;

int N, M, H, ans;
bool map[max_N][max_H];

void Input(){
    ans = init_ans;
    cin >> N >> M >> H;
    for(int i=0;i<M;i++){
        int a, b;
        cin >> a >> b;
        map[b][a] = true;
    }
}

bool one_game(){
    for(int i=1;i<=N;i++){
        int value = i;
        for(int j=1;j<=H;j++){
            //길이 오른쪽에 연결된 경우
            if(map[value][j]==true) value++;
            //길이 왼쪽에 연결된 경우
            else if(map[value-1][j]==true) value--;
            //길이 연결되지 않은 else 부분은 그대로 아래로 내려가기 때문에 value 변화가 없다.
        }
        if(value!=i) return false;
    }
    return true;
}

void solve(int idx, int depth){
    if(depth >= 4) return;
    if(one_game() == true){
        ans = min(ans,depth);
        return;
    }

    //새로운 선을 연결하기 위한 모든 경우 탐색
    for(int j=idx; j<=H; j++){
        for(int i=1; i<N; i++){
            //A, B 두 선을 연결한다고 할 때,    (1) A (2) B (3)     1,2,3 위치에 선이 연결되어 있다면,
            //A, B 두 선을 연결할 수 없다.
            if(map[i][j] || map[i-1][j] || map[i+1][j]) continue;

            //dfs
            map[i][j] = true;
            solve(j,depth+1);
            map[i][j] = false;
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    Input();
    solve(1,0);
    if(ans == init_ans) ans = -1;
    cout << ans;

    return 0;
}