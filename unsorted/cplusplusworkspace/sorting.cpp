#include <iostream>
#include <algorithm>
using namespace std;
int N;
int a[10];
int main() {
	cin >> N;
	for(int i = 0; i < N;i++)
		cin >> a[i];
	sort(a,a+N);
	for(int i = 0; i < N;i++)
		cout << a[i] << " ";
	return 0;
}
