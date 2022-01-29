/* 
 * baekjoon 2667
 * 
 * 숨바꼭질
 * 
 * https://www.acmicpc.net/problem/2667
 * 
 * 
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX 100001


vector<bool> visited(MAX, false);
int ans;
int N, K;

void solve(int n, int depth){
    queue<pair<int, int>> q;
    q.push({n, depth});
    while(!q.empty()){
        n = q.front().first;
        depth = q.front().second;
        q.pop();
        if(n == K){
            cout << depth;
            return;
        }
        else if(!visited[n]){
            visited[n]=true;
            if(n*2 < MAX && n < K)
                q.push({n*2, depth+1});
            if(n < K)
                q.push({n+1, depth+1});
            if(n > 0)
                q.push({n-1, depth+1});
        }
    }

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> N >> K;
    solve(N,0);

    return 0;
}