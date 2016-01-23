#include <iostream>
using namespace std;

int a,b,c,t,t2;
int main() {
	t = 11*24*60 + 11*60 +11;
	cin >> a >> b >> c;
	t2 = a*24*60 + b*60 + c;
	if(t2 - t < 0)
		cout << "-1" << endl;
	else
		cout << t2-t << endl;
	return 0;
}
