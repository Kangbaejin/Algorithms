/* 
 * baekjoon 2580
 * 
 * 스도쿠
 * 
 * https://www.acmicpc.net/problem/2580
 * 
 * 
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int all[9][9];
int check[10];
int N;
bool is_print = false;



void print_sudoku(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout << all[i][j] << " ";
        }
        cout << "\n";
    }

    return;
}

void solve(int x, int y){
    if(is_print) return;
    else if(x==9 && y == 0){
        print_sudoku();
        is_print = true;
        return;
    }
    else if(all[x][y]!=0){
        if(y<8) solve(x,y+1);
        else solve(x+1,0);

        return;
    }

    else{
        for(int k=1;k<=9;k++){

            for(int i=0;i<=9;i++)    check[i] = 0;

            for(int i=0;i<9;i++){
                check[all[i][y]]=1;
            }
            for(int i=0;i<9;i++){
                check[all[x][i]]=1;
            }

            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    check[all[(x/3)*3+i][(y/3)*3+j]]=1;
                }
            }

            if(check[k]==0){
                all[x][y] = k;
                if(y<8) solve(x,y+1);
                else solve(x+1,0);
                all[x][y] = 0;
            }
        }
    }


    return;
}



int main(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin >> all[i][j];
        }
    }

    solve(0,0);

    return 0;
}