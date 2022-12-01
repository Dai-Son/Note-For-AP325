#include <bits/stdc++.h>
using namespace std;
#define StarBurstStream ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long

int ans[100005];

map<int,int> h;
map<int,int> rh;

int hl[100005],hr[100005];

void rec( int l, int r, int w );

signed main(){

    StarBurstStream
    int fi, fo;

    int n, i, w;cin >> n >> i >> w;

    h.clear();
    rh.clear();

    for( fi = 1 ; fi <= n ; fi++ ){
        int tmp;
        cin >> tmp;
        h[fi] = tmp;
        rh[tmp] = fi;
    }
    h[0] = 1000000005;
    h[n+1] = 1000000006;

    for( fi = 1 ; fi <= n ; fi++ ){
        for( fo = fi-1 ; fo >= 0 ; fo-- ){
            if( h[fo] > h[fi] ){
                hl[fi] = fo;
            }
        }for( fo = fi+1 ; fo <= n+1 ; fo++ ){
            if( h[fo] > h[fi] ){
                hr[fi] = fo;
            }
        }
    }





}
void rec( int l, int r, int w ){

}
