/* 
 * baekjoon 2606
 * 
 * 바이러스
 * 
 * https://www.acmicpc.net/problem/2606
 * 
 * 
 */

#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int N,M;
bool chk[101];
vector<vector<int>> mat(101);

int bfs(int s){
	int ret = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int i=0; i<mat[x].size();i++){
			if(chk[mat[x][i]]==false){
				chk[mat[x][i]]=true;
				ret++;
				q.push(mat[x][i]);
			}
		}
	}
	return ret;
}

int main(){
	scanf("%d %d", &N,&M);
	for(int i=0; i<M; i++){
		int S,E;
		scanf("%d %d", &S, &E);
		mat[S].push_back(E);
		mat[E].push_back(S);
	}
	printf("%d\n",bfs(1)-1);
}