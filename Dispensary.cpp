#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Dispensary{
		string name;
		int amount;
	public:
		Dispensary(){
		}
		void addstock(){
			ofstream fout;
			cout<<"Medicine Name: "; getline(cin,name);
			cout<<"Medicine Amount: "; cin>>amount;
			fout.open("Dispensary.txt",ios::app);
			fout.write((char *)this,sizeof(*this));
			fout<<endl;
			fout.close();
		}
		void readstock(){
			string tp;
			ifstream fin;
			fin.open("Dispensary.txt",ios::in);
			while(!fin.eof()){
		    getline(fin,tp); //read data from file object and put it into string.
        	cout << tp << "\n"; //print the data of the string
      		}
		
		}

};

int main(){
	Dispensary D,D1;
//	D.addstock();
	D.readstock();

}
