#include<stdio.h> 
#include<conio.h> 
#include<stdlib.h> 
#include<dos.h>
#include<graphics.h> 
#include<alloc.h>

char key;

//---------------REQUIRED STRUCTURE----------------

struct loc
{
    int x,y;
};  

struct snake
{
    struct loc sloc; 
    struct snake *link; 
    char dir;
};

struct game_data
{
    int score; 
    int no_food;
};

struct game_data gd={0,0};

struct limit
{
    int lx1,ly1,lx2,ly2;
};

struct limit l={96,96,404,404};

struct food
{
    struct loc floc; 
    int number;
};

int n=0,ch;
//
// FUNCTIONS
//
gameover(void)
{
    cleardevice();
    outtextxy(100,100,"----------------- GAME OVER----------------- ");
    printf("\n\n\n\n\n\n\n\n"); 
    printf("\t\t# Score - %d",gd.score);
    printf("\n\t\t# Food eaten - %d", gd.no_food); 
    outtextxy(200,300,"Press any key to exit");
    s1: sound(300);
        delay(300);
        sound(450);
        delay(150);
        sound(500);
        delay(150);
        sound(300);
        delay(200);
        sound(450);
        delay(100);
        sound(450);
        delay(200);
        while(!kbhit())
        {
            goto s1;
        }
        nosound();
        exit(0); 
        return 0;
    }
    draw(struct snake *head,struct food *f,int ch)
    {
        struct snake *temp; 
        temp=head;
        switch(ch)
        {
            case 1:
                    rectangle(96,96,404,404); 
                    rectangle(98,98,402,402); 
                    rectangle(100,100,400,400); 
                    setfillstyle(9,13); 
                    outtextxy(220,40,"Easy");
                    bar(temp->sloc.x-6,temp->sloc.y-6,temp->sloc.x+6,temp->sloc.y+6);
                    temp=temp->link; 
                    setfillstyle(9,2); 
                    while(temp->link!=NULL)
                    {
                        bar(temp->sloc.x-5,temp->sloc.y-5,temp->sloc.x+5,temp->sloc.y+5);
                        temp=temp->link;
                    }
                    bar(temp->sloc.x-5,temp->sloc.y-5,temp->sloc.x+5,temp->sloc.y+5);
                    circle(f->floc.x-2,f->floc.y-2,3); 
                    circle(f->floc.x+2,f->floc.y+2,3); 
                    circle(f->floc.x-2,f->floc.y+2,3); 
                    circle(f->floc.x+2,f->floc.y-2,3);
                    delay(25); 
                    while(!kbhit())
                    {
                        goto e;
                    } 
                    key=getche();
                    break;
            case 2:
                    rectangle(96,96,404,404); 
                    rectangle(98,98,402,402); 
                    rectangle(100,100,400,400); 
                    setfillstyle(9,13); 
                    outtextxy(220,40,"Medium");
                    bar(temp->sloc.x-6,temp->sloc.y-6,temp->sloc.x+6,temp->sloc.y+6);
                    temp=temp->link; 
                    setfillstyle(9,BLUE); 
                    while(temp->link!=NULL)
                    {
                        bar(temp->sloc.x-5,temp->sloc.y-5,temp->sloc.x+5,temp->sloc.y+5);
                        temp=temp->link;
                    }
                    bar(temp->sloc.x-5,temp->sloc.y-5,temp->sloc.x+5,temp->sloc.y+5);
                    circle(f->floc.x-2,f->floc.y-2,3); 
                    circle(f->floc.x+2,f->floc.y+2,3); 
                    circle(f->floc.x-2,f->floc.y+2,3); 
                    circle(f->floc.x+2,f->floc.y-2,3);
                    delay(20); 
                    while(!kbhit())
                    {
                        goto e;
                    } 
                    key=getche();
                    break;
            case 3:
                    rectangle(96,96,404,404); 
                    rectangle(98,98,402,402); 
                    rectangle(100,100,400,400); 
                    setfillstyle(9,13); 
                    outtextxy(220,40,"Hard");
                    bar(temp->sloc.x-6,temp->sloc.y-6,temp->sloc.x+6,temp->sloc.y+6); 
                    temp=temp->link;
                    setfillstyle(9,RED); 
                    while(temp->link!=NULL)
                    {
                        bar(temp->sloc.x-5,temp->sloc.y-5,temp->sloc.x+5,temp->sloc.y+5);
                        temp=temp->link;
                    }
                    bar(temp->sloc.x-5,temp->sloc.y-5,temp->sloc.x+5,temp->sloc.y+5);
                    circle(f->floc.x-2,f->floc.y-2,3); 
                    circle(f->floc.x+2,f->floc.y+2,3); 
                    circle(f->floc.x-2,f->floc.y+2,3); 
                    circle(f->floc.x+2,f->floc.y-2,3);
                    break;
        }
        e:
            delay(10); 
            while(!kbhit())
            {
                goto e;
            } 
            key=getche();
            cleardevice(); 
            return 0;
    }
void game(struct snake *head,struct food *f,int ch)
{
    struct snake *temp,pre,nxt; 
    temp=head;
    while(key!='p')
    {
        if(head->sloc.x==l.lx1||head->sloc.x==l.ly2||head->sloc.y==l.ly1||head->sloc.y==l.ly2)
        {
            gameover();
        }
        if(head->sloc.x>=f->floc.x-5 && head->sloc.x<=f->floc.x+5 && head->sloc.y>=f->floc.y-5 && head->sloc.y<=f->floc.y+5)
        {
            temp=head; 
            sound(420);
            f->floc.x=150+random(245); 
            f->floc.y=150+random(245); 
            gd.score+=100; 
            gd.no_food+=1;
            n=n+1;
            while(temp->link!=NULL)
            {
                temp=temp->link;
            }
            temp->link=(struct snake *)malloc(sizeof(struct snake)); 
            temp->link->link=NULL;
            temp->link->sloc.x= temp->sloc.x; 
            temp->link->sloc.y= temp->sloc.y;
            temp->link->dir=temp->dir; 
            n=0;
        }
        switch(key)
        {
            case 'a': 
                        if(head->dir!='d')
                        {
                            head->dir='a'; 
                            head->sloc.x-=2; 
                        } 
                        else
                        {
                            key=head->dir;
                        } 
                        break;
            case 'w': 
                        if(head->dir!='s')
                        {
                            head->dir='w'; 
                            head->sloc.y-=2;
                        } 
                        else
                        {
                            key=head->dir;
                        } 
                        break;
            case 'd': 
                        if(head->dir!='a')
                        {
                            head->dir='d'; 
                            head->sloc.x+=2; 
                        } 
                        else
                        {
                            key=head->dir;
                        }
                        break;
            case 's': 
                        if(head->dir!='w')
                        {
                            head->dir='s';
                            head->sloc.y+=2;
                        } 
                        else
                        {
                            key=head->dir;
                        } 
                        break;
        }
        draw(head,f,ch); 
        nosound(); 
        temp=head; 
        pre=*temp;
        while(temp->link!=NULL)
        {
            nxt.sloc.x=temp->link->sloc.x; 
            nxt.sloc.y=temp->link->sloc.y; 
            nxt.dir=temp->link->dir;
            temp->link->sloc.x=pre.sloc.x;
            temp->link->sloc.y=pre.sloc.y;
            temp->link->dir=pre.dir; 
            temp=temp->link; 
            pre=nxt;
        }
    }
}


void main(void)
{
    struct snake *s; 
    struct food f;
    int gdriver = DETECT, gmode, errorcode;
    clrscr();
    s=(struct snake *)malloc(sizeof(struct snake)); 
    s->dir='w';
    s->link=NULL;
    s->sloc.x= s->sloc.y=300;
    f.f loc.x=150+random(250); 
    f.floc.y=150+random(250);
    initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
    
    
    //-------- # ENTER REQUIRED PATH FOR EGAVGA.BGI---------------
    
    outtextxy(300,50,"The SNAKE Game!!!"); 
    outtextxy(220,100,"Created by Darsh, Nimit and Alekhya"); 
    outtextxy(100,160,"# Instructions :"); 
    outtextxy(100,200,"1. Press 'w' to go upward"); 
    outtextxy(100,220,"2. Press 's' to go downward"); 
    outtextxy(100,240,"3. Press 'a' to go left hand side"); 
    outtextxy(100,260,"4. Press 'd' to go right hand side"); 
    outtextxy(100,280,"5. Press 'p' to pause the game"); 
    outtextxy(100,320,"CHOOSE DIFFULCITY:");
    outtextxy(100,340,"1. Easy"); 
    outtextxy(100,360,"2. Medium"); 
    outtextxy(100,380,"3. Hard"); 
    scanf("%d",&ch);
    s: 
        sound(700);
        delay(200);
        sound(450);
        delay(180);
        sound(300);
        delay(150);
        sound(350);
        delay(200);
        sound(450);
        delay(180);
        sound(500);
        delay(150); 
        while(!kbhit())
        {
            goto s;
        }
        nosound();
        pause :
                draw(s,&f,ch);
                game(s,&f,ch); key='r';
                rectangle(60,60,600,200); 
                outtextxy(260,100,"GAME PAUSED");
                s1: 
                    sound(400);
                    delay(500);
                    sound(450);
                    delay(250);
                    sound(300);
                    delay(200);
                    sound(400);
                    delay(300);
                    sound(450);
                    delay(250);
                    sound(300);
                    delay(200); 
                    while(!kbhit())
                    {
                        goto s1;
                    }
                    goto pause;
                    closegraph(); 
                    clrscr();
                    printf("\n\n\n\n\t\t\t\tThankyou.....");
                    getch();
}