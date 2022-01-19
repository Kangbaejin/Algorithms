/* 
 * baekjoon 2661
 * 
 * 좋은 수열
 * 
 * https://www.acmicpc.net/problem/2661
 * 
 * 
 * 
 * 내가 구현했을 당시엔 계속 시간초과가 발생했다.
 * 
 * dfs 알고리즘, 백트래킹에 대한 이해가 부족하다고 판단하여
 * 관련 내용을 공부하고 아래 블로그를 참고하여 구현하였다.
 * https://pangtrue.tistory.com/102
 * 
 * 위 코드 실행 시간은 8ms 로 나왔는데,
 * 다른 사용자들의 코드는 1ms 미만인 코드도 많아서 참고해보게 되었다.
 * 
 * https://www.acmicpc.net/source/37745669
 * 
 * 이 코드는 빈 문자열을 입력하여,
 * "" -> "1"   1을 넣었을 때 좋은 수열인 경우, 1을 추가하고
 * 추가 된 문자열을 다시 해당 함수로 호출하는 방식으로 구현했다.
 * 여기에서 조건에 맞는 경우에만 해당 함수가 호출되며,
 * 이 구현이 훨씬 효율적으로 느껴졌다.
 * 
 */


#include <iostream>
#include <string>
using namespace std;


int N;
bool flag=false;

void solve(string k, int depth){
    //이미 적절한 답을 찾았다면 return;
    if(flag)    return;

    int len = k.size();
    for(int i=1;i<=len/2;i++){
        if(k.substr(len-i,i)==k.substr(len-(2*i),i)){
            //substr 을 통해 k 의 일부를 추출하여 이용한다.
            //이때 len-i 위치에서 i 만큼의 값과 len-2*i 위치에서의 i 만큼의 값을 비교하여
            //같은 것이 발생할 경우 k를 비우고 return 한다.
            //이 과정에서 비교길이는 33 과 같이 길이가 1일때,
            //1212 와 같이 길이가 2일때 ... 해서 길이가 len/2 일때 까지 반복한다.
            k = "";
            return;
        }
    }

    if(depth > N) return;

    if(depth == N){
        flag = true;
        cout << k << '\n';
        return;
    }
    else{
        for(int i=0;i<N;i++){
            //depth 가 N 이 아니라면 재귀적으로 다시 실행시킨다.
            solve(k+"1",depth+1);
            solve(k+"2",depth+1);
            solve(k+"3",depth+1);
        }
    }
}

int main(){
    cin >> N;
    
    string s;
    solve(s,0);

    return 0;
}