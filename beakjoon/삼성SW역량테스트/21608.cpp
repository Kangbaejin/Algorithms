/* 
 * baekjoon 21608
 * 
 * 상어 초등학교
 * 
 * https://www.acmicpc.net/problem/21608
 * 
 */

#include <iostream>
#include <vector>
using namespace std;


int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int N, ans;
const int max_n = 21;
int map[max_n][max_n];
int prefer[max_n*max_n][4];
vector<int> order;

void Input(){
    cin >> N;
    for(int i=0;i<N*N;i++){
        int idx; cin >> idx;
        order.push_back(idx);
        for(int j=0;j<4;j++){
            cin >> prefer[idx][j];
        }
    }
}

bool out_range(int x, int y){
    return x<0 || x>=N || y<0 || y>=N;
}

void print_map(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int num_prefer(int s, int x, int y){
    int cnt=0;
    for(int i=0;i<4;i++){
        int nx = x+dir[i][0];
        int ny = y+dir[i][1];
        if(out_range(nx,ny)) continue;
        for(int j=0;j<4;j++){
            if(map[nx][ny]==prefer[s][j]) cnt++;
        }
    }

    return cnt;
}

int num_blank(int x, int y){
    int cnt=0;
    for(int i=0;i<4;i++){
        int nx = x+dir[i][0];
        int ny = y+dir[i][1];
        if(out_range(nx,ny)) continue;
        for(int j=0;j<4;j++){
            if(map[nx][ny]==0) cnt++;
        }
    }

    return cnt;
}

void seat(int s){
    int max_cnt=0;
    vector<pair<int,int>> v;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(map[i][j]!=0) continue;
            int value = num_prefer(s,i,j);
            if(max_cnt<value){
                max_cnt = value;
                v.clear();
                v.push_back({i,j});
            }
            if(max_cnt==value){
                v.push_back({i,j});
            }
        }
    }

    if(v.size()==1){
        map[v[0].first][v[0].second]=s;
        return;
    }

    //열 행 순서로 탐색했으니 벡터에도 그 순서대로 들어있다.
    int max_blank_cnt=-1;
    int x, y;

    for(int i=0;i<v.size();i++){
        int temp_x=v[i].first;
        int temp_y=v[i].second;
        if(map[temp_x][temp_y]!=0) continue;
        int value = num_blank(temp_x,temp_y);
        if(max_blank_cnt<value){
            max_blank_cnt = value;
            x=temp_x;
            y=temp_y;
        }
    }
    map[x][y]=s;
}


void score(int max_cnt){
    switch (max_cnt){
        case 1:
            ans+=1;
            break;
        case 2:
            ans+=10;
            break;
        case 3:
            ans+=100;
            break;
        case 4:
            ans+=1000;
            break;
        default:
            break;
    }
}

void solve(){
    for(int i=0;i<order.size();i++){
        int s = order[i];
        seat(s);
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int value = num_prefer(map[i][j],i,j);
            score(value);
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