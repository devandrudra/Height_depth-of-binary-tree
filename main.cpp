#ifndef main_h
#define main_h

#include "construction_Of_Binary_Tree.cpp"
#include<iostream>
using namespace std;

class HeightOfBinaryTree
{
    node* head;
    public:
    HeightOfBinaryTree(node* head)
    {
        this -> head = head;
    }

    int height(node* head)
    {
        if(head == NULL) return -1;
        return max(height(head -> left), height(head -> right));
    }
};

int main()
{
    node* head = new node(1);
    head -> left = new node(2);
    head -> left -> left = new node(4);
    head -> right = new node(3);
    head -> right -> right = new node(5);
    head -> right -> right -> left = new node(6);
    head -> right -> right -> right = new node(7);
    postorder(head);
    HeightOfBinaryTree obj(head);
    cout << "\n" << obj.height(head);
    return 0;
}

#endif