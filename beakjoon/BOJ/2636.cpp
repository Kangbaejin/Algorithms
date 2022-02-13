/* 
 * baekjoon 2636
 * 
 * 치즈
 * 
 * https://www.acmicpc.net/problem/2636
 * 
 * 
 * 
 * 
 * 
 * 아래의 블로그를 참고하였다.
 * https://ongveloper.tistory.com/159?category=854013
 * bfs 를 진행하며, 각 단계별로의 time 변수를 통해 지나간 시간을 기록하고,
 * 각 bfs 안에서 cnt 를 통해 치즈의 유무를 판단하고, 남은 치즈의 양을 기록하며 진행한다.
 * 
 * 이후 치즈가 모두 녹은 (cnt == 0) 경우에서는 result 변수로 기록된, 직전 시간의 치즈의 양을 가져올 수 있다.
 * 
 */

#include <iostream>
#include <queue>
#include <cstring>
#define MAX 101

using namespace std;
 

int M,N;
int value[MAX][MAX];
bool visited[MAX][MAX];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int result=0, time=0;

int bfs(){
    queue<pair<int,int>> q;
    visited[0][0]=true;
    q.push({0,0});
    time++;
    int cnt = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int newX = x + dir[i][0];
			int newY = y + dir[i][1];
            //배열 벗어나면 continue 처리
			if(newX<0 || newX>=M || newY<0 || newY>=N) continue;

            //새로운 좌표가 방문한 적이 없다면, 
            if(!visited[newX][newY]){
                //새로운 좌표가 치즈이면, 0으로 바꿔주고 그 갯수를 센다.
                if(value[newX][newY] == 1){
                    value[newX][newY] = 0;
                    cnt ++;
                }
                //공기인 경우, 다음 좌표 탐색
                else{
                    q.push({newX,newY});
                }
            }
            visited[newX][newY] = true;
		}
    }
    //치즈가 다 녹은 경우
    if(cnt == 0){
        cout << time-1 << '\n' << result;
        return 0;
    }
    
    //치즈가 남아있는 경우, 단계별 치즈갯수 업데이트
    else{
        result = cnt;
        return -1;
    }

}




int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N;

    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cin >> value[i][j];
        }
    }

    while(1){
        if(bfs()==0)
            break;
        memset(visited, false, sizeof(visited));

    }


    return 0;
}
