/* 
 * baekjoon 2636
 * 
 * 치즈
 * 
 * https://www.acmicpc.net/problem/2636
 * 
 * 
 */

#include <iostream>
#define MAX 101

using namespace std;


int M,N;
int mat[MAX][MAX];


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N;

    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cin >> mat[i][j];
        }
    }



    return 0;
}
