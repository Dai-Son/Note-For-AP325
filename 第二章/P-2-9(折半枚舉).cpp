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

    map<int,int> M1, M2; // Map key�������� �Ȭ����ƶq (M[����] = �ƶq)

    // �ΰj������Ҧ��l���X
    subset(va, 0, 1, M1, p);
    subset(vb, 0, 1, M2, p);

    // ������̫�mod���Ȥ]�O1 => �h�X�Ӫ� �n�
    M1[1] -= 1;
    M2[1] -= 1;

    int ans = M1[1] + M2[1];

    //���Ҧ����䪺�l���X �D�PM2�l���X�ۭ���mod��1���i��
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

//�D�Ҧ��l���X
void subset( vector<int> &V, int i, int prod, map<int,int> &M, int p ){
    // �z�פW�i�H�g��i == v.size() ���n���j�a���g>=
    if( i>=V.size() ){
        M[prod] += 1;
        return;
    }
    subset(V, i+1, (prod*V[i])%p, M, p); // ��
    subset(V, i+1, prod, M, p); // ����
    return;
}

int exp( int x, int y, int p){
    if( y == 0 ) return 1;
    if( y & 1 ) return (x * exp( x, y-1, p )) % p;
    return ( exp( x, y/2, p ) * exp( x, y/2, p ) ) %p;
}
