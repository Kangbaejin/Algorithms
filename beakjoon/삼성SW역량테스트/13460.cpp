/* 
 * baekjoon 13460
 * 
 * 구슬 탈출2
 * 
 * https://www.acmicpc.net/problem/13460
 * 
 * 
 * '.', '#', 'O', 'R', 'B'
 * 빈칸, 벽, 구멍, red, blue
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct bead{ 
	int rx, ry; //빨간 구슬 좌표
	int bx, by;  //파란 구슬 좌표 
	int d;  //기울인 횟수 
};

int n,m;
char board[10][10];
bool visited[10][10][10][10];  //방문 여부 
queue<bead> q;
 
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

//새로운 위치가 벽이 아니고, 현재 구멍의 위치가 아니라면, 이동을 진행한다.
//이때 c 라는 변수를 통해 이동 거리를 기록한다.
void move(int& x, int& y, int& c, int& i){
	while(board[x+dx[i]][y+dy[i]] != '#' && board[x][y] != 'O'){
		x += dx[i];
		y += dy[i];
		c += 1; 
	}
}

void bfs(){
	while(!q.empty()){
		int rx = q.front().rx;
		int ry = q.front().ry;
		int bx = q.front().bx;
		int by = q.front().by;
		int d = q.front().d;
		q.pop();
		
        //기울인 횟수가 10이 넘어가면 탐색 중단.
		if(d>=10) break;
		
		for(int i=0; i<4; i++){
			int nrx=rx, nry=ry, nbx=bx, nby=by;
			int rc=0, bc=0, nd=d+1;
			
			move(nrx, nry, rc, i);
			move(nbx, nby, bc, i);
			
            //파란 공이 이미 구멍에 들어간 경우, 탐색을 멈춘다.
			if(board[nbx][nby] == 'O') continue;
			if(board[nrx][nry] == 'O'){
				cout<<nd;
				return;
			}
			
			//구슬이 겹쳤을 때 
			if(nrx == nbx && nry == nby){
				//굴릴 때, 이동거리가 더 긴 구슬의 위치를 한칸 뒤로 돌림
				if(rc > bc) nrx -= dx[i], nry -= dy[i];
				else nbx -= dx[i], nby -= dy[i];
			}
			
            //4차원 배열을 통해 이미 방문한 경우라면,
            //이미 방문하여 아닌 경우이므로 continue 해준다.
			if(visited[nrx][nry][nbx][nby]) continue;
			visited[nrx][nry][nbx][nby] = true;
			q.push({nrx, nry, nbx, nby, nd});
		}
	}

    //10번 안에 return되지 않으면 -1 출력
	cout<<-1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int rx=0, ry=0, bx=0, by=0;
	cin>>n>>m;
	
	for(int i=0; i<n; i++){
		string s;
		cin>>s;	
		for(int j=0; j<m; j++) {
			board[i][j] = s[j];
			if(s[j] == 'R') rx = i, ry = j;
			else if(s[j] == 'B') bx = i, by = j;
		}
	}
	
	q.push({rx, ry, bx, by, 0});
	visited[rx][ry][bx][by] = true;
	bfs();
}