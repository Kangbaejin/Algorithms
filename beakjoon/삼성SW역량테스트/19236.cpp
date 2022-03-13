/* 
 * baekjoon 19236
 * 
 * 청소년 상어
 * 
 * https://www.acmicpc.net/problem/19236
 * 
 * 
 * 
 */

#include <iostream>

using namespace std;

int value[4][4][2] = {0,};

int dir[8][2] = {{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};



int check_8_ways(int r, int c, int d){
    int newd = d;
    do{
        int newr = r + dir[newd][0];
		int newc = c + dir[newd][1];
        //배열 벗어나면 continue 처리
		if(newr<0 || newr>=4 || newc<0 || newc>=4) {
            newd = (newd + 1) % 8;
            continue;
        }
        //가능한 좌표라면 교환
        if(!(newr == 0 && newc == 0)){
            
        }
	}while(newd != d);


    return 0;
}


void moving_fish(){

}




int main(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<2;k++){
                cin >> value[i][j][k];
            }
        }
    }


    return 0;
}