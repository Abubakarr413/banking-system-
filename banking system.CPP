#include <fstream.h>
#include <conio.h>
#include <iomanip.h>
#include <stdio.h>
#include <string.h>
#include <process.h>
void login();
void Manager();
void trans(char);
int gentransid();
int genaccountno();
class bank
{ private: char name[26];

	   char address[50];
	   long phoneno;
	   char pan[10];
	   char dob[10];
  public:
		int accountno;
	    double balamt; //balamt: balance amount
	       void feed_info();
	       void show_info();
	       void deleterecord();
	       int retaccountno()
	       { return accountno;
	       }

}bnk;
void bank::feed_info()
 {           clrscr();
	     cout<<"Enter customer name : ";
	     gets (name);

	     cout<<"Enter customer address : ";
	     gets (address);
	     cout<<"Enter customer phone no. : ";
	     cin >>phoneno;
	     cout<<"Enter customer PAN no. : ";
	     gets (pan);
	     cout<<"Enter customer DOB in DD/MM/YYYY : ";
	     gets (dob);
	     cout<<"Enter balance amount : ";
	     cin>>balamt;
}
void bank::show_info()
{      clrscr();
       cout << setfill('-') << setw(1) << "+" << setw(7) << "-" <<          setw(1) << "+"<<setw(9) << "-" <<                setw(1) << "+" << setw(10) << "-" <<          setw(1) << "+" << setw(10) << "-"<<        setw(1) << "+"<< setw(8) << "-" << setw(1) << "+"<< setw(11) << "-" << setw(1) << "+"<< setw(11) << "-" <<setw(1) << "+" << endl;

       cout << setfill(' ') << setw(1) << "|" << setw(7) << "acc_no." <<    setw(1) << "|"<<setw(9) << "cust. add" <<        setw(1) << "|" << setw(10) << "cust_name:" << setw(1) << "|" << setw(10) << "phone no."<<setw(1)<< "|" << setw(8) << "PAN no" << setw(1) << "|"<< setw(11) << "Cust_DOB" << setw(1) << "|" << setw(11) << "balance Amt" << setw(1) << "|" <<endl;

       cout << setfill('-') << setw(1) << "+" << setw(7) << "-" <<          setw(1) << "+"<<setw(9) << "-" <<                setw(1) << "+" << setw(10) << "-" <<          setw(1) << "+" << setw(10) << "-"<<       setw(1) << "+"<<  setw(8) << "-" << setw(1) << "+"<< setw(11) << "-" << setw(1) << "+"<<setw(11) << "-" <<setw(1) << "+" << endl;

       cout << setfill(' ') << setw(1) << "|" << setw(7) << accountno<<     setw(1) << "|"<<setw(9) << address <<            setw(1) << "|" << setw(10) << name<<          setw(1) << "|" << setw(10) << phoneno<<   setw(1)<<"|" <<   setw(8) << pan << setw(1) << "|"<< setw(11) << dob << setw(1) << "|" << setw(11) << balamt<< setw(1) << "|" <<endl;

       cout << setfill('-') << setw(1) << "+" << setw(7) << "-" <<          setw(1) << "+"<<setw(9) << "-" <<                setw(1) << "+" << setw(10) << "-" <<          setw(1) << "+" << setw(10) << "-"<<       setw(1) << "+"<<  setw(8) << "-" << setw(1) << "+"<< setw(11) << "-" << setw(1) << "+"<< setw(11) << "-" <<setw(1) << "+" << endl;
       cout<<"\n\n\t\t\tPress any key to continue.....";
	getch();
}
class transaction
{ private : int accountno;
	    char type;

  public : int tid; //tid:transaction ID
	    int DD;
	    int MM;
	    int YY;
	    double amount;
	    void feedtrans(int t, int acno, char T, double amt, int d, int m, int y)
		{
	       tid = t;
	      accountno = acno;
	      type = T;
	      DD = d;
	      MM = m;
	      YY = y;
	      amount = amt;
		}
	    void showtrans()
	    {  clrscr();
	   cout << setfill('-') << setw(1) << "+" << setw(9) << "-" <<          setw(1) << "+"<<setw(7) << "-" <<                setw(1) << "+" << setw(4) << "-" <<          setw(1) << "+" << setw(10) << "-"<<       setw(1) << "+"<<  endl;

	   cout << setfill(' ') << setw(1) << "|" << setw(9) << "trans_id." <<    setw(1) << "|"<<setw(7) << "acc_no." <<        setw(1) << "|" << setw(4) << "Type" <<       setw(1) << "|" << setw(10) << "Amount"<<        setw(1)<< "|" << endl;

	   cout << setfill('-') << setw(1) << "+" << setw(9) << "-" <<          setw(1) << "+"<<setw(7) << "-" <<                setw(1) << "+" << setw(4) << "-" <<          setw(1) << "+" << setw(10) << "-"<<       setw(1) << "+"<< endl;

	   cout << setfill(' ') << setw(1) << "|" << setw(9) << tid<<     setw(1) << "|"<<setw(7) << accountno <<                setw(1) << "|" << setw(4) << type<<          setw(1) << "|" << setw(10) << amount<<    setw(1)<<"|" << endl;

	   cout << setfill('-') << setw(1) << "+" << setw(9) << "-" <<          setw(1) << "+"<<setw(7) << "-" <<                setw(1) << "+" << setw(4) << "-" <<          setw(1) << "+" << setw(10) << "-"<<       setw(1) << "+"<< endl;
       cout<<"\n\n\t\t\tPress any key to continue.....";
	getch();
	    }
       rettransid()
	   {  return tid;
		 }

  }trn;
int gentransid()
{ ifstream ob;
ob.open("transaction.txt",ios::in);
if(!ob)
{  return 101;
}
ob.seekg(-1*sizeof(trn),ios::end);
ob.read((char*)&trn,sizeof(trn));
int x=trn.rettransid();
x++;
ob.close();
return x;
}
int genaccountno()
{ ifstream ob;
ob.open("bank.txt",ios::in);
if(!ob)
{
  return 1;
}
ob.seekg(-1*sizeof(bnk),ios::end);
ob.read((char*)&bnk,sizeof(bnk));
int x=bnk.retaccountno();
x++;
ob.close();
return x;
}


 void writecustomer()
  {     cout<<"Enter data\n ";
       bnk.feed_info();
       bnk.accountno=genaccountno();
       cout<<"account no is : "<<bnk.accountno;
       getch();
       ofstream ob;
       ob.open("bank.txt",ios::app);

      ob.write((char*)&bnk,sizeof(bnk));
      if(ob)
      cout<<"Data has been added";
      else
      cout<<"file is not created";
      ob.close();
    }

void readcustomer()
  { ifstream ob;
    ob.open("bank.txt",ios::in);
    while(ob.read((char*)&bnk,sizeof(bnk)))
   {
    bnk.show_info();
   }
    ob.close();
}
void searchcustomer()
  {ifstream ob;
   ob.open("bank.txt",ios::in);
   cout<<"Enter the account no. u want to find : ";
   int x;
 cin>>x;
 while(ob.read((char*)&bnk,sizeof(bnk)))
 { if(bnk.retaccountno()==x)
   bnk.show_info();
 }       ob.close();
}

void writetransaction(int tid, int accountno,char type, double amount,int DD,int MM,int YY)
{  ofstream ob;
 int x,y;
 ob.open("transaction.txt",ios::app);
 trn.feedtrans(tid,accountno,type,amount,DD,MM,YY);
 ob.write((char*)&trn,sizeof(trn));
 ob.close();
}
void readtransaction()
{ifstream ob("transaction.txt");

 while(ob.read((char*)&trn,sizeof(trn)))
{ trn.showtrans();
}
 ob.close();
}
void searchtransaction()
  {ifstream ob;
    int Y;
    int d,m,y;
   ob.open("transaction.txt",ios::in);
   cout<<"Search by \n\t1.Account no.\n\t2.By Date OF Transaction\n\t3/Monthly transaction\n";
   cout<<"enter your choice : ";
   cin>>Y;
   if(Y==1)
     { cout<<"enter the account no. u want to find : ";
       int x;
       cin>>x;
       while(ob.read((char*)&bnk,sizeof(bnk)))
      {if(bnk.retaccountno()==x)
       trn.showtrans();
      } ob.close();
     }

  else if(Y==2)
      {

	    cout<<"Enter the date on DD MM YY : ";
	cin>>d>>m>>y;
	while(ob.read((char*)&bnk,sizeof(bnk)))
       { if(trn.DD==d && trn.MM==m && trn.YY==y)
	 trn.showtrans();
       }ob.close();
     }
   else
     {  cout<<"Enter the date on DD MM YY : ";
	cin>>m>>y;
	while(ob.read((char*)&bnk,sizeof(bnk)))
       { if(trn.MM==m && trn.YY==y)
	 trn.showtrans();
       } ob.close();
		}
}
float checkbalance(float withdrawl,int accountno)
{ ifstream ob;
	float A;
ob.open("bank.txt",ios::in);
  while(ob.read((char*)&bnk,sizeof(bnk)))
  {
    if(bnk.retaccountno()==accountno)
	 A = bnk.balamt-withdrawl;
}
	ob.close();
	return A;
}
void modify(double amount, int accountno)
{ fstream ob;
   ob.open("bank.txt",ios::in|ios::out);
   int count = 0;
    while(ob.read((char*)&bnk,sizeof(bnk)))
   { if(bnk.retaccountno()== accountno)
	{
	bnk.balamt -= amount;
	ob.seekg(count*sizeof(bnk), ios::beg);
	ob.write((char*)&bnk, sizeof(bnk));
	}
	count++;
	ob.close();

}
}
void deposit(int accountno,double amount)
{	fstream ob;
	ob.open("bank.txt",ios::in|ios::out);
	       int count = 0,tid;
		while(ob.read((char*)&bnk,sizeof(bnk)))
		{ 	if(bnk.retaccountno()== accountno)
			{ 	bnk.balamt += amount;
				ob.seekg(count*sizeof(bnk), ios::beg);
				ob.write((char*)&bnk, sizeof(bnk));
			}
			count++;
		}
		      ob.close();
}
void trans(char t)
{
       float withdrawal;
	int tid; //tid:transaction ID
	int accountno;
	char type=t;
	int DD,MM,YY;
	double amount;
	clrscr();
	tid = gentransid();
	cout<<"Your transaction id is: "<<tid;
	cout<<"\nEnter account no : ";
	cin>>accountno;
    cout<<"\nEnter ammount : ";
	cin >> amount;
	cout<<"\nEnter date in form of DD(space)MM(space)YY : ";
	cin>>DD>>MM>>YY;
	if ( type == 'w' || type == 'W')
	{
		if(checkbalance(accountno, withdrawal)<1000)
		{
			cout<<"\nYour balance has been withdrawn : ";
			modify(amount, accountno);
			writetransaction(tid,accountno,type,amount,DD,MM,YY);
		}
		else
		cout<<"\nAmount can not be withdrawn the leftout balance is less than 1000";
	}
	else if(type=='d'||type=='D')
	{	deposit(accountno,amount);
		writetransaction(tid, accountno, type, amount, DD, MM, YY);
	}
	cout<<"\n\n\t\t\tPress any key to continue.....";
	getch();
}
void bank::deleterecord()
{
	cout<<"\n\t\t\t"<<"  Delete Record  ";
	cout<<endl<<endl;
	ifstream ob1;
	ofstream ob2;
	char ch;
	int flag=0;
	int account;
	cin>>account;
	ob1.open("bank.txt",ios::in|ios::binary);
	ob2.open("temp.txt",ios::out|ios::binary);
	if(!ob1)
	{
		cout<<"\nfile does not exist";
		return;
	}
	while(ob1.read((char*)&bnk,sizeof(bnk)))
	{
		if(bnk.retaccountno()!=accountno)
		{
			ob2.write((char*)&bnk,sizeof(bnk));
		}
		else
		{
			flag=1;
			cout<<"\ndo you want to delete it:y/n";
			cin>>ch;
			if(ch=='y'||ch=='Y')
			{     	cout<<"\nAccount is deleated";
			}
			else
			{
				ob2.write((char*)&bnk,sizeof(bnk));
			}
		}
	}
	ob1.close();
	ob2.close();
	remove("bank.txt");
	rename("temp.dat","bank.dat");
	if(flag==0)
	{
		cout<<"\n Account has already deleated";
	}
	cout<<"\n\n\t\t\tPress any key to continue.....";
	getch();
}
void clerk()
{  int x;
	clrscr();
	do
	{       clrscr();
		cout<<"1.add an account\n2.Enquire an account\n3.Close an account\n4.Main Menu\n";
		cout<<"\n\n\n\t Enter your choice : ";
		cin>>x;
		switch (x)
		{
		case 1: writecustomer();
			break;
		case 2: searchcustomer();
			break;
		case 3: bnk.deleterecord();
		    break;
		case 4: return;
		default: cout<<"wrong input";
			return;
		}
	}while(x<5);
	getche();
}
void Manager()
{ int x;
  clrscr();
  do
  { clrscr();
   cout<<"1.see a customer's account\n2.See all account\n3.transaction of a account\n4.Main menu";
   cout<<"\n\n\n\t Enter your choice : ";
   cin>>x;
   switch(x)
      {
       case 1: searchcustomer();
		break;
       case 2: readcustomer();
		break;
       case 3: readtransaction();
		    break;
       case 4: return;
	}
   }while(x<5);
}
void cashier()
{  int x;
   clrscr();
   do
  { clrscr();
    cout<<"1.deposit amount\n2. Withdraw Amount\n3.Return to main menu";
    cout<<"\n\n\n\t Enter your choice : ";
   cin>>x;
   switch(x)
      {
       case 1: trans('d');
		break;
       case 2: trans('w');
		    break;
       case 3: return;

       default: cout<<"wrong input";
		return;
	}
   }while(x<4);
}
void login()
{  char a[15],b[15];         //a is username :: b is password
   clrscr();
   cout<<"Enter users name : ";
   gets(a);
   cout<<"Enter password : ";
   gets(b);
   if(strcmp(a,"clerk")==0)
   {	if(strcmp(b,"pass@123")==0)
		clerk();
   }
   else  if(strcmp(a,"cashier")==0)
	 {
		if(strcmp(b,"pass@456")==0)
			cashier();
	 }
  else  if(strcmp(a,"manager")==0)
	{
		if(strcmp(b,"pass@789")==0)
			Manager();
	 }
}
void main()
{	clrscr();
	int d;
	do
	{       clrscr();
		cout<<"\t\t\t !!^_^ Welcome to A_K Bank Of India^_^!!."<<endl;
		cout<<"\n\n\n\t "<<endl;
		cout<<"\n\t1.Login\n\t2.About us \n\t3.Exit\n";
		cout<<"\n\n\n\t Enter your choice : ";
		cin>>d;
		if(d == 1)
			login();
		else if(d == 2)
			 cout<<"ABOUT US";
	       else
			 exit(0);
	}while(d<3);
	getch();

}



