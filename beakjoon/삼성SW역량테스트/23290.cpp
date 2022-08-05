/* 
 * baekjoon 23290
 * 
 * 마법사 상어와 복제
 * 
 * https://www.acmicpc.net/problem/23290
 * 
 */
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct shark{
    int x,y;
};

shark shk;

int M,S;
int map[5][5];
vector<int> fish_map[5][5];

int dir[9][2]={{0,0},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};

void Input(){
    cin >> M >> S;
    int x,y,d;
    for(int i=0; i<M; i++){
        cin >> x >> y >> d;
        fish_map[x][y].push_back(d);
    }

    cin >> shk.x >> shk.y;
}

void move_fish(){    
    vector<int> move_fish_map[5][5];
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            for(int k=0;k<fish_map[i][j].size();k++){
                int cur_dir = fish_map[i][j][k];
                int cnt = 8;
                while(cnt--){
                    int nx=i+dir[cur_dir][0];
                    int ny=j+dir[cur_dir][1];
                    //범위 벗어나거나, 냄새가 남아있거나, 상어 위치라면 방향 바꾼다.
                    if((nx < 1 || nx > 4 || ny < 1 || ny > 4) || 
                       (map[nx][ny]>0)   || (nx == shk.x && ny == shk.y)){
                        cur_dir--;
                        if(cur_dir==0) cur_dir = 8;
                    }
                    else{
                        move_fish_map[nx][ny].push_back(cur_dir);
                        break;
                    }
                }
                //한바퀴 다 돌아도 없는 경우 그대로 넣는다.
                if(cnt<0){
                    move_fish_map[i][j].push_back(fish_map[i][j][k]);
                }
            }
        }
    }


    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            fish_map[i][j] = move_fish_map[i][j];
        }
    }
}

int dfs_max=0;
int dfs_temp[3];
int dfs_ans[3];
int dfs_dir[5][2] = {{0,0},{-1,0},{0,-1},{1,0},{0,1}};
bool dfs_visited[5][5];
void dfs(int x, int y, int sum, int cnt){
    if(cnt==3){
        if(dfs_max < sum){
            dfs_max = sum;
            memcpy(dfs_ans, dfs_temp, sizeof(dfs_temp));
        }
        return;
    }

    for(int i=1;i<=4;i++){
        int nx = x+dfs_dir[i][0];
        int ny = y+dfs_dir[i][1];
        if(nx < 1 || nx > 4 || ny < 1 || ny > 4) continue;
        dfs_temp[cnt] = i;
        int num_fish = fish_map[nx][ny].size();
        if(dfs_visited[nx][ny]){
            dfs(nx,ny,sum,cnt+1);
        }
        else{
            dfs_visited[nx][ny] = true;
            dfs(nx,ny,sum+num_fish,cnt+1);
            dfs_visited[nx][ny] = false;
        }
    }

}

void move_shark(){
    //dfs 전 초기화 과정
    dfs_max = -1;
    for(int i=0;i<3;i++) {
        dfs_ans[i]=1;
        dfs_temp[i]=1;
    }
    memset(dfs_visited,false,sizeof(dfs_visited));

    dfs(shk.x,shk.y,0,0);

    //dfs 이후에는 dfs_ans 에 사전순으로 빠르며 가장 많은 물고기를 잡는경로가 저장됨
    int nx = shk.x;
    int ny = shk.y;
    for(int i=0;i<3;i++){
        nx+=dfs_dir[dfs_ans[i]][0];
        ny+=dfs_dir[dfs_ans[i]][1];
        if(fish_map[nx][ny].size()!=0){
            fish_map[nx][ny].clear();
            //냄새
            map[nx][ny] = 3;
        }
    }
    shk.x = nx;
    shk.y = ny;
}

void one_cycle(){
    vector<int> copy_fish_map[5][5];
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            copy_fish_map[i][j] = fish_map[i][j];
        }
    }
    move_fish();
    move_shark();
    //냄새 1 감소
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            if(map[i][j]>0) map[i][j]--;
        }
    }
    //복제
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            for(int k=0;k<copy_fish_map[i][j].size();k++){
                fish_map[i][j].push_back(copy_fish_map[i][j][k]);
            }
        }
    }
}

void solve(){
    while(S--){
        one_cycle();
    }
    int ans = 0;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            ans += fish_map[i][j].size();
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