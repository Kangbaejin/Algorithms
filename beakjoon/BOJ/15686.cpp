/* 
 * baekjoon 15686
 * 
 * 치킨 배달
 * 
 * https://www.acmicpc.net/problem/15686
 * 
 * 브루트포스 알고리즘
 * 
 */




/*
 * 모든 값을 배열에 저장하는 것이 아니라,
 * 집의 위치와 가게의 위치를 벡터에 저장하여 이용하자
 * 
 * 굳이 이중배열을 선언해서 넣을 필요 없이 각각 입력 받는 값을 이용해서 변수 처리 해보기
 * 
 */




#include <iostream>
#include <climits>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int min_legnth = INT_MAX;

void solve(vector<pair<int,int>> hu, vector<pair<int,int>> st){
    int temp_min;
    int temp;
    int sum=0;
    for(int i=0;i<hu.size();i++){
        temp_min=INT_MAX;
        for(int j=0;j<st.size();j++){
            temp = abs(hu[i].first - st[j].first) + abs(hu[i].second - st[j].second);
            if(temp < temp_min)
                temp_min = temp;
        }
        sum += temp_min;
    }
    if(sum < min_legnth)
        min_legnth = sum;
    return;
}




int main(){
    int N, M;
    cin >> N >> M;

    int **a = new int*[N];

    for(int i=0; i<N; i++){
        a[i] = new int[N];
    }

    vector<pair<int, int>> house;
    vector<pair<int, int>> store;

    int x;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> x;
            a[i][j] = x;
            if(x == 1)
                house.push_back(make_pair(i,j));
            else if(x == 2)
                store.push_back(make_pair(i,j));
        }
    }

    if(store.size()==M){
        solve(house,store);
        for(int i=0;i<N;i++)
            delete [] a[i];
        delete [] a;
    }

    else{
        vector<int> temp;
        int st_size=store.size();
        for(int i=0;i<st_size;i++){
            if(i<M)
                temp.push_back(1);
            else
                temp.push_back(0);
        }
        
        do{
            vector<pair<int,int>> temp_st(store);
            for(int i=0;i<st_size;i++){
                if(temp[i]==0)
                    temp_st.erase(temp_st.begin()+i);
            }
            solve(house,temp_st);
        }while(prev_permutation(temp.begin(),temp.end()));

        for(int i=0;i<N;i++)
            delete [] a[i];
        delete [] a;
    }

    cout << min_legnth;
    return 0;



}