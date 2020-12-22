#include <iostream>
#include <string>
#include<sstream>
using namespace std;


class node
{
    public:
        int value;
        node *left,*right;
};

class tree
{
    public:
        node *root;

        tree()
        {
            root=NULL;
        }

        node* insertIntoTheTree(int key,node *newNode)
        {
            if(newNode==NULL)
            {
                newNode=new node();
                newNode->value=key;
                newNode->left=newNode->right=NULL;
                //cout<<newNode->value;
            }
            else if(key<=newNode->value)
            {
                newNode->left=insertIntoTheTree(key,newNode->left);
            }
            else
            {
                newNode->right=insertIntoTheTree(key,newNode->right);
            }
            return newNode;
        }

        void insertNode(int key)
        {
            root=insertIntoTheTree(key,root);
        }

        inline string int2str(int n) {
            ostringstream sstream;
            sstream << n;
  
            return sstream.str();
        }
        
        void printTree(node *root, string &str)
        {
            if(root==NULL)
                return;

            else
            {
                //cout<<root->value<<" ";
                //str.append(int2str(root->value));
                //str.append(" ");
                str=str+int2str(root->value)+" ";
                printTree(root->left,str);
                printTree(root->right,str);
            }
        }

        string printNodes()
        {
            string str;
            printTree(root,str);
            //cout<<str;
            return str;
        }
};
int main()
{
    tree t;
    t.insertNode(14);
    t.insertNode(12);
    t.insertNode(2);
    t.insertNode(13);
    t.insertNode(8);
    string str=t.printNodes();
    return 0;
}
