#include<iostream.h>
#include<stdio.h>
#include<process.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<fstream.h>

void admin_menu();
void intro();
void opening();
void search_cust();
void search_date();

//LOGIN CLASS

class log
{
	public:
		char usr[20];
		fstream fp;
		fstream fps;
		void add_admin()
		{
			clrscr();
			cout<<"*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*";
			cout<<"\n\nEnter the Username : ";
			gets(usr);
		}

};


class write:public log
{
	private:
		log adm;
	public:
	write()
	{
		fp.open("LOGIN.TXT",ios::out|ios::app);
		add_admin();
		fp<<usr<<"\n";
		fp.close();
		cout<<"\n\n\t\t"<<usr<<" may now Proceed";
		getch();
		admin_menu();
		opening();
	}
};


class item
{
	int itno;
	char name[30];
	float price,qty,tax,dis;
	public:
		void create_item();
		void show_item();
		int retitno()
		{	return itno;	}
		float retprice()
		{	return price;	}
		char* retname()
		{	return name;	}
		int retdis()
		{	return dis;	}
};


void item::create_item()
{
	cout<<"\n\n\t*-*-*-*-*-*-*-*-* ADD YOUR ITEM *-*-*-*-*-*-*-*-*\n";
	cout<<"\n\t\tEnter The Item No. of The Item : ";
	cin>>itno;
	cout<<"\n\t\tEnter The Name of The Item : ";
	gets(name);
	cout<<"\n\t\tEnter The Price of The Item : ";
	cin>>price;
	cout<<"\n\t\tEnter The Discount (%) : ";
	cin>>dis;
}

void item::show_item()
{
	cout<<"\n\tThe Item No. of The Item : "<<itno;
	cout<<"\n\tThe Name of The Item : ";
	puts(name);
	cout<<"\n\tThe Price of The Item : "<<price;
	cout<<"\n\tDiscount : "<<dis;
}


class record
{
	public:
		void show_record();
		char cust[30];
		char item[30];
		char dates[15];
		int quant;
		float prices,amot,disamot;	
		char* retcname()
		{	return cust;	}
		char* retdate()
		{	return dates;	}		
};

void record::show_record()
{
	cout<<"\n\tThe Customer Name : ";
	puts(cust);
	cout<<"\n\tDate of purchase : ";
	puts(dates);
	cout<<"\n\tName of the Item Purchased : ";
	puts(item);
	cout<<"\n\tQuantity of Items : "<<quant;
	cout<<"\n\tAmount of single Item : "<<prices;
	cout<<"\n\tTotal Amount : "<<amot;
	cout<<"\n\tTotal Amount after Discount : "<<disamot;
}


class shopping:public log
{
	public:
	item pr;
	void place_order();
};


//-----------------------------------------------------------------------------------------------------------------------------------


// global declaration for stream object, object

fstream fp;
item pr;
record rec;

// function to write in file

void write_item()
{
	fp.open("INVEN.txt",ios::out|ios::app);
	pr.create_item();
	fp.write((char*)&pr,sizeof(item));
	fp.close();
	cout<<"\n\nThe Item has been Added ";
	getch();
}

// function to read all records from file

void display_all()
{
	clrscr();
	cout<<"\n\n\n\t\t*-*-*-*-*-*-*-* DISPLAYING ALL RECORDS *-*-*-*-*-*-*-*\n\n";
	fp.open("INVEN.txt",ios::in);
	while(fp.read((char*)&pr,sizeof(item)))
	{
		pr.show_item();
		cout<<"\n\n====================================\n";
		getch();
	}
	fp.close();
	getch();
}


// function to read specific record from file

void display_sp(int n)
{
	int flag=0;
	fp.open("INVEN.txt",ios::in);
	while(fp.read((char*)&pr,sizeof(item)))
	{
		if(pr.retitno()==n)
		{
			clrscr();
			pr.show_item();
			flag=1;
		}
	}
	fp.close();
	if(flag==0)
	cout<<"\n\nrecord not exist";
	getch();
}


// function to modify record of file


void modify_item()
{
	int no,found=0;
	clrscr();
	cout<<"\n\n\t\t*-*-*-*-*-*-*-*-*-*-*-* MODIFY YOUR ITEM *-*-*-*-*-*-*-*-*-*-*-* ";
	cout<<"\n\n\tEnter The Item No. of The Item";
	cin>>no;
	fp.open("INVEN.txt",ios::in|ios::out);
	while(fp.read((char*)&pr,sizeof(item)) && found==0)
	{
		if(pr.retitno()==no)
		{
			pr.show_item();
			cout<<"\n\tEnter The New Details of Item"<<endl;
			pr.create_item();
			int pos=-1*sizeof(pr);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&pr,sizeof(item));
			cout<<"\n\n\t Record Updated";
			found=1;
		}
	}
	fp.close();
	if(found==0)
	cout<<"\n\n Record Not Found ";
	getch();
}


// function to delete record of file


void delete_item()
{
	int no;
	clrscr();
	cout<<"\n\n\tDelete Record";
	cout<<"\n\n\tEnter The Item no. of The item You Want To Delete";
	cin>>no;
	fp.open("INVEN.txt",ios::in|ios::out);
	fstream fp2;
	fp2.open("TEMP.txt",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&pr,sizeof(item)))
	{
		if(pr.retitno()!=no)
		{
			fp2.write((char*)&pr,sizeof(item));
		}
	}
	fp2.close();
	fp.close();
	remove("INVEN.txt");
	rename("TEMP.txt","INVEN.txt");
	cout<<"\n\n\tRecord Deleted ...";
	getch();
}


// function to display all items price list


void menu()
{
	clrscr();
	fp.open("INVEN.txt",ios::in);
	if(!fp)
	{
		cout<<"ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Admin Menu to create File";
		cout<<"\n\n\n Program is closing ....";
		getch();
		exit(0);
	}
	cout<<"\n\n\t\*-*-*-*-*-*-*-*-*-*-*-* ITEM MENU *-*-*-*-*-*-*-*-*-*-*-*\n\n";
	cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
	cout<<"Item No.\t\tItem Name\t\tItem Price\n";
	cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
	while(fp.read((char*)&pr,sizeof(item)))
	{
		cout<<"  "<<pr.retitno()<<"\t\t\t"<<pr.retname()<<"\t\t\t"<<pr.retprice()<<endl;
	}
	fp.close();
}


// function to place order and generating bill for items


void shopping::place_order()
{
	char Cname[30];
	char date[15];

	cout<<"\n\n\t*-*-*-*-*-*-*-*-*-*-*-* WELCOME CUSTOMER *-*-*-*-*-*-*-*-*-*-*-*\n";
	cout<<"\n\t\tEnter the Name of Customer : \n\t\t";
	gets(Cname);
	cout<<"\n\t\tEnter the Date of Purchase (dd-mm-yyyy) : \n\t\t";
	gets(date);
	cout<<"\n\n\t\t"<<Cname<<" may now Proceed";
	getch();

	clrscr();
	int order_arr[50],quan[50],c=0;
	float amt,damt,total=0;
	char ch='Y';
	menu();

	cout<<"\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
	cout<<"\n*-*-*-*-*-*-*-*-* PLACE YOUR ITEMS *-*-*-*-*-*-*-*-*-*-*-*";
	cout<<"\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
	do{
	    cout<<"\n\nEnter The Item No. Of The Item : ";
	    cin>>order_arr[c];
	    cout<<"\nQuantity in number : ";
	    cin>>quan[c];
	    c++;
	    cout<<"\nDo You Want To Order Another item (Y/N)?";
	    cin>>ch;
	   }while(ch=='y' ||ch=='Y');

	cout<<"\n\nThank You For Placing The Order";
	getch();

	clrscr();
	cout<<"\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* YOUR BILL *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n";
	cout<<"\nItem No.   Item Name   Quantity    Price     Amount     Amount after discount\n";
	for(int x=0;x<=c;x++)
	{
		fp.open("INVEN.txt",ios::in);
		fp.read((char*)&pr,sizeof(item));
		while(!fp.eof())
		{
			if(pr.retitno()==order_arr[x])
			{
				amt=pr.retprice()*quan[x];
				damt=amt-(amt*pr.retdis()/100);
				cout<<"\n  "<<order_arr[x]<<"\t   "<<pr.retname()<<"\t\t"<<quan[x]<<"\t    "<<pr.retprice()<<"\t     "<<amt<<"\t\t"<<damt;
				total+=damt;

				fps.open("RECORD.txt",ios::out|ios::app);
				strcpy(rec.cust,Cname);
				strcpy(rec.dates,date);
				strcpy(rec.item,pr.retname());
				rec.quant = quan[x];
				rec.prices = pr.retprice();
				rec.amot = amt;
				rec.disamot = damt;
				fps.write((char*)&rec,sizeof(record));
				fps.close();
			}
			fp.read((char*)&pr,sizeof(item));
		}
		fp.close();
	}
	cout<<"\n\n\t\t\t\t\tTOTAL = "<<total;
	getch();
	opening();
}

// INTRODUCTION FUNCTION

void intro()
{
	clrscr();
	gotoxy(23,5);
	cout<<"|=*=|=*=|=*=|=*=|=*=|=*=|=*=|=*=|=*=|";
	gotoxy(18,5);cout<<"||";gotoxy(18,6);cout<<"||";gotoxy(18,7);cout<<"||";gotoxy(18,8);cout<<"||";gotoxy(18,19);cout<<"||";gotoxy(18,20);cout<<"||";
	gotoxy(18,9);cout<<"||";gotoxy(18,10);cout<<"||";gotoxy(18,11);cout<<"||";gotoxy(18,12);cout<<"||";gotoxy(18,13);cout<<"||";
	gotoxy(18,14);cout<<"||";gotoxy(18,15);cout<<"||";gotoxy(18,16);cout<<"||";gotoxy(18,17);cout<<"||";gotoxy(18,18);cout<<"||";
	gotoxy(33,9);
	cout<<"INVENTORY MANAGEMENT";
	gotoxy(38,12);
	cout<<"SYSTEM";
	gotoxy(38,15);
	cout<<"PROJECT";
	gotoxy(63,5);cout<<"||";gotoxy(63,6);cout<<"||";gotoxy(63,7);cout<<"||";gotoxy(63,8);cout<<"||";gotoxy(63,19);cout<<"||";gotoxy(63,20);cout<<"||";
	gotoxy(63,9);cout<<"||";gotoxy(63,10);cout<<"||";gotoxy(63,11);cout<<"||";gotoxy(63,12);cout<<"||";gotoxy(63,13);cout<<"||";
	gotoxy(63,14);cout<<"||";gotoxy(63,15);cout<<"||";gotoxy(63,16);cout<<"||";gotoxy(63,17);cout<<"||";gotoxy(63,18);cout<<"||";
	gotoxy(23,20);
	cout<<"|=*=|=*=|=*=|=*=|=*=|=*=|=*=|=*=|=*=|";
	delay(900);
	gotoxy(32,22);
	cout<<"YOU ARE WELCOME !!!";
	getch();
}


// ADMINSTRATOR MENU FUNCTION

void admin_menu()
{
char o1;
do{
	clrscr();
	char ch2;
	cout<<"\n\n\t*-*-*-*-*-*-*-*-* WELCOME ADMINISTRATOR *-*-*-*-*-*-*-*-*";
	cout<<"\n\n\t\t|-|-|-|-|- ADMIN MENU -|-|-|-|-|";
	cout<<"\n\n\t||\t1.  Add new Item           \t\t||";
	cout<<"\n\n\t||\t2.  Display all Items      \t\t||";
	cout<<"\n\n\t||\t3.  Search specific Item   \t\t||";
	cout<<"\n\n\t||\t4.  Modify specific Item   \t\t||";
	cout<<"\n\n\t||\t5.  Delete specific Item   \t\t||";
	cout<<"\n\n\t||\t6.  View the Item Menu     \t\t||";
	cout<<"\n\n\t||\t7.  Back to the Main Menu  \t\t||";
	cout<<"\n\n\t\tPlease Enter Your Choice\n";
	ch2=getche();
	switch(ch2)
	{
		case '1': clrscr();
		write_item();
		break;
		case '2': display_all();
		break;
		case '3':
		int num;
		clrscr();
		cout<<"\n\n\tPlease Enter The item No. ";
		cin>>num;
		display_sp(num);
		break;
		case '4': modify_item();
		break;
		case '5': delete_item();
		break;
		case '6': menu();
		break;
		case '7': break;
		default:cout<<"Please Select a valid option";
			admin_menu();
	}
	cout<<"\n\n\t\tDo You want to Continue (Y/N)?";
	cin>>o1;
    }while(o1=='Y'||o1 =='y');
}


//  MANAGER MENU FUNCTION

void search_cust()
{
	char cusnam[30];
	clrscr();
	cout<<"\n\n\t*-*-*-*-*-*-*-*-*-* CUSTOMER SECTION *-*-*-*-*-*-*-*-*-*-* \n";
	cout<<"\t\tEnter the Customer Name :\n\t\t";
	gets(cusnam);
	int flag=0;
	fp.open("RECORD.txt",ios::in);
	fp.read((char*)&rec,sizeof(record));
	while(!fp.eof())
	{
		if(strcmp(rec.retcname(),cusnam)==0)
		{
			rec.show_record();
			cout<<"\n\n\t====================================\n";
			getch();
			flag=1;
		}
		fp.read((char*)&rec,sizeof(record));
	}
	fp.close();
	if(flag==0)
	cout<<"\n\n\t\trecord not exist";
	getch();
}


void search_date()
{
	char da[15];
	clrscr();
	cout<<"\n\n\t*-*-*-*-*-*-*-*-*-* SALE OF A DAY *-*-*-*-*-*-*-*-*-*-* \n";
	cout<<"\t\tEnter the Date of Purchase (dd-mm-yyyy) :\n\t\t";
	gets(da);
	int flag=0;
	fp.open("RECORD.txt",ios::in);
	fp.read((char*)&rec,sizeof(record));
	while(!fp.eof())
	{
		if(strcmp(rec.retdate(),da)==0)
		{
			rec.show_record();
			cout<<"\n\n\t====================================\n";
			getch();
			flag=1;
		}
		fp.read((char*)&rec,sizeof(record));
	}
	fp.close();
	if(flag==0)
	cout<<"\n\n\t\trecord not exist";
	getch();
}

//  FIRST SCREEN

void opening()
{
	char opt1, ch;
	char opt2;
	clrscr();
	cout<<"\n\n\n\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* \n";
	cout<<"\t -!-!-!-!-!-!-!-!-!-! SALES INVENTORY !-!-!-!-!-!-!-!-!-! \n";
	cout<<"\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n";
	cout<<"\t\t-------Choose your option-------"<<endl;
	cout<<"\n\n\t\t1. Enter as Administrator \n\n\t\t2. Enter as Customers \n\n\t\t3. Enter as Manager \n\n\t\t4. Exit\n";
	opt1=getche();
	switch(opt1)
	{
		case '1':clrscr();
			 cout<<"\n\n\n\t\t*-*-*-*-*-*-*-*-*-*-*-* WELCOME ADMINISTRATOR *-*-*-*-*-*-*-*-*-*-*-*\n";
			 cout<<"\n\t\t Login as Administrator ";
			 write mem;
			 break;
		case '2':clrscr();
			 shopping shop;
			 shop.place_order();
			 break;
		case '3':clrscr();
			 cout<<"\n\n\n\t*-*-*-*-*-*-*-*-*-*-*-* VIEW PURCHASES *-*-*-*-*-*-*-*-*-*-*-*\n\n";
			 cout<<"\t\t 1. By a particular Customer \n\n";
			 cout<<"\t\t 2. On a particular Date \n\n";
			 cout<<"\t\t 3. Back To Main Menu \n\n";
			 cout<<"\t\t-------Choose your option-------"<<endl;
			 opt2=getche();
			 switch(opt2)
			 {
				 case '1':search_cust();
					  opening();
					  break;
				 case '2':search_date();
					  opening();
					  break;
				 case '3':opening();
					  break;
				 default:cout<<"\nPlease Select a valid option";
			 }
		case '4':clrscr();
			 cout<<"\n\n\n\n\n\t\t|=*=|=*=|=*=|=*=|=*=|=*=|=*=|=*=|=*=|";
			 delay(900);
			 cout<<"\n\n\t\t\tMADE BY : MEET MEHTA";
			 delay(900);
			 cout<<"\n\n\t\t\tTHANKS FOR VISITING !!!";
			 delay(1000);
			 exit(0);
			 break;
		default:cout<<"\nPlease Select a valid option";
			getch();
			opening();
			break;
	}
}

void main()
{
	textcolor(14);
	textbackground(6);
	intro();
	opening();
	getch();
}