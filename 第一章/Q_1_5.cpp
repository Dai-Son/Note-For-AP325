#include <bits/stdc++.h>
	using namespace std;

	void again_again( int n );
	string in;
	int p, black; //�}�b int main()�~ �w�]��0

	int main( void ){

		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		int n;
		cin >> in >> n;
		again_again(n);

		cout << black << endl;
	}
// return; �N��禡����
	void again_again( int n ){
		int i;

		if( n == 0 ) return; //�ھ��D�N n<1���s�b *int���p�Ʈ� �L����˥h*

		/*
		  �] 1 or 0 ��in���Ĥ@��
		  ��X�h�� n*n or 0 �L�~

		  �]2�� ��in���Ĥ@��
		  �h�|���jn/2�|�� ���O�D�|���O���O�¦⪺
		  �H������
		*/
		if( in[p] == '0'){
			p++;

			return;
		}

		if( in[p] == '1'){
			p++;

			black += n*n;

			return;
		}

		p++;
		for( i = 0 ; i <= 3 ; i++ ){ //�|��
			again_again(n/2);
		}
	}
