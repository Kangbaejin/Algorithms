/* 
 * baekjoon 15683
 * 
 * 감시
 * 
 * https://www.acmicpc.net/problem/15683
 * 
 * 
 */


#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define m_max 8
using namespace std;

struct cctv{
	int type, x, y;
};

int N,M;
int map[m_max][m_max];
vector<cctv> cam_vector;
int ans = -1;


void Input(){
	cin >> N >> M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin >> map[i][j];
			if(map[i][j]!=0 && map[i][j]!=6){
				cam_vector.push_back({map[i][j],i,j});
			}
		}
	}
}


void watch(int d, int x, int y){
	//dfs 를 진행할 때 방향 조정을 위해 나머지 연산
	d %= 4;
	switch (d) {
		//위
		case 0:
			for(int i=x-1; i>=0; i--){
				if(map[i][y] == 6){
					break;
				}
				else if(map[i][y] == 0){
					map[i][y] = -1;
				}
			}
			break;
		//오른쪽
		case 1:
			for(int i=y+1; i<M; i++){
				if(map[x][i] == 6){
					break;
				}
				else if(map[x][i] == 0){
					map[x][i] = -1;
				}
			}
			break;
		//아래
		case 2:
			for(int i=x+1; i<N; i++){
				if(map[i][y] == 6){
					break;
				}
				else if(map[i][y] == 0){
					map[i][y] = -1;
				}
			}
			break;

		//왼쪽 (case 3)
		default:
			for(int i=y-1; i>=0; i--){
				if(map[x][i] == 6){
					break;
				}
				else if(map[x][i] == 0){
					map[x][i] = -1;
				}
			}
			break;
	}
}


//DFS 를 통해 각 cam 하나씩 접근한다.
//Input에서 저장한 cam_vector를 이용한다.
int cam_settings_num[6] = {0, 4, 2, 4, 4, 1};
void DFS(int idx_cam){
	if(idx_cam==cam_vector.size()){
		int bs=0;
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				if(map[i][j]==0) bs++;
			}
		}
		if(ans == -1) ans = bs;
		else ans = min(bs, ans);
		return;
	}

	int copy_map[m_max][m_max];

	int type = cam_vector[idx_cam].type;
	int x = cam_vector[idx_cam].x;
	int y = cam_vector[idx_cam].y;
	for(int i=0;i<cam_settings_num[type];i++){
		//이전 상태 저장
		memcpy(copy_map, map, sizeof(int)*m_max*m_max);
		
		switch (type) {
			//각 캠 종류마다 다른 감시 시행
			case 1:
				watch(i,x,y);
				break;
			case 2:
				watch(i,x,y);
				watch(i+2,x,y);
				break;
			case 3:
				watch(i,x,y);
				watch(i+1,x,y);
				break;
			case 4:
				watch(i,x,y);
				watch(i+1,x,y);
				watch(i+2,x,y);
				break;
			default:
				watch(i,x,y);
				watch(i+1,x,y);
				watch(i+2,x,y);
				watch(i+3,x,y);
				break;
		}
		DFS(idx_cam+1);
		//원래 상태로 복원
		memcpy(map, copy_map, sizeof(int)*m_max*m_max);
	}
}

int main(){
	Input();
	DFS(0);
	cout << ans;
	return 0;
}