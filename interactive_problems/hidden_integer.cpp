// in interactive problems use this endl !! or use cout.flush();
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	// initialize
	string s; // input from the grader
	ll mid, low, high;
	bool verdict;

	// take input and store/process
	// why low high otherwuse there is no way we are going to get the termination condition!!
	low = 0;
	high = 1e9;
	while(low<high){
		mid = low+(high-low)/2;
		cout<<"?"<<" "<<mid<<endl;// very important!!
		cin>>s;
		verdict = (s=="YES");
		if(verdict){
			low = mid+1;
		}
		else{
			high = mid;
// important the output is only y<x means it may happen y==x in that case we should not throw mid
// in binary search we did mid-1 as we had another check in there but now we only get yes or no
		}
	}
	cout<<"!"<<" "<<low;
// as here the code is saying that low== high otherwise it wont reach here!!
}
