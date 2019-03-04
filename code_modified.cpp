#include<iostream>
#define inf 100000008
#include<stdlib.h>
using namespace std;

char a[6][7],b[6][7],d[6][7][5],d1[6][7][5];
int i,j,k,l,r=6,c=7;

void print()
{
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

int update(char arr[][7],char ch,int x)
{
    if(x<1 || x>c)
    return 1;
    int check=0;
    for(i=r-1;i>=0;i--)
    {
        if(arr[i][x-1]=='-')
            {
                check=1;
                arr[i][x-1]=ch;
                break;
            }
    }
    if(check==0)
        return 1;
    return 0;
}

int score(char arr[][7]);
int min(char arr[][7],int num);
int gameover();

void revert()
{
    int i1,j1;
    for(i1=0;i1<r;i1++)
    {
        for(j1=0;j1<c;j1++)
        {
            a[i1][j1]=b[i1][j1];
        }
    }
}

int max(char arr[][7],int num)
{
    if(num==3)
        {
            //print();
            return score(arr);
        }
    int maxi=-inf,move=0;
    for(int i2=0;i2<c;i2++)
    {
        for(int i1=0;i1<6;i1++)
           for(int j1=0;j1<7;j1++)
               d1[i1][j1][num]=arr[i1][j1];
        if(update(arr,'x',i2+1))
            continue;
        if(gameover())
        {
            if(num!=0)
            return inf;
            else
            return move=i2;
        }
        int x=min(arr,num);
        if(x>maxi)
        {
            maxi=x;
            move=i2;
        }
        //cout<<maxi<<":";
        for(int i1=0;i1<6;i1++)
           for(int j1=0;j1<7;j1++)
               arr[i1][j1]=d1[i1][j1][num];
    }
    if(num==0)
    {
        //cout<<maxi<<" ";
        return move;
    }
    return maxi;
}

int min(char arr[][7],int num)
{
    int mini=inf;
    for(int i2=0;i2<c;i2++)
    {
        for(int i1=0;i1<6;i1++)
           for(int j1=0;j1<7;j1++)
               d[i1][j1][num]=arr[i1][j1];
        if(update(arr,'o',i2+1))
            continue;
        if(gameover())
            return -inf;
        int x=max(arr,num+1);
        if(x<mini)
        {
            mini=x;
        }
        //cout<<" "<<mini<<":";
        for(int i1=0;i1<6;i1++)
           for(int j1=0;j1<7;j1++)
               arr[i1][j1]=d[i1][j1][num];
    }
    return mini;
}

int score(char arr[][7])
{
    int score=0,score1=0;
    for(i=0;i<r;i++)
    {
        int x1=0;
        for(j=0;j<c;j++)                                                                  //vertical
        {
            if(arr[i][j]=='x')
            {
                if(arr[i][j-1]=='x')
                x1*=50;
                else
                x1++;
            }
            else
            {
                score+=x1;
                x1=0;
            }
        }
        if(x1!=0)
        score+=x1;
    }
    //cout<<score<<":";
    for(j=0;j<c;j++)                                                                      //horizontal
    {
        int x1=0;
        for(i=0;i<r;i++)
        {
            if(arr[i][j]=='x')
            {
                if(arr[i-1][j]=='x')
                x1*=50;
                else
                x1++;
            }
            else
            {
                score+=x1;
                x1=0;
            }
        }
        if(x1!=0)
        score+=x1;
    }
    //cout<<score<<":";
    for(k=0;k<r;k++)
    {   
    for(l=0;l<c;l++)                                                                         //Diagonal 1
    {
        int x1=0;
        for(i=k,j=l;i<r,j<c;i++,j++)
            {   
                if(arr[i][j]=='x')
            {
                if(arr[i-1][j-1]=='x')
                x1*=50;
                else
                x1++;
            }
            else
            {
                score+=x1;
                x1=0;
            }
            }
        if(x1!=0)
        score+=x1;
    }
    for(l=c-1;l>=0;l--)                                                                       //Diagonal 2
    {
        int x1=0;
        for(i=k,j=l;i<r,j>=0;i++,j--)
            {   
                if(arr[i][j]=='x')
            {
                if(arr[i-1][j+1]=='x')
                x1*=50;
                else
                x1++;
            }
            else
            {
                score+=x1;
                x1=0;
            }
            }
        if(x1!=0)
        score+=x1;
    }
    } 
   // cout<<score<<":";
    // FOR THE NEGATIVE SCORE

    for(i=0;i<r;i++)
    {
        int x1=0;
        for(j=0;j<c;j++)                                                                  //vertical
        {
            if(arr[i][j]=='o')
            {
                if(arr[i][j-1]=='o')
                x1*=50;
                else
                x1++;
            }
            else
            {
                score1+=x1;
                x1=0;
            }
        }
        if(x1!=0)
        score1+=x1;
    }
   // cout<<endl<<score1<<":";
    for(j=0;j<c;j++)                                                                      //horizontal
    {
        int x1=0;
        for(i=0;i<r;i++)
        {
            if(arr[i][j]=='o')
            {
                if(arr[i-1][j]=='o')
                x1*=50;
                else
                x1++;
            }
            else
            {
                score1+=x1;
                x1=0;
            }
        }
        if(x1!=0)
        score1+=x1;
    }
    //cout<<score1<<":";
    for(k=0;k<r;k++)
    {   
    for(l=0;l<c;l++)                                                                         //Diagonal 1
    {
        int x1=0;
        for(i=k,j=l;i<r && j<c;i++,j++)
            {   
                if(arr[i][j]=='o')
            {
                if(arr[i-1][j-1]=='o')
                x1*=50;
                else
                x1++;
            }
            else
            {
                score1+=x1;
                x1=0;
            }
            }
        if(x1!=0)
        score1+=x1;
    }
    for(l=c-1;l>=0;l--)                                                                       //Diagonal 2
    {
        int x1=0;
        for(i=k,j=l;i<r && j>=0;i++,j--)
            {   
                if(arr[i][j]=='o')
            {
                if(arr[i-1][j+1]=='o')
                x1*=50;
                else
                x1++;
            }
            else
            {
                score1+=x1;
                x1=0;
            }
            }
        if(x1!=0)
        score1+=x1;
    }
    }
    //cout<<score1<<":";
    return (score-score1);                                                                            
}

int gameover()
{
    for(k=0;k<r;k++)
    {
        for(l=0;l<c;l++)                                                                       //Diagonal 1
        {
            int x1=0;
            for(i=k,j=l;i<r && j<c;i++,j++)
            {
                if(a[i][j]==a[i-1][j-1] && a[i][j]!='-')
                    x1++;
                else
                    x1=0;
                if(x1==3)
                    {
                        //cout<<i<<" "<<j<<"::";
                        if(a[i][j]=='x')
                        return 1;
                        else
                        return 2;
                    }
            }
        }
        //cout<<"test";
        for(l=c-1;l>=0;l--)                                                                     //Diagonal 2
        {
            int x1=0;
            for(i=k,j=l;i<r && j>=0;i++,j--)
            {
                if(a[i][j]==a[i-1][j+1] && a[i][j]!='-')
                    x1++;
                else
                    x1=0;
                if(x1==3)
                    {
                        if(a[i][j]=='x')
                        return 1;
                        else
                        return 2;
                    }
            }
        }
    }
    //cout<<"test";
    for(i=0;i<r;i++)
    {
        int x1=0;
        for(j=0;j<c;j++)                                                                  //vertical
        {
            if(a[i][j]==a[i][j-1] && a[i][j]!='-')
                x1++;
            else
                x1=0;
            if(x1==3)
                {
                        if(a[i][j]=='x')
                        return 1;
                        else
                        return 2;
                }  
        }
    }
    for(j=0;j<c;j++)                                                                      //horizontal
    {
        int x1=0;
        for(i=0;i<r;i++)
        {
            if(a[i][j]==a[i-1][j] && a[i][j]!='-')
                x1++;
            else
                x1=0;
            if(x1==3)
                {
                        if(a[i][j]=='x')
                        return 1;
                        else
                        return 2;
                }  
        }
    }
    return 0;
}

int main()
{
    cout<<"Welcome\n";
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            a[i][j]='-';
        }
    }
    int x,y,z;
    for(int i1=0;i1<42;i1++)
    {
        print();
        if(gameover())
        break;
        else
        {
            if(i1%2==0)
            {
                cout<<"Enter your move\n";
                cin>>x;
                while(update(a,'o',x))
                {
                    cout<<"Enter again \n";
                    cin>>x;
                }
            }
            else
            {
                for(i=0;i<r;i++)
                    {
                        for(j=0;j<c;j++)
                            {
                                b[i][j]=a[i][j];
                            }
                    }
                int x2=max(a,0);   
                //int x2=rand()%7;
                revert();
                update(a,'x',x2+1);
                //cout<<score(a)<<"::";
                cout<<x2+1<<endl;
            }
        }
    }
    switch(gameover())
    {
        case 0: cout<<"Tie \n";
        break;
        case 1: cout<<"AI \n";
        break;
        case 2: cout<<"Human \n";
        break;
    }
    getwchar();
    return 0;
}