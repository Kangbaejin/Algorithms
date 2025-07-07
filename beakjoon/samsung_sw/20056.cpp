/* 
 * baekjoon 20056
 * 
 * 마법사 상어와 파이어볼
 * 
 * https://www.acmicpc.net/problem/20056
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N,M,K;
const int max_n = 52;
int dir[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

struct fire_ball{
    int m,d,s;
};

queue<fire_ball> q[max_n][max_n];

void Input(){
    cin >> N >> M >> K;
    for(int i=0;i<M;i++){
        fire_ball fb1;
        int r, c;
        cin >> r >> c >> fb1.m >> fb1.s >> fb1.d;
        q[r][c].push(fb1);
    }
}


void move(){
    queue<fire_ball> new_q[max_n][max_n];
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            while(!q[i][j].empty()){
                // cout << "i : " << i << " j : " << j << ' ';
                fire_ball fb1;
                fb1 = q[i][j].front();
                q[i][j].pop();
                int newi, newj;
                int speed = fb1.s%N;
                newi = (i+dir[fb1.d][0]*speed + N)%N;
                if(newi==0) newi=N;

                newj = (j+dir[fb1.d][1]*speed + N)%N;
                if(newj==0) newj=N;

                // cout << "newi : " << newi << " newj : " << newj << '\n';
                new_q[newi][newj].push(fb1);
            }
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            q[i][j]=new_q[i][j];
        }
    }
}

void sum_divide(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(q[i][j].size()>=2){
                int even_cnt = 0;
                int num_fb = q[i][j].size();
                int sum_mass = 0;
                int sum_speed = 0;
                while(!q[i][j].empty()){
                    fire_ball fb1 = q[i][j].front();
                    q[i][j].pop();

                    sum_speed += fb1.s;
                    sum_mass += fb1.m;

                    if(fb1.d%2==0) even_cnt++;
                }

                int each_mass = sum_mass/5;
                if(each_mass==0) continue;

                int each_speed = sum_speed/num_fb;

                int each_dir[4] = {1,3,5,7};
                if(even_cnt == 0 || even_cnt == num_fb){
                    for(int k=0;k<4;k++){
                        each_dir[k]--;
                    }
                }

                for(int k=0;k<4;k++){
                    fire_ball fb1;
                    fb1.d = each_dir[k];
                    fb1.m = each_mass;
                    fb1.s = each_speed;
                    q[i][j].push(fb1);
                }
            }
        }
    }    
}

void solve(){
    while(K--){
        move();
        sum_divide();
    }
    int sum=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            while(!q[i][j].empty()){
                fire_ball fb1 = q[i][j].front();
                q[i][j].pop();
                sum += fb1.m;
            }
        }
    }

    cout << sum;
}

int main(){
    Input();
    solve();
    return 0;
}