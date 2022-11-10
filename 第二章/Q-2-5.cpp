#include <bits/stdc++.h>
using namespace std;
#define StarBurstStream ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int unsigned long long
//快速冪
vector<vector<int>> recur_exp(int n);

//矩陣乘法
vector<vector<int>> multipy(vector<vector<int>> a, vector<vector<int>> b);

int fib(int m);

//矩陣
vector<vector<int>> tmp( 2, vector<int> ( 2 , 0 ) );
vector<vector<int>> A
{
    { 1 , 1 },
    { 1 , 0 }
};

int P = 1000000007;
signed main(){

    StarBurstStream
    int in;

    while( cin >> in && in != -1 ){
        cout << fib(in) << '\n';
    }
    return 0;
}

vector<vector<int>> recur_exp(int n){

    if( n == 1 ) return A;

    //n是奇數
    else if( n & 1 ){
        tmp = recur_exp((n-1)/2);
        return multipy(multipy(tmp, tmp), A);
    }

    tmp = recur_exp(n/2);
    return multipy(tmp, tmp);

}

vector<vector<int>> multipy(vector<vector<int>> a, vector<vector<int>> b){
    int c1 = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % P;
    int c2 = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % P;
    int c3 = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % P;
    int c4 = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % P;
    vector<vector<int>> c
    {
        { c1 , c2 },
        { c3 , c4 }
    };
    return c;
}

int fib(int m){
    if( m <= 1 ) return m;
    return recur_exp(m-1)[0][0];
}
