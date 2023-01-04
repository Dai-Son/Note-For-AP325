#include <bits/stdc++.h>
#include <limits>
using namespace std;

#define StarBurstStream ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define N 200010

int line[N];
stack<int> S;
signed main(){
    int MAXVAL = numeric_limits<int>::max();
    int i;

    int ans = 0;
    S.push(0);
    line[0] = MAXVAL;

    int n;cin >> n;
    for( i = 1 ; i <= n ; i++ ){
        cin >> line[i];
    }

    for( i = 1 ; i <= n ; i++ ){
        while(line[S.top()] <= line[i])
            S.pop();
        ans+= i - S.top();
        S.push(i);
    }
    cout << ans << '\n';
}
