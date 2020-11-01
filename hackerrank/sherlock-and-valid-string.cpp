#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string str) {
    map<char, int>m;
    map<int, string> revm;
    for(int i = 0;i < str.size();i++) {
        m[str[i]]++;
    }
    for(const auto &it: m) {
        char letter = it.first;
        int occ = it.second;
        revm[occ] += letter;
    }
    if(revm.size() == 1){
        return "YES";
    } else if(revm.size() == 2){ 
        vector< pair<int,string> > revm_conv(revm.begin(), revm.end());
        // make sure frequencies only differ by 1 for letters
        // to satify that only 1 character can be changed
        if(abs(revm_conv[0].first - revm_conv[1].first) == 1) {
            // if either of them contains at most 1 character we can append it to the other group
            if(revm_conv[1].second.size() == 1 
                || revm_conv[0].second.size() == 1) {
                return "YES";
            } 
        } 
        // edge cases like aaabccc where one cahracter can be deleted
        else if(revm_conv[0].second.size() == 1 && revm_conv[0].first == 1){
            return "YES";
        }else if(revm_conv[1].second.size() == 1 && revm_conv[1].first == 1){
            return "YES";
        }
    }  
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

