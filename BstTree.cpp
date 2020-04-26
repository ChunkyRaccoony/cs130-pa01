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
    if (word.compare(n->value) == 0) {
        n->count += 1;
        // cout<<word<<" inserted, new count = "<<(n->count)<<endl;
        return (n->count);
    }
    if (word.compare(n->value)< 0) {
        if (n->left){
            return insert(word, n->left);
        }else{
            n->left = new Node(word);
            n->left->parent = n;
            n->left->count += 1;
            // cout<<word<<" inserted, new count = "<<(n->left->count)<<endl;
            return (n->left->count);
        }
    }else{
        if (n->right){
            return insert(word, n->right);
        }else{
            n->right = new Node(word);
            n->right->parent = n;
            n->right->count += 1;
            // cout<<word<<" inserted, new count = "<<(n->right->count)<<endl;
            return (n->right->count);
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
// BstTree::Node* BstTree::getPredecessorNode(string word) const{
//        if (root == nullptr)
//        {return nullptr;
//        }
//        Node *temp =getNodeFor(word, root);
//        if (temp != nullptr){
//            if (temp->left){
//                temp = temp->left;
//                while(temp->right){
//                    temp = temp->right;
//                }
//                return temp;
//            }else{
//                if(temp->parent->right == temp){
//                    return temp->parent;
//                }else{
//                    while(temp->parent && temp->parent->parent){
//                        if(temp->parent->parent->right == temp->parent){
//                            return temp->parent->parent;
//                        }
//                        temp = temp->parent;
//                    }
//                    return nullptr;
//                }
//            }
//        }else{
//            return nullptr;
//        }
// }
void BstTree::bstDelete(string word){
     Node* t1 = getNodeFor(word, root);
     Node* temp = removeNode(root, word);
     Node* t2 = getNodeFor(word, root);
     if ((t1)&&(t2 == nullptr)){
         cout<<word<<" deleted"<<endl;
     }

}

BstTree::Node* BstTree::findMin(BstTree::Node* n){
    while(n->left != nullptr){
        n = n->left;
    }
    return n;
}
BstTree::Node* BstTree::removeNode(BstTree::Node* root, string word){
    if(root == nullptr){
        return root; 
    }else{
        if(word.compare(root->value) < 0) {
        root->left = removeNode(root->left,word);
        }else if (word.compare(root->value) > 0) {
        root->right = removeNode(root->right,word);
        }else if (word.compare(root->value) == 0) {
            if(root->count >1){
                root->count -= 1;
                cout<<word<<" deleted, new count = "<<(root->count)<<endl;
            }else{
		// Case 1:  No child
		if(root->left == nullptr && root->right == nullptr) { 
			delete root;
			root = nullptr;
		}
		//Case 2: One child 
		else if(root->left == nullptr) {
			Node* temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			Node* temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else { 
			Node* temp = findMin(root->right);
			root->value = temp->value;
			root->right = removeNode(root->right,temp->value);
		}
            }
	}
	return root;
    }
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