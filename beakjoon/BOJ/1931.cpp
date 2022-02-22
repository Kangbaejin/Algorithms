/* 
 * baekjoon 1931
 * 
 * 회의실 배정
 * 
 * https://www.acmicpc.net/problem/1931
 * 
 * 
 * 회의가 끝나는 시간으로 정렬하여 끝나는 시간이 빠른 스케쥴 부터 처리한다.
 * 한 회의를 처리 한 후, 다음 스케줄을 시작할 수 있는 회의를 처리한다.
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;


vector<pair<int, int>> value;

bool compare (pair<int, int> a, pair<int, int> b) {
  if(a.second == b.second)  return a.first < b.first;
  else  return a.second < b.second;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    int start, end, max = 0;

    for(int i=0;i<N;i++){
        cin >> start >> end;
        value.push_back({start, end});
    }

    sort(value.begin(),value.end(), compare);

    int cnt = 1;
    int end_time = value[0].second;

    for(int i=1;i<N;i++){
        if(end_time <= value[i].first){
            end_time = value[i].second;
            cnt++;
        }
    }

    cout << cnt;


    return 0;
}
