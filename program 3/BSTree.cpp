//CS10C - Spring 2021
//Program 3
//Pair: 

#include <iostream>
#include <string>
#include <cctype>
#include "Node.h"
#include "BSTree.h"

using namespace std;

//default constructor
BSTree::BSTree() {
    root = nullptr;
}

//destructor
BSTree::~BSTree() {
    clearTree(root);
}

void BSTree::clearTree(Node *node) {
    if (node != nullptr) {
        clearTree(node->left);
        clearTree(node->right);
    }
    delete node;
}

//Order functions
void BSTree::preOrder(Node *node) const {
    if (node == nullptr) {
        return;
    }
    else {
        cout << node->item << "(" << node->count << "), ";
        preOrder(node->left);
        preOrder(node->right);
    }
    
}
void BSTree::postOrder(Node *node) const {
    if (node == nullptr) {
        return;
    }
    else {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->item << "(" << node->count << "), ";
    }
    
}
void BSTree::inOrder(Node *node) const {
    if (node == nullptr) {
        return;
    }
    else {
        inOrder(node->left);
        cout << node->item << "(" << node->count << "), ";
        inOrder(node->right);
    }
    
}

//recursive Order function
void BSTree::preOrder() const {
    preOrder(root);
}
void BSTree::postOrder() const {
    postOrder(root);
}
void BSTree::inOrder() const {
    inOrder(root);
}

/* Insert an item into the binary search tree. 
    Be sure to keep BST properties. 
    When an item is first inserted into the tree the count should be set to 1. 
    When adding a duplicate string (case sensitive), rather than adding another node, 
    the count variable should be incremented 
*/
void BSTree::insert(const string &newString) { //help from zybooks 4.5

    if (root == nullptr) { //if the tree is empty
        root = new Node(newString);
        root->count++;
        root->left = nullptr;
        root->right = nullptr;
    }
    else {
        Node* tracker = root;
        while (tracker != nullptr) {
            if (tracker->item == newString) { //tracker is currently on a preexisting node that has the same string
                //cout << "count incremented" << endl;
                tracker->count++;
                cout << tracker->count << endl;
                //cout << "           updated" << endl;
                return;
            }
            else { //looking for where to put the string
                if (newString < tracker->item) { //left
                    if (tracker->left == nullptr) {
                        Node* new_node = new Node(newString);
                        tracker->left = new_node;
                        new_node->count++;
                        tracker = nullptr;
                        return;
                        //cout << "           added left" << endl;
                    }
                    else {
                        tracker = tracker->left;
                    }
                }
                else if (newString > tracker->item) { //right
                    if (tracker->right == nullptr) {
                        Node* new_node = new Node(newString);
                        tracker->right = new_node;
                        new_node->count++;
                        tracker = nullptr;
                        return;
                        //cout << "           added right" << endl;
                    }
                    else {
                        tracker = tracker->right;
                    }
                }
            }
        }
    }
    
}

//helper to compare strings
/*bool BSTree::isSmaller(const string new_node, const string tracker) const {
    //cout << "isSmaller entered" << endl;
    int size = new_node.size();
    int size2 = tracker.size();
    //cout << "new_node size: " << size << endl << "tracker size: "<< size2 << endl;

    if (size < size2) {
        for (int i = 0; i < size; ++i) {
            const char temp = toupper(new_node[i]);
            const char temp2 = toupper(tracker[i]);
            //cout << "new_node: " << temp << ", tracker: " << temp2 << endl;
            if (temp < temp2) {
                //cout << "returned true" << endl;
                return true;
            }
            else if (temp > temp2) {
                //cout << "returned false" << endl;
                return false;
            }
        }
        //cout << "exit loop, returned true" << endl;
        return true;
    }
    else if (size2 < size) {
        for (int i = 0; i < size2; ++i) {
            const char temp = toupper(new_node[i]);
            const char temp2 = toupper(tracker[i]);
            //cout << "new_node: " << temp << ", tracker: " << temp2 << endl;
            if (temp < temp2) {
                return true;
            }
            else if (temp > temp2) {
                return false;
            }
        }
        return false;
    }
    else { //same size
        for (int i = 0; i < size; ++i) {
        const char temp = toupper(new_node[i]);
        const char temp2 = toupper(tracker[i]);
        if (temp > temp2) {
            return true;
        }
        else if (temp < temp2) {
            return false;
        }
        
        return false;
        }
    }
    
    return false;
}
*/

void BSTree::remove(const string &key) { //help from zybooks 4.6
    Node* parent = nullptr;
    Node* curr = root;
    while (curr != nullptr) {
        if (curr->item == key) { // if word is found
            if (curr->left == nullptr && curr->right == nullptr) { //no children
                if (parent == nullptr) { //node is root
                    if (root->count > 1) {
                        root->count--;
                    }
                    root = nullptr; //IF THIS DOESN'T REMOVE NODE, ADD DELETE
                }
                else if (parent->left == curr) { //
                    if (curr->count > 1) {
                        curr->count--;
                        break;
                    }
                    parent->left = nullptr;
                }
                else {
                    if (curr->count > 1) {
                        curr->count--;
                        break;
                    }
                    parent->right = nullptr;
                }
            }
            else if (curr->right == nullptr) { //no right child, but has a left child
                if (parent == nullptr) { //node is root
                    if (root->count > 1) {
                        root->count--;
                        break;
                    }
                    else {
                        root = curr->left;
                    }
                }
                else if (parent->left == curr) {
                    if (curr->count > 1) {
                        curr->count--;
                        break;
                    }
                    else {
                        parent->left = curr->left;
                    }
                }
                else {
                    if (curr->count > 1) {
                        curr->count--;
                        break;
                    }
                    else {
                        parent->right = curr->left;
                    }
                }
            }
            else if (curr->left == nullptr) { //no left child, but has a right child
                if (parent == nullptr) { //node is root
                    if (root->count > 1) {
                        root->count--;
                        break;
                    }
                    else {
                        root = curr->right;
                    }
                }
                else if (parent->left == curr) {
                    if (curr->count > 1) {
                        curr->count--;
                        break;
                    }
                    else {
                        parent->left = curr->right;
                    }
                }
                else {
                    if (curr->count > 1) {
                        curr->count--;
                        break;
                    }
                    else {
                        parent->right = curr->right;
                    }
                }
            }
            else { //has left and right child
                Node* successor = curr->left;
                while (successor->right != nullptr) {
                    successor = successor->right;
                }
                Node* copy = successor;
                //cout << "Successor: " << successor->item << endl;
                remove(successor->item); //removes successor
                curr->item = copy->item;
                curr->count = copy->count;
                 //assign's curr's item with copy's item
            }
            return;
        }
        else if (key < curr->item) { 
            parent = curr;
            curr = curr->left;
        }
        else { 
            parent = curr;
            curr = curr->right;
        }
    }
    return;
}

bool BSTree::search(const string &key) const { //help from zybook 4.4
    Node* curr = root;
    while (curr != nullptr) {
        if (curr->item == key) {
            return true;
        }
        else if (key < curr->item) {
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }
    return false; //not found
}

string BSTree::largest() const {
    Node* curr = root;
    if (curr == nullptr) {
        return "";
    }
    while (curr->right != nullptr) {
        curr = curr->right;
    }
    cout << curr->item;
    return curr->item;
}

string BSTree::smallest() const {
    Node* curr = root;
    if (curr == nullptr) {
        return "";
    }
    while (curr->left != nullptr) {
        curr = curr->left;
    }
    cout << curr->item;
    return curr->item;
}

int BSTree::height(const string& key) const {
    Node* curr = root;
    int h = get_height(key, curr);
    curr = root;
    while (curr != nullptr) {
        if (curr->item == key) {
            if (curr->left == nullptr && curr->right == nullptr) {
                return 0;
            }
            return get_height(key, curr);
        }
        else if (key < curr->item) {
            --h;
            curr = curr->left;
        }
        else if (key > curr->item) {
            --h;
            curr = curr->right;
        }
    }

    return -1;
}

int BSTree::get_height(const string& key, Node* node) const {
    if (node == nullptr) {
        return -1;
    }
    else {
        int lh, rh;
        lh = get_height(key, node->left);
        rh = get_height(key, node->right);
        if (lh > rh) {
            return lh + 1;
        }
        else {
            return rh + 1;
        }
    }
}


