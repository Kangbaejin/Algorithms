/* baekjoon 10989
 *
 * 문제
 * 
 * N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.
 *
 * 
 * 입력
 * 
 * 첫째 줄에 수의 개수 N(1 ≤ N ≤ 10,000,000)이 주어진다.
 * 둘째 줄부터 N개의 줄에는 수가 주어진다.
 * 이 수는 10,000보다 작거나 같은 자연수이다.
 * 
 * 
 * 출력
 * 
 * 첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.
 * 
 * 
 * 문제 주요 point
 * 
 * 제한된 메모리를 이용하여 프로그램을 작성해야한다.
 * 
 * 주어진 수를 sorting 한다는 개념을 다른 각도로 바라본다.
 * 숫자의 범위보다 숫자의 갯수가 훨씬 많으므로,
 * 각 배열의 index 를 숫자로 보고 해당 index의 값을 그 숫자의 갯수로 생각한다.
 */

#include <stdio.h>

int main(){
    int N,value;
    scanf("%d", &N);

    int counting[10001]={0,};

    for(int i=0;i<N;i++){
        scanf("%d", &value);
        counting[value]++;
    }

    for(int i=1;i<10001;i++){
        if(counting[i]!=0){
            for(int j=0;j<counting[i];j++){
                printf("%d\n", i);
            }
        }
    }

    return 0;
}