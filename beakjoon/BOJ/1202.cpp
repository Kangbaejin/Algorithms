/* 
 * baekjoon 1202
 * 
 * 보석 도둑
 * 
 * https://www.acmicpc.net/problem/1202
 * 
 * 
 */

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct compare{
    bool operator()(pair<int,int> a, pair<int,int> b){
        if(a.second == b.second){
            return a.first > b.first;
        }
        else{
            return a.second < b.second;
        }
    }
};


priority_queue<pair<int,int>, vector<pair<int, int>>, compare> jewels;
vector<int> bags;
int N, K;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    long long sum = 0;

    int mass, value;
    for(int i=0;i<N;i++){
        cin >> mass >> value;
        jewels.push({mass,value});
    }

    int x;
    for(int i=0;i<K;i++){
        cin >> x;
        bags.push_back(x);
    }

    sort(bags.begin(),bags.end());

    while(!jewels.empty()){
        int wrong_cnt=0;
        pair<int,int> goal = jewels.top();
        for(int i=0;i<K;i++){
            if(bags[i]>=goal.first){
                sum+=goal.second;
                jewels.pop();
                bags[i] = 0;
                break;
            }
            else{
                wrong_cnt++;
            }
        }
        if(wrong_cnt==K){
            jewels.pop();
        }
    }

    cout << sum;

    return 0;

}