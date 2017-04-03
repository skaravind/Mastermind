			       // HEADER FILES


#include<iostream.h>
//for I/O operations

#include<conio.h>
//for getch()

#include<stdlib.h>
//for srand()

#include<time.h>
//for clock()

#include<fstream.h>
//for file handling

#include<graphics.h>
//for text colours

#include<stdio.h>
//for printf etc

#include<dos.h>
//for delay()


			  // GLOBAL VARIABLES

int tr; //to store tries
int y; //to store difficulty
int tm; //to store clock reading
long input1;
int rnrp,rnwp, input, choice[20], num[20];
char name[30];
int score;
char diff[20];
int sarr[10];
double points;

	  //***************************************************

			// USER DEFINED FUNCTIONS
	  //***************************************************

	     // FUNCTIONS FOR RANDOM NUMBER FROM COMPUTER

	   //***************************************************


void choice_easy()
{
    srand (time(NULL));
    int i,x;
    for(i=0;i<4;i++)
    {
       label:
       x=rand() % 7;
       choice[i]=x;
       for(int j=1;j<=3;j++)
       {
	  if(choice[i]==choice[i-j]||choice[i]==0)
	  {
	     goto label;
	  }
	  else
	  {
	     continue;
	  }
       }
    }
    for(i=0;i<4;i++)
    {
       cout<<choice[i];
    }
}

void choice_medium()
{
    srand (time(NULL));
    int i,x;
    for(i=0;i<5;i++)
    {
       label:
       x=rand() % 8;
       choice[i]=x;
       for(int j=1;j<=5;j++)
       {
	  if(choice[i]==choice[i-j]||choice[i]==0)
	  {
	     goto label;
	  }
	  else
	  {
	     continue;
	  }
       }
    }
}

void choice_hard()
{
    srand (time(NULL));
    int i,x;
    for(i=0;i<6;i++)
    {
       label:
       x=rand() % 9;
       choice[i]=x;
       for(int j=1;j<=6;j++)
       {
	  if(choice[i]==choice[i-j]||choice[i]==0)
	  {
	     goto label;
	  }
	  else
	  {
	     continue;
	  }
       }
    }
}

	      //***************************************************
		      //FUNCTIONS FOR USER INPUT (GUESS)
	     //***************************************************

void input_easy()
{
    lbinput:
    cout<<"(PRESS 9 FOR EXIT)";
    cout<<"\n:-  ";
    cin>>input;
    if(input==9)
    {
      system("cls");
      setbkcolor(BLUE);
      cout<<"\t     THANK YOU FOR PLAYING THE MASTERMIND GAME!!\n\n\n";
      delay(3000);
      exit(1);
    }
    int check;
    check=input/1000;
    if(check>=10||check==0)
    {
       cout<<"PLEASE ENTER A 4 DIGIT NUMBER";
       goto lbinput;
    }
    for(int i=3;i>=0;i--)
    {
       num[i]=input%10;
       input=input/10;
    }
}

void input_medium()
{
    lbinput:
    cout<<"(PRESS 9 FOR EXIT)";
    cout<<"\n:-  ";
    cin>>input1;
    if(input1==9)
    {
      system("cls");
      setbkcolor(BLUE);
      cout<<"\t     THANK YOU FOR PLAYING THE MASTERMIND GAME!!\n\n\n";
      delay(3000);
      exit(1);
    }
    long check;
    check=input1/10000;
    if(check>=10||check==0)
    {
       cout<<"PLEASE ENTER A 5 DIGIT NUMBER";
       goto lbinput;
    }
    for(int i=4;i>=0;i--)
    {
       num[i]=input1%10;
       input1=input1/10;
    }
}

void input_hard()
{
    lbinput:
    cout<<"(PRESS 9 FOR EXIT)";
    cout<<"\n:-  ";
    cin>>input1;
    if(input1==9)
    {
      system("cls");
      setbkcolor(BLUE);
      cout<<"\t     THANK YOU FOR PLAYING THE MASTERMIND GAME!!\n\n\n";
      delay(3000);
      exit(1);
    }
    long check;
    check=input1/100000;
    if(check>=10||check==0)
    {
       cout<<"PLEASE ENTER A 6 DIGIT NUMBER";
       goto lbinput;
    }
    for(int i=5;i>=0;i--)
    {
       num[i]=input1%10;
       input1=input1/10;
    }
}
     //***************************************************************
	// FUNCTIONS TO CROSS-CHECK THE INPUT WITH THE RANDOM NUMBER
     //***************************************************************


void check_easy()
{
    rnrp=0;
    rnwp=0;
    for(int i=0;i<4;i++)
    {
	if(choice[i]==num[i])
	rnrp++;
	else
	for(int j=1;j<4;j++)
	{
	    if(choice[i]==num[i+j]||choice[i]==num[i-j])
	    rnwp++;
	}
    }
}

void check_medium()
{
    rnrp=0;
    rnwp=0;
    for(int i=0;i<5;i++)
    {
	if(choice[i]==num[i])
	rnrp++;
	else
	for(int j=1;j<5;j++)
	{
	    if(choice[i]==num[i+j]||choice[i]==num[i-j])
	    rnwp++;
	}
    }
}

void check_hard()
{
    rnrp=0;
    rnwp=0;
    for(int i=0;i<6;i++)
    {
	if(choice[i]==num[i])
	rnrp++;
	else
	for(int j=1;j<6;j++)
	{
	    if(choice[i]==num[i+j]||choice[i]==num[i-j])
	    rnwp++;
	}
    }
}


	   //***************************************************

		   // FUNCTION TO SAVE USER'S SCORE
	   //***************************************************


void SAVE()
{
   fstream temp;
   temp.open("temp.txt",ios::out);
   fstream lscore;
   lscore.open("lscores.txt",ios::in);
   system("cls");
   setbkcolor(RED);
   char dtls;
   while(!lscore.eof())
   {
      lscore.get(dtls);
      temp<<dtls;
   }
   cout<<"PLEASE ENTER YOUR NAME....\n\nNAME :-";
   cin>>name;
   lscore.close();
   lscore.open("lscores.txt",ios::out);
   lscore<<name<<' '<<tr<<' ';
   if(y==1)
   lscore<<"QUICK";
   if(y==2)
   lscore<<"REGULAR";
   if(y==3)
   lscore<<"IMPOSSIBLE";
   lscore<<' '<<points;
   lscore.close();
   temp.close();
   temp.open("temp.txt",ios::in);
   lscore.open("lscores.txt",ios::app);
   char dtls1;
   lscore<<endl;
   while(!temp.eof())
   {
      temp.get(dtls1);   //flushing and reappending the file so
      lscore<<dtls1;	 //that latest scores are displayed above
   }
}


	    //***************************************************

		     // FUNCTION TO DISPLAY HIGHSCORES
	    //***************************************************


void display_lscore()
{
   int count=1;
   cout<<"NAME -------- TRIES ------ DIFFICULTY --------- POINTS\n\n";
   ifstream lscore;
   lscore.open("lscores.txt");
   lscore.seekg(0);
   while(!lscore.eof())
   {
      lscore>>name>>tr>>diff>>points;
      cout<<name<<" -------- "<<tr<<" ---------- "<<diff<<" ----------------- "<<points;
      cout<<endl<<endl;
      count++;
      if(count==9)
      break;
   }
}




	    //***************************************************

			    //  MAIN FUNCTION

	    //***************************************************

int main()
{
  clock_t start,end;    //for in-game stopwatch
  ifstream inst;
  inst.open("INST.txt",ios::in);
  system("cls");

    /* request auto detection */
  int gdriver = DETECT, gmode, errorcode;

    /* initialize graphics mode */
  initgraph(&gdriver, &gmode, "C:\\turboc3\\bgi");

    /* read result of initialization */
  errorcode = graphresult();

  if (errorcode != grOk)  /* an error occurred */
  {
     printf("Graphics error: %s\n", grapherrormsg(errorcode));
     printf("Press any key to halt:");
     getch();
     exit(1);             /* return with error code */
  }
    int midx=getmaxx()/2-225;
    int midy=(getmaxy()/2)-100;
    setbkcolor(RED);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
    outtextxy(midx,midy,"***  WELCOME TO THE MASTERMIND GAME  ***\n\n\n\n\n\n\n\n");
    delay(5000);
    menu:
    input=0;
    input1=0;
    system("cls");
    setbkcolor(BLUE);
    cout<<"\t\t\t   ***** MENU *****\n\n\n\n";
    cout<<"\t1. Start The game\n\n\n";
    cout<<"\t2. Look at some latest scores\n\n\n";
    cout<<"\t3. Instructions\n\n\n";
    cout<<"\t4. Points Scheme\n\n\n";
    cout<<"\t5. Exit\n\n\n";
    cout<<"\t**** CHOOSE OPTION BY PRESSING (1-5) ....";
    int num,dif,tries=0;
    cin>>num;
    switch(num)
    {
	case 1 : system("cls");
		 setbkcolor(GREEN);
		 cout<<"\t*** PLEASE CHOOSE DIFFICULTY...\n\n\n";
		 cout<<"\t 1. QUICK (4 DIGIT NUMBER)\n\n\n";
		 cout<<"\t 2. REGULAR (5 DIGIT NUMBER)\n\n\n";
		 cout<<"\t 3. IMPOSSIBLE (6 DIGIT NUMBER)\n\n\n";
		 cout<<"REMEMBER!, TIMER STARTS AS SOON AS YOU CHOOSE THE DIFFICULTY";
		 cout<<"\t\n\n CHOICE (1,2 or 3):-  ";
		 cin>>dif;
		 y=dif;
		 goto lb1;

	case 2 : system("cls");
		 cout<<"\t\t  *** SCORES ***\n\n";
		 cout<<"\t\t(LATEST AT THE TOP)\n";
		 display_lscore();
		 system("pause");
		 goto menu;

	case 3 : system("cls");
		 setbkcolor(MAGENTA);
		 char line;
		 while(inst)
		 {
		   inst.get(line);
		   cout<<line;
		 }
		 system("pause");
		 goto menu;

	case 4 : system("cls");
		 char dtls;
		 ifstream pts;
		 pts.open("points.txt",ios::in);
		 while(!pts.eof())
		 {
		    pts.get(dtls);
		    cout<<dtls;
		 }
		 cout<<endl<<endl;
		 system("pause");
		 goto menu;

	case 5 : exit(0);

	default : cout<<"Wrong Choice ....!, Please choose a no. b/w 1-4.";
		  system("pause");
		  goto menu;

    }
    lb1:
    system("cls");
    setbkcolor(BLUE);
    start=clock();
    switch(dif)
    {
       case 1: choice_easy();
	       cout<<"OK,\n\nThe computer has chosen a no., ";
	       cout<<"now its ur turn to guess the number!\n";
	       system("pause");
	       system("cls");
	       setbkcolor(RED);
	       cout<<"Enter your guess. Remember, only a ";
	       cout<<"4 digit number!!! \n(no. between 1 to 6)";
	       while(rnrp!=4)
	       {
		  input_easy();
		  check_easy();
		  cout<<"Right number and right position..."<<rnrp<<endl;
		  cout<<"Right number but wrong position..."<<rnwp<<endl;
		  tries++;
	       }
	       system("cls");
	       setbkcolor(GREEN);
	       cout<<"CONGRATULATIONS YOU GOT THE NO!!!!!\n\nNumber of tries you took...."<<tries;
	       tr=tries;
	       break;

       case 2: choice_medium();
	       cout<<"OK,\n\nThe computer has chosen a no., ";
	       cout<<"now its ur turn to guess the number!\n";
	       system("pause");
	       system("cls");
	       setbkcolor(RED);
	       cout<<"Enter your guess. Remember, only a ";
	       cout<<"5 digit number!!! \n(no. between 1 to 7)";
	       while(rnrp!=5)
	       {
		  input_medium();
		  check_medium();
		  cout<<"Right number and right position..."<<rnrp<<endl;
		  cout<<"Right number but wrong position..."<<rnwp<<endl;
		  tries++;
	       }
	       system("cls");
	       setbkcolor(GREEN);
	       cout<<"CONGRATULATIONS YOU GOT THE NO!!!!!\n\nNumber of tries you took...."<<tries;
	       tr=tries;
	       break;

       case 3: choice_hard();
	       cout<<"OK,\n\nThe computer has chosen a no., ";
	       cout<<"now its ur turn to guess the number!\n";
	       system("pause");
	       system("cls");
	       setbkcolor(RED);
	       cout<<"Enter your guess. Remember, only a ";
	       cout<<"6 digit number!!! \n(no. between 1 to 8)";
	       while(rnrp!=6)
	       {
		  input_hard();
		  check_hard();
		  cout<<"Right number and right position..."<<rnrp<<endl;
		  cout<<"Right number but wrong position..."<<rnwp<<endl;
		  tries++;
	       }
	       system("cls");
	       setbkcolor(GREEN);
	       cout<<"CONGRATULATIONS YOU GOT THE NO!!!!!\n\nNumber of tries you took...."<<tries;
	       tr=tries;   //Storing no. of tries globally
	       break;

       default: cout<<"wrong choice";
		break;
    }
    end=clock();
    tm=(end-start)/CLK_TCK;
    points=((500-tr))+((5000-tm));
    cout<<"\n\nTHE TIME YOU TOOK : "<<tm<<" seconds";
     cout<<"\n\nSO YOUR FINAL POINTS TALLY IS ......";
    cout<<points;
    cout<<"\n\nWant to save your no. of tries and time taken?? (y/n)... ";
    char ans;
    cin>>ans;
    if(ans=='y'||ans=='Y')
    {
       SAVE();
       cout<<"\n\nYOUR SCORE HAS BEEN SAVED...";
    }
    cout<<"\n\nWANT TO PLAY AGAIN (y/n) ?..... ";
    cin>>ans;
    if(ans=='y'||ans=='Y')
    goto menu;
    system("pause");
    system("cls");
    setbkcolor(BLUE);
    cout<<"\t     THANK YOU FOR PLAYING THE MASTERMIND GAME!!\n\n\n";
    delay(3000);
    closegraph();
    inst.close();
    return 0;
}


