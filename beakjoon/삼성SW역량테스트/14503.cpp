/* 
 * baekjoon 14503
 * 
 * 로봇 청소기
 * 
 * https://www.acmicpc.net/problem/14503
 * 
 * 
 * 
 */

#include <iostream>

#define MAX 51
using namespace std;

int N, M;
int answer = 0;

int value[MAX][MAX] = {0,};
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

void dfs(int cx, int cy, int cd){
    if (value[cx][cy] == 0) {
		value[cx][cy] = 2;
		answer++;
	}
	for(int i=0; i<4; i++){
        int newd = (cd-i+3)%4;
        int newx = cx + dir[newd][0];
		int newy = cy + dir[newd][1];
        //배열 벗어나면 continue 처리
		if(newx<0 || newx>=N || newy<0 || newy>=M) continue;
        //가능한 좌표중 빈칸이면 dfs
        if(value[newx][newy] == 0){
            dfs(newx,newy,newd);
        }
	}
    //위의 for 문을 4번 돌면서 네 방향 모두 벽인지 혹은 청소가 되었는지 확인하고
    //아래의 부분의 명령이 실행 된다는 것은 네 방향 모두 청소가 이미 되어있거나, 벽인 경우를 의미한다.

    int back_idx = (cd+2)%4;
    int back_x = cx + dir[back_idx][0];
    int back_y = cy + dir[back_idx][1];


    if(!(back_x<0 || back_x>=N || back_y<0 || back_y>=M)){
        if(value[back_x][back_y]==1){
            cout << answer;
            exit(0);
        }
        dfs(back_x,back_y,cd);
    }
}



int main(){
    
    cin >> N >> M;

    int r,c,d;
    cin >> r >> c >> d;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> value[i][j];
        }
    }


    dfs(r,c,d);
    
    return 0;
}