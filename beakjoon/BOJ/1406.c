/* baekjoon 1406
 *
 * 에디터
 * 
 * https://www.acmicpc.net/problem/1406
 * 
 * 
 *  
 * 자료구조, 스택, 연결 리스트
 * 
 * 
 * 
 * 문제 Point
 * 배열 한개와 커서로 구현을 할 수도 있지만,
 * 자료 구조의 장점을 이용,
 * 커서의 위치를 왼쪽 스택과 오른쪽 스택으로 구분하여
 * 표현할 수 있다.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char L_stack[6000001], R_stack[6000001];
int L_top = -1;
int R_top = -1;

void moveLeft(){
    R_stack[++R_top]=L_stack[L_top--];
    L_stack[L_top+1]='\0';

}

void moveRight(){
    L_stack[++L_top]=R_stack[R_top--];
    R_stack[R_top+1]='\0';
}

void delete(){
    L_stack[L_top--]='\0';
}


void insert(char value){
    L_stack[++L_top]=value;
    L_stack[L_top+1]='\0';
}



int main(){
    //커서 왼쪽을 L_stack 으로 커서 오른쪽을 R_stack 으로 구현

    scanf("%s", L_stack);
    L_top = strlen(L_stack)-1;

    int commands;
    scanf("%d", &commands);

    while(commands>0){
        commands--;

        char command;
        scanf(" %c", &command);

        if(command == 'L'){
            if(L_top!=-1)
                moveLeft();
        }
        if(command == 'D'){
            if(R_top!=-1)
                moveRight();
        }
        if(command == 'B'){
            if(L_top!=-1)
                delete();
        }
        if(command == 'P'){
            char val;
            scanf(" %c",&val);
            insert(val);
        }
    
    }

    for(int i=0;i<=L_top;i++){
        printf("%c",L_stack[i]);
    }
    //printf("%s", L_stack);

    while(R_top>=0){
        printf("%c", R_stack[R_top]);
        R_top--;
    }

}