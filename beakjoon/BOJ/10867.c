/* baekjoon 10867
 *
 * 중복 빼고 정렬하기
 * 
 * https://www.acmicpc.net/problem/10867
 * 
 * 
 * sorting 후 값이 변할때만 출력하게 짤 수도 있을 것이다.
 * 
 */

#include <stdio.h>

int main(){
    int N=0;
    int array[2001]={0,};

    scanf("%d", &N);

    int value=0;
    for(int i=0;i<N;i++){
        scanf("%d", &value);
        array[value+1000]++;
    }

    for(int i=0;i<2001;i++){
        if(array[i]!=0)
            printf("%d ",i-1000);
    }
}