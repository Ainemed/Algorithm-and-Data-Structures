#include <iostream>
#include <vector>

using namespace std;
/**
 * @brief Create a permutation of all the elements in the array, using the backtracking
 * 
 * @param res 
 * @param nums 
 * @param permutation 
 * @param used 
 */
void backtrack(vector<vector<int>>& res, vector<int>& nums, vector<int>& permutation, vector<bool>& used){
    if(permutation.size() == nums.size()){
        res.push_back(permutation);
    }
    for(int i=0; i<nums.size(); i++){
        if(!used.at(i)){
            used.at(i) = true;
            permutation.push_back(nums.at(i));
            backtrack(res,nums,permutation,used);
            used.at(i)=false;
            permutation.pop_back();
        }
    }
}
void backtrack2(vector<vector<int>>& res, vector<int>& nums, vector<int>& permutation, vector<bool>& used){
    if(permutation.size() == nums.size()){
        res.push_back(permutation);
    }
    for(int i=0; i<nums.size(); i++){
        permutation.push_back(nums.at(i));
        backtrack2(res,nums,permutation,used);
        permutation.pop_back();
    }
}
void backtrack_mod(vector<int>& res, vector<int>& nums, vector<int>& permutation, vector<bool>& used, int& count){
    if(permutation.size() == nums.size()){

        res.push_back(count++);
    }
    for(int i=0; i<nums.size(); i++){
        if(!used.at(i)){
            used.at(i) = true;
            permutation.push_back(nums.at(i));
            backtrack_mod(res,nums,permutation,used, count);
            used.at(i)=false;
            permutation.pop_back();
        }
    }
}

int countElem(int n, int one, int two){
    if(two+one<=n){
        int elemOne = countElem(n,one+1, two+2)+1;
        cout<<"One:  "<<one<<endl;
        cout<<"Two:  "<<two<<endl;
        
        return elemOne;
    }else{
        return 0;
    }
}

int main(){
    
    vector<vector<int>> res;
    vector<int> nums;
    vector<int> permutation;
    vector<bool> used;

    int dim;
    cout<<"Size: ";
    cin>>dim;

    for (size_t i = 0; i < dim; i++)
    {
        int tmp;
        cout<<"Elem "<<i+1<<" :";
        cin>>tmp;
        nums.push_back(tmp);
        used.push_back(false);
    }
    
    backtrack(res,nums,permutation,used);
    
    for (size_t i = 0; i < res.size(); i++)
    {
        cout<<"[";
        for(int j=0; j<res.at(i).size();j++){
            cout<<res.at(i).at(j)<<",";
        }
        cout<<"],"<<endl;
    }

    vector<int> sol;
    int count=0;
    backtrack_mod(sol,nums,permutation,used,count);

    for (size_t i = 0; i < sol.size(); i++)
    {
        cout<<sol.at(i)<<endl;
    }
    
    
    

    return 0;
}