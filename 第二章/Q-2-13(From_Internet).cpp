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
