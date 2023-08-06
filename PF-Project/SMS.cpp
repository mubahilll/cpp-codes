#include<iostream>
#include <string>
using namespace std;

/*
Group Members
1) Mubahil Ahmad (211037)
2) Ahsan Ahmad   (211059)
3) Syed zain     (211113)
4) Shahrukh khan (211061) 
*/

string names[20], rollNumbers[20], course[20], semester[20], contact[20];
int total=0;

void dataEntery() //function for enrolling new students
{
    int students=0;
    
	cout<<"How many students do you want to enroll?"<<endl;
	cin>>students;
	cout<<"----------------------------------------"<<endl;

	if(total==0)
    {
	    total=students+total;
		for(int i=0; i<students; i++) //loop for collection of data
		{
				cout<<"\nEnter the following data of student: "<<i+1<<endl<<endl;

				cout<<"Enter Name of student: "; 
				cin.ignore();
                getline(cin, names[i]);            //using "getline"  to get an input more than one word
				

				cout<<"Enter Roll Number: ";
				cin>>rollNumbers[i];
				while (rollNumbers[i].length() != 6)                        //input validation for improper roll number
				{
					cout<<"Kindly enter a valid Roll Number (6-Digit): ";
					cin>>rollNumbers[i];
				}

				cout<<"Enter Course: ";
				cin.ignore();
                getline(cin, course[i]);        //using "getline"  to get an input more than one word

				cout<<"Enter Semester: ";
				cin>>semester[i];
				
				cout<<"Enter Contact Number: ";
				cin>>contact[i];
				while (contact[i].length() != 11)                            //input validation for improper contact number
				{
					cout<<"Kindly enter a valid Number (11-Digit): ";
					cin>>contact[i];
				}
				cout<<"----------------------------------------"<<endl;
		}
	}

    else

	{
		for(int i=total;i<students+total;i++)
		{
			cout<<"Enter the Data of student "<<i+1<<endl<<endl;

			cout<<"Enter Name: ";
		    cin.ignore();              //using "getline"  to get an input more than one word
            getline(cin, names[i]);

		    cout<<"Enter Roll Number: ";
		    cin>>rollNumbers[i];
		    while (rollNumbers[i].length() != 6)         //input validation for improper roll number
			{
			    cout<<"Kindly enter a valid Roll Number (6-Digit): ";
			    cin>>rollNumbers[i];
		    }

		    cout<<"Enter Course: ";
		    cin.ignore();                 //using "getline"  to get an input more than one word
	        getline(cin, course[i]);

			cout<<"Enter Semester: ";
            cin>>semester[i];

            cout<<"Enter Contact Number: ";              
            cin>>contact[i];
			while (contact[i].length() != 11)            //input validation for improper contact number
			{
				cout<<"Kindly enter a valid Number (11-Digit): ";
				cin>>contact[i];
			}
			cout<<"----------------------------------------"<<endl;
        }

		total=students+total;
	}
}


void showRecord()  //function to output the stored data
{

	if(total==0)
	{
	    cout<<"No data available..."<<endl;
	    cout<<"----------------------------------------"<<endl;
    }

	else
	{
        for(int i=0;i<total;i++)   //loop to ouput the data of multiple students
        {
            cout<<"Data of Student "<<i+1<<": "<<endl<<endl;
 
            cout<<"Name: "<<names[i]<<endl;

	    	cout<<"Roll Number: "<<rollNumbers[i]<<endl;

	    	cout<<"Course: "<<course[i]<<endl;

	    	cout<<"Semester: "<<semester[i]<<endl;

	    	cout<<"Contact Number: "<<contact[i]<<endl;
	    	cout<<"----------------------------------------"<<endl;
        }
        
	}
}

void searchRecord()  //function to search data of any student using roll number

{
    if(total==0)
    {
	    cout<<"No data available..."<<endl;
	    cout<<"----------------------------------------"<<endl;
    }

	else
	{
        string rollNum;

		cout<<"Enter the roll number of student"<<endl;
        cin>>rollNum;
        while (rollNum.length() != 6)                   //input validation for improper roll number
		{
		    cout<<"Kindly enter a valid Roll Number (6-Digit): ";
			cin>>rollNum;
		}

	    for(int i=0;i<total;i++)           //output for the specific roll number
        {
            if(rollNum==rollNumbers[i])
            {
		        cout<<"Name: "<<names[i]<<endl;

	    	    cout<<"Roll Number: "<<rollNumbers[i]<<endl;

	    	    cout<<"Course: "<<course[i]<<endl;

	    	    cout<<"Semester: "<<semester[i]<<endl;

                cout<<"Contact Number: "<<contact[i]<<endl;
                cout<<"----------------------------------------"<<endl;
             }
        }
     }
}

void updateRecord() //function to update any student data

{

	if(total==0)
    {
	    cout<<"No data available..."<<endl;
	    cout<<"----------------------------------------"<<endl;
    }
    
	else
	{
	    string rollNum;
        
		cout<<"Enter the Roll Number of student\nwhich you want to update: ";
        cin>>rollNum;
        while (rollNum.length() != 6)          //input validation for improper roll number
		{
			cout<<"Kindly enter a valid Roll Number (6-Digit): ";
			cin>>rollNum;
		}

	    for(int i=0;i<total;i++)  //loop for displaying previous data and getting input of new data
        {
	       if(rollNum==rollNumbers[i])
		   {
		        cout<<"\nPrevious data"<<endl<<endl;
            
			    cout<<"Data of Student "<<i+1<<endl;
            
			    cout<<"Name: "<<names[i]<<endl;

	    	    cout<<"Roll Number: "<<rollNumbers[i]<<endl;

	    	    cout<<"Course "<<course[i]<<endl;

	    	    cout<<"Semester "<<semester[i]<<endl;

	    	    cout<<"Contact Number: "<<contact[i]<<endl<<endl;
	    	    
	    	    cout<<"----------------------------------------"<<endl;

       	    	cout<<"\nEnter new data"<<endl<<endl;
 
			    cout<<"Enter Name: ";
                cin.ignore();
                getline(cin, names[i]);     //using "getline"  to get an input more than one word

		    	cout<<"Enter Roll Number: ";
			    cin>>rollNumbers[i];
			    while (rollNumbers[i].length() != 6)       //input validation for improper roll number
			    {
					cout<<"Kindly enter a valid Roll Number (6-Digit): ";
					cin>>rollNumbers[i];
			    }

		    	cout<<"Enter Course: ";      
                cin.ignore();                      //using "getline"  to get an input more than one word
                getline(cin, course[i]);

			    cout<<"Enter Semester: ";
                cin>>semester[i];

		    	cout<<"Enter Contact: ";
		     	cin>>contact[i];
			    while (contact[i].length() != 11)         //input validation for improper contact number
	      	    {
			        cout<<"Kindly enter a valid Number (11-Digit): ";
			        cin>>contact[i];
		        }
		        cout<<"----------------------------------------"<<endl;
		        break;
		    }
		    
		    else
		        {
		        	cout<<"No data found...\n";
		        	cout<<"----------------------------------------"<<endl;
		        	break;
				}
	    }
    }
}

void deleteRecord()  //function to delete the total or specific data

{

	if(total==0)
	{
	    cout<<"No data available..."<<endl;
	    cout<<"----------------------------------------"<<endl;
	}

	else
	{
	    int a;

	    cout<<"Press 1 to delete all record"<<endl;
        cout<<"Press 2 to delete specific record"<<endl;
        cin>>a;
        cout<<"----------------------------------------"<<endl;

		if(a==1)
		{
		    total=0;
			cout<<"All record is deleted..!!"<<endl;
			cout<<"----------------------------------------"<<endl;
		}
		
		else if(a==2)
		{
		    string rollNum;
            
			cout<<"Enter the Roll Number of student which you want to delete"<<endl;
			cin>>rollNum;
			while (rollNum.length() != 6)           //input validation for improper roll number
		    {
		        cout<<"Kindly enter a valid Roll Number (6-Digit): ";
			    cin>>rollNum;
		    }
		    cout<<"----------------------------------------"<<endl;
			
            for(int i=0;i<total;i++)
			{
			    if(rollNum==rollNumbers[i])
				{
				    for(int j=i;j<total;j++)    //loop for overwritig the data
					{
					    names[j] = names[j+1];
						
						rollNumbers[j] = rollNumbers[j+1];

					    course[j] = course[j+1];

						semester[j] = semester[j+1];

						contact[j] = contact[j+1];
					}

					total--;

					cout<<"Your required record is deleted..."<<endl;
					cout<<"----------------------------------------"<<endl;
				}
			}
		}

		else 
		{
		    cout<<"Invalid input";
		    cout<<"----------------------------------------"<<endl;
		}
	}
}

int main()

{

	int value;
	
        cout<<"   -----------------------------------"<<endl;
		cout<<"\tSTUDENT MANAGEMENT SYSTEM\t"<<endl;
	    cout<<"   -----------------------------------"<<endl;
	    const string username = "mubahilll";
	const int password = 1234; 
	int pass;
	string user; 
	cout<<"Enter your username: "; 
	cin>>user; 
	cout<<"Enter your password: ";
	cin>>pass; 
	
	if(username==user && pass==password){
		cout<<"login successful...\n";
		while(true) //loop to run the menu infinite times until we exit
	{
		
		cout<<endl;
        cout<<"\t***********************\n";
        cout<<"\t***********************\n";
	    cout<<"\tPress 1 to Enter Data"<<endl<<endl;
        cout<<"\tPress 2 to Show Data"<<endl<<endl;
		cout<<"\tPress 3 to Search Data"<<endl<<endl;
		cout<<"\tPress 4 to Update Data"<<endl<<endl;
		cout<<"\tPress 5 to Delete Data"<<endl<<endl;
		cout<<"\tPress 6 to Exit"<<endl<<endl;
		cout<<"\t***********************\n";
        cout<<"\t***********************\n";
        cout<<"\t";
	    cin>>value;
	    cout<<"----------------------------------------"<<endl;
	
	    switch(value)
	    {
	        case 1:
            dataEntery();
		    break;

		    case 2:
		    showRecord();
		    break;

		    case 3:
		    searchRecord();
		    break;

		    case 4:
		    updateRecord();
		    break;

		    case 5:
		    deleteRecord();
		    break;

            case 6:
		    exit(0);
		    break;

		    default:
		    cout<<"Invalid input"<<endl;
		    break;
	    }
    }
	}
	else
	cout<<"Incorrect username or password\n";
	    
	
}
