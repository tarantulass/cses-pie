#include<iostream>
using namespace std;

int binsearch(vector<int>& truth, target){
	int low=0, high= truth.size();
	while(low<=high){
		mid = low + (high-low)/2;
		if(truth[mid]==target){
			;
		}
	}
}

int main(){
	// initialize
	int n,m,k,x, count;
	vector<int> truth, desire, vis;
	cin>>n>>m>>k;

	// store input
	for(int i=0;i<n;i++){
		cin>>x;
		desire.push_back(x);
	}

	for(int i=0;i<m;i++){
		cin>>x;
		truth.push_back(x);
	}

	// process
	/*
	1. sort the truth array
	2. search by binary search get the closest element and maintain a visited array
	3. search -> linear till more than k--> may have issue not good !!
	*/
	// instead we as of now only have 1 visited array
	sort(truth.begin, truth.end());
	for(int i = 0;i<n;i++){
		x=binsearch(truth, desire[i]);
		if((x-desire[i])*(1-2*(x<desire[i])) <= k){ // basically took the absolue value
			count++;
		}
	}
	cout<<count;
}
