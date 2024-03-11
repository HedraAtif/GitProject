#include <iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};
node* head = NULL;

void InsertToEnd(int value)
{
    node* new_node = new node;
    new_node->data = value ;
    new_node->next = NULL ;

    if (head == NULL)
    {
        head = new_node ;
    }
    else
    {
        node* last = head ;
        while(last->next != NULL)
        {
            last = last->next ;
        }
        last->next = new_node ;
    }
}
void Display()
{
    if (head==NULL)
    {
        cout<<"The linked list is empty .\n" ;
    }
    else
    {
        node* current = head;
        while(current != NULL)
        {
            cout<<current->data<<"\t";
            current = current->next;
        }
        cout<<endl;
    }
}
void DeleteNode(int value)
{
    node* current = head,* previous = head ;

    if (current->data ==value)
    {
        head = current->next ;
        free(current);
        return;
    }
    while (current != NULL && current->data != value)
    {
        previous = current;
        current = current-> next;
    }
    if (current == NULL)
        return ;
    previous->next = current->next;
    free(current);
}
void InsertToBeg(int value)
{
    node* new_node = new node;
    new_node->data = value;
    new_node->next = head;
    head = new_node;
}
void DeleteFromBeg()
{
    if(head==NULL)
        cout<<"The linked list is empty .\n";
    else
    {
        node* first_node = head;
        head = first_node->next;
        delete(first_node);
    }
}
void DeleteFromEnd()
{
    if (head==NULL)
    {
        cout<<"The linked list is empty .\n" ;
        return ;
    }
    else if(head->next == NULL)
    {
        delete(head);
        head = NULL;
        return ;
    }
    else
    {
        node* current = head ,* previous = head;
        while(current->next != NULL)
        {
            previous = current;
            current = current->next;
        }
        previous->next = NULL;
        delete(current);
    }
}
int main()
{
    InsertToEnd(51);
    InsertToEnd(50);
    InsertToEnd(22);
    InsertToEnd(79);
    Display();
    DeleteNode(51);
    Display();
    DeleteNode(79);
    DeleteNode(74);
    Display();
    InsertToBeg(101);
    Display();
    DeleteFromBeg();
    Display();
    DeleteFromEnd();
    Display();

    return 0;
}
