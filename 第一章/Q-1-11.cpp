#include <bits/stdc++.h>
#define StarBurstStream ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int again_del( int r0, int c0, int r1, int c1);
int cost( int isR, int p, int q0 ,int q1 );

int m, n;
int matrix[13][13]; //痻皚

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

//患癹┮Τ猭
int again_del( int r0, int c0, int r1, int c1){// again_del(程,程オ,程,程)

	int minimal = 2147483647;
	int t;

	if( r0 == r1 || c0 == c1 ) return 0; //逞

	//del程
	t = cost(1 , r0, c0, c1) + again_del( r0+1, c0, r1, c1 );
	minimal = min( minimal, t );

	//del程
	t = cost(1 , r1, c0, c1) + again_del( r0, c0, r1-1, c1 );
	minimal = min( minimal, t );

	//del程オ
	t = cost(0 , c0, r0, r1) + again_del( r0, c0+1, r1, c1 );
	minimal = min( minimal, t );

	//del程
	t = cost(0 , c1, r0, r1) + again_del( r0, c0, r1, c1-1 );
	minimal = min( minimal, t );

	return minimal;
}

//璸衡Θセ
int cost( int isR, int p, int q0 ,int q1 ){ //cost( 琌︽琌, ︽/, 竚, 竚 )
	int i;
	int zero=0, one=0;

	if(isR){ //Θセ
		for( i = q0 ; i <= q1 ; i++ ){
			if(matrix[p][i]) one++;
			else zero++;
		}
		return min( zero , one );
	}else{ //︽Θセ
		for( i = q0 ; i <= q1 ; i++ ){
			if(matrix[i][p]) one++;
			else zero++;
		}
		return min( zero , one );
	}
}
