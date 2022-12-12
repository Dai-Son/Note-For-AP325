#include <bits/stdc++.h>
using namespace std;
#define StarBurstStream ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long

int ans[100005];

map<int,int> h;
map<int,int> rh;

int hl[100005],hr[100005];

void Fill( int l, int r, int w );

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

    Fill( i, i+1, w )

}
void Fill( int l, int r, int w ){
    if( h[r] > h[l] ){
        int width = r-l;
        if( width*h[l] >= w ){
            int h = w/width;
            for( int i = l ; i < l+width ; i++ ){
                w -= h-ans[i];
                ans[i] = h;
            }
        }else{
            for( int i = l ; i < l+width ; i++ ){
                w -= h[l]-ans[i];
                ans[i] = h[l];
            }

        }
    }
}
