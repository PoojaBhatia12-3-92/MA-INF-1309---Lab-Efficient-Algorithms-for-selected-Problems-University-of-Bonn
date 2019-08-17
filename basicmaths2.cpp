#include <iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

void check(unsigned long long u,unsigned long long v,unsigned long long w)
{
    unsigned long long root1,root2,root3,b,c,bpower2,d=0;
    unsigned long long range = sqrt(w);
    bool checkfac=false;
    int a=1;
    vector<unsigned long long> val;
    for(unsigned long long i= 1 ;i<ceil(range);i++){
        if(v % i == 0){
            root1 = i;
            b = u - root1;
            bpower2=pow(b,2);
            c= v / i;
        }
        if( bpower2>4*a*c && ((bpower2- 2 * c) + pow(root1,2)) == w )
        {
            checkfac=true;
            d=b*b - 4*a*c;
            root2 = (b  + sqrt(d))/(2*a);
            root3 =  (b - sqrt(d))/(2*a);
            break;
        }
    }
 
 val.insert(val.end(),root1);
 val.insert(val.end(),root2);
 val.insert(val.end(),root3);
 sort(val.begin(),val.end());
if(checkfac==true && root1!=root2 && root1!=root3)
    {
     cout<<val[0]<<" "<<val[1]<<" "<<val[2];
     cout<<endl;
    }
else
     cout<<"empty set"<<endl;
}


int main()
{
    unsigned long long n;
    cin>>n;
    for(unsigned long long i=0;i<n;i++)
    {
        unsigned long long u,v,w;
        cin>>u>>v>>w;
        check(u,v,w);
    }
}


