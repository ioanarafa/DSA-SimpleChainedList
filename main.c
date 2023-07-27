#include <stdio.h>
#include <stdlib.h>
//inset last, insert first, insert after
//delete last, delete first, delete key


typedef struct node{  //am facut continutul nodului

    int key;
    struct node* next;

}nodeT;

//cream un nod in lista cu keye data
nodeT* create(int givenkey){
    nodeT* p = (nodeT*)malloc(sizeof(nodeT));
    p->key = givenkey;
    p->next = NULL;
    return p;
}

//afisare lista
void afisare(nodeT* first){
    nodeT* p =first;
    while(p != NULL)
    {
        printf("%d ", p->key);
        p = p->next ;
    }
    printf("\n");
}

void insert_first(int givenKey, nodeT** first, nodeT** last )
{
   nodeT* p = create(givenKey);

   if(*first == NULL){
    *first = p;
    *last = p;
   }
   else
   {
       p->next = (*first);
       (*first)= p;
   }
}

void insert_last(int givenkey, nodeT** first, nodeT** last)
{
    nodeT* p = create(givenkey);
    if(*first == NULL)
    {
        *first = p;
        *last = p;
    }
    else
    {
        (*last)->next = p;
        (*last) = p;
    }

}

void insert_after(int givenkey, nodeT** first, nodeT** last, int afterkey )
{
    nodeT* p = create(givenkey); //nodul care se insereaza dupa nodul afterkey
    nodeT* q = *first; //nodul afterkey pe care il caut
    while(q !=NULL)
    {
        if (q->key == afterkey) break;
        else q = q->next;
    }
    if( q !=NULL)
    {
        p -> next = q->next;
        q->next = p;
        if ( q == *last) *last = p;
    }

}

void delete_first(nodeT** first, nodeT** last)
{
    nodeT* p = *first;
    if (p != NULL)
    {
        *first = p->next;
        free(p);

        if(*first == NULL) *last =NULL;
    }


}
void delete_last(nodeT** first, nodeT** last)
{
    nodeT* p = *first;
    if( *first == *last)
    {
        *first = NULL;
        *last = NULL;
    }

    if( p !=NULL)
    {
        while( p->next != *last)
        {
            p = p->next;
        }
        *last = p;
        p->next = NULL;
    }
}

void deleteKey(int givenkey, nodeT** first, nodeT** last)
{
    nodeT* p = *first;
    nodeT* q = NULL;

    if( (*first)->key == givenkey ) delete_first(&first,&last);
    if( (*last)->key == givenkey ) delete_last(&first,&last);

    while( p->next->key != givenkey)
    {
        p= p->next;
    }
    if( p->next != NULL)
    {
        q = p->next;
        p->next = q->next;
        q->next = NULL;
        //free(q);
    }

}


int main()
{
    nodeT* first =NULL;
    nodeT* last =NULL;

    insert_first(3, &first, &last);
    insert_first(1, &first, &last);
    insert_first(8, &first, &last);
    afisare(first);

    insert_last(10, &first, &last);
    insert_last(5, &first, &last);
    insert_last(9, &first, &last);
    afisare(first);

    insert_after(4, &first, &last, 10);
    afisare(first);

    delete_first(&first, &last);
    afisare(first);

    delete_last(&first, &last);
    afisare(first);

    deleteKey(3, &first, &last);
    afisare(first);
    return 0;
}
