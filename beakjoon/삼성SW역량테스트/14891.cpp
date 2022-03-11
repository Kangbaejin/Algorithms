/* 
 * baekjoon 14891
 * 
 * 톱니바퀴
 * 
 * https://www.acmicpc.net/problem/14891
 * 
 * 
 * 
 */

#include <iostream>
#include <cstdio>

#define MAX 51
using namespace std;

int wheel[5][8];

int rotate_list[5]={0,};
void will_rotate(int n, int d){
    
    rotate_list[n] = d;
    int idx = n;
    //check left
    while(idx>=2){
        if(rotate_list[idx]!=0 && (wheel[idx-1][2]!=wheel[idx][6])){
            rotate_list[idx-1] = -rotate_list[idx];
        }
        idx--;
    }

    idx = n;
    //cehck right
    while(idx<=3){
        if(rotate_list[idx]!=0 && (wheel[idx][2]!=wheel[idx+1][6])){
            rotate_list[idx+1] = -rotate_list[idx];
        }
        idx++;
    }

    return;
}

void roll(int n, int direction){
    int temp;
    if(direction == 1){
        temp = wheel[n][7];
        for(int i=7;i>0;i--){
            wheel[n][i] = wheel[n][i-1];
        }
        wheel[n][0] = temp;
    }
    else{
        temp = wheel[n][0];
        for(int i=0;i<7;i++){
            wheel[n][i] = wheel[n][i+1];
        }
        wheel[n][7]=temp;
    }
    return;
}


int check_ans(void){
    int ans = 0;
    int value = 1;
    for(int i=1;i<=4;i++){
        if(wheel[i][0]==1){
            ans+=value;
        }
        value = value*2;
    }

    printf("%d", ans);

    return 0;
}




int main(){
    
    for(int i=1;i<=4;i++){
        for(int j=0;j<8;j++){
            scanf("%1d", &wheel[i][j]);
        }
    }

    int times;
    scanf("%d", &times);

    int n, direction;
    for(int k=0;k<times;k++){
        scanf("%d %d", &n, &direction);

    
        //회전할 바퀴 저장 배열 초기화
        for(int i=1;i<=4;i++){
            rotate_list[i] = 0;
        }

        //회전할 바퀴 저장
        will_rotate(n, direction);

        //rotate_list 출력
        // for(int i=1;i<=4;i++){
        //     printf("%d ", rotate_list[i]);
        // }
        // printf("\n");

        //저장 된 바퀴들 회전
        for(int i=1;i<=4;i++){
            if(rotate_list[i]!=0){
                roll(i,rotate_list[i]);
            }
        }

        // //한번 회전된거 출력
        // printf("\n");
        // for(int i=1;i<=4;i++){
        //     for(int j=0;j<8;j++){
        //         printf("%d", wheel[i][j]);
        //     }
        //     printf("\n");
        // }
    }

    check_ans();

    return 0;
}