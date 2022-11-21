#include <bits/stdc++.h>
using namespace std;
#define StarBurstStream ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long

signed main(){

	StarBurstStream

    int i, n, p, a[50];

    cin >> n >> p;

    for (i=0;i<n;i++)
        cin >> a[i]

    map<int,int> M1; // Map key紀錄元素 值紀錄數量 (M1[元素] = 數量)
    M1[a[0]]=1; // 第一個元素出現一次

    for (i=1;i<n;i++) { // 逐個計算
        map<int,int> M2(M1); // 複製M1到M2

        for (auto e:M1){ // 跑過整個M1
            int t = (e.first*a[i])%p; // 紀錄MOD後值
            M2[t] = (M2[t] + e.second)%p;// 如果M2[t]不存在=0
        }

        M2[a[i]] = (M2[a[i]] + 1)%p; // 把a[i]這個數字也放進M2
        M1.swap(M2); // M1 M2交換
    }

    cout << M1[1] << '\n';
    return 0;
}
