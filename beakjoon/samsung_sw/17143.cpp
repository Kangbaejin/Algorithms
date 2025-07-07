/* 
 * baekjoon 17143
 * 
 * 낚시왕
 * 
 * https://www.acmicpc.net/problem/17143
 * 
 * 
 * speed = 1000 인경우
 * 한칸씩 움직이면 1000번 움직임.
 * 따라서 speed 를 방향에 맞게 row 나 col 로 % 연산하여 이동 횟수를 줄인다.
 * 
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct shark{
    int speed=0;
    int dir=0;
    int size=0;    
};

const int max_rc = 100;
int R, C, M, ans=0;
shark map[max_rc][max_rc];

void make_shark(int r, int c, int s, int d, int z){
    shark one = {s,d,z};
    map[r][c] = one;
}


void Input(){
    cin >> R >> C >> M;
    int r,c,s,d,z;
    for(int i=0;i<M;i++){
        cin >> r >> c >> s >> d >> z;
        make_shark(r-1,c-1,s,d,z);
    }
}

void catch_shark(int col){
    for(int i=0;i<R;i++){
        if(map[i][col].size == 0) continue;
        ans += map[i][col].size;
        map[i][col] = {0,0,0};
        break;
    }
}

void move_shark(){
    int direction[5][2] = {{0,0},{-1,0},{1,0},{0,1},{0,-1}};
    shark after_move[max_rc][max_rc];
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(map[i][j].size == 0) continue;
            shark one = map[i][j];
            int x=i;int y=j;
            int distance = one.speed;
            if(one.dir == 1 || one.dir == 2) distance = distance % ((R-1)*2);
            else distance = distance % ((C-1)*2);
            while(distance>0){
                int newX = x+direction[one.dir][0];
                int newY = y+direction[one.dir][1];
                if(newX < 0 || newX >=R || newY <0 || newY >=C){
                    switch (one.dir)
                    {
                    case 1:
                        one.dir = 2;
                        break;
                    case 2:
                        one.dir = 1;
                        break;
                    case 3:
                        one.dir = 4;
                        break;
                    case 4:
                        one.dir = 3;
                        break;
                    default:
                        break;
                    }
                    newX = x+direction[one.dir][0];
                    newY = y+direction[one.dir][1];
                    x=newX; y=newY;
                    distance--;
                }
                else{
                    x=newX; y=newY;
                    distance--;
                }
            }

            if(after_move[x][y].size < one.size)
                after_move[x][y] = one;
        }
    }

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            map[i][j]=after_move[i][j];
        }
    }
}

void solve(){
    for(int i=0;i<C;i++){
        catch_shark(i);
        move_shark();
    }
    cout << ans;
}




int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Input();
    solve();
}