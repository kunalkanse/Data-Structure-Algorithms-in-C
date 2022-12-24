
#include<stdio.h>
#include<stdlib.h>

// This program demonstrate the implementation of the DOUBLY CIRCULAR LINKED LIST.
// CUI (command user interface) Application
// menu driven code for DOUBLY CIRCULAR LINKED LIST



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//--------------------------------------------------------
// Structure Decleration
//--------------------------------------------------------
//////////////////////////////////////////////////////////


typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;

} NODE, *PNODE, **PPNODE;

/*----------------------------------------------------------
 Old Name               New Name
 ----------------------------------------------------------
 struct Node            NODE
 struct Node *          PNODE
 struct Node **         PPNODE
 ----------------------------------------------------------*/

/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//--------------------------------------------------------
// Function Decleration
//_____________________________________________________________*/

void Display(PNODE Head, PNODE Tail);
int Count(PNODE Head, PNODE Tail);

void insertFirst(PPNODE Head, PPNODE Tail, int no);
void insertLast(PPNODE Head, PPNODE Tail,int no);
void insertAtPos(PPNODE Head, PPNODE Tail,int no, int iPos);

void deleteFirst(PPNODE Head , PPNODE Tail);
void deleteLast(PPNODE Head , PPNODE Tail);
void deleteAtPos(PPNODE Head , PPNODE Tail, int iPos);

//_____________________________________________________________*/


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//---------------------------------------------------------------
// Function Definations
//---------------------------------------------------------------
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------
// Function name : Display
// Description : Used to display List of elements
// Parameters : First pointer , Last Pointer
// Return Value : void
//-----------------------------------------------------------------
///////////////////////////////////////////////////////////////////

void Display(PNODE Head, PNODE Tail)
{
    PNODE temp = Head;

    

    if((Head != NULL) && (Tail != NULL))
    {
        do
        {
            printf("|%d|%d|%d| -> ", temp->prev, temp->data, temp->next);
            temp = temp->next;

        } while (temp != (Tail->next));
    }
    else
    {
        printf("NULL");
        return;
    }

    printf("NULL\n");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------
// Function name : Count
// Description : Used to count elements of Linked List
// Parameters : First pointer , Last pointer
// Return Value : int
//-----------------------------------------------------------------
///////////////////////////////////////////////////////////////////

int Count(PNODE Head, PNODE Tail)
{

    PNODE temp = Head;
    int iCnt = 0;

    if((Head != NULL) && (Tail != NULL))
    {
        do
        {
            iCnt++;
            temp = temp->next;
        }while(temp != (Tail->next));
    }

    return iCnt;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------
// Function name : InsertFirst
// Description : Used to insert at first position of Linked List
// Parameters : Addreas of First pointer , last pointer & data of node
// Return Value : void
//-----------------------------------------------------------------
///////////////////////////////////////////////////////////////////

void insertFirst(PPNODE Head, PPNODE Tail, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if ((*Head == NULL) && (*Tail == NULL))
    {
        *Head = newn;
        *Tail = newn;
    }
    else
    {
        newn->next = *Head;
        (*Head)->prev = newn;

        *Head = newn;
    }

    (*Head)->prev = *Tail;
    (*Tail)->next = *Head;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------
// Function name : InsertLast
// Description : Used to insert at last position of Linked List
// Parameters : Addreas of First pointer , last pointer & data of node
// Return Value : void
//-----------------------------------------------------------------
///////////////////////////////////////////////////////////////////

void insertLast(PPNODE Head, PPNODE Tail, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if ((*Head == NULL) && (*Tail == NULL))
    {
        printf("\ninside if\n");
        *Head = newn;
        *Tail = newn;
    }
    else
    {
        (*Tail)->next = newn;
        newn->prev = *Tail;

        *Tail = newn;
    }

    (*Head)->prev = *Tail;
    (*Tail)->next = *Head;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------
// Function name : insertAtPos
// Description : Used to insert element at given positions of Linked List
// Parameters : Addreas of First pointer , last pointer ,  position of insertion ,data of node 
// Return Value : void
//-----------------------------------------------------------------
///////////////////////////////////////////////////////////////////

void insertAtPos(PPNODE Head, PPNODE Tail, int iPos,int no)
{
    int size = Count(*Head , *Tail);

    if((iPos < 1) || (iPos > (size+1)))
    {
        printf("Invalid position");
        return;
    }

    if(iPos == 1)
    {
        insertFirst(Head,Tail,no);
    }
    else if(iPos == (size+1))
    {
        insertLast(Head , Tail , no);
    }
    else
    {
        PNODE newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        PNODE temp = *Head;

        for(int i = 1 ; i < (iPos-1) ; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------
// Function name : deleteFirst
// Description : Used to delete first element of Linked List
// Parameters : Addreas of First pointer , last pointer
// Return Value : void
//-----------------------------------------------------------------
///////////////////////////////////////////////////////////////////

void deleteFirst(PPNODE Head, PPNODE Tail)
{
    if ((*Head != NULL) && (*Tail != NULL))
    {
        if ((*Head)->next == NULL)
        {
            free(*Head);
            *Head = NULL;
            *Tail = NULL;
        }
        else
        {
            *Head = (*Head)->next;
            free((*Tail)->next);
        }

        (*Head)->prev = *Tail;
        (*Tail)->next = *Head;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------
// Function name : deleteLast
// Description : Used to delete last element of Linked List
// Parameters : Addreas of First pointer , last pointer
// Return Value : void
//-----------------------------------------------------------------
///////////////////////////////////////////////////////////////////

void deleteLast(PPNODE Head, PPNODE Tail)
{
    if ((*Head != NULL) && (*Tail != NULL))
    {
        if ((*Head)->next == NULL)
        {
            free(*Head);
            *Head = NULL;
            *Tail = NULL;
        }
        else
        {
            *Tail = (*Tail)->prev;
            free((*Tail)->next);
        }

        (*Head)->prev = *Tail;
        (*Tail)->next = *Head;
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------
// Function name : deleteAtPos
// Description : Used to delete element at given position of Linked List
// Parameters : Addreas of First element , last pointer , position of element
// Return Value : void
//-----------------------------------------------------------------
///////////////////////////////////////////////////////////////////

void deleteAtPos(PPNODE Head , PPNODE Tail , int iPos)
{
    int size = Count(*Head , *Tail);

    if((iPos < 1) || (iPos > (size)))
    {
        printf("Invalid position");
        return;
    }

    if(iPos == 1)
    {
        deleteFirst(Head,Tail);
    }
    else if(iPos == (size+1))
    {
        deleteLast(Head , Tail);
    }
    else
    {
        
        PNODE temp = *Head;

        for(int i = 1 ; i < (iPos-1) ; i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        
        free(temp->next->prev);

        temp->next->prev = temp;
    }
}
//***********************************************************************************************************************************
//***********************************************************************************************************************************


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------
// Function name : Main Function
// Description : Menu driven , Used for function calls
//-----------------------------------------------------------------
///////////////////////////////////////////////////////////////////

int main()
{
    PNODE first = NULL;
    PNODE last = NULL; 

    int iChoice = 1, iPos = 0, iRet = 0;
    int iData = 0;

    while(iChoice != 0)
    {
        printf("\n-----------------------------------------------------------\n");
        printf("\nEnter the desired operation to perform on linked list : \n");
        printf("\n1 : insert the node at first position\n");
        printf("2 : insert the node at last position\n");
        printf("3 : insert the node at desired position\n");
        printf("\n4 : delete the first node\n");
        printf("5 : delete the last node\n");
        printf("6 : delete the node of desired position\n");
        printf("\n7 : display the content of linked list\n");
        printf("8 : count he number of elements present in list\n");
        printf("0 : terminate the application\n");
        printf("\n-----------------------------------------------------------\n");


        printf("\nEnte the choice : ");
        scanf("%d",&iChoice);

        switch(iChoice)
        {
            case 1:
                printf("Enter the data to insert : ");
                scanf("%d",&iData);

                insertFirst(&first , &last , iData);
                break;

            case 2:
                printf("Enter the data to insert : ");
                scanf("%d",&iData);

                insertLast(&first , &last , iData);
                break;

            case 3:
                printf("Enter the position : ");
                scanf("%d",&iPos);

                printf("Enter the data to insert : ");
                scanf("%d",&iData);

                insertAtPos(&first , &last , iPos , iData);

                break;

            case 4:
                deleteFirst(&first, &last);
                break;

            case 5:
                deleteLast(&first, &last);
                break;

            case 6:
                printf("Enter the position : ");
                scanf("%d",&iPos);

                deleteAtPos(&first , &last , iPos);
                break;

            case 7:
                Display(first ,last);
                break;

            case 8:
                iRet = Count(first , last);
                printf("\nList contains %d elements\n",iRet);

                break;

            case 0:
                printf("\n--------------------------------------------------\n");
                printf("Thank you for using Application.......!!!!!");
                printf("\n--------------------------------------------------\n");

                break;

            default:
                printf("\n--------------------------------------------------\n");
                printf("Enter the proper choice");
                printf("\n--------------------------------------------------\n");
                
                break;

        } 

    }

    return 0;
    
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
