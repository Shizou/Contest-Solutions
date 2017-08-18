#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <iterator>
#include <algorithm>
#define pb push_back
using namespace std;

int N;
double ans = 0x3f3f3f3f;
const double dps = 72.0/365.0*60.0;
vector<double>arr;

double dist(double d,double x){
	return min(abs(d-x),abs(360+d-x));
}

int main() {
    freopen("input.txt","r",stdin);
	cin >> N;
	for(int i = 0;i < N;i++){
		string A;double B;
		cin >> A >> B;
		arr.pb(B);
	}
	sort(arr.begin(),arr.end());
	for(double i = arr[0];i <= 360.0;i+=0.1){
		int pos  = 0;
		if(binary_search(arr.begin(),arr.end(),i))
			pos = distance(lower_bound(arr.begin(),arr.end(),i),arr.begin());
		else if(upper_bound(arr.begin(),arr.end(),i) == )

		else
			pos = distance(upper_bound(arr.begin(),arr.end(),i),arr.begin());
		cout << pos << endl;
		double d = dist(i,arr[pos]);
		for(int j = pos+1;j < N;j++)
			d+=dist(arr[j-1],arr[j]);
		if(pos != 0)
			for(int j = 0;j < pos;j++)
				d+=dist(arr[(j-1+N)%N],arr[j]);
		if(d < ans){
			ans = min(ans,d);
			printf("%.1f : %.2f\n",i,d);
		}
		break;
	}
	cout << ans <<endl;
	ans *=dps;
	cout << ans << endl;
	printf("%.0f",ans);
	return 0;
}
