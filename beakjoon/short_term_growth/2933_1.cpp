/* 
 * baekjoon 2933
 * 
 * 미네랄
 * 
 * https://www.acmicpc.net/problem/2933
 * 
 * 
 * 반례 모음
 * https://www.acmicpc.net/board/view/51662
 * 
 * 
 * 메모리 초과가 발생하는 코드이다.
 * 
 */

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int r,c,n;
const int max_rcn = 101;
char map[max_rcn][max_rcn];
int order[max_rcn];
queue<pair<int,int>> q;

int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

void print_map(){
    for(int i=r;i>=1;i--){
        for(int j=1;j<=c;j++){
            cout << map[i][j];
        }
        cout << '\n';
    }

    return;
}

void Input(){
    cin >> r >> c;
    for(int i=r;i>=1;i--){
        for(int j=1;j<=c;j++){
            cin >> map[i][j];
        }
    }

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> order[i];
    }

    return;
}


void find_cluster(int x, int y){
    if(x<1 || y<1 || x>r || y>c) return;
    if(map[x][y]=='.') return;

    //cluster 가 떨어질 것인가
    bool flag=true;

    //q 초기화 (모든 좌표 기록을 위한 queue)
    while(!q.empty())   q.pop();

    //temp q 생성 (bfs를 위한 queue)
    queue<pair<int,int>> temp;

    //아래 과정이 수행되면 q에는 bfs로 탐색한 좌표들이 저장 되어있다.
    q.push({x,y});
    temp.push({x,y});
    while(!temp.empty()){
        int px = temp.front().first;
        int py = temp.front().second;
        map[px][py] = '.';
        temp.pop();

        for(int i=0;i<4;i++){
            int nx = px + dir[i][0];
            int ny = py + dir[i][1];
            if(nx<1 || ny<1 || nx>r || ny>c) continue;
            if(map[nx][ny]=='.') continue;

            if(nx == 1) flag = false;
            temp.push({nx,ny});
            q.push({nx,ny});
        }
    }


    int size = q.size();
    //이동이 필요 없는 경우 원래 map으로 돌린 뒤 종료
    if(flag == false) {
        for(int i=0;i<size;i++){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            map[x][y] = 'x';
        }
        return;
    }

    //이동이 필요한 경우
    int md = 0; //move_distance
    bool next_md=true;
    while(next_md){
        for(int i=0;i<size;i++){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            int next_h = x-md-1;
            if(next_h <=0 || map[next_h][y]=='x') {
                next_md = false;
            }
            q.push({x,y});
        }

        if(next_md) md ++;
    }

    for(int i=0;i<size;i++){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        map[x-md][y] = 'x';
    }

    return;
}


void shoot(int r, int left_right){
    int point;
    if(left_right % 2 == 1){
        for(int i=1;i<=c;i++){
            if(map[r][i]=='x'){
                point = i;
                map[r][i] = '.';
                break;
            }
        }
        //왼쪽에서 날아와서 부딪혔다 -> 오른쪽, 위, 아래 확인
        find_cluster(r,point+1);
        find_cluster(r+1,point);
        find_cluster(r-1,point);
    }
    else{
        for(int i=c;i>=1;i--){
            if(map[r][i]=='x'){
                point = i;
                map[r][i] = '.';
                break;
            }
        }
        //오른쪽에서 날아와서 부딪혔다 -> 왼쪽, 위, 아래 확인
        find_cluster(r,point-1);
        find_cluster(r+1,point);
        find_cluster(r-1,point);
    }
    return;
}

void solve(){
    for(int i=1;i<=n;i++){
        shoot(order[i],i);
    }
    print_map();
}


int main(){
    Input();
    solve();
    return 0;
}
