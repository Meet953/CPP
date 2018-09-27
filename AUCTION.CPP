
// HEADER FILE USED IN PROJECT

#include<conio.h>
#include<stdio.h>
#include<iostream.h>
#include<string.h>
#include<process.h>
#include<fstream.h>

void man_menu();
void aud();
void respo();
void mainpro();

class exhibit
{
	char bike[25],car[25],truck[25];
	int b_no,c_no,t_no;
	char b_sp[50],c_sp[50],t_sp[50];
	char b_yr[10],c_yr[10],t_yr[10];
	char b_co[10],c_co[10],t_co[10];
	public:
		void add_bike()
		{
		cout<<"\n\n\t =============== ADD BIKE ===============";
		cout<<"\n\n\tEnter the Model No. of Bike\n\t";
		cin>>b_no;
		cout<<"\n\tEnter the Bike Name\n\t";
		gets(bike);
		cout<<"\n\tEnter the Colour Of Bike\n\t";
		gets(b_co);
		cout<<"\n\tEnter the Year of Manufacture of Bike\n\t";
		gets(b_yr);
		cout<<"\n\tSpeciality of the Bike\n\t";
		gets(b_sp);
		}

		void show_bike()
		{
		cout<<"\n\n\t=============== BIKE EXHIBITON =================";
		cout<<"\n\t\tModel No. of the Bike : "<<b_no;
		cout<<"\n\t\tName of the Bike : ";
		puts(bike);
		cout<<"\n\t\tColour of the Bike : ";
		puts(b_co);
		cout<<"\n\t\tYear of Manufacture of the Bike : ";
		puts(b_yr);
		cout<<"\n\t\tSpeciality of the Bike : ";
		puts(b_sp);
		}

		void add_car()
		{
		cout<<"\n\n\t =============== ADD CAR ===============";
		cout<<"\n\n\tEnter the Model No. of Car\n\t";
		cin>>c_no;
		cout<<"\n\tEnter the Car Name\n\t";
		gets(car);
		cout<<"\n\tEnter the Colour Of Car\n\t";
		gets(c_co);
		cout<<"\n\tEnter the Year of Manufacture of Car\n\t";
		gets(c_yr);
		cout<<"\n\tSpeciality of the Car\n\t";
		gets(c_sp);
		}

		void show_car()
		{
		cout<<"\n\n\t=============== CAR EXHIBITON =================";
		cout<<"\n\t\tModel No. of the Car : "<<c_no;
		cout<<"\n\t\tName of the Car : ";
		puts(car);
		cout<<"\n\t\tColour of the Car : ";
		puts(c_co);
		cout<<"\n\t\tYear of Manufacture of the Car : ";
		puts(c_yr);
		cout<<"\n\t\tSpeciality of the Car : ";
		puts(c_sp);
		}

		void add_truck()
		{
		cout<<"\n\n\t =============== ADD TRUCK ===============";
		cout<<"\n\n\tEnter the Model No. of Truck\n\t";
		cin>>t_no;
		cout<<"\n\tEnter the Truck Name\n\t";
		gets(truck);
		cout<<"\n\tEnter the Colour Of Truck\n\t";
		gets(t_co);
		cout<<"\n\tEnter the Year of Manufacture of Truck\n\t";
		gets(t_yr);
		cout<<"\n\tSpeciality of the Truck\n\t";
		gets(t_sp);
		}

		void show_truck()
		{
		cout<<"\n\n\t=============== TRUCK EXHIBITON =================";
		cout<<"\n\t\tModel No. of the Truck : "<<t_no;
		cout<<"\n\t\tName of the Truck : ";
		puts(truck);
		cout<<"\n\t\tColour of the Truck : ";
		puts(t_co);
		cout<<"\n\t\tYear of Manufacture of the Truck : ";
		puts(t_yr);
		cout<<"\n\t\tSpeciality of the Truck : ";
		puts(t_sp);
		}

		int retbno(){return b_no;}
		int retcno(){return c_no;}
		int rettno(){return t_no;}
		char* retbike(){return bike;}
		char* retcar(){return car;}
		char* rettruck(){return truck;}
		char* retbcol(){return b_co;}
		char* retccol(){return c_co;}
		char* rettcol(){return t_co;}
		char* retbyr(){return b_yr;}
		char* retcyr(){return c_yr;}
		char* rettyr(){return t_yr;}
		char* retbsp(){return b_sp;}
		char* retcsp(){return c_sp;}
		char* rettsp(){return t_sp;}
};


class review
{
	public:

	char bk[25],cr[25],tk[25];
	int bk_no,cr_no,tk_no;
	char bk_co[10],cr_co[10],tk_co[10];
	int bk_rat,cr_rat,tk_rat;

		void view_bike()
		{
		cout<<"\n\n\t=============== BIKE REVIEWS =================";
		cout<<"\n\t\tModel No. of the Bike : "<<bk_no;
		cout<<"\n\t\tName of the Bike : ";
		puts(bk);
		cout<<"\n\t\tColour of the Bike : ";
		puts(bk_co);
		cout<<"\n\t\tRatings of the Bike : "<<bk_rat;
		}

		void view_car()
		{
		cout<<"\n\n\t=============== CAR REVIEWS =================";
		cout<<"\n\t\tModel No. of the Car : "<<cr_no;
		cout<<"\n\t\tName of the Car : ";
		puts(cr);
		cout<<"\n\t\tColour of the Car : ";
		puts(cr_co);
		cout<<"\n\t\tRatings of the Car : "<<cr_rat;
		}

		void view_truck()
		{
		cout<<"\n\n\t=============== TRUCK REVIEWS =================";
		cout<<"\n\t\tModel No. of the Truck : "<<tk_no;
		cout<<"\n\t\tName of the Truck : ";
		puts(tk);
		cout<<"\n\t\tColour of the Truck : ";
		puts(tk_co);
		cout<<"\n\t\tRatings of the Truck : "<<tk_rat;
		}
};


fstream fp;
exhibit ex;
review rev;

void man_menu()
{
	char ch1;
	clrscr();
	cout<<"\n\n\t*-*-*-*-*-*-*-*SELECT YOUR EXHIBITION VEHICLE *-*-*-*-*-*-*-*-*";
	cout<<"\n\n\t\t1.  BIKE";
	cout<<"\n\n\t\t2.  CAR";
	cout<<"\n\n\t\t3.  TRUCK";
	cout<<"\n\n\t\t4.  BACK TO MENU\n\n\t\t";
	cin>>ch1;
	switch(ch1)
	{
		case'1':char ch2;
			clrscr();
			cout<<"\n\n\t=============== BIKE ===============";
			cout<<"\n\n\t\t1. ADD BIKE IN EXHIBHITION";
			cout<<"\n\n\t\t2. REMOVE BIKE FROM EXHIBITION";
			cout<<"\n\n\t\t3. VIEW BIKE IN EXHIBITION";
			cout<<"\n\n\t\t4. BACK";
			cout<<"\n\n\tEnter your choice\n\n\t";
			cin>>ch2;
			switch(ch2)
			{
				case'1':clrscr();
				fp.open("BIKE.txt",ios::out|ios::app);
				ex.add_bike();
				fp.write((char*)&ex,sizeof(exhibit));
				fp.close();
				cout<<"\n\t\tBIKE IS ADDED TO EXHIBITION";
				getch();
				break;

				case'2':int no;
				clrscr();
				cout<<"\n\n\t================= REMOVE BIKE ================= ";
				cout<<"\n\n\tEnter the Model No. of Bike\n\t";
				cin>>no;
				fp.open("BIKE.txt",ios::in|ios::out);
				fstream fp2;
				fp2.open("TBIKE.txt",ios::out);
				fp.seekg(0,ios::beg);
				while(fp.read((char*)&ex,sizeof(exhibit)))
				{
					if(ex.retbno()!=no)
					{
					fp2.write((char*)&ex,sizeof(exhibit));
					}
				}
				fp2.close();
				fp.close();
				remove("BIKE.txt");
				rename("TBIKE.txt","BIKE.txt");
				cout<<"\n\n\t============= BIKE WAS REMOVED SUCCESSFULLY ===============";
				getch();
				break;

				case'3':clrscr();
				fp.open("BIKE.txt",ios::in);
				while(fp.read((char*)&ex,sizeof(exhibit)))
				{
				ex.show_bike();
				cout<<"\n\n====================================\n";
				getch();
				}
				fp.close();
				getch();
				break;

				case'4':man_menu();
				break;

				default:cout<<"\n\n\t\tWRONG CHOICE ";
			}
			break;

		case'2':char ch3;
			clrscr();
			cout<<"\n\n\t=============== CAR ===============";
			cout<<"\n\n\t\t1. ADD CAR IN EXHIBHITION";
			cout<<"\n\n\t\t2. REMOVE CAR FROM EXHIBITION";
			cout<<"\n\n\t\t3. VIEW CAR IN EXHIBITION";
			cout<<"\n\n\t\t4. BACK";
			cout<<"\n\n\tEnter your choice\n\n\t";
			cin>>ch3;
			switch(ch3)
			{
				case'1':clrscr();
				fp.open("CAR.txt",ios::out|ios::app);
				ex.add_car();
				fp.write((char*)&ex,sizeof(exhibit));
				fp.close();
				cout<<"\n\t\tCAR IS ADDED TO EXHIBITION";
				getch();
				break;

				case'2':int no;
				clrscr();
				cout<<"\n\n\t================= REMOVE CAR ================= ";
				cout<<"\n\n\tEnter the Model No. of Car\n\t";
				cin>>no;
				fp.open("CAR.txt",ios::in|ios::out);
				fstream fp2;
				fp2.open("TCAR.txt",ios::out);
				fp.seekg(0,ios::beg);
				while(fp.read((char*)&ex,sizeof(exhibit)))
				{
					if(ex.retcno()!=no)
					{
					fp2.write((char*)&ex,sizeof(exhibit));
					}
				}
				fp2.close();
				fp.close();
				remove("CAR.txt");
				rename("TCAR.txt","CAR.txt");
				cout<<"\n\n\t============= CAR WAS REMOVED SUCCESSFULLY ===============";
				getch();
				break;

				case'3':clrscr();
				fp.open("CAR.txt",ios::in);
				while(fp.read((char*)&ex,sizeof(exhibit)))
				{
				ex.show_car();
				cout<<"\n\n====================================\n";
				getch();
				}
				fp.close();
				getch();
				break;

				case'4':man_menu();
				break;

				default:cout<<"\n\n\t\tWRONG CHOICE ";
			}
			break;

		case'3':char ch4;
			clrscr();
			cout<<"\n\n\t=============== TRUCK ===============";
			cout<<"\n\n\t\t1. ADD TRUCK IN EXHIBHITION";
			cout<<"\n\n\t\t2. REMOVE TRUCK FROM EXHIBITION";
			cout<<"\n\n\t\t3. VIEW TRUCK IN EXHIBITION";
			cout<<"\n\nt\t4. BACK";
			cout<<"\n\n\tEnter your choice\n\n\t";
			cin>>ch4;
			switch(ch4)
			{
				case'1':clrscr();
				fp.open("TRUCK.txt",ios::out|ios::app);
				ex.add_truck();
				fp.write((char*)&ex,sizeof(exhibit));
				fp.close();
				cout<<"\n\t\tTRUCK IS ADDED TO EXHIBITION";
				getch();
				break;

				case'2':int no;
				clrscr();
				cout<<"\n\n\t================= REMOVE TRUCK ================= ";
				cout<<"\n\n\tEnter the Model No. of Truck\n\t";
				cin>>no;
				fp.open("TRUCK.txt",ios::in|ios::out);
				fstream fp2;
				fp2.open("TTRUCK.txt",ios::out);
				fp.seekg(0,ios::beg);
				while(fp.read((char*)&ex,sizeof(exhibit)))
				{
					if(ex.rettno()!=no)
					{
					fp2.write((char*)&ex,sizeof(exhibit));
					}
				}
				fp2.close();
				fp.close();
				remove("TRUCK.txt");
				rename("TTRUCK.txt","TRUCK.txt");
				cout<<"\n\n\t============= TRUCK WAS REMOVED SUCCESSFULLY ===============";
				getch();
				break;

				case'3':clrscr();
				fp.open("TRUCK.txt",ios::in);
				while(fp.read((char*)&ex,sizeof(exhibit)))
				{
				ex.show_truck();
				cout<<"\n\n====================================\n";
				getch();
				}
				fp.close();
				getch();
				break;

				case'4':man_menu();
				break;

				default:cout<<"\n\n\t\tWRONG CHOICE ";
			}
			break;

		case'4':mainpro();
			break;

		default:cout<<"\n\\n\t\tWRONG CHOICE ";
	}
}

// AUDIENCE FUNCTION

void aud()
{
	char op1;
	fstream fps;
	char an;
	int no,rat;
	clrscr();
	cout<<"\n\n\t-=-=-=-=--=-=-=- WELCOME -=-=-=-=-=-=-=-=-=-=";
	cout<<"\n\n\t\t1. GO TO BIKE EXHIBITION";
	cout<<"\n\n\t\t2. GO TO CAR EXHIBITION";
	cout<<"\n\n\t\t3. GO TO TRUCK EXHIBITION";
	cout<<"\n\n\t\t4. GO BACK";
	cout<<"\n\n\t\tEnter your Choice\n\n\t\t";
	cin>>op1;
	switch(op1)
	{
		case'1':
		clrscr();
		fp.open("BIKE.txt",ios::in);
		if(!fp)
		{
		cout<<"ERROR!!! NO BIKES IN EXHIBITION\n\n\n ADD BIKES TO EXHIBITION FIRST";
		getch();
		man_menu();
		}
		cout<<"\n\n\t\-=-=-=-=-=-=-== BIKES IN EXHIBITION -=-=-=-=-=-=-=-=-=\n\n";
		cout<<"================================================================\n";
		cout<<"Model No.    Name          Colour       Year        Specialities\n";
		cout<<"================================================================\n";
		while(fp.read((char*)&ex,sizeof(exhibit)))
		{
		cout<<"  "<<ex.retbno()<<" \t     "<<ex.retbike()<<" \t    "<<ex.retbcol()<<" \t\t"<<ex.retbyr()<<" \t      "<<ex.retbsp()<<endl;
		}
		fp.close();
		cout<<"\n\t\tWould you like to Appreciate any Bike(y/n)?\n\t\t";
		cin>>an;
		if(an=='y'||an=='Y')
		{
			cout<<"\n\t\tEnter the Model No. of Bike\n\t\t";
			cin>>no;
			cout<<"\n\t\tEnter the ratings you want to give(1-10)\n\t\t";
			cin>>rat;
			fp.open("BIKE.txt",ios::in);
			fp.read((char*)&ex,sizeof(exhibit));
			while(!fp.eof())
			{
			if(ex.retbno()==no)
			{
			fps.open("REVBIKE.txt",ios::out|ios::app);
			rev.bk_no=ex.retbno();
			strcpy(rev.bk,ex.retbike());
			strcpy(rev.bk_co,ex.retbcol());
			rev.bk_rat=rat;
			fps.write((char*)&rev,sizeof(review));
			fps.close();
			}
			fp.read((char*)&ex,sizeof(exhibit));
			}
			fp.close();
			cout<<"\n\n\tTHANKS FOR SHARING YOUR OPINION";
			getch();
			break;
		}
		break;

		case'2':
		clrscr();
		fp.open("CAR.txt",ios::in);
		if(!fp)
		{
		cout<<"ERROR!!! NO CARS IN EXHIBITION\n\n\n ADD CARS TO EXHIBITION FIRST";
		getch();
		man_menu();
		}
		cout<<"\n\n\t\-==-=-=-=-=-=-=-= CARS IN EXHIBITION -=-=-=-=-=-=-=-=-=-=-=\n\n";
		cout<<"================================================================\n";
		cout<<"Model No.    Name          Colour       Year        Specialities\n";
		cout<<"================================================================\n";
		while(fp.read((char*)&ex,sizeof(exhibit)))
		{
		cout<<"  "<<ex.retcno()<<" \t     "<<ex.retcar()<<" \t    "<<ex.retccol()<<" \t\t"<<ex.retcyr()<<" \t      "<<ex.retcsp()<<endl;
		}
		fp.close();
		cout<<"\n\t\tWould you like to Appreciate any Car(y/n)?\n\t\t";
		cin>>an;
		if(an=='y'||an=='Y')
		{
			cout<<"\n\t\tEnter the Model No. of Car\n\t\t";
			cin>>no;
			cout<<"\n\t\tEnter the ratings you want to give(1-10)\n\t\t";
			cin>>rat;
			fp.open("CAR.txt",ios::in);
			fp.read((char*)&ex,sizeof(exhibit));
			while(!fp.eof())
			{
			if(ex.retcno()==no)
			{
			fps.open("REVCAR.txt",ios::out|ios::app);
			rev.cr_no=ex.retcno();
			strcpy(rev.cr,ex.retcar());
			strcpy(rev.cr_co,ex.retccol());
			rev.cr_rat=rat;
			fps.write((char*)&rev,sizeof(review));
			fps.close();
			}
			fp.read((char*)&ex,sizeof(exhibit));
			}
			fp.close();
			cout<<"\n\n\tTHANKS FOR SHARING YOUR OPINION";
			getch();
			break;
		}
		break;

		case'3':
		clrscr();
		fp.open("TRUCK.txt",ios::in);
		if(!fp)
		{
		cout<<"ERROR!!! NO TRUCK IN EXHIBITION\n\n\n ADD TRUCK TO EXHIBITION FIRST";
		getch();
		man_menu();
		}
		cout<<"\n\n\t\-==-=-=-=-=-=-=-= TRUCK IN EXHIBITION -=-=-=-=-=-=-=-=-=-=-=\n\n";
		cout<<"================================================================\n";
		cout<<"Model No.    Name          Colour       Year        Specialities\n";
		cout<<"================================================================\n";
		while(fp.read((char*)&ex,sizeof(exhibit)))
		{
		cout<<"  "<<ex.rettno()<<" \t     "<<ex.rettruck()<<" \t    "<<ex.rettcol()<<" \t\t"<<ex.rettyr()<<" \t      "<<ex.rettsp()<<endl;;
		}
		fp.close();
		cout<<"\n\t\tWould you like to Appreciate any Truck(y/n)?\n\t\t";
		cin>>an;
		if(an=='y'||an=='Y')
		{
			cout<<"\n\t\tEnter the Model No. of Truck\n\t\t";
			cin>>no;
			cout<<"\n\t\tEnter the ratings you want to give(1-10)\n\t\t";
			cin>>rat;
			fp.open("TRUCK.txt",ios::in);
			fp.read((char*)&ex,sizeof(exhibit));
			while(!fp.eof())
			{
			if(ex.retcno()==no)
			{
			fps.open("REVTRUCK.txt",ios::out|ios::app);
			rev.tk_no=ex.rettno();
			strcpy(rev.tk,ex.rettruck());
			strcpy(rev.tk_co,ex.rettcol());
			rev.tk_rat=rat;
			fps.write((char*)&rev,sizeof(review));
			fps.close();
			}
			fp.read((char*)&ex,sizeof(exhibit));
			}
			fp.close();
			cout<<"\n\n\tTHANKS FOR SHARING YOUR OPINION";
			getch();
			break;
		}
		break;

		case'4':mainpro;
			break;
		default:cout<<"\n\t\tWrong Choice";
	}
}

// THE REVIEW PROGRAM

void respo()
{
	char cho;
	cout<<"\n\n\t*-*-*-*-*-*-*-* REVIEWS OF EXHIBITION *-*-*-*-*-*-*-*-*";
	cout<<"\n\n\t\t1.  BIKE";
	cout<<"\n\n\t\t2.  CAR";
	cout<<"\n\n\t\t3.  TRUCK";
	cout<<"\n\n\t\t4.  BACK TO MENU\n\n\t\t";
	cin>>cho;
	switch(cho)
	{
		case'1':clrscr();
			fp.open("REVBIKE.txt",ios::in);
			if(!fp)
			{
			cout<<"\n\n\t\tNO REVIEWS FOUND";
			}
			while(fp.read((char*)&rev,sizeof(review)))
			{
			rev.view_bike();
			cout<<"\n\n\t\t====================================\n";
			getch();
			}
			fp.close();
			getch();
			break;

		case'2':clrscr();
			fp.open("REVCAR.txt",ios::in);
			if(!fp)
			{
			cout<<"\n\n\t\tNO REVIEWS FOUND";
			}
			while(fp.read((char*)&rev,sizeof(review)))
			{
			rev.view_car();
			cout<<"\n\n\t\t====================================\n";
			getch();
			}
			fp.close();
			getch();
			break;

		case'3':clrscr();
			fp.open("REVTRUCK.txt",ios::in);
			if(!fp)
			{
			cout<<"\n\n\t\tNO REVIEWS FOUND";
			}
			while(fp.read((char*)&rev,sizeof(review)))
			{
			rev.view_truck();
			cout<<"\n\n\t\t====================================\n";
			getch();
			}
			fp.close();
			getch();
			break;

		case'4':mainpro();
			break;

		default:cout<<"\n\n\t\tWRONG CHOICE";
	}
}


// THE MAIN FUNCTION OF PROGRAM

void mainpro()
{
char ch;
do
{
	clrscr();
	cout<<"\n\n\n\t============================================================\n";
	cout<<"\t !-!-!-!-!-!-!-!-!-!-! VEHICLES EXHIBITION !-!-!-!-!-!-!-!-!-! \n";
	cout<<"\t=============================================================\n";
	cout<<"\n\n\t\t 1. MANAGE YOUR EXHIBITION";
	cout<<"\n\n\t\t 2. VIEW EXHIBITION";
	cout<<"\n\n\t\t 3. SEE REVIEWS";
	cout<<"\n\n\t\t 4. EXIT";
	cout<<"\n\n\tEnter your Choice : \n\n\t\t";
	cin>>ch;
	switch(ch)
	{
		case '1': clrscr();
		man_menu();
		getch();
		break;
		case '2': clrscr();
		aud();
		break;
		case '3':clrscr();
		respo();
		mainpro();
		break;
		case '4':exit(0);
		default :cout<<"\a";
	}
	}while(ch!='3');
}

void main()
{
textbackground(CYAN);
mainpro();
}