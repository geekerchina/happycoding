#include <iostream>
#include <string>
#include <list>

using namespace std;

int main(int argc, char const *argv[])
{
    string str;
    string temp;
    string ans;
    int ansi,ansj;
    string * split;
    int pos=0;
    int num=1;
    list<int> L;

    getline(cin,str);
//    cin>>str;
    while(!str.empty())
    {
        //start compute answer
        num=1;
        temp = str;
        while((pos = temp.find(",")) != string::npos)
        {
            //cout << temp.substr(0,pos) << endl;
            temp.erase(0,pos+1);
            num+=1;
        }
        //cout << temp << endl;
        //cout << num << endl;
        int * input = new int[num];

        temp = str;
        num=1;
        while((pos = temp.find(",")) != string::npos)
        {
            //cout << temp.substr(0,pos) << endl;
            input[num-1]=stoi(temp.substr(0,pos));
            temp.erase(0,pos+1);
            num+=1;
        }
        //cout << temp << endl;
        input[num-1] = stoi(temp);
        //output for test
        for (int i = 0; i < num; ++i)
        {
            //cout<<" "<<input[i];
        }
        int max=0;int tempmax=0;
        for (int i = 0; i < num-1; ++i)
        {
            for (int j = i+1; j < num; ++j)
            {
                tempmax = 0;
                if (input[i]<=input[j])
                {
                    break;
                }
                for (int k = i+1; k < j; ++k)
                {
                    if (input[k] >= input[j])
                    {
                        tempmax++;
                    }
                    if (input[k] <= input[i])
                    {
                        tempmax++;
                    }
                }
                if (tempmax > max)
                {
                    max=tempmax;ansi=i;ansj=j;
                }
            }
        }
        //cout<<"max_increase:"<<max<<"Method:swap "<<input[ansi]<<" and "<<input[ansj]<<endl;
        L.push_back(max);
        getline(cin,str);
        
    }
    list<int>::iterator i;

    for(i=L.begin(); i != L.end(); ++i) 
    {
        cout << *i << endl;
    }
    return 0;
}