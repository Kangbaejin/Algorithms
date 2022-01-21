/* 
 * baekjoon 1644
 * 
 * 소수의 연속합
 * 
 * https://www.acmicpc.net/problem/1644
 * 
 * 
 *
ios::sync_with_stdio(0);
cin.tie(0); 
cout.tie(0);
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> v;

void eratosthenes(int n){
    if(n<=1)    return;
    bool* primes = new bool[n+1];

    for(int i=2; i<=n; i++)
        primes[i] = true;

    for(int i=2; i*i<=n; i++){
        if(primes[i])
            for(int j=i*i; j<=n; j+=i)
                primes[j] = false;
    }

    for(int i=2; i<=n; i++){
        if(primes[i]==true)
            v.push_back(i);
    }

    return;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N;
    cin >> N;
    eratosthenes(N);

    int ans = 0, sum = 0, high = 0, low = 0;


    /*
     * 두 포인터의 개념 이용
     *
     * 우선 sum 이 N 보다 큰 경우엔, sum 에서 v[low] 를 뺴준 뒤, low 위치를 한칸 올린다.
     * 그렇지 않았을 때 즉, sum<N 인 상황에서 high 가 v.size() 라면 종료
     * 종료되지 않았다면, 아직 더해줄 index 가 있는 것이고 큰 수를 더해준다.
     * 
     * 해당 두 포인터로 더하거나 빼기 이후에 N 과 같은지 비교하여 답의 개수를 늘린다.
     */

    while(1){
        if(sum >= N)    sum -= v[low++];
        else{
            if(high == v.size()) break;
            sum += v[high++];
        }

        if(sum == N)    ans++;
    }



    cout << ans;

    return 0;
}