/* 
 * baekjoon 2636
 * 
 * 영역 구하기
 * 
 * https://www.acmicpc.net/problem/2636
 * 
 * 
 * 앞쪽의 직사각형들의 범위를 입력받아 설정해주는 부분을 제외하면
 * 2667 문제의 풀이와 같은 맥락으로 풀 수 있는 문제였다.
 * 
 * 직사각형으로 값이 변하지 않은 1의 값일때 탐색을 시작하여,
 * 영역의 넓이를 구하고 해당 영역의 넓이를 vector 에 넣어주며
 * 영역의 넓이들을 기록하였고, sort 알고리즘을 이용하여
 * 순서대로 출력하였다.
 * 
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAX 101

using namespace std;
 

int M,N,K, cnt;
int value[MAX][MAX]={0,};
bool visited[MAX][MAX];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
vector<int> ans;

void dfs(int x, int y){
    visited[x][y] = true;
    cnt++;
    for(int i=0;i<4;i++){
        int newX = x + dir[i][0];
        int newY = y + dir[i][1];

        if((0<=newX && newX < M) && (0 <=newY && newY < N)){
            if(value[newX][newY]==1 && !visited[newX][newY]){
                dfs(newX, newY);
            }
        }
    }
}




int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N >> K;
    
    //활성화 할 범위의 값을 1로 초기화
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            value[i][j]=1;
        }
    }

    //주어진 직사각형 범위를 0으로 변경
    int ary[4];
    for(int i=0;i<K;i++){
        for(int j=0;j<4;j++){
            cin >> ary[j];
        }

        for(int j=ary[1];j<ary[3];j++){
            for(int k=ary[0];k<ary[2];k++){
                value[j][k] = 0;
            }
        }
    }

    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(value[i][j]==1 && !visited[i][j]){
                cnt = 0;
                dfs(i,j);
                ans.push_back(cnt);
            }
        }
    }


    sort(ans.begin(),ans.end());

    cout << ans.size() << '\n';
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }

    return 0;
}
