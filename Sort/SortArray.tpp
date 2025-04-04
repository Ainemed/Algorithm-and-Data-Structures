#include "SortArray.hpp"

//---------------------------------------------------------- STRUCT CREATION ------------------------------------------------------
template<typename T>
Sort<T>::Sort(vector<T> arr): arr(arr){}

template<typename T>
Sort<T>::Sort(){
    int dim;
    cout<<"Set the Size: ";
    cin>>dim;
    cout<<"---------------"<<endl;
    for (size_t i = 0; i < dim; i++)
    {
        T elem=0;
        cout<<"Elem "<<i+1<<" : ";
        cin>>elem;
        this->arr.push_back(elem);
        
    }
}


//---------------------------------------------------------- FUNCTIONS ------------------------------------------------------------

//---------------------------------------------------------- Print Sort ---------------------------------------------------------
template<typename T> 
void Sort<T>::printArr(){
    cout<<"----- Print Array -----"<<endl;
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout<<this->arr.at(i)<<endl;
    }
    
}