#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
using namespace std;

//student management system with file management.

class employee // created a Employee class
{
	private:
		//defining variables for collacting emloyee.
	string name, employee_id, salary, email, contact_no, address; 
	public:
		//defined the function names
		void menu();
		void insert();
		void display();
		void modify();
};
void employee::menu()//menu faction to list the main manu.
{
	menustart:
	int choice;
	char x;
	system("cls");
	//Items of Main menu.
	cout<<"\t\t\t---------------------------------------"<<endl;
	cout<<"\t\t\t|     Employee Management System!     |"<<endl;
	cout<<"\t\t\t---------------------------------------"<<endl;
	cout<<"\t\t\t 1. Enter new record."<<endl;
	cout<<"\t\t\t 2. Display record."<<endl;
	cout<<"\t\t\t 3. Modify record."<<endl;
	cout<<"\t\t\t 4. Serach record."<<endl;
	cout<<"\t\t\t 5. Delete record."<<endl;
	cout<<"\t\t\t 6. Exit."<<endl;
	
	cout<<"\t\t\t---------------------------------------"<<endl;
	cout<<"\t\t\t| Choose Option:[1/2/3/4/5/6]         |"<<endl;
	cout<<"\t\t\t---------------------------------------"<<endl;
	//asking user to enter his choise from above menu.
	cout<<"Enter your Choise : ";
	cin>>choice;
	//switch function to run the process.
	switch(choice)
	{
		case 1:
			//created a dowhile loop for insert function.
			do
			{
				insert();
				//asking user to add more employees details.
				cout<<"n\t\t\t Add Another Employee Record (Y/N): ";
				cin>>x;
			}while(x=='y'||x=='Y');
			break;
		case 2: 
			display();
			break;
		case 3:
			modify();
			break;
		case 6:
			//exit function.
			exit(0);
			
		default:
			//invalid choise msg function.
			cout<<"n\t\t\t\ Invaild Choice...! Please try again...!";
	}
	getch();
	goto menustart;
}
void employee::insert()
{
	system("cls");
	fstream file;
	cout<<"\t\t\t\t**************************\t\t\t";
	cout<<"\n\t\t\t\t*  Add Employee Details  *\t\t\t";
	cout<<"\n\t\t\t\t**************************\t\t\t"<<endl;
	//function for taking employee information from user.
	cout<<"\t\t\t Enter Name : ";
	cin>>name;
	cout<<"\t\t\t Enter Employee Id : ";
	cin>>employee_id;
	cout<<"\t\t\t Enter salary : ";
	cin>>salary;
	cout<<"\t\t\t Enter email : ";
	cin>>email;
	cout<<"\t\t\t Enter contact No. : ";
	cin>>contact_no;
	cout<<"\t\t\t Enter address : ";
	cin>>address;
	//storing employee details in text file.
	file.open("EmployeeRecords.txt", ios::app | ios::out);
	file<<" "<< name << " " << employee_id << " " << salary << " " << email << " " << contact_no << " " << address << "\n";
	file.close();
}
void employee::display()//display the stored employeed deatails function
{
	system("cls");
	fstream file;
	int total=0;
	cout<<"\t\t\t\t**************************\t\t\t";
	cout<<"\n\t\t\t\t*  Display Details  *\t\t\t";
	cout<<"\n\t\t\t\t**************************\t\t\t"<<endl;
	file.open("EmployeeRecords.txt", ios::in);
	if(!file)
	{
		//function to show message when no data available in text file
		cout<<"\n\t\t\t No Data is present...!";
		file.close();
	}
	else
	{
		file >> name >> employee_id >> salary >> email >> contact_no >> address;
		while(!file.eof())
		{
			cout<<"\n\n\t\t\t Employee No.: "<< total++ <<endl;
			cout<<"\t\t\t Employee Name : "<< name <<endl;
			cout<<"\t\t\t Employee employee ID : "<< employee_id <<endl;
			cout<<"\t\t\t Employee salary : "<< salary <<endl;
			cout<<"\t\t\t Employee email :"<< email <<endl;
			cout<<"\t\t\t Employee contact no : "<< contact_no <<endl;
			cout<<"\t\t\t Employee address :"<< address <<endl;
			file>> name >> employee_id >> salary >> email >> contact_no >> address;
		}
		if(total==0)
		{
			cout<<"\n\t\t\t No Data is present...!";
		}
	}
	file.close();
}
void employee::modify()
{
	system("cls");
	fstream file, file1;
	string rollno;
	int found;
	cout<<"\t\t\t\t**************************\t\t\t";
	cout<<"\n\t\t\t\t*  Modify Details  *\t\t\t";
	cout<<"\n\t\t\t\t**************************\t\t\t"<<endl;
	file.open("EmployeeRecords.txt", ios::in);
	if(!file)
	{
		cout<<"\n\t\t\t No details are present";
		file.close();
	}
	else 
	{
		cout<<"\n Enter employee ID of employee to modify the details : ";
		cin>>rollno;
		file1.open("Records.txt", ios::app|ios::out);
		file>> name >> employee_id >> salary >> email >> contact_no >> address;
		while(!file.eof())
		{
			if(rollno != employee_id)
			{
				file<<" "<< name << " " << employee_id << " " << salary << " " << email << " " << contact_no << " " << address << "\n";
			}
			else
			{
				cout<<"\t\t\t Enter Name : ";
				cin>>name;
				cout<<"\t\t\t Enter Employee Id : ";
				cin>>employee_id;
				cout<<"\t\t\t Enter salary : ";
				cin>>salary;
				cout<<"\t\t\t Enter email : ";
				cin>>email;
				cout<<"\t\t\t Enter contact No. : ";
				cin>>contact_no;
				cout<<"\t\t\t Enter address : ";
				cin>>address;
				file<<" "<< name << " " << employee_id << " " << salary << " " << email << " " << contact_no << " " << address << "\n";
				found++;
			}
			file>> name >> employee_id >> salary >> email >> contact_no >> address;
			if(found == 0)
			{
				cout<<"Employee id not found...!!!";
			}
		}
		file1.close();
		file.close();
		remove("EmployeeRecords.txt");
		rename("Records.txt","EmployeeRecords.txt");
	}
}
main()//main function to run the whole system.
{
	employee project;
	project.menu();
	return 0;
}	
