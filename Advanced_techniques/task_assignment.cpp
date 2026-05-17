// brute force is O(n!) but how do we get to the hungarian algorithm O(n^3)
// define the vector<vector<int>> as typedef thingwith some alias
#include<bits/stdc++.h>
using namespace std;

// doesnt return anything just changes inplace
void subtractrow_subroutine(vector<vector<int>>& costmatrix){
	for(int row=0;row<costmatrix.size();row++){
		// important only use of min_element gives an iterator
		int minval = *min_element(costmatrix[row].begin(), costmatrix[row].end());
		for(int col=0;col<costmatrix.size();col++){
			costmatrix[row][col] -= minval;
		}
	}
}

// cant use the min_elements thing now resort back to minval = min(minval, costmatrix[row][col])
void subtractcol_subroutine(vector<vector<int>>& costmatrix){
        for(int col=0;col<costmatrix.size();col++){
                // important only use of min_element gives an iterator
                int minval = INT_MAX;
		for(int row=0;row<costmatrix.size();row++){
                	minval = min(minval,costmatrix[row][col])
                }
		for(int row=0;row<costmatrix.size();row++){
			costmatrix[row][col] -= minval;
		}
        }
}

void dfs(){

}

bool isdfsfull(vector<vector<int>>& costmatrix){
	//wip
	int counter = 0;
	int nr[3] = {-1,0,1};
	vector<vector<bool>> visited;
	for(int row=0;row<costmatrix.size();row++){
		for(int col=0;col<costmatrix.size();col++){
			// 9 neighbours check
			visited[row][col] = true;
			if(costmatrix[row]][col]==0 && visited[row][col]){
				nrrow = nrr+row;
				nrcol = nrc+col;
				dfs();
			}

		}
	}
	return (counter==costmatrix.size());
}

vector<vector<int>> finalassignment(costmatrix){


}

int main(){
	// initialize
	int employees;
	vector<vector<int>> costmatrix, tasklist;
	vector<int> intermediate;

	// take input and store
	cin>>employees;
	for(int i=0;i<employees;i++){
		for(int i=0;i<employees;i++){
			cin>>x;
			intermediate.push_back(x);
		}
		costmatrix.push_back(intermediate);
	}

	// process and main algorithm
	subtractrow_subroutine(costmatrix);
	subtractcol_subroutine(costmatrix);

	// now we get independent zeros
	while(true){
		if(isdfsfull(costmatrix)){
			tasklist = finalassignment(costmatrix);
			break;
		}
	}
	cout<<;
	for(int i=0;i<employees;i++){
		cout<<;
	}

}
