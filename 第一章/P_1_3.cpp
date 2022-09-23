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
	line[N+1] = L; // 0 �M L �ҵ������I ��K����B�z
	for( i = 1 ; i <= N ; i++ ) cin >> line[i];

	cout << again_again(0 , N+1) << endl;

	return 0;
}

long long again_again( int Left , int Right ) // Left �������I��m Right ���k
{
	long long length;
	int mid, pos;

	if ( Right - Left <= 1 ) return 0; // �����F ����<1

	length = line[Right] - line[Left]; // ����

	mid = (line[Left] + line[Right])/2�@// ���I��m
	pos = lower_bound(line+Left, line+Right,mid) - line; // ��� ">=" mid�Ȫ��̤p��m Ex 1,2,3,4,4,5 �� 4 ��X 3

	if(line[pos-1] - line[Left] >= line[Right] - line[pos]) pos--; // �T�wpos-1��m�O���O�󱵪� �̷��D�ؼg

	return length + again_again(Left, pos) + again_again(pos, Right);// ������ �~�򻼰j

}
