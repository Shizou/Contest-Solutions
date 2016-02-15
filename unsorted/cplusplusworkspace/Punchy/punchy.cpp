#include<iostream>
#include<stdio.h>
using namespace std;
int a,b,v;
char cmd;
char c;
string s;
int main(){
    freopen("input.txt","r",stdin);
    while(true){
        cin >> cmd;
        cin.ignore();
        if(cmd == '7')
            break;
        else if(cmd == '6'){

        }
        else if(cmd == '5'){
            cin.ignore();
            scanf("%c", &c);
            if(c == 'A'){
                scanf("%c", &c);
                if(c == 'A')
                    a=0;
                else{
                    a-=b;
                }
            }
            else{
                scanf("%c", &c);
                if(c == 'B')
                    b=0;
                else{
                    b-=a;
                }
            }
        }
        else if(cmd == '4'){
           scanf("%c", &c);
            if(c == 'A'){
                scanf("%c", &c);
                if(c == 'A')
                    a*=a;
                else{
                    a*=b;
                }
            }
            else{
                scanf("%c", &c);
                if(c == 'B')
                    b*=b;
                else{
                    b*=a;
                }
            }
        }
        else if(cmd == '3'){
            scanf("%c", &c);
            if(c == 'A'){
                scanf("%c", &c);
                if(c == 'A')
                    a*=2;
                else{
                    a+=b;
                }
            }
            else{
                scanf("%c", &c);
                if(c == 'B')
                    b*=2;
                else{
                    b+=a;
                }
            }
        }
        else if(cmd == '2'){
            scanf("%c",&c);
            if(c == 'A')
                cout << a << endl;
            else
                cout << b << endl;
        }
        else{
            scanf("%c %d",&c,&v);
            if(c == 'A'){
                a = v;
            }
            else{
                b = v;
            }
           //cout << c << " " << v << endl;
        }

    }
    fclose(stdin);
    return 0;
}
