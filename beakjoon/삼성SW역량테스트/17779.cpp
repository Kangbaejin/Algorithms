/* 
 * baekjoon 17779
 * 
 * 게리맨더링 2
 * 
 * https://www.acmicpc.net/problem/17779
 * 
 * 
 * 
 * 우선 5개의 영역으로 모두 나누어준다.
 * 각 영역의 인구의 합을 배열 형태에 update 한다.
 * 인구 조사가 끝난 뒤, 최대 최소를 업데이트 하고 그 둘의 차이를 비교한다.
 * 
 * 이때 최대 최소의 차이가 0인경우 0을 리턴,
 * 0 이 아니라면 계속 업데이트 하면서 브루트포스하게 탐색
 * 
 * 
 * 모든 경우를 포함시키기 위한 부르트포스 탐색방법
 * 
 * 모든 x, y, d1, d2 의 경우를 포함해야한다.
 * 
 * 1. (x,y) 가 주어진 상황에서 각 꼭짓점은 map 을 벗어나면 안된다. (이 조건이 문제에서 준 조건)
 * 2. 위의 조건을 만족하는 기준점인 (x,y) 에서 가능한 d1,d2 를 모두 탐색해야한다.
 * 
 * d1, d2 를 모두 각각 1로 초기화한 후 while 문 두개를 이용하여  d1 d2 조건을 만족하는 탐색 진행
 * 
 */

#include <iostream>
#include <algorithm>
#define max_rc 21

using namespace std;


int map[max_rc][max_rc];
int zone[max_rc][max_rc];
int popular[5];
int ans = -1;
int N;

void Input(){
    cin >> N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> map[i][j];
        }
    }
    return;
}

bool valid_check(int x, int y, int d1, int d2){
    int x0 = x, y0 = y;
    int x1 = x+d1, y1 = y-d1;
    int x2 = x+d1+d2, y2 = y-d1+d2;
    int x3 = x+d2, y3 = y+d2;

    if(x1 > N || y1 < 1) return false;
    if(x2 > N || y2 > N) return false;
    if(x3 > N || y3 > N) return false;
    if(x3 > N || y3 < 1) return false;
    else return true;
}


void zone_separation(int x, int y, int d1, int d2){
    //각 꼭짓점 좌표 -> 반시계 방향으로 0, 1, 2, 3 순서
    int x0 = x, y0 = y;
    int x1 = x+d1, y1 = y-d1;
    int x2 = x+d1+d2, y2 = y-d1+d2;
    int x3 = x+d2, y3 = y+d2;


    //모든 선거구를 5로 초기화 하고 시작
    for(int i=1; i<=N;i++){
        for(int j=1; j<=N; j++){
            zone[i][j] = 5;
        }
    }


    //1번 선거구 설정
    int end = y0;
    for(int i=1; i<x1; i++){
        if(i >= x0) end--;
        for(int j=1; j<=end; j++){
            zone[i][j] = 1;
        }
    }

    //2번 선거구 설정
    int start=y0+1;
    for(int i=1; i<=x3; i++){
        if(i > x0) start++;
        for(int j=start; j<=N; j++){
            zone[i][j] = 2;
        }
    }

    //3번 선거구 설정
    end = y1-1;
    for(int i=x1; i<=N; i++){
        for(int j=1; j<=end; j++){
            zone[i][j] = 3;
        }
        if(end < y2-1){
            end++;
        }
    }

    //4번 선거구 설정
    start = y3;
    for(int i=x3+1; i<=N; i++){
        for(int j=start; j<=N; j++){
            zone[i][j] = 4;
        }
        if(start > y2){
            start--;
        }
    }

    // //꼭지점 표시
    // zone[x0][y0] = 0;
    // zone[x1][y1] = 0;
    // zone[x2][y2] = 0;
    // zone[x3][y3] = 0;

    return;
}

void print_zone(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cout << zone[i][j];
            cout << " ";
        }
        cout << "\n";
    }
}


void function_pop(int x, int y, int d1, int d2){
    //calculate pop
    int sum[6]={0,0,0,0,0,0};
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            sum[zone[i][j]] += map[i][j];
        }
    }

    sort(sum, sum+6);
    int gap = sum[5]- sum[1];

    if(ans == -1){
        ans = gap;
        return;
    }

    else{
        ans = min(gap, ans);
    }
    
}


void solve(){
    for(int x=1; x<=N; x++){
        for(int y=1; y<=N; y++){
            for(int d1=1; d1<=N; d1++){
                for(int d2=1; d2<=N; d2++){
                    if(valid_check(x,y,d1,d2)){
                        zone_separation(x,y,d1,d2);
                        // print_zone();
                        // cout << "\n";
                        function_pop(x,y,d1,d2);
                    }
                }
            }
        }
    }


}



int main(){
    Input();
    solve();
    cout << ans;

    return 0;
}