/* 
 * baekjoon 17825
 * 
 * 주사위 윷놀이
 * 
 * https://www.acmicpc.net/problem/17825
 * 
 * 
 */

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

//다른 길이 집어넣고 관리하기 위해서 vector 이용
vector<int> way_10 = {10,13,16,19,25,30,35,40};
vector<int> way_20 = {20,22,24,25,30,35,40};
vector<int> way_30 = {30,28,27,26,25,30,35,40};
vector<int> out_way;  //0, 2, 4, ... 40

vector<vector<int>> ways;
int dice[10];

/* 
 * 말의 종류(번호)
 * 어느 경로에 위치하는지 저장 (0: out, 1: way_10, 2: way_20, 3: way_30)
 * 경로위의 현재 위치
 * 도착점 도달여부
 * ex) way : 0, idx : 0 은 시작지점이다.
 */
struct stone{
    int way=0, idx=0;
    bool end=false;
};
stone stones[5];

int ans=0;
vector<int> horse;
vector<int> ans_v;

void Input(){
    //주사위 입력 처리
    for(int i=0;i<10;i++)   cin >> dice[i];

    //경로 전처리  
    for(int i=0;i<21;i++)   out_way.push_back(i*2);
    //ways[0], ways[1], ways[2], ways[3] 으로 접근가능
    ways.push_back(out_way);
    ways.push_back(way_10);
    ways.push_back(way_20);
    ways.push_back(way_30);

}

//도착한 칸의 값 return
int move(stone& s, int distance){
    int cur_way = s.way;
    int cur_idx = s.idx;
    vector<int> cur_way_vector = ways[cur_way];
    
    //경로 벗어나는 경우 -> 도착에 도달하는 경우
    int next_idx = cur_idx + distance;
    if(next_idx >= cur_way_vector.size()) {
        s.end = true;
        return 0;
    }

    //경로 내부에 존재하는 경우
    //cur_way_vector[next_idx]는 이동 후의 값을 의미한다.
    int next_value = cur_way_vector[next_idx];

    //이동을 마쳤을 때 값이 10, 20, 30 이면 새로운 경로로 조정해야한다.
    //10, 20, 30 이 아닌 경우는 업데이트하고 종료
    switch (next_value){
        case 10:
            s.way = 1;
            s.idx = 0;
            break;
        case 20:
            s.way = 2;
            s.idx = 0;
            break;
        case 30:
            s.way = 3;
            s.idx = 0;
            break;
        default :
            s.idx = next_idx;
            break;
    }
    return next_value;
}

void print_stones(){
    cout << "####print####\n";
    for(int i=1;i<=4;i++){
        cout << "stone[" << i << "]\n";
        cout << "way : " << stones[i].way << " ";
        cout << "idx : " << stones[i].idx << " ";
        cout << "end : " << stones[i].end << "\n";
    }

    for(int i=0;i<ans_v.size();i++){
        cout << ans_v[i] << " ";
    }
    cout <<"\n";
}


void DFS(int depth, int sum){
    if(depth == 10){
        if(sum>ans) {
            cout << ans << "\n";
            ans = sum;
            ans_v = horse;
            print_stones();
        }
        return;
    }
    
    
    for(int i=1;i<=4;i++){
        // if(stones[i].end) continue;
        horse.push_back(i);
        //이전 상태 저장
        stone temp[5];
        memcpy(temp, stones, sizeof(struct stone)*5);

        int cur;
        cur = move(stones[i],dice[depth]);


        //겹치는지 체크
        bool overlab_flag=false;
        for(int j=1;j<=4;j++){
            if(i==j) continue;
            int other_val = ways[stones[j].way][stones[j].idx];
            if(cur != other_val) continue;
            //같은 값들 넘어왔다.
            //way 랑 idx 다르면 다른 것으로 분류한다.
            if(stones[j].way==stones[i].way && stones[j].idx == stones[i].idx){
                overlab_flag = true;
                break;
            }
            //하지만 25, 30, 35, 40 부분은 way, idx 다르더라도 겹친다.
            //번거롭지만 일일이 index 따져서 처리해준다.
            //25 : way10 5  way20 4 way30 5
            //30 : way10 6  way20 5 way30 6
            //35 : way10 7  way20 6 way30 7
            //40 : way10 8  way20 7 way30 8 out_way 20
            else{
                switch (cur){
                    case 25:
                        if(stones[j].way==1 && stones[j].idx==4) overlab_flag = true;
                        if(stones[j].way==2 && stones[j].idx==3) overlab_flag = true;
                        if(stones[j].way==3 && stones[j].idx==4) overlab_flag = true;
                        break;
                    case 30:
                        if(stones[j].way==1 && stones[j].idx==5) overlab_flag = true;
                        if(stones[j].way==2 && stones[j].idx==4) overlab_flag = true;
                        if(stones[j].way==3 && stones[j].idx==5) overlab_flag = true;
                        break;
                    case 35:
                        if(stones[j].way==1 && stones[j].idx==6) overlab_flag = true;
                        if(stones[j].way==2 && stones[j].idx==5) overlab_flag = true;
                        if(stones[j].way==3 && stones[j].idx==6) overlab_flag = true;
                        break;
                    case 40:
                        if(stones[j].way==0 && stones[j].idx==20) overlab_flag = true;
                        if(stones[j].way==1 && stones[j].idx==7) overlab_flag = true;
                        if(stones[j].way==2 && stones[j].idx==6) overlab_flag = true;
                        if(stones[j].way==3 && stones[j].idx==7) overlab_flag = true;
                        break;
                    default :
                        break;
                }
                
            }
        }

        //겹친다면 원래대로 돌려놓고 다음 탐색
        if(overlab_flag) {
            memcpy(stones, temp, sizeof(struct stone)*5);
            horse.pop_back();
        }
        //겹치지 않는다면 DFS 진행
        else{
            DFS(depth+1, sum+cur);
            memcpy(stones, temp, sizeof(struct stone)*5);
            horse.pop_back();
        }
        
    }

}

void solve(){
    DFS(0,0);
    cout << ans;
}


int main(){
    Input();
    solve();


    return 0;
}