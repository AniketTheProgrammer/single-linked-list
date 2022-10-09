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

void deleteFirst(){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp = first;
    first = first->next;
    free(temp);
}

int main(){
    printf("Delete At First Linked List\n");
    int arr[] = {10,20,30,40,50};
    create(arr , 5);
    // deleteFirst();
    display(first);   
}