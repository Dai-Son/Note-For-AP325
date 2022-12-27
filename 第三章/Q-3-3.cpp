#include <bits/stdc++.h>
using namespace std;

#define StarBurstStream ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

int pr(string in);

signed main(){

    int i;

    char in[110];
    cin >> in;
    len = strlen(in);

    Stack<string> S;

    for( i = 0 ; i < len ; i++ )

}
int pr(char in){
    switch(in){
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        default: return 0;
    }
}
