/* 
 * baekjoon 2217
 * 
 * 로프
 * 
 * https://www.acmicpc.net/problem/2217
 * 
 *
 * 로프가 강한 것 부터 더해나가는 데 아래의 식을 만족해야 한다.
 * 더해진 로프 중 가장 작은 값 * 더해진 로프의 총 갯수 = 최대 무게 
 * 
 * 예를 들면, 입력이
 * 
 * 4
 * 30
 * 10
 * 9
 * 8
 * 
 * 일 때,
 * 
 * 최대 하중은 30 -> 20 -> 27 -> 32 가 된다.
 * 
 * 다른 강한 로프들도 결국 가장 약한 로프의 무게 만큼의 무게만 들 수 밖에 없다.
 * 그 이상의 무게를 들면 가장 약한 로프가 끊어 지기 때문이다.
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;


vector<int> value;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    int x;

    for(int i=0;i<N;i++){
        cin >> x;
        value.push_back(x);
    }

    sort(value.begin(),value.end(), greater<int>());


    int count = 1;
    int ans = 0;
    for(int i=0;i<N;i++){
        if(value[i]*count > ans){
            ans = value[i]*count;
        }
        count++;
    }

    cout << ans;

    return 0;
}
