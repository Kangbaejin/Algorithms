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
vector<pair<int,int>> v;
int N;

bool is_print = false;



void print_sudoku(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout << all[i][j] << " ";
        }
        cout << "\n";
    }
}

bool solve(int x, int y){

    for(int i=0;i<9;i++){
        if(all[i][y]==all[x][y]){
            if(i==x) continue;
            else return false;
        }
    }
    for(int i=0;i<9;i++){
        if(all[x][i]==all[x][y]){
            if(i==y) continue;
            else return false;
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(all[(x/3)*3+i][(y/3)*3+j]==all[x][y]){
                if((x/3)*3+i==x && (y/3)*3+j == y){
                    continue;
                }
                else{
                    return false;
                }
            }
        }
    }

    return true;
}




void dfs(int depth){
    if(is_print)    return;
    if(depth == v.size()){
        print_sudoku();
        is_print = true;
        return;
    }

    int x = v[depth].first;
    int y = v[depth].second;

    for(int i=1;i<=9;i++){
        all[x][y] = i;
        if(solve(x,y))
            dfs(depth+1);
    }

    all[x][y]=0;

    return;
}


int main(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin >> all[i][j];
            if(all[i][j]==0)
                v.push_back({i,j});
        }
    }


    dfs(0);

    return 0;
}