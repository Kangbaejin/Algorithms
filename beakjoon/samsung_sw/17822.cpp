/* 
 * baekjoon 17822
 * 
 * 원판 돌리기
 * 
 * https://www.acmicpc.net/problem/17822
 * 
 * 
 */


#include <iostream>
#include <vector>
#include <queue>


using namespace std;

int N,M,T, remain_nums;
vector<vector<int>> map;

struct xdk{
    int x,d,k;
};

vector<xdk> v;


void print_map(){
    for(int i=1;i<=N;i++){
        for(int j=0;j<M;j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void Input(){
    vector<int> temp_v;
    cin >> N >> M >> T;
    int temp;

    //시작 인덱스를 1로 맞추기위해 0번에 0값으로 채우기
    for(int i=0;i<M;i++) temp_v.push_back(0);
    map.push_back(temp_v);

    for(int i=0;i<N;i++){
        temp_v.clear();
        for(int j=0;j<M;j++){
            cin >> temp;
            temp_v.push_back(temp);
        }
        map.push_back(temp_v);
    }
    remain_nums = N*M;
    int x,d,k;
    for(int i=0;i<T;i++){
        cin >> x >> d >> k;
        v.push_back({x,d,k});
    }
}


bool del_flag=false;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
void BFS(int ix, int iy){
    bool BFS_flag=false;
    if(map[ix][iy]==0) return;
    
    queue<pair<int,int>> q;
    int x = ix, y = iy;
    int temp = map[x][y];
    //초기 BFS 탐색 시 우선 삭제한다. flag 통해 변화 없으면 복구한다.
    map[x][y]=0;
    remain_nums--;

    q.push({x,y});
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int newX = x+dir[i][0];
            int newY = y+dir[i][1];
            // //이미 삭제되어 없는 경우
            // if(map[newX][newY]==0) continue;
            //범위를 벗어나는 경우 (y좌표는 원형 순환이므로 한칸 씩 여유있게 확보)
            if(newX<1 || newX>N || newY<-1 || newY>M) continue;
            //원형 순환에 맞게 index 조정
            if(newY==-1) newY = M-1;
            else if(newY==M) newY = 0;

            if(temp==map[newX][newY]){
                BFS_flag = true;
                del_flag = true;
                map[newX][newY] = 0;
                remain_nums--;
                q.push({newX,newY});
            }
        }
    }
    //지워진 것이 없다면 복구
    if(!BFS_flag){
        map[x][y]=temp;
        remain_nums++;
    }
    return;
}

/* 
 * x : 돌릴 원판 숫자, x의 배수의 원판들을 돌린다.
 * d : 돌리는 방향 (0 : 시계방향, 1 : 반시계방향)
 * k : 돌리는 횟수
 */
void rotate(int xi, int di, int ki){
    int cnt=1;
    int x = xi*cnt;
    int d = di;
    int k = ki;
    vector<int> temp;
    while(x<=N){
        temp.clear();
        //어차피 M 번 탐색해서 반대방향인 경우 k 를 m-k 로 바꾸고 하면 똑같은 코드로 실행가능
        //반시계방향으로 동작하도록 구현
        if(d==0) k = M-ki;
        for(int i=k;i<M;i++) temp.push_back(map[x][i]);
        for(int i=0;i<k;i++) temp.push_back(map[x][i]);
        map[x]=temp;
        x = xi*(++cnt);
    }
}

/* 
 * 1. 인접하면서 같은 수 지우기
 * 2. 1이 아닌 경우 원판의 수의 평균 구해서 조정
 */
void update(){
    del_flag = false;
    int sum=0;
    int non_zero_cnt=0;
    for(int i=1;i<=N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j]!=0) {
                sum+=map[i][j];
                non_zero_cnt++;
                BFS(i,j);
            }
        }
    }

    //1 진행했는데 del_flag 가 아직 false 라면 지워진 것이 없는 것이다. (BFS 내부에서 체크)
    //따라서 2 를 진행한다.
    
    //만약 위의 BFS 진행 시 변경이 있었다면 해당 조건문이 실행되지 않는다.
    //변경이 되지 않았을 경우 BFS를 통한 변화가 없기 때문에
    //위의 이중 for 문에서 얻은 sum, cnt 값을 이용해도 문제가 없다 (중복되는 탐색 제거)
    if(!del_flag){
        double avg;
        if(non_zero_cnt==0) avg=0;
        else avg = (double)sum/non_zero_cnt;
        for(int i=1;i<=N;i++){
            for(int j=0;j<M;j++){
                if(map[i][j]!=0) {
                    if(map[i][j]>avg) map[i][j]--;
                    else if(map[i][j]<avg) map[i][j]++;
                }
            }
        }
    }

}

void solve(){
    for(int i=0;i<T;i++){
        if(remain_nums==0) break;
        int x,d,k;
        x=v[i].x;
        d=v[i].d;
        k=v[i].k;
        rotate(x,d,k);
        update();
    }

    int ans=0;
    for(int i=1;i<=N;i++){
        for(int j=0;j<M;j++){
            ans+=map[i][j];
        }
    }

    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Input();
    solve();
    return 0;
}
