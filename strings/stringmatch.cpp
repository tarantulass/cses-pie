#include<bits/stdc++.h>
using namespace std;

// 1. createlps array
// 2. we iterate on string and pattern with pointers initalized to 0 with a counter

void createlps(string& pattern, vector<int>& lps){
	int i=1;
	int j=0;
	while(i<pattern.size()){
		if(pattern[i]==pattern[j]){
			j+=1;
			lps[i] = j;
			i+=1;
		}
		else if(j>0){
			j = lps[j-1];
		}
		else{
			i+=1;
		}
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("error_strmatch.txt" , "w", stderr);
#endif
	// initialize
	string strsample, pattern;
	int i=0; //iterator for string sample
	int j=0;// iterator for pattern
	int count = 0;

	// take input and store check trivial cases
	cin>>strsample>>pattern;
	vector<int> lpsarray(pattern.size());// will it break when the strings are of longer lengths?
	if(pattern.size()>strsample.size()){
		cout<<0;
		return 0;
	}
	else if(pattern.size()==strsample.size()){
		cout<<(strsample==pattern);
		return 0;
	}

	// process
	createlps(pattern, lpsarray);
	while(i<strsample.size()){ // important for getting the count we dont add another conditon
		if(strsample[i]==pattern[j]){
			i+=1;
			j+=1;
		}
		else if(j>0){
			j = lpsarray[j-1]; /// gets to the last matched pattern
		}
		else{
			i+=1;
		}

		// very important moved at last  so that trailing ones are not ignored!!
		// if put at fornt may happen like jofwrjo and jo match are 2 but last is ignored!!
		if(j==pattern.size()){
			count+=1;
			j = lpsarray[j-1];
		}


	}
	cout<<count;
}

