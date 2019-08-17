#include<bits/stdc++.h> 
using namespace std; 
#include <sstream>
#include <iostream>


int main() 
{ 

	char value, start, end;
	int countopen=0,countq=0,flag=1,rule=0;
	cin.get(start);

	if (start=='(') 
        
        { 
            
            countopen++;
            rule++;
            
            
        } 
        
    else if (start==')')
        {
            countopen--;
            
        }
        
    else if (start=='?')
        
        {
                
            countopen++;
            rule++;
                
        }
    
	do
    {
        cin.get(value);
        
        
        
        if (value=='(') 
        
        { 
            
            countopen++;
            rule++;
        } 
        
        
        
        if (value==')' && countopen>0)
        {
            countopen--;
            if (rule>0)
            {
                rule--;
            }
            
        }
        
        else if (value==')' && countopen==0 && countq>0)
        
        {
            countq--;
            if (rule>0)
            {
                rule--;
            }
            
        }
        
        else if (value==')' && countopen==0 && countq==0)
        
        {
            flag=0;
            if (rule>0)
            {
                rule--;
            }
            
        }
        
        
        
        if (value=='?')
        
        {
                
            countq++;
            if (rule>0)
            {
                rule--;
            }
                
        }
        
        
            
       if (value!='\n')
       {
           end=value;
           
       }
        
     
    }   while (value != '\n');
    
    
    if (start != ')' && end != '(' && countopen<=countq && ( (countopen % 2 ==0 && countq % 2==0) || (countopen % 2 !=0 && countq % 2 !=0) ) && flag==1 && rule==0)
    {
        
        
    
            std::cout << 1 << std::endl;
    
        
    }
    
    else
    {
       
        std::cout << 0 << std::endl;
    }
    
	return 0; 
} 
