#include<iostream>
#include<vector>
using namespace std;
vector<int> nums;
int cnt;
int main(){
    int n,k; cin >> n >> k;

    for(int i = 2;i <= n;i++)
        nums.push_back(i);

    n = nums.size();
    for(int i = 0;i < n && cnt < k;i++){

        if(nums[i] != 0 ){
            cnt++;
            if(cnt == k){
                cout << nums[i] << endl;
                break;
            }
            for(int j = i+1;j < n && cnt < k;j++){
                if(nums[j]%nums[i] == 0){
                    cnt++;
                    if(cnt == k){
                        cout << nums[j] << endl;
                        break;
                    }
                    nums[j] = 0;
                }
            }
            nums[i] = 0;
        }

    }

    return 0;
}
