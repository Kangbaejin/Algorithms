/* 
 * baekjoon 21609
 * 
 * 상어 중학교
 * 
 * https://www.acmicpc.net/problem/21609
 * 
 */
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

//빈칸을 0으로 나타내기 위해
//검은색 블록은 -1, 무지개 블록은 -2 로 표현
const int max_n = 22;
int map[max_n][max_n];
bool visited[max_n][max_n];
int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

int N,M, ans;
struct value_row{
    int value,row;
};

void Input(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
            if(map[i][j]==0) map[i][j]=-2;
        }
    }
}

void rotate() {
	int temp[max_n][max_n];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[i][j] = map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = temp[j][N-1-i];
		}
	}
}

void gravity(){
    for(int j=0;j<N;j++){
        vector<value_row> v;
        for(int i=N-1; i>=0; i--){
            if(map[i][j]!=0){
                v.push_back({map[i][j],i});
            }
            map[i][j]=0;
        }
        int idx = N-1;
        for(int i=0; i<v.size(); i++){
            if(v[i].value == -1){
                idx = v[i].row;
                map[idx][j]=v[i].value;
                idx--;
            }
            else{
                map[idx][j]=v[i].value;
                idx--;
            }
        }
    }
}

int bfs(int ix, int iy, int& num_rainbow){
    visited[ix][iy]=true;
    int value = map[ix][iy];
    int ret=1;
    map[ix][iy]=0;
    queue<pair<int,int>> q;
    q.push({ix,iy});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x+dir[i][0];
            int ny = y+dir[i][1];
            if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
            if(visited[nx][ny] || map[nx][ny]==-1) continue;
            if(map[nx][ny]==value || map[nx][ny]==-2){
                if(map[nx][ny]==-2) num_rainbow++;
                ret++;
                map[nx][ny] = 0;
                visited[nx][ny]=true;
                q.push({nx,ny});
            }
        }
    }
    return ret;
}


bool one_cycle(){
    int max_num_rainbow = -1;
    int max_num=0;
    int tx=0, ty=0;
    int copy_map[max_n][max_n];
    int num_rainbow;
    //무지개 좌표 저장
    vector<pair<int,int>> rainbow_v;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            copy_map[i][j] = map[i][j];
            if(map[i][j]==-2) rainbow_v.push_back({i,j});
        }
    }
    //방문 노드 초기화
    memset(visited, false, sizeof(visited));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            //무지개 좌표들에 대해서 visited와 map 복구 (다른 그룹에서도 방문할 수 있도록)
            for(int k=0;k<rainbow_v.size();k++){
                visited[rainbow_v[k].first][rainbow_v[k].second] = false;
                map[rainbow_v[k].first][rainbow_v[k].second]= -2;
            }
            //현재 좌표가 이미 검정, 빈칸, 방문 된 칸 이라면 continue
            //시작 좌표는 무지개가 될 수 없다. (그룹엔 최소 하나의 색깔 블록있어야함)
            if(map[i][j]==-1 || map[i][j] == 0 || visited[i][j] || map[i][j]==-2) continue;
            num_rainbow=0;
            int cur_num = bfs(i,j,num_rainbow);
            if(max_num<cur_num){
                tx=i; ty=j; 
                max_num_rainbow = num_rainbow;
                max_num = cur_num;
            }
            if(max_num==cur_num){
                if(max_num_rainbow<=num_rainbow){
                    tx=i; ty=j;
                    max_num_rainbow = num_rainbow;
                }
            }
        }
    }

    if(max_num<=1) return false;

    memset(visited, false, sizeof(visited));
    memcpy(map, copy_map, sizeof(map));
    bfs(tx,ty,num_rainbow);

    ans+=max_num*max_num;

    gravity();
    rotate();
    gravity();

    return true;
}

void solve(){
    while(one_cycle()){
    }
    cout << ans;
    return;
}

int main(){
    Input();
    solve();
    return 0;
}