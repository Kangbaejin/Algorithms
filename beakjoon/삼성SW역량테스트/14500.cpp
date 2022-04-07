/* 
 * baekjoon 14500
 * 
 * 테트로미노
 * 
 * https://www.acmicpc.net/problem/14500
 * 
 * 
 * 구현 계획
 * 
 * 결국 모든 테트로미노의 모양을 구현한 다음
 * 제일 왼쪽 위 블럭을 포함하는 경우에서 시작해서 제일 오른쪽까지 진행, 테트로미노가 벗어나는 경우 멈춤
 * 제일 아래쪽까지 진행, 벗어나는경우 멈춤.
 * 
 * 위의 과정을 총 4방향으로 돌리고
 * 
 * 모양에 따라 뒤집어도 변하지 않는경우 ex) 정사각형은 모든 경우가 같은 모양이다.
 * 등을 고려하여 가짓 수를 세분화한다.
 * 
 * 그런 모든 가짓수 모양에 대해 순차적으로 빠짐없이 진행
 * 
 */

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    return 0;
    
}