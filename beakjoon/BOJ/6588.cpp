/* 
 * baekjoon 6588
 * 
 * 골드바흐의 추측
 * 
 * https://www.acmicpc.net/problem/6588
 * 
 * 
 * 
 * 참고 및 주의사항
 * https://www.acmicpc.net/board/view/44906
 */

#include <iostream>
#include <cmath>
using namespace std;

bool primes[1000001];


void eratosthenes(int n){
    if(n<=1)    return;

    for(int i=2; i<=n; i++)
        primes[i] = true;

    for(int i=2; i*i<=n; i++){
        if(primes[i])
            for(int j=i*i; j<=n; j+=i)
                primes[j] = false;
    }

    return;
}



int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    eratosthenes(1000000);

    int N=-1;
    
    while(1){
        cin >> N;
        if(N==0)
            break;

        int a=0, b=0;

        for(a=3;a<N;a++){
            if(primes[a]){
                b=N-a;
                if(primes[b]){
                    cout << N << " = " << a << " + " << b << "\n";
                    break;
                }
            }
        }
        if(a==N)
            cout << "Goldbach's conjecture is wrong.\n";
    }



    return 0;
}
