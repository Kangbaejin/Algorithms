/* 
 * baekjoon 1978
 * 
 * 소수 찾기
 * 
 * https://www.acmicpc.net/problem/1978
 * 
 * 
 * 
 */

#include <iostream>
#include <vector>

using namespace std;


int isprime(int val){
    if(val == 1)
        return 0;
    if(val == 2)
        return 1;


    for(int i=2;i<=val;i++){
        if(i==val)
            return 1;
        
        if(val%i==0)
            return 0;


    }

    return 0;
}




int main(){
    int n,x, count = 0;
    cin >> n;
    while(n--){
        cin >> x;
        if(isprime(x))
            count++;
    }

    cout << count;
}



/*
 * https://www.acmicpc.net/source/29968152
 * 
 * 훨씬 간결하고, 1 과 자기자신으로만 나눌 수 있다는 소수의 성질을
 * 잘 이용한 코드라고 생각된다.
 * 1부터 자기 자신까지 검사하여 2번만 나눠졌다면 그 수는 소수라고 할 수 있다.
 * 이는 2도 포함된다.
 */

/*

#include <stdio.h>

int main()
{
	int n,k,m,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		m=0;
		scanf("%d",&k);
		for(int i=1;i<=k;i++)
		{
			if(k%i==0) m++;
		}
		if(m==2) ans++;
	}
	printf("%d",ans);
}



*/