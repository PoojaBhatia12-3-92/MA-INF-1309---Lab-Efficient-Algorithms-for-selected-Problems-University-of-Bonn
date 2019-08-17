#include <iostream>
#include <map> 
#include <vector>
#include <bits/stdc++.h>
#include <bitset>
using namespace std;



int main()
{

    int r;
    cin>>r;
    bitset<2000> arr[r];
    for ( int i=0; i<r; ++i)
    {
    cin>>arr[i];
    }
    
   
int bit=0;
unsigned long long count=0,val=0;
bitset<2000> a(0);
for (int i=0; i<r; ++i)
    {
        for (int j=i+1; j<r; ++j)
        { 
        
            a=(arr[i]&arr[j]);
            bit=a.count();
            if (bit>=2)
            {   
                val=(bit*(bit-1))/2;
                count+=val;
                
                
            }
        }
    }
cout<<count<<endl;
return 0;   
}    