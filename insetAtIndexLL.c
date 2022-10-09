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

void insertIndex(int index , int value){
    // index += 1;
    struct Node* temp , *ptr;
    int i = 0;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    ptr = first;
    if (index == 1)
    {
        temp->next = first;
        first = temp;
    }
    else{
        for (int i = 2; i < index; i++)
        {
            ptr = ptr->next;
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }
}

int main(){
    printf("Insert At Index In Linked List\n");
    int arr[] = {10,20,30,40,50};
    create(arr , 5);
    insertIndex(2,567);
    display(first);   
}