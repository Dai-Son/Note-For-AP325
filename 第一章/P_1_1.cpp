#include <bits/stdc++.h>
using namespace std;
int again_again(void); //我知道迴圈叫recur 但我還是以自己喜歡的方式寫:>
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); // cin優化加速
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
    //如果不是f或g則返回數字
    return atoi(str.c_str()); //@
}
