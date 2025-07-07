/* 
 * baekjoon 14890
 * 
 * 경사로
 * 
 * https://www.acmicpc.net/problem/14890
 * 
 * 
 * 나는 구현 시에, 앞의 값이 크고 뒤에 오는 값이 작은 -1 일 때의 경우
 * 현재 위치 뒤의 L 개의 칸을 확인하여 경사로를 놓을 수 있는지 판단하고,
 * 
 * 앞의 값이 작고 뒤에 오는 값이 큰 +1 일 때의 경우
 * 현재 위치 앞의 L 개 칸을 확인하여 경사로를 놓을 수 있는지 판단하도록 구현했다.
 * 
 * 하지만 경사로를 놓고 난 다음의 처리에서 문제가 막혀 해결할 수 없었다.
 * 
 * 예를 들어 경사로의 길이가 2일 때, 2 2 1 1 2 2 의 경우에서
 * 2 2 1 1 로 내려가는 경사로를 놓은 뒤에, 2 2 에는 설치하지 못해야 하는데,
 * 경사로가 설치 되었는지 판단할 수 있는 수단이 없어 다시 2 2    1 1 2 2  위치에서
 * 오르막길을 설치할 수 있다고 판단하게 되었다.
 * 
 * 
 * 아래의 사람은 이전 길의 길이를 기록해 나가며, L 이상이면 설치할 수 있도록 코드를 구현하였다.
 *
 * 문제를 푸는데 매우 큰 영향을 주는 아이디어는 아니지만,
 * MAP의 입력을 받을 때, 행렬의 위치를 바꾼 입력을 하나 더 받아서,
 * 똑같은 함수를 적용하는 아이디어에 감탄했다.
 * 
 * 입력을 하나 더 받는 것을 통해 함수를 행에 맞도록 열에 맞도록 따로 수정하지 않아도 되고,
 * 하나의 함수로 두 방향의 값을 처리할 수 있는 장점을 가졌다.
 * 
 * 나는 본 문제를 풀 때, 행을 검사하는 함수, 열을 검사하는 함수 두개를
 * 각 열과 행을 하나의 일차원 배열에 복사하여 이용하는 방식을 이용했었는데,
 * 
 * 아래 코드와 같은 입력을 조절하는 생각을 배울 수 있었다.
 * 
 * https://yabmoons.tistory.com/49
 * 
 */

#include<iostream>
#include<cmath>
 
#define endl "\n"
#define MAX 100
using namespace std;
 
int N, L;
int MAP[MAX][MAX];
int MAP2[MAX][MAX];
 
void Input()
{
    cin >> N >> L;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> MAP[i][j];
            MAP2[j][i] = MAP[i][j];
        }
    }
}
 
bool Can_Make_Road(int A[][MAX], int x, int y)
{
    int Standard = A[x][y + 1];
    for (int j = y + 1; j < y + 1 + L; j++)
    {
        if (A[x][j] != Standard) return false;
    }
    return true;
}
 
int Make_Road(int A[][MAX])
{
    int Total_Road = 0;
    for (int i = 0; i < N; i++)
    {
        bool Can_Road = true;
        int Before_Road = 1;
 
        for (int j = 0; j < N - 1; j++)
        {
            if (A[i][j] == A[i][j + 1]) Before_Road++;    // 1번 Case
            else if (A[i][j] == A[i][j + 1] + 1)        // 2번 Case 앞에것이 더 높을 때
            {
                if (Can_Make_Road(A, i, j) == true)
                {
                    j = j + L - 1;
                    Before_Road = 0;
                }
                else
                {
                    Can_Road = false;
                    break;
                }
            }
            else if (A[i][j] + 1 == A[i][j + 1])        // 3번 Case 뒤에것이 더 높을 때
            {
                if (Before_Road >= L)
                {
                    Before_Road = 1;
                }
                else
                {
                    Can_Road = false;
                    break;
                }
            }
            else if (abs(A[i][j] - A[i][j + 1]) >= 2)
            {
                Can_Road = false;
                break;
            }
        }
 
        if (Can_Road == true)
        {
            Total_Road++;
        }
    }
    return Total_Road;
}
 
void Solution()
{
    int A = Make_Road(MAP);
    int B = Make_Road(MAP2);
 
    cout << A + B << endl;
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
 
    return 0;
}
