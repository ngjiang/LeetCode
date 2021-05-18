#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
	vector<int> twoSum(vector<int>& nums, int target){
		int i, j, n=nums.size();
		vector<int> indices;
		for(i=0; i<n-1; i++) for(j=i+1; j<n; j++)
			if(nums[i]+nums[j] == target)
				indices.push_back(i), indices.push_back(j);
		return indices;
	}
};


int main(){
	Solution solution;
	vector<int> nums, indices;
	int target;
	//nums.push_back(2), nums.push_back(7), nums.push_back(11), nums.push_back(15); 

	nums = {2,7,11,15};
	target = 9;
	indices = solution.twoSum(nums, target);
	for(int i=0; i<indices.size(); i++) cout<<indices[i]<< " "; cout<<endl;

	nums = {3,2,4};
	target = 6;
	indices = solution.twoSum(nums, target);
	for(int i=0; i<indices.size(); i++) cout<<indices[i]<< " "; cout<<endl;

	nums = {3,3};
	target = 6;
	indices = solution.twoSum(nums, target);
	for(int i=0; i<indices.size(); i++) cout<<indices[i]<< " "; cout<<endl;

	return 0;
}

