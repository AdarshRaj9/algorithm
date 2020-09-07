#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int reset[MAX];
void kmp_helper(string pattern)
{
    int n=pattern.size();
    reset[0]=-1;
    int i=0,j=-1;
    while(i<n)
    {
        while(j>=0 and pattern[i]!=pattern[j])
        {
            j=reset[j];
        }
        j++;i++;
        reset[i]=j;
    }
}
void kmp_search(string text,string pattern)
{
    kmp_helper(pattern);
    int i=0,j=-1;
    while(i<text.size())

    {
        while(j>=0 and text[i]!=pattern[j])
        {
            j=reset[j];
        }
        i++;j++;
        if(j==pattern.size())
        {
            cout<<"Pattern is found at:"<<i-j<<"\n";
            j=reset[j];
        }
    }

}
int main()
{
    string text,pattern;
    cin>>text>>pattern;
    kmp_search(text,pattern);
    return 0;
}