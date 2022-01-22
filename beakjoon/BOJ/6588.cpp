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
#include <vector>
#include <cmath>
using namespace std;

vector<int> v;

void eratosthenes(int n){
    int sqrt_n = (int)sqrt(n);
    if(n<=1)    return;
    bool* primes = new bool[n+1];

    for(int i=2; i<=n; i++)
        primes[i] = true;

    for(int i=2; i*i<=sqrt_n; i++){
        if(primes[i])
            for(int j=i*i; j<=n; j+=i)
                primes[j] = false;
    }

    //홀수인 소수만을 추출하기위해 2를 제외시킨다.
    primes[2] = false;

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
    eratosthenes(1000000);

    int N=-1;
    
    while(1){
        cin >> N;
        if(N==0)
            break;
            
        int sum = 0, low = 0, high = v.size()-1;
        sum = v[low]+v[high];
        while(1){
            if(sum == N){
                cout << N << " = " << v[low] << " + " << v[high] <<"\n";
                break;
            }
            else if(sum > N){
                sum -= v[high--];
                sum += v[high];
            }
            else{
                sum -= v[low++];
                sum += v[low];
            }

            if(high == low){
                cout << "Goldbach's conjecture is wrong.\n";
                break;
            }

        }
        

    }



    return 0;
}
