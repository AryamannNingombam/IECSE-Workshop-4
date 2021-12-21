#include <bits/stdc++.h>
using namespace std;
int find(int a[],int u)
{
    if(a[u]==u)
    return u;
    a[u]=find(a,a[u]);
    return a[u];
}
void uni(int a[],int u,int v)
{
    int x,y;
    x=find(a,u);
    y=find(a,v);
    a[x]=y;
}
int main() {
	int n,q;
	int a[100003];
	cin>>n>>q;
	for(int i=1;i<=n;i++)
        a[i] = i;
	while(q--)
	{
	    int t,x,y;
	    cin>>t>>x>>y;
	    if(t==0)
	    {
	        uni(a,x,y);
	    }
	    else
	    {
	        if(find(a,x)==find(a,y))
	        {
	            cout<<"Yes"<<"\n";
	        }
	        else
	            cout<<"No"<<"\n";
	    }
	}
	return 0;
}
