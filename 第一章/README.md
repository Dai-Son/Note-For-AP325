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
```cpp
// p 1.1b
#include <stdio.h>

int eval(){
    int val, x, y, z;
    char c;
    // first try to read an int, if successful, return the int
    if (scanf("%d",&val) == 1) {
        return val;
    }
    // otherwise, it is a function name: f or g
    scanf("%c", &c);
    if (c == 'f') {
        x = eval(); // f has one variable
        return 2*x-1;
    } else if (c == 'g') {
        x = eval(); // g has two variables
        y = eval();
        return x + 2*y -3;
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
## Q-1-2
### 題目
Q-1-2. 合成函數(2) (APCS201902)

令 f(x)=2x–3；g(x,y)=2x+y–7；h(x,y,z)=3x–2y+z。本題要計算一個合成函

數的值，例如 h(f(5),g(3,4),3)=h(7,3,3)=18。

Time limit: 1 秒

輸入格式：輸入一行，長度不超過 1000，它是一個 f, g, 與 h 的合成函數，但所

有的括弧與逗號都換成空白。輸入的整數絕對值皆不超過 1000。

輸出：輸出函數值。最後答案與運算過程不會超過正負 10 億的區間。
### 作法
##### 我的寫法
```cpp
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

```
基本上做法和P-1-1同

只是x y z變了

另外縮排弄得更好看而已
## P-1-3
### 題目
有一台切割棍子的機器，每次將一段棍子會送入此台機器時，機器會偵測棍子上標示
的可切割點，然後計算出最接近中點的切割點，並於此切割點將棍子切割成兩段，切
割後的每一段棍子都會被繼續送入機器進行切割，直到每一段棍子都沒有切割點為
止。請注意，如果最接近中點的切割點有二，則會選擇**座標較小**的切割點。每一段棍
子的切割成本是該段棍子的長度，輸入一根長度 L 的棍子上面 N 個切割點位置的座
標，請計算出切割總成本。

Time limit: 1 秒

輸入格式：第一行有兩個正整數 N 與 L。第二行有 N 個正整數，依序代表由小到大的
切割點座標 p[1]~p[N]，數字間以空白隔開，座標的標示的方式是以棍子左端為 0，
而右端為 L。N <= 5e4，L< 1e9。

輸出：切割總成本點。
### 作法
##### 教授作法
線性搜尋
```cpp
// p_1_3a, linear search middle-point
#include <cstdio>
#define N 50010
typedef long long LL;
LL p[N];

// find the cut in (left,right), and then recursively
LL cut(int left, int right) {
    if (right-left<=1) return 0;
    LL len=p[right]-p[left], k=(p[right]+p[left])/2;
    int m=left;
    while (p[m]<k) m++; // linear search the first >=k
    if (p[m-1]-p[left] >= p[right]-p[m]) // check if m-1 is better
        m--;
    return len + cut(left, m) + cut(m, right);
}

int main() {
	int i, n, l;
    scanf("%d%d", &n, &l);
    p[0]=0; p[n+1]=l;
    for (i=1; i<=n; i++) scanf("%lld", &p[i]);
    printf("%lld\n",cut(0, n+1));
	return 0;
}

```
二分搜尋
```cpp
// p_1_3, binary search middle-point
#include <cstdio>
#define N 50010
typedef long long LL;
LL p[N];

// find the cut in (left,right), and then recursively
LL cut(int left, int right) {
    if (right-left<=1) return 0;
    int m=left;
    LL k=(p[right]+p[left])/2;
    for (int jump=(right-left)/2;jump>0; jump>>=1) {
        while (m+jump<right && p[m+jump]<k)
            m+=jump;
    }
    if (p[m]-p[left] < p[right]-p[m+1])
        m++;
    return p[right]-p[left] + cut(left, m) + cut(m, right);
}

int main() {
	int i, n, l;
    scanf("%d%d", &n, &l);
    p[0]=0; p[n+1]=l;
    for (i=1; i<=n; i++) scanf("%lld", &p[i]);
    printf("%lld\n",cut(0, n+1));
	return 0;
}

```

##### 我的作法
```cpp
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
```
##### 筆記(@@)
這邊比較重要的應該是lower_bound&upper_bound的用法
***

* 【用途】針對 **「已經排序」** 的資料進行binary search。

	* vector <int> v;
	
	* sort(v.begin(), v.end());
	
* **lower_bound**：找出vector中「大於或等於」val的「最小值」的位置：

	* auto it = lower_bound(v.begin(), v.end(), val);
	
* **upper_bound**：找出vector中「大於」val的「最小值」的位置：

	* auto it = upper_bound(v.begin(), v.end(), val);
	
***
<p align="right">-引自 <a href="http://https://yuihuang.com/cpp-algorithm-lower-bound-upper-bound/">YUI HUANG 演算法學習筆記</a></p>

以過去考APCS實作105、120數次的經驗來講

我感覺二分搜尋法是很常考 很常運用到的東西

不論是自己寫出來或lower_bound都要學著

給自己一個小提醒 能不DFS就不DFS 太常被TLE了 ; ;

二分搜尋法的概念就如其名 就是一直二分/切半來做搜尋

依靠中點的值比你要找的值大還小來決定要往前找還是往後找

圖像化就像是這樣
[![二分搜尋法](https://upload.wikimedia.org/wikipedia/commons/f/f7/Binary_search_into_array.png "二分搜尋法")](https://commons.wikimedia.org/wiki/File:Binary_search_into_array.png#mw-jump-to-license "二分搜尋法")

<p align="right">-引自 <a href="https://commons.wikimedia.org/wiki/File:Binary_search_into_array.png#mw-jump-to-license">Tushe2000 - Binary search in a sorted array </a></p>

要二分搜前 因為要用到相對的大小 所以記得**要Sorted要Sorted要Sorted**

## Q_1_4
### 題目
[![題目](https://cdn.discordapp.com/attachments/988162819679715408/1023553904564240384/Q_1_4.PNG "題目")](https://judge.tcirc.tw/ShowProblem?problemid=d004)

### 作法
##### 我的作法
```cpp
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
}
```