/* baekjoon 11651
 *
 * 좌표 정렬하기 2
 * 
 * https://www.acmicpc.net/problem/11651
 * 
 * 
 * sort 의 compare 함수 부분을 수정하여,
 * 원하는 순서로 정렬을 진행한다.
 * 
 * 
 * endl 은 출력 버퍼를 비워야해서 느리다. endl 대신 '\n' 사용했다.
 * 
 * 
 * c 의 stdio와 cpp의 iostrean을 동기화 하는 역할을 하는 아래의 코드를 이용할 수 있다.
 * cin.sync_with_stdio(false);
 * 이는 c의 버퍼를 사용하지 않기 때문에 실행 속도는 빨라질 수 있다.
 * 하지만 이 문장을 실행하면, 버퍼가 분리되었기 때문에,
 * c의 scanf, gets, printf, puts 같은 함수들을 사용하면 안된다.
 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool compare(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second)
        return a.first < b.first;
    
    return a.second < b.second;
}

int main(){
    int N, p1, p2;
    cin >> N;

    vector<pair<int,int>> v1;

    for(int i=0;i<N;i++){
        cin >> p1 >> p2;
        v1.push_back(make_pair(p1,p2));
    }

    sort(v1.begin(),v1.end(),compare);
    

    for(int i=0;i<N;i++){
        cout << v1[i].first << " " << v1[i].second << '\n';
    }

    return 0;
}  