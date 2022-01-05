/* baekjoon 1920
 *
 * 문제
 * 
 * N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 때,
 * 이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성하시오.
 *
 * 
 * 입력
 * 
 * 첫째 줄에 자연수 N(1 ≤ N ≤ 100,000)이 주어진다. 
 * 다음 줄에는 N개의 정수 A[1], A[2], …, A[N]이 주어진다. 
 * 다음 줄에는 M(1 ≤ M ≤ 100,000)이 주어진다.
 * 다음 줄에는 M개의 수들이 주어지는데, 이 수들이 A안에 존재하는지 알아내면 된다.
 * 모든 정수의 범위는 -2^31 보다 크거나 같고 2^31보다 작다.
 * 
 * 
 * 출력
 * 
 * M개의 줄에 답을 출력한다. 존재하면 1을, 존재하지 않으면 0을 출력한다.
 * 
 * 
 * 
 * 
 * 
 * 문제 주요 point
 * 
 * 1초의 제한 시간을 만족하기위해 정렬 및 탐색에서 빠른 알고리즘을 이용해야 한다.
 * 변수를 이용한 index 사용 시, 오버플로우가 발생하지 않도록 범위에 주의하여 사용한다.
 * 
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
    int A[100000];

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
    int question[100000];
    for(int i=0;i<question_size;i++){
        scanf("%d", &question[i]);
    }

    //index 로 A_size 를 사용하는데 주의!
    if(A_size==1){
        for(int i=0;i<question_size;i++){
            if(A[A_size-1] == question[i]) printf("%d\n", 1);
            else printf("%d\n", 0);
        }
    }

    else{
        mergeSort(A,0,A_size-1);
        for(int i=0; i<question_size;i++){
            if(binarySearch(A,0,A_size-1,question[i])==-1)  printf("%d\n", 0);
            else printf("%d\n", 1);
        }
    }

    return 0;
}