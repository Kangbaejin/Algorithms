/* 
 * baekjoon 17837
 * 
 * 새로운 게임 2
 * 
 * https://www.acmicpc.net/problem/17837
 * 
 * 
 * 구현 계획
 * 
 * 1) 선택
 * 
 * 이동 함수
 *  흰색인 경우
 *  빨간색인 경우
 *  파란색인 경우
 * 
 * 1턴이 끝난 뒤 마다 체크 함수
 * 
 * 
 * 2) 
 * 이동 함수
 *  흰색인 경우
 *  빨간색인 경우
 *  파란색인 경우
 * 
 * 현재 상태를 기록하는 배열에서
 * 이동함수가 실행 되었을 때, 높이가 4가 된다면 
 * 턴을 출력하고 return
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>

#define N_MAX 13
#define K_MAX 11
using namespace std;

struct stone {
    int x;
    int y;
    int dir;
};

//map[i][j] 위치의 말들을 기록하기위해 vector 생성

vector<int> map[N_MAX][N_MAX];
stone list[K_MAX];
// →, ←, ↑, ↓
int dir[5][2] = {{0,0},{1,0},{-1,0},{0,-1},{0,1}};
int N,K;




bool checking(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(map[i][j].size()>=5)
                return true;
        }
    }

    return false;
}


void moving(){
    for(int i=1;i<K_MAX;i++){
        int x = list[i].x;
        int y = list[i].y;
        int d = list[i].dir;
        //x==0 이거나 y==0 인 경우 이상부터는 움직일 말이 없는 경우 이므로 이상일 경우 return
        if(x==0 || y==0) break;

        
        int first_number = find(map[x][y].begin()+1, map[x][y].end(), i) - map[x][y].begin();
        vector<int> move_list;
        for(int k=first_number;k<map[x][y].size();k++){
            move_list.push_back(map[x][y][k]);
        }

        //원래 x,y 위치에 있던 값 제거
        int move_list_size = move_list.size();
        while(move_list_size--){
            map[x][y].pop_back();
        }

        //cout << "pop back done \n";

        //움직일 수 없다면
        //파란색인 경우와 똑같이 처리
        int newx = x + dir[d][0];
        int newy = y + dir[d][1];
        if(newx < 1 || newx >N || newy < 1 || newy>N){
            //새로운 방향이 배열 밖이었다면, 반대 방향은 무조건 배열 안쪽이다.

            //d 방향 뒤집기
            int r = d%2;
            if(r==0) {
                d = d-1;
            }
            else {
                d = d+1;
            }

            newx = x + dir[d][0];
            newy = y + dir[d][1];
            //파란색과 똑같이 취급하여 움직이지 못하므로
            if(map[newx][newy][0] == 2){
                list[i].dir = d;
                //원래 위치에 다시 입력
                for(int j=0;j<move_list.size();j++){
                    map[x][y].push_back(move_list[j]);
                }
            }
            //파란색이 아니라면 새로운 위치에 move_list 값들을 입력
            else{
                for(int j=0;j<move_list.size();j++){
                    list[move_list[j]].x = newx;
                    list[move_list[j]].y = newy;
                    map[newx][newy].push_back(move_list[j]);
                }
            }
        }

        //움직일 수 있다면
        else{
            //흰색인 경우
            if(map[newx][newy][0]==0){
                for(int j=0;j<move_list.size();j++){
                    list[move_list[j]].x = newx;
                    list[move_list[j]].y = newy;
                    map[newx][newy].push_back(move_list[j]);
                }
            }
            //빨간색인 경우
            else if(map[newx][newy][0] == 1){
                for(int j=move_list.size()-1;j>=0;j--){
                    list[move_list[j]].x = newx;
                    list[move_list[j]].y = newy;
                    map[newx][newy].push_back(move_list[j]);
                }
            }
            //파란색인 경우
            else if(map[newx][newy][0] == 2){
                int r = d%2;
                if(r==0) {
                    d = d-1;
                }
                else {
                    d = d+1;
                }
                newx = x + dir[d][0];
                newy = y + dir[d][1];
                //새로운 방향이 파란색이거나 배열을 벗어나면 방향만 바꿔준다.
                //move_list 로 옮겨놨던 값 다시 원래 x y 위치에 넣어준다.
                if((map[newx][newy][0] == 2) || (newx < 1 || newx >N || newy < 1 || newy>N)){
                    list[i].dir = d;
                    for(int j=0;j<move_list.size();j++){
                        map[x][y].push_back(move_list[j]);
                    }
                }
                else{
                    for(int j=0;j<move_list.size();j++){
                        list[move_list[j]].x = newx;
                        list[move_list[j]].y = newy;
                        map[newx][newy].push_back(move_list[j]);
                    }
                }
            }
        }
        //cout << i <<"th cycle is done \n";
    }
}


void solve(){
    int cnt = 0;
    while(cnt <= 1000){
        cnt++;
        moving();
        if(checking()){
            cout << cnt;
            return;
        }
    }
    cout << -1;
    return;
}


void v_input(){
    cin >> N >> K;
    int temp;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> temp;
            map[i][j].push_back(temp);
        }
    }

    for(int i=1; i<=K; i++){
        int ix, iy, id;
        cin >> ix >> iy >> id;
        list[i].x = ix;
        list[i].y = iy;
        list[i].dir = id;

        map[ix][iy].push_back(i);
    }

}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0); 
    // cout.tie(0);

    v_input();

    solve();

    return 0;
    
}