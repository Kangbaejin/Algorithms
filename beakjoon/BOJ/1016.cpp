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
 * long long 변수형을 사용하여 큰 수를 처리했고,
 * 배열의 크기를 위해 max - min 의 최대값은 1000000 값으로 주어졌다.
 * 이때 큰 수를 조건에 맞게 index를 설정하는 것이 포인트
 * 
 * 소수 판정 후 소수만을 이용하는 알고리즘을 떠올렸었는데,
 * 굳이 소수를 뽑아내고 소수의 제곱수의 배수마다 체크하는 것 보다
 * 
 * 최대값 까지의 제곱수들을 이용하여 최소값을 나누었을 때
 * 조건식을 두어 첫 index를 잘 설정한 뒤 1000000 개 안의 배열에서
 * 반복문을 통해 체크하며 개수를 반환하는 문제
 * 
 * 
 * 소수를 이용한 알고리즘을 떠올리기 전에, 제일 먼저 떠올렸던 알고리즘이 위와 같았는데,
 * 첫 index 에 대한 문제 때문에 계속 막막했었다.
 * https://www.acmicpc.net/board/view/65584
 * 이 분의 코드엔 막연하게 생각했던 부분들이 체계적으로 잘 구현이 되어 있었다...
 * 
 */

#include <iostream>
using namespace std;


bool mintomax[1000001];


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    long long min, max;
    cin >> min >> max;
    long long gap = max - min;

    for(int i=0;i<=gap;i++){
        mintomax[i] = true;
    }

    long long temp, square_min;
    for(long long i=2; i*i<=max; i++){
        temp = i*i;
        //나누어 떨어지지 않으면, 다음 배수부터 시작하기 위한 조건문
        if(min%temp==0) square_min = min;
        else square_min = (min/temp + 1)*temp;

        for(long long j = square_min; j<=max; j+=temp){
            mintomax[j-min] = false;
        }
    }


    int count = 0;
    for(int i=0;i<=gap;i++){
        if(mintomax[i]) count ++;
    }

    cout << count;


    return 0;
}
