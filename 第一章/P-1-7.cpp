#include <bits/stdc++.h>
using namespace std;
#define StarBurstStream ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void recur( int i , long long p );

int n, ans;
long long A[26];


int main(void){
	int i;

	StarBurstStream

	cin >> n;
	for( i = 0 ; i < n ; i++ ) cin >> A[i];

	recur( 0 , 1 );

	cout << ans-1 << '\n'; //�����諸���p�U p�٬O����1 �ҥH��X�n��1

	return 0;
}

void recur( int i, long long p ){
	if ( i >= n ){
		if( p == 1 ) ans++;
	}else{
		recur( i + 1 , ( p*A[i] ) % 10009 ); //��
		recur( i + 1 , p ); //����
	}
}
