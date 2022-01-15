/* 
 * baekjoon 1037
 * 
 * 약수
 * 
 * https://www.acmicpc.net/problem/1037
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,x;
    cin >> n;

    vector <int> v;
    for(int i=0;i<n;i++){
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(),v.end(), less<int>());

    long long answer = v.front() * v.back();

    cout << answer;
    return 0;

}