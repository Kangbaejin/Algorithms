/* 
 * baekjoon 19236
 * 
 * 청소년 상어
 * 
 * https://www.acmicpc.net/problem/19236
 * 
 * 
 * 아래 링크를 참고하여 구현하였다.
 * 
 * 블로그를 통해 변화 이전의 값을 저장하고 불러오는 함수를 구현하여
 * 이전의 상태로 되돌리는 아이디어를 배울 수 있었다.
 * 
 * 간단한 DFS 구현에서는 q에 넣고 빼고의 방식을 이용했는데,
 * 저장해야할 변수가 fish 라는 구조체를 선언하여 이요할 정도로 많았기 때문에,
 * 이를 구조적으로 구현해야 한다는 생각을 하는 것이 어려웠다.
 * 
 * 그리고 물고기 구조체를 작성하여 물고기가 죽었는지 여부를 사용한 것이 주요했다.
 * 방향의 값이 1~8을 이용하기 때문에 죽은 물고기의 방향을 0으로 설정해야 겠다고 마음먹고 구현을 시작했었다.
 * 구현을 하던 중 DFS 를 진행하며 죽었던 물고기를 되살려야 할 경우, 물고기의 원래 방향을 알 수 없는 문제가 발생했다.
 * 
 * 하지만 블로그처럼 죽었는지 살았는지 여부를 다른 bool 변수를 이용하여 판단한다면, 물고기가 죽었더라도 방향 정보가
 * fish 의 Dir 변수에 남아있기 때문에, DFS를 진행하는데 훨씬 편리했다.
 * 
 * 아래 블로그에서의 코드중 move_fish 함수에서 flag 를 사용하여
 * 움직일 수 없는 위치일때 아닌때를 판단 후에 같은 코드를 반복했는데,
 * 이는 do while 문을 이용하여 간략하게 변경했다.
 * 
 * 위에서 부터 아래까지 진행되는 코드들을 보며 정말 깔끔하게 구현이 잘 되었다고 느꼈다.
 * 
 * https://yabmoons.tistory.com/495
 */

#include <iostream>
#include <algorithm>

using namespace std;

struct fish{
    int x;
    int y;
    //Dir : 1~8 방향을 나타낸다.
    int Dir;
    bool Live;
};


int ans;
int value[4][4];
fish fish_list[17];

//방향에 관한 정수, 1~8 을 사용하기 위해 앞에 {0,0} 을 입력하여 사용
int dir[9][2] = {{0,0},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};

void copy_state(int Copy_A[][4], int A[][4], fish Copy_B[], fish B[]){
    //A 값을 Copy_A 에 B 값을 Copy_B 에 저장하는 상태를 복사하는 함수
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            Copy_A[i][j] = A[i][j];
        }
    }
    for(int i=1;i<=16;i++){
        Copy_B[i] = B[i];
    }
}


//물고기의 좌표만 바꿔주는 함수이다.
void Swap_fish(int idx1, int idx2){
    fish temp = fish_list[idx1];
    fish_list[idx1].x = fish_list[idx2].x;
    fish_list[idx1].y = fish_list[idx2].y;

    fish_list[idx2].x = temp.x;
    fish_list[idx2].y = temp.y;
}


void move_fish(){
    for(int i=1;i<=16;i++){
        if(fish_list[i].Live == false) continue;

        int x = fish_list[i].x;
        int y = fish_list[i].y;
        int Dir = fish_list[i].Dir;
        int nDir = Dir;

        int nx = x + dir[Dir][0];
        int ny = y + dir[Dir][1];
        do{
            if(!(nx<0 || nx>=4 || ny<0 || ny>=4)){
                //물고기가 먹혀서 빈자리라면, 해당 위치에 대한 물고기 정보가 없으므로
                //swap fish 사용하지 못한다.
                if(value[nx][ny]==0){
                    fish_list[i].x = nx;
                    fish_list[i].y = ny;
                    fish_list[i].Dir = nDir;
                    value[nx][ny] = i;
                    value[x][y] = 0;
                    break;
                }
                //물고기가 있다면 두 물고기 위치를 바꾼다.
                else if(value[nx][ny] != -1){
                    Swap_fish(i, value[nx][ny]);
                    fish_list[i].Dir = nDir;
                    swap(value[x][y], value[nx][ny]);
                    break;
                }
            }

            nDir = nDir+1;
            if(nDir== 9) nDir = 1;
            nx = x + dir[nDir][0];
            ny = y + dir[nDir][1];
        }while(nDir != Dir);
    }

}





void make_state(int x, int y, int nx, int ny, int fish_num, bool T){
    if(T == true){
        //상어가 있던 x, y 위치는 빈자리가 되고, nx ny 위치로 상어가 이동하는 상황
        value[x][y] = 0;
        value[nx][ny] = -1;
        fish_list[fish_num].Live = false;
    }
    else{
        //상어에게 먹히기 전 상황으로 돌려놓는다.
        value[x][y] = -1;
        value[nx][ny] = fish_num;
        fish_list[fish_num].Live = true;

    }
}


void DFS(int x, int y, int Dir, int Sum){
    ans = max(ans, Sum);

    int Copy_value[4][4];
    fish Copy_fish_list[17];
    copy_state(Copy_value, value, Copy_fish_list, fish_list);


    move_fish();

    for(int i=1;i<=3;i++){
        int nx = x + dir[Dir][0] * i;
        int ny = y + dir[Dir][1] * i;
        //상어가 움직이는 방향이 배열 밖이라면 break
        if(!(nx<0 || nx>=4 || ny<0 || ny>=4)){
            //빈 곳이라면 그냥 지나가고 다음 장소 확인
            if(value[nx][ny]==0) continue;
            
            int fish_num = value[nx][ny];
            int nDir = fish_list[fish_num].Dir;
            //상어가 물고기 먹는 상황 실행
            make_state(x,y,nx,ny, fish_num, true);

            //상어가 위 상황처럼 물고기를 먹었다는 상황을 기준으로 DFS 실행
            DFS(nx,ny,nDir, Sum + fish_num);

            //상어가 물고기 먹기 전의 상황으로 되돌리기
            make_state(x,y,nx,ny, fish_num, false);
        }
        else break;
    }

    //이 DFS 함수가 실행되기 전의 상황을 저장해놨던 배열들을 통해 원래의 상태 복원
    copy_state(value, Copy_value, fish_list, Copy_fish_list);

}

void Solution(){
    int fish_num = value[0][0];
    int Dir = fish_list[fish_num].Dir;
    fish_list[fish_num].Live = false;
    value[0][0] = -1;

    DFS(0,0, Dir, fish_num);

    cout << ans;
}



int main(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            int a,b;
            cin >> a >> b;
            value[i][j] = a;
            fish_list[a]={i,j,b, true};
        }
    }

    Solution();

    return 0;
}