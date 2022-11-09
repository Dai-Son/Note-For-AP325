#include <bits/stdc++.h>

#define StarBurstStream ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int recur_exp(int x, int y, int p);

signed main(void){

	StarBurstStream
	int x, y, p;
	string s;
	int i;

    //long long �ˤ��U200���� => ��string��
	cin >> s;

	cin >> y >> p;

	//s[0]-'0' ��s����0���ഫ��int
	x = (s[0]-'0') % p;

    //�v��D��
	for (i=1; i<s.length(); i++){
		x = (x*10+(s[i]-'0')) % p;
	}

	cout << recur_exp(x, y, p) << '\n';
	return 0;

}

//�ֳt��
int recur_exp(int x, int y, int p)
{

	int t;

	if(p == 1) return 0;
	if(y == 0) return 1;

	if(y & 1){
		return (recur_exp(x,y-1,p)*x) % p;
	}

	t = recur_exp(x ,y/2 ,p);
	return (t*t)%p;
}
