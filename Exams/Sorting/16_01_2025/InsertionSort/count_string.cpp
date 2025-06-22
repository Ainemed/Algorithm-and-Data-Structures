#include <iostream>
#include <vector>

using namespace std;

void countingSort(vector<pair<string,int>> arrA, vector<string>& arrB, int n, int k){
    arrB.resize(n);
    vector<int> arrC(k+1,0);
    for (int i = 0; i < n; i++)
    {
        arrC.at(arrA.at(i).second)++;
    }
    for(int i=k-1; i>=0; i--){
        arrC.at(i) +=arrC.at(i+1);
    }

    for(int j=0; j<n;j++){
        arrB.at(arrC.at(arrA.at(j).second)-1)=arrA.at(j).first;
        arrC.at(arrA.at(j).second)--;
    }
    
}

void riordina(vector<string>& arr){
    vector<pair<string,int>> sol;
    int k=0;
    for (int i = 0; i < arr.size(); i++)
    {
        int tmp1=0;
        for (int j = 1; j < arr.at(i).size(); j++)
        {
            int tmp2 = arr.at(i).at(j)-48;
            tmp1 *= 10;
            tmp1 +=tmp2;
        }
        pair<string,int> tmp3 = {arr.at(i),tmp1};
        sol.push_back(tmp3);
        k = max(tmp1,k);
    }
    vector<string> arrB;
    countingSort(sol, arrB, sol.size(),k);
    arr=arrB;
}


int main(){
    int dim;
    cout<<"Dim: ";
    cin>>dim;
    vector<string> arr;

    for (int i = 0; i < dim; i++)
    {
        string tmp;
        cout<<"Elem "<<i+1<<" : ";
        cin>>tmp;
        arr.push_back(tmp);
    }

    riordina(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr.at(i)<<endl;
    }
    
    
    
    
    



    return 0;
}