#include <stdio.h>

int binarySearch(int a[], int low, int high, int target){
    while(low <= high){
        int mid = (low+high)/2;
        if(a[mid] == target) return mid;
        if(a[mid] > target) high = mid-1;
        else low = mid + 1;
    }

    return -1;
}