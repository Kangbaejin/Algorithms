/* 
 * baekjoon 1422
 * 
 * 숫자의 신
 * 
 * https://www.acmicpc.net/problem/1422
 * 
 * 
 * 
 * compare 함수를 만드는 것이 정말 간단하고 명쾌했다.
 * 나는 받은 문자열의 최대길이에 맞춰 모든 문자열 뒤에 9를 넣어 사전순 정렬하여 비교하려했다.
 * 예를들어 9, 15, 997 이 들어왔다면,
 * 999, 159, 997 로 비교하여 999, 997, 159 순으로 정렬한다.
 * 즉 999715 가 가장큰 수가 된다 로 구현하려고 했었다.
 * 
 * 하지만
 * sort 의 compare 함수를 아래 링크처럼 구현하니 깔끔하고 정말 간단하게 풀렸다.
 * https://chosh95.tistory.com/487
 * 
 * 53번째줄의 조건문을 그냥 if(max<temp) max = temp 로 실행했을때 틀렸다는 결과를 냈는데,
 * 예제는 문제없이 통과가 되었었다. 왜, 어떤 이유로 틀렸는지 더 찾아봐야겠다.
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

//두 문자열을 concat 해본 결과중 큰 값이 되도록 정렬
bool comp(string s1, string s2){
    if(s1+s2 > s2+s1)
        return true;

    return false;
}

vector<string> value;

int K, N;

int main(){
    cin >> K >> N;
    
    string temp = "";
    string max = "";
    for(int i=0;i<K;i++){
        cin >> temp;
        value.push_back(temp);
        if(max.size() < temp.size() || (max.size()==temp.size() && max < temp))
            max = temp;
    }


    for(int i=0;i<N-K;i++){
        value.push_back(max);
    }

    sort(value.begin(),value.end(), comp);


    for(int i=0;i<N;i++){
        cout << value[i];
    }

    return 0;
}