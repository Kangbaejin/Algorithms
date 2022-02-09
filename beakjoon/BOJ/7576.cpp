/* 
 * baekjoon 7576
 * 
 * 토마토
 * 
 * https://www.acmicpc.net/problem/7576
 * 
 * 
 */
#include <cstdio>
#include <queue>
#define MAX 1001

using namespace std;

int value[MAX][MAX] = {0,};
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

queue<pair<int, int>> q;

int N,M;

int bfs(void){
	while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
		q.pop();

		for(int i=0; i<4; i++){
            int newX = x + dir[i][0];
			int newY = y + dir[i][1];
            //배열 벗어나면 continue 처리
			if(newX<0 || newX>=M || newY<0 || newY>=N) continue;

            //새로운 좌표가 안익은 토마토일 때
            if(value[newY][newX] == 0){
                value[newY][newX] = value[y][x] + 1;
                q.push({newY,newX});
            }
		}
	}
	return 0;
}


int main(){
    int ans=0;

    scanf("%d %d", &M, &N);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%d", &value[i][j]);
            if(value[i][j]==1){
                q.push({i,j});
            }
        }
    }
    bfs();
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(value[i][j]==0){
                printf("-1");
                return 0;
            }
            if(ans < value[i][j]){
                ans = value[i][j];
            }
        }
    }
    printf("%d", ans-1);
    return 0;
}
