#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <sstream>
#include <iomanip>
#include <limits.h>

using namespace std;
struct Node{
    int n;
    struct Node *left,*right;
    Node(int data):n(data),left(NULL),right(NULL){}
};
class BTree{
    Node *root;
    Node emptyNode; // for pretty printing

    void printNode(Node *node, int indent){
        if(node==&emptyNode){
            cout<<string(indent*2,' ');
            return;
        }
        cout<<string(indent/2,' ');
        if(node->left)
            cout<<string(indent/2,'_');
        else
            cout<<string(indent/2,' ');
        cout<<node->n;
        if(node->right)
            cout<<string(indent/2,'_');
        else
            cout<<string(indent/2,' ');
        cout<<string(indent/2,' ');
    }
public:
    int height;
    BTree():root(NULL),height(0),emptyNode(INT_MIN){}
    bool insert(Node *newnode){
        if(!root){
            root=newnode;
            return true;
        }
        Node *curr=root;
        int currlvl=0;
        while(1){
            if(newnode->n < curr->n){
                if(curr->left)
                    curr=curr->left;
                else{
                    curr->left=newnode;
                    break;
                }
            }else if(newnode->n > curr->n){
                if(curr->right)
                    curr=curr->right;
                else{
                    curr->right=newnode;
                    break;
                }
            }else
                return false;
            currlvl++;
        }
        currlvl++;
        if(currlvl > height)
            height=currlvl;
        return true;
    }
    bool insertrecursive(Node *newnode){
        root=insertrecursive_helper(root,newnode);
        return true;
    }
    Node *insertrecursive_helper(Node *curr, Node *newnode){
        if(!curr)
            return newnode;
        if(newnode->n < curr->n)
            curr->left=insertrecursive_helper(curr->left,newnode);
        else if(newnode->n > curr->n)
            curr->right=insertrecursive_helper(curr->right,newnode);
        return curr;
    }
    bool place(int data){
        Node *newnode=new Node(data);
        insert(newnode);
    }
    void remove(int n){
        Node *curr=root;
        Node **prev=&root;
        while(curr){
            if(n < curr->n){
                prev=&curr->left;
                curr=curr->left;
            }else if(n > curr->n){
                prev=&curr->right;
                curr=curr->right;
            }else{
                if(curr->left && curr->right){
                    Node *right=curr->left->right;
                    *prev=curr->left;
                    (*prev)->right=curr->right;
                    if(right){
                        Node *tmp=(*prev)->right;
                        while(tmp->left){
                            tmp=tmp->left;
                        }
                        tmp->left=right;
                    }
                }else if(curr->left){
                    *prev=curr->left;
                }else if(curr->right){
                    *prev=curr->right;
                }else{
                    *prev=NULL;
                }
                delete curr;
                break;
            }
        }
    }
    void remove(Node *node){
        remove(node->n);
    }
    void removerecursive(int n){
        root=removerecursive_helper(n,root);
    }
    Node *removerecursive_helper(int n, Node *curr){
        if(n < curr->n){
            curr->left=removerecursive_helper(n,curr->left);
        }else if(n > curr->n){
            curr->right=removerecursive_helper(n,curr->right);
        }else{
            Node *ret;
            if(curr->left && curr->right){
                ret=curr->left;
                Node *right=curr->left->right;
                Node *tmp=curr->right;
                curr->left->right=curr->right;
                if(right){
                    while(tmp->left)
                        tmp=tmp->left;
                    tmp->left=right;
                }
            }else if(curr->left){
                ret=curr->left;
            }else if(curr->right){
                ret=curr->right;
            }else{
                ret=NULL;
            }
            return ret;
        }
    }
    void removerecursive(Node *node){
        removerecursive(node->n);
    }
    void print(int spaces=2){
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        int lvl=0;
        string node2str;
        while(!q.empty()){
            Node *p=q.front(); q.pop();
            if(!p){
                if(!q.empty())
                    q.push(NULL);
                lvl++;
                cout<<endl;
                continue;
            }
            int indent=1*spaces;
            for(int i=0;i<(height-lvl);i++)
                indent*=2;
            printNode(p,indent);
            if(p->left){
                q.push(p->left);
            }else if(lvl < height){
                q.push(&emptyNode);
            }
            if(p->right){
                q.push(p->right);
            }else if(lvl < height){
                q.push(&emptyNode);
            }
        }
    }
};

BTree *createBTree(int nrnodes){
    BTree *btree=new BTree();
    Node *node;
    int n;
    for(int i=0;i<nrnodes;i++){
        n=rand()%10;
        node=new Node(n);
        btree->insert(node);
    }
    return btree;
}

int main(int argc,char**argv)
{
    int nrnodes=5;
    bool interactive=false;
    if(argc==2)
        nrnodes=atoi(argv[1]);
    else if(argc == 3){
        if(argv[1][0]=='-' && argv[1][1]=='i'){
            interactive=true;
            nrnodes=atoi(argv[2]);
        }else if(argv[2][0]=='-' && argv[2][1]=='i'){
            interactive=true;
            nrnodes=atoi(argv[1]);
        }else {
            fprintf(stderr,"wrong option provided\n");
            fprintf(stderr,"usage: %s [-i] [nrnodes]\n", argv[0]);
            return 1;
        }
    }
    BTree *btree=new BTree();
    if (interactive){
        int node;
        for(int i=0;i<nrnodes;i++){
            cin>>node;
            btree->place(node);
        }
    }else{
        srand(time(NULL));
        btree=createBTree(nrnodes);
    }

    btree->print();

    btree->remove(5);
    btree->print();
}
