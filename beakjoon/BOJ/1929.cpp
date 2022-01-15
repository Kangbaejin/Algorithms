/* 
 * baekjoon 1929
 * 
 * 소수 구하기
 * 
 * https://www.acmicpc.net/problem/1929
 * 
 */

#include <iostream>
#include <vector>


using namespace std;


void eratosthenes(int start, int n){
    if(n<=1)    return;

    bool* primes = new bool[n+1];

    for(int i=2; i<=n; i++)
        primes[i] = true;

    for(int i=2; i*i<=n; i++){
        if(primes[i])
            for(int j=i*i; j<=n; j+=i)
                primes[j] = false;
    }

    for(int i=start; i<=n; i++){
        if(i==1)
            continue;

        if(primes[i])
            cout << i << '\n';
    }

    return;
}



int main(){
    int start, end;
    cin >> start >> end;

    eratosthenes(start, end);
    return 0;
}