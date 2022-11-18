//CS10C - Spring 2021
//Lab 7
//Pair: Baron Fung, Kelley Zhou
//Resource(s): Zybooks pseudocode

#include "AVLTree.h"
#include "Node.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

AVLTree::AVLTree() {
    root = nullptr;
    // root->left = nullptr;
    // root->right = nullptr;
    // root->parent = nullptr;
}

void AVLTree::insert(const string & newString) { //zybooks
    //cout << "search 4 newstring" << endl;
    if (search(newString)) { //if string exists in tree
        //cout << "creating temp" << endl;
        Node* temp = returnSearch(newString);
        temp->count++;
        //cout << "temp count iterated: duplicates case" << endl;
        return; //updates count of the node
    }
    
    if (root == nullptr) {
        root = new Node(newString);
        root->parent = nullptr;
        return;
    }

    //cout << "string: " << newString << endl;
    Node* node = new Node(newString);
    Node* curr = root;
    while (curr != nullptr) {
        if (node->data < curr->data) {
            if (curr->left == nullptr) {
                //cout << "entered curr->left == nullptr" << endl;
                curr->left = node;
                node->parent = curr;
                node->count++;
                curr = nullptr;
            }
            else {
                //cout << "entered curr->left == nullptr    iteration" << endl;
                curr = curr->left;
            }
        }
        else {
            if (curr->right == nullptr) {
                //cout << "entered curr->right == nullptr" << endl;
                curr->right = node;
                node->parent = curr;
                node->count++;
                curr = nullptr;
            }
            else {
                //cout << "entered curr->rightt == nullptr    iteration" << endl;
                curr = curr->right;
            }
        }
    }

    //cout << "about to balance" << endl;
    node = node->parent;
    while (node != nullptr) {
        //cout << "balancing" << endl;
        rotate(node);
        node = node->parent;
    }
    //cout << "balanced" << endl;
}

int AVLTree::balanceFactor(Node* node) {
    if (node == nullptr) {
        //cout << "node is nullptr" << endl;
        return -1;
    }
    //cout << "computing balFact" << endl;
    return get_height(node->left) - get_height(node->right);
}

void AVLTree::printBalanceFactors() {
    printBalanceFactors(root);
    cout << endl;
}

//given
void AVLTree::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error"<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}

// Node* AVLTree::findUnbalancedNode(Node* node) {

// }

//zybooks 7.2.2 rebalance
Node* AVLTree::rotate(Node* node) {
    updateHeight(node);
    //cout << "updated height" << endl;
    if (balanceFactor(node) == -2) {
        //cout << "balFact == -2" << endl;
        if (balanceFactor(node->right) == 1) {
            //cout << "double rotation case: rotate right then left" << endl;
            //double rotation case
            rotateRight(node->right);
        }
        //cout << "rotate left" << endl;
        return rotateLeft(node);
    }
    else if (balanceFactor(node) == 2) {
        //cout << "balFact == 2" << endl;
        if (balanceFactor(node->left) == -1) {
            //cout << "double rotation case: rotate left then right" << endl;
            //double rotation case
            rotateLeft(node->left);
        }
        //cout << "rotate right" << endl;
        rotateRight(node);
    }
    //cout << "end" << endl;
    return node;
}

Node* AVLTree::rotateLeft(Node* node) {
    Node* rightLeftChild = node->right->left;
    if (node->parent != nullptr) {
        replaceChild(node->parent, node, node->right);
    }
    else {
        root = node->right;
        root->parent = nullptr;
    }
    setChild(node->right, "left", node);
    setChild(node, "right", rightLeftChild);
    return node;
}

//zybooks 7.2.7
Node* AVLTree::rotateRight(Node* node) {
    Node* leftRightChild = node->left->right;
    if (node->parent != nullptr) {
        replaceChild(node->parent, node, node->left);
    }
    else {
        root = node->left;
        root->parent = nullptr;
    }
    setChild(node->left, "right", node);
    setChild(node, "left", leftRightChild);
    return node;
}

void AVLTree::printBalanceFactors(Node *node) { //inorder notation
    if (node != nullptr) {
        printBalanceFactors(node->left);
        cout << node->data << "(" << balanceFactor(node) << "), ";
        printBalanceFactors(node->right);
    }
}

//given
void AVLTree::visualizeTree(ofstream & outFS, Node *n){
    if(n){
        if(n->left){
            visualizeTree(outFS,n->left);
            outFS<<n->data <<" -> " <<n->left->data<<";"<<endl;    
        }

        if(n->right){
            visualizeTree(outFS,n->right);
            outFS<<n->data <<" -> " <<n->right->data<<";"<<endl;    
        }
    }
}

//zybooks 4.4
bool AVLTree::search(const string &key) const { 
    Node* curr = root;
    //cout << "curr assigned root" << endl;
    while (curr != nullptr) {
        //cout << "while loop entered" << endl;
        if (curr->data == key) {
            //cout << "found duplicate" << endl;
            return true;
        }
        else if (key < curr->data) {
           // cout << "looking left" << endl;
            curr = curr->left;
        }
        else {
            //cout << "looking right" << endl;
            curr = curr->right;
        }
    }
    return false; //not found
}

Node* AVLTree::returnSearch(const string &key) {
    Node* curr = root;
    //cout << "created curr" << endl;
    Node* returnNode = nullptr;
    //cout << "created returnNode" << endl;
    while (curr != nullptr) {
        //cout << "while entered" << endl;
        if (curr->data == key) {
            //cout << "found the node" << endl;
            returnNode = curr;
            break;
        }
        else if (key < curr->data) {
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }
    return returnNode; //not found
}

//zybooks 7.2.1
void AVLTree::updateHeight(Node* node) { 
    int leftHeight = -1;
    if (node->left != nullptr) {
        leftHeight = node->left->height;
    }
    int rightHeight = -1;
    if (node->right != nullptr) {
        rightHeight = node->right->height;
    }
    
    if (leftHeight > rightHeight) {
        node->height = leftHeight + 1;
    }
    else {
        node->height = rightHeight + 1;
    }
}

//zybooks 7.2.1
bool AVLTree::replaceChild(Node* parent, Node* currChild, Node* newChild) {
    if (parent->left == currChild) {
        return setChild(parent, "left", newChild);
    }
    else if (parent->right == currChild) {
        return setChild(parent, "right", newChild);
    }
    return false;
}

//zybooks 7.2.1
bool AVLTree::setChild(Node* parent, string whichChild, Node* child) {
    if (whichChild != "left" && whichChild != "right") {
        return false;
    }

    if (whichChild == "left") {
        parent->left = child;
    }
    else {
        parent->right = child;
    }

    if (child != nullptr) {
        child->parent = parent;
    }

    updateHeight(parent);
    return true;
}

int AVLTree::get_height(Node* node) const {
    if (node == nullptr) {
        return -1;
    }
    else {
        int lh, rh;
        lh = get_height(node->left);
        rh = get_height(node->right);
        if (lh > rh) {
            return lh + 1;
        }
        else {
            return rh + 1;
        }
    }
}



