#include<iostream>
#include<string>
#include<fstream>
#include "compression.h"

#define LEAF 0
#define INTERNAL 1

typedef struct node{
    char x;
    int freq;
    char* code;
    int type;
    struct node* next;
    struct node* left;
    struct node* right;
}node;

node *HEAD, *ROOT;

void printll();
void makeTree();
void genCode(node* p, char* code);
void insert(node* p, node *m);
void addSymbol(char c);
void writeHeader(FILE *f);
void writeBit(int b, FILE *f);
void writeCode(char c, FILE *f);
char *getCode(char ch);

node *newNode(char c){
    node *temp;
    temp = new node;
    temp->x=c;
    temp->type=LEAF;
    temp->freq=1;
    temp->next=NULL;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

int main(int argc, char **argv){
    
}