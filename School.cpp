/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <chrono>
using namespace std::chrono;
#include <set>
using namespace std;
const int MAX_CHAR = 26; 

string sortString(string &str) 
{ 
  
    string result;
    int charCount[MAX_CHAR] = {0}; 
      

    for (int i=0; i<str.length(); i++) 
  
       
        charCount[str[i]-'a']++;     
      
     
    for (int i=0;i<MAX_CHAR;i++) 
        for (int j=0;j<charCount[i];j++) 
               result+=(char)('a'+i);
          
            

    return result;
} 

int main()
{
  
   int line1;
    cin >> line1 ;
    set <string> result;
    for (int i = 0; i < line1; i++)
    {
        string ip;
        cin >> ip;
        ip=sortString(ip);
        result.insert(ip);
    }

    cout<<result.size()<<endl;
    return 0;
}
