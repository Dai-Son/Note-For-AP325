#include <bits/stdc++.h>
using namespace std;

#define StarBurstStream ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

int pr(char in);
int eval(char* post, int len);
signed main(){

    char in[110] = {'\0'};
    char postfix[110] = {'\0'};
    cin >> in;
    int len = strlen(in);
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
    while( S.top() != '|' ){
        postfix[j++] = S.top();
        S.pop();
    }

    cout << eval(postfix , len) << '\n';


}
int pr(char in){
    switch(in){
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        default: return 0;
    }
}
int eval(char* post, int len){
    stack<int> S;
    int i;
    for( i = 0 ; i < len ; i++){
        if( post[i]-'0' < 0 ){
            int num2 = S.top();
            S.pop();
            int num1 = S.top();
            S.pop();
            switch(post[i]){
                case '+':
                    S.push(num1+num2);
                    break;
                case '-':
                    S.push(num1-num2);
                    break;
                case '*':
                    S.push(num1*num2);
                    break;
                case '/':
                    S.push(num1/num2);
                    break;
                default:
                    break;
            }
        }else{
            S.push(post[i]-'0');
        }
    }
    return S.top();
}
