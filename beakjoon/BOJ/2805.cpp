/* 
 * baekjoon 2805
 * 
 * 나무 자르기
 * 
 * https://www.acmicpc.net/problem/2805
 * 
 * 
 * 
 * 
 * #include <algorithm>
 * max_element(value.begin(),value.end());
 * 
 * 이런 함수도 있다.
 */



#include <iostream>
#include <vector>

using namespace std;


int N;
long long M;
vector<int> value;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    int max=0;
    int x;
    for(int i=0;i<N;i++){
        cin >> x;
        value.push_back(x);
        if(max < x)
            max = x;
    }

    int start = 0;
    int end = max;
    int ans = 0;

    //첫 시도에서 max 값에서 하나씩 값을 줄이며 탐색했었는데 시간초과가 발생했다.
    //따라서 이 탐색하는 부분을 이분탐색으로 진행시켜 실행 시간을 줄인다.

    while(start <= end){
        long long sum = 0;
        int mid = (start+end)/2;
        for(int i=0;i<N;i++){
            long long temp = value[i]-mid;
            if(temp>0)
                sum+=temp;
        }

        if(sum>=M){
            start = mid + 1;
            ans = mid;
        }

        if(sum < M)
            end = mid - 1;
    }

    cout << ans;




    return 0;
}
