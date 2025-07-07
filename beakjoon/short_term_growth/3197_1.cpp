/* 
 * baekjoon 3197
 * 
 * 백조의 호수
 * 
 * https://www.acmicpc.net/problem/3197
 * 
 * 
 * 입력 받는 char
 * . -> 물
 * X -> 얼음
 * L -> 백조
 * 
 * 백조가 있는 위치는 물이다. 
 * 
 * 1) 얼음 기록
 * 얼음을 queue 에 기록한다.
 * queue에 적힌 얼음들을 탐색하며 테두리가 물과 맞닿지 않은 얼음을 next_ice_q 에 기록한다.
 * 물과 맞닿지 않은 얼음은 다음 날짜에 남아있을 얼음을 의미한다.
 * 
 * 지도를 업데이트 하며,
 * ice_q = next_ice_q 를 수행해서 다음 날짜의 얼음을 표시한다.
 * 
 * 2) 백조가 갈 수 있는 길 기록
 * 백조가 갈수 있는 길은 지도에 L 로 표시한다.
 * 초기 입력시 두개의 L을 입력받는다. 
 * 둘 중 하나 (먼저 입력받은)의 좌표의 값은 L로 표시하고, 다른 좌표의 값은 얼음으로 표시한다. (이때 좌표는 기록)
 * 
 * 백조가 BFS형태로 L인 부분과 X인 부분 (이미 방문 했던 부분과 얼음인 부분)은 방문하지 않도록
 * 설정하여 탐색한다.
 * 
 * 탐색 후 위에서 기록했던 도착지의 좌표가 L로 바뀌었다면 두 백조가 만날 수 있는 길이 만들어진 것이므로
 * 반복을 종료하며 날짜를 출력한다.
 * 
 * 
 */

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int r,c;
const int max_rc = 1501;
char map[max_rc][max_rc];

pair<int,int> swans[2];
queue<pair<int,int>> ice_q, s, next_ice_q, next_s;
void print_map(){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout << map[i][j];
        }
        cout << "\n";
    }   
    cout << "\n";
}


void Input(){
    cin >> r >> c;
    char temp;
    int swan_cnt = 0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> temp;
            if(temp == 'L'){
                swans[swan_cnt].first = i;
                swans[swan_cnt].second = j;
                swan_cnt ++;
                map[i][j]='.';
            }
            else if(temp == '.') map[i][j]=temp;
            else if(temp == 'X'){
                map[i][j]=temp;
                ice_q.push({i,j});
            }
        }
    }
    s.push({swans[0].first, swans[0].second});
    
}

int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
bool check_melting(int x, int y){
    bool flag = false;
    for(int i=0;i<4;i++){
        int nx = x+dir[i][0];
        int ny = y+dir[i][1];
        if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
        // 4방향 중 하나라도 물이라면 flag 는 true가 된다.
        if(map[nx][ny] != 'X') flag = true;
    }

    return flag;
}


void melting_ice(){
    while(!ice_q.empty()){
        int x = ice_q.front().first;
        int y = ice_q.front().second;
        // cout << x << " " << y << "\n";
        ice_q.pop();
        //녹지 않은 얼음들은 next_ice_q 에 저장
        if(!check_melting(x,y)){
            next_ice_q.push({x,y});
        }
    }
    memset(map,'.',sizeof(map));
    while(!next_ice_q.empty()){
        int x = next_ice_q.front().first;
        int y = next_ice_q.front().second;
        next_ice_q.pop();
        map[x][y] = 'X';
        ice_q.push({x,y});
    }
    
}


/*
 * 한번 다녀간 길은 L로 표시한다. 곧 녹을 얼음은 next_ice_q 를 통해 관리하므로,
 * 추가 탐색할 칸은 next_s로 관리한다.
 */

bool is_way(){
    while(!s.empty()){
        int x = s.front().first;
        int y = s.front().second;
        map[x][y]='L';
        s.pop();
        for(int i=0;i<4;i++){
            int nx = x+dir[i][0];
            int ny = y+dir[i][1];
            if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            if(map[nx][ny]=='X'){
                next_s.push({nx,ny});
                continue;
            }
            if(map[nx][ny] == 'L') continue;
            
            s.push({nx,ny});
        }
    }
    
    s = next_s;
    int end_x = swans[1].first;
    int end_y = swans[1].second;
    if(map[end_x][end_y]=='L') return true;
    else return false;
}


void solve(){
    int day = 0;
    while(!is_way()){
        melting_ice();
        day++;
    }
    cout << day;
}

int main(){
    ios_base::sync_with_stdio(0);   
    cin.tie(0);
    Input();
    solve();
    return 0;
}