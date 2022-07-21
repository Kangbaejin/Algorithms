/* 
 * baekjoon 20055
 * 
 * 컨베이어 벨트 위의 로봇
 * 
 * https://www.acmicpc.net/problem/20055
 * 
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

int N,K;

struct cell{
    int durability=0;
    bool is_full=false;
};

vector<cell> c_belt;

void Input(){
    cin >> N >> K;
    int temp;
    for(int i=0;i<2*N;i++){
        cin >> temp;
        cell one;
        one.durability=temp;
        c_belt.push_back(one);
    }
}

void solve(){
    int level=0;
    while(1){
        level++;
        //회전
        cell last_cell;
        c_belt[N-1].is_full = false;
        last_cell = c_belt[2*N-1];
        for(int i=2*N-2;i>=0;i--){
            c_belt[i+1]=c_belt[i];
        }
        c_belt[0]=last_cell;

        for(int i=N-2;i>=0;i--){
            if(c_belt[i].is_full){
                int nexti=i+1;
                c_belt[N-1].is_full = false;
                if(!c_belt[nexti].is_full && (c_belt[nexti].durability>=1)){
                    c_belt[i].is_full=false;
                    c_belt[nexti].is_full=true;
                    c_belt[nexti].durability--;
                    i++;
                }
            }
        }

        if(c_belt[0].durability>0 && !c_belt[0].is_full){
            c_belt[0].durability--;
            c_belt[0].is_full=true;
        }

        int zero_cnt=0;
        for(int i=0;i<2*N;i++){
            if(c_belt[i].durability==0) zero_cnt++;
        }
        if(zero_cnt >= K){
            cout << level;
            break;
        }
    }
}



int main(){
    Input();
    solve();
    return 0;
}