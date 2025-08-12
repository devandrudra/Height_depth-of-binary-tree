#ifndef main_h
#define main_h

#include "construction_Of_Binary_Tree.cpp"
#include<iostream>
#include<vector>
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
        return max(height(head -> left), height(head -> right)) + 1;
    }
};

class DepthOfBinaryTree
{
    int x;
    node* head;
    public:
    DepthOfBinaryTree(node* head, int x)
    {
        this -> x = x;
        this -> head = head;
    }
    int Depth(node* head, int &x)
    {
        if(head == NULL) return -1;
        if(head -> data == x) return 0;
        int res;
        if((res = Depth(head -> left, x)) >= 0 || (res = Depth(head -> right, x)) >= 0)
        {
            return res + 1;
        }
        return -1;

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
    DepthOfBinaryTree dp_obj(head, 5);
    int x = 7;
    cout << "\ndepth(x = 7): " << dp_obj.Depth(head, x);
    cout << "\nHeight: " << obj.height(head);
    return 0;
}

#endif