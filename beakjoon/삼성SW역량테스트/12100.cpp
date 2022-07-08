/* 
 * baekjoon 12100
 * 
 * 2048(Easy)
 * 
 * https://www.acmicpc.net/problem/12100
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N,ans=0;
const int max_N = 20;
int map[max_N][max_N];

void Input(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
        }
    }
}




//움직이는 함수 구현할 때 하나씩 하면 안되고
//움직이기 직전의 상황에서 겹칠 수 있는 애들을 딱 체크한 뒤에
//합쳐서 다시 줄어든걸 그 행이든 열에 채워줘야한다.

//0, 1, 2, 3 순서로 시계방향으로 설정하였다. 0이 12시 방향을 나타낸다.
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
void move(int direction){
    queue<int> q;
    if(direction==0){
        //반복문을 통해 각각 col 마다 수행한다.
        for(int j=0; j<N; j++){
            //모든 row 의 값을 탐색하며 0이 아닌 값들을 q 에 넣어준다.
            for(int i=0; i<N; i++){
                if(map[i][j]!=0)
                    q.push(map[i][j]);
                map[i][j]=0;
            }
            //q를 이용하여 덧셈과 이동을 수행한다.
            //1 1 2 2 2 -> 2 4 2 0 0 이 되어야 한다
            //따라서 q 에 기존의 값을 저장한 뒤 순차적으로 꺼내어 진행한다.
            int idx=0;
            while(!q.empty()){
                int value = q.front();
                q.pop();
                //idx 번째 칸이 0인 경우 q 에 있던 제일 앞의 값을 입력한다. 
                //(0 0 4 2 1) -> (4 2 1 0 0) 만들어 주는 과정
                if(map[idx][j]==0)
                    map[idx][j] = value;
                //idx 번째 칸이 q 에 있던 제일 앞의 값과 동일한 경우
                //이 경우는 동일한 두개가 있는 경우로, 두 칸을 더하며 하나로 만든다.
                //이후 idx를 증가시켜 다음칸으로 위치시킨다.
                else if(map[idx][j]==value){
                    map[idx][j] *= 2;
                    idx++;
                }
                //0 도 아니고 값이 다른 경우 idx 를 증가시키고 그 위치에 값을 저장한다.
                else{
                    idx++;
                    map[idx][j] = value;
                }
            }
        }
    }
    //오른쪽
    else if(direction==1){
        for(int i=0; i<N; i++){
            for(int j=N-1; j>=0; j--){
                if(map[i][j]!=0)
                    q.push(map[i][j]);
                map[i][j]=0;
            }
            int idx=N-1;
            while(!q.empty()){
                int value = q.front();
                q.pop();
                if(map[i][idx]==0)
                    map[i][idx] = value;
                else if(map[i][idx]==value){
                    map[i][idx] *= 2;
                    idx--;
                }
                else{
                    idx--;
                    map[i][idx] = value;
                }
            }
        }
    }
    //아래쪽
    else if(direction==2){
        for(int j=0; j<N; j++){
            for(int i=N-1; i>=0; i--){
                if(map[i][j]!=0)
                    q.push(map[i][j]);
                map[i][j]=0;
            }
            int idx=N-1;
            while(!q.empty()){
                int value = q.front();
                q.pop();
                if(map[idx][j]==0)
                    map[idx][j] = value;
                else if(map[idx][j]==value){
                    map[idx][j] *= 2;
                    idx--;
                }
                else{
                    idx--;
                    map[idx][j] = value;
                }
            }
        }
    }
    //왼쪽
    else{
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(map[i][j]!=0)
                    q.push(map[i][j]);
                map[i][j]=0;
            }
            int idx=0;
            while(!q.empty()){
                int value = q.front();
                q.pop();
                if(map[i][idx]==0)
                    map[i][idx] = value;
                else if(map[i][idx]==value){
                    map[i][idx] *= 2;
                    idx++;
                }
                else{
                    idx++;
                    map[i][idx] = value;
                }
            }
        }
    }
}


void DFS(int cnt){
    if(cnt == 5){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                ans = max(ans, map[i][j]);
            }
        }
        return;
    }

    //현재 상태 저장
    int copymap[max_N][max_N];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            copymap[i][j]=map[i][j];
        }
    }

    for(int i=0; i<4; i++){
        move(i);
        DFS(cnt+1);

        //원래 상태로 복구
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                map[i][j]=copymap[i][j];
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Input();
    DFS(0);
    cout << ans;
    
    return 0;
}