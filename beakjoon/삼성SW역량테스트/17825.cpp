/* 
 * baekjoon 17825
 * 
 * 주사위 윷놀이
 * 
 * https://www.acmicpc.net/problem/17825
 * 
 * 
 */

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int ans=-1;

int way_10[] = {10,13,16,19,25,30,35,40};
int way_20[] = {22,24,25,30,35,40};
int way_30[] = {28,27,26,25,30,35,40};

int dice[10];
void Input(){
    for(int i=0;i<10;i++)   cin >> dice[i];
}


int main(){
    Input();

    return 0;
}