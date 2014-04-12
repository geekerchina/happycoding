#include <iostream>
#include <string>

using namespace std;
int main()
{
    string str;
    cin >> str;
    //map<char, int> hmap;
    int length = (int)str.size();
    int nl = 1, ll = 1, temp = 1;
    cout << length;
    int i;
    for(i = 0; i < length; i ++)
    {
        if(!(str[i] >= '0' && str[i] <= '9') && !(str[i] >= 'a' && str[i] <= 'z'))
        {
            cout << "<invalid input string>" << endl;
            return 0;
        }
    }
    sort(str.begin(),str.end());
    cout<<str<<endl;
    for(i = 1; i < length; i ++)
    {
        if(str[i] == str[i - 1])
        {
            temp += 1;
        }
        else
        {
            if(temp > ll)
            {
                ll = temp;
                
            }
            nl += 1;
            temp=1;
        }
    }
    cout<<"ll"<<ll<<endl;
    cout<<"nl"<<nl<<endl;
    cout<<"temp"<<temp<<endl;
    char* c_uni = (char *) malloc(sizeof(char) * nl);
    int* i_uni = (int *) malloc(sizeof(int) * nl);
    temp = 1;
    int j = 1;
    c_uni[0] = str[0];
    i_uni[0] = 1;
    for(i = 1; i < length; i ++)
    {
        if(str[i -1] == str[i])
        {
            temp += 1;
        }
        else
        {
            c_uni[j-1] = str[i-1];
            i_uni[j-1] = temp;
            j ++;
            cout<<"stri-1  "<<str[i-1];
            cout<<"temp "<<temp<<endl;
            temp=1;
            
        }
    }
    c_uni[nl-1] = str[length-1];
    i_uni[nl-1] = temp;
    cout<<"temp"<<temp<<endl;
    cout<<"nl"<<nl<<endl;
    cout<<"nl6"<<i_uni[nl-1]<<endl;

    for(j = 0; j < ll+1; j ++)
    {
        for(i = 0; i < nl; i ++)
        {
            if(i_uni[i] > 0)
            {
                cout << c_uni[i];
                i_uni[i] -= 1;
            }
        }
    }
    
    
}