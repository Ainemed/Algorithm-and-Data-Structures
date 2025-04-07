#include <iostream>
#include <vector>

using namespace std;
/**
 * @brief Create a combination of all the elements in the given range, using the backtracking
 * 
 * @param res 
 * @param nums 
 * @param permutation 
 * @param used 
 */
void backtrack_comb(vector<vector<int>>& res, vector<int>& combination, int k, int n, int start){
    if(combination.size()==k){
        res.push_back(combination);
    }
    for(int i=start; i<=n; i++){
        combination.push_back(i);
        backtrack_comb(res,combination,k,n,start+1);
        combination.pop_back();
        
    }
}
void backtrack_comb_arr(vector<vector<int>>& res, vector<int>& combination, vector<int>& nums, int k, int start){
    if(combination.size()==k){
        res.push_back(combination);
    }
    for(int i=start; i<nums.size(); i++){
        combination.push_back(nums.at(i));
        backtrack_comb_arr(res,combination,nums,k,i+1);
        combination.pop_back();
    }
}

int main(){
    
    vector<vector<int>> res;
    vector<int> combination;
    vector<int> nums;

    int n,k;
    cout<<"Write the n: ";
    cin>>n;
    cout<<"Write the k: ";
    cin>>k;

    
    //backtrack_comb(res,combination,k,n,1);

    for (size_t i = 0; i < n; i++)
    {
        int tmp;
        cout<<"Elem "<<i+1<<" :";
        cin>>tmp;
        nums.push_back(tmp);
    }

    backtrack_comb_arr(res, combination, nums, k,0);

    for (size_t i = 0; i < res.size(); i++)
    {
        cout<<"[";
        for(int j=0; j<res.at(i).size();j++){
            cout<<res.at(i).at(j)<<",";
        }
        cout<<"],"<<endl;
    }    
    

    return 0;
}