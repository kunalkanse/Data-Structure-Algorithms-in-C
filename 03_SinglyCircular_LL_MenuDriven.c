
#include <stdio.h>
#include <stdlib.h>

// This program demonstrate the implementation of the SINGLY CIRCULAR LINKED LIST.
// CUI (command user interface) Application
// menu driven code for SINGLY CIRCULAR LINKED LIST

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//--------------------------------------------------------
// Structure Decleration
//--------------------------------------------------------
//////////////////////////////////////////////////////////

typedef struct node
{
    int data;
    struct node *next;

} NODE, *PNODE, **PPNODE;

/*----------------------------------------------------------
 Old Name               New Name
 ----------------------------------------------------------
 struct Node            NODE
 struct Node *          PNODE
 struct Node **         PPNODE
 ----------------------------------------------------------*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//--------------------------------------------------------
// Function Decleration
//_____________________________________________________________*/

void Display(PNODE Head, PNODE Tail);
int Count(PNODE Head, PNODE Tail);

void insertFirst(PPNODE Head, PPNODE Tail, int no);
void insertLast(PPNODE Head, PPNODE Tail, int no);
void insertAtPos(PPNODE Head, PPNODE Tail, int iPos, int no);

void deleteFirst(PPNODE Head, PPNODE Tail);
void deleteLast(PPNODE Head, PPNODE Tail);
void deleteAtPos(PPNODE Head, PPNODE Tail, int iPos);

//_____________________________________________________________*/

//---------------------------------------------------------------
// Function Definations
//---------------------------------------------------------------
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------
// Function name : Display
// Description : Used to display List of elements
// Parameters : First pointer , Last Pointer
// Return Value : void
//-----------------------------------------------------------------
///////////////////////////////////////////////////////////////////

void Display(PNODE Head, PNODE Tail)
{
    if ((Head == NULL) && (Tail == NULL))
    {
        printf("\nNULL\n");
        return;
    }

    do
    {
        printf("|%d|->", (Head->data));
        Head = Head->next;
    } while ((Head != (Tail->next)));

    printf("NULL\n");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------
// Function name : Count
// Description : Used to count elements of Linked List
// Parameters : First pointer , Last pointer
// Return Value : int
//-----------------------------------------------------------------
///////////////////////////////////////////////////////////////////

int Count(PNODE Head, PNODE Tail)
{
    int iCnt = 0;

    if ((Head == NULL) && (Tail == NULL))
    {
        return 0;
    }

    do
    {
        iCnt++;
        Head = Head->next;
    } while ((Head != (Tail->next)));

    return iCnt;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------
// Function name : InsertFirst
// Description : Used to insert at first position of Linked List
// Parameters :  First pointer , last pointer & data of node
// Return Value : void
//-----------------------------------------------------------------
///////////////////////////////////////////////////////////////////

void insertFirst(PPNODE Head, PPNODE Tail, int no)
{
    PNODE newn = NULL;

    // new node created
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if ((*Head == NULL) && (*Tail == NULL)) // if List is empty
    {
        *Head = newn;
        *Tail = newn;
    }
    else
    {
        newn->next = *Head;
        *Head = newn;
    }
    (*Tail)->next = newn; // to maintain circular nature
    // common for if & else
    // most important
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------
// Function name : InsertLast
// Description : Used to insert at last position of Linked List
// Parameters : First pointer , last pointer & data of node
// Return Value : void
//-----------------------------------------------------------------
///////////////////////////////////////////////////////////////////

void insertLast(PPNODE Head, PPNODE Tail, int no)
{
    PNODE newn = NULL;

    // new node created
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if ((*Head == NULL) && (*Tail == NULL)) // if List is empty
    {
        *Head = newn;
        *Tail = newn;
    }
    else
    {
        (*Tail)->next = newn;
        *Tail = newn;
    }
    (*Tail)->next = *Head; // To mainatain circular nature
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------
// Function name : insertAtPos
// Description : Used to insert element at given positions of Linked List
// Parameters :  First pointer , last pointer ,  position of insertion ,data of node
// Return Value : void
//-----------------------------------------------------------------
///////////////////////////////////////////////////////////////////

void insertAtPos(PPNODE Head, PPNODE Tail, int pos, int no)
{
    int size = 0;

    size = Count(*Head, *Tail);

    if ((pos < 1) || (pos > (size + 1)))
    {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1)
    {
        insertFirst(Head, Tail, no);
    }
    else if (pos == (size + 1))
    {
        insertLast(Head, Tail, no);
    }
    else
    {
        PNODE newn = NULL;

        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
        newn->next = NULL;

        PNODE temp = *Head;

        for (int iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------
// Function name : deleteFirst
// Description : Used to delete first element of Linked List
// Parameters :  First pointer, last pointer
// Return Value : void
//-----------------------------------------------------------------
///////////////////////////////////////////////////////////////////

void deleteFirst(PPNODE Head, PPNODE Tail)
{
    if ((*Head == NULL) && (*Tail == NULL))
    {
        return;
    }
    else if (*Head == *Tail)
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else
    {
        *Head = (*Head)->next;
        free((*Tail)->next);
        (*Tail)->next = *Head;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------
// Function name : deleteLast
// Description : Used to delete last element of Linked List
// Parameters :  First pointer , last pointer
// Return Value : void
//-----------------------------------------------------------------
///////////////////////////////////////////////////////////////////

void deleteLast(PPNODE Head, PPNODE Tail)
{
    PNODE temp = NULL;
    temp = *Head;

    if ((*Head == NULL) && (*Tail == NULL))
    {
        return;
    }
    else if (*Head == *Tail)
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else
    {
        while (((temp->next) != (*Tail)))
        {
            temp = temp->next;
        }

        free(*Tail);
        *Tail = temp;
        (*Tail)->next = *Head;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------
// Function name : deleteAtPos
// Description : Used to delete element at given position of Linked List
// Parameters :  First element , last pointer, position of element
// Return Value : void
//-----------------------------------------------------------------
///////////////////////////////////////////////////////////////////

void deleteAtPos(PPNODE Head, PPNODE Tail, int pos)
{
    int size = 0;

    size = Count(*Head, *Tail); // number of elements

    if ((pos < 1) || (pos > size))
    {
        printf("invalid position");
        return;
    }

    if (pos == 1) // for first position
    {
        deleteFirst(Head, Tail);
    }
    else if (pos == (size)) // for last position
    {
        deleteLast(Head, Tail);
    }
    else // position is in between first & last position
    {
        PNODE temp = *Head;
        PNODE targeted = NULL;

        for (int iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        targeted = temp->next;
        temp->next = temp->next->next;
        free(targeted);
    }
}

//****************************************************************************************************************************************
//****************************************************************************************************************************************




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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

    while (iChoice != 0)
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
        scanf("%d", &iChoice);

        switch (iChoice)
        {
        case 1:
            printf("Enter the data to insert : ");
            scanf("%d", &iData);

            insertFirst(&first, &last, iData);
            break;

        case 2:
            printf("Enter the data to insert : ");
            scanf("%d", &iData);

            insertLast(&first, &last, iData);
            break;

        case 3:
            printf("Enter the position : ");
            scanf("%d", &iPos);

            printf("Enter the data to insert : ");
            scanf("%d", &iData);

            insertAtPos(&first, &last, iPos, iData);

            break;

        case 4:
            deleteFirst(&first, &last);
            break;

        case 5:
            deleteLast(&first, &last);
            break;

        case 6:
            printf("Enter the position : ");
            scanf("%d", &iPos);

            deleteAtPos(&first, &last, iPos);
            break;

        case 7:
            Display(first, last);
            break;

        case 8:
            iRet = Count(first, last);
            printf("\nList contains %d elements\n", iRet);

            break;

        case 0:
            printf("\n--------------------------------------------------\n");
            printf("Thank you for using Application.......!!!!!");
            printf("\n--------------------------------------------------\n");

            break;

        default:
            printf("\n--------------------------------------------------\n");
            printf("Wrong Choice\nEnter the proper choice........");
            printf("\n--------------------------------------------------\n");

            break;
        }
    }

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
