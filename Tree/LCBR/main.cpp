#include "LCBR.hpp"

int main(){
    Node<char> elem1('A'), elem2('L'), elem3('B'), elem4('E'), elem5('R'), elem6('O');
    Tree<char> tree(&elem1);

    elem1.left_child=&elem2;
    
    elem2.p=&elem1;
    elem2.left_child=&elem4;
    elem2.right_sib=&elem3;

    elem3.left_child=&elem6;

    elem6.p=&elem3;

    elem4.p=&elem2;
    elem4.right_sib=&elem5;

    elem5.p=&elem2;

    return 0;
}