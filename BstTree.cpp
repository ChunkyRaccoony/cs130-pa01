#include "BstTree.h"

#include<iostream>
using namespace std;

BstTree::BstTree() : root(0) {}

BstTree::~BstTree() {
    clear(root);
}
void BstTree::clear(Node* n){
    if (n) {
        clear(n->left);
        clear(n->right);
        delete n;
    }
}

int BstTree::bstInsert(string word){
    if(!root){
        root = new Node(word);
        root->count += 1;
        cout<< word<<" inserted, new count = "<<(root->count)<<endl;
        return true;
    }
    return insert(word, root);
}

int BstTree::insert(string word, Node* n){
    if (word == (n->value)) {
        n->count += 1;
        cout<<word<<" inserted, new count = "<<(n->count)<<endl;
        return (n->count);
    }
    if (word.compare(n->value)<= 0) {
        if (n->left){
            return insert(word, n->left);
        }else{
            n->left = new Node(word);
            n->left->parent = n;
            n->count += 1;
            cout<<word<<" inserted, new count = "<<(n->count)<<endl;
            return (n->count);
        }
    }else{
        if (n->right){
            return insert(word, n->right);
        }else{
            n->right = new Node(word);
            n->right->parent = n;
            n->count += 1;
            cout<<word<<" inserted, new count = "<<(n->count)<<endl;
            return (n->count);
        }
    }
}

bool BstTree::bstSearch(string word) const{
    Node* n = root;
    while (n != nullptr){
        if ((n->value) == word){
            cout<<word<<" found, count = "<<(n->count)<<endl;
            return true;
        }else{
            if ((n->value).compare(word) >= 0){
                n = n -> left;
            }else{
                n = n -> right;
            }
        }
    }
    cout<<word<<" not found"<<endl;;
    return false;
}

BstTree::Node* BstTree::getNodeFor(string word, Node* n) const{
   Node* temp = n;
   if (n == nullptr){
       return nullptr;
   }
   while(1){
       if (temp->value == word){
           break;
       }else if ((temp->value).compare(word)>=0){
           temp = temp -> left;
       }else{
           temp = temp -> right;
       }
       if (temp == nullptr){
           break;
       }
   }
  return temp; // REPLACE THIS NON-SOLUTION
}
BstTree::Node* BstTree::getPredecessorNode(string word) const{
       if (root == nullptr)
       {return nullptr;
       }
       Node *temp =getNodeFor(word, root);
       if (temp != nullptr){
           if (temp->left){
               temp = temp->left;
               while(temp->right){
                   temp = temp->right;
               }
               return temp;
           }else{
               if(temp->parent->right == temp){
                   return temp->parent;
               }else{
                   while(temp->parent && temp->parent->parent){
                       if(temp->parent->parent->right == temp->parent){
                           return temp->parent->parent;
                       }
                       temp = temp->parent;
                   }
                   return nullptr;
               }
           }
       }else{
           return nullptr;
       }
}
bool BstTree::bstDelete(string word){
    if (root == nullptr){
        return false;
    }
    Node* n = getNodeFor(word,root);//representing target
    Node* p = n->parent;//representing parent
    Node* c = nullptr;//representing child
    if(n->count > 1){
            n->count -= 1;
            cout<<word<<" deleted, new count = "<<(n->count)<<endl;
            return true;
        }
    if(n->left == nullptr && n->right == nullptr){
        if(p == nullptr){
            delete n;
            root = nullptr;
            cout<<word<<" deleted"<<endl;
            return true;
        }//leaf case
        if (n == p->right){
            p->right = nullptr;
           }else{
            p->left = nullptr; }
             delete n;
             cout<<word<<" deleted"<<endl;
             return true;
           
   }else if(n->left != nullptr && n->right != nullptr){
       Node* pre = getPredecessorNode(word);
       string val = pre->value;
       bstDelete(val);
       n->value = val;
       cout<<word<<" deleted"<<endl;
       return true;

   } else {
       if(n->left)
           c = n->left;
       else if(n->right)
           c = n->right;
       if(p == nullptr){
           delete n;
           root = c;
           root->parent = nullptr;
           cout<<word<<" deleted"<<endl;
           return true;
       }
       if((c->value).compare(p->value) < 0){
           c->parent = p;
           p->left = c;
           delete n;
           cout<<word<<" deleted"<<endl;
           return true;
       }else{
           c->parent = p;
           p->right = c;
           delete n;
           cout<<word<<" deleted"<<endl;
           return true;
       }
   }
   return false;   
}

void BstTree::bstRangeSearch(string word1,string word2){
    printRange(root,word1,word2);
}

void BstTree::printRange(Node* root, string w1, string w2){
    if (root == nullptr){
        return;
    }
    if (w1.compare(root->value) < 0){
        printRange(root->left,w1,w2);
    }
    if (w1.compare(root->value) <= 0 && w2.compare(root->value) >= 0){
        cout<<(root->value)<<endl;
    }
    if (w2.compare(root->value) > 0){
        printRange(root->right,w1,w2);
    }
}