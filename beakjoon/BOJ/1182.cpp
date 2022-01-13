/* baekjoon 1182
 * 
 * 부분수열의 합
 * 
 * https://www.acmicpc.net/problem/1182
 * 
 * 
 * 6603 번대의 풀이와 비슷한 방식으로, next_permutation 함수를 이용했는데
 * 
 * 다른 사람들은 재귀 함수를 이용하거나, DFS 알고리즘을 이용하여 풀었다.
 * 백트래킹 + pruning 의 방법을 추가적으로 고려해 봐야 할 것 같다.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int numbers = 0;
    int goal = 0;
    int x = 0;
    vector<int> v;
    vector<int> temp;

    int count = 0;

    cin >> numbers >> goal;


    for(int i=0;i<numbers;i++){
        cin >> x;
        v.push_back(x);
    }

    int sum = 0;

    for(int i=0;i<numbers;i++){
        temp.clear();

        for(int k=numbers-i-1; k>0; k--){
            temp.push_back(0);
        }
        for(int j=i; j>=0; j--){
            temp.push_back(1);
        }
        do{
            sum = 0;
            for(int l=0;l<numbers;l++){
                if(temp[l]==1)
                    sum += v[l];
            }

            if(sum == goal)
                count++;
        }while(next_permutation(temp.begin(),temp.end()));
    }

    cout << count;

    return 0;
}