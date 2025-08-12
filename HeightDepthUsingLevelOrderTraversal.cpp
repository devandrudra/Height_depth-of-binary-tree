#ifndef queue_h
#define queue_h

#include "construction_Of_Binary_Tree.cpp"

#include<iostream>
#include<vector>
#include<queue>

class HeightDepth
{
    node* head;
    public:
    HeightDepth(node* head)
    {
        this -> head = head;
    }
    int findheightOfTree()
    {
        queue<node*> q;
        q.push(this -> head);
        int height = -1;
        while(q.size())
        {
            int size = q.size();
            int i;
            for(i = 0; i < size; i++)
            {
                node* root = q.front();
                q.pop();
                if(root -> left) q.push(root -> left);
                if(root -> right) q.push(root -> right);
            }
            height++;
        }
        return height;
    }

    int finddepth_at(int x)
    {
        queue<node*> q;
        q.push(this -> head);
        int dep = -1;
        while(q.size())
        {
            int size = q.size();
            int i;
            for(i = 0; i < size; i++)
            {
                node* root = q.front();
                if(root -> data == x) return ++dep;
                q.pop();
                if(root -> left) q.push(root -> left);
                if(root -> right) q.push(root -> right);
            }
            dep++;
        }
        return -1;
    }

    int height_at(int x)
    {
        return findheightOfTree() - finddepth_at(x);
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
    head -> right -> right -> right -> right = new node(11);
    postorder(head);
    HeightDepth obj(head);
    cout << endl;
    cout << obj.findheightOfTree();
    cout << endl;
    cout << obj.finddepth_at(1);
    cout << endl;
    cout << obj.height_at(4); // not correct!
    return 0;
}



#endif