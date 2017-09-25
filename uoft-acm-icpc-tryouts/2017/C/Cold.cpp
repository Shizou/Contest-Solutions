using namespace std;

int string_to_int(string s);
string int_to_string(int i);
vector<string>split(string s, char delim);
template< class T>
void print_vec(vector<T>vec, bool new_line=false);

int T;
int N,P,S;
map<char, int>dlls; // dll id, size of dll
map<int , pair<int, string>>prog; // prog id, size of prog, dlls req'd

int main() {
    needforspeed;
    while(cin >> N && N != 0){
        cin >> P >> S;
        if(db) trace3(N, P, S);
        for(int i = 0;i < N;i++){
            int a;
            char id = 'A'+i;
            cin >> a;
            dlls[id]=a;
            if(db)trace2(id, a)
        }
        for(int i = 1;i <= P;i++){
            int size;
            string labels;
            cin >> size >> labels;
            if(db) trace2(size, labels);
            prog[i] = mp(size, labels);
        }
        if(db)cout << endl;
        map< char, int >in_use_dlls; // dull id, references to it
        map< int,int >in_use_progs; // prog id, references to it
        int max_mem = 0;
        for(int i = 0;i < S;i++){
            int q;
            cin >> q;
            if(db) trace1(q); cout << endl;
            if(q > 0){
               in_use_progs[q]++;
               string dlls_req = prog[q].second;
               if(db)trace1(dlls_req); cout << endl;
               for(int j = 0;j < len(dlls_req);j++){
                   in_use_dlls[dlls_req[j]]++;
               }
            }else if (q < 0){
                q = -q;
                in_use_progs[q]--;
                string dlls_req = prog[q].second;
                for(int j = 0;j < len(dlls_req);j++){
                    in_use_dlls[dlls_req[j]]--;
                }
            }
            int cur_mem = 0;
            // dlls
            if(db) cout << "iter:" << i << endl;
            if(db)cout << "dlls: ";
            for(auto &it: in_use_dlls){
               if(db) cout << "(" << it.first << "," << it.second << ")" << " ";
               cur_mem += dlls[it.first] * (it.second > 0 ? 1:0);
            }
            if(db)cout << endl;
            // programs
            if(db)cout << "progs: ";
            for(auto &it: in_use_progs){
               if(db) cout << "(" << it.first << "," << it.second << ")" << " ";
               cur_mem += prog[it.first].first*it.second;
            }
            if(db)cout << endl;
            if(db)cout << cur_mem << endl;
            if(db)cout << endl;
            max_mem = max(max_mem, cur_mem);
        }
        cout << max_mem << endl;
    }
    return 0;
}

template< class T>
void print_vec(vector<T>vec, bool new_line){
    for(int i = 0;i < len(vec);i++){
        cout << vec[i] << ((new_line) ? '\n' : ' ');
    }
    cout << endl;
}

int string_to_int(string s){
    int ret;
    stringstream ss;
    ss << s;
    ss >> ret;
    return ret;
}

string int_to_string(int i){
    string ret;
    stringstream ss;
    ss << i;
    ss >> ret;
    return ret;
}

vector<string>split(string s, char delim){
    stringstream ss(s);
    vector<string>ret;
    string temp;
    while(getline(ss, temp, delim)){
        ret.push_back(temp);
    }
    return ret;
}
