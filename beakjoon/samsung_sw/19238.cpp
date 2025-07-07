/* 
 * baekjoon 19238
 * 
 * 스타트 택시
 * 
 * https://www.acmicpc.net/problem/19238
 * 
 * 거리가 같은 경우 처리는 행이 작은 순서, 열이 작은 순서로 방문하도록 해야한다.
 * 해당 조건 만족을 위해 승객을 행과 열 순서로 sort한 뒤
 * search 할 때 값이 클 때만 업데이트 하도록 구현했다.
 * 이렇게 할 경우 값이 같은 거리 중에서 가장 행과 열에 대해 조건에 부합하도록 탐색할 수 있다.
 * 
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int max_n = 23;

int taxi_x, taxi_y;
int N,M,fuel;
int map[max_n][max_n];
int BFS_map[max_n][max_n];

int num_using_taxi=0;

/*
 * 승객의 처음 위치 x, y 가고자 하는 위치 x, y 를 입력한다.
 * 마지막 인자는 이용했는지 여부 기록을 위한 값이다.
 * 
 * 자세히 설명하면 아래와 같다.
 * start_end[0][1] : 0번 승객의 출발지 x 좌표
 * start_end[0][2] : 0번 승객의 출발지 y 좌표
 * start_end[0][3] : 0번 승객의 도착지 x 좌표
 * start_end[0][4] : 0번 승객의 도착지 y 좌표
 * start_end[0][5] : 0번 승객의 택시 이용 여부
 */
vector<vector<int>> start_end;

int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

bool cmp(vector<int> a, vector<int> b){
    if(a[0]==b[0]) return a[1] < b[1];
    return a[0]<b[0];
}   

void Input(){
    cin >> N >> M >> fuel;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> map[i][j];
        }
    }

    cin >> taxi_x >> taxi_y;

    for(int i=0;i<M;i++){
        vector<int> temp_v;
        int temp;
        for(int j=0;j<4;j++){
            cin >> temp;
            temp_v.push_back(temp);
        }
        temp_v.push_back(0);
        start_end.push_back(temp_v);
    }

    sort(start_end.begin(), start_end.end(), cmp);
}

void BFS(int ix, int iy){
    //BFS 를 통해 1씩 증가시키며 BFS_map에 거리를 저장할 것이므로 벽을 -1로 표시
    bool visited[max_n][max_n];
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            BFS_map[i][j] = map[i][j]*(-1);
            visited[i][j] = false;
        }
    }
    queue <pair<int,int>> q;
    visited[ix][iy]=true;
    q.push({ix,iy});

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int newX= x+dir[i][0];
            int newY= y+dir[i][1];
            if(newX<1 || newX>N || newY<1 || newY>N) continue;
            if(BFS_map[newX][newY]==-1) continue;
            if(visited[newX][newY]==false){
                visited[newX][newY]=true;
                BFS_map[newX][newY]=BFS_map[x][y]+1;
                q.push({newX,newY});
            }
        }
    }
}

void search(){
    //현재 택시 위치에서 각 승객까지의 거리를 구하기 위해 BFS를 수행하여 거리를 구한다.
    BFS(taxi_x, taxi_y);
    int short_idx=0;
    int short_path=500;
    for(int i=0;i<M;i++){
        if(start_end[i][4]==1) continue;
        if(short_path > BFS_map[start_end[i][0]][start_end[i][1]]){
            short_path = BFS_map[start_end[i][0]][start_end[i][1]];
            short_idx = i;
        }
    }

    //출발지로 이동할 거리가 0 일때 (2가지 경우 발생)
    //1. 현재 택시 위치에서 갈 수 없는 출발지 인 경우 (BFS 탐색시 방문되지 않아 0이다.) -> 종료
    //2. 현재 택시 위치가 출발지인 경우 -> 통과
    if(short_path==0) {
        //벽에 막혀 이동할 수 없는 출발지일 경우
        if(!(start_end[short_idx][0]==taxi_x &&
             start_end[short_idx][1]==taxi_y)) return;
    }

    //그 승객을 데리러갈 연료가 없을 때
    if(short_path>fuel) return;

    //승객을 태운 지점에서 BFS를 통해 거리를 구한다.
    BFS(start_end[short_idx][0],start_end[short_idx][1]);
    int delivery_distance = BFS_map[start_end[short_idx][2]][start_end[short_idx][3]];

    //도착지로 이동할 거리가 0 일때 (2가지 경우 발생)
    //1. 현재 택시 위치에서 갈 수 없는 도착지 인 경우 (BFS 탐색시 방문되지 않아 0이다.) -> 종료
    //2. 현재 택시 위치가 도착지인 경우 -> 통과
    if(delivery_distance==0) {
        //벽에 막혀 이동할 수 없는 도착지 일 경우
        if(!(start_end[short_idx][0]==start_end[short_idx][2] &&
             start_end[short_idx][1]==start_end[short_idx][3])) return;
    }

    //이동할 연료가 충분한 경우
    if(fuel >= short_path + delivery_distance){
        //택시의 현재 좌표를 도착지로 업데이트
        taxi_x = start_end[short_idx][2];
        taxi_y = start_end[short_idx][3];

        //연료 업데이트
        fuel = fuel-short_path-delivery_distance + delivery_distance*2;

        //택시 사용자 정보 업데이트
        num_using_taxi++;
        start_end[short_idx][4]=1;

        //택시 사용자가 M보다 작을 경우 새로운 search 진행
        if(num_using_taxi<M) search();
    }

    return;
}

void solve(){
    search();
    if(num_using_taxi==M) cout << fuel;
    else cout << -1;
}



int main(){
    Input();
    solve();
    return 0;
}