/* 
 * baekjoon 16235
 *
 * 나무 재테크
 * 
 * https://www.acmicpc.net/problem/16235
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

deque<int> trees[10][10];
vector<pair<pair<int,int>, int>> dead, parent;

int N,M,K;
int map[10][10];
int S2D2[10][10];

void print_map(){
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cout << map[i][j] << " ";
        }
        cout <<"\n";
    }
}




void Input(){
    cin >> N >> M >> K;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> S2D2[i][j];
            map[i][j] = 5;
        }
    }
    int ix, iy, iz;
    for(int i=0; i<M; i++){
        cin >> ix >> iy >> iz;
        trees[ix-1][iy-1].push_back(iz);
    }
}

/*
 * 봄
 * 나무의 나이를 증가시키는 함수
 * 나이를 증가시킬 때 같은 칸의 어린 나이부터 양분을 흡수하며,
 * 양분을 흡수하지 못하는 나무는 죽는다.
 */

void spring(){
    dead.clear();
    parent.clear();
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(trees[i][j].size()==0) continue;
            //trees deque 안에는 나무의 나이들이 들어있는데 그중 작은 것 부터
            //처리하기 위해 sort 를 진행한다.
            sort(trees[i][j].begin(),trees[i][j].end());
            int size = trees[i][j].size();
            for(int k=0; k<size; k++){
                int a_age = trees[i][j].front();
                trees[i][j].pop_front();
                if(map[i][j] >= a_age){
                    map[i][j]-= a_age;
                    trees[i][j].push_back(a_age+1);
                    //살아 남는 나무들 중 번식 가능한 경우를 미리 체크하여
                    //parent 에 저장 후 가을때 사용
                    if((a_age+1)%5==0){
                        parent.push_back({{i,j},a_age+1});
                    }
                }
                else{
                    dead.push_back({{i,j},a_age});
                }
            }

        }
    }
}

/*
 * 여름
 * 죽은 나무를 양분으로 변하게 하는 함수
 * 죽은 나무의 나이를 2로 나눈 값이 나무가 있던 칸의 양분이 된다.
 */

void summer(){
    int size = dead.size();
    for(int i=0; i<size; i++){
        int x = dead[i].first.first;
        int y = dead[i].first.second;
        int age = dead[i].second;

        map[x][y] += age/2;
    }
}

/*
 * 가을
 * 나무의 나이가 5의 배수라면 번식
 * 인접한 8칸에 모두 번식한다.
 */
int dir[8][2] = {{1,0},{-1,0},{0,1},{0,-1},
                {1,1},{-1,-1},{1,-1},{-1,1}};

void fall(){
    int size = parent.size();
    for(int i=0; i<size; i++){
        int x = parent[i].first.first;
        int y = parent[i].first.second;
        for(int j=0; j<8; j++){
            int newX = x + dir[j][0];
            int newY = y + dir[j][1];
            if(newX<0 || newX >=N || newY<0 || newY >=N) continue;
            //8방향 중 통과된 위치에 나이가 1인 나무 추가
            trees[newX][newY].push_back(1);
        }
    }
}

/*
 * 겨울
 * S2D2 가 땅에 양분을 추가한다. 각 칸에 추가되는 것은 해당 칸의 양분이므로
 * 저장했던 S2D2 값을 더해준다.
 */

void winter(){
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            map[i][j] += S2D2[i][j];
        }
    }
}

/*
 * 1년을 보내는 함수
 */

void one_year(){
    spring();
    summer();
    fall();
    winter();
}

void solve(){
    while(K--){
        one_year();
    }

    int ans=0;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            ans+=trees[i][j].size();
        }
    }

    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    cout.tie(0);
    Input();
    solve();
    return 0;
}