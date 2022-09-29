#include <bits/stdc++.h>
#define StarBurstStream ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int n,p,A[26];
int CalcMx;

void solve( int where , int calc ){
	if( where >= n ){
		if ( calc <= p ){
			CalcMx = max( calc, CalcMx );
		}
		return;
	}
	solve( where + 1 , calc + A[where] ); // ¿ï
	solve( where + 1 , calc); // ¤£¿ï
}


int main(void){

	StarBurstStream

	cin >> n >> p;
	for( int i = 0; i < n ; i++ ){
		cin >> A[i];
	}
	CalcMx = 0;
	solve( 0 , 0 );
	cout << CalcMx << '\n';
	return 0;
}
