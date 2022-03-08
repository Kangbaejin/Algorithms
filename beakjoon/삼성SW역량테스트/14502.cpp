/* 
 * baekjoon 1826
 * 
 * 연료 채우기
 * 
 * https://www.acmicpc.net/problem/1826
 * 
 * 
 * 
 */

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX 9
using namespace std;

int N, M;
int value[MAX][MAX] = {0,};
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

queue<pair<int, int>> q;
vector<pair<int,int>> v;
int cnt = 0;




int safe_size(void){
    cnt = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(value[i][j]==0){
                cnt++;
            }
        }
    }

    return cnt;
}

void print_value(void){
    cnt = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout << value[i][j] << " ";
        }
        cout << "\n";
    }
    return;
}

void virus_spread(void){
	while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        
		q.pop();

		for(int i=0; i<4; i++){
            int newX = x + dir[i][0];
			int newY = y + dir[i][1];
            //배열 벗어나면 continue 처리
			if(newX<0 || newX>=N || newY<0 || newY>=M) continue;

            //새로운 좌표가 빈칸 일때
            if(value[newX][newY] == 0){
                value[newX][newY] = 2;
                q.push({newX,newY});
            }
		}
	}
	return;
}


void solve(void){
    int max_safe_size = 0;
    vector<int> add3;
    for(int i=0;i<v.size();i++){
        if(i<=2) {
            add3.push_back(1);
        }
        else {
            add3.push_back(0);
        }
    }

    do{
        for(int i=0;i<v.size();i++){
            int x = v[i].first;
            int y = v[i].second;
            value[x][y] = add3[i];
        }
        //print_value();
        //cout << "\n";
        virus_spread();
        //print_value();
        int temp_size = safe_size();
        if(max_safe_size<temp_size){
            max_safe_size = temp_size;
            print_value();
        }

        //break;

    }while(prev_permutation(add3.begin(), add3.end()));

    cout << max_safe_size;

    return;
}





int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int temp = 0;
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> temp;
            value[i][j] = temp;
            if(value[i][j]==2){
                q.push({i,j});
            }
            if(value[i][j]==0){
                v.push_back({i,j});
            }
        }
    }

    solve();

    return 0;
}