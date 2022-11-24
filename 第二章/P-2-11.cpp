#include <bits/stdc++.h>
using namespace std;

#define StarBurstStream ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long

signed main(){

    StarBurstStream

    int n, k;
    cin >> n >> k;

    set<int> S{0};
    int in, presum = 0;
    int ans = -1;
    for(int i = 0; i < n; i++){
        cin >> in;
        presum += in;
        auto it = S.lower_bound(presum-k);
        if( it != S.end() )
            ans = max(ans, presum-(*it));
        S.insert(presum);
    }

    cout << ans << '\n';

}
