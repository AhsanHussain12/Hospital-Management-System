
class Philanthropist:public Person{
	protected:
	
	float don_amnt;

	public:
		static double TA_donation;
		void writefile(){
			ofstream fout;
			console A1;
			fout.open("Donaters.txt",ios::app);
			for(int i=0;i<50;i++){fout<<"-";}
			fout<<"\n||"<<A1.d<<"/"<<A1.m<<"/"<<A1.y<<"||"<<endl;
			fout<<"Name: "<<name<<endl;	
		    fout<<"Age: "<<age<<endl;
		    fout<<"Gender: "<<gender<<endl;
		    fout<<"Address: "<<address<<endl;
		    fout<<"Contact_info: "<<con_info<<endl;
		    fout<<"Donated Amount: $"<<don_amnt<<endl;
		    for(int i=0;i<50;i++){fout<<"-";}
			fout.close();
		}	
	
		void philanthropist_arrive(){
			getData();
			writefile();
		}
		int getData(){
			fflush(stdin);	
			Person::getData();
			cout<<"Enter Donation Amount: $";
			cin>>don_amnt;
			TA_donation+=don_amnt;
		}

		float getDonationAmount(){	return don_amnt;	} 
};
double Philanthropist::TA_donation=0;
