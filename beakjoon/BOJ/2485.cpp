/* 
 * baekjoon 2485
 * 
 * 가로수
 * 
 * https://www.acmicpc.net/problem/2485
 * 
 * 
 *
ios::sync_with_stdio(0);
cin.tie(0); 
cout.tie(0);
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int gcd(int a, int b){
    int temp;
    if(a<b){
        temp = a;
        a = b;
        b = temp;
    }

    while(b!=0){
        temp = a%b;
        a = b;
        b = temp;
    }

    return a;

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);


    cin >> N;
    int length = 0;
    int temp=0;
    vector<int> point;
    vector<int> distance;

    for(int i=0;i<N;i++){
        cin >> temp;
        point.push_back(temp);
    }

    sort(point.begin(),point.end());

    for(int i=0;i<N-1;i++){
        length+=point[i+1]-point[i];
        distance.push_back(point[i+1]-point[i]);
    }

    int gcd_value = -1;
    for(int i=1;i<distance.size();i++){
        if(gcd_value == -1) gcd_value = gcd(distance[i],distance[i-1]);
        else gcd_value = gcd(gcd_value, distance[i]);
    }

    /*
     * 각 거리 사이 값들의 최대 공배수는 곧 전체 가로수의 사이 길이가 된다.
     * 이때 필요한 추가 나무 갯수는 distance[i] / gcd_value - 1 개인데
     * 이를 정리하면 distance[i] 의 총합인 length 를 이용하여,
     * length / gcd_value - 1 * distance.size() 로 정리할 수 있다.
     *
     */
    cout << length/gcd_value - distance.size();

    return 0;



}