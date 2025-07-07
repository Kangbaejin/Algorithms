#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>
using namespace std;

int main(){
    mt19937 gen(time(NULL));
    uniform_int_distribution<> dis(1,45);
    vector<int> win;
    

    int value;
    int number=0;
    while(number<6){
        value = dis(gen);
        int flag_same = 0;
        for(int i=0;i<win.size();i++){
            if(value==win[i]) flag_same = 1;
        }

        if(flag_same==0){
            win.push_back(value);
            number++;
        }
    }


    sort(win.begin(),win.end(),less<>());


    for(int i=0;i<6;i++){
        cout << win[i] << " ";
    }
    
    cout << "\n";
}