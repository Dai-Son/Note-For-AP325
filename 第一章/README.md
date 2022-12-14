# 第一章
小提醒 善用ctrl+F :>
## P-1-1
### 題目
[![P-1-1](https://cdn.discordapp.com/attachments/988162819679715408/1024365436286013460/unknown.png "P-1-1")](https://judge.tcirc.tw/ShowProblem?problemid=d001 "P-1-1")
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
[![Q-1-2](https://cdn.discordapp.com/attachments/988162819679715408/1024365824879902731/unknown.png "Q-1-2")](https://judge.tcirc.tw/ShowProblem?problemid=d002 "Q-1-2")
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
[![P-1-3](https://cdn.discordapp.com/attachments/988162819679715408/1024366132423041084/unknown.png "P-1-3")](https://judge.tcirc.tw/ShowProblem?problemid=d003 "P-1-3")
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

* **lower_bound**：找出vector中「大於或等於」val的「最小值」的指標：

	* auto it = lower_bound(v.begin(), v.end(), val);

* **upper_bound**：找出vector中「大於」val的「最小值」的指標：

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

## Q-1-4
### 題目
[![題目](https://cdn.discordapp.com/attachments/988162819679715408/1023553904564240384/Q_1_4.PNG "Q-1-4")](https://judge.tcirc.tw/ShowProblem?problemid=d004)

### 作法
##### 我的作法
```cpp
#include <bits/stdc++.h>
using namespace std;
#define StarBurstStream ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); //其實寫在裡面就好 這樣只是方便複製w

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
	long long cost, minimal = ((long long)1 << 63)-1; //(1<<63)=2^63
	int cut;

	if( level > k || R - L < 2 ) return 0;

	delta = lps[L] = 0;
	for( i = L+1; i <= R; i++ ){
		delta += p[i-1];
		lps[i] = lps[i-1] + delta;
	}
	/*
	  假設數列是a b c d e
	  設切點在1 也就是b的位置
	  算b左邊(p[i]-(i-m))的和就是a
	  設切點在2 也就是c的位置
	  算c左邊(p[i]-(i-m))的和就是2a + b
	  所以用delta紀錄累加和 (切點在1時 = a 在2時= a+b)
	  再另外創建lps紀錄delta累加 (切點在1時 = a 在2時= 2a + b)
	  rps同理
	*/
	delta = rps[R] = 0;
	for( i = R-1; i>=L; i-- ){
		delta += p[i+1];
		rps[i] = rps[i+1] + delta;
	}

	for( i = L+1; i <= R-1; i++ ){
		cost = abs(rps[i]-lps[i]); //abs(x) => 返回x的絕對值
		if( cost < minimal ){
			minimal = cost;
			cut = i;
		}
	}

	return p[cut]+again_again(L, cut-1, level+1)+again_again(cut+1, R, level+1);
}
```
## Q-1-5
### 題目
[![Q-1-5](https://cdn.discordapp.com/attachments/988162819679715408/1024000499999055942/unknown.png "Q-1-5")](https://judge.tcirc.tw/ShowProblem?problemid=d005 "Q-1-5")

### 作法
##### 我的作法
```cpp
#include <bits/stdc++.h>
	using namespace std;

	void again_again( int n );
	string in;
	int p, black; //開在 int main()外 預設為0

	int main( void ){

		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		int n;
		cin >> in >> n;
		again_again(n);

		cout << black << endl;
	}
// return; 代表函式結束
	void again_again( int n ){
		int i;

		if( n == 0 ) return; //根據題意 n<1不存在 *int有小數時 無條件捨去*

		/*
		  設 1 or 0 為in的第一位
		  輸出則為 n*n or 0 無誤

		  設2為 為in的第一位
		  則會遞迴n/2四次 分別求四塊是不是黑色的
		  以此類推
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
		for( i = 0 ; i <= 3 ; i++ ){ //四次
			again_again(n/2);
		}
	}
```
## P-1-6
### 題目
![P-1-6](https://cdn.discordapp.com/attachments/988162819679715408/1024709032222666802/unknown.png "P-1-6")

(TCIRC未收錄)

##### 筆記

其實我在前面的[Q-1-4](https://github.com/Dai-Son/Personal-Note-For-AP325/tree/main/第一章#作法-3 "Q-1-4")就用過前綴和(prefix-sum)的用法了

可以看裡面的delta就是前綴和的運用

而這邊求區間和就是用一個ps[n]來分別記錄陣列的 A[1] , A[1]+A[2] , ....... , A[1]+A[2]+...+A[n] 的和

EX: ps[0] = A[1], ps[1] = A[1] + A[2], ps[n] = A[1] + A[2] + ........ + A[n]

後再用這些值來計算其中區間的和

EX: 我要求第3個到第5個數字之和就會是 ps[4] ( A[1] ~ A[5] 的和 ) - ps[1] ( A[1] ~ A[2] 的和 )
## P-1-7
### 題目
[![P-1-7](https://cdn.discordapp.com/attachments/988162819679715408/1024721166650323044/unknown.png "P-1-7")](https://judge.tcirc.tw/ShowProblem?problemid=d006 "P-1-7")
### 作法
##### 教授作法
**從這邊起我會自己幫教授的code加上中文註解 如果想看原程式請去[教授的google drive](https://drive.google.com/drive/u/0/folders/10hZCMHH0YgsfguVZCHU7EYiG8qJE5f-m "教授的google drive")找**

迴圈
```cpp
// subset product = 1 mod P, using loop
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, ans=0;
    long long P=10009, A[26];
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%lld", &A[i]);
    for (int s=1; s< (1<<n); s++) {
        /*
          s表所有二進位組合方式
          例假設n是8 則s最大值為255 ( 二進位 1111 1111 )
          最小為 1 ( 二進位 0000 0001 )
          所以會一路跑過 8位所有的0和1組合
        */
        long long prod=1; // 每作完一次要歸1給下一個組合用
        for (int j=0;j<n;j++) {
            if (s & (1<<j))
            /*
              &-按位與
              0001 & 1010 = 0000 (0)
              0001 & 1011 = 0001 (1)
              1010 & 1000 = 1000 (8)

              1<< j 表示 第j位bit為1 (2的j次)
              1<<0 0001 (1)
              1<<3 1000 (8)

              所以這邊if (s & (1<<j))
              是在檢測哪幾位是1哪幾位是0
              以達到檢測每一種組合的作法
            */
                prod = (prod*A[j])%P;
        }
        if (prod==1) ans++;
    }
    printf("%d\n", ans);
}

```

遞迴
```cpp
// subset product = 1 mod P, using recursion
#include<bits/stdc++.h>
using namespace std;
int n, ans=0;
long long P=10009, A[26];
// for i-th element, current product=prod
void rec(int i, int prod) {
    if (i>=n) { // terminal condition
        if (prod==1) ans++;
        return;
    }
    rec(i+1, (prod*A[i])%P); // select A[i]
    rec(i+1, prod); // discard A[i]
    return;
}

int main() {
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%lld", &A[i]);
    ans=0;
    rec(0,1);
    printf("%d\n", ans-1); // -1 for empty subset
    return 0;
}
```
##### 我的作法
```cpp
#include <bits/stdc++.h>
using namespace std;
#define StarBurstStream ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void recur( int i , long long p );

int n, ans;
long long A[26];


int main(void){
	int i;

	StarBurstStream

	cin >> n;
	for( i = 0 ; i < n ; i++ ) cin >> A[i];

	recur( 0 , 1 );

	cout << ans-1 << '\n'; //全不選的情況下 p還是等於1 所以輸出要減1

	return 0;
}

void recur( int i, long long p ){
	if ( i >= n ){
		if( p == 1 ) ans++;
	}else{
		recur( i + 1 , ( p*A[i] ) % 10009 ); //選
		recur( i + 1 , p ); //不選
	}
}
```
#####筆記

窮舉的問題在這種情況下就是把所有可能列出來

而迴圈的做法就像是在列樹狀圖一樣

把所有的可能性都試一遍後 用ans紀錄有多少個符合條件

## Q-1-8
### 題目
[![Q-1-8](https://cdn.discordapp.com/attachments/988162819679715408/1025077066514833539/unknown.png "Q-1-8")](https://judge.tcirc.tw/ShowProblem?problemid=d007 "Q-1-8")
#####我的作法
```cpp
#include <bits/stdc++.h>
#define StarBurstStream ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int n,p,A[26];
int CalcMx;

void solve( int where , int calc ){
	if( where >= n ){
		if ( calc <= p ){
			CalcMx = max( calc, CalcMx );
		}
		return;
	}
	solve( where + 1 , calc + A[where] ); // 選
	solve( where + 1 , calc); // 不選
}


int main(void){

	StarBurstStream

	cin >> n >> p;
	for( int i = 0; i < n ; i++ ){
		cin >> A[i];
	}
	CalcMx = 0;
	solve( 0 , 0 );
	cout << CalcMx << '\n';
	return 0;
}
```
#####筆記

同P-1-7

## P-1-9
### 題目
![P-1-9](https://cdn.discordapp.com/attachments/988162819679715408/1025282975518183464/unknown.png "P-1-9")

(TCIRC未收錄)

#####筆記
這邊教授在解釋 字典順序(lexicographic order) 和教 庫存函數(next_permutation()) 的用法

字典順序就是把有一整串排列依照在字典順序進行排列的方法

換個方式說明一下 我們先來講比大小

-------

從**單個字元**來看
```
'0' < '1' < '2' < '3' ...... < 'a' < 'b' < 'c' ...... < 'z'
```

從**多個字元**來看

從左邊往右比 比到有結果為止

如果第1位相等 就比較第2位 直至有一位可以比較出大小來 則不再繼續比較。
```
'ab' < 'ac'  'abc' < 'ac' // 從左往右比 比到第二位  'app' < 'apple' // 從左往右比 比到第四位 空視為最小
```

**排序**
由最小的一路排到最大

詳細的作法就是

[![字典排序](https://img-blog.csdnimg.cn/20181101133823660.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0hhcHB5Um9ja2luZw==,size_16,color_FFFFFF,t_70 "字典排序")](https://www.796t.com/content/1541608144.html "字典排序")
```
'abc' => 'acb' => 'bac' => 'bca' => 'cab' => 'cba'
```

-------

<p align="right">-引自 <a href="https://www.796t.com/content/1541608144.html">程式人生 > > 字典序演算法詳解</a></p>

庫存函數(next_permutation())便是利用整個過程

生成n個數的全排列

範例如下
```cpp
int a[3] = { 1 , 2 , 3 }
string b[3] = { a , b , c }
int c[3] = { 3 , 2 , 1 }
string d[3] = { c , b , a }

next_permutation(a,a+3)
next_permutation(b,b+3)
next_permutation(c,c+3)
next_permutation(d,d+3)

/*
*******
result
*******
*/

a[3] == { 1 , 3 , 2 }
b[3] == { a , c , b }
c[3] == { 1 , 2 , 3 }
d[3] == { a , b , c }
```


但要注意的是 假設拿它當作布林值(boolean) 循環時會當作false

也就是說 假設 string a[3] = { c , b , a }

while ( next_permutation( a , a + 3 ) )會跳出while

接著我們看皇后的攻擊模式

![Queen](https://cdn.discordapp.com/attachments/988162819679715408/1026900399548006460/unknown.png "Queen")

看到這張圖也不難理解為什麼會用到字典序了吧

只要今天皇后要在互不攻擊的情況下做全排列

他們必然要在不同列或行

所以我們只要做pos[N]個數的全排列 就能窮舉完所有有可能的排列了

教授作法,窮舉 (即逐行討論)
```cpp
#include<bits/stdc++.h>
using namespace std;
int nq(int n) {
    int p[14], total=0;
    for (int i=0;i<n;i++) p[i]=i; //first permutation
    do {
    // check valid
        bool valid=true;
        for (int i=0; i<n; i++) for (int j=i+1;j<n;j++)
            if (abs(p[i]-p[j])==j-i) { // one the same diagonal
                valid=false;
                break;
            }
        if (valid) total++;
    }while (next_permutation(p, p+n)); // until no-next
    return total;
}
int main() {
    for (int i=1;i<12;i++)
    printf("%d ",nq(i));
    return 0;
}
```
教授作法,遞迴 (個人註解)
```cpp
// number of n-queens, recursion
#include<bits/stdc++.h>
using namespace std;
// k 表現在查證到哪一"行", p[] 表他被放在前面"行"的"列" EX p[a] == b 被放在第a行的第b個
int nqr(int n, int k, int p[]) {
    if (k>=n) return 1; // 排完最後一行了 回傳1(total++)
    int total=0;
    for (int i=0;i<n;i++) { // 試每一欄可不可以放
        // 檢查可行性
        bool valid=true;
        for (int j=0;j<k;j++)
            if (p[j]==i || abs(i-p[j])==k-j) {
                valid=false;
                break;
            }
        if (!valid/*vaild == false*/) continue; //不行了就檢查下一行
        p[k]=i; //p
        total+=nqr(n,k+1,p);
    }
    return total;
}
int main() {
    int p[15];
    for (int i=1;i<12;i++)
    printf("%d ",nqr(i,0,p));
    return 0;
}
```

另外 教授還有寫了一個更快的方法

需要可以自己點開AP325看歐
## Q-1-10
### 題目
[![Q-1-10](https://cdn.discordapp.com/attachments/988162819679715408/1031977463590420520/unknown.png "Q-1-10")](https://judge.tcirc.tw/ShowProblem?problemid=d008 "Q-1-10")
##### 我的作法
```cpp
#include <bits/stdc++.h>
#define StarBurstStream ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

void again_nq( int n, int k, int p[]);

int chessboard[14][14];
int score;

int main(void){

	StarBurstStream

	int n;
	int i, j;
	int p[14];

	cin >> n;
	for( i = 0 ; i < n ; i++ ){
		for( j = 0 ; j < n ; j++ ){
			cin >> chessboard[i][j]; //紀錄分數
		}
	}

	again_nq( n, 0 ,p ); //遞迴 ( n, 0, p[]) n表共有多少行 0表在第幾行 p[]紀錄在哪行放哪列
	cout << score << '\n';

	return 0;
}

void again_nq( int n, int k, int p[])
{
    //vaild確定可行性
	bool vaild[14];
	int i,j;
	int t;

	if( k >= n ){
		t = 0;
		for( i = 0 ; i < n ; i++ ){
			t += chessboard[i][p[i]];
		}
		score = max(score , t );
		return;
	}

	for( i = 0 ; i <= n ; i++ ) vaild[i] = true; //重置

	for( j = 0 ; j < k ; j++ ){ //標註哪裡不能放
		vaild[p[j]] = false;

		i = ( k - j ) + p[j];
		if( i < n ) vaild[i] = false;

		i = p[j] - ( k - j );
		if( i >= 0 ) vaild[i] = false;
	}

	for( i = 0; i <= n ; i++ ){
		if( vaild[i] ){ //如果可以放這位置的話 討論下一行

			p[k] = i;
			again_nq( n , k+1 , p );
		}
	}
}
```
## Q-1-11
### 題目
[![Q-1-11](https://cdn.discordapp.com/attachments/988162819679715408/1032348494100447232/unknown.png "Q-1-11")](https://judge.tcirc.tw/ShowProblem?problemid=d009 "Q-1-11")
```cpp
#include <bits/stdc++.h>
#define StarBurstStream ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int again_del( int r0, int c0, int r1, int c1);
int cost( int isR, int p, int q0 ,int q1 ); 

int m, n;
int matrix[13][13]; //矩陣

int main(void){
	
	StarBurstStream
	
	int i,j;
	
	cin >> m >> n;
	for( i = 0 ; i < m ; i++ ){
		for( j = 0 ; j < n ; j++ ){
			cin >> matrix[i][j];
		}
	}
	
	cout << again_del( 0, 0, m-1, n-1 ) << '\n'; 
	
	return 0;
}

//遞迴所有刪法
int again_del( int r0, int c0, int r1, int c1){// again_del(最上,最左,最下,最右)
	
	int minimal = 2147483647;
	int t;
	
	if( r0 == r1 || c0 == c1 ) return 0; //只剩一列
	
	//del最上
	t = cost(1 , r0, c0, c1) + again_del( r0+1, c0, r1, c1 );
	minimal = min( minimal, t ); 
	
	//del最下 
	t = cost(1 , r1, c0, c1) + again_del( r0, c0, r1-1, c1 );
	minimal = min( minimal, t ); 
	
	//del最左 
	t = cost(0 , c0, r0, r1) + again_del( r0, c0+1, r1, c1 );
	minimal = min( minimal, t ); 
	
	//del最右 
	t = cost(0 , c1, r0, r1) + again_del( r0, c0, r1, c1-1 );
	minimal = min( minimal, t ); 
	
	return minimal;
}

//計算成本
int cost( int isR, int p, int q0 ,int q1 ){ //cost( 是行是列, 哪一行/列, 位置, 位置 ) 
	int i;
	int zero=0, one=0;
	
	if(isR){ //列成本
		for( i = q0 ; i <= q1 ; i++ ){
			if(matrix[p][i]) one++;
			else zero++;
		} 
		return min( zero , one );
	}else{ //行成本
		for( i = q0 ; i <= q1 ; i++ ){
			if(matrix[i][p]) one++;
			else zero++;
		} 
		return min( zero , one );
	}
}

```
