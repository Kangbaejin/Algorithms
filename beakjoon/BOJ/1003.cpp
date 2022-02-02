/* 
 * baekjoon 1003
 * 
 * 피보나치 함수
 * 
 * https://www.acmicpc.net/problem/1003
 * 
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

int fib[41];

vector <pair<int,int>> v;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    fib[0] = 0;
    fib[1] = 1;
    v.push_back({1,0});
    v.push_back({0,1});

    
    for(int i=2;i<41;i++){
        fib[i] = fib[i-1] + fib[i-2];
        v.push_back({v[i-1].first+v[i-2].first, v[i-1].second+v[i-2].second});
    }

    int N, temp;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> temp;
        cout << v[temp].first << " " << v[temp].second << '\n';
    }

    return 0;
}