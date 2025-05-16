#include <iostream>

#include <list>

using namespace std;

class Node{
    public:
        char info;
        int parent;

        Node(){
            this->info=0;
            this->parent=0;
        }

        Node(char info, int parent){
            this->info=info;
            this->parent=parent;
        }
        
};

/**
 * @brief Create a Tree object
 * 
 * @param tree 
 */
void createTree(vector<Node>& tree){
    int dim;
    cout<<"Tree Size: ";
    cin>> dim;

    for(int i=0;i<dim;i++){
        char info;
        int parent=0;
        cout<<endl;
        cout<<"--Node num: "<<i+1<<"---"<<endl;
        cout<<"Info: ";
        cin>>info;
        cout<<"Parent: ";
        cin>>parent;
        Node elem(info,parent);
        tree.push_back(elem);
    }
}


/**
 * @brief Print the entire tree
 * 
 * @param tree 
 */
void printTree(vector<Node> tree){
    for (size_t i = 0; i < tree.size(); i++)
    {
        cout<<"-"<<i+1<<')'<<" Info: "<<tree.at(i).info<<" Parent: "<<tree.at(i).parent<<endl;
    }
    
}
/**
 * @brief Return the Father of the Node , Complexity : Θ(1)
 * 
 * @param tree 
 * @param v 
 * @return int 
 */
int fatherTree(vector<Node> tree, int v){
    if(tree.at(v).parent==-1){
        cout<<"It is the root"<<endl;
        return -1;
    }else{
        return tree.at(v).parent;
    }
}

/**
 * @brief Returns a list of all children of node v, Complexity : Θ(n)
 * 
 * @param tree 
 * @param v 
 * @return list<Node> 
 */
list<Node> childrensTree(vector<Node> tree, int v){
    list<Node> sons;
    for (size_t i = 0; i < tree.size(); i++)
    {
        if(tree.at(i).parent==v){
            sons.push_back(tree.at(i));
        }
    }
    return sons;
    
}

int main(){
    
    vector<Node> tree;
    createTree(tree);
    printTree(tree);

    int v;

    cout<<"Sons of the Node: ";
    cin>>v;

    list<Node> sons= childrensTree(tree,v);
    int i=1;
    for(Node son : sons){
        cout<<"-"<<i+1<<')'<<" Info: "<<son.info<<" Parent: "<<son.parent<<endl;
        i++;
    }



    return 0;
}
