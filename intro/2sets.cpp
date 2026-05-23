// input is an integer output is YES or a  NO
#include<iostream>
#include<vector>
using namespace std;
using ll=long long;

int main(){
	// initialize long as we  have a squared term involved
	ll n, target;
	cin>>n;
	vector<int> a,b;

	//process
	// rejection is very esy when the sum is odd
	// may be no need to multiply but let it be
	if((n*(n+1)/2)%2){
		cout<<"NO";
	}
	// if divisible then clearly output the configuration
	else{
		cout<<"YES\n";
		target = n*(n+1)/4;
		// important this way we the soln is correct otherwise wrong if start from 0
		for(int i =n;i>0;i--){
			if(target>=i){
				a.push_back(i);
				target-=i;
			}
			else{
				b.push_back(i);
			}
		}

		cout<<a.size()<<endl;
		for(int i=0;i<a.size();i++){
			cout<<a[i]<<" ";
		}
		cout<<"\n";
		cout<<b.size()<<endl;
		for(int i=0;i<b.size();i++){
			cout<<b[i]<<" ";
		}

	}
}
