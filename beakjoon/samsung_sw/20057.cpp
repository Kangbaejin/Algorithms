/* 
 * baekjoon 20057
 * 
 * 마법사 상어와 토네이도
 * 
 * https://www.acmicpc.net/problem/20057
 * 
 * 
 * 구현 계획
 * 
 * 토네이도의 움직임을 구현한 함수, 토네이도 함수 작성
 * 
 * 위치는 N/2 N/2 위치에서 시작하며
 * 토네이도의 움직임을 구현한 함수를 통해 위치를 이동하며,
 * 해당 위치에서 토네이도를 수행한다.
 * 
 * 
 * 토네이도 진행 방향을 고려하여 구현 해야한다!
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define map_max 500
using namespace std;


int sand=0;
int map[map_max][map_max];
int dir_x[4] = {0,1,0,-1};
int dir_y[4] = {-1,0,1,0};
int N;

void Input(){
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
        }
    }
}

void Print(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << map[i][j] << " ";
        }
        cout <<"\n";
    }

    cout << "\n";
}

void tornado(int x, int y, int idx){
    //1 1 2 2 7 7 5 10 10 나머지 % 순서로 구현
    //cout<< x << "," << y <<'\n';
    int xx = x + dir_x[idx];
    int yy = y + dir_y[idx];
    if(xx<0 || xx >=N || yy <0 || yy>=N) return;

    int original = map[xx][yy];
    int temp = original;
    int tor_x[4][10] = {{-1,1,-2,2,0,-1,1,-1,1,0},
                        {0,0,1,1,3,1,1,2,2,2},
                        {-1,1,-2,2,0,-1,1,-1,1,0},
                        {0,0,-1,-1,-3,-1,-1,-2,-2,-2}};
    int tor_y[4][10] = {{0,0,-1,-1,-3,-1,-1,-2,-2,-2},
                        {-1,1,-2,2,0,-1,1,-1,1,0},
                        {0,0,1,1,3,1,1,2,2,2},
                        {-1,1,-2,2,0,-1,1,-1,1,0}};
                        
    int percent[10] = {1,1,2,2,5,7,7,10,10,55};
    for(int i=0;i<10;i++){
        int newx = x+tor_x[idx][i];
        int newy = y+tor_y[idx][i];
        int value = (original*percent[i])/100;
        if(i==9) {
            value = temp;
            // cout<< "remain = " << value <<'\n';
        }
        if(newx<0 || newx >=N || newy <0 || newy>=N) sand+=value;
        else map[newx][newy]+=value;
        temp -= value;
    }
    map[xx][yy]=0;
    //Print();
    return;
}

void moving_point(){
    int distance = 1;
    //총 직선의 갯수는 2N-1 번   마지막 distance 는 3번 움직인다.
    //0,0 위치에 도달했으면 break 하는 방식 사용
    int x = N/2;
    int y = N/2;
    int idx = 0;
    int tests = 2*N-1;
    while(tests--){
        int inner_loop = distance;
        while(inner_loop--){
            tornado(x,y,idx);
            x += dir_x[idx];
            y += dir_y[idx];
            
            //cout << "(x,y) = " << "(" << x << ","  << y << ")\n";
            if(x==0 && y==0){
                tornado(x,y,idx);
                return;
            }
        }
        idx++;
        if(idx==4) idx = 0;

        inner_loop = distance;
        while(inner_loop--){
            tornado(x,y,idx);
            x += dir_x[idx];
            y += dir_y[idx];
            
            //cout << "(x,y) = " << "(" << x << ","  << y << ")\n";
        }
        idx++;
        if(idx==4) idx = 0;

        distance++;
    }

}




int main(){
    Input();
    moving_point();
    cout<<sand;
    return 0;

}