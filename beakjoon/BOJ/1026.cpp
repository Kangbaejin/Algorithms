/* baekjoon 1026
 *
 * 보물
 * 
 * https://www.acmicpc.net/problem/1026
 * 
 * 
 * 그리디 알고리즘, 정렬
 * 
 * 항상 변수 사용 전에 초기화 및 할당 확인 하고 사용하기
 * 
 */



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> v1(n);
    vector<int> v2(n);

    for(int i=0;i<v1.size();i++){
        cin >> v1[i];
    }

    for(int i=0;i<v2.size();i++){
        cin >> v2[i];
    }

    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end(),greater<int>());

    int answer;
    answer = 0;
    for(int i=0;i<v1.size();i++){
        answer += v1[i]*v2[i];
    }

    cout << answer;

    return 0;
}