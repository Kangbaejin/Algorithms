/* 
 * baekjoon 1826
 * 
 * 연료 채우기
 * 
 * https://www.acmicpc.net/problem/1826
 * 
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//oil 내림차순으로 정렬
struct compare1{
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
    }
};


//distance 오름순으로 정렬
struct compare2{
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.first > b.first;
    }
};


priority_queue<pair<int,int>, vector<pair<int,int>>, compare2> distance_order;
priority_queue<pair<int,int>, vector<pair<int,int>>, compare1> oil_order;

vector<pair<int, int>> value;

vector<int> list;
int N;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    int dist, max_oil;
    for(int i=0;i<N;i++){
        cin >> dist >> max_oil;
        distance_order.push({dist,max_oil});
    }

    int goal, present_oil, cnt = 0;
    cin >> goal >> present_oil;

    pair<int, int> temp;
    while(present_oil < goal){
        while(!distance_order.empty() && present_oil >= distance_order.top().first){
            temp = distance_order.top();

            //현재 가진 연료로 갈 수 있는 모든 주유소를 oil_order queue 에 넣는다.
            //이때 가진 연료가 많은 순서대로 정렬된다.
            //갈 수 있는 곳 중에서 가장 많은 연료를 가진 주유소를 선택하게 된다.
            oil_order.push(temp);
            distance_order.pop();
        }
        if(oil_order.empty()){
            //만약 갈 수 있는 주유소가 없다면 경로 진행이 불가하다는 것을 의미한다.
            cout << -1;
            return 0;
        }
        //연료 보유량이 가장 많은 곳으로 향하여 연료를 보충한다.
        int oil_supply = oil_order.top().second;
        oil_order.pop();
        present_oil += oil_supply;
        cnt++;
    }


    cout << cnt;

    return 0;
}