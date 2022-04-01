/* 
 * baekjoon 23288
 * 
 * 주사위 굴리기 2
 * 
 * https://www.acmicpc.net/problem/23288
 * 
 * 
 * 
 */

#include <iostream>
#include <queue>
#define map_max 21
#define oper_max 1000

using namespace std;

struct dice{
    int x;
    int y;
    int dice_plane[7];
    int dir;
};

int map[map_max][map_max];
int DIR[5][2] = {{0,0},{0,1},{0,-1},{-1,0},{1,0}};

int N,M, tests;
dice one_dice;



void Input(){
    cin >> N >> M  >> tests;
    one_dice.x = 1;
    one_dice.y = 1;
    one_dice.dir = 1;
    for(int i=1;i<=6;i++){
        one_dice.dice_plane[i]=i;
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> map[i][j];
        }
    }
}

//연속된 칸수를 구하는 갯수
//bfs 형태로 구현
int cont_count(int xx, int yy){
    int visited[map_max][map_max]={false,};
    int value = map[xx][yy];
    
    int count = 1;

    queue<pair<int, int>> q;
    q.push({xx,yy});
    visited[xx][yy] = true;

    while(!q.empty()){

        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=1;i<=4;i++){
            int newx = x + DIR[i][0];
            int newy = y + DIR[i][1];
            if(newx >=1 && newx <= N && newy >=1 && newy <=M && !visited[newx][newy] && (map[newx][newy]==value)) {
                count++;
                visited[newx][newy]=true;
                q.push({newx, newy});
            }
        }

    }
    return value * count;
}




int moving(dice &dice){
    int newr = dice.x+DIR[dice.dir][0];
    int newc = dice.y+DIR[dice.dir][1];

    if(newr<1 || newr>N || newc<1 || newc> M){
        if(dice.dir%2 == 0){
            dice.dir--;
        }
        else{
            dice.dir++;
        }
        newr = dice.x+DIR[dice.dir][0];
        newc = dice.y+DIR[dice.dir][1];
    }
    //동 1   오른쪽
    if(dice.dir == 1){
        int temp = dice.dice_plane[1];
        dice.dice_plane[1] = dice.dice_plane[4];
        dice.dice_plane[4] = dice.dice_plane[6];
        dice.dice_plane[6] = dice.dice_plane[3];
        dice.dice_plane[3] = temp;
    }
    //서 2   왼쪽
    else if(dice.dir == 2){
        int temp = dice.dice_plane[1];
        dice.dice_plane[1] = dice.dice_plane[3];
        dice.dice_plane[3] = dice.dice_plane[6];
        dice.dice_plane[6] = dice.dice_plane[4];
        dice.dice_plane[4] = temp;
    }
    //북 3
    else if(dice.dir == 3){
        int temp = dice.dice_plane[1];
        dice.dice_plane[1] = dice.dice_plane[5];
        dice.dice_plane[5] = dice.dice_plane[6];
        dice.dice_plane[6] = dice.dice_plane[2];
        dice.dice_plane[2] = temp;  
    }
    //남 4
    else if(dice.dir == 4){
        int temp = dice.dice_plane[1];
        dice.dice_plane[1] = dice.dice_plane[2];
        dice.dice_plane[2] = dice.dice_plane[6];
        dice.dice_plane[6] = dice.dice_plane[5];
        dice.dice_plane[5] = temp;  
    }
    //A > B  시계방향
    if(dice.dice_plane[6] > map[newr][newc]){
        if(dice.dir == 1) dice.dir = 4;
        else if(dice.dir == 2)  dice.dir = 3;
        else if(dice.dir == 3)  dice.dir = 1;
        else if(dice.dir == 4)  dice.dir = 2;
    }
    //A < B   반시계 방향
    else if(dice.dice_plane[6] < map[newr][newc]){
        if(dice.dir == 1) dice.dir = 3;
        else if(dice.dir == 2)  dice.dir = 4;
        else if(dice.dir == 3)  dice.dir = 2;
        else if(dice.dir == 4)  dice.dir = 1;
    }   
    dice.x = newr;
    dice.y = newc;
    
    int count = cont_count(newr,newc);
    return count;
}


void solve(){
    int ans = 0;
    for(int i=0;i<tests;i++){
        int temp_score;
        temp_score = moving(one_dice);
        ans += temp_score;
    }

    cout << ans;
}


int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    Input();
    solve();
    return 0;
}