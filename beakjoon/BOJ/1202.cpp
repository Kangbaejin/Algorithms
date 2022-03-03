/* 
 * baekjoon 1202
 * 
 * 보석 도둑
 * 
 * https://www.acmicpc.net/problem/1202
 * 
 * 
 * 아래 링크를 참고했다.
 * https://jaimemin.tistory.com/760
 * 
 * 보석의 무게와 가격을 우선순위 queue 로 정렬하여 문제를 해결하는 것이아니라,
 * 
 * 가방 무게와 보석 무게 순으로 정렬 한 뒤,
 * 가방에 넣을 수 있는 보석의 가격을 우선순위 queue 에 넣어 가장 가격이 큰 보석들을
 * 챙기는 방식으로 구현하여 해결할 수 있었다.
 * 
 */

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 300000

using namespace std;



vector<pair<int,int>> jewels;
vector<int> bags;
priority_queue<int> pq;

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
        jewels.push_back({mass,value});
    }

    int x;
    for(int i=0;i<K;i++){
        cin >> x;
        bags.push_back(x);
    }

    sort(bags.begin(),bags.end());
    sort(jewels.begin(),jewels.end());  //보석 무게 기준 오름차순 정렬


    int index = 0;
    for(int i=0;i<K;i++){
        //i 번째 가방에 넣을 수 있는 보석의 가격을 pq 에 모두 담는다.
        while(index<N && jewels[index].first<=bags[i]){
            pq.push(jewels[index++].second);
        }
        //무게 제한이 적은 것 부터 체크했으므로,
        //만약 무게가 적음에도 비싼 광석도 놓치지 않고 담을 수 있다.
        if(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
    }


    cout << sum;


    return 0;

}