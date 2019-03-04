#include <iostream>
using namespace std;

char a[6][7],b[6][7];
long note,i1;

struct polt
{
    long scoreA;
    long scoreB;
};

polt Min(int num);

bool update(char who,int x)
{
    int i=5;
    while(a[i][x]!='-')i--;
    if(i<0)
    {
        return false;
    }
    else
    {
        a[i][x]=who;return true;
    }
}

polt score()
{
    long i,j,k,l,c;
    polt sum;
    sum.scoreA=0;sum.scoreB=0;
    for(i=0;i<6;i++)
    {
        for(j=0;j<7;j++)
        {
            c=0;
            l=i;k=j;
            while(a[l++][k++]=='x')                     //right diagonal
            c++;
            if(c==2)
            sum.scoreA+=2;
            else if(c==3)
            sum.scoreA+=20;
            else if(c>3)
            sum.scoreA+=100;
            c=0;
            l=5;k=j;
            while(a[l--][k++]=='x')                     //left diagonal
            c++;
            if(c==2)
            sum.scoreA+=2;
            else if(c==3)
            sum.scoreA+=20;
            else if(c>3)
            sum.scoreA+=100;
            c=0;
            l=i;k=j;
            while(a[l++][k]=='x')                       //right side
            c++;
            if(c==2)
            sum.scoreA+=2;
            else if(c==3)
            sum.scoreA+=20;
            else if(c>3)
            sum.scoreA+=100;
            c=0;
            l=i;k=j;
            while(a[l][k++]=='x')                       //up
            c++;
            if(c==2)
            sum.scoreA+=2;
            else if(c==3)
            sum.scoreA+=20;
            else if(c>3)
            sum.scoreA+=100;
        }
    }
    //For the HOOMAN
    for(i=0;i<6;i++)
    {
        for(j=0;j<7;j++)
        {
            c=0;
            l=i;k=j;
            while(a[l++][k++]=='o')                     //right diagonal
            c++;
            if(c==2)
            sum.scoreA+=-1;
            else if(c==3)
            sum.scoreA+=-30;
            else if(c>3)
            sum.scoreA+=-2000;
            c=0;
            l=i;k=j;
            while(a[l--][k++]=='o')                     //left diagonal
            c++;
            if(c==2)
            sum.scoreA+=-1;
            else if(c==3)
            sum.scoreA+=-30;
            else if(c>3)
            sum.scoreA+=-2000;
            c=0;
            l=i;k=j;
            while(a[l++][k]=='o')                       //right side
            c++;
            if(c==2)
            sum.scoreA+=-1;
            else if(c==3)
            sum.scoreA+=-30;
            else if(c>3)
            sum.scoreA+=-2000;
            c=0;
            l=i;k=j;
            while(a[l][k++]=='o')                       //up
            c++;
            if(c==2)
            sum.scoreA+=-1;
            else if(c==3)
            sum.scoreA+=-30;
            else if(c>3)
            sum.scoreA+=-2000;
        }
    }
    //SCORE B
    for(i=0;i<6;i++)
    {
        for(j=0;j<7;j++)
        {
            c=0;
            l=i;k=j;
            while(a[l++][k++]=='x')                     //right diagonal
            c++;
            if(c==2)
            sum.scoreB+=2;
            else if(c==3)
            sum.scoreB+=20;
            else if(c>3)
            sum.scoreB+=100;
            c=0;
            l=i;k=j;
            while(a[l--][k++]=='x')                     //left diagonal
            c++;
            if(c==2)
            sum.scoreB+=2;
            else if(c==3)
            sum.scoreB+=20;
            else if(c>3)
            sum.scoreB+=100;
            c=0;
            l=i;k=j;
            while(a[l++][k]=='x')                       //right side
            c++;
            if(c==2)
            sum.scoreB+=2;
            else if(c==3)
            sum.scoreB+=20;
            else if(c>3)
            sum.scoreB+=100;
            c=0;
            l=i;k=j;
            while(a[l][k++]=='x')                       //up
            c++;
            if(c==2)
            sum.scoreB+=2;
            else if(c==3)
            sum.scoreB+=20;
            else if(c>3)
            sum.scoreB+=100;
        }
    }
    //For the HOOMAN
    for(i=0;i<6;i++)
    {
        for(j=0;j<7;j++)
        {
            c=0;
            l=i;k=j;
            while(a[l++][k++]=='o')                     //right diagonal
            c++;
            if(c==2)
            sum.scoreB+=-1;
            else if(c==3)
            sum.scoreB+=-30;
            else if(c>3)
            sum.scoreB+=-2000;
            c=0;
            l=i;k=j;
            while(a[l--][k++]=='o')                     //left diagonal
            c++;
            if(c==2)
            sum.scoreB+=-1;
            else if(c==3)
            sum.scoreB+=-30;
            else if(c>3)
            sum.scoreB+=-2000;
            c=0;
            l=i;k=j;
            while(a[l++][k]=='o')                       //right side
            c++;
            if(c==2)
            sum.scoreB+=-1;
            else if(c==3)
            sum.scoreB+=-30;
            else if(c>3)
            sum.scoreB+=-2000;
            c=0;
            l=i;k=j;
            while(a[l][k++]=='o')                       //up
            c++;
            if(c==2)
            sum.scoreB+=-1;
            else if(c==3)
            sum.scoreB+=-30;
            else if(c>3)
            sum.scoreB+=-2000;
        }
    }
    return sum;
}

polt Max(int num)
{
    if(num>3)
        return score();
    long i,check=0;
    polt nux;
    nux.scoreA=0;nux.scoreB=0;
    for(i=0;i<7;i++)
    {
        char c[7][6];
        for(int i1=0;i1<6;i1++)
           for(int j1=0;j1<7;j1++)
               c[i1][j1]=a[i1][j1];
        if(update('x',i)==0)
            {check++;continue;}
        polt y=(Min(num));
        if(nux.scoreA<y.scoreA)
            {
                nux=y;
                if(num==1)
                note=i;
            }
        for(int i1=0;i1<6;i1++)
           for(int j1=0;j1<7;j1++)
               a[i1][j1]=c[i1][j1];
    }
    if(check>6)
    return score();
    else
    {return nux;}
}

polt Min(int num)
{
    long i,check=0;
    polt nux;
    nux.scoreA=0;nux.scoreB=0;
    for(i=0;i<7;i++)
    {
        char c[7][6];
        for(int i1=0;i1<6;i1++)
           for(int j1=0;j1<7;j1++)
               c[i1][j1]=a[i1][j1];
        if(update('x',i)==0)
            {check++;continue;}
        polt y=Max(num+1);
        if(nux.scoreB<y.scoreB)
            {
                nux=y;
            }
        for(int i1=0;i1<6;i1++)
           for(int j1=0;j1<7;j1++)
               a[i1][j1]=c[i1][j1];
    }
    if(check>6)
    return score();
    else
    {return nux;}
}

void revert()
{
    for(int i1=0;i1<6;i1++)
       for(int j1=0;j1<7;j1++)
           a[i1][j1]=b[i1][j1];
}

int gameover()
{
    long i,j,k,l,c,sum=0;
    for(i=0;i<6;i++)
    {
        for(j=0;j<7;j++)
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
    for(i=0;i<6;i++)
    {
        for(j=0;j<7;j++)
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
    for(i=0;i<6;i++)
    {
        for(j=0;j<7;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}

int main() {
    long n,x,i,j1;
    for(i1=0;i1<6;i1++)
        for(j1=0;j1<7;j1++)
           a[i1][j1]='-';
    /*cin>>n;
    update('x',n-1);
    cin>>n;
    update('x',n-1);
    update('x',0);
    update('o',3);
    update('x',1);
    update('x',1);
    update('o',3);
    update('x',2);
    update('o',3);
    update('o',3);
    */
    for(i=0;i<42;i++)
    {
        if(gameover())
        break;
        if(i%2==0)
            {
                print();
                o:
                cin>>x;
                if(update('o',x-1)==0)
                {
                    cout<<"Enter again :')\n";
                    goto o;
                }
                for(int i1=0;i1<6;i1++)
                for(int j1=0;j1<7;j1++)
                b[i1][j1]=a[i1][j1];
            }

        else
            {
                long k;
                polt y=Max(1);
                cout<<y.scoreA<<" "<<y.scoreB<<endl;
                k=note;
                revert();
                update('x',k);
                for(int i1=0;i1<6;i1++)
                for(int j1=0;j1<7;j1++)
                b[i1][j1]=a[i1][j1];
            }
    }
    print();
    if(gameover()==1)
    cout<<"AI :) \n";
    else if(gameover()==2)
    cout<<"HOOMAN :)) \n";
    else
    cout<<"TIE \n";
    return 0;
}
