/* 
 * baekjoon 2667
 * 
 * 단지 번호 붙이기
 * 
 * https://www.acmicpc.net/problem/2667
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,cnt;
string mat[25];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

vector<int> ans;

bool visited[25][25]={false,};

void dfs(int x, int y){
    visited[x][y] = true;
    cnt++;
    for(int i=0;i<4;i++){
        int newX = x + dx[i];
        int newY = y + dy[i];

        if((0<=newX && newX < N) && (0 <=newY && newY < N)){
            if(mat[newX][newY]=='1' && !visited[newX][newY]){
                dfs(newX, newY);
            }
        }
    }
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> N;
    for(int i=0;i<N;i++) cin >> mat[i];
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(mat[i][j]=='1' && !visited[i][j]){
                cnt = 0;
                dfs(i,j);
                ans.push_back(cnt);
            }
        }
    }
    sort(ans.begin(),ans.end());

    cout << ans.size() << '\n';
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << '\n';
    }
    
    return 0;
}