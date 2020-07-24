#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <windows.h>
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
 
int width=70 , height=30,gameover,flag;
int x,y,fruitx,fruity,score=0,life;
int tailx[100],taily[100],counttail=0;
void makelogic();
void GotoXY(int x, int y)
{
    HANDLE a;
    COORD b;
    fflush(stdout);
    b.X = x;
    b.Y = y;
    a = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(a,b);
 }
void Print()
{
   //GotoXY(10,12);
   printf("\tWelcome to the mini Snake game.(press any key to continue)\n");
  getch();
   system("cls");
   printf("\tGame instructions:\n");
   printf("\n-> Use arrow keys to move the snake.\n\n-> You will be provided foods at the several coordinates of the screen which you have to eat. Everytime you eat a food the length of the snake will be increased by 1 element and thus the score.\n\n-> Here you are provided with three lives. Your life will decrease as you hit the wall or snake's body.\n\n-> YOu can pause the game in its middle by pressing any key. To continue the paused game press any other key once again\n\n-> If you want to exit press esc. \n");
   printf("\n\nPress any key to play game...");
   if(getch()==27)
  
   exit(0);
}
void load(){
    int row,col,r,c,q;
     system("cls");
	GotoXY(36,14);
    printf("loading...");
    GotoXY(30,15);
    for(r=1;r<=20;r++){
    for(q=0;q<=100000000;q++);//to display the character slowly
    printf("%c",177);}
    getch();
}
void setup()
{
gameover=0;
x=35;
y=15;
life=3;
label1:
fruitx=rand()%70;
if(fruitx<=10)
goto label1;

label2:
fruity=rand()%30;
if(fruity<=10)
goto label2;
score=0;
}
void draw()
{
system("cls");
int i,j,k=0;
GotoXY(20,8);
printf("SCORE=%d",score);
GotoXY(50,8);
printf("LIFE=%d",life);
 for(i=10;i<71;i++)
   {
       GotoXY(i,10);
           printf("!");
       GotoXY(i,30);
           printf("!");
   }
   for(i=10;i<31;i++)
   {
       GotoXY(10,i);
           printf("!");
       GotoXY(70,i);
       printf("!");
   }
   GotoXY(fruitx,fruity);   /*displaying food*/
       printf("F");
       GotoXY(x,y);
       printf("*");
 while(tailx[k]!='\0' && taily[k]!='\0')
 { GotoXY(tailx[k],taily[k]);
   printf("o");
   k++;
 }


}

void input()
{  if(kbhit())
{
switch(getch())
{
case 'a' : //aswz
 flag=1;
break;
case LEFT : flag=1; break;
case 's' : //aswz
 flag=2;
break;
case RIGHT :
	flag=2; break;
case 'w' : //aswz
 flag=3;
break;
case UP :
	flag=3; break;
case 'z' : //aswz
 flag=4;
break;
case DOWN : flag=4; break;

}
}
}
void record(){
   char plname[20],nplname[20],cha,c;
   int i,j,px;
   FILE *info;
   info=fopen("snake game records.txt","a+");
   getch();
   system("cls");
   printf("Enter your name\n");
   scanf("%[^\n]",plname);
   //************************
   for(j=0;plname[j]!='\0';j++){ //to convert the first letter after space to capital
   nplname[0]=toupper(plname[0]);
   if(plname[j-1]==' '){
   nplname[j]=toupper(plname[j]);
   nplname[j-1]=plname[j-1];}
   else nplname[j]=plname[j];
   }
   nplname[j]='\0';
   //*****************************
   //sdfprintf(info,"\t\t\tPlayers List\n");
   fprintf(info,"Player Name :%s\n",nplname);
    //for date and time
 
   time_t mytime;
  mytime = time(NULL);
  fprintf(info,"Played Date:%s",ctime(&mytime));
     //**************************
     fprintf(info,"Score:%d\n",score);
	 system("cls");
	 //call score to display score
     //fprintf(info,"\nLevel:%d\n",10);//call level to display level
   for(i=0;i<=50;i++)
   fprintf(info,"%c",'_');
   fprintf(info,"\n");
   fclose(info);
   printf("wanna see past records press 'y'\n");
   cha=getch();
   system("cls");
   if(cha=='y'){
   info=fopen("snake game records.txt","r");
   do{
       putchar(c=getc(info));
       }while(c!=EOF);}
     fclose(info);
}
void makelogic()
{ int i, a,prevx=tailx[0];
int prevy=taily[0];
int prev2x,prev2y;
tailx[0]=x;
taily[0]=y;
for(i=1;i<counttail;i++)
{
prev2x=tailx[i];
prev2y=taily[i];
tailx[i]=prevx;
taily[i]=prevy;
prevx=prev2x;
prevy=prev2y;
}

switch(flag)
{
case 1:
x--;
break;
case 2:
x++;
break;
case 3:
y--;
break;
case 4:
y++;
break;

default : break;
}




 
if(x<=10||x>=width||y<=10||y>=height)
{
life--;
if(life>=0)
{
x=35; y=15;}
     else
        {
            system("cls");
            printf("All lives completed\nBetter Luck Next Time!!!\nPress any key to quit the game\n");
            record();
            exit(0);
        } 
		}
for(i=0;i<counttail;i++)
{
if(x==tailx[i] && y==taily[i]) 
{
life--;
if(life>=0)
{
x=35; y=15;}
     else
        {
            system("cls");
            printf("All lives completed\nBetter Luck Next Time!!!\nPress any key to quit the game\n");
            record();
            exit(0);
        }
}
else continue;
}


if(x==fruitx && y==fruity)
{

label3:
fruitx=rand()%70;
if(fruitx<=10)
goto label3;

label4:
fruity=rand()%30;
if(fruity<=10)
goto label4;


score+=10;
counttail++;
}
}
void Delay()
{
    long double i;
    for(i=0;i<=(10000000);i++);
}


int main()
{ 
	int c,m,n;
Print();
load();
setup();
while(!gameover)
{
draw();
input();
makelogic();
Delay();
}

return 0;
}














