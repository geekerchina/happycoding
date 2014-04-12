#include <iostream>
#include <string>

using namespace std;
int fac(int n)
{
    int ans=1;
    for (int i = 1; i <=  n; ++i)
    {
        ans = ans * i;
    }
    return ans;
}
int c(int a,int b)
{
    return fac(a)/fac(b)/fac(a-b);
}
int g(int a,int b,int k)
{
    if (c(a,b)>=k)
    {
        cout<<0;
        return 0;
    }
    cout<<1;
    return 1;
}
int main()
{
    int count;
    int n,m,k;
    cin >> count;
    int **t=new int*[count];
    for (int i = 0; i < count; ++i)
    {
        t[i]=new int[3];
        cin >> t[i][0]>>t[i][1]>>t[i][2];
    }
    for (int i = 0; i < count; ++i)
    {
        //cout<<t[i][0]<<t[i][1]<<t[i][2]<<endl;
        n=t[i][0];m=t[i][1];k=t[i][2];
        if (c(n+m,n)<k)
        {
            cout<<"Impossible";
            return 0;
        }
        else
        {
            //cout<<"let's start compute"<<endl;
            int sum0=0,sum1=0;
            int temp=k;
            for (int i = 0; i < n+m-1; ++i)
            {
                if (g(m+n-1-i,n-1-sum0,temp)==0)
                {
                    sum0++;
                }
                else
                {
                    temp=temp-c(m+n-1-i,n-1-sum0);
                    sum1++;
                }
            }
            if (n==sum0)
            {
                cout<<1<<endl;
            }
            else
            {
                cout<<0<<endl;
            }
        }
    }
    return 0;
}