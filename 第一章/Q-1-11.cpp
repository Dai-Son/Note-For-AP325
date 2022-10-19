#include <bits/stdc++.h>
#define StarBurstStream ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int again_del( int r0, int c0, int r1, int c1);
int cost( int isR, int p, int q0 ,int q1 );

int m, n;
int matrix[13][13]; //�x�}

int main(void){

	StarBurstStream

	int i,j;

	cin >> m >> n;
	for( i = 0 ; i < m ; i++ ){
		for( j = 0 ; j < n ; j++ ){
			cin >> matrix[i][j];
		}
	}

	cout << again_del( 0, 0, m-1, n-1 ) << '\n';

	return 0;
}

//���j�Ҧ��R�k
int again_del( int r0, int c0, int r1, int c1){// again_del(�̤W,�̥�,�̤U,�̥k)

	int minimal = 2147483647;
	int t;

	if( r0 == r1 || c0 == c1 ) return 0; //�u�Ѥ@�C

	//del�̤W
	t = cost(1 , r0, c0, c1) + again_del( r0+1, c0, r1, c1 );
	minimal = min( minimal, t );

	//del�̤U
	t = cost(1 , r1, c0, c1) + again_del( r0, c0, r1-1, c1 );
	minimal = min( minimal, t );

	//del�̥�
	t = cost(0 , c0, r0, r1) + again_del( r0, c0+1, r1, c1 );
	minimal = min( minimal, t );

	//del�̥k
	t = cost(0 , c1, r0, r1) + again_del( r0, c0, r1, c1-1 );
	minimal = min( minimal, t );

	return minimal;
}

//�p�⦨��
int cost( int isR, int p, int q0 ,int q1 ){ //cost( �O��O�C, ���@��/�C, ��m, ��m )
	int i;
	int zero=0, one=0;

	if(isR){ //�C����
		for( i = q0 ; i <= q1 ; i++ ){
			if(matrix[p][i]) one++;
			else zero++;
		}
		return min( zero , one );
	}else{ //�榨��
		for( i = q0 ; i <= q1 ; i++ ){
			if(matrix[i][p]) one++;
			else zero++;
		}
		return min( zero , one );
	}
}
