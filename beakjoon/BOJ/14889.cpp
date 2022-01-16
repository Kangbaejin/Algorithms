/* 
 * baekjoon 14889
 * 
 * 스타트와 링크
 * 
 * https://www.acmicpc.net/problem/14889
 * 
 * 브루트포스 알고리즘
 * 백트래킹
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int N;
    cin >> N;
    int *arry = new int[N*N];

    for(int i=0; i<N*N; i++){
        cin >> arry[i];
    }

    vector<int> v;

    for(int i=0;i<N;i++){
        if(i<N/2)
            v.push_back(0);
        else
            v.push_back(1);
    }

    vector<int> star;
    vector<int> link;
    int min = 2000;
    int sum;
    do{
        star.clear();
        link.clear();


        sum = 0;
        for(int i=0;i<N;i++){
            if(v[i]==0)
                star.push_back(i);
            else
                link.push_back(i);
        }

        for(int i=0;i<N/2;i++){
            for(int j=0;j<N/2;j++){
                sum += arry[star[i]*N+star[j]];
            }
        }

        for(int i=0;i<N/2;i++){
            for(int j=0;j<N/2;j++){
                sum -= arry[link[i]*N+link[j]];
            }
        }

        if(sum==0){
            min = 0;
            break;
        }

        if(abs(sum)<min)
            min = abs(sum);

    }while(next_permutation(v.begin(),v.end()));

    cout << min;

    return 0;
}



/*
 *
 * 내가 푼 답으로는 52ms 가 걸렸고, 아래 링크의 사용자가 분 방법은 1ms 도 걸리지 않았다.
 * 
 * https://www.acmicpc.net/source/27975340
 *
 * 나는 해당 문제를 풀기위해 당연히 팀을 절반씩 나눈 모든 경우를 탐색하여
 * 가장 작은 sum 값을 갖는다면 해당 값을 출력하도록 구현하려고 노력했다.
 * 이를 위해 0011 0101 0110 ... 식으로 탐색을하여 모든 경우를 반복문을 통해 탐색했는데,
 * 사용된 여러 반복문에 의해 이렇게 실행시간이 오래 걸렸던 것 같다.
 * 
 * 하지만 링크의 사람은, solve 라는 함수를 분기하는 과정에서, 각 index 마다 팀에
 * 합류시키는 경우와 그렇지 않은 경우를 재귀적으로 탐색하여 최종적으로 min 값을 구하도록 설정하였다.
 * 
 * 이 사람의 풀이에서 최소가 아닌 경우들은 (에를들어, 팀에 모두 들어오지 않는 경우) 애초에
 * 최솟값만을 기록하며 진행하는 과정이기 때문에 상관할 필요가 없다.
 * 
 * 전체 시너지에서 팀에 합류하여 각 팀에서 발휘하는 시너지의 총합을 빼 나가며 가장 적게 남아있는 경우를 구했다.
 * 
 */



/*
#include <iostream>
#include <climits>
int N, total = 0;       // total : synergy 테이블 총합
int synergy_sum[20];    // idx 번째 row, col 총합
int min = INT_MAX;

void solve(int idx, int team_cnt, int remain_total)
{
    // 팀에 사람이 충분해졌으면 종료
    if (team_cnt >= N / 2)
    {
        int abs = std::abs(remain_total);
        if (min > abs)
            min = abs;
        return;
    }

    // idx 번째 사람이 팀 합류하는지에 따라 분기
    if (idx < N - 1)
    {
        // 합류하는 경우
        // 팀에 합류시에 시너지 점수 row, col 총합을 빼나가면
        // 팀이 나뉜 후 남은 값이 각 팀간 시너지 합의 차이가 됨
        solve(idx + 1, team_cnt + 1, remain_total - synergy_sum[idx]);

        // 합류하지 않는 경우 (모두 합류하지 않는 경우가 생기는데 최소값이 아니라 상관없음)
        solve(idx + 1, team_cnt, remain_total);
    }
}

int main() {
    int in;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> in;
            total += in;
            synergy_sum[i] += in;
            synergy_sum[j] += in;
        }
    }

    solve(0, 0, total);
    std::cout << min;
}



*/