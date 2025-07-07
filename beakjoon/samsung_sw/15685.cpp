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
 * (드래곤 커브 표현 예시 : generation 1에 해당하는 gen[1] 값에 {{0,0}, {1,0}, {1,-1}} 이 들어갈 것이다.)
 * (이를 DP 로 앞의 과정을 회전시켜서 마지막 부분에 붙이는 알고리즘을 구현해야한다.)
 * 
 * 이후 정답은 map 을 100 X 100 사이즈 안에서 4개의 작은 정사각형 단위로 모든
 * 
 * 꼭지점이 체크된 정사각형의 갯수를 저장하고 출력한다.
 * 
 * 
 * 
 * 시계방향으로 90 도 돌리는 동작 = "y=x 대칭 이동, y=0 기준 대칭이동, 이후 평행이동"
 * == rotate(3, vector)
 * 
 * 
 * 회전시킨 것의 끝점 -> 원래의 끝점과 같아져야함.
 * 원래의 끝점 - 회전시킨 것의 끝점 = gap
 * 
 * 회전시킨 것에 모든 좌표에 gap 을 더해주면 회전시킨 것의 끝점 = 원래의 끝점
 * 
 * 이런 방식으로 회전시킨 것과 원래 것을 이어준다.
 * 
 * 
 */


using namespace std;

#include <iostream>
#include <vector>

bool map[101][101];

vector<vector<pair<int, int>>> gen;

void rotate(int d, vector<pair<int,int>> &v){
    //d=0 일땐 그대로
    if(d==0) return;
    //d=1 일땐 위 -> 왼쪽으로 반시계 회전 == y=x 대칭 & x = 0 대칭
    //d=2 일땐 y = 0 대칭, x = 0 대칭
    //d=3 일땐 y = x 대칭 & y = 0 대칭

    for(int i=0; i<v.size();i++){
        int x = v[i].first;
        int y = v[i].second;
        int temp;

        if(d==1){
            temp = x;
            x = y;
            y = temp;

            y = -y;

            v[i].first = x;
            v[i].second = y;
        }
        else if(d==2){
            x = -x;
            y = -y;

            v[i].first = x;
            v[i].second = y;
        }
        else if(d==3){
            temp = x;
            x = y;
            y = temp;

            x = -x;

            v[i].first = x;
            v[i].second = y;
        }
    }

    return;
}

void x_y_dir_gen(int x, int y, int d, int g){
    vector<pair<int,int>> load_gen(gen[g]);
    rotate(d, load_gen);
    for(int i=0;i<load_gen.size();i++){
        load_gen[i].first += x;
        load_gen[i].second += y;
    }

    for(int i=0;i<load_gen.size();i++){
        int newx = load_gen[i].first;
        int newy = load_gen[i].second;
        if(newx<0 || newx>100 || newy<0 || newy>100)    continue;
        else{
            map[newx][newy] = true;
        }
    }
}


void make_generation(){
    vector<pair<int,int>> initial;
    initial.push_back({0,0});
    initial.push_back({1,0});
    gen.push_back(initial);
    for(int i=1;i<11;i++){
        vector<pair<int,int>> cur_gen = gen[i-1]; //벡터 복사
        vector<pair<int,int>> copy_v(gen[i-1]);   //벡터 복사
        rotate(3,copy_v);

        pair<int, int> gap;
        gap.first =0;
        gap.second=0;
        gap.first = cur_gen[cur_gen.size()-1].first - copy_v[copy_v.size()-1].first;
        gap.second = cur_gen[cur_gen.size()-1].second - copy_v[copy_v.size()-1].second;
        for(int j=0;j<copy_v.size();j++){
            copy_v[j].first += gap.first;
            copy_v[j].second += gap.second;
        }

        for(int j=copy_v.size()-2;j>=0;j--){
            cur_gen.push_back({copy_v[j].first,copy_v[j].second});
        }

        gen.push_back(cur_gen);
    }
}


void check_1x1_rect(){
    int ans = 0;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(map[i][j] && map[i+1][j] && map[i][j+1] && map[i+1][j+1]){
                ans++;
            }
        }
    }
    cout << ans;
    return;
}

int main(){

    make_generation();
    // vector<pair<int,int>> temp = gen[3];

    // for(int i=0;i<temp.size();i++){
    //     cout << "{" << temp[i].first << ", " << temp[i].second << "} ";
    // }

    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        int x,y,d,g;
        cin >> x >> y >> d >> g;
        x_y_dir_gen(x,y,d,g);
    }

    check_1x1_rect();

    return 0;
}