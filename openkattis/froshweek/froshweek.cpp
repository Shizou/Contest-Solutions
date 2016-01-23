#include<bits/stdc++.h>
#define len(x) (int)(x).size()
#define MAXN 1000000
#define LL long long
#define DB 1

using namespace std;


int N;
int arr[MAXN];
int temp[MAXN];
LL cnt;

LL merge(int left,int mid,int right){
     int i = left;
     int j = mid+1;
     int index = left;
     LL ret = 0;
     while(i <= mid && j <= right){
         if(arr[i] < arr[j])
            temp[index++] = arr[i++];
         else{
            temp[index++] = arr[j++];
            ret += mid - i + 1;
         }
     }
    while(i <= mid)
          temp[index++] = arr[i++];
    while(j <= right)
          temp[index++] = arr[j++];
    for(int k = left;k <= right;k++)
        arr[k] = temp[k];
    return ret;
}

void merge_sort(int left,int right){
    if(left < right){
       int mid = (left+right)/2;
       merge_sort(left,mid);
       merge_sort(mid+1,right);
       cnt += merge(left,mid,right);
    }
}

int main(){
    #ifdef DBa
    freopen("input.txt","r",stdin);
    #endif
    cin >> N;
    for(int i = 0;i < N;i++){
        cin >> arr[i];
    }
    merge_sort(0,N-1);
    cout << cnt << endl;
    return 0;
}