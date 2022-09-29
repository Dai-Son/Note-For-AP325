#include <bits/stdc++.h>
	using namespace std;

	void again_again( int n );
	string in;
	int p, black; //開在 int main()外 預設為0

	int main( void ){

		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		int n;
		cin >> in >> n;
		again_again(n);

		cout << black << endl;
	}
// return; 代表函式結束
	void again_again( int n ){
		int i;

		if( n == 0 ) return; //根據題意 n<1不存在 *int有小數時 無條件捨去*

		/*
		  設 1 or 0 為in的第一位
		  輸出則為 n*n or 0 無誤

		  設2為 為in的第一位
		  則會遞迴n/2四次 分別求四塊是不是黑色的
		  以此類推
		*/
		if( in[p] == '0'){
			p++;

			return;
		}

		if( in[p] == '1'){
			p++;

			black += n*n;

			return;
		}

		p++;
		for( i = 0 ; i <= 3 ; i++ ){ //四次
			again_again(n/2);
		}
	}
