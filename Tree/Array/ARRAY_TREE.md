# Tree created using an Array

The implementation using an array requires a **vector of pairs** , where each node is represented **(info, parent)**. Where **info** is the information of the node and **parent** is the node's father.

![alt text](Images/image.png)

The vector ***P*** associated is: 

![alt text](Images/image-1.png)

## Observations

### 1) fatherTree

Return the Father of the Node
![alt text](Images/image-2.png)

**Complexity : Θ(1)**

### 2) childrensTree

Returns a list of all children of node v

![alt text](Images/image-3.png)

**Complexity : Θ(n)**
