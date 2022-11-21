#include <bits/stdc++.h>
using namespace std;
#define StarBurstStream ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long

signed main(){
    int i, n;
    LL p, a[50];
    scanf("%d%lld", &n, &p);
    for (i=0;i<n;i++)
        scanf("%lld", &a[i]);
    map<LL,LL> M1; // (product, number)
    M1[a[0]]=1; // The first element appear once
    for (i=1;i<n;i++) { // for each element
        // compute from M1 to M2
        map<LL,LL> M2(M1); // copy M1 to M2
        for (auto e:M1) {
            LL t = (e.first*a[i])%p;
            M2[t] = (M2[t] + e.second)%p;
        }
        M2[a[i]] = (M2[a[i]] + 1)%p; // for {a[i]}
        M1.swap(M2);
    }
    printf("%lld\n", M1[1]);
    return 0;
}
