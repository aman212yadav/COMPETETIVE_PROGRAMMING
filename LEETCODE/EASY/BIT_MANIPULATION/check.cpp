#include<bits/stdc++.h>
using namespace std;
void Remove(char *str)
{
    if(str[0]=='\0')
    {
        return;
    }
    if(str[0]==str[1])
    {
        int i=0;
        while(str[i]!='\0')
        {
            str[i] = str[i+1];
            i++;
        }
        Remove(str);
    }
    Remove(str+1);
}
int main() {
    char s[1000];
    cin>>s;
    Remove(s);
    cout<<s<<"\n";
	return 0;
}
