/* 
 * baekjoon 1463
 * 
 * 1로 만들기
 * 
 * https://www.acmicpc.net/problem/1463
 * 
 * 
 */

#include <iostream>
#include <vector>
#define MAX 1000000
#define mini(a,b) (a<b ? a : b)
using namespace std;

int ary[MAX+1]={0,};




int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;

    ary[1] = 0;
    for(int i=2;i<MAX+1;i++){
        if(i%6 == 0){
            ary[i] = mini(mini(ary[i/3], ary[i/2]), ary[i-1]) + 1;
        }
        else if(i%3==0){
            ary[i] = mini(ary[i-1], ary[i/3]) + 1;
        }
        else if(i%2==0){
            ary[i] = mini(ary[i-1], ary[i/2]) + 1;
        }
        else{
            ary[i] = ary[i-1] + 1;
        }
    }

    cin >> N;
    cout << ary[N];

    return 0;
}


/*
https://www.acmicpc.net/source/32683506

#include <cstdio>
int f(int x) {
	if (x <2) { return 0; }
	int v1 = f(x/3) + x % 3 + 1;
	int v2 = f(x/2)+ x % 2 + 1;
	return v1<v2?v1:v2;
}
int main() {
	int x;
	scanf("%d", &x);
	printf("%d",f(x));
}

*/