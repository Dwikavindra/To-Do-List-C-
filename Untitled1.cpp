#include <string>
#include <iostream>
#include<fstream>//has the capabiltites of both ofstream and if stream
#include<vector>
#include<windows.h>
using namespace std;
//functions 
//1/ Function for menu 
void add_task(string input_array){
	ofstream myfile;//stands for output
	myfile.open("savefile1trying.txt",ios::app);//appending the file//ofstream is used to wrte to a file while 
	if(input_array!="3"){
		for(int i=0;i<1;i++){
		myfile<<"\n"<<input_array;//insert the data i see just \n to write to a new line 
		myfile.close();
			cout<<"Task "<<input_array<<" is "<<"Added Sucessfully "<<"\n";
		;}
	}
}
void input_task(vector<string>&contents){
	string tp;
	ifstream obj("savefile1trying.txt");
	while(getline(obj,tp)){
	 	if (tp=="" || tp==" "){// if tp is blank then skip " " kalau ada spasi dianggepnya spasi bukan blanks 
	 		continue;
	}
	 	contents.push_back(tp);
			 }
	//opening and apending to array so that we can process it
	 obj.close();
	 }
void view_task(){
	 string tp;
	 int count=0;
	 int count1=1;
	//later would be implemented with struct too still protoyping
	 ifstream obj("savefile1trying.txt");
	 cout<<"Task View"<<"\n";
	 cout<<"\t  \t  \t"<<"\n";
	 while(getline(obj,tp)){//ra
	 	if (tp=="" || tp==" "){// if tp is blank then skip " " kalau ada spasi dianggepnya spasi bukan blanks 
	 		continue;
		 }
	 	cout<<count1<<"."<<""<<tp<<"\t";
	 	count++;
	 	count1++;
	 	if (count%3==0 && count!=0){
	 		cout<<"\n";
			 }
	//opening and apending to array so that we can process it
	 }
	 obj.close();
}
//delete task, overwrite from vector to file,
void delete_task(int n,vector<string>&target){
	target.erase(target.begin()+n);
	ofstream myfile;
	myfile.open("savefile1trying.txt",ios::trunc);
	if (myfile.is_open()){
		for(int i=0;i<target.size();i++){
			myfile<<"\n"<<target[i];
		}
	}
}
//shows menu
void show_menu(){
		cout<<"Menu"<<"\n";
		cout<<"1. Add Task"<<"\n";
		cout<<"2. Delete Task"<<"\n";	
		cout<<"3. Exit"<<"\n";
		view_task();
}
void start(){
	int c=0;
	vector<string>taskslist;	
	while (c==0){
		string inputstring;
		int option_input;
		cout<<"Menu"<<"\n";
		cout<<"1. Add Task"<<"\n";
		cout<<"2. Delete Task"<<"\n";	
		cout<<"3. Exit"<<"\n";
		view_task();
		cout<<"\n"<<"------"<<"\n";
		cout<<"Enter Option: ";
		cin>>option_input;
		cin.ignore();
		input_task(taskslist);//inputs to the vector
		switch (option_input){
			case 1://for adding task 
			while(inputstring!="3"){
				system("cls");
				show_menu();
				cout<<"\n";
				cout<<"------------"<<"\n";
				cout<<"Type 3 to go back to menu"<<"\n";
				cout<<"Enter Your Task Here (Press Enter to Input): ";
				getline(cin,inputstring);
		 		add_task(inputstring);//write to the file
		 		cout<<"\n";
		 		system("cls");
				 }
				break;
			case 2://For Deletion
				while(true){
				int n;
				system("cls");
				show_menu();
				cout<<"\n";
				cout<<"------------"<<"\n";
				cout<<"Which Task are you going to delete?"<<"\n";
				cin>>n;
				if (n==0){//please change this later on
					system("cls");
		 			break;
				 }
		 		delete_task(n-1,taskslist);
		 		cout<<"\n";
		 		system("cls");
				 }
				break;
			case 3://For exit
				c=1;
				break;
}
}
}
int main(){
	start();		
//	int i;
//	int b;
//	cout<<"Choose the file you want to delete";
//	cin>>i;
//	contents.erase(contents.begin()+i);
//	myfile.open("savefile1trying.txt",ios::trunc);
//	if (myfile.is_open()){
//		while(b<8){
//			myfile<<"\n"<<contents[b];
//			b++;
//		}
//	}
//	myfile.close();
//	cout<<"AFTER UPDATE"<<"\n";
//	ifstream duar("savefile1trying.txt");//overwrting the whole thing again
//	string tai;
//		while(getline(duar,tai)){//ra
//		cout<<tai;
//		cout<<"\n";
//	}
	}
	
