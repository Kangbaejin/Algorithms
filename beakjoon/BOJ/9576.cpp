/* 
 * baekjoon 9576
 * 
 * 책 나눠주기
 * 
 * https://www.acmicpc.net/problem/9576
 * 
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}



vector<pair<int, int>> v;

int test, N, M, a, b;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> test;

    while(test--){
        
        cin >> N >> M;
        v.clear();
        for(int i=0;i<M;i++){
            cin >> a >> b;
            v.push_back({a,b});
        }

        sort(v.begin(),v.end(), compare);

        int ans = 0;
        bool check[1001] = {false,};
        //정렬한 순서대로 진행하며, 책을 나눠줬는지 아닌지 체크하면서 진행
        for(int i=0;i<M;i++){
            for(int j=v[i].first;j<=v[i].second;j++){
                if(!check[j]){
                    check[j] = true;
                    break;
                }
            }
        }
        //체크 된 책이라면, 나눠 준 책이다.  1~N 까지 확인
        for(int i=1;i<=N;i++){
            if(check[i]) ans++;
        }
        cout << ans << '\n';
    }


    return 0;

}