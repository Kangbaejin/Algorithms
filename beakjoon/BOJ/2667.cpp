/* 
 * baekjoon 2667
 * 
 * 숨바꼭질
 * 
 * https://www.acmicpc.net/problem/2667
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ans;
int x, y;

void solve(int n, int depth){
    cout << "depth : " << depth << " n : " << n << '\n';
    if(n<0)  return;
    if(depth>y-x)  return;
    else if(n==y){
        if(depth<ans) ans = depth;
        return;
    }
    else{
        solve(n-1,depth+1);
        solve(n+1,depth+1);
        solve(n*2,depth+1);
    }

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> x >> y;
    ans = (y-x)>=0 ? y-x : x-y;
    solve(x,0);
    cout << ans;

    return 0;
}