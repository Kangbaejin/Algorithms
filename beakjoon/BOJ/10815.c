/* baekjoon 10815 
 * 
 * 숫자 카드
 *
 * 문제
 * 
 * 숫자 카드는 정수 하나가 적혀져 있는 카드이다. 상근이는 숫자 카드 N개를 가지고 있다.
 * 정수 M개가 주어졌을 때,
 * 이 수가 적혀있는 숫자 카드를 상근이가 가지고 있는지 아닌지를 구하는 프로그램을 작성하시오.
 *
 * 
 * 입력
 * 
 * 첫째 줄에 상근이가 가지고 있는 숫자 카드의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 
 * 
 * 둘째 줄에는 숫자 카드에 적혀있는 정수가 주어진다. 
 * 숫자 카드에 적혀있는 수는 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다. 두 숫자 카드에 같은 수가 적혀있는 경우는 없다.
 * 
 * 셋째 줄에는 M(1 ≤ M ≤ 500,000)이 주어진다. 
 * 
 * 넷째 줄에는 상근이가 가지고 있는 숫자 카드인지 아닌지를 구해야 할 M개의 정수가 주어지며, 
 * 이 수는 공백으로 구분되어져 있다. 이 수도 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다
 * 
 * 
 * 출력
 * 
 * 첫째 줄에 입력으로 주어진 M개의 수에 대해서,
 * 각 수가 적힌 숫자 카드를 상근이가 가지고 있으면 1을,
 * 아니면 0을 공백으로 구분해 출력한다.
 * 
 * 
 * 
 * 
 * 
 * 문제 주요 point
 * 
 * 2초의 제한 시간을 만족하기위해 정렬 및 탐색에서 빠른 알고리즘을 이용해야 한다.
 * 1920 번 문제와 동일한 문제이며, 입력의 크기가 5배인 500000 인 점에서만 차이가 있다.
 */


#include <stdio.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
  
    /* create temp arrays */
    int L[n1], R[n2];
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
  
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
  
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
  
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
  
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
  
        merge(arr, l, m, r);
    }
}


int binarySearch(int a[], int low, int high, int target){
    while(low <= high){
        int mid = (low+high)/2;
        if(a[mid] == target) return mid;
        if(a[mid] > target) high = mid-1;
        else low = mid + 1;
    }

    return -1;
}






int main(){
    int A_size=0;
    int A[500001];

    //A 의 size 입력
    scanf("%d", &A_size);
    //A 입력
    for(int i=0;i<A_size;i++){
        scanf("%d", &A[i]);
    }

    //정답을 알고 싶은 수의 size 입력
    int question_size;
    scanf("%d", &question_size);
    //question 입력
    int question[500001];
    for(int i=0;i<question_size;i++){
        scanf("%d", &question[i]);
    }

    //index 로 A_size 를 사용하는데 주의!
    if(A_size==1){
        for(int i=0;i<question_size;i++){
            if(A[A_size-1] == question[i]) printf("%d ", 1);
            else printf("%d ", 0);
        }
    }

    else{
        mergeSort(A,0,A_size-1);
        for(int i=0; i<question_size;i++){
            if(binarySearch(A,0,A_size-1,question[i])==-1)  printf("%d ", 0);
            else printf("%d ", 1);
        }
    }

    return 0;
}