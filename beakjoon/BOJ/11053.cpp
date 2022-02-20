/* 
 * baekjoon 11053
 * 
 * 연속합
 * 
 * https://www.acmicpc.net/problem/11053
 * 
 * 
 * 
 */

#include <iostream>

#define MAX 1000
#define maxi(a,b) (a>b ? a : b)
using namespace std;

int N;

int value[MAX+1];
int result[MAX+1];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    
    cin >> N;

    for(int i=0;i<N;i++){
        cin >> value[i];
    }

    int max = 0;

    for(int i=0;i<N;i++){
        result[i]=1;
        for(int j=0;j<i;j++){
            if(value[j]<value[i])
                result[i] = maxi(result[j]+1, result[i]);
        }

        max = maxi(result[i],max);
    }



    cout << max;

    return 0;
}
