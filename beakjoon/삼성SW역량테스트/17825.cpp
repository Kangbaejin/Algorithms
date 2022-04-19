/* 
 * baekjoon 17825
 * 
 * 주사위 윷놀이
 * 
 * https://www.acmicpc.net/problem/17825
 * 
 *
 * 구현 계획
 * 테두리를 도는 점수는 +2 씩 진행된다.
 * 
 * 이때 10에서 출발할때, 20에서 출발할때, 30에서 출발할때 경로가 달라진다.
 * 해당 3가지 경우에 대한 경로는 따로 배열로 저장하여 이용한다.
 * 
 * 
 * 시작점 0, 도착점 -1 로 설정
 * 
 * 
 * 말이 이동을 마치는 칸에 다른 말이 있으면 그 말은 고를 수 없다.
 * 단, 이동을 마치는 칸이 도착 칸이면 고를 수 있다.
 * 라는 조건에 맞도록 구현해야한다.
 * 
 * 
 * moving 함수를 통해 변경된 값을 return 받아서,
 * solve 를 통해 모든 경우를 탐색할때 이용해야 하는가?
 * 그 단계까지의 총합을 기록하며 백트래킹? 하려면 그래야 할 것 같다.
 * 
 */

#include <iostream>

using namespace std;

int ans;

int way_10[] = {10,13,16,19,25,30,35,40};
int way_20[] = {22,24,25,30,35,40};
int way_30[] = {28,27,26,25,30,35,40};

int dice[10];
int stones[4] = {0,0,0,0};

void Input(){
    for(int i=0;i<10;i++)   cin >> dice[i];
}


int moving(int *a, int dice_number){
    //이미 안쪽 경로에 있는 경우 체크
    int flag = 0;
    int idx = 0;
    int newa = *a;
    for(int i=0;i<8;i++){
        if(newa == way_10[i]){
            flag=1;
            idx = i;
            break;
        }
    }
    for(int i=0;i<6;i++){
        if(newa == way_20[i]){
            flag=2;
            idx = i;
            break;
        }
    }
    for(int i=0;i<7;i++){
        if(newa == way_30[i]){
            flag=3;
            idx = i;
            break;
        }
    }
    int newidx = idx + dice_number;
    //이미 안쪽에 있는 경우
    if(flag==1){
        if(newidx >= 8) newa=-1;
        else newa = way_10[newidx];
    }
    if(flag==2){
        if(newidx >= 6) newa = -1;
        else newa = way_20[newidx];
    }
    if(flag==3){
        if(newidx >= 7) newa = -1;
        else newa = way_30[newidx];
    }

    //바깥 쪽에 있는 경우
    if(flag == 0){
        newa = newa + 2*dice_number;
        if(newa > 40) newa = -1;
    }

    //이동하는 칸에 이미 말이 있는지 체크
    int flag2 =0;
    for(int i=0;i<4;i++){
        if(stones[i]==newa){
            //도착칸은 상관 없음
            if(stones[i]!=-1){
                flag2 = -1;
                break;
            }
        }
    }
    //이동하는 칸에 이미 말이 없는 경우 위치 업데이트
    if(flag2==0) *a = newa;

    return newa;
}





int solve(){

}

int main(){
    Input();
    return 0;
}