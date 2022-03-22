/* 
 * baekjoon 5373
 * 
 * 큐빙
 * 
 * https://www.acmicpc.net/problem/5373
 * 
 * 
 * 평면 
 * 0 1 2 3 4 5
 * u d f b l r
 * 
 * 색
 * 0 1 2 3 4 5
 * w y r o g b
 * 
 */


#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

char all[6][9];


char plane[6] = {'U', 'D', 'F', 'B', 'L', 'R'};
char color[6] = {'w', 'y', 'r', 'o', 'g', 'b'};

void initial(){
    for(int i=0;i<6;i++){
        for(int j=0;i<9;j++){
            all[i][j] = color[i];
        }
    }
}

//p = 0~5, row = 0~2
void get_one_row(int p, int row, char *a, char *b, char *c){
    *a = all[p][row*3];
    *b = all[p][row*3+1];
    *c = all[p][row*3+2];
}
//p = 0~5, col = 0~2
void get_one_col(int p, int col, char *a, char *b, char *c){
    *a = all[p][col];
    *b = all[p][col+3];
    *c = all[p][col+6];
}


// 0 1 2
// 3 4 5
// 6 7 8

// 1 1 4                2 2 1
// 2 X 4  clock wise -> 3 X 1
// 2 3 3                3 4 4
//
// 1 1 4                        4 4 3
// 2 X 4  counter clock wise -> 1 X 3
// 2 3 3                        1 2 2
void rot_one_plane(int p, char dir){
    if(dir == '+'){
        char one[2] = {all[p][0], all[p][1]};
        //1 위치에 2 입력
        all[p][1] = all[p][3];
        all[p][0] = all[p][6];

        //2 위치에 3 입력
        all[p][3] = all[p][7];
        all[p][6] = all[p][8];

        //3 위치에 4 입력
        all[p][7] = all[p][5];
        all[p][8] = all[p][2];

        //4 위치에 저장했던 1 입력
        all[p][5] = one[1];
        all[p][2] = one[0];
    }
    else{
        char one[2] = {all[p][0], all[p][1]};
        //1 위치에 4 입력
        all[p][0] = all[p][2];
        all[p][1] = all[p][5];

        //4 위치에 3 입력
        all[p][2] = all[p][8];
        all[p][5] = all[p][7];

        //3 위치에 2 입력
        all[p][8] = all[p][6];
        all[p][7] = all[p][3];

        //2 위치에 저장했던 1 입력
        all[p][3] = one[1];
        all[p][6] = one[0];
    }
}

/*
 * 한 면을 돌린다는 것은 해당하는 면은 방향대로 모든 9개의 인자를 돌려야하고,
 * 그 면과 연결된 주변의 12개의 인자들을 방향에 맞게 순환시켜 다시 저장해야한다.
 * 
 */
void action(char char_p, char dir){
    int p;
    for(p = 0; p<6; p++){
        if(plane[p] == char_p) break;
    }

    rot_one_plane(p, dir);
    //평면에 딸린 옆면들 돌리는 코드
    //추가 작성 해야한다.

}




void print_top(){
    for(int i=1;i<=9;i++){
        cout << all[0][i-1];
        if(i%3 == 0) cout << "\n";
    }
}


void solve(){
    initial();

    int N;
    cin >> N;

    for(int i=0;i<N;i++){
        int M;
        cin >> M;
        string temp;
        for(int j=0; j<M; j++){
            cin >> temp;
            action(temp[0], temp[1]);
        }
        print_top();
    }
}


int main(){
    solve();
    return 0;
}