#include <bits/stdc++.h>
using namespace std;
#define StarBurstStream ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long

void subset( vector<int> &V, int i, int prod, vector<int> &VO, int p );

signed main(){

	StarBurstStream

    int i, n, p;
    vector<int> va,vb;

    cin >> n >> p;

    int in;
    for (i=0;i<n/2;i++){
        cin >> in;
        va.push_back(in);
    }
    for ( ;i<n;i++){
        cin >> in;
        vb.push_back(in);
    }

    vector<int> V1, V2;

    // 用迴圈紀錄所有子集合
    subset(va, 0, 0, V1, p);
    subset(vb, 0, 0, V2, p);

    sort(V1.begin(),V1.end());
    auto last1 = unique(V1.begin(),V1.end());
    V1.resize(distance(V1.begin(),last1));
    sort(V2.begin(),V2.end());
    auto last2 = unique(V2.begin(),V2.end());
    V2.resize(distance(V2.begin(),last2));

    int ans = -1;
    for( auto e1:V1 ){
        int found = p - e1;
        auto it = upper_bound( V2.begin(), V2.end(), found );
        it--;
        ans = max( ans, e1+(*it));
    }

    cout << ans << '\n';
    return 0;
}
//求所有子集合
void subset( vector<int> &V, int i, int prod, vector<int> &VO, int p ){
    if( prod > p )
        return;
    // 理論上可以寫成i == v.size() 但好像大家都寫>=
    if( i>=V.size() ){
        VO.push_back(prod);
        return;
    }
    subset(V, i+1, prod+V[i], VO, p); // 選
    subset(V, i+1, prod, VO, p); // 不選
    return;
}
