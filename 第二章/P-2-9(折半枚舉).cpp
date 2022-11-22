#include <bits/stdc++.h>
using namespace std;
#define StarBurstStream ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long

void subset( vector<int> &V, int i, int prod, map<int,int> &M, int p );
int exp( int x, int y, int p);

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

    map<int,int> M1, M2; // Map key紀錄元素 值紀錄數量 (M[元素] = 數量)

    // 用迴圈紀錄所有子集合
    subset(va, 0, 1, M1, p);
    subset(vb, 0, 1, M2, p);

    // 全不選最後mod的值也是1 => 多出來的 要減掉
    M1[1] -= 1;
    M2[1] -= 1;

    int ans = M1[1] + M2[1];

    //對於所有左邊的子集合 求與M2子集合相乘後mod為1的可能
    for(auto e: M1){
        int value = e.first, counts = e.second;
        int found = exp(value,p-2,p);
        auto it = M2.find(found);
        if(it != M2.end())
            ans = (ans + (counts * it->second))%p;
    }

    cout << ans << '\n';
    return 0;
}

//求所有子集合
void subset( vector<int> &V, int i, int prod, map<int,int> &M, int p ){
    // 理論上可以寫成i == v.size() 但好像大家都寫>=
    if( i>=V.size() ){
        M[prod] += 1;
        return;
    }
    subset(V, i+1, (prod*V[i])%p, M, p); // 選
    subset(V, i+1, prod, M, p); // 不選
    return;
}

int exp( int x, int y, int p){
    if( y == 0 ) return 1;
    if( y & 1 ) return (x * exp( x, y-1, p )) % p;
    return ( exp( x, y/2, p ) * exp( x, y/2, p ) ) %p;
}
