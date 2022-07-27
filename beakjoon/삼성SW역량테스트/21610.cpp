/* 
 * baekjoon 21610
 * 
 * 마법사 상어와 비바라기
 * 
 * https://www.acmicpc.net/problem/21610
 * 
 */


#include <iostream>
#include <cstring>
using namespace std;

int N, M;
const int max_n = 51;
int map[max_n][max_n];
bool cloud[max_n][max_n];
int dir[9][2]={{0,0},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};
int moving_list[101][2];

void Input(){
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> map[i][j];
        }
    }

    int d,s;
    for(int i=0;i<M;i++){
        cin >> d >> s;
        moving_list[i][0] = d;
        moving_list[i][1] = s;
    }
}

void init_cloud(){
    memset(cloud, false, sizeof(cloud));
    cloud[N][1]=true;
    cloud[N][2]=true;
    cloud[N-1][1]=true;
    cloud[N-1][2]=true;
}

void move_cloud(int d, int s){
    int speed = s%N;
    bool copy_cloud[max_n][max_n];
    memset(copy_cloud,false, sizeof(copy_cloud));

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(cloud[i][j]){
                int nx, ny;
                nx = (i + dir[d][0]*speed+N)%N;
                ny = (j + dir[d][1]*speed+N)%N;
                if(nx == 0) nx = N;
                if(ny == 0) ny = N;
                copy_cloud[nx][ny]=true;
            }
        }
    }

    memcpy(cloud, copy_cloud, sizeof(cloud));
}

void rain(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(cloud[i][j]){
                map[i][j]++;
            }
        }
    }
}

void water_magic(){
    int plus_map[max_n][max_n];
    memset(plus_map,0,sizeof(plus_map));
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(!cloud[i][j]) continue;
            for(int k=2;k<=8;k+=2){
                int nx = i + dir[k][0];
                int ny = j + dir[k][1];
                if(nx < 1 || nx > N || ny < 1 || ny > N) continue;
                if(map[nx][ny]!=0) plus_map[i][j]++;
            }
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            map[i][j]+=plus_map[i][j];
        }
    }
}

void new_cloud(){
    bool new_cloud[max_n][max_n];
    memset(new_cloud, false, sizeof(new_cloud));
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(cloud[i][j] || map[i][j] <2) continue;
            new_cloud[i][j]=true;
            map[i][j]-=2;
        }
    }

    memcpy(cloud, new_cloud, sizeof(cloud));
}

void solve(){
    init_cloud();
    for(int i=0; i<M; i++){
        move_cloud(moving_list[i][0], moving_list[i][1]);
        rain();
        water_magic();
        new_cloud();
    }

    int ans=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            ans+=map[i][j];
        }
    }
    
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Input();
    solve();
    return 0;
}