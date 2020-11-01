#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the solve function below.

// solve this using two stacks to find the maximum on each corresponding side.
long long solve(vector<int> arr) {
    int N = arr.size();
    stack< pair<int, int> > s;
    vector<long long> lt(N), rt(N);
    // compute left side
    s.push(make_pair(arr[0], 1));
    for(int i = 1;i < arr.size();i++){
        while(!s.empty() && s.top().first <= arr[i]) s.pop();
        if(!s.empty()) lt[i] = s.top().second;
        s.push(make_pair(arr[i], i+1));
    }
    while(!s.empty())s.pop(); // clear the stack
    // compute right side
    s.push(make_pair(arr[N-1], N));
    for(int i = N-2; i >= 0;i--) {
        while(!s.empty() && s.top().first <= arr[i]) s.pop();
        if(!s.empty()) rt[i] = s.top().second;
        s.push(make_pair(arr[i],i+1));
    }
    long long ans = 0;
    for(int i = 0;i < arr.size();i++) {
        ans = max(ans, lt[i]*rt[i]);
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int arr_count;
    cin >> arr_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(arr_count);

    for (int arr_itr = 0; arr_itr < arr_count; arr_itr++) {
        int arr_item = stoi(arr_temp[arr_itr]);

        arr[arr_itr] = arr_item;
    }

    long long result = solve(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

