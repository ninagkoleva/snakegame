#include<conio.h>
#include<stdlib.h>
float zabconst=0.5;
struct snakebodytype {
   char x,y;
} snakebody[1000];
struct snaketype {
   char x,y;
   int head,len;
   char lives,dir;
   long score;
} snake={40,22,1,2,5,1,0};
struct hranatype {
     char x,y;
} food;
float z,zab=zabconst;
//long int score=0;
char pole[80][50],ch,x,y;
void erasesnake(void);

void logo(void) {
	int x0=15,x,y,bz[10][8],i,j,bi[5][2]={0,-1,1,2,3,4,5,-1,6,7};

   for (i=0;i<10;i++)
   	for (j=0;j<8;j++)
      	bz[i][j]=-1;
   bz[0][0]=6; bz[1][0]=7; bz[8][0]=1; bz[8][1]=7;
   for (i=2;i<8;i++) {
   		bz[i][0]=0;
         bz[i][1]=7;
   }
   for (i=2;i<7;i++) bz[9][i-2]=i;

   textcolor(LIGHTGREEN);
   x=x0;y=22;
   for (i=0;i<10;i++)
   	for (j=0;j<8;j++)
      	if (bz[i][j]!=-1) {
         		gotoxy(x+i,y+bz[i][j]);
               cprintf("%c",219);
               gotoxy(x+i,y-bz[i][j]);
               cprintf("%c",219);
         }
   x=x0+18;
   for (i=0;i<5;i++)
      for (j=0;j<2;j++)
         if (bi[i][j]!=-1) {
      		gotoxy(x-i,y-bi[i][j]);
            cprintf("%c",219);
            gotoxy(x+i,y-bi[i][j]);
            cprintf("%c",219);
      	}
   for (i=y-7;i<y+8;i++)  {
   		gotoxy(x-4,i);
         cprintf("%c",219);
         gotoxy(x+4,i);
         cprintf("%c",219);
         gotoxy(x0+27,i);
         cprintf("%c",219);
         gotoxy(x0+35,i);
         cprintf("%c",219);
   }
   x=x0+31;
   for (i=0;i<5;i++)
      for (j=0;j<2;j++)
         if (bi[i][j]!=-1) {
      		gotoxy(x+i,y-bi[i][j]);
            cprintf("%c",219);
            gotoxy(x-i,y+bi[i][j]);
            cprintf("%c",219);
      	}

  x=x0+48;
     for (i=1;i<7;i++) {
      		gotoxy(x,y-i);
            cprintf("%c",219);
            gotoxy(x-8,y-i);
            cprintf("%c",219);
     }
     for (i=0;i<8;i++) {
      		gotoxy(x-i,y-7);
            cprintf("%c",219);
            gotoxy(x-i,y);
            cprintf("%c",219);
            gotoxy(x-i-1,y+i);
            cprintf("%c",219);
            //gotoxy(x-i-18,y+i-7);
            //cprintf("%c",219);
            gotoxy(x,y+i);
            cprintf("%c",219);
     }
     snake.x=5; snake.y=3; snake.dir=1; snake.len=100;
  int tail;
  int itr=0;
  do {
  	if (kbhit()) break;
  itr++;
  	if (itr==70) snake.dir=4;
   if (itr==75) snake.dir=3;
   if (itr==145) snake.dir=4;
   if (itr==150) snake.dir=1;

   if (itr==220) snake.dir=4;
   if (itr==240) snake.dir=3;
   if (itr==310) snake.dir=4;
   if (itr==315) snake.dir=1;

   if (itr==390) snake.dir=4;
   if (itr==395) snake.dir=3;
   if (itr==470) snake.dir=2;
   if (itr==510) snake.dir=1;

   if (itr==510) {
   		itr=0;
         snake.head=1;
          for(i=0;i<1000;i++) {
      if (snakebody[i].x!=0) {
	  		for (float z=-1000000;z<200000;z++);
	  			gotoxy(snakebody[i].x,snakebody[i].y);
            cprintf(" ");
	  			snakebody[j].x=0;
	  			pole[snakebody[j].x][snakebody[j].y]=0;
       }

   }
  	}

   if(snake.dir==1) snake.x++;
   if(snake.dir==2) snake.y--;
   if(snake.dir==3) snake.x--;
   if(snake.dir==4) snake.y++;

   if (snake.x==81) snake.x=80;
   if (snake.x==0) snake.x=1; 

   gotoxy(snake.x,snake.y);
   textcolor(YELLOW);
   cprintf("%c",219);

   for(z=-200000;z<2000000;z+=zab);

   snake.head++;
   snakebody[snake.head].x=snake.x;
   snakebody[snake.head].y=snake.y;
   pole[snake.x][snake.y]=1;
   tail=(snake.head+1001-snake.len)%1000;

   if (snakebody[tail].x!=0) {
		gotoxy(snakebody[tail].x,snakebody[tail].y);
		cprintf(" ");
		pole[snakebody[tail].x][snakebody[tail].y]=0;
		snakebody[tail].x=0;
   }

  }
  while(1);


}

void erasesnake(void) {
   int j;

   for(j=0;j<1000;j++) {
      if (snakebody[j].x!=0) {
	  //for (float z=-1000000;z<200000;z++);
	  gotoxy(snakebody[j].x,snakebody[j].y);
	  cprintf(" ");
	  snakebody[j].x=0;
	  pole[snakebody[j].x][snakebody[j].y]=0;
       }

   }
}



void showfood(void) {
  do  {
	food.x=rand()%77+2;
	food.y=rand()%42+2;
  }
  while (pole[food.x][food.y]==1);

  textcolor(LIGHTRED);
  gotoxy(food.x,food.y);
  cprintf("%c",3);
}

void initpole(char level) {
  int x,y;
  for (x=0;x<1000;x++) snakebody[x].x=0;

  for(x=0;x<80;x++)       //za nvata//
   for(y=0;y<50;y++)
	pole[x][y]=0;
   for(x=1;x<80;x++) {
	pole[x][1]=1;
	pole[x][44]=1;
   }
   for(y=1;y<45;y++) {
	pole[1][y]=1;
	pole[79][y]=1;
   }
   switch (level) {
      case 2:
	      for (x=12;x<68;x++)
		   pole[x][22]=1;
	     break;
      case 3:
	      for (y=6;y<37;y++) {
		   pole[22][y]=1;
		   pole[58][y]=1;
	      }
         snake.dir=2;
	     break;
      case 4:
	      for (y=6;y<37;y++) {
		   pole[22][y]=1;
		   pole[58][y]=1;
         }
         for (x=30;x<50;x++)
		   pole[x][22]=1;
         snake.dir=2;
         break;
      case 5:
	      for (y=6;y<37;y++) {
		   pole[20][y]=1;
         pole[40][y]=1;
		   pole[60][y]=1;
         }
         snake.x=23;
         snake.dir=1;
         break;
      case 6:
	      for (y=6;y<37;y++) {
		   pole[20][y]=1;
         pole[40][y]=1;
		   pole[60][y]=1;
         }
         for (x=26;x<35;x++){
         pole[x+20][22]=1;
         pole[x][22]=1;
         }
         snake.x=18;
         snake.dir=2;
         break;
         case 7:
	      for (y=10;y<34;y++) {
		   pole[26][y]=1;
         pole[53][y]=1;
		   }
         for (x=28;x<52;x++){
         pole[x][8]=1;
         pole[x][35]=1;
         }
         snake.x=40;
         snake.dir=1;
         break;
        case 8:
	      for (y=15;y<44;y++) {
		   pole[9][y]=1;
         pole[71][y-14]=1;
		   }
         for (x=1;x<63;x++){
         pole[x+17][37]=1;
         pole[x][8]=1;
         }
         snake.x=18;
         snake.dir=1;
         break;
         case 9:
	      for (y=1;y<39;y++) {
		   pole[10][y]=1;
         pole[30][y]=1;
		   pole[50][y]=1;
         pole[70][y]=1;
         pole[20][y+6]=1;
		   pole[40][y+6]=1;
         pole[60][y+6]=1;
         }
         snake.x=18;
         snake.dir=2;
         break;
         case 10:
	      for (y=1;y<44;y+=2) {
		   pole[10][y]=1;
         pole[30][y]=1;
		   pole[50][y]=1;
         pole[70][y]=1;
         pole[20][y-1]=1;
		   pole[40][y-1]=1;
         pole[60][y-1]=1;
         }
         snake.x=18;
         snake.dir=2;

   } //end switch
}
void drawpole(char color) {
   textcolor(color);
   for(x=0;x<80;x++)
   for(y=0;y<50;y++)
      if (pole[x][y]==1) {
	gotoxy(x,y);
	cprintf("%c",219);
      }
      else {
	gotoxy(x,y);
	cprintf(" ");
      }
}
main() {
  int tail;
  textmode(C4350);
  _setcursortype(_NOCURSOR);
  logo();
  getch();
  textcolor(GREEN);
  clrscr();
  randomize();
  initpole(1);
  drawpole(GREEN);
  showfood();
  char brfood=0;
  snake.lives=5;
  char level=1;
  int maypassnewlevel=0;
  do {
   if(snake.dir==1) snake.x++;
   if(snake.dir==2) snake.y--;
   if(snake.dir==3) snake.x--;
   if(snake.dir==4) snake.y++;
     if(kbhit()){
      ch=getch();
      if(ch=='j' && snake.dir!=1) snake.dir=3;
      if(ch=='k' && snake.dir!=3) snake.dir=1;
      if(ch=='i' && snake.dir!=4) snake.dir=2;
      if(ch=='m' && snake.dir!=2) snake.dir=4;
      if(ch=='q') break;
     }
   if(snake.x==food.x && snake.y==food.y) {
			brfood++;
			snake.score+=100;
			snake.len+=3*brfood;
			if (snake.len>960) snake.len=960;
			zab+=0.013;
			showfood();
   }
   if (brfood==3)
        for (int i=38;i<41;i++) {
        		textcolor(BLACK);
            gotoxy(i,1);
            cprintf(" ");
            pole[i][1]=2;
        }
   if (pole[snake.x][snake.y]==2) maypassnewlevel=1;

   if (maypassnewlevel) {
		brfood=0;level++;
		zab=zabconst;
		snake.x=20;snake.y=20;snake.dir=1;
		snake.len=2;
		snake.head=1;
   	maypassnewlevel=0;
		erasesnake();

		initpole(level);
		drawpole(GREEN);
		showfood();
   }
   if(pole[snake.x][snake.y]==1) {
		brfood=0;
		snake.lives--;
		zab=zabconst;
		snake.x=20;snake.y=20;snake.dir=1;
		snake.len=2;
		snake.head=1;
		erasesnake();
		initpole(level);
		drawpole(GREEN);
		showfood();
   }

   gotoxy(snake.x,snake.y);
   textcolor(YELLOW);
   cprintf("%c",219);

   for(z=-200000;z<2000000;z+=zab);

   snake.head++;
   snakebody[snake.head].x=snake.x;
   snakebody[snake.head].y=snake.y;
   pole[snake.x][snake.y]=1;
   tail=(snake.head+1001-snake.len)%1000;

   if (snakebody[tail].x!=0) {
		gotoxy(snakebody[tail].x,snakebody[tail].y);
		cprintf(" ");
		pole[snakebody[tail].x][snakebody[tail].y]=0;
		snakebody[tail].x=0;
   }
   textcolor(YELLOW);
   gotoxy(20,47);
   cprintf("lives=%d  ",snake.lives);
   gotoxy(40,47);
   cprintf("level=%d  ",level);
   gotoxy(20,49);
   cprintf("score=%d  ",snake.score);

     if (snake.lives==0) break;
    }
    while(1);
    gotoxy(36,20);
    cprintf("GAME OVER!");
    getch();
 }