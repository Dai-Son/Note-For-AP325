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
## P-2-1
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

tl;dr 考試建議乖乖用lower_bound 不會多多少行
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