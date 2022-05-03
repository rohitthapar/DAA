#include<iostream>
#include<string>

using namespace std;

int LCS(string s1, string s2, int arr[100][100])
{
    int n1=s1.length();
    int n2=s2.length();
    for(int i=0;i<=n1;i++)
    {
        for(int j=0;j<=n2;j++)
        {
            if(i==0 || j==0)
            {
                arr[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1])
            {
                arr[i][j]=arr[i-1][j-1]+1;
            }
            else
            {
                arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
            }
        }
    }
    return arr[n1][n2];
}
void reverse(string str)
{
   for (int i=str.length()-1; i>=0; i--)
      cout << str[i]; 
}
string backtrack(int arr[100][100], string s1, string s2)
{
    string s="";
    int n1=s1.length();
    int n2=s2.length();
    int i=n1;
    int j=n2;
    while(i>0 && j>0)
    {
        if(arr[i][j]==arr[i-1][j-1]+1)
        {
            s=s+s1[i-1];
            i--;
            j--;
        }
        else if(arr[i][j]==arr[i-1][j])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    return s;
}
string backtrack2(int arr[100][100], string s1, string s2)
{
    string s="";
    int n1=s1.length();
    int n2=s2.length();
    int i=n1;
    int j=n2;
    while(i>0 && j>0)
    {
        if(arr[i][j]==arr[i-1][j-1]+1)
        {
            s=s+s1[i-1];
            i--;
            j--;
        }
        else if(arr[i][j]==arr[i-1][j])
        {
            j--;
        }
        else
        {
            i--;
        }
    }
    return s;
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int arr[100][100];
    cout<<"length of substring: "<<LCS(s1,s2,arr)<<endl;
    string result=backtrack(arr,s1,s2);
    cout<<"substring1:";
    reverse(result);
    cout<<endl;
    result=backtrack2(arr,s1,s2);
    cout<<"substring2:";
    reverse(result);
    return 0;
}