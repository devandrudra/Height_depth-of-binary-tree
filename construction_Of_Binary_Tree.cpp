#ifndef BT_CONSTRUCTION_H
#define BT_CONSTRUCTION_H

#include<iostream>
using namespace std;

struct node
{
    int data;
    node* left = NULL;
    node* right = NULL;
    node(int data)
    {
        this -> data = data;
    }
};

class constructionOfBinaryTree
{
    public:
    node* constructBT()
    {
        string x;
        cout << "enter the data: (enter 'q' if don't want to proceed)";
        cin >> x;
        if(x == "q") return NULL;
        node* head = new node(stoi(x));
        head -> left = constructBT();
        head -> right = constructBT();
        return head;
    }

};

void postorder(node* head)
{
    if(head == NULL) return;
    postorder(head -> left);
    postorder(head -> right);
    cout << head -> data << " ";
}

// int main()
// {
//     constructionOfBinaryTree obj;
//     node* head = obj.constructBT();
//     postorder(head);
//     return 0;
// }



#endif