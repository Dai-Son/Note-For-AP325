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
#####我的作法
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