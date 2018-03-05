//Brendon Lyra
//writing a linked list in C, with simple functions to manipulate it.


#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node* next;
} Node;


void menu();
void init(Node**, int);
void print_list(Node*);
void delete_list(Node**);
void add_node_to_end(Node**);
void delete_last_node(Node**);
void delete_specific_node(Node**);


int main()
{
    menu();

    return 0;
}

void menu(){

    Node* head = NULL;

    int input = -1;

    while (input != 0){ //infinite loop, until input 0 for quit is received.

        printf("\n\n0 = quit program.\n");
        printf("1 = add node to end (input data requested).\n");
        printf("2 = delete the whole list.\n");
        printf("3 = delete last node.\n");
        printf("4 = delete node with certain value (input data required).\n");
        printf("5 = print linked list. \n\n");

        scanf("%d", &input);

        switch (input)
        {
            case 0:
                break; //safely exit program.
            case 1:
                add_node_to_end(&head);
                break;
            case 2:
                delete_list(&head);
                break;
            case 3:
                delete_last_node(&head);
                break;
            case 4:
                delete_specific_node(&head);
                break;
            case 5:
                print_list(head);
                break;
        }
    }

    printf("Final status of Linked List:\n\n");
    print_list(head);
}


void print_list(Node* head)
{

    Node* temp = head;
    printf("\nhead ->");
    while (temp != NULL){
        printf(" %1d ->", temp->data);
        temp = temp->next;
    }
    printf(" NULL\n");
}


//recursively deletes the whole list
void delete_list(Node ** head){

    if (*head == NULL)
        return;

    delete_list((&(*head)->next)); //sending the address of the next node in list.

    (*head) = NULL;
    free(*head);

}


void add_node_to_end(Node** head)
{
    printf("\n what number would you like to put in the list?\n");
    int num;
    scanf("%d", &num);


    if (*head == NULL) //if there was no initial head, make a head node.
        init(head, num);

    else
    {
        Node* temp = *head;

        while (temp->next != NULL)
            temp = temp->next;

        init(&temp->next,num);
    }
}


void delete_specific_node(Node** head)
{
    printf("What number do you want to delete from the list?\n");
    int num;
    scanf("%d", &num);

    Node* temp = *head;
    Node* temp2 = temp;


    if (*head != NULL) //if it is not an empty list
    {
        if ((*head)->data == num) //if head is the value we want to delete
        {
            *head = (*head)->next;
            temp = NULL;
            free(temp);
            printf("Node Found, and deleted.\n");
            return;
        }

        else{
            //else go until the end, or find data.
            while (temp != NULL)
            {
                if (temp->data == num){ //found data
                    temp2->next = temp->next;
                    temp = NULL;
                    free(temp);
                    return;
                }
                temp2 = temp;
                temp = temp->next;
            }
        }

        printf("Data not found. Try another number.\n");
        return;
    }
    printf("List was empty. Can't delete data.\n");
}


void delete_last_node(Node** head){

    if (*head == NULL) //if list empty, do nothing.
        printf("list empty. returning\n");

    else if ((*head)->next == NULL) //if head is the last node
    {
        free((*head));
        (*head) = NULL;
        printf("head successfully deleted.\n");
    }


    else //find last node, and delete it
    {
        Node* temp = *head;
        Node* temp2 = temp;

        while (temp->next != NULL)
        {
            temp2 = temp; //will point to second to last node
            temp = temp->next; //will point to last node
        }

        free(temp);
        temp2->next = NULL;
        printf("successfully deleted last node.\n");
    }

}


void init(Node** head, int num){

    *head = (Node*)malloc(sizeof(Node));

    (*head)->next = NULL;
    (*head)->data = num;
}

