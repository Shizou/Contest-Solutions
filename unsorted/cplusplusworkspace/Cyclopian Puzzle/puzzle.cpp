#include<iostream>
#include<fstream>
#include<stack>
using namespace std;
int n,t,m=1;
stack<int> a,b,c;

void atob(){
     if(!a.empty() && (b.empty() || a.top() < b.top() ) ){
        cout << "AB" << endl;
        b.push(a.top());
        a.pop();
     }
     else if(!b.empty() && (a.empty() || b.top() < a.top() ) ){
        cout << "BA" << endl;
        a.push(b.top());
        b.pop();
     }m++;
}
void atoc(){
    if(!a.empty() && (c.empty() || a.top() < c.top() ) ){
        cout << "AC" << endl;
        c.push(a.top());
        a.pop();
    }
    else if(!c.empty() && (a.empty() || c.top() < a.top() ) ){
        cout << "CA" << endl;
        a.push(c.top());
        c.pop();
    }m++;
}
void btoc(){
     if(!b.empty() && (c.empty() || b.top() < c.top() ) ){
        cout << "BC" << endl;
        c.push(b.top());
        b.pop();
    }
    else if(!c.empty() && (b.empty() || c.top() < b.top() ) ){
        cout << "CB" << endl;
        b.push(c.top());
        c.pop();
    }m = 1;
}
int main(){
    cin >> n;
    t = n+1;
    while(--t)a.push(t);
    if(n%2 == 0){
        while(c.size() != n){
                if(m == 1) atob();
                else if(m == 2) atoc();
                else if(m == 3) btoc();
        }
    }
    else{
        while(c.size() != n){
                if(m == 1) atoc();
                else if(m == 2) atob();
                else if(m == 3) btoc();
        }

    }
   return 0;
}
