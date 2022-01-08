/* baekjoon 10816
 *
 * 숫자 카드 2
 * 
 * https://www.acmicpc.net/problem/10816
 * 
 * 
 * 
 * 
 * 자료 구조, 정렬, 이분 탐색, 해시를 사용한 집합과 맵
 */


#define ten_million 10000000
#include <stdio.h>


int array[2*ten_million + 1]={0,};

int main(){
    int N=0;
    scanf("%d", &N);

    int value=0;
    for(int i=0; i<N; i++){
        scanf("%d", &value);
        array[ten_million+value]++;
    }


    int M=0;
    scanf("%d", &M);
    for(int i=0; i<M; i++){
        scanf("%d", &value);
        printf("%d ", array[ten_million+value]);
    }

    return 0;
}