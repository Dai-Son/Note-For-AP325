#include <bits/stdc++.h>
#define StarBurstStream ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

signed main(void){

	int m,n,k;
	int i;
	int answer = 0;

	set<int> A;
	int s;

	cin >> m >> n >> k;
	for( i=0; i<m ; i++ ){
		cin >> s;
		A.insert(s);
	}

	for( i = 0 ; i < n ; i++ ){
		cin >> s;
		//set.find(val) 回傳val在此set的指標 val不存在則回傳set.end()
		if(A.find(k-s) != A.end()) answer++;
	}

	cout << answer << '\n';

	return 0;

}
