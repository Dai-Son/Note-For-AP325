#include <bits/stdc++.h>
using namespace std;

#define StarBurstStream ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

int pr(char in);

signed main(){

    char in[110];
    char postfix[110];
    cin >> in;
    int len = strlen(in);
    cout << len;
    stack<char> S;
    S.push('|');
    int i, j;
    for( i = 0, j = 0 ; i < len ; i++ ){
        if( in[i]-'0' < 0 ){
            while(pr(S.top())>=pr(in[i]) && S.top() != '|'){
                postfix[j++] = S.top();
                S.pop();
            }
            S.push(in[i]);
        }else{
            postfix[j++] = in[i];
        }
    }
    cout << postfix;


}
int pr(char in){
    switch(in){
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        default: return 0;
    }
}
