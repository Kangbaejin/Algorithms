/* 
 * baekjoon 14500
 * 
 * 테트로미노
 * 
 * https://www.acmicpc.net/problem/14500
 * 
 * 
 * 구현 계획

 * '''
 * 첫 모양에 대한 형태를 좌표로 표시 후, 해당 좌표가 범위를 벗어난다면 체크하지 않고,
 * 첫 모양에 대한 좌표를 벗어나기 전까지 열 방향으로 한칸씩 이동시키고, 벗어난다면 이를 행을 한칸 증가시켜서 진행
 * '''
 * 
 * 
 * 구현하는 도중, 해당 모양들이 모두 depth = 3 인 dfs 알고리즘의 형태라는 느낌이 왔다.
 * 그런데 ㅜ 모양은 그렇지 않았다.
 * 
 * ㅜ 모양에 대해서는 확인하는 다른 함수를 ''' ''' 안에 있는 부분의 논리로 구현하여 진행하였다.
 * 
 */


#include <iostream>
#include <cstring>
#include <vector>
#define max_map 500
using namespace std;

int N,M, ans;
int map[max_map][max_map];
bool visited[max_map][max_map];
int dir_x[4] = {0,0,1,-1};
int dir_y[4] = {1,-1,0,0};

void Input(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
        }
    }
}

void dfs(int x, int y, int sum, int depth){
    visited[x][y] = true;

    if(depth==3){
        if(ans < sum) ans = sum;
        return;
    }


    for(int i=0;i<4;i++){
        int newx = x+dir_x[i];
        int newy = y+dir_y[i];
        if(newx < 0 || newx >= N || newy < 0 || newy >= M) continue;
        if(visited[newx][newy]) continue;

        dfs(newx,newy,sum+map[newx][newy],depth+1);
        visited[newx][newy]=false;
    }
}

void check_T_shape(){
    
    //필요한 x 의 갯수는 4개 | 가능한 모양이 4개
    //각 shape 별로 x,y 변위 담아서 사용
    vector<pair<int, int>> v[4];
    // ㅗ ㅜ ㅓ ㅏ 순서
    v[0] = {{0,0},{0,1},{0,2},{-1,1}};
    v[1] = {{0,0},{0,1},{0,2},{1,1}};
    v[2] = {{0,0},{1,0},{1,-1},{2,0}};
    v[3] = {{0,0},{1,0},{1,1},{2,0}};
    for(int a=0;a<4;a++){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                int T_sum=0;
                int newx[4] = {i+v[a][0].first, i+v[a][1].first, i+v[a][2].first, i+v[a][3].first};
                int newy[4] = {j+v[a][0].second, j+v[a][1].second, j+v[a][2].second, j+v[a][3].second};
                
                bool check = true;
                for(int k=0;k<4;k++){
                    if(newx[k]<0 || newx[k]>=N || newy[k]<0 || newy[k] >= M){
                        check = false;
                    }
                }
                
                if(check){
                    for(int k=0;k<4;k++){
                        T_sum+=map[newx[k]][newy[k]];
                    }
                    
                    if(T_sum > ans) ans = T_sum;
                }

            }
        }
    }
    return;
}



void solve(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            memset(visited, false, sizeof(visited));
            dfs(i,j,map[i][j],0);
        }
    }
    check_T_shape();

    cout << ans;
}


int main(){
    Input();
    solve();
    return 0;
    
}