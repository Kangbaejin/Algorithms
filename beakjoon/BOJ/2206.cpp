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
#define mini(a,b) (a<b ? a : b)
using namespace std;

int value[MAX][MAX] = {0,};
int result[MAX][MAX] = {100000,};
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

vector<pair<int, int>> v;

int N,M;


int bfs(int sy, int sx){
	queue<pair<int, int> > q;
	q.push(make_pair(sy,sx));
	value[sy][sx]=2;
	while(!q.empty()){
		int y = q.front().first, x = q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			int newY= y + dir[i][0], newX= x+ dir[i][1];
			if(newY<0 || newY>=N || newX<0 || newX>=M) continue;
			if(value[newY][newX]==0){
				result[newY][newX]=result[y][x]+1;
				q.push(make_pair(newY,newX));
			}
		}
	}
	return result[N-1][M-1]-1;
}


int solve(){
    for(int x=0;x<N;x++){
        for(int y=0;y<M;y++){
            if(value[x][y]==0){
                for(int i=0; i<4; i++){
                    int newX = x + dir[i][1], newY = y + dir[i][0];
                    if(newX<0 || newX>=M || newY<0 || newY>=N ) continue;
                    if(result[newX][newY]==0){
                        result[x][y]=mini(result[x][y], result[newX][newY]+1);
                    }
                }
            }
        }
    }

    return 0;
}



int main(){
    scanf("%d %d", &N, &M);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%1d", &value[i][j]);
            if(value[i][j] == 1)
                v.push_back({i,j});
        }
    }

    return 0;
}
