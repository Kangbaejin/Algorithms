/* 
 * baekjoon 15711
 * 
 * 환상의 짝꿍
 * 
 * https://www.acmicpc.net/problem/15711
 * 
 * 
 */

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool primes[2000001];
vector<int> v;


bool is_prime(long long x){
    if(x<=2000001)    return primes[x];
    else{
        for(int i=0;i<v.size();i++){
            if(x % v[i]==0)
                return false;
        }
        return true;
    }
}

void eratosthenes(int n){
    v.clear();
    if(n<=1)    return;

    for(int i=2; i<=n; i++)
        primes[i] = true;

    for(int i=2; i*i<=n; i++){
        if(primes[i])
            for(int j=i*i; j<=n; j+=i)
                primes[j] = false;
    }


    for(int i=0;i<=n;i++){
        if(primes[i]){
            v.push_back(i);
        }
    }

    return;
}



int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    eratosthenes(2000001);

    int N;
    cin >> N;

    long long x,y, sum;
    
    while(N--){
        cin >> x >> y;
        sum = x+y;
        long long int a=0, b=0;

        if(sum == 2)    cout << "NO\n";
        else if(sum % 2 == 0)   cout << "YES\n";    //골드바흐의 추측 이용
        else{                                       //홀수 인 경우
            if(is_prime(sum - 2)) cout << "YES\n";  //합이 홀수 = (짝수 + 홀수) 일텐데 짝수인 소수는 2뿐이다.
            else cout << "NO\n";
        }
    }



    return 0;
}
