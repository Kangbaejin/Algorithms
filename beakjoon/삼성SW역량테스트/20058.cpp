/* 
 * baekjoon 20058
 * 
 * 마법사 상어와 파이어스톰
 * 
 * https://www.acmicpc.net/problem/20058
 * 
 * 
 * 테두리는 녹는다!!!
 * 
 */

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N,Q,s;
const int max_n = 64;
int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int board[max_n][max_n], temp[max_n][max_n];
bool check_melt[max_n][max_n], visited[max_n][max_n];


void Input(){
    cin >> N >> Q;
    s = (1<<N);
    for(int i=0;i<s;i++){
        for(int j=0;j<s;j++){
            cin >> board[i][j];
        }
    }

}

// 격자 시계방향 회전
void rotate(int x, int y, int L){
    for(int i=0;i<L;i++)
        for(int j=0;j<L;j++)
            temp[i][j]=board[x+L-1-j][y+i];
    for(int i=0;i<L;i++)
        for(int j=0;j<L;j++)
            board[x+i][y+j]=temp[i][j];
}


int dfs(int x, int y){
    visited[x][y]=true;
    int ret = 1;
    for(int i=0;i<4;i++){
        int newx = x+dir[i][0];
        int newy = y+dir[i][1];

        if(newx<0 || newx>=s || newy<0 || newy>=s) continue;
        if(visited[newx][newy] || board[newx][newy]==0) continue;
        ret+=dfs(newx, newy);
    }
    return ret;
}


int biggest_ice(){
    int ret=0;
    for(int i=0;i<s;i++){
        for(int j=0;j<s;j++){
            if(board[i][j]>0 && !visited[i][j])
                ret = max(ret,dfs(i,j));
        }
    }
    return ret;
}

int sum_ice(){
    int ret=0;
    for(int i=0;i<s;i++){
        for(int j=0;j<s;j++){
            ret+=board[i][j];
        }
    }

    return ret;
}

void solve(int lq){
    lq = (1<<lq);

    for(int i=0;i<s;i+=lq)
        for(int j=0;j<s;j+=lq)
            rotate(i,j,lq);

    memset(check_melt,false,sizeof(check_melt));
    for(int i=0;i<s;i++){
        for(int j=0;j<s;j++){
            if(board[i][j]==0) continue;
            int cnt=0;
            for(int k=0;k<4;k++){
                int newx = i+dir[k][0];
                int newy = j+dir[k][1];
                if(newx<0 || newx>=s || newy<0 || newy>=s) continue;
                if(board[newx][newy]>0) cnt++;
            }
            if(cnt<3) check_melt[i][j]=true;
        }
    }
    
    for(int i=0;i<s;i++){
        for(int j=0;j<s;j++){
            if(check_melt[i][j])
                board[i][j]--;
        }
    }
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Input();

    while(Q--){
        int lq; cin >>lq;
        solve(lq);
    }

    cout << sum_ice() << '\n';
    cout << biggest_ice() << '\n';
    return 0;
}