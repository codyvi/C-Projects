#pragma once
#include "NodeT.h"
#include <queue>
#include <stack>

class BST
{
    public:
        BST();
        ~BST();
        void add(int data);
        bool search(int data);
        void remove(int data);
        void print(int x);
        int height();
        int whatLevelamI(int data);
        void ancestors(int data);
        int maxWidth();
        int count();
        int nearstRelative(int num1, int num2);
        bool operator == (const BST& treeB);
    private:
        NodeT *root;
        int howManyChildren(NodeT *r);
        int predecesor(NodeT *r);
        int sucesor(NodeT *r);
        void preOrder(NodeT *r);
        void inOrder(NodeT *r);
        void postOrder(NodeT *r);
        void levelxlevel(NodeT *r);
        void printLeaves(NodeT *r);
        void free(NodeT *r);
        int getHeight(NodeT *r);
        int getWidth(NodeT *r, int data);
        int cuantos(NodeT *r);
        bool compararA(NodeT *a, NodeT *b);
};

BST::BST()
{
    root = NULL;
}

BST::~BST()
{
    free(root);
}

int BST::howManyChildren(NodeT *r)
{
    int c = 0;
    if(r->getLeft() != NULL){
        c++;
    }
    if(r->getRight() != NULL){
        c++;
    }

    return c;
}


bool BST::search(int data)
{
    NodeT *curr = root;
    while(curr != NULL){
        if(curr->getData() == data){
            return true;
        }
        curr = (curr->getData() > data) ?
                curr->getLeft() : curr->getRight();
    }
    return false;
}

int BST::predecesor(NodeT *r){
    NodeT *aux = r->getLeft();

    while(aux->getRight() != NULL)
    {
        aux = aux->getRight();
    }
    return aux->getData();
}

int BST::sucesor(NodeT *r)
{
    NodeT *aux = r->getRight();

    while(aux->getLeft() != NULL)
    {
        aux = aux->getLeft();
    }
    return aux->getData();
}

void BST::preOrder(NodeT *r)
{
    if(r != NULL){
        cout << r->getData() << " ";
        preOrder(r->getLeft());
        preOrder(r->getRight());
    }
}

void BST::inOrder(NodeT *r)
{
    if(r != NULL){
        inOrder(r->getLeft());
        cout << r->getData() << " ";
        inOrder(r->getRight());
    }
}

void BST::postOrder(NodeT *r)
{
    if(r != NULL){
        postOrder(r->getLeft());
        postOrder(r->getRight());
        cout << r->getData() << " ";
    }
}

void BST::free(NodeT *r)
{
    if (r != NULL){
        free(r->getLeft());
        free(r->getRight());
        delete r;
    }
}

void BST::add(int data)
{
    NodeT *father = NULL;
    NodeT *curr = root;

    while(curr != NULL)
    {
        if(curr->getData() == data)
        {
            return;
        }
        father = curr;
        curr = (curr->getData() > data) ?
                curr->getLeft() : curr->getRight();
    }

    if(father == NULL){
        root = new NodeT(data);
    }
    else{
        if(father->getData() > data){
            father->setLeft(new NodeT(data));
        }
        else{
            father->setRight(new NodeT(data));
        }
    }
}

void BST::remove(int data){
    NodeT *curr = root;
    NodeT *father = NULL;

    while(curr != NULL && curr->getData() != data){
        father = curr;
        curr = (curr->getData() > data) ?
                curr->getLeft() : curr->getRight();
    }

    if(curr == NULL){
        return;
    }

    int c = howManyChildren(curr);

    switch(c){
        case 0:
            if(father == NULL){
                root = NULL;
            }
            else{
                if(father->getData() > data){
                    father->setLeft(NULL);
                }
                else{
                    father->setRight(NULL);
                }
            }
            delete curr;
            break;

        case 1:
            if(father == NULL){
                if(curr->getLeft() != NULL){
                    root = curr->getLeft();
                }
                else{
                    root = curr->getRight();
                }
            }
            else{
                if(father->getData() > data){
                    if(curr->getLeft() != NULL){
                        father->setLeft(curr->getLeft());
                    }
                    else{
                        father->setLeft(curr->getRight());
                    }
                }
                else{
                    if(curr->getLeft() != NULL){
                        father->setRight(curr->getLeft());
                    }
                    else{
                        father->setRight(curr->getRight());
                    }

                }
            }
            delete curr;
            break;

        case 2:
            int x = sucesor(curr);
            remove(x);
            curr->setData(x);
            break;
    }
}

void BST::print(int c)
{
    switch(c){
        case 1:
            preOrder(root);
            break;

        case 2:
            inOrder(root);
            break;

        case 3:
            postOrder(root);
            break;
        case 4:
            printLeaves(root);
            break;
        case 5: 
            levelxlevel(root);
            break;
    }
    cout << endl;
}

int BST::getHeight(NodeT *r)
{
    if(r == NULL)
    {
        return 0;
    }

    else
    {
        int leftHeight = getHeight(r->getLeft());
        int rightHeight = getHeight(r->getRight());

        if(leftHeight > rightHeight)
        {
            return (leftHeight + 1);
        }

        else
        {
            return (rightHeight + 1);
        }
    }
}

int BST::height()
{
    return getHeight(root);
}


int BST::whatLevelamI(int data)
{
    NodeT* curr = root;
    int nivel = 0;

    while(curr != NULL)
    {
        if(curr->getData() == data)
        {
            return nivel;
        }

         curr = (curr->getData() > data) ?
                curr->getLeft() : curr->getRight();
                nivel++;
    }

    return -1;
}

void BST::ancestors(int data)
{
    NodeT *curr = root;
    stack<int> nodeStack;

    while(curr != NULL)
    {
        if(curr->getData() == data)
        {

            if(nodeStack.empty())
            {
                cout << "Este dato no tiene ancestros" << endl;
            }
            else
            {
                while(!nodeStack.empty())
                {
                    cout << nodeStack.top() << " ";
                    nodeStack.pop();
                }
                cout << endl;
            }
            return;
    }
    nodeStack.push(curr->getData());
    curr = (curr->getData() > data) ?
                curr->getLeft() : curr->getRight();
    }
    cout << "El dato no esta en el arbol" << endl;
}

void BST::printLeaves(NodeT *r)
{
    if(r != NULL)
    {
        if(r->getLeft() == NULL && r->getRight() == NULL)
        {
            cout << r->getData() << " ";
        }

        else
        {
            printLeaves(r->getLeft());
            printLeaves(r->getRight());
        }
    }
}

void BST::levelxlevel(NodeT *r)
{
    if(r != NULL)
    {
        queue<NodeT *> nodeQueue;
        nodeQueue.push(r);
       
        while(!nodeQueue.empty())
        {
            NodeT *temp = nodeQueue.front();
            nodeQueue.pop();
            cout << temp->getData() << " ";

            if(temp->getLeft())
            {
                nodeQueue.push(temp->getLeft());
            }

            if(temp->getRight())
            {
                nodeQueue.push(temp->getRight());
            }

        }

    }
}

int BST::getWidth(NodeT* r, int data)
{
    if(r == NULL)
    {
        return 0;
    }

    if(data == 1)
    {
        return 1;
    }

    else if(data > 1)
    {
       return getWidth(r->getLeft(), data -1) + getWidth(r->getRight(), data -1);
    }
}

int BST::maxWidth()
{
    int maxW = 0;
    int width;
    int h = getHeight(root);

    for(int i = 1 ; i <= h; i++)
    {
        width = getWidth(root, i);
        if(width > maxW)
        {
            maxW = width;
        }
    }

    return maxW;
}

int BST::count()
{
    return cuantos(root);
}

int BST::cuantos(NodeT *r)
{
    if(r == NULL)
    {
        return 0;
    }

    return 1 + cuantos(r->getLeft()) + cuantos(r->getRight());
}

int BST::nearstRelative(int a, int b)
{
    int mayor = (a>b) ? a : b;
    int menor = (a<b) ? a : b;
    int padre;

    if(root->getData() == mayor || root->getData() == menor)
    {
        cout << "No hay relativo más cercano" << endl;
        return -1;
    }

    NodeT *curr = root;
    
    if(menor > root->getData())
    {
        curr = root->getRight();
    }

    else if(mayor < root->getData())
    {
        curr = root->getLeft();
    }

    while(!(menor < curr->getData() && mayor > curr->getData()))
    {    
        padre = curr->getData();
        if(menor > curr->getData())
        {
            curr = curr->getRight();
        }

        if(mayor < curr->getData())
        {
            curr = curr->getLeft();
        }

        if(menor == curr->getData() || mayor == curr->getData())
        {
            return padre;
        }
    }
    
    return curr->getData();
}

bool BST::compararA(NodeT *a, NodeT *b)
{
    if(a==NULL && b==NULL)
    {
        true;
    } 

    else if(a!=NULL && b!= NULL)
    {
        //cout<< a->getData() << " - " << b->getData() <<endl;
       
        if(a->getData() != b->getData())
        {
            return false;
        } 
        
        else 
        {
            return compararA(a->getLeft(),b->getLeft()) && compararA(a->getRight(),b->getRight());
        }
    }

    else
    {
        return false;
    }
}

bool BST::operator == (const BST& arbolB)
{
    return compararA(this->root,arbolB.root);
}
