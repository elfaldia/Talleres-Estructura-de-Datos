#pragma once 
#include <vector>
#include <climits>
using namespace std;

class Node
{

public:
    int value;
    int column;
    Node* father;
    vector<Node*> children;

    Node():value(0),column(-1),father(nullptr){}
    Node(int val, int col, Node* fat): value(val),column(col),father(fat){}
    ~Node()
    {
        for(Node* child:children){
            delete child;
        }
    }
};