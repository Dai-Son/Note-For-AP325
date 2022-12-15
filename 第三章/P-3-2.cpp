#include <bits/stdc++.h>
using namespace std;

#define StarBurstStream ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

int sol();
signed main(){
    while(!sol());

    return 0;
}

int sol(){
    stack<int> S;
    char in[210];
    char ch[7]="([{)]}";

    bool error = false;
    if( cin >> in ){
        for( int i = 0 ; i < strlen(in) ; i++ ){
            int mnum = strchr(ch, in[i]) - ch;
            if( mnum < 3 ){
                S.push(mnum);
            }else{
                if( mnum - S.top() != 3 ){
                    error = true;
                    break;
                }else{
                    S.pop();
                }
            }
        }
        if( error == true || !S.empty() ){
            cout << "no" << '\n';
            return 0;
        }
        cout << "yes" << '\n';
        return 0;
    }
    return -1;
}
