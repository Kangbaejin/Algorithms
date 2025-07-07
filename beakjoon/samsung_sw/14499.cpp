/* 
 * baekjoon 14499
 * 
 * 주사위 굴리기
 * 
 * https://www.acmicpc.net/problem/14499
 * 
 * 
 * 구현 계획
 * 
 * 지도를 위한 배열, 주사위를 위한 배열
 * 
 * 이동 함수 
 * 
 * 상단 값을 구하는 함수
 * 
 * 이동에 성공하면 상단 값을 구하는 함수를 호출하여 상단 값을 출력하도록 구현,
 * 이동에 성공하지 않을 경우 원래 상태 유지 출력도 하지 않는다,
 * 
 * 
 * 
 * 동 서 남 북
 * 1  2  3  4
 * 
 * 
 * 이동 함수
 * 굴러 가는 함수 호출 전에 새로 움직일 수 있는 위치 확인 후 가능 하다면 아래 함수 수행
 * 
 * 오른쪽으로 굴러간다 -> 앞 뒤 블럭은 그대로고, 위 오른쪽 아래 왼쪽 순으로 한번 회전한 뒤, 위치를 오른쪽으로 한칸 이동시킨다고 생각.
 * 왼쪽은 그 반대
 * 
 * 위로 굴러간다 -> 왼쪽 오른쪽 블럭으 그대로고, 위 뒤 아래 앞 순으로 한번 회전한 뒤 위치를 위로 한칸 이동시킨다.
 * 아래는 그 반대
 * 
 * 회전하고 위치이동 다 되었으면, 맨 아래 즉 map[newx][newy] 값에 따라 다르게 작동
 * map[newx][newy] == 0 이면, map[newx][newy] = dir_ary[6];
 * map[newx][newy] !=0 이면 , dir_ary[6] = map[newx][newy]; -> map[newx][newy] = 0;
 * 
 * 이 후,
 * 맨 윗면 출력 = dir_ary[0] 출력 
 * 
 * 
 */

#include <iostream>
#define map_max 20
#define oper_max 1000

using namespace std;

struct dice{
    int x;
    int y;
    int dir_ary[7];
};

int map[map_max][map_max];
int oper[oper_max];
int DIR[5][2] = {{0,0},{0,1},{0,-1},{-1,0},{1,0}};

int N,M, r, c, tests;
dice one_dice;



void Input(){
    cin >> N >> M >> r >> c >> tests;
    one_dice.x = r;
    one_dice.y = c;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
        }
    }

    for(int i=0;i<tests;i++){
        cin >> oper[i];
    }
}

void moving(dice &dice, int dir){
    int newr = dice.x+DIR[dir][0];
    int newc = dice.y+DIR[dir][1];

    //벗어나면 아무것도 하지 않고 return
    if(newr<0 || newr>=N || newc<0 || newc>= M) return;
    else{
        //동 1   오른쪽
        if(dir == 1){
            int temp = dice.dir_ary[1];
            dice.dir_ary[1] = dice.dir_ary[4];
            dice.dir_ary[4] = dice.dir_ary[6];
            dice.dir_ary[6] = dice.dir_ary[3];
            dice.dir_ary[3] = temp;
        }
        //서 2   왼쪽
        else if(dir == 2){
            int temp = dice.dir_ary[1];
            dice.dir_ary[1] = dice.dir_ary[3];
            dice.dir_ary[3] = dice.dir_ary[6];
            dice.dir_ary[6] = dice.dir_ary[4];
            dice.dir_ary[4] = temp;
        }
        //북 3
        else if(dir == 3){
            int temp = dice.dir_ary[1];
            dice.dir_ary[1] = dice.dir_ary[5];
            dice.dir_ary[5] = dice.dir_ary[6];
            dice.dir_ary[6] = dice.dir_ary[2];
            dice.dir_ary[2] = temp;  
        }
        //남 4
        else if(dir == 4){
            int temp = dice.dir_ary[1];
            dice.dir_ary[1] = dice.dir_ary[2];
            dice.dir_ary[2] = dice.dir_ary[6];
            dice.dir_ary[6] = dice.dir_ary[5];
            dice.dir_ary[5] = temp;  
        }

        if(map[newr][newc] == 0){
            map[newr][newc] = dice.dir_ary[6];
        }
        else{
            dice.dir_ary[6] = map[newr][newc];
            map[newr][newc] = 0;
        }
        dice.x = newr;
        dice.y = newc;

        cout << dice.dir_ary[1] << '\n';
    }

    return;
}




int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    Input();

    for(int i=0;i<tests;i++){
        moving(one_dice, oper[i]);
    }

    return 0;
}