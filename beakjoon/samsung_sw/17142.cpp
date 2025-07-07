/* 
 * baekjoon 17142
 * 
 * 연구소 3
 * 
 * https://www.acmicpc.net/problem/17142
 * 
 * 
 */


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>


using namespace std;


int N,M, ans=-1;
const int max_n = 50;
int map[max_n][max_n];
int original_map[max_n][max_n];
vector<pair<int,int>> virus_vector;
int num_virus;

void Input(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> original_map[i][j];
            if(original_map[i][j]==2) virus_vector.push_back({i,j});
        }
    }
    num_virus = virus_vector.size();
    memcpy(map,original_map, sizeof(int)*max_n*max_n);

}

int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
void BFS(int ix, int iy){
    queue<pair<int,int>> q;
    int x = ix, y = iy;
    q.push({x,y});
    map[x][y]=0;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int newX = x+dir[i][0];
            int newY = y+dir[i][1];
            //범위를 벗어나는 경우
            if(newX<0 || newX>=N || newY<0 || newY>=N) continue;
            //다음 좌표가 벽인 경우 제거
            if(original_map[newX][newY]==1) continue;
            
            //여기까지 왔다면, 벽이 아니고 빈칸이다.
            //0 인 경우는 한번도 방문 되지 않은 경우
            if(map[newX][newY] == 0){
                map[newX][newY] = map[x][y]+1;
                q.push({newX,newY});
            }
            //0 이 아닌 경우 중, 기존의 값보다 짧은 경로라면 업데이트한다.
            else if(map[newX][newY]>map[x][y]+1){
                map[newX][newY] = map[x][y]+1;
                q.push({newX,newY});
            }
        }
    }
}

vector<pair<int,int>> chosen;
vector<bool> visited;

void DFS(int depth, int idx){
    if(depth>M) return;
    if(depth==M){
        //DFS 탐색 마무리에서 BFS 시작으로 넘어갈 때
        //변화하는 map 값에 대해서 초기화를 진행한다.
        memset(map, 0, sizeof(int)*max_n*max_n);
        for(int i=0; i<M; i++){
            int x = chosen[i].first;
            int y = chosen[i].second;
            BFS(x,y);
        }


        //original_map 에서 0이었던 곳이 map에서도 0이 라면
        //해당 좌표가 바이러스에 전파되지 않은 지역이라는 뜻이다.
        int temp_max=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(original_map[i][j]==0){
                    if(map[i][j]==0)    return;
                    else{
                        temp_max = max(temp_max,map[i][j]);
                    }
                }
            }
        }

        //모든 경우 빈칸이 남아있다면,아래의 코드로 넘어오지 않았을 것이고,
        //그러면 ans 는 초기값 그대로 -1 일 것이다.
        if(ans==-1) ans = temp_max;
        else ans = min(ans, temp_max);

        return;
    }

    for(int i=idx; i<num_virus; i++){
        if(visited[i]) continue;
        visited[i]=true;

        int x=virus_vector[i].first;
        int y=virus_vector[i].second;
        chosen.push_back({x,y});

        DFS(depth+1, ++idx);
        visited[i]=false;
        chosen.pop_back();
    }
}

void solve(){
    for(int i=0;i<num_virus;i++) visited.push_back(false);
    DFS(0,0);
    cout << ans;
}



int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Input();
    solve();
    return 0;
}
