#include <bits/stdc++.h>
using namespace std;

#define StarBurstStream ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

int r[500010];

void presum(int n);

signed main(){

    StarBurstStream
    int i;

    int n, m;cin >> n >> m;

    for( i = 0 ; i < n ; i++ ){
        cin >> r[i];
        r[n+i] = r[i];
    }

    presum(n);

    int inroom = 0;
    int key;
    for( i = 0 ; i < m ; i++ ){
        cin >> key;
        if(inroom != 0)
            key += r[inroom-1];
        inroom = lower_bound( r+inroom, r+(2*n), key ) - r;
        inroom = (inroom+1) % n;
    }

    cout << inroom << '\n';

}
void presum(int n){
    for( int i = 1 ; i < 2*n ; i++ ){
        r[i] += r[i-1];
    }
}
