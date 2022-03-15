/* 
 * baekjoon 15685
 * 
 * 드래곤 커브
 * 
 * https://www.acmicpc.net/problem/15685
 * 
 * 
 * 
 * 구현 계획
 * 
 * 
 * 드래곤 커브를 DP 방식으로 늘려 나가면서 각 generation 을 저장 한 뒤,
 * 
 * 방향에 맞게 회전시키는 함수를 구현하고,
 * 
 * 입력대로 시작 좌표, 세대와 회전에 맞는 그래프를 연속된 좌표값을 통해 전체 map에 표시한다.
 * (드래곤 커브 표현 예시 : generation 2에 해당하는 gen[2] 값에 {{0,0}, {1,0}, {1,-1}} 이 들어갈 것이다.)
 * (이를 DP 로 앞의 과정을 회전시켜서 마지막 부분에 붙이는 알고리즘을 구현해야한다.)
 * 
 * 이후 정답은 map 을 100 X 100 사이즈 안에서 4개의 작은 정사각형 단위로 모든
 * 
 * 꼭지점이 체크된 정사각형의 갯수를 저장하고 출력한다.
 * 
 * 
 * 
 * 왼쪽으로 90 도 돌리는 동작 = "(이전 세대의 끝의 점을 기준으로 잡고) 위로 뒤집고, y=-x 대칭 이동"
 * 이말인 즉슨, 앞의 좌표의 나열을 위로 뒤집고, y=-x 대칭 이동한 후 이전 세대의 끝점을 모두 더해주면 될 것이다.
 * 
 */


using namespace std;

#include <iostream>
#include <vector>

//→ ↑ ← ↓
int dir[4][2] = {{1,0},{0,-1},{-1,0},{0,1}};


vector<vector<pair<int, int>>> gen;

void make_generation(){
    vector<pair<int,int>> cur_gen;
    cur_gen.push_back({0,0});
    gen.push_back(cur_gen);
    for(int i=1;i<11;i++){
        pair<int, int> temp = cur_gen[i-1];
        int newx= temp.first;
        int newy= temp.second;
    }
}


int main(){

    return 0;
}