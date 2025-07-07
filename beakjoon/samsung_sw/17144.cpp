/* 
 * baekjoon 17144
 * 
 * 미세먼지 안녕!
 * 
 * https://www.acmicpc.net/problem/17144
 * 
 * 
 * 
 */

#include <iostream>
#include <deque>

#define MAX 51
using namespace std;

int R,C,T;
int ac_location;

int value[MAX][MAX] = {0,};
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

int next_state[MAX][MAX] = {0,};


int check_4_ways(int r, int c){
    int cnt = 0;
	for(int i=0; i<4; i++){
        int newr = r + dir[i][0];
		int newc = c + dir[i][1];
        //배열 벗어나면 continue 처리
		if(newr<0 || newr>=R || newc<0 || newc>=C) continue;
        //가능한 좌표가 공기정청기가 아니라면 카운트
        if(value[newr][newc] != -1){
            next_state[newr][newc] += value[r][c]/5;
            cnt++;
        }
	}

    next_state[r][c]+=value[r][c]-(value[r][c]/5)*cnt;

    return 0;
}



void diffusion(void){
    //next_state 배열 초기화
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            next_state[i][j] = 0;
        }
    }

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(value[i][j]!=0 && value[i][j]!=-1){
                check_4_ways(i,j);
            }
        }
    }
    next_state[ac_location-1][0]=-1;
    next_state[ac_location][0]=-1;


    //next_state 값을 현재 값에 할당
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            value[i][j] = next_state[i][j];
        }
    }

    // cout << "\n";
    // for(int i=0;i<R;i++){
    //     for(int j=0;j<C;j++){
    //         cout << value[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    return;
}



void air_cleaner(void){
    deque<int> u_dq;
    deque<int> d_dq;
    int upper_loc = ac_location-1;
    int down_loc = ac_location;
    
    /*upper_circle*/
    int i = upper_loc;
    int j = 1;
    // ->
    while(j<C){
        u_dq.push_back(value[i][j]);
        j++;
    }
    j--;

    //up
    i--;
    while(i>=0){
        u_dq.push_back(value[i][j]);
        i--;
    }
    i++;

    // <-
    j--;
    while(j>=0){
        u_dq.push_back(value[i][j]);
        j--;
    }
    i++;
    j++;

    //down
    while(i<upper_loc){
        u_dq.push_back(value[i][j]);
        i++;
    }
    
    u_dq.pop_back();
    u_dq.push_front(0);

    j = 1;

    // ->
    while(j<C){
        value[i][j] = u_dq.front();
        u_dq.pop_front();
        j++;
    }
    j--;

    //up
    i--;
    while(i>=0){
        value[i][j] = u_dq.front();
        u_dq.pop_front();
        i--;
    }
    i++;

    // <-
    j--;
    while(j>=0){
        value[i][j] = u_dq.front();
        u_dq.pop_front();
        j--;
    }
    i++;
    j++;

    //down
    while(i<upper_loc){
        value[i][j] = u_dq.front();
        u_dq.pop_front();
        i++;
    }


    /*down_circle*/
    i = down_loc;
    j = 1;
    // ->
    while(j<C){
        d_dq.push_back(value[i][j]);
        j++;
    }
    j--;

    //down
    i++;
    while(i<R){
        d_dq.push_back(value[i][j]);
        i++;
    }
    i--;

    // <-
    j--;
    while(j>=0){
        d_dq.push_back(value[i][j]);
        j--;
    }
    j++;

    //up
    i--;
    while(i>down_loc){
        d_dq.push_back(value[i][j]);
        i--;
    }
    
    // deque<int> :: iterator iter;
    // cout << "this is d_dq " << d_dq.size() << "\n";
    // for(iter = d_dq.begin(); iter != d_dq.end() ; iter++){
    //     cout << *iter << " ";
    // }
    // cout << "\n";


    d_dq.pop_back();
    d_dq.push_front(0);


    j = 1;

    // ->
    while(j<C){
        value[i][j] = d_dq.front();
        d_dq.pop_front();
        j++;
    }
    j--;

    //down
    i++;
    while(i<R){
        value[i][j] = d_dq.front();
        d_dq.pop_front();
        i++;
    }
    i--;

    // <-
    j--;
    while(j>=0){
        value[i][j] = d_dq.front();
        d_dq.pop_front();
        j--;
    }
    j++;

    //up
    i--;
    while(i>down_loc){
        value[i][j] = d_dq.front();
        d_dq.pop_front();
        i--;
    }

    return;
}





int main(){
    
    cin >> R >> C >> T;

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin >> value[i][j];
            if(value[i][j]==-1){
                ac_location = i;
            }
        }
    }

    while(T--){
        diffusion();
        air_cleaner();
        // cout << "\n";
        // for(int i=0;i<R;i++){
        //     for(int j=0;j<C;j++){
        //         cout << value[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
    }

    int ans=0;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            ans+= value[i][j];
        }
    }
    //공기청정기가 -1 로 2개 차지하므로
    cout << ans+2;

    
    return 0;
}