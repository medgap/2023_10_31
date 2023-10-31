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


typedef struct QueueNode
{
    TreeNode* data;
    struct QueueNode* pre; 
    struct QueueNode* next; 
}QueueNode;


QueueNode* initQueue(){
    QueueNode* q = (QueueNode*)malloc(sizeof(QueueNode));
    q->data = NULL;
    q->pre = q;
    q->next = q;
    return q;
}

int isEmpty(QueueNode* q){
    if(q->next == q)
        return 1;
    return 0;
}

void enQueue(QueueNode* q,TreeNode* data){
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    node->data = data;
    node->pre = q->pre;
    node->next = q;
    q->pre->next = node;
    q->pre = node;

}

QueueNode* deQueue(QueueNode* q){
    if(isEmpty(q)){
        return NULL;
    }
    else{
        QueueNode* node = q->next;
        q->next->next->pre = q;
        q->next = q->next->next;
        return node;
    }
}

void levelTraverse(QueueNode* q, TreeNode* tree){
    enQueue(q,tree);
    while(!isEmpty(q)){
        QueueNode* node = deQueue(q);
        printf("%c",node->data->data);
        if(node->data->lchild){
            enQueue(q,node->data->lchild);
        }
        if(node->data->rchild){
            enQueue(q,node->data->rchild);
        }
    }
}

int main(int argc,char* argv[]){
    TreeNode* tree;
    int index = 0;
    createTree(&tree,"AB##C##",&index);
    QueueNode* q = initQueue();
    levelTraverse(q,tree);
    return 0;
}