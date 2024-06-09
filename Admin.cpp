#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Admin{
	int pass;
	string username;
	public:
		Admin(){
			username="admin04";
			pass=1122;
		}
		int admin_options(){
			int select;
			string U_temp;
			int pass_temp;
			cout<<"\n Enter Username: "; cin>>U_temp;
			cout<<" Enter Passcode: "; cin>>pass_temp;
			if(U_temp==username && pass_temp==pass){
				system("cls");
				cout<<"[1] To Check Patient Record "<<endl;
				cout<<"[2] To Check Donation Record "<<endl;
				cout<<"[3] To Check Staff Memebers"<<endl;
				cout<<"[4] To ADD Staff "<<endl<<endl;
				cin>>select;
				return select;
			}
			else{
			cout<<"\nRe-Enter Username: "; cin>>U_temp;
			cout<<" Re-Enter Passcode: "; cin>>pass_temp;
			}
		}
		void readpatient(){
			cin.ignore();
            char filename[100];
            ifstream infile;
            do{
            cout<<"Enter Patients filename: ";
            cin>>filename;
            infile.open(filename);
			}
			while(infile.fail());
			string line;
			while(!infile.eof())
			{//fetch line from data.txt and put it in a string
			getline(infile, line);
			cout << line<<endl;
			}
			infile.close();
		}
		void readdonaters(){
			string tp;
			ifstream fin;
			fin.open("Donaters.txt");
			while(!fin.eof()){
		    getline(fin,tp); //read data from file object and put it into string.
        	cout << tp << "\n"; //print the data of the string
      		}
		}
		void addstaff(){
			string name,des;
			float pay;
			ofstream fout;
			cout<<"Enter Staff Name: "; cin>>name;
			cout<<"Enter Staff Designation: ";cin>>des;
			cout<<"Enter Staff monthly pay: ";cin>>pay;
			fout.open("Staff.txt",ios::app);
			fout<<name<<"        "<<des<<"        "<<pay<<endl;
			fout.close();
		}
		void readstaff(){
			string tp;
			ifstream fin;
			fin.open("Staff.txt",ios::in);
			while(!fin.eof()){
		    getline(fin,tp); //read data from file object and put it into string.
        	cout << tp << "\n"; //print the data of the string
      		}
		}
};
int main(){
	Admin A;
	A.admin_options();
	A.addstaff();
}
