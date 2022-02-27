/* 
 * baekjoon 2869
 * 
 * 달팽이는 올라가고 싶다.
 * 
 * https://www.acmicpc.net/problem/2869
 * 
 * 
 * 
 */


#include <iostream>

using namespace std;

int A,B,V;

int main(){
    cin >> A >> B >> V;
    

    int q = (V-A)/(A-B);
    int r = (V-A)%(A-B);
    int ans = q;
    if(r!=0){
        ans++;
    }

    cout << ans + 1;

    return 0;
}