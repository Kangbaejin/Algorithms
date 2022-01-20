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
int check[10];
bool *flag;
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

void solve(int x, int y){
    for(int i=0;i<9;i++)    check[i] = 0;

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

    for(int i=1;i<=9;i++){
        if(check[i]==0){
            all[x][y] = i;
            return;
        }
    }

    return;
}




void dfs(int depth){
    if(is_print)    return;
    if(depth > N)   return;
    if(depth == N){
        print_sudoku();
        is_print = true;
        return;
    }

    for(int i=0;i<N;i++){
        if(flag[i]) continue;
        flag[i] = true;
        solve(v[i].first,v[i].second);
        dfs(depth+1);
        flag[i] = false;
        all[v[i].first][v[i].second] = 0;
    }

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

    cout << "\n";


    N = v.size();
    flag = new bool[N];

    for(int i=0;i<N;i++){
        flag[i] = false;
    }

    dfs(0);

    return 0;
}