/* baekjoon 10816
 *
 * 숫자 카드 2
 * 
 * https://www.acmicpc.net/problem/10816
 * 
 * 
 * 
 * 
 * 자료 구조, 정렬, 이분 탐색, 해시를 사용한 집합과 맵
 * 
 * binary search 의 개념을 이용하여,
 * lower bound 와 upper bound 를 구한다.
 * 
 * https://blog.encrypted.gg/985
 * 
 * 
 * 시간초과 해결을 위해
 * ios::sync_with_stdio(0);
 * cin.tie(0);
 * 
 * 이럼에도 시간 초과 문제가 발생하면, C 표준 입출력 함수를 사용해야 할 수 있다.
 */


#include <iostream>
#include <algorithm>

using namespace std;
int a[50000005];

int upper_bound(int target, int size){
    int st = 0;
    int end = size;
    int mid = 0;
    while(st < end){
        mid = (st+end)/2;
        if(a[mid] > target)
            end = mid;
        else
            st = mid+1;
    }
    return st;
}

int lower_bound(int target, int size){
    int st = 0;
    int end = size;
    int mid = 0;
    while(st < end){
        mid = (st+end)/2;
        if(a[mid] >= target)
            end = mid;
        else
            st = mid+1;
    }
    return st;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> a[i];
    }

    sort(a, a+N);

    int M;
    cin >> M;
    while(M--){
        int value;
        cin >> value;
        cout << upper_bound(value, N) - lower_bound(value, N) << " ";
    }

}
