#include<iostream>
#include<fstream>
#include<stdio.h>
#include<conio.h>
#include<string.h>

using namespace std;

class menu {
	private :
		int select ;
		int select_edit;
	public: 
		void main_menu(void);
		void edit_menu(void);	
};

class product {
	protected :
		char item_name[100];
		int item_cost;
		int item_code;
		public :
			void add_item(void);
			void display(void);
			void delete_item(void);
			void modify_item(void);
				int retpno();
				int retprice();
				char* retname();
	//		int last_code(void);
};

class account:public product
{ 
product p;
  public:
int order_arr,quan,c;
float amt,damt,total;
int x;
char ch;
//void add_bill();

void display_bill()
{ 
total=0.0;
amt=2;	
cout<<"\n \n********************************INVOICE************************\n";
cout<<"\nPr No.\tPr Name\tQuantity \tPrice \tAmount \n";

ifstream file("BILL.txt",ios::in);


string name ,name1;
int code , cost ,cost1;
int p1,q1;
while(file>>p1>>q1)
{ 
ifstream fs("SALES1.txt",ios::in);
while (fs>>name>>code>>cost)
{
if(p1==code)

{
	cost1=cost;
	name1=name;
	amt=q1*cost ; 
	total=total+amt;
}
}
fs.close();
cout<<"\n"<<p1<<"\t"<<name1<<"\t"<<q1<<"\t\t"<<cost1<<"\t"<<amt<<"\t\t";


}

file.close();

cout<<"\n\n\t\t\t\t\tTOTAL = "<<total;
}

void add_bill()
{
	
ch='Y';
c=0;
amt=0;
total=0;
fstream file ;
    file.open("BILL.txt",ios::trunc | ios::out | ios::in | ios::binary) ;
	cout<<"\n============================";
cout<<"\n PLACE YOUR ORDER";
cout<<"\n============================\n";
do{
cout<<"\n\nEnter The Product No. Of The Product : ";
cin>>order_arr;
file<<order_arr;
file<<" ";
cout<<"\nQuantity in number : ";
cin>>quan;
file<<quan;
file<<" ";
c++;
cout<<"\nDo You Want To Order Another Product ? (y/n)";
cin>>ch;
}while(ch=='y' ||ch=='Y');
cout<<"\n\nThank You For Placing The Order";

   
	file.close() ;
    display_bill();
}

};
void product::add_item(void)
	{
		char ch;
		product pr;
		fstream file;
		file.open("SALES1.txt",ios::app | ios::out | ios::in | ios::binary);
		do
		{
			cout<<"ENTER PRODUCT DETAILS : \n";
			cout<<"Enter name of product:\n";
			cin>>item_name;
			file << item_name << " ";//to write
			cout<<"Enter code of product:\n";
			cin>>item_code;
			file << item_code << " ";
			cout<<"Enter cost of product:\n";
			cin>>item_cost;
			file << item_cost << " ";
			cout<<"Do you want to add more product? (y/n) \n";
			ch=getche();		
		}
		while(ch=='y');
		file.close();//close file
		menu m;
		m.main_menu();
}
int product::retpno()
{return item_code;}

int product::retprice()
{cout<<item_cost;
return item_cost;}

char* product::retname()
{return item_name;}

void product::modify_item()
	{
		char edit_name[100];
		int temp_code , edit_code ;
		float temp_cost , edit_cost ;
		int mi;
		cout<<"What do you want to edit ?\n\n";
		cout<<"1:Edit name of product\n";
		cout<<"2:Edit code of product\n";
		cout<<"3:Edit cost of product\n";
		cin>>mi;
		if(mi==1)
		{
			cout<<"Enter name of product:\n";
			cin>>edit_name;
			strcpy(item_name,edit_name);
			cout<<"Name of product is:"<<item_name<<endl;
		}
		else if(mi==2)
		{
			cout<<"Enter code of product :\n";
			cin>>edit_code;
			temp_code=item_code;
			item_code=edit_code;
			cout<<"Code of product is :"<<item_code<<endl;
			
		}
		else if(mi==3)
		{
			cout<<"Enter cost of product:\n";
			cin>>edit_cost;
			temp_cost=item_cost;
			item_cost=edit_cost;
			cout<<"Cost of product is:"<<item_cost<<endl;
			
		}
		else 
		{
		cout<<"Exit";}
	}
void product::delete_item()
{		string line , name ,name1;
		int code,price;	
		cout<<"Please enter the name of product you want to delete!\n";
		cin>>name;
		ifstream file;
		ofstream temp;
		file.open("SALES1.txt");
		temp.open("TEMP.txt");
		
		
		while(file>>name1>>code>>price)
		{	if(name!=name1){
			temp<<name1<<" "<<code<<" "<<price<<" ";
		}
		}

		cout<<"The record with the name "<<name<<" has been deleted"<<endl;
		file.close();
		temp.close();
		remove("SALES1.txt");
		int result = rename("TEMP.txt","SALES1.txt");
	//	ifstream file;
	//	file open("SALES.DAT");
		
	}

void product::display()
{
//		file.read(reinterpret_cast)
		fstream file; 
   		file.open("SALES1.txt"); 
 		cout << "Reading from the file" << endl; 
 		
 		while(file>>item_name>>item_code>>item_cost)
 		{	
			cout<<item_name<<"\t"<<item_code<<"\t"<<item_cost<<"\n";
		}
		file.close();
}

void menu::main_menu(void)
{
	while(1)
	{
		cout<<"\n\n";
		cout<<"WELCOME TO MAIN MENU \n\n";
		cout<<"1:List Of Product\n";
		cout<<"2:Add Product Details\n";
		cout<<"3:Bill \n";
		cout<<"4:list bill \n";
		cout<<"0:Quit\n";
		cout<<"Enter your selection between 0-3";
		cin>>select;
		if(select==1)
		{
			product p1;
			p1.display();
			
		}
		else if(select==2)
		{
			product p1;
		edit_menu();
		}
		else if(select==3)
		{
			account a1;
		a1.add_bill();
		}
		else if(select==4)
		{
			account a2;
			a2.display_bill();
		}
		else if(select==0)
		return ;
		break ;
	}
}
void menu::edit_menu()
{
	while(1)
	{
		cout<<"WELCOME TO EDIT MENU\n\n";
		cout<<"1:Add record\n";
		cout<<"2:Delete record\n";
		cout<<"3:Modify record\n";
		cout<<"4:Go back to main page\n";
		cout<<"Enter your selection between 1-4!!\n";
		cin>>select_edit;
		if(select_edit==1)
		{
			product p;
			p.add_item();
		}
		else if(select_edit==2)
		{
			product p;
			p.delete_item();
		}
		else if(select_edit==3)
		{
			product p;
			p.modify_item();
		}
		else if (select_edit==4)
		{
			menu m1;
			m1.main_menu();
		}
		else 
		return ;
		break ;
	}	
}

int main(void)
	{
    menu m1;
    //int m ;
    cout<<"******** WELCOME TO SALES MANAGEMENT SYSTEM*********\n";
       menu m12;
		m12.main_menu();
	//	system ("pause");
	char ch;
    		product p;
    		fstream file ;
    		file.seekg(0);
    		file.read(reinterpret_cast<char*>(&p),sizeof(p));
    	while(!file.fail())
    		{
    			cout<<"DISPLAY RECORD \n";
    			p.display();
			}
    	//	system("pause");
    		return 0;
    }
