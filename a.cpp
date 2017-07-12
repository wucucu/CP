#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int first[n],second[n];
    int i,j,firstresult,secondresult;
    for(i=0;i<n;i++)
    {
        cin>>first[i];
        second[i] = first[i];
    }
    if(n==1)
        cout<<first[0];
    else if(n==2)
        cout<<min(first[0],first[1]);
    else
    {
        //first always selected
        first[1] += first[0];
        first[2] += first[0];
        for(i=3;i<n;i++)
        {
            first[i] += min(first[i-1],first[i-2]);
        }
        firstresult = min(first[n-1],first[n-2]);
        //last always selected
        second[0] += second[n-1];
        second[1] += second[n-1];
        for(i=2;i<n-1;i++)
        {
            second[i] += min(second[i-1],second[i-2]);
        }
        secondresult = min(second[n-2],second[n-3]);
 
        cout<<min(firstresult,secondresult);
    }
    return 0;
}
