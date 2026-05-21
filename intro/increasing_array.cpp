// misconception of the problem there is no pass
// we have to check many time due to the constraint of only 1 increament per pass
// we chnage the array on the run simple
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
	int n;
	vector<int> buffer;
//	pair<int> buffer;
//	deque<int> buffer[2];

	ll x, sum, a;
	sum = 0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		buffer.push_back(x);
	}
	for(int i=0;i<buffer.size()-1;i++){
		x = buffer[i];
		a = buffer[i+1];
		sum+=(x-a)*(x>a);
		buffer[i+1] = a + (x-a)*(x>a);
	}

	cout<<sum;

}
