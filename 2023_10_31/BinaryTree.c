#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode
{
    char data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
}TreeNode;

void createTree(TreeNode** tree,char* data,int* index){

    char ch;
    ch = data[*index];
    *index += 1;
    if(ch == '#'){
        *tree = NULL;
    }
    else{    
        *tree = (TreeNode*)malloc(sizeof(TreeNode));
        (*tree)->data = ch;
        createTree(&((*tree)->lchild),data,index);
        createTree(&((*tree)->rchild),data,index);
    }
}

void preOrder(TreeNode* tree){
    if(tree == NULL){
        return;
    }
    else{
        printf("%c ",tree->data);
        preOrder(tree->lchild);
        preOrder(tree->rchild);
    }

}

void inOrder(TreeNode* tree){
    if(tree == NULL){
        return;
    }
    else{
        inOrder(tree->lchild);
        printf("%c ",tree->data);
        inOrder(tree->rchild);
    }

}

void postOrder(TreeNode* tree){
    if(tree == NULL){
        return;
    }
    else{
        postOrder(tree->lchild);
        postOrder(tree->rchild);
        printf("%c ",tree->data);
    }
    
}

int main(int argc,char* argv[]){
    TreeNode* tree;
    int index = 0;
    createTree(&tree,"AB##C##",&index);
    preOrder(tree);
    printf("\n");
    inOrder(tree);
    printf("\n");
    postOrder(tree);
    printf("\n");
    return 0;
}