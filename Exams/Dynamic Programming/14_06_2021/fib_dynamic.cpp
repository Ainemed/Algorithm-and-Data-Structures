#include <iostream>

using namespace std;

int fib_dynamic(int num){
    if(num==0 || num==1){
        return num;
    }
    int count=1, prec=1;
    for(int i=2; i<num;i++){
        int tmp=count;
        count += prec;
        prec = tmp;
    }
    return count;
}



int main(){

    int num;
    cout<<"Num: ";
    cin>>num;

    cout<<"Fib: "<<fib_dynamic(num)<<endl;

    return 0;
}