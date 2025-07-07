/* 
 * baekjoon 9376
 * 
 * 탈옥
 * 
 * https://www.acmicpc.net/problem/9376
 * 
 * 
 * 참고링크
 * https://rebas.kr/770
 * 
 * 위 링크대로 제출하면 틀린다. 따라서 93 Line 추가
 * 
 */

#include <iostream>
#include <cstring>
#include <deque>
#include <climits>

using namespace std;

int n;
const int MAX = 102;
int h,w;

char a[MAX][MAX];
int dist[MAX][MAX][3];

deque<pair<int,int>> dq;

int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

void BFS(){
    //외부에서 문을 열기 시작하는 경우 dq에 입력
    dq.push_back({0,0});
    for(int k=0; k<3; k++){
        int sx = dq.back().first;
        int sy = dq.back().second; 
        dq.pop_back();

        deque<pair<int,int>> q;
        q.push_back({sx,sy});
        dist[sx][sy][k] = 0;

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop_front();
            for(int i=0; i<4; i++){
                int nx = x+dir[i][0];
                int ny = y+dir[i][1];
                if(nx < 0 || nx > h+1 || ny < 0 || ny > w+1) continue;
                if(dist[nx][ny][k] >= 0 || a[nx][ny] == '*') continue;
                if(a[nx][ny] == '.'){
                    dist[nx][ny][k] = dist[x][y][k];
                    q.push_front({nx,ny});
                }
                else if(a[nx][ny] == '#'){
                    dist[nx][ny][k] = dist[x][y][k]+1;
                    q.push_back({nx,ny});
                }
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        memset(dist, -1, sizeof(dist));
        cin >> h >> w;
        for(int i=0;i<h+2;i++){
            for(int j=0;j<w+2;j++){
                //테두리 빈칸으로 채우기
                if(i==0 || i==h+1 || j==0 || j==w+1) a[i][j] = '.';
                else cin >> a[i][j];
                //죄수1, 죄수2 위치에서 문을 열기 시작하는 경우 dq에 입력
                if(a[i][j] == '$'){
                    a[i][j] = '.';
                    dq.push_back({i,j});
                }
            }
        }
        BFS();
        int ans = INT_MAX;
        for(int i=0;i<h+2;i++){
            for(int j=0;j<w+2;j++){
                if(a[i][j] == '*') continue;
                if(dist[i][j][0]==-1 || dist[i][j][1]==-1 || dist[i][j][2]==-1) continue;
                int k = dist[i][j][0] + dist[i][j][1] + dist[i][j][2];
                if(a[i][j] == '#') k-=2;
                if(ans > k) ans = k;
            }
        }

        cout << ans << "\n";
    }


    return 0;
}