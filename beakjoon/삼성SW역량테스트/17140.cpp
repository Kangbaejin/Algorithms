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
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define max_map 110

using namespace std;
int map[max_map][max_map];

int r,c,k;
int find_r, find_c;

//내림차순 (큰 것부터 작은 것의 순서대로 정렬)
bool compare(pair<int,int> a, pair<int,int> b){
    return a.first > b.first;
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
    //각 row 마다 아래의 과정을 수행한다.
    for(int i=1;i<=r;i++){
        //새로 추가될 배열을 만드는 과정
        vector<pair<int, int>> v;
        for(int j=1;j<=c;j++){
            if(map[i][j]==0) continue;
            int temp_idx = 0;
            for(int k=0;k<v.size();k++){
                if(v[k].first==map[i][j]) {
                    temp_idx = k;
                    break;
                }
            }
            //새로운 원소인 경우
            if(temp_idx == 0){
                v.push_back({map[i][j],1});
            }
            //기존에 있는 원소의 경우, second(등장 횟수) 의 값을 증가시킨다.
            else{
                v[temp_idx].second++;
            }
        }

        //해당 벡터를 v.first 를 기준으로 sort 한다.
        sort(v.begin(),v.end(), compare);

        //추가된 새로운 배열을 입력한다.
        int max_size = v.size() > 50 ? 50 : v.size();
        for(int j=1;j<=max_size*2;j+=2){
            map[i][j] = v[j-1].first;
            map[i][j+1] = v[j-1].second;
        }

        c = max_size*2;
    }

    print_map();
}

void C_op(){
    //각 col 마다 아래의 과정을 수행한다.
    for(int j=1;j<=c;j++){
        //새로 추가될 배열을 만드는 과정
        vector<pair<int, int>> v;
        for(int i=1;i<=r;i++){
            if(map[i][j]==0) continue;
            int temp_idx = 0;
            for(int k=0;k<v.size();k++){
                if(v[k].first==map[i][j]) {
                    temp_idx = k;
                    break;
                }
            }
            //새로운 원소인 경우
            if(temp_idx == 0){
                v.push_back({map[i][j],1});
            }
            //기존에 있는 원소의 경우, second(등장 횟수) 의 값을 증가시킨다.
            else{
                v[temp_idx].second++;
            }
        }
        //해당 벡터를 v.first 를 기준으로 sort 한다.
        sort(v.begin(),v.end(), compare);


        //추가된 새로운 배열을 입력한다.
        int max_size = v.size() > 50 ? 50 : v.size();
        for(int i=1;i<=max_size*2;i+=2){
            map[i][j] = v[j-1].first;
            map[i+1][j] = v[j-1].second;
        }

        r = max_size*2;
    }

    print_map();
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
    while(cnt < 100){
        if(check()){
            cout << cnt;
            return;
        }
        if(r>=c) R_op();
        else C_op();
        cnt++;

    }
    if(cnt == 100) cout << -1;
    return;
}

int main(){
    Input();
    solve();
    return 0;
}