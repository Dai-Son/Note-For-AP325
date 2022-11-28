#include <bits/stdc++.h>
using namespace std;

#define StarBurstStream ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long

vector<vector<int>> multi( vector<vector<int>> a, vector<vector<int>> b );
vector<vector<int>> exp( vector<vector<int>> n1, int n );
signed main(){

    StarBurstStream
    int x, y, n;cin >> x >> y >> n;
    vector<vector<int>> n1
    {
        { x, 2*y },
        { y, x}
    };
    cout << exp( n1, n )[0][0] << " " << exp( n1, n )[0][1] << '\n';

}
vector<vector<int>> exp( vector<vector<int>> n1, int n ){

}
vector<vector<int>> multi( vector<vector<int>> a, vector<vector<int>> b, int p ){
    int o1 = (a[0][0]*b[0][0] + a[0][1]*b[1][0])%p;
    int o2 = (a[0][0]*b[0][1] + a[0][1]*b[1][1])%p;
    int o3 = (a[1][0]*b[0][0] + a[1][1]*b[1][0])%p;
    int o4 = (a[1][0]*b[1][0] + a[1][1]*b[1][1])%p;
    vector<vector<int>> c
    {
        {o1, o2},
        {o3, o4}
    };
    return c;
}
