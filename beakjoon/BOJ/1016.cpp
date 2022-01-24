/* 
 * baekjoon 1016
 * 
 * 제곱 ㄴㄴ 수
 * 
 * https://www.acmicpc.net/problem/1016
 * 
 * 
 */





/* 
 * 일단 수의 범위가 너무 큰 것에서 이를 간단히 실행 할 수 있는 방법을
 * 고민하던 중, 입력의 sqrt 값을 이용하여 sqrt_max 이하의 소수들의 배수들의 위치에
 * 마킹을 하여, 마킹되지 않은 수를 구하는 알고리즘을 떠올렸다.
 * 
 * ex) 1 10  일때 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
 * sqrt min = 1, sqrt max = 3.xxx
 * 따라서 해당 수 사이에 있는 최대 가능 소수의 제곱은, 4와 9 이다.
 * 제곱수로 나누어지는 경우는 4의 배수 경우인 4와 8,
 * 9의 배수인 9로
 * 
 * 해당 경우를 제외한 1,2,3,5,6,7,10 이므로 답은 7
 * 
 * 
 * 
 * 아래의 코드는 완벽하지 않으며,
 * 1 10 경우 :  출력 7 (정답 = 7)
 * 15 15 경우 : 출력 0 (정답 = 1)
 * 1 1000 경우 : 출력 609 (정답 = 608)
 * 
 * 두 수 사이의 gap 을 이용함에 있어서 시작 위치를 정하는 것에서 문제가 있다.
 * 
 */





#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


bool primes[1000001];
vector<int> v;

void eratosthenes(int start, int n){
    if(n<=1)    return;

    for(int i=2; i<=n; i++)
        primes[i] = true;

    for(int i=2; i*i<=n; i++){
        if(primes[i])
            for(int j=i*i; j<=n; j+=i)
                primes[j] = false;
    }

    for(int i=start; i<=n; i++){
        if(primes[i])
            v.push_back(i*i);
    }
    return;
}





int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    long long min, max;
    cin >> min >> max;
    long long gap = max - min;


    
    bool mintomax[1000001]={false,};

    int sqrt_min, sqrt_max;
    sqrt_min = (int)sqrt(min);
    sqrt_max = (int)sqrt(max);

    eratosthenes(1,sqrt_max);
    
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }


    for(int i=0;i<v.size();i++){
        int temp = v[i];
        while(temp<gap){
            mintomax[temp] = true;
            temp += v[i];
        }
    }

    int count = 0;
    for(int i=0;i<gap;i++){
        if(!mintomax[i])
            count ++;
    }

    cout << "\n" <<count;


    return 0;
}
