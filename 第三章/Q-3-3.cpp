#include <bits/stdc++.h>
using namespace std;

#define StarBurstStream ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

signed main(){
    StarBurstStream

    char in[110];
    char tran[15]="123456789+-*/"
    cin >> in;

    queue<int> Qnum;
    queue<int> Qmath;

    for( int i = 0 ; i < strlen(in) ; i++ ){
        int tr = strchr(tran, in[i]) - tran;
        if( tr > 9 ){
            Qmath.push(tr);
        }else()
    }

}
