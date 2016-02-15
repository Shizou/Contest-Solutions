#include<bits/stdc++.h>
#define len(x) (int)(x.size())
using namespace std;

string s;


bool monkey_word(string str)
{
   // this is the base case
   // A is always a monkey word
   if(len(str) == 1 && str[0] == 'A')
       return true;
   // if it's not this then it's not a monkey word
   else if(len(str) == 1)
       return false; 
   else
   {
        bool ret = true;
        // rule 2, B + monkey word + S
        if(str[0] == 'B' && str[len(str)-1] == 'S')
        {
            string monkey_str = str.substr(1, len(str)-2);
            if(len(monkey_str) >= 1)
                ret &= monkey_word(monkey_str);
            else
                ret &= false;
        }
        // a monkey word starting with B must always end with S
        else if(str [0] == 'B' && str[len(str)-1] != 'S')
        {
            ret &= false;
        }
        // rule 1, A + N + monkey word
        if(str[0] == 'A' && str[1] == 'N')
        {
            string monkey_str = str.substr(2, len(str)-2);
            ret &= monkey_word(monkey_str);
        }
        // rule 1, A + monkey word
        if(str[0] == 'A')
        {
            string monkey_str = str.substr(1,len(str)-1);
            ret &= monkey_word(monkey_str);
        }
        return ret;
   }
}

int main()
{
    
    while(cin >> s && s != "X")
    {
        if(monkey_word(s))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
