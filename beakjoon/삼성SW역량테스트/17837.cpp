/* 
 * baekjoon 17837
 * 
 * 새로운 게임 2
 * 
 * https://www.acmicpc.net/problem/17837
 * 
 * 
 * 
 * 주의점
 * 1)
 * 1턴안에서 말이 한번 움직일 때마다 체크하며 높이가 4가 넘었을 경우 턴을 반환.
 * 왜냐하면, 1턴이 다 실행 된 뒤에 높이를 체크하게 된다면,
 * 1턴 안에서 높이가 4가 넘었다가 이동하면서 다시 높이가 4 미만으로 변경되었을 수 도 있으므로,
 * 매 움직임(말 하나 하나) 마다 체크를 해야한다.
 * 
 * 2)
 * 파란색으로 인해 방향이 바뀐 다음 블럭의 색을 고려하여 진행해야한다.
 * 
 * 
 * 
 * 
 * 전체적인 구현 계획과 구현은 매우 비슷했으나, move 함수를 구현하는 과정이 훨씬 깔끔해서 보고 반영하게 되었다.
 * 배열을 벗어나는 경우와, 파란색 이후 새로운 블럭을 처리함에 있어 재귀적인 함수를 이용하여 표현하면,
 * 
 * 내가 작성했던 if else 문의 지옥에서 벗어날 수 있었다.
 * 
 * https://yabmoons.tistory.com/304
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>

#define N_MAX 13
#define K_MAX 11
using namespace std;

struct stone {
    int x;
    int y;
    int dir;
};

//map[i][j] 위치의 말들을 기록하기위해 vector 생성

vector<int> map[N_MAX][N_MAX];
int map_check[N_MAX][N_MAX];
stone list[K_MAX];
// →, ←, ↑, ↓
int Dir[5][2] = {{0,0},{0,1},{0,-1},{-1,0},{1,0}};

int N,K;


void Print(){
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            cout << map[i][j].size() << " ";
        }
        cout << endl;
    }
    cout << "#######################################################################" << endl;
}

bool checking(){
    for(int i=1;i<=K;i++){
        int x = list[i].x;
        int y = list[i].y;
        if(map[x][y].size()>=4)  return true;
    }
    return false;
}

void moving(int x, int y, int nx, int ny, int Num, int pos, int state){
    if(state == 0){
        for(int i=pos;i<map[x][y].size();i++){
            map[nx][ny].push_back(map[x][y][i]);
            list[map[x][y][i]].x = nx;
            list[map[x][y][i]].y = ny;
        }
        int del_num = map[x][y].size()-pos;
        while(del_num--){
            map[x][y].pop_back();
        }
    }
    else if(state == 1){
        for(int i=map[x][y].size()-1;i>=pos;i--){
            map[nx][ny].push_back(map[x][y][i]);
            list[map[x][y][i]].x = nx;
            list[map[x][y][i]].y = ny;
        }
        int del_num = map[x][y].size()-pos;
        while(del_num--){
            map[x][y].pop_back();
        }
    }
    else if(state == 2){
        int d = list[Num].dir;

        if(d==1) d=2;
        else if(d==2) d=1;
        else if(d==3) d=4;
        else d = 3;

        list[Num].dir = d;
        int nnx = x + Dir[d][0];
        int nny = y + Dir[d][1];
        if (nnx >= 1 && nny >= 1 && nnx <= N && nny <= N){
            if (map_check[nnx][nny] != 2) moving(x, y, nnx, nny, Num, pos, map_check[nnx][nny]);
        }
    }
}

void solve(){
    bool flag = false;
    int cnt = 0;
    while(cnt <= 1000){
        cnt++;
        for(int i=1; i<=K;i++){
            int x = list[i].x;
            int y = list[i].y;
            int d = list[i].dir;

            int nx = x + Dir[d][0];
            int ny = y + Dir[d][1];

            int pos = find(map[x][y].begin(), map[x][y].end(), i) - map[x][y].begin();
            if(nx>=1 && ny>=1 && nx<=N && ny<=N) moving(x,y,nx,ny,i,pos,map_check[nx][ny]);
            else moving(x,y,nx,ny,i,pos,2);

            if(checking() == true){
                flag = true;
                break;
            }

        }
        if(flag == true) break;
    }
    if(flag == true) cout << cnt;
    else cout << -1;
    return;
}


void v_input(){
    cin >> N >> K;
    int temp;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> temp;
            map_check[i][j] = temp;
        }
    }

    for(int i=1; i<=K; i++){
        int ix, iy, id;
        cin >> ix >> iy >> id;
        list[i] = {ix, iy, id};

        map[ix][iy].push_back(i);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    v_input();

    solve();

    return 0;
    
}