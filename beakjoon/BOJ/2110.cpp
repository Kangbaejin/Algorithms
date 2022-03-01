/* 
 * baekjoon 2110
 * 
 * 공유기 설치
 * 
 * https://www.acmicpc.net/problem/2110
 * 
 * 
 * 
 */



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int N, C;
vector<int> value;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> C;

    int x;
    for(int i=0;i<N;i++){
        cin >> x;
        value.push_back(x);
    }

    sort(value.begin(),value.end());

    int start = 0;
    int end = value[N-1];

    while(start<=end){
        int mid = (start+end)/2;
        int wifi_cnt = 1;
        int before = value[0];
        for(int i=1;i<N;i++){
            if(value[i]-before>=mid){
                wifi_cnt++;
                before = value[i];
            }
        }


        if(wifi_cnt >= C){
            start = mid + 1;
        }

        if(wifi_cnt < C){
            end = mid - 1;
        }
    }

    cout << end;

    return 0;
}
