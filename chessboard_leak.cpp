#include <iostream>
#include <string>
//author liuhm09 2014/04/19/00:39:14
using namespace std;
int main(int argc, char const *argv[])
{
    //generate a matrix////////////////////////////////
    int n=5;
    int m=5;
    int mn[12][12];
    int water[12][12];
    int flagflag[12][12];
    //init the mn and flagflag////////////////////////////////
    for (int i = 0; i <= n+1; ++i)
    {
        for (int j = 0; j <= m+1; ++j)
        {
            mn[i][j]=0;
            flagflag[i][j]=1;
        }
    }
    for(int i = 1;i<=n;i++)
    {
        for(int j =1;j<=m;j++)
        {
            mn[i][j] = rand() %6 + 1;
            flagflag[i][j]=0;
        }
    }
    //compute the max height//////////////////////////////////
    int max =0;
    for(int i = 0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            if (mn[i][j]>max)
            {
                max=mn[i][j];
            }
        }
    }
    cout<<"max: "<<max<<endl;

    //init the water to max height////////////////////////////////
    for (int i = 0; i <=n+1; ++i)
    {
        for (int j= 0; j <= m+1; ++j)
        {
            water[i][j]=0;
        }
    }
    for(int i = 1;i<=n;i++)
    {
        for(int j =1;j<=m;j++)
        {
            water[i][j]=max;
            if (max==mn[i][j])
            {
                flagflag[i][j]=1;
            }
        }
    }

    //start the compute////////////////////////////////

    int temp=0;
    int count=0;
    int ans =max*n*m;
    int flag=ans+1;
    int flagc=ans+1;

    while(flag)
    {
        flag=0;
        for (int i = 1; i <=n; ++i)
        {
            for (int j=1; j <= m; ++j)
            {
                if ((water[i][j]>mn[i][j])&&(flagflag[i][j]==0))
                {
                    if (water[i-1][j]<water[i][j])
                    {
                        water[i][j]=((water[i-1][j]>mn[i][j])?water[i-1][j]:mn[i][j]);
                        if(water[i][j]==mn[i][j]) flagflag[i][j]=1;flag=1;
                    }
                    if (water[i+1][j]<water[i][j])
                    {
                        water[i][j]=((water[i+1][j]>mn[i][j])?water[i+1][j]:mn[i][j]);
                        if(water[i][j]==mn[i][j]) flagflag[i][j]=1;flag=1;
                    }
                    if (water[i][j-1]<water[i][j])
                    {
                        water[i][j]=((water[i][j-1]>mn[i][j])?water[i][j-1]:mn[i][j]);
                        if(water[i][j]==mn[i][j]) flagflag[i][j]=1;flag=1;
                    }
                    if (water[i][j+1]<water[i][j])
                    {
                        water[i][j]=((water[i][j+1]>mn[i][j])?water[i][j+1]:mn[i][j]);
                        if(water[i][j]==mn[i][j]) flagflag[i][j]=1;flag=1;
                    }
                }
            }
        }
    }

    ans=0;
    cout<<"show the final:"<<endl;
    for (int i = 0; i <=n+1; ++i)
    {
        for (int j= 0; j <= m+1; ++j)
        {
            if (flagflag[i][j]==0)
            {
                cout<<water[i][j]<<"("<<mn[i][j]<<")"<<"\t";
            }
            else
            {
                cout<<water[i][j]<<"\t";
            }
            
        }
        cout<<endl;
    }
    cout<<"final ans is:  "<<ans<<endl;
    return 0;
}
