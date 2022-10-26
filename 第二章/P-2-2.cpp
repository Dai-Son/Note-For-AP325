d011. ¨ÒÃD P-2-2. Â÷´²¤Æ ¡V sort -- AP325
#include <bits/stdc++.h>
#define StarBurstStream ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

signed main(void){
	int i;

	int n;
	vector<int> vec;
	vector<int> vec2;
	int push;
	int where;

	StarBurstStream

	cin >> n;
	for( i = 0 ; i < n ; i++ ){
		cin >> push;
		vec.push_back(push);
	}

	vec2 = vec;

	sort( vec.begin () , vec.end() );
	where = unique( vec.begin () , vec.end() ) - vec.begin();

	for( i = 0 ; i < where ; i++ ){
		replace( vec2.begin() , vec2.end() , vec[i] , i );
	}

	for( i = 0 ; i < n ; i++ ){
		cout << vec2[i] << ' ';
	}
}
