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
vector<int> sum_v;

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

    int size = v.size();
    int ans = 0;
    int temp = 0;


    sum_v.push_back(0);
    int s = 0;
    for(int i=0;i<size;i++){
        s += v[i];
        sum_v.push_back(s);
    }



    for(int i=0;i<=size;i++){
        for(int j=i+1;j<=size;j++){
            if(sum_v[j]-sum_v[i]==N)
                ans++;
        }
    }


    cout << ans;

    return 0;
}