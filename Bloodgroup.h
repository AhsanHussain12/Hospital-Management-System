
class Blood_group{
	
	string list_group[6];
	string BG;
	public:
		Blood_group(){
			list_group[0]="A+";	  list_group[1]="B+";
			list_group[2]="AB+";  list_group[3]="AB-";
			list_group[4]="O+";	  list_group[5]="O-";

		}
		bool checkBG(){
			int i,entry=0;
			
			while(entry!=3){
			cout<<"Blood Group(*Upper Case Only*): "; cin>>BG;	
			++entry;
			for(i=0;i<6;i++){	if(BG==list_group[i]){return true;}	  }
		    }
		    return false; 
        }
		string getBG(){	return BG;	}   
		
};
