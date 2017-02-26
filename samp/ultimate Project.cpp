#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>


class movies
{
 private:
	 char name[50];
	 char mov[50];
	 char cast[100];
	 char pvr[150];
	 void display();

 public:
	void enter();
	void view();
	void insert();
	void del();
	void mod();

}m;



	void movies::enter()
		{
		cout<<"Enter the name of the movie."<<endl;
		gets(mov);
		cout<<"Enter the cast of the movie."<<endl;
		gets(cast);
		cout<<"Enter the PVR Cinemas and timings for the movie."<<endl;
		gets(pvr);
		}

	void movies::display()
	{
	cout<<"Name of the movie."<<endl;
	puts(mov);
	cout<<"Cast of the movie."<<endl;
	puts(cast);
	cout<<"NOW SHOWING IN"<<endl;
	puts(pvr);
	}

	void movies::view()
	{
	ifstream ifile;
	ifile.open("mov.dat");
	ifile.seekg(0);
	ifile.read((char*)&m,sizeof(m));

	while(ifile)
		{
			display();
			ifile.read((char*)&m,sizeof(m));
		}

	ifile.close();
	}


	void movies::insert()
	{
	ofstream mfile   ;
	mfile.open("mov.dat", ios::app|ios::binary);
	enter();
	mfile.write((char*)&m,sizeof(m));
	mfile.close();
	}

	void movies::del()
	{
	char b[50];
	char t;
	ifstream mfile;
	mfile.open("mov.dat", ios::app|ios::binary);
	ofstream fi;
	fi.open("new.dat", ios::app|ios::binary);
	cout<<"Enter the name of the movie whose record you want to delete."  ;
	gets(b);
	mfile.seekg(0);
	mfile.read((char*)&t,sizeof(t));
	while(mfile)
	{
	 if (strcmpi(b,mov)==0)
	 fi.write((char*)&t,sizeof(t));
	 mfile.read((char*)&t,sizeof(t));
	}

	mfile.close();
	fi.close();
	remove("mov.dat");
	rename("new.dat","mov.dat");
  }

	void movies::mod()
	{
	char d[50];
	int p;
	cout<<"\n Enter the name of movie whose record you want to modify.";
	gets(d);
	fstream m;
	m.open("mov.dat", ios::in|ios::out);
	m.seekg(0);
	m.read((char*)&m,sizeof(m));

	while(m)
	{
	 if(!strcmpi(d,mov))
	{
	cout<<"\n Press 1 to change the name of the movie.";
	cout<<"\n Press 2 to change the cast details.";
	cout<<"\n Press 3 to change the cinema details of the movie.";
	cin>>p;
	switch(p)
	{
	 case 1: gets(name);
			  break;
	 case 2: gets(cast);
			  break;
	 case 3: gets(pvr);
			  break;
	}
	m.write((char*)&m,sizeof(m));
  }
  m.close();
 }
}






class bookings
{
 private:
 char name[100];
 char movie[50];
 char cine[100];
 int seat;
 int num;
 int amt;
 int price;
 public:
 void enter();
 void display();
}b;

void bookings::enter()
{
 cout<<"\n\n\t\tBooking Menu";
 cout<<"\n Enter your name:";
 gets(name);
 cout<<"Enter the movie.";
 gets(movie);
 cout<<"\nEnter the Cinema:";
 gets(cine);
 cout<<"\nSelect the Class(enter the Sno.):" ;
 cout<<"\n1.Gold\t\t\t2.Premium\t\t\t.3Normal\n";
 cin>>seat;
 if(seat==1)
 price=1000;
 else if (seat==2)
 price=450;
 else if(seat==3)
 price=250;
 else
 cout<<"\nYour input is invalid\n\t Please Type the correct input"     ;

 cout<<"\nSelect the no. of people:"   ;
 cin>>num;
 amt=num*price ;
 display();
}

void bookings::display()
{
 clrscr();
  cout<<"\t\t\t YOUR BOOKING DETAILS ARE";
  cout<<"Name"<<endl;
  puts(name);
  cout<<"Movie"<<endl;
  puts(movie);
  cout<<"Cinema"<<endl;
  puts(cine);
  cout<<"Class"<<endl;
  if(seat==1)
  cout<<"Gold";
  if(seat==2)
  cout<<"Premium";
  if(seat==3)
  cout<<"Normal";
  cout<<"\n No. of people.";
  cout<<num;
  cout<<"Amount of booking."<<endl;
  cout<<amt;
}

void main()
{
 clrscr();
 int choice, adm,use;
 char ch='n';
 cout<<"******************************************"<<endl;
 cout<<"\n\n\n\t\t\t WELCOME TO OVR CINEMAS*******"<<endl;
 cout<<" \t\t\t **********************************"<<endl;
 cout<<"Press any key to continue.";
 getch();
 while(1)
 {
  clrscr();
  cout<<"\n Menu";
  cout<<"\n 1. ADMIN";
  cout<<"\n 2. USER";
  cout<<"\n Enter your choice";
  cin>>choice;
  if(choice==1)
  {
	cout<<"\n 1. Insert new record";
	cout<<"\n 2. Delete a record";
	cout<<"\n 3. Modify a record.";
	cin>>adm;
	switch(adm)
	{
	 case 1: m.insert();
			  break;
	 case 2: m.del();
			  break;
	 case 3: m.mod();
			  break;
	}
  }

  else if(choice==2)
  {
	cout<<"\n 1. Movie details";
	cout<<"\n 2. Booking";
	cin>>use;
	switch(use)
	{
	 case 1: m.view();
			  break;
	 case 2: b.enter();
			  break;
	}
  }
  cout<<"Do you wish to continue?(Y/N)";
  cin>>ch;
  if((ch=='n')||(ch=='N'))
  exit(0);
 }
}







