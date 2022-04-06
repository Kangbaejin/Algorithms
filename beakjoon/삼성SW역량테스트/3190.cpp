/* 
 * baekjoon 3190
 *
 * 뱀
 * 
 * https://www.acmicpc.net/problem/3190 
 * 
 * 
 * 구현
 * 
 * 진행 방향은 DIR 로 구현하여 1,2,3,4 로 나타낸다.
 * 이는 순서대로 북 동 남 서 를 나타낸다.
 * 
 * L , D 에 대한 정보는 opers 배열에 해당 시간에 맞도록 입력한다.
 * 이때 L = 1, D = 2 로 해당 정보를 입력한다.
 * 
 * moving 함수
 * 해당 body를 deque로 구현해야하나? 그렇지만 body를 검사하여 자신의 몸에 부딪히는지 파악해야하는데?
 * 현재 body는 deque로 구현하고
 * map 에 body 위치 (= 9)를 모두 표시한다.
 * 이후 머리 + 방향 칸의 map 이 뱀의 body이면(9 이면)
 * x = dq.front().first+DIR[one.snake.dir][0]
 * y = dq.front().second+DIR[one.snake.dir][1]
 * map[x][y]==9 이면 moving 을 끝내고, 9 가 아니면 진행
 * 
 * 진행할 때 마지막 부분에서 map 업데이트
 * 
 * 
 * 먼저 snake.dir 방향으로 한칸을 body에 추가한다. 이후 해당 위치가 사과라면 그대로 두고,
 * 해당 위치에 아무것도 없다면 꼬리 위치칸을 비워준다.
 * 
 * 위 동작 수행 후, 추가된 머리가 몸에 부딪히는지 파악한다.
 * 부딪힌다면 false 를 return 하여 게임을 끝나게 하고,
 * 부딪히지 않는다면 true 를 return 하여 다음 동작을 수행시킨다.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#define max_map 101
using namespace std;

struct snake{
    int dir;
    deque<pair<int, int>> body;
};

int N, K, L;
int map[max_map][max_map];
int opers[10001];
int DIR[5][2] = {{0,0},{-1,0},{0,1},{1,0},{0,-1}};
snake one_snake;


void printmap(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}


void Input(){
    one_snake.dir = 2;
    one_snake.body.push_front({1,1});
    map[1][1] = 9;

    cin >> N >> K;
    for(int i=0;i<K;i++){
        int x,y;
        cin >> x >> y;
        map[x][y] = 1;
    }

    cin >> L;
    for(int i=1;i<=L;i++){
        int x;
        char c;
        cin >> x >> c;

        if(c == 'D') opers[x] = 2;
        else if(c == 'L') opers[x] = 1;
    }

}

void turn(snake &s, int wise){
    //왼쪽으로 돌리기
    if(wise == 1){
        if(s.dir == 1) s.dir = 4;
        else s.dir--;
    }
    //오른쪽으로 돌리기
    else{
        if(s.dir == 4) s.dir = 1;
        else s.dir++;
    }
}

bool moving(int cnt){
    int x = one_snake.body.front().first;
    int y = one_snake.body.front().second;

    int newx = x + DIR[one_snake.dir][0];
    int newy = y + DIR[one_snake.dir][1];

    if(map[newx][newy]==9) return false;
    if(newx < 1 || newx > N || newy < 1 || newy > N) return false; 


    one_snake.body.push_front({newx,newy});
    

    if(map[newx][newy]==0)  {
        int delx = one_snake.body.back().first;
        int dely = one_snake.body.back().second;
        map[delx][dely]=0;
        one_snake.body.pop_back();
        
    }

    map[newx][newy] = 9;

    if(opers[cnt]!=0){
        turn(one_snake, opers[cnt]);
    }


    //printmap();
    //cout << "\n";
    return true;

}


void solve(){
    int cnt = 1;
    while(moving(cnt)){
        cnt++;
    }
    cout << cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    Input();
    solve();
    return 0;
}