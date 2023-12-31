#include<stdio.h>
#include<stdlib.h>

typedef struct String
{
    char* data;
    int len;
}String;

String* initString() {
    String* s = (String*)malloc(sizeof(String));
    s->data = NULL;
    s->len = 0;
    return s;
}

String* StringAssign(String* s,char* data){
    if(s->data){
        free(s->data);
    }
    int len = 0;
    char* temp = data;
    while(*temp){
        len++;
        temp++;
    }
    if(len == 0){
        s->data = NULL;
        s->len = 0;
    }
    else{
        temp = data;
        s->len = len;
        s->data = (char*)malloc(sizeof(char)*(len + 1));
        for(int i = 0; i < len; i++,temp++){
            s->data[i] = *temp;
        }
    }

}

void PrintString(String* s){
    if(s->data != NULL && s->len != 0){
        for(int i = 0; i < s->len; i++){
        printf(i == 0 ? "%c " : "-> %c ", s->data[i]);
        }
        printf("\n");
    }
    else{
        return;
    }
}

int* getNext(String* s){
    int* next = (int*)malloc(sizeof(int)*(s->len));
    int i = 0;
    int j = -1;
    next[i] = j;
    while(i<s->len-1){
        if(j==-1||next[i] == next[j]){
            i++;
            j++;
            next[i] = j;
        }
        else{
            j = next[j];
        }
    }
    return next;
}

void KMPMatch(String* master,String* sub,int* next){
    int i = 0;
    int j = 0;
    while(i<master->len&&j<sub->len){
        if(j==-1||master->data[i] == sub->data[j]){
            i++;
            j++;
        }
        else{
            j = next[j];
        }
    }
    if(j == sub->len){
        printf("KMP SUCCESS\n");
    }
    else{
        printf("KMP FAIL\n");
    }
}

int main(int argc,char* argv[]){
    String* master = initString();
    String* sub = initString();
    StringAssign(master,"ABACCABABD");
    StringAssign(sub,"ABD");
    int* next = getNext(sub);
    KMPMatch(master,sub,next);
    
    return 0;
}