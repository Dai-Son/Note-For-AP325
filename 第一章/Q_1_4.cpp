#include <bits/stdc++.h>
using namespace std;
#define StarBurstStream ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);//其實寫在裡面就好 這樣只是方便複製w

int again_again( int L, int R, int level);

int n, k;
int p[50001];
long long lps[50000], rps[50000];

int main(void){

	int i;

	StarBurstStream

	cin >> n >> k;
	for( i = 0 ; i < n ; i++ ) cin >> p[i];
	cout << again_again( 0, n-1, 1) << '\n';

	return 0;

}
int again_again( int L, int R, int level ){

	int i;
	long long delta;
	long long cost, minimal = ((long long)1 << 63)-1;
	int cut;

	if( level > k || R - L < 2 ) return 0;

	delta = lps[L] = 0;
	for( i = L+1; i <= R; i++ ){
		delta += p[i-1];
		lps[i] = lps[i-1] + delta;
	}
	delta = rps[R] = 0;
	for( i = R-1; i>=L; i-- ){
		delta += p[i+1];
		rps[i] = rps[i+1] + delta;
	}

	for( i = L+1; i <= R-1; i++ ){
		cost = abs(rps[i]-lps[i]);
		if( cost < minimal ){
			minimal = cost;
			cut = i;
		}
	}

	return p[cut]+again_again(L, cut-1, level+1)+again_again(cut+1, R, level+1);
