#include <iostream>
#include <vector>

using namespace std;



void merge(vector<int>& arr, int p, int q, int r){
    int n1 = q-p+1;
    int n2 = r-q;

    vector<int> tmp1, tmp2;
    int max = arr.at(0);

    for(int i=0; i<n1; i++){
        if(arr.at(p+i)>max){
            max = arr.at(p+i);
        }
        tmp1.push_back(arr.at(p+i));
    }

    for(int i=0; i<n2; i++){
        if(arr.at(q+i+1)>max){
            max = arr.at(q+i+1);
        }
        tmp2.push_back(arr.at(q+i+1));
    }
    tmp1.push_back(max+1);
    tmp2.push_back(max+2);

    int i=0, j=0;
    for(int k=p; k<=r; k++){
        if(tmp1.at(i)<=tmp2.at(j)){
            arr.at(k)=tmp1.at(i);
            i++;
        }else{
            arr.at(k)=tmp2.at(j);
            j++;
        }
    }
}

void mergeSort(vector<int>& arr, int p, int r){
    if(p<r){
        int med = (p+r)/2, q = med;
        mergeSort(arr, p, med);
        mergeSort(arr, med+1, r);
        merge(arr, p, q, r);
    }
}

int minimumDifference(vector<int>& nums, int k) {
    if(nums.size()==1){
        return 0;
    }else{
        mergeSort(nums, 0,nums.size()-1);
        int min = nums.at(nums.size()-1)-nums.at(nums.size()-k);
        int i=0;
        while((nums.size()-k-i)>0){
            int tmp = nums.at(nums.size()-1-i)-nums.at(nums.size()-k-i);
            cout<<nums.at(nums.size()-1-i)<<endl;
            if(tmp<min){
                min = tmp;
            }
            i++;
        }
        int tmp = nums.at(nums.size()-1-i)-nums.at(nums.size()-k-i);
        if(tmp<min){
                min = tmp;
            }
        return min;
    }

}

int main(){
    

    return 0;
}