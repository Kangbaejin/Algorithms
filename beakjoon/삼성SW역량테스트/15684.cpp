/* 
 * baekjoon 15684
 * 
 * 사다리 조작
 * 
 * https://www.acmicpc.net/problem/15684
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
 * sovle 내부에서 모든 경우를 탐색할 수 있도록 구현하는 방법은
 * dfs 방식으로 구현할 수 있을 것이다.
 * 모든 탐색되지 않은 ( input 시에 row 배열업데이트와 함께 visit 배열도 업데이트 해야 할 것이다.)
 * visit 배열을 통해 연결 가능한 node 를 연결한 뒤 다음 선택을 진행하고, 다시 그 연결을 원래로 되돌리는 방식으로 진행.
 * 
 */

#include <iostream>
#include <vector>
#define max_H 30
#define max_N 11
using namespace std;

int N, M, H;
//가로 길 표시 ex) 세로선 1,2 가 가로의 4번째 칸에서 연결되어 있는 경우,  row[4][1] = 2, row[4][2] = 1
int row[max_H][max_N];


void Input(){
    cin >> N >> M >> H;
    for(int i=0;i<M;i++){
        int a, b;
        cin >> a >> b;
        row[a][b] = b+1;
        row[a][b+1] = b;
    }
}

void solve(){

}


int main(){
    Input();
    solve();

    return 0;
}