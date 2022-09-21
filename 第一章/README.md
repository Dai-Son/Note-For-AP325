# 第一章 
小提醒 善用ctrl+F :>
## P-1-1
### 題目
P-1-1. 合成函數(1)

令 f(x)=2x-1, g(x,y)=x+2y-3。本題要計算一個合成函數的值，例如

f(g(f(1),3))=f(g(1,3))=f(4)=7。

Time limit: 1 秒

輸入格式：輸入一行，長度不超過 1000，它是一個 f 與 g 的合成函數，但所有的括

弧與逗號都換成空白。輸入的整數絕對值皆不超過 1000。

輸出：輸出函數值。最後答案與運算過程不會超過正負 10 億的區間。
### 作法
##### 教授寫法
```cpp
// p_1_1
#include <bits/stdc++.h>
int eval(){
    int val, x, y, z;
    char token[7];
    scanf("%s", token);
    if (token[0] == 'f') {
        x = eval();
        return 2*x-1;
    } else if (token[0] == 'g') {
        x = eval();
        y = eval();
        return x + 2*y -3;
    } else {
        return atoi(token);
    }
}

int main() {
    printf("%d\n",eval());
    return 0;
}
```
##### 我的寫法
```cpp
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
```
##### 筆記
比較要注意的應該是atoi()的用法改變

因為我用的是string輸入 所以後面要加上 **.c_str()** 讓他可以正常運作

應該是把string的形式轉換成ascii的樣子的意思吧

不過我在另一個方法遇到了一點瓶頸
```cpp
int IF_int;
string Otherwise;

if (cin >> IF_int){
    cout << IF_int;
}else{
    cin >> Otherwise;
    cout << Otherwise;
}
```
在cin的情況下 好像有點難先判定他是不是int後再處理

假設輸入不是int IF_int 先動後 變成 Otherwise 會吃不到輸入/下一個輸入值

有空要去惡補一下scanf的用法了 ; ;
