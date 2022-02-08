/* 
 * baekjoon 2206
 * 
 * 벽 부수고 이동하기
 * 
 * https://www.acmicpc.net/problem/2206
 * 
 * 
 */

#include <cstdio>
#include <queue>

#define MAX 1001

using namespace std;

int value[MAX][MAX] = {0,};
int result[MAX][MAX][2] = {0,};
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int N,M;


int bfs(void){
	queue<pair<pair<int, int>, int> > q;

	q.push({{0,0},1});
	result[0][0][1]=1;
	while(!q.empty()){
        int x = q.front().first.first;
		int y = q.front().first.second;
        int block = q.front().second;
		q.pop();

        if(x == N-1 && y == M-1)
            return result[x][y][block];

		for(int i=0; i<4; i++){
            int newX = x + dir[i][0];
			int newY = y + dir[i][1];
            //배열 벗어나면 continue 처리
			if(newX<0 || newX>=N || newY<0 || newY>=M) continue;

            //벽이 있으며, 아직 벽을 뚫지 않았으면
            if(value[newX][newY] == 1 && block == 1){
                result[newX][newY][block-1] = result[x][y][block] + 1;
                q.push({{newX,newY},block-1});
            }
            //벽이 없는 경우
			else if(value[newX][newY]==0 && result[newX][newY][block]== 0){
				result[newX][newY][block]=result[x][y][block]+1;
				q.push({{newX,newY}, block});
			}
		}
	}
	return -1;
}





int main(){
    scanf("%d %d", &N, &M);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%1d", &value[i][j]);
        }
    }

    printf("%d", bfs());

    return 0;
}
