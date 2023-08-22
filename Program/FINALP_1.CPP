/*Computer Science Project-Class XII A
 Topic:Online health centre
 About:Analysing a patients's health under 3 categories:
		 1.General health
       2.Physical health
		 3.Mental health                                   */
#include<fstream.h>
#include<string.h>
#include<iomanip.h>
#include<conio.h>
#include<snap.h>
#include<graphics.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<dos.h>
//class having main details of patient
class details{
	       char name[30],bdgrp[5],gend;
	       int age;
	 protected:char id[10];
		 public:void getdet(char ID[10]);
	      char* retid();
				  int retage();
				  void putdet();
				 }D;
void details::getdet(char ID[10])
{
 int cbg;
 strcpy(id,ID);
 cout<<"Name: ";
 gets(name);
 cout<<'\n';
 cout<<"Age: ";
 cin>>age;
 while((age<0)||(age>150))
 {
  cout<<"Enter valid age: ";
  cin>>age;
 }
 cout<<'\n';
 cout<<"Bloodgroup(If O+ve -> O+): ";
 gets(bdgrp);
 do{
	 if(strcmpi(bdgrp,"A+")==0)
	  cbg=1;
	 else if(strcmpi(bdgrp,"B+")==0)
	  cbg=2;
	 else if(strcmpi(bdgrp,"O+")==0)
	  cbg=3;
	 else if(strcmpi(bdgrp,"AB+")==0)
	  cbg=4;
	 else if(strcmpi(bdgrp,"A-")==0)
	  cbg=5;
	 else if(strcmpi(bdgrp,"B-")==0)
	  cbg=6;
	 else if(strcmpi(bdgrp,"O-")==0)
	  cbg=7;
	 else if(strcmpi(bdgrp,"AB-")==0)
	  cbg=8;
	 else
	 {
	  cbg=9;
	  cout<<"Enter valid Bloodgroup: ";
	  gets(bdgrp);
	 }
	}while(cbg==9);
 cout<<'\n';
 cout<<"Gender(If Female->F,Male->M): ";
 cin>>gend;
 while((toupper(gend)!='M')&&(toupper(gend)!='F'))
 {
  cout<<"Enter valid gender: ";
  cin>>gend;
 }
 cout<<'\n';
}
char* details::retid()
{
 return id;
}
int details::retage()
{
 return age;
}
void details::putdet()
{
 cout<<"ID: "<<id<<'\n';
 cout<<"Name: "<<name<<'\n';
 cout<<"Age: "<<age<<'\n';
 cout<<"Bloodgroup: "<<bdgrp<<'\n';
 cout<<"Gender: "<<gend<<'\n';
}
//class for general health
class general{
	      char q[100],a[5][20];
      public: void read();
	      void show();
	     }G;
void general::read()
{
 cout<<"Enter question:";
 gets(q);
 for(int i=0;i<3;i++)
 {
  cout<<"\nEnter option "<<(i+1)<<':';
  gets(a[i]);
 }
}
void general::show()
{
 cout<<q<<'\n';
 for(int i=0;i<3;i++)
  cout<<(i+1)<<'.'<<a[i]<<'\n';
 cout<<'\n';
}
//class for physical health
class physical{
		 char string[100];
		 public: void getques()
					{
					 gets(string);
					}
			 void putques()
				       {
					 cout<<string<<'\n';
				       }
				 }ph;
//class for mental health
class mental{
	     char question[100],option[5][20];

     public: void r();
	     void s();
				}m;
void mental::r()
{
 cout<<"Enter the question\n";
 gets(question);
 cout<<"Enter the options\n";
 for(int k=0;k<4;k++)
  gets(option[k]);
}
void mental::s()
{
 cout<<"Q."<<question<<'\n';
 for(int i=0;i<4;i++)
  cout<<option[i]<<'\n';
 cout<<'\n';
}
char i1[10];
int check1=1;
int checkid();
void updet(char Id[10]);
void cregen();
void crephy();
void cremen();
void ansgen();
void ansphy();
void ansmen();
void addition();
void update();
void deletion(char idd[10]);
void main()
{
 clrscr();
 int choice;
 int gdriver = DETECT,gmode;
 int x,y,i;
 initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
 x=getmaxx()/2;
 y=getmaxy()/2;
 for(i=30;i<200;i++)
 {
  delay(100);
  setcolor(i);
  arc(x,y,0,180,i-10);
 }
  outtextxy(310,250,"SHM");
  cout<<'\n';
  outtextxy(220,265,"Your health is our priority");
  cout<<'\n';
  outtextxy(295,280,"WELCOME");
  cout<<'\n';
  capture("C:\\TC\\Capture\\Capture1.jpg");
 clrscr();
 getch();
 closegraph();
 cout<<"Enter:\n1-If you are a user\n2-If you are an admin: ";
 cin>>choice;
 while(choice!=1&&choice!=2)
 {
  cout<<"Enter valid choice: ";
  cin>>choice;
 }
 clrscr();    //to clear previous outputs
 if(choice==1)
 {
  int ch;
  cout<<"\nEnter:\n1-To take the test\n2-To delete a person's record: ";
  cin>>ch;
  while(ch!=1&&ch!=2)
  {
   cout<<"Invalid choice.Please enter the correct choice: ";
   cin>>ch;
  }
  clrscr();
  if(ch==2)
  {
	char i[10];
	cout<<"\nEnter ID: ";
   cin>>i;
   ifstream f("details.dat",ios::binary);
   if(f)
	{
	 int flag=0;
    while(f.read((char*)&D,sizeof(D)))
    {
	  if(strcmp(D.retid(),i)==0)
     {
      flag=1;
		cout<<"Please verify the details of the person\n";
		D.putdet();
     }
    }
    f.close();
	 if(flag==0)
	 {
     cout<<'\n';
     cout<<"The entered ID does not exist\n";
    }
	 else
	  deletion(i);
   }
   else
    cout<<"\nFile is not opening";
  }
  else
  {
   int c;
   cout<<"\nEnter:\n1-If you are taking the quiz for the first time\n";
   cout<<"2-If this is not your first time: ";
   cin>>c;
	while(c!=1&&c!=2)
	{
	 cout<<"Invalid choice.\nPlease enter the correct choice: ";
	 cin>>c;
       }
  clrscr();
	if(c==1)
	{
    cout<<"SHM is committed to connecting people concerned about their health ";
    cout<<"with reviewed health quizzes.We wish you to";
    cout<<" take a proactive approach to your wellness.\n";
    cout<<"We will be assessing your General, Physical and Mental health.\n";
    ifstream f1("details.dat",ios::binary);
	 if(f1)
	 {
     int check=0;
     cout<<"Create your ID(of form SHMxx): ";
	  cin>>i1;                                  //declared globally
	  while(f1.read((char*)&D,sizeof(D)))
     {
      if(strcmp(D.retid(),i1)==0)
		 check=1;
     }
     f1.close();
	  while(check==1)
	  {
      check=checkid();
     }
     if(check==0)
	  {
		cout<<"Your ID has been successfully created\n";
      cout<<"Your ID is "<<i1<<'\n';
     }
    }
	 else
	  cout<<"File is not opening\n";
    ofstream fo("details.dat",ios::binary|ios::app);
    if(fo)
    {
	  D.getdet(i1);
	  fo.write((char*)&D,sizeof(D));
     fo.close();
    }
	 else
     cout<<"File is not opening\n";
   }
  else
  {
    char iddd[10];
    cout<<"Welcome back.We are delighted that you chose us again\n";
    cout<<"\nEnter ID: ";
    cin>>iddd;
    updet(iddd);
   }
   if(check1!=0)
   {
    cout<<'\n';
    cout<<"Lets's get started!";
    delay(5000);//to let the screen wait
    clrscr();
    int j;
    cout<<"The first round is the General health round";
    cout<<'\n';
    ansgen();
    for(j=1;j<=79;j++)
     cout<<"*";
    cout<<'\n';
    delay(10000);
    clrscr();
    cout<<"The second round is the Physical health round";
    cout<<'\n';
    ansphy();
    for(j=1;j<=79;j++)
     cout<<"*";
    delay(15000);
    clrscr();
    cout<<"The third round is the Mental health round";
    cout<<'\n';
    ansmen();
    for(j=1;j<=79;j++)
     cout<<"*";
    delay(10000);
    clrscr();
    cout<<"THANKS FOR CHOOSING US!:)\n";
    cout<<"Hope you had a comfortable experience\n";
    cout<<"Do recommend us to others\n";
   }
  }
 }
 else
 {
  char user[20],password[10];
  cout<<setw(450)<<"Welcome ADMIN\n";
  cout<<"Enter username:\n";
  gets(user);
  cout<<"Enter password:\n";
  gets(password);
  if(strcmp(user,"SHM")==0)
  {
   if(strcmp(password,"SHM122723")==0)
   {
	 int cc;
	 cout<<"Enter\n1.If you want to add questions\n";
    cout<<"2.If you want to update questions:\n";
    cin>>cc;
    while(cc!=1&&cc!=2)
	 {
	  cout<<"Enter valid choice: ";
     cin>>cc;
    }
    clrscr();
	 if(cc==1)
     addition();
    else
	  update();
	}
   else
    cout<<"Password is invalid\n";
  }
  else
	cout<<"Username is invalid\n";
 }
 getch();
}
//function to check id entered by user
int checkid()
{
 int f=0;
 char x[10];
 cout<<"ID already exists.\nPlease enter a different ID: ";
 cin>>x;
 strcpy(i1,x);
 ifstream fc("details.dat",ios::binary);
 if(fc)
 {
  while(fc.read((char*)&D,sizeof(D)))
  {
	if(strcmp(D.retid(),x)==0)
	 f=1;
  }
  fc.close();
 }
 else
  cout<<"File is not opening\n";
 return f;
}
//function to update the details of a person who has already come
void updet(char Id[10])
{
 fstream fi("details.dat",ios::binary|ios::in|ios::out);
 if(fi)
 {
  int flag=0,pos=0;
  while(fi.read((char*)&D,sizeof(D)))
  {
	if(strcmp(D.retid(),Id)==0)
	{
	 char cho;
	 flag=1;
	 cout<<"Please verify the details of the person\n";
	 D.putdet();
	 cout<<"Do you wish to update your details. If yes, enter Y\n";
	 cin>>cho;
	 if(toupper(cho)=='Y')
	 {
	  details du;
	  cout<<"Enter your details:\n";
	  du.getdet(Id);
	  fi.seekp(pos);
	  fi.write((char*)&du,sizeof(D));
	  cout<<"Details have been updated\n";
	  break;
	 }
	 else
	 {
	  cout<<"OK! So you wish to continue with the same details\n";
	  break;
	 }
	}
	pos=fi.tellg();
  }
  fi.close();
  if(flag==0)
  {
	cout<<'\n';
	check1=0;             //declared globally
	cout<<"The ID does not exist.You haven't taken the quiz before\n";
  }
 }
 else
  cout<<"The file is not opening\n";
}
//function for creating general health questions
void cregen()
{
 char ch;
 ofstream f("general.dat",ios::binary|ios::app);
 if(f)
 {
  do{
	  G.read();
	  f.write((char*)&G,sizeof(G));
	  cout<<"\nEnter Y to continue:";
	  cin>>ch;
	  cout<<"\n";
	 }while(toupper(ch)=='Y');
  f.close();
 }
 else
  cout<<"File is not created\n";
}
//function for creating physical health questions
void crephy()
{
 ofstream fp;
 fp.open("physical.dat",ios::binary|ios::app);
 char ch;
 if(fp)
 {
  cout<<"Enter questions one by one ";
  cout<<"Enter N if u want to stop entering\n";
  do{
	  ph.getques();
	  fp.write((char*)&ph,sizeof(ph));
	  cin>>ch;
	 }while(toupper(ch)!='N');
  fp.close();
 }
 else
  cout<<"File is not created\n";
}
//function for creating mental health questions
void cremen()
{
 char c;
 ofstream fin("mental.dat",ios::binary|ios::app);
 if(fin)
 {
  do{
	  m.r();
	  fin.write((char*)&m,sizeof(mental));
	  cout<<"Enter y to continue\n";
	  cin>>c;
	 }while(c=='y'||c=='Y');
  fin.close();
 }
 else
  cout<<"File is not created\n";
}
//function for answering general health questions
void ansgen()
{
 int op,B[50],k=0,tot=0;
 ifstream f1("general.dat",ios::binary);
 if(f1)
 {
  cout<<"Enter your option for the following questions\n";
  while(f1.read((char*)&G,sizeof(general)))
  {
	G.show();
	cout<<"Ans: ";
	cin>>op;
	while(op!=1&&op!=2&&op!=3&&op!=4)
	{
	 cout<<"Please enter correct option: ";
	 cin>>op;
	}
	if(op==1)
	 B[k]=3;
	else if(op==2)
	 B[k]=2;
	else if(op==3)
	 B[k]=1;
	k++;
  }
  for(int i=0;i<k;i++)
   tot=tot+B[i];
  cout<<'\n';
  for(int j=1;j<=79;j++)
   cout<<"*";
  cout<<'\n';
  cout<<"Your results for General Health:\n\n";
  cout<<"YOUR SCORE OUT OF "<<(3*k)<<" IS: "<<tot<<'\n';
  if(tot>(2*k))
    cout<<"You are healthy and fit.All the best for your healthy journey"<<'\n';
  else if(tot<=(2*k)&&tot>(1*k))
	cout<<"You are ok but you can do better.Avoid unhealthy eating habits\n";
  else
	cout<<"You are not at your best.Please avoid junk food and workout more\n";
  f1.close();
 }
 else
  cout<<"File is not opening\n";
}
//function for answering physical health questions
 void ansphy()
{
 ifstream fp;
 fp.open("physical.dat",ios::binary);
 int A[50],i=1,j;
 char ans;
 float bmi,h,w,lc,uc,r;
 if(fp)
 {
  cout<<"Enter Y or N for each and every question\n";
  while(fp.read((char*)&ph,sizeof(ph)))
  {
	ph.putques();
	if(i==1)
	{
	 if(D.retage()>=18)
	{
	 cout<<"Enter height(in m): ";
	 cin>>h;
	 cout<<"Enter weight(in kg): ";
	 cin>>w;
	 bmi=w/pow(h,2);
	 if(bmi<18.5)
	  A[i]=-1;
	 else if(bmi>=18.5&&bmi<=22.5)
	  A[i]=0;
	 else
	  A[i]=1;
	}
	 else
	  cout<<"You need not calculate BMI as your age is less than 18 years\n";
	}
	else
	{
	 cout<<"Ans: ";
	 cin>>ans;
	 while((toupper(ans)!='Y')&&(toupper(ans)!='N'))
	 {
	  cout<<"Enter vaild answer: ";
	  cin>>ans;
	 }
	 if(toupper(ans)=='Y')
	  A[i]=1;
	 else
	  A[i]=0;
	}
	i++;
  }
  cout<<'\n';
  for(int k=1;k<=79;k++)
   cout<<"*";
  cout<<'\n';
  cout<<"Your results for Physical Health:\n\n";
  for(j=1;j<=i;j++)
  {
	if(j==1)
	{
	 cout<<"Results for BMI:"<<'\n';
	 if(D.retage()>=18)
	{
	 if(A[j]==-1)
	  cout<<"You are underweight.Take care of your health\n";
	 else if(A[j]==1)
	  cout<<"You are obese.Take care of your health\n";
	 else
	  cout<<"Your BMI is normal\n";
	}
	 else
	  cout<<"You dont need to know your BMI level as you are underaged\n";
	}
	if(j==2)
	{
	 cout<<"Results for BP:\n";
	 if(A[j]==1)
	 {
	  cout<<"Enter your lower and upper limit of bp\n";
	  cin>>lc>>uc;
	  if((80<=lc&&lc<=90)&&(uc>=110&&uc<=120))
		cout<<"Your bp levels are normal\n";
	  else
		cout<<"Your bp levels are abnormal.Take care of your heart\n";
	 }
	 else
	  cout<<"You wont get bp\n";
	}
	if(j==3)
	{
	 cout<<"Results for Cholestrol:\n";
	 if(A[j]==1)
	 {
	  cout<<"Enter your cholestrol level\n";
	  cin>>r;
	  if(r>=180&&r<=220)
		cout<<"Your cholestrol levels are normal.You wont get attack\n";
	  else
		cout<<"Cholestrol levels are very alarming.You may get a heart attack\n";
	 }
	 else
	  cout<<"Your heart is functioning normally\n";
	}
	if(j==4)
	{
	 cout<<"Results for Diabetes:\n";
	 if(A[j]==1)
	  cout<<"If your parents have diabetes, you might get it\n";
	 else
	  cout<<"Sugar levels in your body is perfect\n";
	}
	if(j==5)
	{
	 cout<<"Results for Thyroid:\n";
	 if(A[j]==1)
	  cout<<"You may get thyroid\n";
	 else
	  cout<<"Your thyroid levels are normal\n";
	}
	if(j==6)
	{
	 cout<<"Results for Vitamin D:\n";
	 if(A[j]==1)
	  cout<<"You will have enough vitamin D in your body\n";
	 else
	  cout<<"You need to get Vitamin D.Stand in the sun\n";
	}
	if(j==7)
	{
	 cout<<"Results for Vitamin B12:\n";
	 if(A[j]==1)
	  cout<<"Check your vitamin B12 levels\n";
	 else
	  cout<<"Your vitamin B12 levels are normal\n";
	}
	if(j>8)
	{
	 cout<<"Other results:\n";
	 if(A[j]==1)
	  cout<<"Your body is normal\n";
	 else
	  cout<<"Take care of your body\n";
	 cout<<'\n';
	}
  }
  fp.close();
 }
 else
  cout<<"File is not opening\n";
}
//function for answering mental health questions
void ansmen()
{
 int na=0,lit=0,some=0,tot=0,ext=0,q=0;
 int ch;
 ifstream fin("mental.dat",ios::binary);
 if(fin)
 {
  cout<<"Enter your option for the following questions\n";
  while(fin.read((char*)&m,sizeof(mental)))
  {
	m.s();
	cout<<"Ans: ";
	cin>>ch;
	while(ch!=1&&ch!=2&&ch!=3&&ch!=4)
	{
	 cout<<"Enter valid option: ";
	 cin>>ch;
	}
	switch(ch)
	{
	 case 1:na++;break;
	 case 2:lit++;break;
	 case 3:some++;break;
	 case 4:ext++;break;
	}
	tot=3*ext+2*some+1*lit;
	q++;
  }
  cout<<'\n';
  for(int j=1;j<=79;j++)
   cout<<"*";
  cout<<'\n';
  cout<<"Your results for Mental Health:\n\n";
  cout<<"You are mentally healthy if your score is low\n";
  cout<<"Your score is "<<tot<<" out of "<<(3*q)<<'\n';
  if(tot>=(2.5*q))
  {
	cout<<"Your score falls in the high range region.";
	cout<<"You are experiencing significant depression ";
	cout<<"and it is recommended to see a doctor\n";
  }
  else if(tot>=(1.5*q)&&tot<(2.5*q))
  {
	cout<<"Your score falls in the moderate region.";
	cout<<"It is time to get help.Try talking about your problems to someone\n";
  }
  else if(tot>=(0.5*q)&&tot<(1.5*q))
   cout<<"You have some signs that may indicate depression.Please take care\n";
  else
  {
  cout<<"You do not show any sign of depression.";
  cout<<"Those low feelings will probably go away after the problem passes\n";
  }
  fin.close();
 }
 else
  cout<<"File is not opening\n";
}
//function to add questions
void addition()
{
 int ch;
 char c;
 cout<<"Enter 1 to add questions into general health category\n";
 cout<<"Enter 2 to add questions into physical health category\n";
 cout<<"Enter 3 to add questions into mental health catgory\n";
 cin>>ch;
 while(ch!=1&&ch!=2&&ch!=3)
 {
  cout<<"Enter valid choice: ";
  cin>>ch;
 }
 clrscr();
 if(ch==1)
 {
  ofstream f2("general.dat",ios::binary|ios::app);
  if(f2)
  {
	cout<<"Enter question you need to add alongwith the options\n";
	do{
		G.read();
		f2.write((char*)&G,sizeof(G));
		cout<<"Enter Y if you want to continue entering questions:\n";
		cin>>c;
		}while(toupper(c)=='Y');
	f2.close();
  }
  else
	cout<<"File is not created\n";
 }
 else if(ch==2)
 {
  ofstream f2("physical.dat",ios::binary|ios::app);
  if(f2)
  {
	cout<<"Enter question you need to add\n";
	do{
		ph.getques();
		f2.write((char*)&ph,sizeof(ph));
		cout<<"Enter y if you want to continue entering questions:\n";
		cin>>c;
		}while(toupper(c)=='Y');
   f2.close();
  }
  else
	cout<<"File is not opening\n";
  }
 else if(ch==3)
 {
  ofstream f2("mental.dat",ios::binary|ios::app);
  if(f2)
  {
	cout<<"Enter question you need to add alongwith the options\n";
	do{
      m.r();
		f2.write((char*)&m,sizeof(m));
		cout<<"Enter y if you want to continue entering questions:\n";
		cin>>c;
		}while(c=='y'||c=='y');
   f2.close();
  }
  else
	cout<<"File is not opening\n";
  }
}
//function to update questions
void update()
{
 int ch;
 cout<<"Enter the correct option to update the particular file\n";
 cout<<"Enter:\n1-General Health\n2-Physical health\n3-Mental health\n";
 cin>>ch;
 while(ch!=1&&ch!=2&&ch!=3)
 {
  cout<<"Enter valid choice: ";
  cin>>ch;
 }
 clrscr();
 fstream fu;
 int qno;
 char choice;
 if(ch==1)
 {
  fu.open("general.dat",ios::in|ios::out|ios::binary);
  if(fu)
  {
   general upd;
   do{
      cout<<"Enter question number you would want to update: ";
      cin>>qno;
      while(qno<1)
      {
       cout<<"Enter valid question number: ";
       cin>>qno;
      }
      cout<<"Enter the updated question alongwith the options\n";
      upd.read();
      fu.seekg((qno-1)*sizeof(G));
      fu.write((char*)&upd,sizeof(upd));
      cout<<"Enter Y if you want to continue updating questions\n";
      cin>>choice;
     }while(toupper(choice)=='Y');
   fu.close();
  }
  else
   cout<<"File is not opening\n";
 }
 else if(ch==2)
 {
  fu.open("physical.dat",ios::in|ios::out|ios::binary);
  if(fu)
  {
   physical upd;
   do{
      cout<<"Enter question number you would want to update: ";
      cin>>qno;
      while(qno<1)
      {
       cout<<"Enter valid question number: ";
       cin>>qno;
      }
      cout<<"Enter the updated question\n";
      upd.getques();
      fu.seekg((qno-1)*sizeof(ph));
      fu.write((char*)&upd,sizeof(upd));
      cout<<"Enter Y if you want to continue updating questions\n";
      cin>>choice;
     }while(toupper(choice)=='Y');
   fu.close();
  }
  else
   cout<<"File is not opening\n";
 }
 else if(ch==3)
 {
  fu.open("mental.dat",ios::in|ios::out|ios::binary);
  if(fu)
  {
   mental upd;
   do{
      cout<<"Enter question number you would want to update: ";
      cin>>qno;
      while(qno<1)
      {
       cout<<"Enter valid question number: ";
       cin>>qno;
      }
      cout<<"Enter the updated question alongwith the options\n";
      upd.r();
      fu.seekg((qno-1)*sizeof(m));
      fu.write((char*)&upd,sizeof(upd));
      cout<<"Enter Y if you want to continue updating questions\n";
      cin>>choice;
     }while(toupper(choice)=='Y');
   fu.close();
  }
  else
   cout<<"File is not opening\n";
 }
}
//function to delete a person's details
void deletion(char idd[10])
{
 ifstream f1("details.dat",ios::binary);
 ofstream f2("temp.dat",ios::binary);
 if(f1)
 {
  while(f1.read((char*)&D,sizeof(D)))
  {
	if(strcmp(D.retid(),idd)!=0)
	 f2.write((char*)&D,sizeof(D));
  }
  f2.close();
  f1.seekg(0,ios::end);
  if(f1.tellg()==0)
	cout<<"The person's record could not be deleted\n";
  else
	cout<<"The person's record has been deleted\n";
  f1.close();
 }
 else
  cout<<"File is not opening\n";
 remove("details.dat");
 rename("temp.dat","details.dat");
}












