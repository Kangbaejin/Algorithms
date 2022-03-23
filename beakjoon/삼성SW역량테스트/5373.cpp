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
 * 
 * 
 * print all 함수를 구현하여
 * 
 * 1
 * 2
 * U+ U- 를 모든 평면에 적용하여 오류를 찾아냈다.
 * 
 */


#include <iostream>
#include <string>


using namespace std;

char all[6][9];


char plane[6] = {'U', 'D', 'F', 'B', 'L', 'R'};
char color[6] = {'w', 'y', 'r', 'o', 'g', 'b'};

void initial(){
    for(int i=0;i<6;i++){
        for(int j=0;j<9;j++){
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

        if(p==0){
            char temp[3]={all[2][0], all[2][1], all[2][2]};
            all[2][0] = all[5][0];
            all[2][1] = all[5][1];
            all[2][2] = all[5][2];

            all[5][0] = all[3][0];
            all[5][1] = all[3][1];
            all[5][2] = all[3][2];

            all[3][0] = all[4][0];
            all[3][1] = all[4][1];
            all[3][2] = all[4][2];

            all[4][0] = temp[0];
            all[4][1] = temp[1];
            all[4][2] = temp[2];
        }
        else if(p==1){
            char temp[3]={all[2][6], all[2][7], all[2][8]};
            all[2][6] = all[4][6];
            all[2][7] = all[4][7];
            all[2][8] = all[4][8];

            all[4][6] = all[3][6];
            all[4][7] = all[3][7];
            all[4][8] = all[3][8];

            all[3][6] = all[5][6];
            all[3][7] = all[5][7];
            all[3][8] = all[5][8];

            all[5][6] = temp[0];
            all[5][7] = temp[1];
            all[5][8] = temp[2];

        }
        else if(p==2){
            char temp[3]={all[0][6], all[0][7], all[0][8]};
            all[0][8] = all[4][2];
            all[0][7] = all[4][5];
            all[0][6] = all[4][8];

            all[4][2] = all[1][0];
            all[4][5] = all[1][1];
            all[4][8] = all[1][2];

            all[1][0] = all[5][6];
            all[1][1] = all[5][3];
            all[1][2] = all[5][0];

            all[5][0] = temp[0];
            all[5][3] = temp[1];
            all[5][6] = temp[2];
        }
        else if(p==3){
            char temp[3]={all[0][0], all[0][1], all[0][2]};
            
            all[0][0] = all[5][2];
            all[0][1] = all[5][5];
            all[0][2] = all[5][8];

            all[5][2] = all[1][8];
            all[5][5] = all[1][7];
            all[5][8] = all[1][6];

            all[1][6] = all[4][0];
            all[1][7] = all[4][3];
            all[1][8] = all[4][6];

            all[4][0] = temp[2];
            all[4][3] = temp[1];
            all[4][6] = temp[0];
            
        }
        else if(p==4){
            char temp[3]={all[0][0], all[0][3], all[0][6]};
            
            all[0][6] = all[3][2];
            all[0][3] = all[3][5];
            all[0][0] = all[3][8];

            all[3][2] = all[1][6];
            all[3][5] = all[1][3];
            all[3][8] = all[1][0];

            all[1][0] = all[2][0];
            all[1][3] = all[2][3];
            all[1][6] = all[2][6];

            all[2][0] = temp[0];
            all[2][3] = temp[1];
            all[2][6] = temp[2];
        }
        else if(p==5){
            char temp[3]={all[0][2], all[0][5], all[0][8]};
            
            all[0][2] = all[2][2];
            all[0][5] = all[2][5];
            all[0][8] = all[2][8];

            all[2][2] = all[1][2];
            all[2][5] = all[1][5];
            all[2][8] = all[1][8];

            all[1][2] = all[3][6];
            all[1][5] = all[3][3];
            all[1][8] = all[3][0];

            all[3][0] = temp[2];
            all[3][3] = temp[1];
            all[3][6] = temp[0];
        }

    }
// 0 1 2
// 3 4 5
// 6 7 8

// 1 1 4                        4 4 3
// 2 X 4  counter clock wise -> 1 X 3
// 2 3 3                        1 2 2
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


        if(p==0){
            char temp[3]={all[2][0], all[2][1], all[2][2]};
            all[2][0] = all[4][0];
            all[2][1] = all[4][1];
            all[2][2] = all[4][2];

            all[4][0] = all[3][0];
            all[4][1] = all[3][1];
            all[4][2] = all[3][2];

            all[3][0] = all[5][0];
            all[3][1] = all[5][1];
            all[3][2] = all[5][2];

            all[5][0] = temp[0];
            all[5][1] = temp[1];
            all[5][2] = temp[2];
        }
        else if(p==1){
            char temp[3]={all[2][6], all[2][7], all[2][8]};
            all[2][6] = all[5][6];
            all[2][7] = all[5][7];
            all[2][8] = all[5][8];

            all[5][6] = all[3][6];
            all[5][7] = all[3][7];
            all[5][8] = all[3][8];

            all[3][6] = all[4][6];
            all[3][7] = all[4][7];
            all[3][8] = all[4][8];

            all[4][6] = temp[0];
            all[4][7] = temp[1];
            all[4][8] = temp[2];

        }
        else if(p==2){
            char temp[3]={all[0][6], all[0][7], all[0][8]};
            all[0][6] = all[5][0];
            all[0][7] = all[5][3];
            all[0][8] = all[5][6];

            all[5][0] = all[1][2];
            all[5][3] = all[1][1];
            all[5][6] = all[1][0];

            all[1][0] = all[4][2];
            all[1][1] = all[4][5];
            all[1][2] = all[4][8];

            all[4][2] = temp[2];
            all[4][5] = temp[1];
            all[4][8] = temp[0];
        }
        else if(p==3){
            char temp[3]={all[0][0], all[0][1], all[0][2]};
            
            all[0][0] = all[4][6];
            all[0][1] = all[4][3];
            all[0][2] = all[4][0];

            all[4][0] = all[1][6];
            all[4][3] = all[1][7];
            all[4][6] = all[1][8];

            all[1][6] = all[5][8];
            all[1][7] = all[5][5];
            all[1][8] = all[5][2];

            all[5][2] = temp[0];
            all[5][5] = temp[1];
            all[5][8] = temp[2];
            
        }
        else if(p==4){
            char temp[3]={all[0][0], all[0][3], all[0][6]};
            
            all[0][0] = all[2][0];
            all[0][3] = all[2][3];
            all[0][6] = all[2][6];

            all[2][0] = all[1][0];
            all[2][3] = all[1][3];
            all[2][6] = all[1][6];

            all[1][0] = all[3][8];
            all[1][3] = all[3][5];
            all[1][6] = all[3][2];

            all[3][2] = temp[2];
            all[3][5] = temp[1];
            all[3][8] = temp[0];
        }
        else if(p==5){
            char temp[3]={all[0][2], all[0][5], all[0][8]};
            
            all[0][2] = all[3][6];
            all[0][5] = all[3][3];
            all[0][8] = all[3][0];

            all[3][0] = all[1][8];
            all[3][3] = all[1][5];
            all[3][6] = all[1][2];

            all[1][2] = all[2][2];
            all[1][5] = all[2][5];
            all[1][8] = all[2][8];

            all[2][2] = temp[0];
            all[2][5] = temp[1];
            all[2][8] = temp[2];
        }
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

}




void print_top(){
    for(int i=1;i<=9;i++){
        cout << all[0][i-1];
        if(i%3 == 0) cout << "\n";
    }
}

void print_all(){
    for(int i=1;i<=9;i++){
        cout << all[0][i-1];
        if(i%3 == 0) cout << "\n";
    }

    for(int i=1;i<=9;i++){
        cout << all[1][i-1];
        if(i%3 == 0) cout << "\n";
    }

    for(int i=1;i<=9;i++){
        cout << all[2][i-1];
        if(i%3 == 0) cout << "\n";
    }

    for(int i=1;i<=9;i++){
        cout << all[3][i-1];
        if(i%3 == 0) cout << "\n";
    }

    for(int i=1;i<=9;i++){
        cout << all[4][i-1];
        if(i%3 == 0) cout << "\n";
    }

    for(int i=1;i<=9;i++){
        cout << all[5][i-1];
        if(i%3 == 0) cout << "\n";
    }
}


void solve(){
    int N;
    cin >> N;

    for(int i=0;i<N;i++){
        initial();
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
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    solve();
    return 0;
}