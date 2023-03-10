
#include<stdio.h>
#include<stdlib.h>

// This program demonstrate the implementation of the QUEUE.
// CUI (command user interface) Application
// menu driven code for QUEUE.



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//--------------------------------------------------------
// Structure Decleration
//--------------------------------------------------------
//////////////////////////////////////////////////////////

typedef struct node
{
    int data;
    struct node * next;

}NODE , * PNODE , **PPNODE;

/*----------------------------------------------------------
 Old Name               New Name
 ----------------------------------------------------------
 struct Node            NODE
 struct Node *          PNODE
 struct Node **         PPNODE
 ----------------------------------------------------------*/


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//--------------------------------------------------------
// Function Decleration
//_____________________________________________________________*/


void Display(PNODE Head);
int Count(PNODE Head);

void Enqueue(PPNODE Head , PPNODE Tail , int no);
void Dequeue(PPNODE Head , PPNODE Tail);





//---------------------------------------------------------------
// Function Definations
//---------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------
// Function name : Display
// Description : Used to display List of elements
// Parameters : First pointer
// Return Value : void
//-----------------------------------------------------------------
//////////////////////////////////////////////////////////////////


void Display(PNODE Head)
{
    PNODE temp = Head;

    while (temp != NULL)
    {
        printf("|%d|->", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------
// Function name : Count
// Description : Used to count elements of Linked List
// Parameters : First pointer
// Return Value : int
//-----------------------------------------------------------------
///////////////////////////////////////////////////////////////////

int Count(PNODE Head)
{
    PNODE temp = Head;
    int iCnt = 0;

    while (temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }

    return iCnt;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------
// Function name : Enqueue
// Description : Used to insert at last of Linked List
// Parameters : Addreas of First pointer , last pointer & data of node
// Return Value : void
//-----------------------------------------------------------------
///////////////////////////////////////////////////////////////////

void Enqueue(PPNODE Head ,  PPNODE Tail ,int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
        *Tail = newn;
    }
    else
    {
        (*Tail)->next = newn;
        *Tail = newn;
    }

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------
// Function name : Dequeue
// Description : Used to delete first element of Linked List
// Parameters : Addreas of First pointer , last pointer & data of node
// Return Value : void
//-----------------------------------------------------------------
///////////////////////////////////////////////////////////////////

void Dequeue(PPNODE Head , PPNODE Tail)
{
    PNODE temp = *Head;

    if((*Head==NULL) && (*Tail==NULL))
    {
        return;
    }

    if(*Head == *Tail)
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else
    {
        *Head = (*Head)->next;
        free(temp);
    }
    
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


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

    int iRet = 0, iChoice = 1;
    int iData = 0;

    while (iChoice != 0)
    {
        printf("\n------------------------------------------------------------\n");
        printf("Enter the proper choice to perform operations : \n");
        printf("\n 1 : To Enqueue the data\n");
        printf(" 2 : To Dequeue the data\n");
        printf(" 3 : To display data\n");
        printf(" 4 : To Count the elements\n");
        printf(" 0 : To terminate\n");
        printf("\n---------------------------------------------------------------\n");

        printf("\nEnter the choice : ");
        scanf("%d",&iChoice);

        switch (iChoice)
        {
        case 1:
            printf("\nEnter the Data to push : ");
            scanf("%d", &iData);

            Enqueue(&first,&last,iData);
            break;

        case 2:
            Dequeue(&first , &last);
            break;

        case 3:
            Display(first);
            break;

        case 4:
            iRet = Count(first);
            printf("\nCount is : %d\n", iRet);
            break;

        case 0:
            printf("-------------------------------------------------------\n");
            printf("terminating Queue\n");
            printf("-------------------------------------------------------\n");
            break;

        default:
            printf("-------------------------------------------------------\n");
            printf("\nInvalid Choice\nEnter Again...............\n");
            printf("-------------------------------------------------------\n");
            break;
        }
    }

    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
