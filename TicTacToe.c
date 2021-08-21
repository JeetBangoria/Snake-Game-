#include<stdio.h> 
#include<stdlib.h>

struct Node
{
char sym; 
int counter;
struct Node *next;
};


int main()
{
    int a,b,c,z;
    printf("\t\t\t\tTic Tac Toe Game !!!\n\n"); 
    printf("\t\t\t\tCreated by Jeet Bangoria...\n\n") ; 
    struct Node* head = NULL;
    struct Node* second = NULL; 
    struct Node* third = NULL; 
    struct Node* fourth = NULL; 
    struct Node* fifth = NULL;
    struct Node* sixth = NULL; 
    struct Node* seventh = NULL; 
    struct Node* eight = NULL; 
    struct Node* ninth = NULL; 
    struct Node* tenth = NULL;  
    
    
    //allocated memory space
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node)); 
    third = (struct Node*)malloc(sizeof(struct Node)); 
    fourth = (struct Node*)malloc(sizeof(struct Node));
    fifth = (struct Node*)malloc(sizeof(struct Node)); 
    sixth = (struct Node*)malloc(sizeof(struct Node)); 
    seventh = (struct Node*)malloc(sizeof(struct Node)); 
    eight = (struct Node*)malloc(sizeof(struct Node)); 
    ninth = (struct Node*)malloc(sizeof(struct Node)); 
    tenth = (struct Node*)malloc(sizeof(struct Node));
    
    
    //nodes are allocated to their respective position and created links betIen all nodes
    head->counter = 1; 
    head->sym=' ';
    head->next = second;
    second->counter = 2;
    second->sym=' '; 
    second->next = third;
    third->counter = 3; 
    third->sym=' ';
    third->next = fourth;
    fourth->counter = 4; 
    fourth->sym=' '; 
    fourth->next = fifth;
    fifth->counter = 5; 
    fifth->sym=' '; 
    fifth->next = sixth;
    sixth->counter = 6; 
    sixth->sym=' ';
    sixth->next = seventh;
    seventh->counter = 7; 
    seventh->sym=' '; 
    seventh->next = eight;
    eight->counter = 8; 
    eight->sym=' '; 
    eight->next = ninth;
    ninth->counter = 9; 
    ninth->sym=' '; 
    ninth->next = tenth;
    tenth->next = NULL;


    //displays layout of the game
    printf("\t|\t %d \t |\t %d \t |\t %d \t |\n",head->counter,second->counter,third->counter);
    printf("\t|\t %d \t |\t %d \t |\t %d \t |\n",fourth->counter,fifth->counter,sixth->counter);
    printf("\t|\t %d \t |\t %d \t |\t %d \t |\n",seventh->counter,eight->counter,ninth->counter);
    printf("\nPlayer 1(X)\n"); 
    printf("\nPlayer 2(O)\n"); 
    printf("\nSelect your position\n");



    //displaying output
    void board()
    {
    printf("\t|\t %c \t |\t %c \t |\t %c \t |\n",head->sym,second->sym,third->sym);
    printf("\t|\t %c \t |\t %c \t |\t %c \t |\n",fourth->sym,fifth->sym,sixth->sym);
    printf("\t|\t %c \t |\t %c \t |\t %c \t |\n",seventh->sym,eight->sym,ninth->sym);
    }


    //all the cases for a player to win
    void win()
    {
        if( (head->sym=='X') && (second->sym=='X') && (third->sym=='X') )
        {
             printf("\nPlayer 1 won\n");
            c=10;
        }
        else if( (fourth->sym=='X') && (fifth->sym=='X') && (sixth->sym=='X') )
        { 
            printf("\nPlayer 1 won\n");
            c=10;
        }
        else if( (seventh->sym=='X') && (eight->sym=='X') && (ninth->sym=='X') )
        { 
            printf("\nPlayer 1 won\n");
            c=10;
        }
        else if( (head->sym=='X') && (fourth->sym=='X') && (seventh->sym=='X') )
        { 
            printf("\nPlayer 1 won\n");
            c=10;
        }
        else if( (second->sym=='X') && (fifth->sym=='X') && (eight->sym=='X') )
        { 
            printf("\nPlayer 1 won\n");
            c=10;
        }
        else if( (third->sym=='X') && (sixth->sym=='X') && (ninth->sym=='X') )
        { 
            printf("\nPlayer 1 won\n");
            c=10;
        }
        else if( (head->sym=='X') && (fifth->sym=='X') && (ninth->sym=='X') )
        { 
            printf("\nPlayer 1 won\n");
            c=10;
        }
        else if( (third->sym=='X') && (fifth->sym=='X') && (seventh->sym=='X') )
        { 
            printf("\nPlayer 1 won\n");
            c=10;
        }
        else if( (head->sym=='O') && (second->sym=='O') && (third->sym=='O') )
        { 
            printf("\nPlayer 2 won\n");
            c=10;
        }
        else if( (fourth->sym=='O') && (fifth->sym=='O') && (sixth->sym=='O') )
        { 
            printf("\nPlayer 2 won\n");
            c=10;
        }
        else if( (seventh->sym=='O') && (eight->sym=='O') && (ninth->sym=='O') )
        { 
            printf("\nPlayer 2 won\n");
            c=10;
        }
        else if( (head->sym=='O') && (fourth->sym=='O') && (seventh->sym=='O') )
        { 
            printf("\nPlayer 2 won\n");
            c=10;
        }
        else if( (second->sym=='O') && (fifth->sym=='O') && (eight->sym=='O') )
        { 
            printf("\nPlayer 2 won\n");
            c=10;
        }
        else if( (third->sym=='O') && (sixth->sym=='O') && (ninth->sym=='O') )
        {
            printf("\nPlayer 2 won\n");
            c=10;
        }
        else if( (head->sym=='O') && (fifth->sym=='O') && (ninth->sym=='O') )
        { 
            printf("\nPlayer 2 won\n");
            c=10;
        }
        else if( (third->sym=='O') && (fifth->sym=='O') && (seventh->sym=='O') )
        { 
            printf("\nPlayer 2 won\n");
            c=10;
        }
        else if( (third->sym=='O') && (head->sym=='O') && (eight->sym=='O') )
        { 
            printf("\nTie Game!\n");
            c=10;
        }
        else if( (third->sym=='X') && (head->sym=='X') && (eight->sym=='X') )
        { 
            printf("\nTie Game!\n");
            c=10;
        }
        else if( (second->sym=='O') && (ninth->sym=='O') && (seventh->sym=='O'))
        {   
            printf("\nTie Game!\n"); 
            c=10;
        }
        else if( (second->sym=='X') && (ninth->sym=='X') && (seventh->sym=='X') )
        { 
            printf("\nTie Game!\n");
            c=10;
        }
        else if( (head->sym=='O') && (sixth->sym=='O') && (seventh->sym=='O') )
        {  
            printf("\nTie Game!\n");
            c=10;
        }
        else if( (head->sym=='X') && (sixth->sym=='X') && (seventh->sym=='X') )
        { 
            printf("\nTie Game!\n");
            c=10;
        }
        else if( (third->sym=='O') && (fourth->sym=='O') && (ninth->sym=='O') )
        { 
            printf("\nTie Game!\n");
            c=10;
        }
        else if( (third->sym=='X') && (fourth->sym=='X') && (ninth->sym=='X') )
        { 
            printf("\nTie Game!\n");
            c=10;
        }
    }
    c=0;
    while(c<9)
    { 
        if(c%2==0)
        {
            struct Node *temp=head; 
            printf("\nFirst Player's turn:"); 
            scanf("%d",&a); 
            if(a<10&&a>0)
            {
                while(temp->next!=NULL)
                { 
                    if(temp->counter==a)
                    {
                        temp->sym='X'; 
                        board();
                        win();
                        temp=tenth; 
                        // assigning tenth to temp for proper termination of round
                    }
                    else
                    {
                        temp=temp->next; 
                        //for traversal to next node
                    }
                }
            }
            else
            {
                printf("\nWrong input\nTurn skipped\n");
            } 
            c++;
        }
        else
        {
            struct Node *temp1=head; 
            printf("\nSecond Player's turn:"); 
            scanf("%d",&b);
            if((b<10)&&(b>0))
            {
                while(temp1->next!=NULL)
                {
                    if(temp1->counter==b)
                    {
                        temp1->sym='O';
                        board();
                        win();
                        temp1=tenth;
                    }
                    else
                    {
                        temp1=temp1->next;
                    }
                }
            }
            else
            {
                printf("\nWrong input\nTurn skipped\n");
            } 
            c++;
        }
    }
    return 0;
}