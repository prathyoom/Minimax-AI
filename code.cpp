#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    long value;
    void max(node a,node b)
    {
        if(a.value>b.value)
            value=a.value;
        else    
            value=b.value;
    }
    void min(node a,node b)
    {
        if(a.value>b.value)
            value=b.value;
        else    
            value=a.value;
    }
}a[123456];

void update(long pos)
{
    int i=0;
    pos>>=1;
    while(pos!=0)
    {
        if(i++%2==0)
        a[pos].max(a[pos*2],a[pos*2+1])
        else
        a[pos].min(a[pos*2],a[pos*2+1])
        pos>>=1;
    }
}

int main() {
	long n,p,k,l,m;
	k=ceil(log(n)/log(2));
	p=1<<k;
	for(i=0;i<n;i++)
	{
	    cin>>a[p+i].value;
	    update(p+i,k);
	}
	for(i=0;i<)
	return 0;
}
