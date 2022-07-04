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
 * 1. (x,y) 에서 (1 ≤ x < x+d1+d2 ≤ N) , (1 ≤ y-d1 < y < y+d2 ≤ N) 기준을 만족해야한다.
 * 2. 위의 조건을 만족하는 기준점인 (x,y) 에서 가능한 d1,d2 를 모두 탐색해야한다.
 * 
 * d1, d2 를 모두 각각 1로 초기화한 후 while 문 두개를 이용하여  d1 d2 조건을 만족하는 탐색 진행
 * 
 */

#include <iostream>
#include <cstdio>
#define max_rc 21

using namespace std;


int map[max_rc][max_rc];
int zone[max_rc][max_rc];
int popular[5];
int gap = -1;
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
    if((1<=x && x+d1+d1 <= N) && (1<=y-d1 && y+d2 <= N)) return true;
    else return false;
}


void zone_separation(int x, int y, int d1, int d2){
    //모든 선거구를 5로 초기화 하고 시작
    for(int i=1; i<=N;i++){
        for(int j=1; j<=N; j++){
            zone[i][j] = 5;
        }
    }

    //1번 선거구 설정
    for(int i=1; i<x+d1; i++){
        for(int j=1; j<=y; j++){
            zone[i][j] = 1;
        }
    }

    //2번 선거구 설정
    for(int i=1; i<=x+d2; i++){
        for(int j=y+1; j<=N; j++){
            zone[i][j] = 2;
        }
    }

    //3번 선거구 설정
    for(int i=x+d1; i<=N; i++){
        for(int j=1; j<y-d1+d2; j++){
            zone[i][j] = 3;
        }
    }

    //4번 선거구 설정
    for(int i=x+d2+1; i<=N; i++){
        for(int j=y-d1+d2; j<=N; j++){
            zone[i][j] = 4;
        }
    }

    //5번 선거구 설정
    int x0 = x, y0 = y;
    int x1 = x+d1, y1 = y-d1;
    int x2 = x1+d2, y2 = y1+d2;
    int x3 = x2-d1, y3 = y2+d1;


    for(int i=x+d2+1; i<=N; i++){
        for(int j=y-d1+d2; j<=N; j++){
            zone[i][j] = 4;
        }
    }    
    


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
    
}


void solve(){
    for(int x=1; x<=N; x++){
        for(int y=1; y<=N; y++){
            for(int d1=1; d1<=N; d1++){
                for(int d2=1; d2<=N; d2++){
                    if(valid_check(x,y,d1,d2)){
                        zone_separation(x,y,d1,d2);
                        print_zone();
                        cout << "\n";

                    }
                }
            }
        }
    }


}



int main(){
    Input();
    solve();
    cout << gap;

    return 0;
}