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
 * 현재 body는 deque로 구현하고, 뱀의 현재 몸을 map에 기록한다?
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
#define max_map 101
using namespace std;

struct snake{
    int dir;
    vector<int> body;
};

int N, K, L;
int map[max_map][max_map];
int opers[max_map];
int DIR[5][2] = {{0,0},{-1,0},{0,1},{1,0},{0,-1}};
snake one_snake;

void Input(){
    cin >> N >> K;
    for(int i=0;i<K;i++){
        int x,y;
        cin >> x >> y;
        map[x][y] = 1;
    }

    cin >> L;
    for(int i=0;i<L;i++){
        int x;
        char c;
        cin >> x >> c;

        if(c == 'D') opers[x] = 2;
        else if(c == 'L') opers[x] = 1;
    }

}


bool moving(){

}

void solve(){
    int cnt = 1;
    while(moving()){
        cnt++;
    }

    cout << cnt;
}

int main(){
    return 0;
}