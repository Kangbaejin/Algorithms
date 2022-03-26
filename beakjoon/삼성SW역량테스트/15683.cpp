/* 
 * baekjoon 15683
 * 
 * 감시
 * 
 * https://www.acmicpc.net/problem/15683
 * 
 * 
 * 
 * cctv 1
 * 4가지 경우
 * 
 * cctv 2
 * 2가지 경우
 * 
 * cctv 3
 * 4가지
 * 
 * cctv 4
 * 4가지
 * 
 * cctv 5
 * 1가지
 * 
 * 
 * cctv 종류별로 가짓수 벡터에 푸쉬백 해서 보관,
 * 종류 앞에서부터 하나씩 빼면서 진행, 벡터 마지막 인자 값이 0이 되면 종료
 * 모든 경우의 수 구현해서 처음부터 진행했을 때 현재 경우의 수로 돌리고 진행한다.
 * 
 * 
 */


#include <iostream>
#include <vector>
#define m_max 8
using namespace std;

int N,M;
int map[m_max][m_max];
int min;
vector <int> opers;


void cctv1(int *copy_map[m_max][m_max], int x, int y, int c){
    int dir_x[4]={0,0,1,-1};
    int dir_y[4]={1,-1,0,0};

    int newx = x+dir_x[c];
    int newy = y+dir_y[c];

    while(newx>=0 && newx<N){
        *copy_map[newx][y] = -1;
        newx += dir_x[c];
    }

    while(newy>=0 && newy<M){
        *copy_map[x][newy] = -1;
        newy += dir_y[c];
    }

    return;
}


void cctv2(int *copy_map[m_max][m_max], int x, int y, int c){
    if(c==0){
        int new1 = x+1;
        int new2 = x-1;
        while(new1>=0 && new1<N){
            *copy_map[new1][y] = -1;
            new1 += 1;
        }

        while(new2>=0 && new2<N){
            *copy_map[new1][y] = -1;
            new2 += -1;
        }
    }

    if(c==1){
        int new1 = y+1;
        int new2 = y-1;
        while(new1>=0 && new1<N){
            *copy_map[x][new1] = -1;
            new1 += 1;
        }

        while(new2>=0 && new2<N){
            *copy_map[x][new2] = -1;
            new2 += -1;
        }
    }
    return;
}



void cctv3(int *copy_map[m_max][m_max], int x, int y, int c){
    int dir_new1[4][2] = {{0,1},{0, 1},{0,-1},{0,-1}};
    int dir_new2[4][2] = {{0,-1},{0,1},{0, 1},{0,-1}};

    int new1_x = x+dir_new1[c][0];
    int new1_y = y+dir_new1[c][0];

    int new2_x = x+dir_new2[c][0];
    int new2_y = y+dir_new2[c][0];

    while(new1_x>=0 && new1_x<N && new1_y>=0 && new1_y<M){
        *copy_map[new1_x][new1_y] = -1;
        new1_x += dir_new1[c][0];
        new1_y += dir_new1[c][0];
    }
    
    while(new2_x>=0 && new2_x<N && new2_y>=0 && new2_y<M){
        *copy_map[new2_x][new2_y] = -1;
        new2_x += dir_new2[c][0];
        new2_y += dir_new2[c][0];
    }

    return;
}



//noc = number_of_case
void cctv(int x, int y, int type, int noc){

}




int check(){
    int z_count = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j] == 0){
                z_count++;
            }
        }
    }
    return z_count;
}



void Input(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
            if(map[i][j]==1){
                opers.push_back(4);
            }
            if(map[i][j]==2){
                opers.push_back(2);
            }
            if(map[i][j]==3){
                opers.push_back(4);
            }
            if(map[i][j]==4){
                opers.push_back(4);
            }
        }
    }
    min = N*M;
}


int main(){
    Input();

    return 0;
}