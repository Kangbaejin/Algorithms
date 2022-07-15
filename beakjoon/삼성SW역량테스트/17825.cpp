/* 
 * baekjoon 17825
 * 
 * 주사위 윷놀이
 * 
 * https://www.acmicpc.net/problem/17825
 * 
 * 
 */

#include <iostream>

using namespace std;


//윷놀이 판(순서)
int map[35];

//현재 칸에 말이 있는지 확인
bool is_filled[35];

//윳놀이 판의 각 칸의 점수
int score[35];

//방향을 바꿔야할 곳에 표시
int turn[35];

//주사위 10번
int dice[10];

//각 말의 위치 표시
int stone[4];

int ans=0;

void Input(){
    for(int i=0;i<21;i++) map[i]=i+1;
    map[21]=21;

    for(int i=22;i<27;i++) map[i]=i+1;
    map[28]=29; map[29]=30; map[30]=25;
    map[31]=32; map[32]=25; map[27]=20;

    turn[5]=22; turn[10]=31; turn[15]=28;
    turn[25]=26;

    for(int i=0;i<21;i++) score[i]=i*2;
    score[22]=13; score[23]=16; score[24]=19;
    score[31]=22; score[32]=24; score[28]=28;
    score[29]=27; score[30]=26; score[25]=25;
    score[26]=30; score[27]=35;


    for(int i=0;i<10;i++) cin >> dice[i];
}



void DFS(int cnt, int sum) {
    if (cnt==10) {
        if (sum > ans) ans = sum;
        return;
    }
    for (int i=0; i<4; i++) {
        // 현재 말 위치, 이동 할 말 위치
        int prev = stone[i];
        int now = prev;
        // 움직여야 하는 횟수
        int move = dice[cnt];
 
        // 만약 현재 위치가 방향 전환 해야하는 곳 이라면 방향 전환 후 이동거리 1 감소
        if (turn[now] > 0) {
            now = turn[now];
            move -= 1;
        }
        // 주사위 만큼 이동
        while (move--) {
            now = map[now];
        }
 
        //현재 위치가 끝이거나 이미 차있다면 DFS 진행하지 않는다.
        if (now != 21 && is_filled[now] == true) continue;

        //이동이 진행되어 prev 위치에 있던 말을 now 로 옮겼다.
        is_filled[prev] = false;
        is_filled[now] = true;
        stone[i] = now;
        
        DFS(cnt + 1, sum + score[now]);
 
        stone[i] = prev;
        is_filled[prev] = true;
        is_filled[now] = false;
    }
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    Input();
    DFS(0,0);
    cout << ans << "\n";
    return 0;
}