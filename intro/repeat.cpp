#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	int maxval = 1;
	cin>>s;
	int left, right;
	left = 0;
	right = 1;

	while(right<s.size()){
		if(s[left]==s[right]){
			maxval = max(maxval, right-left+1);
			right+=1;
		}
		else{
			left=right;
			right+=1;
		}
	}
	cout<<maxval;
}
