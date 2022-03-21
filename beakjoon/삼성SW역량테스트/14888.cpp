/* 
 * baekjoon 14888
 * 
 * 연산자 끼워넣기
 * 
 * https://www.acmicpc.net/problem/14888
 * 
 * 
 * 
 * 구현 계획
 * 0 1 2 3
 * + - x /
 * 
 * 간단하게 전역변수와 백트래킹으로 잘 구현된 것 같다.
 * https://www.acmicpc.net/source/33257371
 * 
 * 브루트 포스 알고리즘으로 모든 조건에 해당하는 경우를 함수 호출로 실행하고,
 * n level 이 되었을 때 max 와 min 값을 업데이트 하는 방식이다.
 * https://www.acmicpc.net/source/20380974
 * 
 */


#include <iostream>
#include <vector>
#include <algorithm>
#define one_billion 1000000000
using namespace std;



int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    vector<int> value;
    vector<int> order;
    int N, temp;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> temp;
        value.push_back(temp);
    }

    for(int i=0;i<4;i++){
        cin >> temp;
        while(temp--){
            order.push_back(i);
        }
    }


    long long max_v = -one_billion, min_v = one_billion, sum = 0;

    do{
        sum = value[0];
        for(int i=1;i<=order.size();i++){
            switch(order[i-1]){
                case 0:
                    sum+=value[i];
                    break;
                case 1:
                    sum-=value[i];
                    break;
                case 2:
                    sum*=value[i];
                    break;
                case 3:
                    sum/=value[i];
                    break;
                default:
                    continue;
            }
        }
        if(sum>max_v) max_v = sum;
        if(sum<min_v) min_v = sum;

    }while(next_permutation(order.begin(),order.end()));

    cout << max_v << "\n" << min_v;
    return 0;
}