/* 
 * baekjoon 13305
 * 
 * 주유소
 * 
 * https://www.acmicpc.net/problem/13305
 * 
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<long long> way_distance;
vector<long long> gas_value;

int N;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    
    long long x=0;
    for(int i=0;i<N-1;i++){
        cin >> x;
        way_distance.push_back(x);
    }

    for(int i=0;i<N;i++){
        cin >> x;
        gas_value.push_back(x);
    }

    long long temp = gas_value[0];

    long long ans = 0;
    for(int i=0;i<N;i++){
        if(temp>gas_value[i]){
            temp = gas_value[i];
        }
        else{
            gas_value[i] = temp;
        }
        ans += temp*way_distance[i];
    }


    cout << ans;

    return 0;

}