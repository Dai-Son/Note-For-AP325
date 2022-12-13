#include <bits/stdc++.h>
using namespace std;

#define StarBurstStream ios::sync_with_stdio(0);cin.tie(0);
#define int long long

signed main(){

    StarBurstStream
    int i;

    int parent[100005]={0};
    int h[100005]={0};
    int children[100005];
    queue<int> Q;

    int N;cin >> N;

    // 輸入 紀錄有幾個孩子 和有誰有家長
    int k;
    for( i = 1 ; i <= N ; i++ ){
        cin >> k;
        children[i] = k;
        if(k == 0)
            Q.push(i);
        while(k){
            int child;cin >> child;
            parent[child]=i;
            k--;
        }
    }

    int rootans, hans=0;
    while(1){
        int v = Q.front();
        Q.pop();
        hans += h[v];
        int p = parent[v];
        if(p == 0){
            rootans = v;
            break;
        }
        h[p] = max(h[p], h[v]+1);
        children[p]--;
        if(children[p] == 0)
            Q.push(p);
    }
    cout << rootans << '\n' << hans << '\n';
}
