#include <bits/stdc++.h>
using namespace std;

#define StarBurstStream ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
int p = 10*10*10*10*10*10*10*10*10+9;

vector<vector<int>> multipy( vector<vector<int>> a, vector<vector<int>> b );
vector<vector<int>> exp( vector<vector<int>> n1, int n );

signed main(){

    StarBurstStream
    int x, y, n;cin >> x >> y >> n;

    vector<vector<int>> n1
    {
        { x, 2*y },
        { y, x }
    };

    vector<vector<int>> ans = exp( n1, n );
    cout << ans[0][0] % p << " " << ans[1][0] % p << '\n';

}
vector<vector<int>> exp( vector<vector<int>> n1, int n ){
    if( n == 0 ){
        return { {1,0},{0,1} };
    }else if( n == 1 ){
        return n1;
    }else if( n & 1 ){
        return multipy( n1, exp( n1, n-1 ) );
    }else{
        vector<vector<int>> re = exp( n1, n/2 );
        return multipy( re, re );
    }
}
vector<vector<int>> multipy( vector<vector<int>> a, vector<vector<int>> b ){
    vector<vector<int>> c{{0, 0},{0, 0}};
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            for(int k=0; k<2; k++)
            {
                c[i][j]+=(a[i][k]*b[k][j])%p;
            }
    return c;

}
