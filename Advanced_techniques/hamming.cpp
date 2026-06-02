// finding the best pair again
// but now we have bits only
// good news we cant do O(n^2.k) and there is no fancy algorithm here
// we can do at best O(n^2) hence we aim that now
#include<bits/stdc++.h>
using namespace std;

// function return the hammign distance simple
//int xorstring(string& a, string& b){
//	int setbits=0;
//	for(int i=0;i<a.size();i++){
//		setbits+=(a[i]!=b[i]);
//	}
//	return setbits;
//}

int main(){
#ifndef ONLINE_JUDGE
	freopen("error_hamming.txt","w", stderr);
#endif
	// initialize
	int testcases, length;
	int minval = INT_MAX;
	string s; // strings are given
	vector<int> storestring;
	// use of a set instead of vector for edge cases
//	set<int> storestring;

	// store input
	cin>>testcases>>length;
	for(int i=0;i<testcases;i++){
		cin>>s;
		storestring.push_back(stoi(s, nullptr, 2));
	}
	// what if all same?

	for(int i=0;i< testcases-1;i++){
		for(int j=i+1;j<testcases;j++){
			minval = min(minval, __builtin_popcount(storestring[i] ^ storestring[j]));
//			minval = min(minval,xorstring(storestring[i], storestring[j]);
		}
	}
	cout<<minval;
}
