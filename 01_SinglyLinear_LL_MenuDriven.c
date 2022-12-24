
#include<stdio.h>
#include<stdlib.h>

// This program demonstrate the implementation of the SINGLY LINEAR LINKED LIST.
// CUI (command user interface) Application
// menu driven code for SINGLY LINEAR LINKED LIST


/*/////////////////////////////////////////////////////////////////////////////////////////////////////
//--------------------------------------------------------
// Structure Decleration
//--------------------------------------------------------
*/

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
 ----------------------------------------------------------
 
 // another systax for typedef
 
 // typedef struct node NODE;
 // typedef struct node * PNODE;
 // typedef struct node ** PPNODE;
*/
//_________________________________________________________________________________________________________


/*//////////////////////////////////////////////////////////////////////////////////////////////////////////
//--------------------------------------------------------
// Function Decleration
//_____________________________________________________________*/

void Display(PNODE Head);
int Count(PNODE Head);

void insertFirst(PPNODE Head , int no);
void insertLast(PPNODE Head , int no);
void insertAtPos(PPNODE , int no , int pos);

void deleteFirst(PPNODE Head);
void deleteLast(PPNODE Head);
void deleteAtPos(PPNODE Head , int pos);

//____________________________________________________________________________________________________________


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------
// Function Definations
//---------------------------------------------------------------
///////////////////////////////////////////////////////////////////



//-----------------------------------------------------------------
// Function name : Display
// Description : Used to display Linked List 
// Parameters : First pointer
// Return Value : void
//-----------------------------------------------------------------
///////////////////////////////////////////////////////////////////

void Display(PNODE Head)
{
    while (Head != NULL)
    {
        printf("|%d|->", Head->data);
        Head = Head->next;
    }

    printf("\nNULL\n");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------
// Function name : Count
// Description : Used to count elements of Linked List
// Parameters : First pointer
// Return Value : int
//-----------------------------------------------------------------
///////////////////////////////////////////////////////////////////

int Count(PNODE Head)
{
    int iCnt = 0;

    while (Head != NULL)
    {
        iCnt++;
        Head = Head->next;
    }

    return iCnt;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------
// Function name : InsertFirst
// Description : Used to insert at first position of Linked List
// Parameters : First pointer , data of node
// Return Value : void
//-----------------------------------------------------------------
///////////////////////////////////////////////////////////////////

void insertFirst(PPNODE Head, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if (*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn->next = *Head;
        *Head = newn;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------
// Function name : InsertLast
// Description : Used to insert at last position of Linked List
// Parameters : First pointer , data of node
// Return Value : void
//-----------------------------------------------------------------
///////////////////////////////////////////////////////////////////

void insertLast(PPNODE Head, int no)
{
    PNODE newn = NULL;
    PNODE temp = *Head;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if (*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------
// Function name : insertAtPos
// Description : Used to insert element at given positions of Linked List
// Parameters : First pointer ,  position of insertion ,data of node 
// Return Value : void
//-----------------------------------------------------------------
///////////////////////////////////////////////////////////////////

void insertAtPos(PPNODE Head, int iPos, int no)
{

    int size = 0;

    size = Count(*Head); // number of elements

    if ((iPos < 1) || (iPos > size + 1))
    {
        printf("invalid position");
        return;
    }

    if (iPos == 1) // for first position
    {
        insertFirst(Head, no);
    }
    else if (iPos == (size + 1)) // for last position
    {
        insertLast(Head, no);
    }
    else // position is in between first & last position
    {
        PNODE newn = NULL;
        PNODE temp = *Head;

        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
        newn->next = NULL;

        for (int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------
// Function name : deleteFirst
// Description : Used to delete first element of Linked List
// Parameters : Addreas of First pointer
// Return Value : void
//-----------------------------------------------------------------
///////////////////////////////////////////////////////////////////

void deleteFirst(PPNODE Head)
{
    PNODE temp = *Head;

    if (*Head != NULL)
    {
        *Head = (*Head)->next;
        free(temp);
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------
// Function name : deleteLast
// Description : Used to delete last element of Linked List
// Parameters : Addreas of First pointer
// Return Value : void
//-----------------------------------------------------------------
///////////////////////////////////////////////////////////////////

void deleteLast(PPNODE Head)
{
    PNODE temp = *Head;

    if (*Head == NULL)
    {
        return;
    }
    else if ((*Head)->next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        while ((temp->next->next) != NULL)
        {
            temp = temp->next;
        }

        free(temp->next);
        temp->next = NULL;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------
// Function name : deleteAtPos
// Description : Used to delete element at given position of Linked List
// Parameters : Addreas of First element , position of element
// Return Value : void
//-----------------------------------------------------------------
///////////////////////////////////////////////////////////////////

void deleteAtPos(PPNODE Head, int iPos)
{

    int size = 0;

    size = Count(*Head); // number of elements

    if ((iPos < 1) || (iPos > size))
    {
        printf("invalid position");
        return;
    }

    if (iPos == 1) // for first position
    {
        deleteFirst(Head);
    }
    else if (iPos == (size + 1)) // for last position
    {
        deleteLast(Head);
    }
    else // position is in between first & last position
    {
        PNODE temp = *Head;
        PNODE targeted = NULL;

        for (int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }

        targeted = temp->next;
        temp->next = temp->next->next;
        free(targeted);
    }
}
//**********************************************************************************************************
//**********************************************************************************************************


///////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------
// Function name : Main Function
// Description : Menu driven , Used for function calls
//-----------------------------------------------------------------
///////////////////////////////////////////////////////////////////

int main()
{
    PNODE first = NULL;
    int iChoice = 1, iNum = 0, iRet = 0, iPos = 0;

    while (iChoice != 0)
    {
        printf("\n_____________________________________________________________\n");
        printf("\nEnter the desired operation to perform on linked list\n");
        printf("\n1 : insert the node at first position\n");
        printf("2 : insert the node at last position\n");
        printf("3 : insert the node at desired position\n");
        printf("\n4 : delete the first node\n");
        printf("5 : delete the last node\n");
        printf("6 : delete the node of desired position\n");
        printf("\n7 : display the content of linked list\n");
        printf("8 : count he number of elements present in list\n");
        printf("0 : terminate the application\n");
        printf("\n____________________________________________________________\n");

        printf("\nEnte the choice : ");
        scanf("%d", &iChoice);

        switch (iChoice)
        {
        case 1:
            printf("Enter the data to insert : ");
            scanf("%d", &iNum);

            insertFirst(&first, iNum);
            break;

        case 2:
            printf("Enter the data to insert : ");
            scanf("%d", &iNum);

            insertLast(&first, iNum);
            break;

        case 3:
            printf("Enter the position : ");
            scanf("%d", &iPos);

            printf("Enter the data to insert : ");
            scanf("%d", &iNum);


            insertAtPos(&first, iPos, iNum);

            break;

        case 4:
            deleteFirst(&first);
            break;

        case 5:
            deleteLast(&first);
            break;

        case 6:
            printf("Enter the position : ");
            scanf("%d", &iPos);

            deleteAtPos(&first, iPos);
            break;

        case 7:
            Display(first);
            break;

        case 8:
            iRet = Count(first);
            printf("\nLinked List contains %d elements\n", iRet);

            break;

        case 0:

            printf("\nThank you for using our application.......!!!!!\n");

            break;

        default:
            printf("\nEnter the proper choice..!!!!!!!!\n");

            break;
        }
    }

    return 0;
}
