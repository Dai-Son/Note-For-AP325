# 第三章
學測倒數35天7小時45分鐘

仍然在耕耘程式
## P-3-1
### 題目[![P-3-1](https://cdn.discordapp.com/attachments/988162819679715408/1051145680216936449/image.png)](https://judge.tcirc.tw/ShowProblem?problemid=d025)
##### 教授的作法
slow
```cpp
// tree height slow method O(nL), L=tree height
#include <bits/stdc++.h>
using namespace std;
#define N 100010

int main() {
    int parent[N]={0};  // parent of node i
    int h[N]={0};  // height of node i
    int deg[N]; // num of children
    int n, i, j, ch;
    scanf("%d", &n);
    for (i=1; i<=n; i++) {
        scanf("%d", &deg[i]); // num of children
        for (j=0; j<deg[i]; j++) {
            scanf("%d", &ch);
            parent[ch] = i; // set parent
        }
    }
    int root;
    for (root=1; root<=n; root++)
        if (parent[root]==0) break; // no parent
    printf("%d\n", root);
    long long step=0;
    for (i=1; i<=n; i++) { // for each
        int cnt=0; // num of step from i
        // go up until root
        for (j=i; j!=0; j=parent[j]) {
            h[j]=max(h[j],cnt);
            cnt++; step++;
        }
    }
    long long total=0;
    for (i=1; i<=n; i++)
        total += h[i];
    printf("%lld\n",total);
    fprintf(stderr,"%d nodes, %lld steps, ans=%lld\n",n, step,total);
	return 0;
}

```
optimization
```cpp
// tree height bottom-up dp, using STL queue
#include <bits/stdc++.h>
using namespace std;
#define N 100010

int main() {
    int parent[N]={0};  // parent of node i
    int h[N]={0};  // height of node i
    int deg[N]; // num of children
    queue<int> Q;
    int n, i, j, ch;
    scanf("%d", &n);
    for (i=1; i<=n; i++) {
        scanf("%d", &deg[i]);
        if (deg[i] == 0) Q.push(i);
        for (j=0; j<deg[i]; j++) {
            scanf("%d", &ch);
            parent[ch] = i;
        }
    }
    int root, total=0; // total height
    // a bottom-up traversal
    while (1) { // queue is not empty
        int v = Q.front(); // pop Q to v
        Q.pop();
        total += h[v]; // add to total
        int p = parent[v];
        if (p == 0) { // root
            root = v;
            break;
        }
        h[p] = max(h[p],h[v]+1);
        if (--deg[p] == 0)  // push parent to queue
            Q.push(p);
    }
    // root must be the last one in the queue
    printf("%d\n%d\n",root,total);
	return 0;
}

```
##### 我的作法
```cpp
#include <bits/stdc++.h>
using namespace std;

#define StarBurstStream ios::sync_with_stdio(0);cin.tie(0);
#define int long long

signed main(){

    StarBurstStream
    int i;

    int parent[100005]={0};
    int h[100005]={0};
    int children[100005];
    queue<int> Q;

    int N;cin >> N;

    // 輸入 紀錄有幾個孩子 和有誰有家長
    int k;
    for( i = 1 ; i <= N ; i++ ){
        cin >> k;
        children[i] = k;
        if(k == 0)
            Q.push(i);
        while(k){
            int child;cin >> child;
            parent[child]=i;
            k--;
        }
    }

    int rootans, hans=0;
    while(1){
        int v = Q.front();
        Q.pop();
        hans += h[v];
        int p = parent[v];
        if(p == 0){
            rootans = v;
            break;
        }
        h[p] = max(h[p], h[v]+1);
        children[p]--;
        if(children[p] == 0)
            Q.push(p);
    }
    cout << rootans << '\n' << hans << '\n';
}

```
##### 筆記
我的作法大致與教授的無異

bottom-up 順序 用Queue處理

只要把家長的每個孩子跑過一次 就可以記錄到這個家長的高

又因為孩子已經處理完了 所以可以去掉(剪枝) 然後再把自己當孩子處理

另外 這題也有運用在P-8-4中 我有稍微看了一下

恩... 樹 ... DFS ... top-down DP 那是之後的事了:P
## P-3-2
### 題目[![P-3-2](https://cdn.discordapp.com/attachments/988162819679715408/1052625255430111312/image.png)](https://judge.tcirc.tw/ShowProblem?problemid=d026)