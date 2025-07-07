#include <cstdio>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <cmath>
#include <ctime>
using namespace std;

#define max_value 9999999
#define applicant 100000
#define num_of_winners 30




int get_mean(vector<int> v){
    int sum=0;
    for(int i=0;i<v.size();i++){
        sum+=v[i];
    }

    return sum/v.size();
}

int get_stderr(int m, vector<int> v){
    int sum=0;
    for(int i=0;i<v.size();i++){
        sum += pow(v[i]-m,2);
    }

    return sqrt(sum/v.size());
}


void get_meand_and_stderr(vector<int> v){
    int mean_v = get_mean(v);
    int stderr_v = get_stderr(mean_v,v);

    cout << "\nMean : " << mean_v << endl;
    cout << "Stderr : " << stderr_v << endl;    

    return;
}



//골드리치 금고 시뮬레이터
int main(){
    int *c = (int*) malloc(sizeof(int)*max_value);
    //memset(c,0,max_value*sizeof(int));


    // 시드값을 얻기 위한 random_device 생성.
    // random_device rd;
    // // random_device 를 통해 난수 생성 엔진을 초기화 한다.
    // mt19937 gen(rd());


    //mt19937 gen(1118);
    mt19937 gen(time(NULL));

    //음수값을 양수로 바꿔 처리된다. 표준편차가 절반정도 수준으로 적용되므로 원하는 그래프의 두배의 표준편차 적용
    int m,s;
    m = 6000;
    s = 6000;
    normal_distribution<> dis(m, s);

    for(int i=0; i<applicant; i++){
        double rd_value = dis(gen);
        while(!(-max_value < rd_value && rd_value<max_value)){

            cout << "The value was : " << rd_value << " . Choose again.\n";
            rd_value = dis(gen);
        }
        int int_rd_value = (int) rd_value;

        //음수인 경우 다시 뽑지 말고 부호 바꿔서 쓰기
        if(int_rd_value<0) int_rd_value *=-1;
        c[int_rd_value]++;
    }

    vector<int> winning;

    for(int i=0; i<max_value; i++){
        if(winning.size()==num_of_winners) break;
        if(c[i] == 1){
            winning.push_back(i);
        }
    }


    //로그
    cout << "\nLogs\n";
    int zero_count = 0;
    vector<int> maybe_win;
    vector<int> maybe_win30;
    vector<int> win_or_maybewin;
    for(int i=0;i<max_value;i++){
        // if(i%10 == 0) cout << endl;
        // cout << c[i] << " ";
        if(c[i]==0 || c[i]==1){
            if(win_or_maybewin.size()<30) win_or_maybewin.push_back(i);
        }
        if(c[i]==0) {
            if(maybe_win30.size()<30) maybe_win30.push_back(i);
            maybe_win.push_back(i);
            zero_count++;
        }
        else zero_count = 0;

        if(zero_count >100) break;
        
    }
    
    //당첨
    cout << "\nWinning";
    for(int i=0;i<num_of_winners;i++){
        if(i%10 == 0) cout << endl;
        cout << winning[i] << " ";
        
    }
    get_meand_and_stderr(winning);

    //당첨 가능했던 번호들 30개
    cout << "\nMaybe it won.";
    for(int i=0;i<maybe_win30.size();i++){
        if(i%10 == 0) cout << endl;
        cout << maybe_win30[i] << " ";
        
    }

    get_meand_and_stderr(maybe_win30);


    //당첨 + 당첨 가능번호 30개
    cout << "\nWin and Maybe it won.";
    for(int i=0;i<win_or_maybewin.size();i++){
        if(i%10 == 0) cout << endl;
        cout << win_or_maybewin[i] << " ";
        
    }

    get_meand_and_stderr(win_or_maybewin);


    return 0;
}
