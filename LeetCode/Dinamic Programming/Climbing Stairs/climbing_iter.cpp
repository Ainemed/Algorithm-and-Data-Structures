#include <iostream>

using namespace std;

int climbStairs(int n) {
    if(n==1 || n==2){
        return n;
    }
    int one = 2;
    int two = 1;
    for(int i=2;i<n;i++){
        int next = one + two;
        two = one;
        one = next;
    }
    return one;
}

int main(){

    

    return 0;
}