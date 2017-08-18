#include<iostream>
#include<cstdio>
using namespace std;

/* This function calculates (a^b)%c */
long long modulo(long long a,long long  b, long long c) {
    // long long is taken to avoid overflow of intermediate results
    long long x=1,y=a;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y)%c;
        }
        y = (y*y)%c; // squaring the base
        b /= 2;
    }
    return x%c;
}

int n;

int main() {
	cin >> n;
	for(int i = 0;i < n;i++){
		long long prime;
        if(modulo(2, prime-1, prime*prime) == 1) {
			cout << "PRIME" << endl;
        }else {
			cout << "NOT" << endl;

		}
    }
    return 0;
}
