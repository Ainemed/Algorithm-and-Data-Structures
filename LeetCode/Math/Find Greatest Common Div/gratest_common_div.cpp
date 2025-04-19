#include <iostream>

using namespace std;

int findGCD(vector<int>& nums) {
    int min=nums.at(0);
    int max=nums.at(0);
    for(int i=1;i<nums.size();i++){
        if(min>nums.at(i)){
            min = nums.at(i);
        }
        if(max<nums.at(i)){
            max=nums.at(i);
        }
    }
    int div=1;
    for(int i=1;i<=min;i++){
        if(min%i==0 && max%i==0 && i>div){
            div=i;
        }
    }
    cout<<min<<' '<<max;
    return div;
}

int main(){
    return 0;
}