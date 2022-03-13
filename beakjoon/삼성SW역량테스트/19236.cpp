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

struct fish{
    int x;
    int y;
    //Dir : 1~8 방향을 나타내고 0이면 물고기가 죽은 것
    int Dir;
};


int ans;
int value[4][4];
fish fish_list[16];

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
            int a,b;
            cin >> a >> b;
            value[i][j] = a;
            fish_list[a]={i,j,b};
        }
    }


    return 0;
}