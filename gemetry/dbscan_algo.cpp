// use of floor instead of simple division hence it is said dont use the simple thing of division
#include<bits/stdc++.h>
using ll=long long;
using namespace std;

struct point{
	ll x,y;
};

// writing for a custom class hashing -> hash is predefined here we just solve after that
// following is a functor or called a operator made a function 
struct pairhash{
	// size_t for hashes and gets the best datatype
	size_t operator()(const pair<ll,ll>& p) const{
		return hash<ll>()(p.first)^(hash<ll>()(p.second) << 16);
	}
	// why the fuck we do this hashing by xor of shift??
	// do this because <7,3> and <3,7> gives same answer!!
	// this just does x*prime number and the prime number is fixed
};

// just simple use so that 1,-1 dont get into same thing happens in c++
// in python it doesnt happen since // does the floor towards -inf
// in c++ the floor is towards 0 irrespective of any number hence floor used
ll flooring(ll x,ll r){return (ll)floor((double)x / r);}

// important to pass by reference!!
void query(pair<ll,ll> ref, pair<ll,ll> neighbour, ll r, vector<point>& finalanswer){
	if(pow(neighbour.x-ref.x,2) + pow(neighbour.y-ref.y,2) < pow(r,2)){
		finalanswer.push_back(neighbour);
	}
}

int main(){
	// initialize
	ll testset,x,y,r;
	unordered_map<pair<ll,ll>, vector<point>, pairhash> gridcell; // preprocessing
	vector<point> finalanswer;
	int nr[3] = {-1,0,1};
	int queries;
	// take input and store them
	cin>>testset>>r;

	for(ll i=0;i<testset;i++){
		cin>>x>>y;
		gridcell[{flooring(x,r),flooring(y,r)}].push_back({x,y});
	}

	cin>>queries;
	// algorithm starts for querying
	for(int i=0;i<queries;i++){
		cin>>x>>y;
		for(auto& nrx: nr){
			for(auto& nry: nr){
				for(auto& p: gridcell[{flooring(x,r)+nrx,flooring(y,r)+nry}]){
					query({x,y}, {p.x, p.y}, r, finalanswer);
				}
			}
		}
	}
	// we must return answer in int
	//return finalanswer;
	for(auto& p: finalanswer){
		cout<<p.x<<" "<<p.y<<"\n";
	}
}
