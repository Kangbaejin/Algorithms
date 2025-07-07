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
 * cctv 종류별로 가짓수를 oper 벡터에 푸쉬해서 보관,
 * 
 * rotate_oper 함수를 통해
 * {4, 4, 2} 가짓수의 경우라면
 * {1, 1, 1} 부터 시작해서
 * {1, 1, 1} -> {2, 1, 1} -> {3, 1, 1} -> {4, 1, 1} -> {1, 2, 1} 식으로
 * 모든 경우의수를 탐색할 수 있게 구현했다.
 * 
 * 문제의 예제 테스트케이스를 모두 통과했고,
 * 반례도 많이 찾아서 실행 했을때 모두 맞게나왔지만
 * 제출하자마자 %도 오르지 않고 바로 틀렸습니다가 출력됐다.
 * 
 */


#include <iostream>
#include <vector>
#include <cstring>
#define m_max 8
using namespace std;

int N,M;
int map[m_max][m_max];
int min_v=0;
vector <int> opers;
vector <int> copy_oper;
//int ans_map[m_max][m_max];

void cctv1(int copy_map[m_max][m_max], int x, int y, int c){
    int dir_x[4]={0,0,1,-1};
    int dir_y[4]={1,-1,0,0};

    int newx = x;
    int newy = y;

    while(1){
        newx += dir_x[c-1];
        newy += dir_y[c-1];
        if(!(newx>=0 && newx<N && newy>=0 && newy<M)) break;
        if(copy_map[newx][newy]==6) break;
        else if(copy_map[newx][newy] == 0){
            copy_map[newx][newy] = -1;
        }
    }

    return;
}

void cctv2(int copy_map[m_max][m_max], int x, int y, int c){
    if(c==1){
        int new1 = x;
        while(1){
            new1 += 1;
            if(!(new1>=0 && new1<N)) break;
            if(copy_map[new1][y]==6) break;
            else if(copy_map[new1][y] == 0){
                copy_map[new1][y] = -1;
            }
        }
        int new2 = x;
        while(1){
            new2 += -1;
            if(!(new2>=0 && new2<N)) break;
            if(copy_map[new1][y]==6) break;
            else if(copy_map[new1][y]==0){
                copy_map[new1][y] = -1;
            }
            
        }
    }

    if(c==2){
        int new1 = y;
        int new2 = y;
        while(1){
            new1 += 1;
            if(!(new1>=0 && new1<M)) break;
            if(copy_map[x][new1] == 6) break;
            else if(copy_map[x][new1] == 0){
                copy_map[x][new1] = -1;
            }
        }

        while(1){
            new2 += -1;
            if(!(new2>=0 && new2<M)) break;
            if(copy_map[x][new2] == 6) break;
            else if(copy_map[x][new2] == 0){ 
                copy_map[x][new2] = -1;
            }
        }
    }
    return;
}

void cctv3(int copy_map[m_max][m_max], int x, int y, int c){
    int dir_new1[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int dir_new2[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

    int new1_x = x;
    int new1_y = y;

    int new2_x = x;
    int new2_y = y;

    while(1){
        new1_x += dir_new1[c-1][0];
        new1_y += dir_new1[c-1][1];
        if(!(new1_x>=0 && new1_x<N && new1_y>=0 && new1_y<M)) break;
        if(copy_map[new1_x][new1_y] == 6) break;
        else if(copy_map[new1_x][new1_y]==0){
            copy_map[new1_x][new1_y] = -1;
        }
    }
    
    while(1){
        new2_x += dir_new2[c-1][0];
        new2_y += dir_new2[c-1][1];
        if(!(new2_x>=0 && new2_x<N && new2_y>=0 && new2_y<M)) break;
        if(copy_map[new2_x][new2_y] == 6) break;
        else if(copy_map[new2_x][new2_y] == 0){
            copy_map[new2_x][new2_y] = -1;
        }
    }

    return;
}

void cctv4(int copy_map[m_max][m_max], int x, int y, int c){
    int dir_new1[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int dir_new2[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    int dir_new3[4][2] = {{0,-1},{-1,0},{0,1},{1,0}};

    int new1_x = x;
    int new1_y = y;

    int new2_x = x;
    int new2_y = y;

    int new3_x = x;
    int new3_y = y;

    while(1){
        new1_x += dir_new1[c-1][0];
        new1_y += dir_new1[c-1][1];
        if(!(new1_x>=0 && new1_x<N && new1_y>=0 && new1_y<M)) break;
        if(copy_map[new1_x][new1_y] == 6) break;
        else if(copy_map[new1_x][new1_y]==0){
            copy_map[new1_x][new1_y] = -1;
        }
    }

    while(1){
        new2_x += dir_new2[c-1][0];
        new2_y += dir_new2[c-1][1];
        if(!(new2_x>=0 && new2_x<N && new2_y>=0 && new2_y<M)) break;
        if(copy_map[new2_x][new2_y] == 6) break;

        else if(copy_map[new2_x][new2_y]==0){
            copy_map[new2_x][new2_y] = -1;
        }
    }

    while(1){
        new3_x += dir_new3[c-1][0];
        new3_y += dir_new3[c-1][1];
        if(!(new3_x>=0 && new3_x<N && new3_y>=0 && new3_y<M)) break;
        if(copy_map[new3_x][new3_y] == 6) break;
        else if(copy_map[new3_x][new3_y]==0){
            copy_map[new3_x][new3_y] = -1;
        }
    }

    return;
}

void cctv5(int copy_map[m_max][m_max], int x, int y){
    int new1_x = x;
    int new1_y = y;

    int new2_x = x;
    int new2_y = y;

    int new3_x = x;
    int new3_y = y;

    int new4_x = x;
    int new4_y = y;

    while(1){
        new1_x += 1;
        new1_y += 0;
        if(!(new1_x>=0 && new1_x<N && new1_y>=0 && new1_y<M)) break;
        if(copy_map[new1_x][new1_y] == 6) break;
        else if(copy_map[new1_x][new1_y]==0){
            copy_map[new1_x][new1_y] = -1;
        }
    }

    while(1){
        new2_x += -1;
        new2_y += 0;
        if(!(new2_x>=0 && new2_x<N && new2_y>=0 && new2_y<M)) break;
        if(copy_map[new2_x][new2_y] == 6) break;
        else if(copy_map[new2_x][new2_y]==0){
            copy_map[new2_x][new2_y] = -1;
        }
    }

    while(1){
        new3_x += 0;
        new3_y += 1;
        if(!(new3_x>=0 && new3_x<N && new3_y>=0 && new3_y<M)) break;
        if(copy_map[new3_x][new3_y] == 6) break;
        else if(copy_map[new3_x][new3_y]==0){
            copy_map[new3_x][new3_y] = -1;
        }
    }

    while(1){
        new4_x += 0;
        new4_y += -1;
        if(!(new4_x>=0 && new4_x<N && new4_y>=0 && new4_y<M)) break;
        if(copy_map[new4_x][new4_y] == 6) break;
        else if(copy_map[new4_x][new4_y]==0){
            copy_map[new4_x][new4_y] = -1;
        }
    }

    return;
}

int check(int map[m_max][m_max]){
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

void print_arr(int map[m_max][m_max]){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    return;
}


void one_action(vector<int> opers){
    int copy_map[m_max][m_max];
    memcpy(copy_map, map, sizeof(int)*m_max*m_max);
    int idx =0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(copy_map[i][j] == 1){
                cctv1(copy_map, i, j, opers[idx]);
                idx++;
            }
            if(copy_map[i][j] == 2){
                cctv2(copy_map, i, j, opers[idx]);
                idx++;
            }
            if(copy_map[i][j] == 3){
                cctv3(copy_map, i, j, opers[idx]);
                idx++;
            }
            if(copy_map[i][j] == 4){
                cctv4(copy_map, i, j, opers[idx]);
                idx++;
            }
            if(copy_map[i][j] == 5){
                cctv5(copy_map, i, j);
                idx++;
            }
        }
    }



    int check_zero = check(copy_map);

    // print_arr(copy_map);

    // cout << "\nzero count : " <<check_zero <<'\n';

    if(min_v > check_zero) {
        //memcpy(ans_map, copy_map, sizeof(int)*m_max*m_max);
        min_v = check_zero;
    }
}

void rotate_oper(vector<int> dest, vector<int> start){
    while(1){
        one_action(start);
        if(dest == start) break;
        else{
            start[0]++;
            for(int i=0;i<start.size()-1;i++){
                if(start[i]>dest[i]){
                    start[i+1]++;
                    start[i] = 1;
                }
            }
        }
    }
}




void solve(){
    rotate_oper(opers,copy_oper);
    return;
}



void Input(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
            if(map[i][j]==0) min_v++;
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
            if(map[i][j]==5){
                opers.push_back(1);
            }
        }
    }

    for(int i=0;i<opers.size();i++){
        copy_oper.push_back(1);
    }
}


int main(){
    Input();
    solve();
    //print_arr(ans_map);
    cout << min_v;

    return 0;
}