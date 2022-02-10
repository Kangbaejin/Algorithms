/* 
 * baekjoon 7569
 * 
 * 토마토_2
 * 
 * https://www.acmicpc.net/problem/7569
 * 
 * 
 */
#include <cstdio>
#include <queue>
#define MAX 101

using namespace std;

int value[MAX][MAX][MAX] = {0,};
int dir[6][3] = {{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};

queue<pair<pair<int, int>,int>> q;

int M,N,H;

int bfs(void){
	while(!q.empty()){
        int y = q.front().first.first;
        int x = q.front().first.second;
        int z = q.front().second;
		q.pop();

		for(int i=0; i<6; i++){
            int newX = x + dir[i][0];
			int newY = y + dir[i][1];
            int newZ = z + dir[i][2];
            //배열 벗어나면 continue 처리
			if(newX<0 || newX>=M || newY<0 || newY>=N || newZ<0 || newZ>= H) continue;

            //새로운 좌표가 안익은 토마토일 때
            if(value[newZ][newY][newX] == 0){
                value[newZ][newY][newX] = value[z][y][x] + 1;
                q.push({{newY,newX},newZ});
            }
		}
	}
	return 0;
}


int main(){
    int ans=0;

    scanf("%d %d %d", &M, &N, &H);
    for(int k=0; k<H; k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                scanf("%d", &value[k][i][j]);
                if(value[k][i][j]==1){
                    q.push({{i,j},k});
                }
            }
        }
    }

    bfs();


    for(int k=0; k<H; k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(value[k][i][j]==0){
                    printf("-1");
                    return 0;
                }
                if(ans < value[k][i][j]){
                    ans = value[k][i][j];
                }
            }
        }
    }
    printf("%d", ans-1);
    return 0;
}
