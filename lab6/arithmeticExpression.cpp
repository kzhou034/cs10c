//CS10C - Spring 2021
//Lab 6
//Pair: Baron Fung, Kelley Zhou

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stack>
#include <cstdlib>

#include "arithmeticExpression.h"

using namespace std;

/* Initializes an empty tree and sets the infixExpression
to the value of parameter passed in. */
arithmeticExpression::arithmeticExpression(const string &v) {
    infixExpression = v;
    root = 0;
}

/* Implementation of destrucor is optional.
    The destructor should deallocate all the nodes in the tree. */
//~arithmeticExpression();

/* Converts the infixExpression to its equivalent postfix string
    and then generates the tree and assigns the root node to the 
    root data field. The key for the first node is 'a', 'b' for the second node and so on. */
void arithmeticExpression::buildTree() {
    string postfixString = infix_to_postfix();
    //cout << "ex1: " << postfixString << endl;
    stack<TreeNode*> temp;
    unsigned i = 0;
    char letter = 'a';
    while (i < postfixString.size()) {
        char element = postfixString[i];
        TreeNode* node = new TreeNode(element, letter);
        if (priority(element) != 0) { //if element is + - * /
            node->right = temp.top();
            temp.pop();
            node->left = temp.top();
            temp.pop();
            temp.push(node);
            root = node;
        }
        else if (priority(element) == 0) { //if element is a letter in the alphabet
            temp.push(node);
        }
        ++i;
        ++letter;
    }
}

/* Calls the recursive infix function. */
void arithmeticExpression::infix() {
    infix(root);
}

/* Calls the recursive prefix function. */
void arithmeticExpression::prefix() {
    prefix(root);
}

/* Calls the recursive postfix function. */
void arithmeticExpression::postfix() {
    postfix(root);
}

//====================== given ======================
/* Calls the recursive visualizeTree function and generates the .png file using system call. */
void arithmeticExpression::visualizeTree(const string &outputFilename) {
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error opening "<< outputFilename<<endl;
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

/* Helper function that returns an integer according to
    the priority of the given operator. */
int arithmeticExpression::priority(char op) {
    int priority = 0;
    if(op == '('){
        priority =  3;
    }
    else if(op == '*' || op == '/'){
        priority = 2;
    }
    else if(op == '+' || op == '-'){
        priority = 1;
    }
    return priority;
}

/* Helper function that returns the postfix notation equivalent
    to the given infix expression */
string arithmeticExpression::infix_to_postfix() {
    stack<char> s;
    ostringstream oss;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i) {
        c = infixExpression.at(i);
        if(c == ' '){
            continue;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);
            }
            else if(c == ')'){
                while(s.top() != '('){
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){
                    if(s.top() == '('){
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            oss << c;
        }
    }
    while(!s.empty()){
        oss << s.top();
        s.pop();
    }
    return oss.str();
}
//===================================================

/* Helper function that outputs the infix notation of the arithmetic expression tree
    by performing the inorder traversal of the tree.
    An opening and closing parenthesis must be added at the 
    beginning and ending of each expression. */
void arithmeticExpression::infix(TreeNode *node) { //traverse left, print, traverse right
    if (node == 0) { //node is null
        return;
    }
    else {
        if (node->left != 0) {
            cout << "(";
        }
        infix(node->left);
        cout << node->data;
        infix(node->right);
        if (node->right != 0) {
            cout << ")";
        }
    }
}

/* Helper function that outputs the prefix notation of the arithmetic expression tree
    by performing the preorder traversal of the tree. */
//reference: https://www.tutorialspoint.com/data_structures_algorithms/tree_traversal.htm
void arithmeticExpression::prefix(TreeNode *node) { //print, traverse left, traverse right
    if (node == 0) { //node is null
        return;
    }
    else {
        // if (node->left != 0) {
        //     cout << "(";
        // }
        cout << node->data;
        prefix(node->left);
        prefix(node->right);
        // if (node->right != 0) {
        //     cout << ")";
        // }
    }
}

/* Helper function that outputs the postfix notation of the arithmetic expression tree
    by performing the postorder traversal of the tree. */
//reference: https://www.tutorialspoint.com/data_structures_algorithms/tree_traversal.htm
void arithmeticExpression::postfix(TreeNode *node) { //traverse left, traverse right, print
    if (node == 0) { //node is null
        return;
    }
    else {
        // if (node->left != 0) {
        //     cout << "(";
        // }
        postfix(node->left);
        postfix(node->right);
        cout << node->data;
        // if (node->right != 0) {
        //     cout << ")";
        // }
    }
}

/* Helper function for generating the dotty file. This is a recursive function. */
void arithmeticExpression::visualizeTree(ofstream & outFS, TreeNode *n){
    if(n){
        outFS<<n->key << "[ label = \""<<n->data<<"\"];"<<endl;
        if(n->left){
            visualizeTree(outFS,n->left);
            outFS<<n->key <<" -> " <<n->left->key<<";"<<endl;    
        }
        
        if(n->right){
            visualizeTree(outFS,n->right);
            outFS<<n->key <<" -> " <<n->right->key<<";"<<endl;    
        }
    }
}