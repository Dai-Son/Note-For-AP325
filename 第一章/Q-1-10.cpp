#include <bits/stdc++.h>
#define StarBurstStream ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

void again_nq( int n, int k, int p[]);

int chessboard[14][14];
int score;

int main(void){

	StarBurstStream

	int n;
	int i, j;
	int p[14];

	cin >> n;
	for( i = 0 ; i < n ; i++ ){
		for( j = 0 ; j < n ; j++ ){
			cin >> chessboard[i][j]; //紀錄分數
		}
	}

	again_nq( n, 0 ,p ); //遞迴 ( n, 0, p[]) n表共有多少行 0表在第幾行 p[]紀錄在哪行放哪列
	cout << score << '\n';

	return 0;
}

void again_nq( int n, int k, int p[])
{
    //vaild確定可行性
	bool vaild[14];
	int i,j;
	int t;

	if( k >= n ){
		t = 0;
		for( i = 0 ; i < n ; i++ ){
			t += chessboard[i][p[i]];
		}
		score = max(score , t );
		return;
	}

	for( i = 0 ; i <= n ; i++ ) vaild[i] = true; //重置

	for( j = 0 ; j < k ; j++ ){ //標註哪裡不能放
		vaild[p[j]] = false;

		i = ( k - j ) + p[j];
		if( i < n ) vaild[i] = false;

		i = p[j] - ( k - j );
		if( i >= 0 ) vaild[i] = false;
	}

	for( i = 0; i <= n ; i++ ){
		if( vaild[i] ){ //如果可以放這位置的話 討論下一行

			p[k] = i;
			again_nq( n , k+1 , p );
		}
	}
}
