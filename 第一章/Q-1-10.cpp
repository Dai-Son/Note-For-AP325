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
			cin >> chessboard[i][j]; //��������
		}
	}

	again_nq( n, 0 ,p ); //���j ( n, 0, p[]) n��@���h�֦� 0��b�ĴX�� p[]�����b�������C
	cout << score << '\n';

	return 0;
}

void again_nq( int n, int k, int p[])
{
    //vaild�T�w�i���
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

	for( i = 0 ; i <= n ; i++ ) vaild[i] = true; //���m

	for( j = 0 ; j < k ; j++ ){ //�е����̤����
		vaild[p[j]] = false;

		i = ( k - j ) + p[j];
		if( i < n ) vaild[i] = false;

		i = p[j] - ( k - j );
		if( i >= 0 ) vaild[i] = false;
	}

	for( i = 0; i <= n ; i++ ){
		if( vaild[i] ){ //�p�G�i�H��o��m���� �Q�פU�@��

			p[k] = i;
			again_nq( n , k+1 , p );
		}
	}
}
