/* 
 * baekjoon 20061
 * 
 * 모노미노도미노 2
 * 
 * https://www.acmicpc.net/problem/20061
 * 
 * 
 * green blue 업데이트 함수를 따로 만들지 말고,
 * green blue 배열을 똑같이 만들고,
 * red 를 x,y 좌표를 바꾼 형태를 넣어주는 방식을 적용 (x=y 대칭 형태로 적용 가능)
 * 
 * 1x1 인 경우는 좌표만 바꿔서 똑같이 업데이트하면 되고,
 * 2x1 인 경우 좌표도 바꾸고, 서로 반대 모양을 넣어주면 된다.
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

int green[6][4];
int blue[6][4];
int N, score;

struct txy{
    int t,x,y;
};

vector<txy> txy_v;

void print_map(int v[6][4]){
    for(int i=0; i<6; i++){
        for(int j=0;j<4;j++){
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
    cout <<"\n";
}


void Input(){
    cin >> N;
    txy one;
    for(int i=0;i<N;i++){
        cin >> one.t >> one.x >> one.y;
        txy_v.push_back(one);
    }
    
}

//초록색을 기준으로 작성
void push_block(int t, int x, int y, int v[6][4]){
    int newX=1;
    if(t==1){
        while(v[newX+1][y]!=1 && (newX+1<=5)){
            newX++;
        }
        v[newX][y]=1;
    }
    else if(t==2){
        while((v[newX+1][y]!=1 && v[newX+1][y+1]!=1) && (newX+1<=5)){
            newX++;
        }
        v[newX][y]=1;
        v[newX][y+1]=1;
    }

    else if(t==3){
        while((v[newX+1][y]!=1) && (newX+1<=5)){
            newX++;
        }
        v[newX][y]=1;
        v[newX-1][y]=1;
    }
}

void update_block(int t, int x, int y){
    if(t==1){
        push_block(t,x,y, green);
        push_block(t,y,x, blue);
    }
    if(t==2){
        push_block(t,x,y, green);
        push_block(3,y,x, blue);
    }
    if(t==3){
        push_block(t,x,y, green);
        push_block(2,y,x, blue);
    }
}

//꽉찬 라인 지우기 후, line 밀어내기 수행
void update_line(int v[6][4]){
    //꽉찬 라인 지우기
    vector< vector<int>> temp_vectors;
    int delete_cnt=0;
    int cnt;
    for(int i=0;i<=6;i++){
        cnt = 0;
        vector<int> temp;
        for(int j=0;j<4;j++){
            temp.push_back(v[i][j]);
            if(v[i][j]==1) cnt++;
        }
        if(cnt==4){
            delete_cnt++;
            score++;
            continue;
        }
        else{
            temp_vectors.push_back(temp);
        }
    }

    int idx=0;
    for(int i=0;i<6;i++){
        if(i<delete_cnt){
            for(int j=0;j<4;j++) v[i][j]=0;
        }
        else{
            for(int j=0;j<4;j++) v[i][j]=temp_vectors[idx][j];
            idx++;
        }
    }


    //라인 밀어내기
    int line_push_cnt=0;
    for(int i=0;i<2;i++){
        for(int j=0;j<4;j++){
            if(v[i][j]!=0) {
                line_push_cnt++;
                break;
            }
        }
    }

    while(line_push_cnt--){
        for(int i=4;i>=0;i--){
            for(int j=0;j<4;j++){
                v[i+1][j]=v[i][j];
            }
        }
        for(int j=0;j<4;j++){
            v[0][j]=0;
        }        
    }
}

void solve(){
    for(int i=0;i<N;i++){
        txy one = txy_v[i];
        update_block(one.t,one.x,one.y);
        update_line(green);
        update_line(blue);
    }

    int total_tiles=0;
    for(int i=0;i<6;i++){
        for(int j=0;j<4;j++){
            if(green[i][j]==1) total_tiles++;
            if(blue[i][j]==1) total_tiles++;
        }
    }

    cout << score << "\n" << total_tiles << "\n";
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    Input();
    solve();
    return 0;
}