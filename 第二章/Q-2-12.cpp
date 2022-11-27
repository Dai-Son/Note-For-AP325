#include <bits/stdc++.h>
using namespace std;

#define StarBurstStream ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long

signed main(){

    StarBurstStream
    int i, o, p;

    int k, m, n;
    cin >> k >> m >> n;

    vector<vector<int>> presum;
    vector<int> pushin;
    for( i = 0 ; i < n ; i++ ){
        pushin.push_back(0);
    }
    presum.push_back(pushin);


    for( i = 0 ; i < m ; i++ ){
        vector<int> pushin;
        for( o = 0 ; o < n ; o++ ){
            int in;cin >> in;
            pushin.push_back(in);
        }
        presum.push_back(pushin);
    }

    for( i = 2 ; i <= m ; i++ ){
        for( o = 0 ; o < n ; o++ ){
            presum[i][o] += presum[i-1][o];
        }
    }

    int ans = (1<<31);
    for( i = 0 ; i < m ; i++ ){
        for( o = i + 1 ; o <= m ; o++ ){
            set<int> S{0};
            int ps = 0;
            for( p = 0 ; p < n ; p++ ){
                ps += presum[o][p]-presum[i][p];
                auto it = S.lower_bound(ps-k);
                if( it != S.end() )
                    ans = max( ans, ps-(*it) );
                S.insert(ps);
            }
        }
    }

    cout << ans << '\n';

}
