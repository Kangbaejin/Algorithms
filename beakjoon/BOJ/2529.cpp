/* 
 * baekjoon 2529
 * 
 * 부등호
 * 
 * https://www.acmicpc.net/problem/2529
 * 
 *
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;


vector<char> value;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    char x;

    for(int i=0;i<N;i++){
        cin >> x;
        value.push_back(x);
    }

    vector<int> rise;
    vector<int> fall;

    for(int i=0;i<=N;i++){
        rise.push_back(i);
        fall.push_back(9-i);
    }


    int cnt;
    do{
        cnt = 0;
        for(int i=0;i<N;i++){
            if(value[i] == '<'){
                if(fall[i]<fall[i+1])
                    cnt++;
            }
            else{
                if(fall[i]>fall[i+1])
                    cnt++;
            }
        }
        if(cnt == N){
            for(int i=0;i<=N;i++){
                cout << fall[i];
            }
            cout << '\n';
            break;
        }
    }while(prev_permutation(fall.begin(), fall.end()));


    do{
        cnt = 0;
        for(int i=0;i<N;i++){
            if(value[i] == '<'){
                if(rise[i]<rise[i+1])
                    cnt++;
            }
            else{
                if(rise[i]>rise[i+1])
                    cnt++;
            }
        }
        if(cnt == N){
            for(int i=0;i<=N;i++){
                cout << rise[i];
            }
            cout << '\n';
            break;
        }
    }while(next_permutation(rise.begin(), rise.end()));


    return 0;
}
