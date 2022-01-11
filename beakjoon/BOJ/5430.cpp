/* baekjoon 5430
 *
 * AC
 * 
 * https://www.acmicpc.net/problem/5430
 * 
 * 
 * 자료구조, 덱(deque), 문자열, 파싱
 * 
 * 입력받은 수의 제일 앞의 값을 지우려고 할때, v[i] = v[i+1] 형태로 구현하게 되면
 * 배열의 모든 길이만큼 접근 및 변경이 이루어져야하므로 시간이 많이 필요하다.
 * 
 * 이를 자료구조 deque 의 특성을 이용해 효율적으로 구현한다.
 * 
 * 반복문 구현시 dq.size() 는 pop 하며 변하기 때문에, 반복문 진입 이전에 변수로 할당하여 이용한다.
 */

#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(){
    int times;
    cin >> times;
    while(times--){
        string p;
        int n;
        int flag = 0;
        int index = 0;
        int delete_error = 0;
        string list;

        cin >> p;
        cin >> n;
        cin >> list;

        deque<int> dq;

        string temp;
        for(int i=1;i<list.length();i++){
            if(list[i]==',' || list[i]== ']'){
                temp[index] = list[i];
                if(index != 0)
                    dq.push_back(stoi(temp));

                temp = "";
                index = 0;
            }
            else{
                temp[index++] = list[i];
            }
        }


        for(int i=0;i<p.length();i++){
            if(p[i]=='R'){
                flag = (flag + 1) %2;
            }
            else if(p[i]== 'D'){
                if(dq.empty()){
                    delete_error = 1;
                    break;
                }
                else{
                    if(flag){
                        dq.pop_back();
                    }
                    else{
                        dq.pop_front();
                    }
                }

            }
        }

        if(delete_error){
            cout << "error\n";
        }
        else{
            int dq_size = dq.size();


            cout << "[";
            for(int i=0;i<dq_size;i++){
                if(flag){
                    cout << dq.back();
                    dq.pop_back();
                }
                else{
                    cout << dq.front();
                    dq.pop_front();
                }
                if(i!= dq_size-1)
                    cout << ",";
            }
            cout << "]\n";
        }
    }

    return 0;
}