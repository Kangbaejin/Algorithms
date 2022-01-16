/* 
 * baekjoon 14889
 * 
 * 스타트와 링크
 * 
 * https://www.acmicpc.net/problem/14889
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int N;
    cin >> N;
    int *arry = new int[N*N];

    for(int i=0; i<N*N; i++){
        cin >> arry[i];
    }

    vector<int> v;

    for(int i=0;i<N;i++){
        if(i<N/2)
            v.push_back(0);
        else
            v.push_back(1);
    }

    vector<int> star;
    vector<int> link;
    int min = 2000;
    int sum;
    do{
        star.clear();
        link.clear();


        sum = 0;
        for(int i=0;i<N;i++){
            if(v[i]==0)
                star.push_back(i);
            else
                link.push_back(i);
        }

        for(int i=0;i<N/2;i++){
            for(int j=0;j<N/2;j++){
                sum += arry[star[i]*N+star[j]];
            }
        }

        for(int i=0;i<N/2;i++){
            for(int j=0;j<N/2;j++){
                sum -= arry[link[i]*N+link[j]];
            }
        }

        if(sum==0){
            min = 0;
            break;
        }

        if(abs(sum)<min)
            min = abs(sum);

    }while(next_permutation(v.begin(),v.end()));

    cout << min;

    return 0;
}