/* 
 * baekjoon 16236
 * 
 * 아기 상어
 * 
 * https://www.acmicpc.net/problem/16236
 * 
 * 
 * 구현 계획
 * 
 */


#include <iostream>
#include <algorithm>
#include <queue>

#define max_size 20
#define abs(a) ((a>0) ?  (a) : -(a))
using namespace std;




struct shark{
    int size;
    int fishes_count;
    int x;
    int y;
};


int map[max_size][max_size];
int N, ans;
shark shk;




void Input(){
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
            if(map[i][j] == 9){
                shk.x = i;
                shk.y = j;
                shk.size = 2;
                shk.fishes_count = 0;
            }
        }
    }
}

//point_and_distance
struct pad{
    int x, y, distance;
};


struct cmp {
    bool operator()(pad a, pad b) {
        if(a.distance == b.distance){
            if(a.x == b.x){
                return a.y > b.y;
            }
            else{
                return a.x > b.x;
            }
        }
        else{
            return a.distance > b.distance;
        }
    }
};

//크기가 같거나 작은 물고기가 있는 칸만 이동할 수 있으므로 그에 맞도록 최단 거리 구하는 함수. 길이 없다면 -1 리턴, 있다면 길의 최단 길이 리턴
int short_path(int start_x, int start_y, int end_x, int end_y){
    int dist[max_size][max_size] = {0,};
    bool visited[max_size][max_size] = {false,};
    queue<pair<int,int>> q;
    q.push({start_x, start_y});
    visited[start_x][start_y] = true;
    

    int dir_x[4] = {0,0,1,-1};
    int dir_y[4] = {1,-1,0,0};

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int newx = x+dir_x[i];
            int newy = y+dir_y[i];
            if(shk.size < map[newx][newy] || newx<0 || newx>=N || newy<0 || newy>=N || visited[newx][newy]) continue;
            q.push({newx, newy});
            visited[newx][newy] = true;
            dist[newx][newy] = dist[x][y] + 1;
        }
    }

    if(!visited[end_x][end_y]) return -1;
    else return dist[end_x][end_y];
}



void BFS(int x, int y){
    queue<pair<int, int>> q;
    q.push({x,y});
    while(!q.empty()){
        priority_queue<pad, vector<pad>, cmp> pq;
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(map[i][j]==0 || map[i][j]==9) continue;
                else if(map[i][j]<shk.size){
                    int d = short_path(cur_x,cur_y, i,j);
                    //현재 위치에서 해당 i,j 위치로 이동이 불가능 한 경우
                    if(d == -1) continue;
                    pad temp;
                    temp.x = i; temp.y = j; temp.distance = d;
                    pq.push(temp);
                }
            }
        }
        //현재 BFS 로 탐색하고 있는 좌표에서 다음 먹을 수 있는 물고기를 next 로 가져왔다. (주어진 조건의 순서로)
        //이 때 이 pq 가 비어있다는 것은, 현재 이동한 좌표에서 먹을 수 있는 물고기가 없다는 것을 의미하므로 break
        if(pq.empty()) break;

        //위의 이중 for 문에서 map == 0 인 경우는 continue 처리를 했기 때문에 pq 에는 0과 같은 값이 들어갈 수 없다.
        //visited 배열을 이용하는 것과 동일하다. 0 이면 방문할 수 없거나 이미 방문한 것과 같은 경우이므로 
        pad next = pq.top();
        int new_x = next.x;
        int new_y = next.y;

        
        //현재의 좌표는 빈칸으로 바꾸고 이동할 칸은 상어로 채운다.
        map[cur_x][cur_y] = 0;
        map[new_x][new_y] = 9;

        //상어가 먹은 물고기 수를 증가시킨다.
        shk.fishes_count++;

        //상어가 먹은 물고기 수가 물고기의 사이즈와 같다면 사이즈를 증가시킨다. 먹은 물고기수 역시 초기화
        if(shk.fishes_count == shk.size){
            shk.size++;
            shk.fishes_count = 0;
        }

        //조건을 만족하는 가장 가까운 물고기 만큼의 거리만큼 이동해야 하므로 이동하는 거리 만큼을 답에 더해준다.
        //cout << "cur_x, cur_y, cur_size, new_x, new_y : "<< cur_x << " " << cur_y << " " << shk.size << " " <<new_x << " " << new_y << '\n';
        ans+= next.distance;

        //새로운 좌표를 q 에 입력한다.
        q.push({new_x, new_y});
    }

    return;
}


int main(){
    Input();

    BFS(shk.x, shk.y);

    cout << ans;


    return 0;
}