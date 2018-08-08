#include <iostream>
using namespace std;

char a[7][6],b[7][6];
long note;
for(int i1=0;i1<7;i1++)
a[i1]="------";

bool update(char who,int x)
{
    int i=0;
    while(a[x][i]!='-')i++;
    if(i>5)
    {return false;}
    else
    {a[x][i]=who;return true;}
}


int score()
{
    long i,j,k,l,c,sum=0;
    for(i=0;i<7;i++)
    {
        for(j=0;j<6;j++)
        {
            c=0;
            l=i;k=j;
            while(a[l++][k++]=='x')                     //right diagonal
            c++;
            if(c==2)
            sum+=2;
            else if(c==3)
            sum+=20;
            else if(c>3)
            sum+=100;
            c=0;
            l=i;k=j;
            while(a[l--][k++]=='x')                     //left diagonal
            c++;
            if(c==2)
            sum+=2;
            else if(c==3)
            sum+=20;
            else if(c>3)
            sum+=100;
            c=0;
            l=i;k=j;
            while(a[l++][k]=='x')                       //right side
            c++;
            if(c==2)
            sum+=2;
            else if(c==3)
            sum+=20;
            else if(c>3)
            sum+=100;
            c=0;
            l=i;k=j;
            while(a[l][k++]=='x')                       //up
            c++;
            if(c==2)
            sum+=2;
            else if(c==3)
            sum+=20;
            else if(c>3)
            sum+=100;
        }
    }
    //For the HOOMAN
    for(i=0;i<7;i++)
    {
        for(j=0;j<6;j++)
        {
            c=0;
            l=i;k=j;
            while(a[l++][k++]=='o')                     //right diagonal
            c++;
            if(c==2)
            sum+=-1;
            else if(c==3)
            sum+=-30;
            else if(c>3)
            sum+=-200;
            c=0;
            l=i;k=j;
            while(a[l--][k++]=='o')                     //left diagonal
            c++;
            if(c==2)
            sum+=-1;
            else if(c==3)
            sum+=-30;
            else if(c>3)
            sum+=-200;
            c=0;
            l=i;k=j;
            while(a[l++][k]=='o')                       //right side
            c++;
            if(c==2)
            sum+=-1;
            else if(c==3)
            sum+=-30;
            else if(c>3)
            sum+=-200;
            c=0;
            l=i;k=j;
            while(a[l][k++]=='o')                       //up
            c++;
            if(c==2)
            sum+=-1;
            else if(c==3)
            sum+=-30;
            else if(c>3)
            sum+=-200;
        }
    }
    return sum;   
}

long Max(int num)
{
    if(num>5)
        return score();
    long i,nux=0,check=0;
    for(i=0;i<7;i++)
    {
        char c[7][6]=a;
        if(update('x',i)==0)
            {check++;continue;}
        long y=Min(num);
        if(nux<y)
            {
                nux=y;
                if(num==1)
                note=i;
            }    
        for(int i1=0;i1<7;i1++)
	       for(int j1=0;j1<6;j1++)
	           a[i1][j1]=c[i1][j1];
    }
    if(check>5)
    return score();
    else
    return nux;
}

long Min(int num)
{
    long i,nux=1000,check=0;
    for(i=0;i<7;i++)
    {
        char c[7][6]=a;
        if(update('x',i)==0)
            {check++;continue;}
        long y=Max(num+1);
        if(nux>y)
            {
                nux=y;
            }
        for(int i1=0;i1<7;i1++)
	       for(int j1=0;j1<6;j1++)
	           a[i1][j1]=c[i1][j1];
    }
    if(check>5)
    return score();
    else
    return nux;
}

void revert()
{
    for(int i1=0;i1<7;i1++)
	   for(int j1=0;j1<6;j1++)
           a[i1][j1]=b[i1][j1];
}

int gameover()
{
    long i,j,k,l,c,sum=0;
    for(i=0;i<7;i++)
    {
        for(j=0;j<6;j++)
        {
            c=0;
            l=i;k=j;
            while(a[l++][k++]=='x')                     //right diagonal
            c++;
            if(c>3)
            return 1;
            c=0;
            l=i;k=j;
            while(a[l--][k++]=='x')                     //left diagonal
            c++;
            if(c>3)
            return 1;
            c=0;
            l=i;k=j;
            while(a[l++][k]=='x')                       //right side
            c++;
            if(c>3)
            return 1;
            c=0;
            l=i;k=j;
            while(a[l][k++]=='x')                       //up
            c++;
            if(c>3)
            return 1;
        }
    }
    for(i=0;i<7;i++)
    {
        for(j=0;j<6;j++)
        {
            c=0;
            l=i;k=j;
            while(a[l++][k++]=='o')                     //right diagonal
            c++;
            if(c>3)
            return 2;
            c=0;
            l=i;k=j;
            while(a[l--][k++]=='o')                     //left diagonal
            c++;
            if(c>3)
            return 2;
            c=0;
            l=i;k=j;
            while(a[l++][k]=='o')                       //right side
            c++;
            if(c>3)
            return 2;
            c=0;
            l=i;k=j;
            while(a[l][k++]=='o')                       //up
            c++;
            if(c>3)
            return 2;
        }
    }
    return 0;
}

void print()
{
    long i,j;
    for(i=0;i<7;i++)
    {
        for(j=0;j<6;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}

int main() {
	long n,x,i;
	for(i=0;i<42;i++)
	{
	    print();
	    if(gameover())
	    break;
	    if(i%2==0)
	        {
	            o:
	            cin>>x;
	            if(update('o',x-1)==0)
	            {
	                cout<<"Enter again :')\n";
	                goto o;
	            }
	            for(int i1=0;i1<7;i1++)
	            for(int j1=0;j1<6;j1++)
	            b[i1][j1]=a[i1][j1];
	        }
	            
	    else
	        {
	            long k=max(1);
	            revert();
	            update('x',k);
	            for(int i1=0;i1<7;i1++)
	            for(int j1=0;j1<6;j1++)
	            b[i1][j1]=a[i1][j1];
	        }
	}
	if(gameover()==1)
	cout<<"AI :) \n";
	else if(gameover()==2)
	cout<<"HOOMAN :)) \n";
	else
	cout<<"TIE \n";
	return 0;
}
