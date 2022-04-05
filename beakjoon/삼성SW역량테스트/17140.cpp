/* 
 * baekjoon 17140
 *
 * 이차원 배열과 연산
 * 
 * https://www.acmicpc.net/problem/17140
 * 
 * 
 * 행 또는 열이 100개 이상으로 넘어가는 경우 처음 100개를 제외한 나머지는 버린다.
 * 0 인 값은 무시해야한다.
 * 
 * 
 * 
 * OP 안쪽의 등장 횟수를 찾기위해 벡터 원소의 처음부터 끝까지 탐색하는데
 * 만약 시간초과가 난다면 이를 이분탐색으로 바꿔야 하는 가?
 * 아마 input 의 사이즈가 100 이하라 시간초과가 날 것 같지는 않다.
 * 
 * 
 * 현재 r_op 의 333 경우 -> 3 3 이 나와야하는데 결과는 3 3 3 이 입력된다. 해당 연산이 잘 이루어지지 않고 있다.
 * vector v 에 넣는 것은 잘 들어 가는 것 같은데,
 * map 에 넣는 과정에서 오류가 있는 것 같다.
 * 
 * 넣기 전에 이전의 배열을 초기화 하는 과정이 필요했다!
 * 이전에 3 3 3 이 입력된 뒤 초기화 되지 않아 앞의 3 3 이 입력되었지만 이전에 입력되어 있던 3이 남아서 출력된 것이다.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define max_map 110

using namespace std;
int map[max_map][max_map];

int r,c,k;
int find_r, find_c;

//오름차순 
bool compare(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}

void print_map(){
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}


void R_op(){
    int max_length=-1;
    //각 row 마다 아래의 과정을 수행한다.
    for(int i=1;i<=r;i++){
        //새로 추가될 배열을 만드는 과정
        vector<pair<int, int>> v;
        int check_ary[max_map] = {0,};
        for(int j=1;j<=c;j++) check_ary[map[i][j]]++;
        for(int j=1;j<max_map;j++){
            if(check_ary[j] == 0)   continue;
            v.push_back({j,check_ary[j]});
        }


        //해당 벡터를 v.second 를 기준으로 sort 한다.
        sort(v.begin(),v.end(), compare);
        //새로운 배열 입력 전에 이전의 배열을 0으로 초기화한다.
        for(int j=1;j<=c;j++) map[i][j]=0;

        //추가된 새로운 배열을 입력한다.
        int max_size = v.size() > 50 ? 50 : v.size();
        for(int j=1;j<max_size*2;j+=2){
            map[i][j] = v[(j-1)/2].first;
            map[i][j+1] = v[(j-1)/2].second;
        }

        if(max_length<max_size) max_length = max_size;
    }

    c = max_length*2;
}

void C_op(){
    int max_length=-1;
    //각 row 마다 아래의 과정을 수행한다.
    for(int j=1;j<=c;j++){
        //새로 추가될 배열을 만드는 과정
        vector<pair<int, int>> v;
        int check_ary[max_map] = {0,};
        for(int i=1;i<=r;i++) check_ary[map[i][j]]++;
        for(int i=1;i<max_map;i++){
            if(check_ary[i] == 0)   continue;
            v.push_back({i,check_ary[i]});
        }


        //해당 벡터를 v.second 를 기준으로 sort 한다.
        sort(v.begin(),v.end(), compare);

        //새로운 배열 입력 전에 이전의 배열을 0으로 초기화한다.
        for(int i=1;i<=r;i++) map[i][j]=0;
        
        //추가된 새로운 배열을 입력한다.
        int max_size = v.size() > 50 ? 50 : v.size();
        for(int i=1;i<max_size*2;i+=2){
            map[i][j] = v[(i-1)/2].first;
            map[i+1][j] = v[(i-1)/2].second;
        }

        if(max_length<max_size) max_length = max_size;
    }

    r = max_length*2;
}


bool check(){
    if(map[find_r][find_c] == k){
        return true;
    }
    return false;
}

void Input(){
    cin >> find_r >> find_c >> k;
    c = 3;
    r = 3;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin >> map[i][j];
        }
    }
}


void solve(){
    int cnt = 0;
    while(cnt <= 100){
        if(check()){
            cout << cnt;
            return;
        }
        if(r>=c) R_op();
        else C_op();
        cnt++;

    }
    if(cnt > 100) cout << -1;
    return;
}

int main(){
    Input();
    solve();
    return 0;
}