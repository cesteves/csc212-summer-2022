#include "rbtree.h"

/*
 * Node Class Functions
*/

// Don't forget to change these constructors!
RBTNode::RBTNode(){
    this->data = 0;
    this->left = nullptr;
    this->right = nullptr;
    this->red = true;
}

RBTNode::RBTNode(int data){
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
    this->red = true;
}

RBTNode::~RBTNode(){

}

RBTNode* RBTree::insert(int data, RBTNode* root){
    if(!root){
        return new RBTNode(data);
    }

    if(data < root->data){
        root->left = insert(data, root->left);
    }else{
        root->right = insert(data, root->right);
    }

	// Add code here to complete this assignment.
	// HINT: Rules 1-3 sequentially!

    if(!isRed(root->left) && isRed(root->right)){
        root = rotateLeft(root);
        root->red = root->left->red;
        root->left->red = true;
    }

    if(isRed(root->left) && isRed(root->left->left)){
        root = rotateRight(root);
        root->red = root->right->red;
        root->right->red = true;
    }

    if(isRed(root->left) && isRed(root->right)){
        root->swapColor();
        root->left->swapColor();
        root->right->swapColor();
    }


    return root;
}

int RBTree::height(RBTNode* root){
    if(!root){
        return -1;
    }
    int left = height(root->left);
    int right = height(root->right);

    return (left > right ? left + 1 : right + 1);
}

void RBTree::preorder(RBTNode* root, std::ostream& os){
    if(!root){
        return;
    }

    os << root->data << ":" << root->red << ", ";
    this->preorder(root->left, os);
    this->preorder(root->right, os);

    return;
}

void RBTree::inorder(RBTNode* root, std::ostream& os){
    if(!root){
        return;
    }

    this->inorder(root->left, os);
    os << root->data << ":" << root->red << ", ";
    this->inorder(root->right, os);

    return;
}

void RBTree::postorder(RBTNode* root, std::ostream& os){
    if(!root){
        return;
    }

    this->postorder(root->left, os);
    this->postorder(root->right, os);
    os << root->data << ":" << root->red << ", ";

    return;
}

void RBTree::destroy(RBTNode* root){
    if(!root){
        return;
    }

    this->destroy(root->left);
    this->destroy(root->right);
    delete root->left;
    delete root->right;
}

bool RBTree::search(int data, RBTNode* root){
    if(!root){
        return false;
    }

    if(data == root->data){
        return true;
    }

    if(data < root->data){
        return this->search(data, root->left);
    }else{
        return this->search(data, root->right);
    }
}

RBTNode* RBTree::rotateLeft(RBTNode* node){
    RBTNode* p = node->right;
    node->right = node->right->left;
    p->left = node;
    return p;
}

RBTNode* RBTree::rotateRight(RBTNode* node){
    RBTNode* p = node->left;
    node->left = node->left->right;
    p->right = node;
    return p;
}

bool RBTree::isRed(RBTNode* node){
    if(!node){
        return false;
    }

    return node->red;
}

/*
 * Public Functions
*/

RBTree::RBTree(){
    this->root = nullptr;
}

RBTree::~RBTree(){
    this->destroy(this->root);
}

void RBTree::insert(int data){
    this->root = this->insert(data, this->root);
    this->root->red = false;
}

int RBTree::height(){
    return this->height(this->root);
}

void RBTree::preorder(std::ostream& os){
    this->preorder(this->root, os);
    os << "\n";
}

void RBTree::inorder(std::ostream& os){
    this->inorder(this->root, os);
    os << "\n";
}

void RBTree::postorder(std::ostream& os){
    this->postorder(this->root, os);
    os << "\n";
}

bool RBTree::search(int data){
    return this->search(data, this->root);
}

void RBTree::clear(){
    this->destroy(this->root);
    this->root = nullptr;
}
