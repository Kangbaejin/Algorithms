/* 
 * baekjoon 16234
 * 
 * 인구 이동
 * 
 * https://www.acmicpc.net/problem/16234
 * 
 * 
 */

#include <iostream>
#include <queue>
#include <vector>
#include <string.h>

#define max_rc 50
#define ABS(x)  (((x)<0)? -(x):(x))
using namespace std;

int map[max_rc][max_rc];
bool visited[max_rc][max_rc]={false,};
int union_map[max_rc][max_rc];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int N, min_gap, max_gap;

void Input(){
    cin >> N >> min_gap >> max_gap;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
        }
    }

}


void print_union(){
    for(int i=0;i<N;i++){
        for(int j=0; j<N; j++){
            cout << union_map[i][j] << " ";
        }
        cout << "\n";
    }
}

void print_map(){
    for(int i=0;i<N;i++){
        for(int j=0; j<N; j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}

queue<pair<int, int>> q;

/*
 * 해당 함수는 bfs 알고리즘을 통해 연결할 수 있는 나라들을 하나의 연합으로
 * union_map 배열에 표시해주는 함수이다.
 * 
 * 해당 입력에 대해 union_map 에 아래와 같은 결과가 저장된다.
 * [입력]
 * 4 10 50
 * 10 100 20 90
 * 80 100 60 70
 * 70 20 30 40
 * 50 20 100 10
 *
 * [결과]
 * 1 2 3 3
 * 3 3 3 3
 * 3 3 3 3
 * 3 3 4 3
 * 
 * 해당 결과로 생성된 union_map 은
 * move people 함수에서 동일한 숫자별 갯수와 인구 총합을 구하는 것에 이용된다.
 * 
 */

void make_union(){
    //초기화
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            union_map[i][j] = 0;
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            visited[i][j] = false;
        }
    }
    int u_number = 1;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(visited[i][j]) continue;

            q.push({i,j});
            union_map[i][j]=u_number;
            while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for(int i=0; i<4; i++){
                    int newX = x + dir[i][0];
                    int newY = y + dir[i][1];
                    //배열 벗어나는 경우 continue 처리
                    if(newX<0 || newX>=N || newY<0 || newY>=N) continue;
                    
                    //현재까지 도달하면 배열 안에 존재하는 새로운 위치를 나타낸다.
                    //두 칸의 차이가 조건을 만족한다면 연합에 포함시킨다.
                    int gap = ABS(map[x][y]-map[newX][newY]);
                    if(min_gap<= gap && gap <= max_gap){
                        //조건 통과 -> 열린 길이 있다 -> 인구 이동이 발생한다
                        if(!visited[newX][newY]){
                            visited[newX][newY] = true;
                            union_map[newX][newY] = u_number;
                            q.push({newX,newY});
                        }
                    }
                }
            }
            u_number++;
        }
    }
}


/*
 * make_union 함수를 통해 얻은 union_map 을 통해
 * 각 지역별 인구의 평균을 구하고 map 에 업데이트 해주는 함수이다.
 * 
 * solve 과정에서 더 이상의 인구 변화가 없음을 탐지하기 위해,
 * beforemap 에 초기 map 을 저장한 뒤 map 업데이트를 진행한다.
 * 
 * 이후 함수 끝 부분에서 beforemap 과 map 의 비교
 * 변화가 있었다면 1을 return 하고,
 * 변화가 없었다면 0을 return 하여,
 * solve 부분에서의 반복문 종료에 사용한다.
 * 
 */


int move_people(){
    //인구 이동 전후 결과 비교를 위해 beforemap으로 저장
    int beforemap[max_rc][max_rc];
    for(int i=0;i<N;i++){
        for(int j=0; j<N; j++){
            beforemap[i][j]=map[i][j];
        }
    }

    //도시 갯수와 인구 총합을 위한 배열 선언 및 초기화
    int count_region[2501];
    int sum_region[2501];
    memset(count_region,0,sizeof(int)*2501);
    memset(sum_region,0,sizeof(int)*2501);

    //도시 갯수와 인구 총합 구하기
    for(int i=0;i<N;i++){
        for(int j=0; j<N; j++){
            count_region[union_map[i][j]]++;
            sum_region[union_map[i][j]]+=map[i][j];
        }
    }

    //인구 평균 구하기
    for(int i=0;i<2501;i++){
        if(count_region[i]==0) continue;
        sum_region[i]=sum_region[i]/count_region[i];
    }

    //인구 평균 적용하기
    for(int i=0;i<N;i++){
        for(int j=0; j<N; j++){
            map[i][j] = sum_region[union_map[i][j]];
        }
    }

    //인구 변화가 있는지 확인하고 변화가 있다면 1을 return
    //변화가 없다면 solve 의 while 문 중단을 위해 0 을 return
    for(int i=0;i<N;i++){
        for(int j=0; j<N; j++){
            if(map[i][j]!=beforemap[i][j]) return 1;
        }
    }

    return 0;
}

int ans=0;

void solve(){
    while(ans<2000){
        //각 연합을 만드는 함수
        make_union();
        //각 연합별로 인구 이동을 진행하고, 변화를 확인한다.
        if(move_people()==0) break;
        ans++;
    }
}

int main(){
    Input();
    solve();
    cout << ans;
}