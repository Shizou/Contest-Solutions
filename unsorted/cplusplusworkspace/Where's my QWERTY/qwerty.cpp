#include<iostream>
using namespace std;
string s,s2;
int main(){
    getline(cin,s);

    for(int i = 0;i < s.size();i++){
        if(s[i] == '\"')//d
            s2+="Q";
        else if(s[i] == '\'')
            s2+="q";
        else if(s[i] == '<')
            s2+="W";
        else if(s[i] == ',')
            s2+="w";
        else if(s[i] == '>')
            s2+="E";
        else if(s[i] == '.')
            s2+="e";
        else if(s[i] == 'P')
            s2+="R";
        else if(s[i] == 'p')
            s2+="r";
        else if(s[i] == 'Y')
            s2+="T";
        else if(s[i] == 'y')
            s2+="t";
        else if(s[i] == 'F')
            s2+="Y";
        else if(s[i] == 'f')
            s2+="y";
        else if(s[i] == 'G')
            s2+="U";
        else if(s[i] == 'g')
            s2+="u";
        else if(s[i] == 'C')
            s2+="I";
        else if(s[i] == 'c')
            s2+="i";
        else if(s[i] == 'R')
            s2+="O";
        else if(s[i] == 'r')
            s2+="o";
        else if(s[i] == 'L')
            s2+="P";
        else if(s[i] == 'l')
            s2+="p";
        else if(s[i] == '?')
            s2+="{";
        else if(s[i] == '/')
            s2+="[";
        else if(s[i] == '+')
            s2+="}";
        else if(s[i] == '=')
            s2+="]";
        else if(s[i] == 'O')
            s2+="S";
        else if(s[i] == 'o')
            s2+="s";
        else if(s[i] == 'E')
            s2+="D";
        else if(s[i] == 'e')
            s2+="d";
        else if(s[i] == 'U')
            s2+="F";
        else if(s[i] == 'u')
            s2+="f";
        else if(s[i] == 'I')
            s2+="G";
        else if(s[i] == 'i')
            s2+="g";
        else if(s[i] == 'D')
            s2+="H";
        else if(s[i] == 'd')
            s2+="h";
        else if(s[i] == 'H')
            s2+="J";
        else if(s[i] == 'h')
            s2+="j";
        else if(s[i] == 'T')
            s2+="K";
        else if(s[i] == 't')
            s2+="k";
        else if(s[i] == 'N')
            s2+="L";
        else if(s[i] == 'n')
            s2+="l";
        else if(s[i] == 'S')
            s2+=":";
        else if(s[i] == 's')
            s2+=";";
        else if(s[i] == '_')
            s2+="\"";
        else if(s[i] == '-')
            s2+="\'";
        else if(s[i] == ':')
            s2+="Z";
        else if(s[i] == ';')
            s2+="z";
        else if(s[i] == 'Q')
            s2+="X";
        else if(s[i] == 'q')
            s2+="x";
        else if(s[i] == 'J')
            s2+="C";
        else if(s[i] == 'j')
            s2+="c";
        else if(s[i] == 'K')
            s2+="V";
        else if(s[i] == 'k')
            s2+="v";
        else if(s[i] == 'X')
            s2+="B";
        else if(s[i] == 'x')
            s2+="b";
        else if(s[i] == 'B')
            s2+="N";
        else if(s[i] == 'b')
            s2+="n";
        else if(s[i] == 'W')
            s2+="<";
        else if(s[i] == 'w')
            s2+=",";
        else if(s[i] == 'V')
            s2+=">";
        else if(s[i] == 'v')
            s2+=".";
        else if(s[i] == 'Z')
            s2+="?";
        else if(s[i] == 'z')
            s2+="/";
        else if(s[i] == '{')
            s2+="_";
        else if(s[i] == '[')
            s2+="-";
        else if(s[i] == '}')
            s2+="+";
        else if(s[i] == ']')
            s2+="=";
        else
            s2+=s[i];

    }
    cout << s2 << endl;
}
