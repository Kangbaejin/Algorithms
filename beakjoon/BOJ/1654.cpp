/* 
 * baekjoon 1654
 * 
 * 랜선 자르기
 * 
 * https://www.acmicpc.net/problem/1654
 * 
 * 
 * 
 */



#include <iostream>
#include <vector>

using namespace std;


int N;
int M;
vector<long long> value;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    long long max=0;
    long long x;
    for(int i=0;i<N;i++){
        cin >> x;
        value.push_back(x);
        if(max < x)
            max = x;
    }

    long long start = 1;
    long long end = max;
    long long ans = 0;

    while(start <= end){
        long long sum = 0;
        long long mid = (start+end)/2;
        for(int i=0;i<N;i++){
            long long temp = value[i]/mid;
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
