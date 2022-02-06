/* 
 * baekjoon 1149
 * 
 * RGB 거리
 * 
 * https://www.acmicpc.net/problem/1149
 * 
 * 
 */

#include <iostream>
#include <queue>

#define MAX 1001
#define mini(a,b) (a<b ? a : b)
using namespace std;

int value[MAX][3] = {0,};
int result[MAX][3] = {0,};

queue <int> q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    q.push(0);
    q.push(1);
    q.push(2);

    for(int i=0;i<N;i++){
        for(int j=0;j<3;j++){
            cin >> value[i][j];
        }
    }

    result[0][0] = value[0][0];
    result[0][1] = value[0][1];
    result[0][2] = value[0][2];

    for(int i=1;i<N;i++){
        for(int j=0;j<3;j++){
            int temp = q.front();
            q.pop();
            int left = q.front();
            q.pop();
            int right = q.front();
            q.pop();
            result[i][j] = mini(result[i-1][left],result[i-1][right]) + value[i][j];
            q.push(left);
            q.push(right);
            q.push(temp);
        }
    }

    cout << mini(mini(result[N-1][0],result[N-1][1]),result[N-1][2]);

    return 0;
}