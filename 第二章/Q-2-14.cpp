#include <bits/stdc++.h>
using namespace std;
#define StarBurstStream ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
void rec(vector<int> wall, int left, int right, int width);

signed main(){

    StarBurstStream
    int fi;

    int n, i, w;cin >> n >> i >> w;

    vector<int> wall;
    int highest=-1;
    wall.push_back(100000001);
    for( fi = 0 ; fi < n ; fi++ ){
        int in;cin >> in;
        wall.push_back(in);
        highest = max(in, highest);
    }
    wall.push_back(100000001);
    int hloc = lower_bound(wall.begin(),wall.end(),highest)-wall.begin();


}
void rec(int amount, int left, int right){

}
