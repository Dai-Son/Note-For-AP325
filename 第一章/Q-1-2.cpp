#include <bits/stdc++.h>
using namespace std;

int again_again(void);

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cout << again_again() << endl;
	return 0;
}

int again_again(void)
{
	string str;
	int x,y,z;

	cin >> str;

	if( str[0] == 'f' ){

		x = again_again();

		return 2*x - 3;

	}if( str[0] == 'g' ){

		x = again_again();

		y = again_again();

		return 2*x + y - 7;

	}if( str[0] == 'h' ){

		x = again_again();

		y = again_again();

		z = again_again();

		return 3*x - 2*y + z;
	}

	return atoi(str.c_str());
}
