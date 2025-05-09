#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& arr){
    for(int i=1; i<arr.size();i++){
        int tmp =arr.at(i);
        int j = i-1;
        while(j>=0 && tmp<arr.at(j)){
            arr.at(j+1)=arr.at(j);
            j--;
        }
        arr.at(j+1)=tmp;
    }
}
void merge(vector<int>& arr, int p, int q, int r){

    int n1 = q-p+1;
    int n2 = r-q;

    vector<int> tmp1, tmp2;
    int max = arr.at(0);

    for(int i=0; i<n1;i++){
        if(arr.at(p+i)>max){
            max= arr.at(p+i);
        }
        tmp1.push_back(arr.at(p+i));
    }
    for(int i=0; i<n2;i++){
        if(arr.at(q+i+1)>max){
            max = arr.at(q+i+1);
        }
        tmp2.push_back(arr.at(q+i+1));
    }
    tmp1.push_back(max+1);
    tmp2.push_back(max+2);

    int i=0, j=0;
    for(int k=p; k<=r;k++){
        if(tmp1.at(i)<=tmp2.at(j)){
            arr.at(k)= tmp1.at(i);
            i++;
        }else{
            arr.at(k)=tmp2.at(j);
            j++;
        }
    }

}
void mergeSort(vector<int>& arr, int p, int r){
    if(arr.size()>=5 && arr.size()<=25){
        insertionSort(arr);
    }else{
        if(p<r){
            int med = (p+r)/2, q = med;
            mergeSort(arr,p, med);
            mergeSort(arr,med+1,r);
            merge(arr,p,q,r);
        }
    }
}
/**
 * @brief Time Complexity : Θ(n log n)
 * 
 * @param nums 
 * @return vector<int> 
 */
vector<int> once_value(vector<int> nums){
    vector<int> res;
    mergeSort(nums, 0, nums.size()-1); // Θ(n log n)
    for(int i=0; i<nums.size();){ // Θ(n)
        int count=1;
        while(count+i < nums.size() && nums.at(i)== nums.at(i+count)){
            count++;
        }
        if(count==1){
            res.push_back(nums.at(i));
        }
        i += count;
    }
    return res;
}

int main(){
    vector<int> arr;
    int dim;
    cout<<"Dim: ";
    cin>>dim;
    for(int i=0;i<dim;i++){
        int tmp;
        cout<<"Elem "<<i+1<<" : ";
        cin>>tmp;
        arr.push_back(tmp);
    }
    vector<int> res= once_value(arr);
    for (size_t i = 0; i < res.size(); i++)
    {
        cout<<res.at(i)<<endl;
    }
    
    return 0;
}