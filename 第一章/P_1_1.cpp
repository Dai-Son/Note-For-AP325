#include <bits/stdc++.h>
using namespace std;
int again_again(void); //�ڪ��D�j��srecur �����٬O�H�ۤv���w���覡�g:>
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); // cin�u�ƥ[�t
    cout << again_again() << endl;
    return 0;
}
int again_again(void)
{
    string str;
    int x,y;
    cin >> str;
    if( str[0] == 'f' ){
        x = again_again();
        return 2*x - 1;
    }if( str[0] == 'g' ){
        x = again_again();
        y = again_again();
        return x + 2*y - 3;
    }
    //�p�G���Of��g�h��^�Ʀr
    return atoi(str.c_str()); //@
}
