/* 
 * baekjoon 9663
 * 
 * N-Queen
 * 
 * https://www.acmicpc.net/problem/9663
 * 
 * 
 * 고민을 많이 했음에도 실마리가 정말 보이지 않아
 * https://ko.wikipedia.org/wiki/%EC%97%AC%EB%8D%9F_%ED%80%B8_%EB%AC%B8%EC%A0%9C
 * 참고 했다.
 * 
 * 입력 받은 크기와 같은 변수를 전역 변수로 설정하여
 * 함수 인자로 전달하지 않아도 되는 아이디어도 얻을 수 있었다.
 * 
 * 배열의 위치를 기록하기 위해 이중 배열을 이용하여 해당 point 에 마킹을 하는 것이 아니라
 * 1차원 배열을 이용하여 1차원 배열에 값으로 index 를 저장하여 표현할 수 있다는 아이디어
 * 
 */

#include <iostream>
#include <cmath>

using namespace std;

int queens[15];
//해당 queens[i] 값은 i 행의 퀸의 위치를 나타낸다.
//예를 들어 queens[4] = 2 일때, (5,3) 위치에 퀸이 있다는 뜻, (행열은 바뀌어도 된다.)

int n;
int cnt;



void path(int level){//level 은 현재까지 몇개의 퀸이 배치 되었는지를 나타내는 변수
    
    int flag; //해당 flag 는 퀸이 배치될 수 있는지 여부를 기록하기 위한 변수
    if(level == n){
        // 입력 받는 n 개의 퀸이 배치가 되었다면 답이다.
        cnt++;
        return;
    }
    for(int i=0;i<n;i++){
        //이미 배치되어있는 퀸의 정보를 통해 i 번째 칸에 퀸을 배치할 수 있는지 확인
        flag = 1;
        for(int j=0;j<level;j++){
            if(queens[j]==i || abs(level-j) == abs(i-queens[j])){
                /*
                 * j번째 줄의 퀸과 같은 칸에 있는 경우, 대각선에 있는 경우, i 번째 칸에 대한 탐색 중단
                 * 이 때 대각선 판단에서 현재 level 에서 i 위치에 대한 것을 판단하고 있으므로,
                 * (level, i) 와 (j, queens[j]) 를 비교하여 
                 * abs(level-j) == abs(i-queens[j]) 이라면
                 * x 좌표 의 차이와 y 좌표의 차이가 같고,
                 * 그렇다면 대각선에 있다고 할 수 있다.
                 */
                flag = 0;
                break;
            }
        }
        if(flag){
            //flag 값의 변경 없었다.
            //배치가 가능 했다면 현재 level 에서의 queen 의 위치를 i 로 설정하고 다음 level 탐색
            queens[level]=i;
            path(level+1);
        }
    }
}

int main(){
    cin >> n;
    cnt = 0;
    path(0);

    cout << cnt << '\n';

    return 0;
}