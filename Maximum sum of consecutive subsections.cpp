#include<iostream>
using namespace std;
int a[10001];
int main()
{
    int n,MAX=0;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
        {
            int m=0;
            for(int j=i;j<n;j++)
            {
                m+=a[j];
                if(m>=MAX)
                    MAX=m;
            }
        }
        cout<<MAX<<endl;
    }
    system("pause");
}
