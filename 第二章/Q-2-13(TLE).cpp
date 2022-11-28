#include <bits/stdc++.h>
using namespace std;

#define StarBurstStream ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long

pair<int, int> exp( int x, int y, int n, int p );

signed main(){

    StarBurstStream

    int p = 10*10*10*10*10*10*10*10*10+9;
    int x, y, n;
    cin >> x >> y >> n;
    pair<int, int> ans = exp( x, y, n, p );
    cout << ans.first << " " << ans.second << '\n';

}

pair<int, int> exp( int x, int y, int n, int p ){
    if( n == 0 ) return { 1 , 0 };
    else if( n == 1 ) return { x , y };
    else if( n & 1 ){
        int F = exp(x, y, n-1, p).first;
        int S = exp(x, y, n-1, p).second;
        return { ( x * F + 2 * y * S ) % p , ( x * S + y * F ) % p };
    }

    int F = exp(x, y, n/2, p).first;
    int S = exp(x, y, n/2, p).second;
    return { ( F * F + 2 * S * S ) % p , ( 2 * F * S ) % p };
}
