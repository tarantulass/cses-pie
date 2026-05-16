// in interactive problems use this endl !! or use cout.flush();
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	// initialize
	string s; // input from the grader
	ll mid, low, high;
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
			high = mid-1;
		}
	}
	cout<<"!"<<" "<<mid;
}
