#include <bits/stdc++.h>
using namespace std;
#define StarBurstStream ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long

int exp(int x, int y, int p);
signed main(){

    StarBurstStream

    int n, P;
    cin >> n >> P;
    while(n--){
        int in;
        cin >> in;
        cout << exp( in, P-2, P ) << " ";
    }
    cout << '\n';
}

int exp(int x, int y, int p){

    if ( y == 0 ) return 1;

    if( y & 1 ) return (exp(x, y-1, p)*x) % p;

    return (exp(x, y/2, p)*exp(x, y/2, p)) % p;

}
