#include <bits/stdc++.h>
using namespace std;

#define StarBurstStream ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

stack<int> Snum;
stack<int> Scalc;

void
signed main(){
    StarBurstStream

    char in[110];
    char tran[16]="0123456789+-*/";
    cin >> in;

    Snum(strchr(tran, in[0]) - tran);

    int len = strlen(in);

    for( int i = 1; i < len ; i = i + 2 ){
        Scalc.push(strchr(tran, in[i]) - tran);
        Snum.push(strchr(tran, in[i+1]) - tran);
    }


}
