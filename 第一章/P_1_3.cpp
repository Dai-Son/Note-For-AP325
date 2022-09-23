#include <bits/stdc++.h>
using namespace std;

long long again_again( int Left , int Right );

int line[50002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N,L;
	int i;

	cin >> N >> L;
	line[0] = 0;
	line[N+1] = L; // 0 和 L 皆視為切點 方便後續處理
	for( i = 1 ; i <= N ; i++ ) cin >> line[i];

	cout << again_again(0 , N+1) << endl;

	return 0;
}

long long again_again( int Left , int Right ) // Left 為左端點位置 Right 為右
{
	long long length;
	int mid, pos;

	if ( Right - Left <= 1 ) return 0; // 切完了 長度<1

	length = line[Right] - line[Left]; // 長度

	mid = (line[Left] + line[Right])/2　// 中點位置
	pos = lower_bound(line+Left, line+Right,mid) - line; // 找到 ">=" mid值的最小位置 Ex 1,2,3,4,4,5 找 4 輸出 3

	if(line[pos-1] - line[Left] >= line[Right] - line[pos]) pos--; // 確定pos-1位置是不是更接近 依照題目寫

	return length + again_again(Left, pos) + again_again(pos, Right);// 切完後 繼續遞迴

}
