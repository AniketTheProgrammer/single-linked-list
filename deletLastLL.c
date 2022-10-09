#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
}*first;

void create(int arr[] , int size){
    struct Node *temp , *last;
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < size; i++)
    {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = arr[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }  
}

void display(struct Node* p){
    while (p!=NULL)
    {
        printf("%d\n" , p->data);
        p = p->next;
    }
}

void deleteLast(){
    struct Node* temp , *last;
    temp = (struct Node*)malloc(sizeof(struct Node));
    last = first;
    while (last->next!=NULL)
    {
        temp = last;
        last = last->next;
    }
    temp->next = NULL;
    free(last);
}

int main(){
    printf("Delete At Last Linked List\n");
    int arr[] = {10,20,30,40,50};
    create(arr , 5);
    // deleteLast();
    display(first);   
}