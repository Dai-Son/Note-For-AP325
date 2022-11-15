#include <bits/stdc++.h>
#define StarBurstStream ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int m,n;

signed main(){

	StarBurstStream

	unsigned U,team,complement;
	vector<int> v0;
	set<int> s0;

	string str0;
	int i;
	int answer;

	/*
	二進制
	假設m=3
	就是把1左移3格
	也就是 1000
	-1後退位 變成 0111
	就可以用不同位置的1代表不同的英文字母
	*/
	cin >> m >> n;
	U = ( 1 << m ) - 1;

	while(n--){
		cin >> str0;

		team = 0;
		for( i = 0 ; i < str0.length() ; i++ ){
			/*
			假設str0 = "ABC"
			str0[0] - 'A' = 0
			str0[1] - 'A' = 1
			str0[2] - 'A' = 2
			也就是說0111 個位數的1代表有A 十位數的1代表有B etc...
			*/
			team |= 1 << str0[i] - 'A';
			/*
			| (OR運算子)
			只要兩個對應位中有一個1時就為1
			*/
		}
		v0.push_back(team);

		//紀錄和這個team互補的team
		complement = U-team;
		s0.insert(complement);
	}

	answer = 0;
	//因為題目保證沒有兩個相同的團隊 因此用set.find找
	for( i = 0 ; i < v0.size() ; i++ ){
		if( s0.find(v0[i]) != s0.end() ) answer++;
	}

	//A會補到B B會補到A 同一對 但會記錄兩次 因此最後除以
	//cout << ( answer / 2 ) << '\n';
	cout << ( answer >> 1 ) << '\n';

	return 0;
}
