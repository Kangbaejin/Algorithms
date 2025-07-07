/* 
 * baekjoon 1956
 * 
 * 운동
 * 
 * https://www.acmicpc.net/problem/1956
 * 
 * 
 */

#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 9999999

using namespace std;
const int max_v = 401;
int dist[max_v][max_v];

int v,e;

void print_ary(int ary[][max_v]){
    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++){
            cout << ary[i][j] << " ";
        }
        cout << "\n";
    }
}


int main(){
    //Input
    cin >> v >> e;
    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++){
            dist[i][j]=INF;
        }
    }

    //Init dist
    for(int i=0; i<e; i++){
        int st, ed, d;
        cin >> st >> ed >> d;
        dist[st][ed] = d;
    }

    //floyd algorithm
    for(int k=1; k<=v; k++){
        for(int i=1;i<=v;i++){
            for(int j=1;j<=v;j++){
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }

    //find shortest cycle
    int ans = INF;
    for(int i=1;i<=v;i++){
        ans = min(ans, dist[i][i]);
    }
    if(ans == INF) ans = -1;
    cout << ans;

    return 0;
}
