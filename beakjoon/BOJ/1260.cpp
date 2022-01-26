/* 
 * baekjoon 1260
 * 
 * DFS와 BFS
 * 
 * https://www.acmicpc.net/problem/1260
 * 
 * 
 */

#include <iostream>
#include <queue>

using namespace std;

int N,M,V;
int mat[1001][1001];
bool chk[1001];
bool chk2[1001];

void dfs(int s){
	chk[s]=true;
	cout << s << " ";
	for(int i=1; i<=N; i++){
		if(mat[s][i]==1 && chk[i]==false){
			dfs(i);
		}
	}
}

void bfs(int s){
	queue<int> q;
	q.push(s);
	chk2[s]=true;
	while(!q.empty()){
		int x = q.front();
		cout << x << " ";
		q.pop();
		for(int i=1;i<=N;i++){
			if(mat[x][i]==1 && chk2[i]==false){
				q.push(i);
				chk2[i]=true;
			}
		}
	}
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> N >> M >> V;
	for(int i=0; i<M; i++){
		int S,E;
		cin >> S >> E;
		mat[S][E]=1;
		mat[E][S]=1;
	}
	dfs(V);
	cout << "\n";
	bfs(V);
}