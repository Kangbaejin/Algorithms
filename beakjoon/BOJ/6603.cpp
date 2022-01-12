/* baekjoon 6603
 *
 * 로또
 * 
 * https://www.acmicpc.net/problem/6603
 * 
 * 
 * 
 * iostream 사용할 때
 * ios_base::sync_with_stdio(0);
 * cin.tie(0);
 * 와 함께 endl 대신에 '\n' 을 사용하여 시간을 줄여야한다.
 */

#include <iostream>
#include <string>
#include <vector>


using namespace std;


int lotto(vector<int> v){
    int size;
    size = v.size();
    
    if(size > 6){
        for(int i=size-1;i>=0;i--){
            vector<int> temp(v);
            temp.erase(temp.begin()+i);
            lotto(temp);
        }
    }
    else{
        for(int i=0;i<6;i++){
            cout << v[i] << " ";
        }
        cout << '\n';
    }

    return 0;

}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(1){
        int t,x;
        cin >> t;

        vector<int> v;
        v.clear();

        if(t==0)
            break;
        else{
            for(int i=0;i<t;i++){
                cin >> x;
                v.push_back(x);
            }
        }

        lotto(v);
    }


    return 0;
}