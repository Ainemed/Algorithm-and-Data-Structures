#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int p, int q, int r){
    int n1 = q-p+1;
    int n2 = r-q;

    vector<int> tmp1, tmp2;

    int min = arr.at(0);

    for(int i=0; i<n1; i++){
        if(arr.at(p+i)<min){
            min = arr.at(p+i);
        }
        tmp1.push_back(arr.at(p+i));
    }

    for(int i=0; i<n2; i++){
        if(arr.at(q+i+1)<min){
            min = arr.at(q+i+1);
        }
        tmp2.push_back(arr.at(q+i+1));
    }

    tmp1.push_back(min-1);
    tmp2.push_back(min-1);

    int i=0, j=0;

    for(int k=p; k<=r; k++){
        if(tmp1.at(i)>=tmp2.at(j)){
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

void insertionSort(vector<int>& arr){
    for(int i=1; i<arr.size();i++){
        int tmp = arr.at(i);
        int j = i-1;
        while(j>=0 && tmp <arr.at(j)){
            arr.at(j+1) = arr.at(j);
            j--;
        }
        arr.at(j+1) = tmp;
    }
}



int minMovesToSeat(vector<int>& seats, vector<int>& students) {
    if(seats.size()>=5 && seats.size()<=25){
        
        insertionSort(seats);
        insertionSort(students);
        
    }else{
        mergeSort(seats, 0, seats.size()-1);
        mergeSort(students, 0, students.size()-1);
    }
        

    int move = 0;
    for(int i=0; i<seats.size();i++){
        move += abs(seats.at(i)- students.at(i));
    }
    return move;

}
int main(){
    
    return 0;
}
