/* 
 * baekjoon 19237
 * 
 * 어른 상어
 * 
 * https://www.acmicpc.net/problem/19237
 * 
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

struct shark{
    int type,x,y,dir=0;
    int prefer[5][5]={0,};
    bool is_dead = false;
};

struct smell{
    int type=0, remain_smell=0;
};

int N,M,k;
const int max_n = 21;
smell map[max_n][max_n];
vector<shark> shks;


void Input(){
    cin >> N >> M >> k;
    int temp;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> temp;
            if(temp!=0){
                map[i][j].type = temp;
                map[i][j].remain_smell = k;
            }
        }
    }

    //이후 주어지는 현재 방향과 선호 방향이 상어의 type 대로 주어지므로
    //입력의 편의를 위해 상어를 순서대로 vector에 넣도록 한다.
    for(int s=1;s<=M;s++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(map[i][j].type==s){
                    shark one;
                    one.x = i; one.y = j; one.type = s;
                    shks.push_back(one);
                }
            }
        }
    }
    //타입순서대로 상어의 방향 입력
    for(int i=0;i<M;i++){
        cin >> temp;
        shks[i].dir = temp;
    }
    //타입순서대로 이동을 선호하는 방향 저장
    for(int i=0;i<M;i++){
        for(int j=1;j<=4;j++){
            for(int k=1;k<=4;k++){
                cin >> temp;
                shks[i].prefer[j][k]=temp;
            }
        }
    }
}

//1, 2, 3, 4는 각각 위, 아래, 왼쪽, 오른쪽
int dir[5][2]={{0,0},{-1,0},{1,0},{0,-1},{0,1}};

void move_shark(shark& one){
    bool change_flag=false;
    //우선 빈칸 부터 우선순위 기준 탐색
    for(int i=1;i<=4;i++){
        int x=one.x;
        int y=one.y;
        int newX = x+dir[one.prefer[one.dir][i]][0];
        int newY = y+dir[one.prefer[one.dir][i]][1];
        if(newX <0 || newX >=N || newY <0 || newY >= N) continue;
        if(map[newX][newY].remain_smell==0){
            change_flag = true;
            one.x = newX; one.y = newY;
            one.dir = one.prefer[one.dir][i];
            break;
        }
    }
    //빈칸에서 변경이 없었다면 본인의 냄새가 남아있는 영역을 우선순위 기준 탐색
    if(!change_flag){
        for(int i=1;i<=4;i++){
            int x=one.x;
            int y=one.y;
            int newX = x+dir[one.prefer[one.dir][i]][0];
            int newY = y+dir[one.prefer[one.dir][i]][1];
            if(map[newX][newY].type==one.type){
                one.x = newX; one.y = newY;
                one.dir = one.prefer[one.dir][i];
                break;
            }
        }
    }
}

//상어의 이동이 끝난 후 겹치는 상어들 중 작은 상어들 내보내는 함수
void update_shark(){
    for(int i=0;i<shks.size();i++){
        if(shks[i].is_dead) continue;
        for(int j=i+1;j<shks.size();j++){
            if(shks[j].is_dead) continue;
            //같은 위치에 상어가 있는 경우
            if((shks[i].x == shks[j].x) && (shks[i].y == shks[j].y)){
                if(shks[i].type > shks[j].type){
                    shks[i].is_dead=true;
                }
                else{
                    shks[j].is_dead=true;
                }
            }
        }
    }
}

void update_map(){
    //일단 map 의 남은 냄새들을 모두 1 감소
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(map[i][j].remain_smell > 0) map[i][j].remain_smell--;
        }
    }
    //이후 상어가 있는 자리는 다시 k로 업데이트
    for(int i=0;i<shks.size();i++){
        if(shks[i].is_dead) continue;
        int nx = shks[i].x;
        int ny = shks[i].y;
        map[nx][ny].type = shks[i].type;
        map[nx][ny].remain_smell=k;
    }
}

bool check_shark(){
    int cnt=0;
    for(int i=0;i<shks.size();i++){
        if(!shks[i].is_dead) cnt++;
    }
    if(cnt==1) return true;
    else return false;
}

void solve(){
    int cnt=0;
    while(cnt<1000){
        cnt++;
        for(int i=0;i<shks.size();i++){
            if(shks[i].is_dead) continue;
            move_shark(shks[i]);
        }
        update_shark();
        update_map();
        if(check_shark()) {
            cout << cnt;
            return;
        }
    }
    cout << -1;
    return;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    Input();
    solve();
    return 0;
}