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

    map<int,int> M1; // Map key�������� �Ȭ����ƶq (M1[����] = �ƶq)
    M1[a[0]]=1; // �Ĥ@�Ӥ����X�{�@��

    for (i=1;i<n;i++) { // �v�ӭp��
        map<int,int> M2(M1); // �ƻsM1��M2

        for (auto e:M1){ // �]�L���M1
            int t = (e.first*a[i])%p; // ����MOD���
            M2[t] = (M2[t] + e.second)%p;// �p�GM2[t]���s�b=0
        }

        M2[a[i]] = (M2[a[i]] + 1)%p; // ��a[i]�o�ӼƦr�]��iM2
        M1.swap(M2); // M1 M2�洫
    }

    cout << M1[1] << '\n';
    return 0;
}
