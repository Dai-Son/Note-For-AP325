#include <bits/stdc++.h>
#define StarBurstStream ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int m,n;

signed main(){

	StarBurstStream

	unsigned U,team,complement;
	vector<int> v0;
	set<int> s0;

	string str0;
	int i;
	int answer;

	/*
	�G�i��
	���]m=3
	�N�O��1����3��
	�]�N�O 1000
	-1��h�� �ܦ� 0111
	�N�i�H�Τ��P��m��1�N���P���^��r��
	*/
	cin >> m >> n;
	U = ( 1 << m ) - 1;

	while(n--){
		cin >> str0;

		team = 0;
		for( i = 0 ; i < str0.length() ; i++ ){
			/*
			���]str0 = "ABC"
			str0[0] - 'A' = 0
			str0[1] - 'A' = 1
			str0[2] - 'A' = 2
			�]�N�O��0111 �Ӧ�ƪ�1�N��A �Q��ƪ�1�N��B etc...
			*/
			team |= 1 << str0[i] - 'A';
			/*
			| (OR�B��l)
			�u�n��ӹ����줤���@��1�ɴN��1
			*/
		}
		v0.push_back(team);

		//�����M�o��team���ɪ�team
		complement = U-team;
		s0.insert(complement);
	}

	answer = 0;
	//�]���D�ثO�ҨS����ӬۦP���ζ� �]����set.find��
	for( i = 0 ; i < v0.size() ; i++ ){
		if( s0.find(v0[i]) != s0.end() ) answer++;
	}

	//A�|�ɨ�B B�|�ɨ�A �P�@�� ���|�O���⦸ �]���̫ᰣ�H
	//cout << ( answer / 2 ) << '\n';
	cout << ( answer >> 1 ) << '\n';

	return 0;
}
