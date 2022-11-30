# 第二章
小提醒 當想不通的時候可以假設後列出來

按照程式做一遍 也許你就懂了
## P-2-1
### 題目
[![P-2-1](https://cdn.discordapp.com/attachments/988162819679715408/1032705228610486363/unknown.png "P-2-1")](https://judge.tcirc.tw/ShowProblem?problemid=d010 "P-2-1")
### 作法
##### 教授作法
```cpp
// P_2_1 distinct number -- sort
#include <bits/stdc++.h>
using namespace std;
#define N 100010

int distinct(int from[], int to[], int n) {
    if (n<1) return 0;
    vector<int> v(from, from+n); // copy from[] to v
    sort(v.begin(), v.end());
    to[0]=v[0];
    int num=1; // number of distinct number
    for (int i=1; i<n; i++)
        if (v[i]!=v[i-1]) // distinct
            to[num++] = v[i];
    return num;
}
int main() {
    int a[N], b[N],n, k;
    scanf("%d", &n);
    for (int i=0;i<n;i++)
        scanf("%d", a+i);
    k=distinct(a,b,n);
    printf("%d\n",k);
    for (int i=0;i<k-1;i++)
        printf("%d ",b[i]);
    printf("%d\n",b[k-1]);
    return 0;
}

```
##### 我的作法
```cpp
#include <bits/stdc++.h>
#define StarBurstStream ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

signed main(void){

	int i;

	int n;
	vector<int> vec;
	int push;
	int count;

	StarBurstStream

	cin >> n;
	for( i = 0 ; i < n ; i++ ){
		cin >> push;
		vec.push_back(push);
	}
	sort( vec.begin () , vec.end() );
	count = unique( vec.begin () , vec.end() ) - vec.begin();
    //or count = distance( vec.begin () , unique( vec.begin () , vec.end() ) ) ;

	cout << count << '\n';
	for( i = 0 ; i < count ; i++ ){
		cout << vec[i] << ' ';
	}
	return 0;

}
```
##### 筆記
教授的寫法我就不多講了

基本上就是sort後檢查 i 和 i-1的位置一不一樣就記錄到另一個容器後輸出

那我的寫法用了&lt;algorithm&gt;的unique函數

unique函數用於刪除在range [First，Last)**連續**(所以要sort)存在的重複項

回傳值則是最後一項的指標
## P-2-2
### 題目
[![P-2-2](https://cdn.discordapp.com/attachments/988162819679715408/1034865782376648764/unknown.png "P-2-2")](https://judge.tcirc.tw/ShowProblem?problemid=d011 "P-2-2")
##### 教授作法
Sort後二分搜(lower_bound)
```cpp
// P_2_2 discretization -- sort
#include <bits/stdc++.h>
using namespace std;
#define N 100010

int distinct(int from[], int to[], int n) {
    if (n<1) return 0;
    vector<int> v(from, from+n); // copy from[] to v
    sort(v.begin(), v.end());
    to[0]=v[0];
    int num=1; // number of distinct number
    for (int i=1; i<n; i++)
        if (v[i]!=v[i-1]) // distinct
            to[num++] = v[i];
    return num;
}
int main() {
    int a[N], b[N],n, k;
    // input data
    scanf("%d", &n);
    for (int i=0;i<n;i++)
        scanf("%d", a+i);
    // sort distinct number to b
    k=distinct(a,b,n);
    // replace number with its rank
    for (int i=0;i<n;i++) {
        a[i] = lower_bound(b, b+k,a[i]) - b; // always found
    }
    // output
    for (int i=0;i<n-1;i++)
        printf("%d ",a[i]);
    printf("%d\n",a[n-1]);
    return 0;
}

```
Sort後二分搜(手寫)
```cpp
// P_2_2 discretization -- sort
#include <bits/stdc++.h>
using namespace std;
#define N 100010

int distinct(int from[], int to[], int n) {
    if (n<1) return 0;
    vector<int> v(from, from+n); // copy from[] to v
    sort(v.begin(), v.end());
    to[0]=v[0];
    int num=1; // number of distinct number
    for (int i=1; i<n; i++)
        if (v[i]!=v[i-1]) // distinct
            to[num++] = v[i];
    return num;
}
int main() {
    int a[N], b[N],n, k;
    // input data
    scanf("%d", &n);
    for (int i=0;i<n;i++)
        scanf("%d", a+i);
    // sort distinct number to b
    k=distinct(a,b,n);
    // replace number with its rank
    for (int i=0;i<n;i++) {
        if (b[0]==a[i]) {
            a[i]=0;
            continue;
        }
        // binary search
        int p=0; // always b[p]<a[i]
        for (int jump=k/2; jump>0; jump>>=1) {
            while (p+jump<k && b[p+jump]<a[i])
                p+=jump;
        }
        a[i] = p+1;
    }
    // output
    for (int i=0;i<n-1;i++)
        printf("%d ",a[i]);
    printf("%d\n",a[n-1]);
    return 0;
}

```
Set/Map作法
```cpp
// P_2_2 discretization -- map
#include <bits/stdc++.h>
using namespace std;
#define N 100010

int main() {
    int a[N],n, k;
    // input data
    scanf("%d", &n);
    for (int i=0;i<n;i++)
        scanf("%d", a+i);
    map<int,int> S;
    for (int i=0;i<n;i++)
        S[a[i]] = 0; // insert a[i] and set rank=0
    int r=0;
    // traversal and set rank in second
    for (auto it=S.begin(); it!=S.end(); ++it) {
        it->second = r++;
    }
    // replace number with its rank
    for (int i=0;i<n;i++) {
        a[i] = S.find(a[i]) -> second; // always found
        // find() return the iterator, then take the rank
        // or S.lower_bound(a[i]) -> second;
    }
    // output
    for (int i=0;i<n-1;i++)
        printf("%d ",a[i]);
    printf("%d\n",a[n-1]);
    return 0;
}

```
##### 我的作法
對 我用了replace 最懶的那種

方便是方便 但不建議使用倒是真的

測資只要大一點 replace的速度就會跟lower_bound拉開差距

**tl;dr 考試建議乖乖用lower_bound 不會多多少行 但可以避免TLE**
```cpp
d011. 例題 P-2-2. 離散化 – sort -- AP325
#include <bits/stdc++.h>
#define StarBurstStream ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

signed main(void){
	int i;

	int n;
	vector<int> vec;
	vector<int> vec2;
	int push;
	int where;
	
	StarBurstStream
	
	cin >> n;
	for( i = 0 ; i < n ; i++ ){
		cin >> push;
		vec.push_back(push);
	} 
	
	vec2 = vec;
		
	sort( vec.begin () , vec.end() );
	where = unique( vec.begin () , vec.end() ) - vec.begin();
	
	for( i = 0 ; i < where ; i++ ){
		replace( vec2.begin() , vec2.end() , vec[i] , i );
	}
	
	for( i = 0 ; i < n ; i++ ){
		cout << vec2[i] << ' ';
	} 
}
```
##### 筆記
這邊又双提到了二分法

而我在第一章的筆記已經提過了

詳情可以點[這裡](https://github.com/Dai-Son/Note-For-AP325/tree/main/第一章#筆記-1 "這裡")

另外另外 這邊有用了一個新的資料結構叫做map
***
map是一種關聯式容器

會把第一個輸入的key值 和給予的另一個元素連接

EX:
```cpp
map<int,int> mp
//   ^   ^
//  key 元素 
```

再透過key值來為搜尋、插入、修改、刪除

而key是唯一值 也就是說一個key只能對應一個值

相關的操作有

    -元素存取
    operator[]：存取指定的[i]元素的資料
    -迭代器
    begin()：回傳指向map頭部元素的迭代器
    end()：回傳指向map末尾的迭代器
    rbegin()：回傳一個指向map尾部的反向迭代器
    rend()：回傳一個指向map頭部的反向迭代器
    -容量
    empty()：檢查容器是否為空，空則回傳true
    size()：回傳元素數量
    max_size()：回傳可以容納的最大元素個數
    -修改器
    clear()：刪除所有元素
    insert()：插入元素 (要插入pair歐)
    erase()：刪除一個元素
    swap()：交換兩個map
    -查找
    count()：回傳指定元素出現的次數
    find()：查找一個元素
	
***
而這題教授即使用**key是唯一值**的概念 把unique的效果寫出 如下
```cpp
    map<int,int> S;
    for (int i=0;i<n;i++)
        S[a[i]] = 0; // insert a[i] and set rank=0
    int r=0;
    // traversal and set rank in second
    for (auto it=S.begin(); it!=S.end(); ++it) {
        it->second = r++;
    }
    // replace number with its rank
    for (int i=0;i<n;i++) {
        a[i] = S.find(a[i]) -> second; // always found
        // find() return the iterator, then take the rank
        // or S.lower_bound(a[i]) -> second;
    }
```
## P-2-3
### 題目
[![P-2-3](https://cdn.discordapp.com/attachments/988162819679715408/1039567446853558392/image.png "P-2-3")](https://judge.tcirc.tw/ShowProblem?problemid=d012 "P-2-3")
### 作法
##### 教授作法
```cpp
// find x^y mod P, 32-bit positive int x, y, p
#include <cstdio>
typedef long long LL;
LL exp(LL x, LL y, LL p) {
    if (y==0) return 1;
    if (y & 1) return (exp(x, y-1,p)*x)%p;
    // otherwise y is even
    LL t=exp(x, y/2, p);
    return (t*t)%p;
}

LL exp2(LL x,LL y,LL p) {
    LL t=1, xi=x, i=1; // t is result, xi = x^ (2^i)
    while (y>0) {
        if (y & 1) // odd, (i-1)-bit of y = 1
            t=(t*xi)%p;
        y>>=1;
        xi=(xi*xi)%p;
        i=i*2; // i is useless, for explanation
    }
    return t;
}

int main() {
	long long x, y, p, res;
	scanf("%lld%lld%lld", &x, &y, &p);
	printf("%lld\n",res=exp(x, y,p));
	if (res!=exp2(x,y,p))
        fprintf(stderr,"different result");
    return 0;
}

```
##### 我的作法
```cpp
#include <bits/stdc++.h>
#define StarBurstStream ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int recur_exp(int x, int y, int p);

signed main(void){
	
	StarBurstStream
	long long x, y, p;
	
	cin >> x >> y >> p;
	cout << recur_exp(x, y, p) << '\n';
	
	return 0;

}

int recur_exp(int x, int y, int p)
{
	
	int t;
	
	if(p == 1) return 0;
	if(y == 0) return 1;
	
	//y是奇數
	if(y & 1){
		return (recur_exp(x,y-1,p)*x) % p;
	}
	
	t = recur_exp(x ,y/2 ,p);
	return (t*t)%p;
}
```
##### 筆記

數論:skull:

平方求冪(快速冪)的概念在於把指數化為二進制

也就是只要知道  $a^1, a^2, a^4, a^8, \dots, a^{2^{\lfloor \log_2 n \rfloor}}$

這樣一來只需要 $\Theta(\log n)$ 的時間就能求出想要的值 進而求模

整理如下

[![快速冪](https://wikimedia.org/api/rest_v1/media/math/render/svg/46fe9e68c70c04df4c3d22c469a57d4655b50539 "快速冪")](https://zh.wikipedia.org/zh-tw/平方求幂 "快速冪")

不適很懂沒關西

以我的這段遞迴為例
```cpp
int recur_exp(int x, int y, int p)
{
	
	int t;
	
	if(p == 1) return 0;
	if(y == 0) return 1;
	
	//y是奇數
	if(y & 1){
		return (recur_exp(x,y-1,p)*x) % p;
	}
	
	t = recur_exp(x ,y/2 ,p);
	return (t*t)%p;
}
```
還是看不懂?

我們用return的值回推思考

$mod$先不看 這邊只看x, y也就是$x^y$

設要求的值是$3^{19}$好了

	第一次return:
	recur(3,18) * 3
	
	第二次return:
	recur(3,9) * recur(3,9) * 3

	第三次return:
	recur(3,8) * recur(3,8) * ( 3 * 3 ) * 3
	^^^^^^^^^^^^^^^^^^^^^^^   ^^^^^^^^^   ^
	8為2的3次 因此會一路做到3,1     3^2     3^1
	做八次 * 八次 也就是3^16

也就是
$$
3^{19} (3^{(1\ 0011)}) = 3^{16} * 3^2 * 3^1 
$$
## P-2-4
### 題目
[![Q-2-4](https://cdn.discordapp.com/attachments/988162819679715408/1039914173498392628/image.png "Q-2-4")](https://judge.tcirc.tw/ShowProblem?problemid=d013 "Q-2-4")
### 作法
##### 我的作法
```cpp
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

    //long long 裝不下200位整數 => 用string裝
	cin >> s;

	cin >> y >> p;

	//s[0]-'0' 把s的第0位轉換成int
	x = (s[0]-'0') % p;

    //逐位求模
	for (i=1; i<s.length(); i++){
		x = (x*10+(s[i]-'0')) % p;
	}

	cout << recur_exp(x, y, p) << '\n';
	return 0;

}

//快速冪
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
```
##### 筆記
因輸入的數字極大 所以只能先求模後做次方

模是可以一位一位做的 內容在AP325內有提到

$$
123\pmod{p} = ((1*10+2)*10+3)\pmod{p}
$$

$$
=>
$$

$$
((((1*10\pmod{p}+2)\pmod{p})*10\pmod{p}+3)\pmod{p}
$$

後再用上面的快速冪處理
## Q-2-5
### 題目
[![Q-2-5](https://cdn.discordapp.com/attachments/988162819679715408/1039923726315167814/image.png "Q-2-5")](https://judge.tcirc.tw/ShowProblem?problemid=d014 "Q-2-5")
### 作法
##### 我的作法
```cpp
#include <bits/stdc++.h>
using namespace std;
#define StarBurstStream ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int unsigned long long
//快速冪
vector<vector<int>> recur_exp(int n);

//矩陣乘法
vector<vector<int>> multipy(vector<vector<int>> a, vector<vector<int>> b);

int fib(int m);

//矩陣
vector<vector<int>> tmp( 2, vector<int> ( 2 , 0 ) );
vector<vector<int>> A
{
    { 1 , 1 },
    { 1 , 0 }
};

int P = 1000000007;
signed main(){

    StarBurstStream
    int in;

    while( cin >> in && in != -1 ){
        cout << fib(in) << '\n';
    }
    return 0;
}

vector<vector<int>> recur_exp(int n){

    if( n == 1 ) return A;

    //n是奇數
    else if( n & 1 ){
        tmp = recur_exp((n-1)/2);
        return multipy(multipy(tmp, tmp), A);
    }

    tmp = recur_exp(n/2);
    return multipy(tmp, tmp);

}

vector<vector<int>> multipy(vector<vector<int>> a, vector<vector<int>> b){
    int c1 = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % P;
    int c2 = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % P;
    int c3 = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % P;
    int c4 = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % P;
    vector<vector<int>> c
    {
        { c1 , c2 },
        { c3 , c4 }
    };
    return c;
}

int fib(int m){
    if( m <= 1 ) return m;
    return recur_exp(m-1)[0][0];
}

```
##### 筆記
根據AP325的內容有提到

![Fibonacci](https://miro.medium.com/max/640/1*mgeTnofXk6e-OK68tRT9VQ.png)

所以我在上面開了vector\<vector\<int\>\> 當作矩陣做處理

最一開始寫是想說用int開

但發現int不能return 數列 矩陣之類的 只能用指標return
 
因此改vector\<vector\<int\>\> 

用法上近無差異
## P-2-6
### 題目
[![P-2-6](https://cdn.discordapp.com/attachments/988162819679715408/1041731847756976189/image.png)](https://judge.tcirc.tw/ShowProblem?problemid=d015)
### 作法
##### 教授作法
```cpp
// p_2_6 find a+b=k
#include <bits/stdc++.h>
using namespace std;
#define N 100010
int a[N], b[N];

int main() {
    int m, n, k,i;
    scanf("%d %d %d", &m,&n,&k);
    //fprintf(stderr,"%d, %d, %d\n",m,n,k);
    for (i=0;i<m;i++) scanf("%d", a+i);
    for (i=0;i<n;i++) scanf("%d", b+i);
    sort(a, a+m); // sort a from small to large
    sort(b, b+n); // sort b from small to large
    int j=n-1; // index of b, from n-1 to 0
    int ans=0;
    for (i=0; i<m; i++) { // each a[i]
        while (j>0 && b[j]>k-a[i]) // backward linear search
            j--;
        if (a[i]+b[j]==k) {
            ans++;
            //fprintf(stderr,"(%d, %d)",a[i],b[j]);
        }
    }
    printf("%d\n",ans);
	return 0;
}
```
```cpp
// p_2_6b find a+b=k, using set
#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n, k,i,t;
    scanf("%d %d %d", &m,&n,&k);
    set<int> S;
    // read A into set
    for (i=0;i<m;i++) {
        scanf("%d", &t);
        S.insert(t);
    }
    int ans=0;
    for (i=0;i<n;i++) { // for each t in B
        scanf("%d", &t);
        if (S.find(k-t)!=S.end()) // search k-t in A
            ans++;
    }
    printf("%d\n",ans);
	return 0;
}
```
##### 我的作法
```cpp
#include <bits/stdc++.h>
#define StarBurstStream ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

signed main(void){
	
	int m,n,k;
	int i;
	int answer = 0;
	
	set<int> A;
	int s;
	
	cin >> m >> n >> k;
	for( i=0; i<m ; i++ ){
		cin >> s;
		A.insert(s);
	} 
	
	for( i = 0 ; i < n ; i++ ){
		cin >> s;
		//set.find(val) 回傳val在此set的指標 val不存在則回傳set.end()
		if(A.find(k-s) != A.end()) answer++;
	}
	
	cout << answer << '\n';

	return 0;
	
}
```
##### 筆記
教授在AP325內有提供不同的想法來做

而我最後選了用set來做

因為集合每個元素最多只有一個

所以用set.find找是可行的

要再快的話或許2分搜可以快一點點
## Q-2-7
### 題目
[![Q-2-7](https://cdn.discordapp.com/attachments/988162819679715408/1041740217415114794/image.png)](https://judge.tcirc.tw/ShowProblem?problemid=d016)
##### 我的作法
```cpp
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
	二進制
	假設m=3
	就是把1左移3格
	也就是 1000
	-1後退位 變成 0111
	就可以用不同位置的1代表不同的英文字母
	*/
	cin >> m >> n;
	U = ( 1 << m ) - 1;
	
	while(n--){
		cin >> str0;
		
		team = 0;
		for( i = 0 ; i < str0.length() ; i++ ){
			/*
			假設str0 = "ABC"
			str0[0] - 'A' = 0
			str0[1] - 'A' = 1
			str0[2] - 'A' = 2
			也就是說0111 個位數的1代表有A 十位數的1代表有B etc...
			*/
			team |= 1 << str0[i] - 'A'; 
			/*
			| (OR運算子)
			只要兩個對應位中有一個1時就為1
			*/
		}
		v0.push_back(team);
		
		//紀錄和這個team互補的team
		complement = U-team;
		s0.insert(complement);
	}
	
	answer = 0;
	//因為題目保證沒有兩個相同的團隊 因此用set.find找
	for( i = 0 ; i < v0.size() ; i++ ){
		if( s0.find(v0[i]) != s0.end() ) answer++; 
	}
	
	//A會補到B B會補到A 同一對 但會記錄兩次 因此最後除以
	//cout << ( answer / 2 ) << '\n';
	cout << ( answer >> 1 ) << '\n';
	
	return 0;
}
```
##### 筆記
基本上為甚麼這樣寫跟要注意的點都寫在上面了

這邊我們假設題目可能有相同的團隊的話 改用multiset

	迴圈
	multiset.find(val) != multiset.end()
	且
	multiset.erase(multiset.find(val)) ans++
	
理應當也能AC
## Q-2-8
### 題目
[![Q-2-8](https://cdn.discordapp.com/attachments/988162819679715408/1042118843079856209/image.png)](https://judge.tcirc.tw/ShowProblem?problemid=d017)
##### 我的作法
```cpp
#include <bits/stdc++.h>
using namespace std;
#define StarBurstStream ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long

int exp(int x, int y, int p);
signed main(){

    StarBurstStream

    int n, P;
    cin >> n >> P;
    while(n--){
        int in;
        cin >> in;
        cout << exp( in, P-2, P ) << " ";
    }
    cout << '\n';
}

int exp(int x, int y, int p){

    if ( y == 0 ) return 1;

    if( y & 1 ) return (exp(x, y-1, p)*x) % p;

    return (exp(x, y/2, p)*exp(x, y/2, p)) % p;

}
```
#####  筆記
這邊用了[快速冪(點我複習)](https://github.com/Dai-Son/Note-For-AP325/tree/main/%E7%AC%AC%E4%BA%8C%E7%AB%A0#%E7%AD%86%E8%A8%98-2) 結合 費馬小定理來求模逆元
##### 什麼是模逆元、費馬小定理
模逆元即 $(a*b) \pmod p = 1$的整數$b$

費馬小定理..又是數論:skull:

在p為質數的情況下

$a^p \equiv a \pmod{p}$ 和他的推導 $a^{p - 1} \equiv 1 \pmod{p}$

而這題用「若 P 為質數，對任意正整數$a$，$(a^{(p-2)} \pmod{p})$是 $a$ 在$[1, p-1]$區間的唯 一乘法反元素。」

所以只要把用快速冪處理$(a^{(p-2)} \pmod{p})$做出來就可以AC了

以下為證明

$a^{(p-2)} \equiv R \pmod{p} ,R \in [1,p-1]$

證明$b$在$[1,P-1]$內唯一

設$c \in [1,p-1] \supsetneq ac \equiv1\pmod{p}$

使 $ab =np+1$ 和 $ac =mp+1$

$\Rightarrow a(b-c)=(n-m)p$

$\Rightarrow (b-c) \equiv 0\pmod{p}$

$\Rightarrow ) b\equiv c\pmod{p}$

因此「若 P 為質數，對任意正整數$a$，$(a^{(P-2)} \pmod{P})$是 $a$ 在$[1, p-1]$區間的唯 一乘法反元素。」得證
## P-2-9
### 題目
[![P-2-9](https://cdn.discordapp.com/attachments/988162819679715408/1042844289044062260/image.png)](https://judge.tcirc.tw/ShowProblem?problemid=d018)

題目麻煩起來了.-.
##### 教授作法
```cpp
// subset product = 1 mod P, O(n*2^(n/2)), sort
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL sa[1<<19], sb[1<<19]; // subset product of a and b

// generate all products of subsets of v[]
// save result in prod[], return length of prod[]
int subset(LL v[], int len, LL prod[], LL p) {
    int k=0; // size of prod[]
    for (int i=0;i<len;i++) {
        for (int j=0;j<k;j++) { // (each subset)*v[i]
            prod[k+j]=(prod[j]*v[i])%p;
        }
        prod[k+k]=v[i]; // for subset {v[i]}
        k += k+1;
    }
    return k;
}
// find x^y mod P
LL exp(LL x, LL y, LL p) {
    if (y==0) return 1;
    if (y & 1) return (exp(x, y-1,p)*x)%p;
    // otherwise y is even
    LL t=exp(x, y/2, p);
    return (t*t)%p;
}

int main() {
    int i, n;
    LL a[30], b[30]; // input data
    LL p;
    scanf("%d%lld", &n, &p);
    int len_a=n/2;
    int len_b=n-len_a;
    for (i=0;i<len_a;i++)  // half in a
        scanf("%lld", &a[i]);
    for (i=0;i<len_b;i++)  // half in b
        scanf("%lld", &b[i]);
    int len_sa=subset(a,len_a,sa,p); // all subsets of a
    int len_sb=subset(b,len_b,sb,p); // all subsets of a
    sort(sb, sb+len_sb);
    // merge same element of sb, assume not empty
    LL num[1<<19], len_sb2=1;
    num[0]=1; //its multiplicity
    for (i=1;i<len_sb;i++) {
        if (sb[i]!=sb[i-1]) { // new element
            sb[len_sb2]=sb[i];
            num[len_sb2]=1;
            len_sb2++;
        }
        else {
            num[len_sb2-1]++;
        }
    }
    LL ans = (sb[0]==1) ? num[0]: 0; // the number of 1 in sb2
    // compute 1 in sa and cross the two sides
    // for each x in sa, find its inverse in sb2
    for (i=0; i<len_sa; i++) {
        if (sa[i]==1) ans=(ans+1)%p;
        LL y = exp(sa[i], p-2, p); // inverse
        int it = lower_bound(sb, sb+len_sb2, y) - sb;
        if (it<len_sb2 && sb[it]==y)  // found
            ans = (ans + num[it])%p;
    }
    printf("%lld\n", ans);
    return 0;
}
```
```cpp
// subset product = 1 mod P, O(n*2^(n/2)), using map
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
// recursive generate product of subsets of v[0..i]
// current product=prod, result stored in M
void rec(vector<LL> &v, int i, LL prod, map<LL,LL> &M, LL p) {
    if (i>=v.size()) { // terminal condition
        M[prod] += 1; // insert into map
        return;
    }
    rec(v, i+1, (prod*v[i])%p, M, p); // select v[i]
    rec(v, i+1, prod, M, p); // discard v[i]
    return;
}
// find x^y mod P
LL exp(LL x, LL y, LL p) {
    if (y==0) return 1;
    if (y & 1) return (exp(x, y-1,p)*x)%p;
    // otherwise y is even
    LL t=exp(x, y/2, p);
    return (t*t)%p;
}

int main() {
    int i, n;
    vector<LL> a, b; // input data
    LL p;
    scanf("%d%lld", &n, &p);
    for (i=0;i<n/2;i++) { // half in a
        LL t;
        scanf("%lld", &t);
        a.push_back(t);
    }
    for ( ;i<n;i++) { // half in b
        LL t;
        scanf("%lld", &t);
        b.push_back(t);
    }
    map<LL,LL> M1, M2;
    rec(a,0,1,M1,p); // all subsets of a
    rec(b,0,1,M2,p); // all subsets of b
    M1[1] -= 1; // empty set was counted as product 1
    M2[1] -= 1; // empty set
    LL ans=M1[1]+M2[1]; // the number of 1 in both sides
    // compute 1 cross the two sides
    // for each x in M1, find its inverse in M2
    for (auto e: M1) {
        LL x=e.first, num=e.second;
        LL y = exp(x, p-2, p); // inverse of x
        //printf("%lld, %lld; ",x,y);
        auto it=M2.find(y);
        if (it!=M2.end()) { // found
            ans = (ans + num*it->second)%p;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
```
##### 筆記
這一段我打算先寫筆記再往後紀錄我的寫法

再開始前 請先看懂題目 再看這個依照題目寫的枚舉做法
```cpp
#include <bits/stdc++.h>
using namespace std;
#define StarBurstStream ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long

signed main(){

	StarBurstStream

    int i, n, p, a[50];

    cin >> n >> p;

    for (i=0;i<n;i++)
        cin >> a[i]

    map<int,int> M1; // Map key紀錄元素 值紀錄數量 (M1[元素] = 數量)
    M1[a[0]]=1; // 第一個元素出現一次

    for (i=1;i<n;i++) { // 逐個計算
        map<int,int> M2(M1); // 複製M1到M2

        for (auto e:M1){ // 跑過整個M1
            int t = (e.first*a[i])%p; // 紀錄MOD後值
            M2[t] = (M2[t] + e.second)%p;// 如果M2[t]不存在=0
        }

        M2[a[i]] = (M2[a[i]] + 1)%p; // 把a[i]這個數字也放進M2
        M1.swap(M2); // M1 M2交換
    }

    cout << M1[1] << '\n';
    return 0;
}

```
效率是 $O(2^n)$

這樣太慢了 對於題目 $P≤1000000009，0<n<37$

$n$ 是 36的情況下一定會TLE

於是就會用到底下的方法 --- 折半枚舉

    對於 n 個數字，我們先將他任意均分為兩半 A 與 B，
    我們要找的解(子集合乘積等於 1) 有三種可能：
    在 A 中、在 B 中、以及跨 AB 兩端(包含兩邊的元素)。
    我們對 A 與 B 分別去窮舉它們的子集合乘積，而佩
    可以找到在 A 中與在 B 中的解。對於跨兩邊的解，
    我們以下列方式計算：
    將其中一邊(例如 B)的所有子集合乘積予以排序後，
    我們對每一個 A 的子集合乘積 x，
    在 B 的子集合乘積中去搜尋 x 的模逆元(使得 xy = 1 的 y)。
   
而內文也有講到提升效率的辦法

    有一點必須留意，我們要把 B 的子集合乘積中，將相同的乘積予以合併，
    原因是這一題 我們需要找出組合數，若相同元素太多，
    一個 x 需要搜尋很多的模逆元就會太花時間。 
    至於 A 那一邊，合併也可以提升效率。

<p align="right">-引述自 AP325內文</p>

第二段的內容

換句話其實就是要我們用set/map實作

由於key的不重複性 set/map在合併上好處理的多

接著按照題目的敘述做 我們就可以寫出來

##### 我的作法

雖然做法基本上和教授第二個方法大同小異

但放上來也沒差吧
```cpp
#include <bits/stdc++.h>
using namespace std;
#define StarBurstStream ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long

void subset( vector<int> &V, int i, int prod, map<int,int> &M, int p );
int exp( int x, int y, int p);

signed main(){

	StarBurstStream

    int i, n, p;
    vector<int> va,vb;

    cin >> n >> p;

    int in;
    for (i=0;i<n/2;i++){
        cin >> in;
        va.push_back(in);
    }
    for ( ;i<n;i++){
        cin >> in;
        vb.push_back(in);
    }

    map<int,int> M1, M2; // Map key紀錄元素 值紀錄數量 (M[元素] = 數量)

    // 用迴圈紀錄所有子集合
    subset(va, 0, 1, M1, p);
    subset(vb, 0, 1, M2, p);

    // 全不選最後mod的值也是1 => 多出來的 要減掉
    M1[1] -= 1;
    M2[1] -= 1;

    int ans = M1[1] + M2[1];

    //對於所有左邊的子集合 求與M2子集合相乘後mod為1的可能
    for(auto e: M1){
        int value = e.first, counts = e.second;
        int found = exp(value,p-2,p);
        auto it = M2.find(found);
        if(it != M2.end())
            ans = (ans + (counts * it->second))%p;
    }

    cout << ans << '\n';
    return 0;
}

//求所有子集合
void subset( vector<int> &V, int i, int prod, map<int,int> &M, int p ){
    // 理論上可以寫成i == v.size() 但好像大家都寫>=
    if( i>=V.size() ){
        M[prod] += 1;
        return;
    }
    subset(V, i+1, (prod*V[i])%p, M, p); // 選
    subset(V, i+1, prod, M, p); // 不選
    return;
}

int exp( int x, int y, int p){
    if( y == 0 ) return 1;
    if( y & 1 ) return (x * exp( x, y-1, p )) % p;
    return ( exp( x, y/2, p ) * exp( x, y/2, p ) ) %p;
}

```
總時間複雜度是 $O(n*2^{n/2})$ 比起單純窮舉 $O(2^n)$要快得多了
## Q-2-10
### 題目
[![Q-2-10](https://cdn.discordapp.com/attachments/988162819679715408/1045017923724529664/image.png)](https://judge.tcirc.tw/ShowProblem?problemid=d019)
##### 我的作法
```cpp
#include <bits/stdc++.h>
using namespace std;
#define StarBurstStream ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long

void subset( vector<int> &V, int i, int prod, vector<int> &VO, int p );

signed main(){

	StarBurstStream

    int i, n, p;
    vector<int> va,vb;

    cin >> n >> p;

    int in;
    for (i=0;i<n/2;i++){
        cin >> in;
        va.push_back(in);
    }
    for ( ;i<n;i++){
        cin >> in;
        vb.push_back(in);
    }

    vector<int> V1, V2;

    // 用迴圈紀錄所有子集合
    subset(va, 0, 0, V1, p);
    subset(vb, 0, 0, V2, p);

    sort(V1.begin(),V1.end());
    auto last1 = unique(V1.begin(),V1.end());
    V1.resize(distance(V1.begin(),last1));
    sort(V2.begin(),V2.end());
    auto last2 = unique(V2.begin(),V2.end());
    V2.resize(distance(V2.begin(),last2));

    int ans = -1;
    for( auto e1:V1 ){
        int found = p - e1;
        auto it = upper_bound( V2.begin(), V2.end(), found );
        it--;
        ans = max( ans, e1+(*it));
    }

    cout << ans << '\n';
    return 0;
}
//求所有子集合
void subset( vector<int> &V, int i, int prod, vector<int> &VO, int p ){
    if( prod > p )
        return;
    // 理論上可以寫成i == v.size() 但好像大家都寫>=
    if( i>=V.size() ){
        VO.push_back(prod);
        return;
    }
    subset(V, i+1, prod+V[i], VO, p); // 選
    subset(V, i+1, prod, VO, p); // 不選
    return;
}

```
##### 筆記
這邊仍然是用了折半枚舉

中間有一串Sort, Unique, Resize整理每個子集合的和剩1個

最後二分搜 用upper_bound找第一個**大於**要找的值的指標

所以他的前一個值就是第一個小於等於要找的值的解

也就是我們要找的值
## P-2-11
### 題目
[![P-2-11](https://cdn.discordapp.com/attachments/988162819679715408/1045372731870420992/image.png)](https://judge.tcirc.tw/ShowProblem?problemid=d020)
##### 教授作法
蠻力解
```cpp
/* p_2_11
Brute force method
*/

#include<bits/stdc++.h>
using namespace std;
#define N 200010
int psum[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,t,v;
    cin>>n>>t;
    int ans=0;
    psum[0]=0;
    for (int i=1;i<=n;i++) {
        cin>>v;
        psum[i]=psum[i-1]+v;
        int best=psum[i], target=psum[i]-t;
        for (int j=0;j<i;j++) {
            if (psum[j]>=target)
                best=min(best,psum[j]);
        }
        ans=max(ans,psum[i]-best);
    }
    cout<<ans<<endl;
    return 0;
}

```
優化解
```cpp
// p_2_11

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, psum=0, k, v;
    scanf("%d%d", &n, &k);
    set<int> S({0}); // record the prefix_sum
    int best=0; // solution of empty range
    for (int r=0; r<n; r++) {
        scanf("%d", &v);
        psum += v; //prefix-sum(r)
        auto it=S.lower_bound(psum-k);
        if (it!=S.end()) // found
            best=max(best, psum-*it); //currently best
        S.insert(psum); // insert prefix-sum(r)
    }
    printf("%d\n",best);
    return 0;
}

```
##### 我的作法
```cpp
#include <bits/stdc++.h>
using namespace std;

#define StarBurstStream ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long

signed main(){

    StarBurstStream

    int n, k;
    cin >> n >> k;

    set<int> S{0}; 
    int in, presum = 0;
    int ans = -1;
    for(int i = 0; i < n; i++){
        cin >> in;
        presum += in;
        auto it = S.lower_bound(presum-k);
        if( it != S.end() )
            ans = max(ans, presum-(*it));
        S.insert(presum);
    }

    cout << ans << '\n';

}

```
##### 筆記
這邊運用到了set函式存入且搜尋

這整道程式其實不難理解 簡而言之就是紀錄prefix-sum後二分搜值

set的lower_bound用法是直接+.lower_bound

但最容易錯的應該就是旺季要給set一個0

因為假設這個prefix sum已經最接近了(presum-x)<0 如果給他第一小的正數的話會有影響的
## Q-2-12
### 題目
[![Q-2-12](https://cdn.discordapp.com/attachments/988162819679715408/1046084739142008903/image.png)](https://judge.tcirc.tw/ShowProblem?problemid=d021)
##### 我的作法
```cpp
#include <bits/stdc++.h>
using namespace std;

#define StarBurstStream ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long

signed main(){

    StarBurstStream
    int i, o, p;

    int k, m, n;
    cin >> k >> m >> n;

    vector<vector<int>> presum;
    vector<int> pushin;
    for( i = 0 ; i < n ; i++ ){
        pushin.push_back(0);
    }
    presum.push_back(pushin);


    for( i = 0 ; i < m ; i++ ){
        vector<int> pushin;
        for( o = 0 ; o < n ; o++ ){
            int in;cin >> in;
            pushin.push_back(in);
        }
        presum.push_back(pushin);
    }

    for( i = 2 ; i <= m ; i++ ){
        for( o = 0 ; o < n ; o++ ){
            presum[i][o] += presum[i-1][o];
        }
    }

    int ans = (1<<31);
    for( i = 0 ; i < m ; i++ ){
        for( o = i + 1 ; o <= m ; o++ ){
            set<int> S{0};
            int ps = 0;
            for( p = 0 ; p < n ; p++ ){
                ps += presum[o][p]-presum[i][p];
                auto it = S.lower_bound(ps-k);
                if( it != S.end() )
                    ans = max( ans, ps-(*it) );
                S.insert(ps);
            }
        }
    }

    cout << ans << '\n';

}

```
##### 筆記

這題先做每列的前綴和

每列的前綴和處理完後用兩個for 以尾-首的方式得出分別處理每種寬度矩陣的前綴和

因為不同寬度的矩陣不能處理 所以在做一個新的寬度的矩陣要把Set重製
## Q-2-13
### 題目
[![Q-2-13](https://cdn.discordapp.com/attachments/988162819679715408/1046813710427103383/image.png)](https://judge.tcirc.tw/ShowProblem?problemid=d022)
##### 網路上的寫法
Self edited
```cpp
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#define int long long
int p = 10*10*10*10*10*10*10*10*10+9;
struct Node
{
    int e[2][2];
    Node()
    {
        memset(e,0,sizeof(e));
    }
};
Node mul(Node a,Node b)
{
    Node c;

    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            for(int k=0; k<2; k++)
            {
                c.e[i][j]+=(a.e[i][k]*b.e[k][j])%p;
            }
    return c;
}

Node quick_mi(Node a,int b)
{
    Node c;
    c.e[0][0]=1;
    c.e[1][1]=1;
    while(b)
    {
        if(b&1)
            c=mul(c,a);
        b>>=1;
        a=mul(a,a);
    }
    return c;
}
signed main()
{
    int x,y,n;
    cin >> x >> y >> n;

    Node A;
    A.e[0][0]=x;
    A.e[0][1]=2*y;
    A.e[1][0]=y;
    A.e[1][1]=x;
    A=quick_mi(A,n);
    cout << A.e[0][0] % p << " " << A.e[1][0] % p <<'\n';
    return 0;
}

```
##### 我的寫法
```cpp
#include <bits/stdc++.h>
using namespace std;

#define StarBurstStream ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
int p = 10*10*10*10*10*10*10*10*10+9;

vector<vector<int>> multipy( vector<vector<int>> a, vector<vector<int>> b );
vector<vector<int>> exp( vector<vector<int>> n1, int n );

signed main(){

    StarBurstStream
    int x, y, n;cin >> x >> y >> n;

    vector<vector<int>> n1
    {
        { x, 2*y },
        { y, x }
    };

    vector<vector<int>> ans = exp( n1, n );
    cout << ans[0][0] % p << " " << ans[1][0] % p << '\n';

}
vector<vector<int>> exp( vector<vector<int>> n1, int n ){
    if( n == 0 ){
        return { {1,0},{0,1} };
    }else if( n == 1 ){
        return n1;
    }else if( n & 1 ){
        return multipy( n1, exp( n1, n-1 ) );
    }else{
        vector<vector<int>> re = exp( n1, n/2 )
        return multipy( re, re );
    }
}
vector<vector<int>> multipy( vector<vector<int>> a, vector<vector<int>> b ){
    vector<vector<int>> c{{0, 0},{0, 0}};
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            for(int k=0; k<2; k++)
            {
                c[i][j]+=(a[i][k]*b[k][j])%p;
            }
    return c;

}

```
##### 筆記
推導的過程

設 $(x+y\sqrt{2})^n  = A(n)+B(n)\sqrt{2}$

 $(x+y\sqrt{2})^{(n+1)}  = (x+y\sqrt{2})(x+y\sqrt{2})^n=(x+y\sqrt{2})(A(n)+B(n)\sqrt{2})$

得
$$
A(n+1)=x*A(n)+2*y*B(n)
$$
$$
B(n+1)=y*A(n)+x*B(n)
$$
因此做矩陣

$$
M =\begin{bmatrix}x&2y\\y&x\end{bmatrix}^n
$$

得 $A(n)=M[0][0]$ 和 $B(n)=M[1][0]$
