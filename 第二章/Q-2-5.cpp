#include <bits/stdc++.h>
using namespace std;
#define StarBurstStream ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//快速冪
int recur_exp(int n);

//矩陣乘法
int multipy(int a[][2], int b[][2]);

//總結
int fib(int m);

//矩陣
int tmp[2][2];
int BASE[2][2]={
                { 1 , 1 },
                { 1 , 0 }
            };

signed main(){

    int in;

    while( cin >> in && in != -1 ){
        cout << fib(in) << '\n';
    }
    return 0;
}

int recur_exp(int n){

    if( n == 1 ) return BASE;

    //n是奇數
    else if( n & 1 ){
        tmp = recur_exp((n-1)/2);
        return multipy(BASE, multipy(BASE, tmp));
    }

    tmp = recur_exp(n/2);
    return multipy(BASE,  tmp);

}

int multipy(int a[][2], int b[][2]){
    int c1 = a[0][0]*b[0][0] + a[0][1]*b[1][0];
    int c2 = a[0][0]*b[0][1] + a[0][1]*b[1][1];
    int c3 = a[1][0]*b[0][0] + a[1][1]*b[1][0];
    int c4 = a[1][0]*b[0][1] + a[1][1]*b[1][1];
    int c[2][2]={
                    { c1 , c2 },
                    { c3 , c4 }
                };
    return c;
}

int fib(int m){
    if( m <= 1 ) return m;
    return recur_exp(m);
}
