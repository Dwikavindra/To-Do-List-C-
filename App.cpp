#include <string>
#include <iostream>
#include<fstream>//has the capabiltites of both ofstream and if stream
#include<vector>
#include<windows.h>
#include<ostream>
#include<time.h>
#include<unistd.h>
#define TEXTTABLE_ENCODE_MULTIBYTE_STRINGS
#define TEXTTABLE_USE_EN_US_UTF8
#include "TextTable.h"
#include <iomanip>
using namespace std;
struct questions{
	string question;
	string answer;
};


void add_questions(string input_array){
	ofstream myfile;//stands for output
	myfile.open("Questions.txt",ios::app);//appending the file//ofstream is used to wrte to a file while 
	if(input_array!="3"){
		for(int i=0;i<1;i++){
		myfile<<"\n"<<input_array;//insert the data i see just \n to write to a new line 
		myfile.close();
			cout<<"Questions"<<input_array<<" is "<<"Added Sucessfully "<<"\n";
		;}
	}
}
void add_answer(string input_array){
	ofstream myfile;//stands for output
	myfile.open("Answers.txt",ios::app);//appending the file//ofstream is used to wrte to a file while 
	if(input_array!="3"){
		for(int i=0;i<1;i++){
		myfile<<"\n"<<input_array;//insert the data i see just \n to write to a new line 
		myfile.close();
			cout<<"Answer"<<input_array<<" is "<<"Added Sucessfully "<<"\n";
		;}
	}
}
void input_questions(vector<questions>&contents){
	contents.clear();
	string tp;
	string answer;
	string a;
	string b;
	vector<string>question;
	vector<string>answers;
	ifstream obj("Questions.txt");
	ifstream obj1("Answers.txt");
	while(getline(obj,tp)){
	 	if (tp=="" || tp==" "){// if tp is blank then skip " " kalau ada spasi dianggepnya spasi bukan blanks 
	 		continue;
	}
	 	question.push_back(tp);
			 }
	while(getline(obj1,answer)){
	 	if (answer=="" || answer==" "){// if tp is blank then skip " " kalau ada spasi dianggepnya spasi bukan blanks 
	 		continue;
	}
	 	answers.push_back(answer);
			 }
	for(int i=0; i<question.size();i++){
		a=question[i];
		b=answers[i];
		questions temp={a,b};
		contents.push_back(temp);
	}
}
//delete one section
void delete_section(int n,vector<questions>&contents){
	contents.erase(contents.begin()+n);
	ofstream myfile;
	ofstream myfile2;
	myfile.open("Questions.txt",ios::trunc);
	if (myfile.is_open()){
		for(int i=0;i<contents.size();i++){
			myfile<<"\n"<<contents[i].question;
		}
}
	myfile2.open("Answers.txt",ios::trunc);
	if(myfile.is_open()){
		for(int i=0;i<contents.size();i++){
			myfile2<<"\n"<<contents[i].answer;
		} 
	}
	
	
}
//edit the question or answer 
void editquestion(int n, vector<questions>&contents,string target){
	contents[n].question=target;
	ofstream myfile;
	myfile.open("Questions.txt",ios::trunc);
	if (myfile.is_open()){
		for(int i=0;i<contents.size();i++){
			myfile<<"\n"<<contents[i].question;
		}
	
	}
}
void editanswer(int n, vector<questions>&contents,string target){
	contents[n].answer=target;
	ofstream myfile;
	myfile.open("Answers.txt",ios::trunc);
	if (myfile.is_open()){
		for(int i=0;i<contents.size();i++){
			myfile<<"\n"<<contents[i].answer;
		}
	
	}
}
//////////////////////////////////////////


void add_task(string input_array){
	ofstream myfile;//stands for output
	myfile.open("savefile.txt",ios::app);//appending the file//ofstream is used to wrte to a file while 
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
	ifstream obj("savefile.txt");
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
	 ifstream obj("savefile.txt");
	 cout<<"Task View"<<"\n";
	 cout<<"\t  \t  \t"<<"\n";
	 while(getline(obj,tp)){//ra
	 	if (tp=="" || tp==" "){// if tp is blank then skip " " kalau ada spasi dianggepnya spasi bukan blanks 
	 		continue;
		 }
		TextTable t( '-', '|', '|' );
	 	cout<<count1<<"."<<""<<tp<<"\n";
	 	count1++;
	//opening and apending to array so that we can process it
	 }
	 obj.close();
}
//delete task, overwrite from vector to file,
void delete_task(int n,vector<string>&target){
	target.erase(target.begin()+n);
	ofstream myfile;
	myfile.open("savefile.txt",ios::trunc);
	if (myfile.is_open()){
		for(int i=0;i<target.size();i++){
			myfile<<"\n"<<target[i];
		}
	}
}
void show_sign(){
	
	cout<<" _     _     _____  _  _      ____        ____  ____  ____ "<<"\n";
	cout<<"/ \\ /\\/ \\   /__ __\\/ \\/ \\__/|/  _ \\      /  _ \\/  __\\/  __\\"<<"\n";
	cout<<"| | ||| |     / \\  | || |\\/||| / \\|      | / \\||  \\/||  \\/|"<<"\n";
	cout<<"| \\_/|| |_/\\  | |  | || |  ||| |-||      | |-|||  __/|  __/"<<"\n";
	cout<<"\\____/\\____/  \\_/  \\_/\\_/  \\|\\_/ \\|_____ \\_/ \\|\\_/   \\_/   "<<"\n";
	
}//shows menu
void show_menu(){
show_sign();
TextTable t( '-', '|', '|' );
cout<<"        Menu   "<<"\n";
		t.add("0. Flash Card Mode");
		t.endOfRow();
		t.add( "1.Add Task" );
		t.endOfRow();
		t.add( "2.Delete Task" );
		t.endOfRow();
		t.add( "3.Exit" );
		t.endOfRow();
		t.setAlignment( 2, TextTable::Alignment::RIGHT );
   		 std::cout << t;
   		 view_task();
}

void start(){
	int c=0;
	vector<string>taskslist;	
	vector<questions> questions_answer;
	while (c==0){
		string inputstring;
		int option_input;
		show_sign();
		TextTable t( '-', '|', '|' );
		cout<<"        Menu   "<<"\n";
		t.add("0. Flash Card Mode");
		t.endOfRow();
		t.add( "1.Add Task" );
		t.endOfRow();
		t.add( "2.Delete Task" );
		t.endOfRow();
		t.add( "3.Exit" );
		t.endOfRow();
		t.setAlignment( 2, TextTable::Alignment::RIGHT );
   		 std::cout << t;
		view_task();
		cout<<"\n"<<"------"<<"\n";
		cout<<"Enter Option: ";
		cin>>option_input;
		cin.ignore();
		input_task(taskslist);//inputs to the vector
		switch (option_input){
			case 0:
				{
				system("cls");
				int h=0;
				while (h==0){
				string inputstring1;
				int option_input1;
				//reads the txt and inputs to to the struct	
				input_questions(questions_answer);
				show_sign();
				cout<<"               Menu   "<<"\n";
				TextTable t( '-', '|', '|' );
				t.add("0. To Do List Mode");
				t.endOfRow();
				t.add( "1.Add Questions and Answer" );
				t.endOfRow();
				t.add( "2.View Questions and Answer" );
				t.endOfRow();
				t.add( "3.Edit or delete Answer or Question" );
				t.endOfRow();
				t.add( "4.Start" );
				t.endOfRow();
				t.setAlignment( 2, TextTable::Alignment::RIGHT );
		   		 std::cout << t;
				cout<<"Enter Option: ";
				cin>>option_input1;
				cin.ignore(1000,'\n');
				switch(option_input1){
					case 0:
						system("cls");
						start();
						break;
					case 1://adding questions and answer;
					while(inputstring1!="3"){
						system("cls");
						cout<<"\n";
						cout<<"------------"<<"\n";
						cout<<"Enter 3 to go back to menu"<<"\n";
						cout<<"Enter Your Question Here (Press Enter to Input): ";
						getline(cin,inputstring1);
						if (inputstring1=="3"){
				 			system("cls");
				 			break; 
							}
				 		add_questions(inputstring1);//write to the filer
				 		cout<<"Enter Your Answer Here(Press Enter to Input): ";
				 		cin.clear();
				 		getline(cin,inputstring1);
				 		add_answer(inputstring1);
				 		cout<<"\n";
				 		system("cls");
						 }
						 break;
					case 2:
					while(inputstring1!="3"){
						system("cls");
						cout<<"\n";
						cout<<"------------"<<"\n";
				cout<<"No"<<"         "<<"Question"<<"                                               "<<"___________Answer___________"<<"\n";
					for (int i=0;i<questions_answer.size();i++){//view questions and answer 
					 cout<<i+1<<"         "<<questions_answer[i].question<<"                                           "<<std::right<<questions_answer[i].answer<<"\n";
				}
				cout<<"Type 3 to go back: ";
				getline(cin,inputstring1);
				system("cls");
			}
				break;
				case 3://editing and deleting 
				while(inputstring1!="3"){
				int y;
				string x;
				string d;
				string edit;
				system("cls");
				cout<<"\n";
				cout<<questions_answer.size()<<"\n";
				cout<<"------------"<<"\n";
				cout<<"No"<<"         "<<"Question"<<"                                               "<<"___________Answer___________"<<"\n";
					for (int i=0;i<questions_answer.size();i++){//view questions and answer 
					 cout<<i+1<<"         "<<questions_answer[i].question<<"                                           "<<std::right<<questions_answer[i].answer<<"\n";
				}
				cout<<"Type 3 to go back or Type 1 to continue :";
				cin>>inputstring1;
				if(inputstring1=="3"){
					system("cls");
					break;
				}
				cout<<"Choose the coloumn: ";
				cin>>y;
				if(y<0 ||(y>questions_answer.size()&&questions_answer.size()>1)){
					cout<<"Please enter the correct section that is available"; 
					continue;
				}
				cout<<"Type X to delete or Type Y to edit";
				cin>>x;
				if (x=="X"||x=="x"){
					delete_section(y-1,questions_answer);
				}
				else{
					cout<<"Type 1 to edit the questions or Type 2 to edit the answer";
					cin>>d;
					if(d=="1"){
						cout<<"Write your change here (Warning this would replace everything within the question section!): ";
						cin.ignore(1000, '\n');
						getline(cin,edit);
						editquestion(y-1,questions_answer,edit);
					}
					else{
						cout<<"Write your change here (Warning this would replace everything within the answer section !): ";
						cin.ignore(1000, '\n');
						getline(cin,edit);
						editanswer(y-1,questions_answer,edit);
					}
				}
				}
				break;
				case 4:
						while(inputstring1!="3"){
								string answer;
								system("cls");
								srand (time(0));
		  						int i = rand() % questions_answer.size();
		  						cout<<"Type 3 to go back Type 1 to continue: ";
		  						getline(cin,inputstring1);
		  						if(inputstring1=="3"){
		  							system("cls");
		  							break;
								  }
		  						cout<<"Question:"<<"\n";
		  						cout<<questions_answer[i].question<<"\n";
		  						cout<<"Answer:"<<"\n";
		  						getline(cin,answer);
		  						cin.clear();
		  						if(answer==questions_answer[i].answer){
		  							cout<<"Your answer is correct"<<"\n";
		  							cout<<"Press Enter to continue";
									cin.ignore(1000,'\n');
									cin.clear();
		  						
								  }
								else{
									cout<<"Your answer is wrong the correct answer is: "<<questions_answer[i].answer<<"\n";
									cout<<"Press Enter to continue";
									cin.ignore(1000,'\n');
									cin.clear();}
		  						
		  						
						}
					
					break;
				
			}
		}
	}
		break;
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
				cout<<"Type 3 to go back Type 1 to continue: ";
				getline(cin,inputstring);
				if(inputstring=="3"){
					system("cls");
					break;
				}
				cout<<"Which Task are you going to delete?"<<"\n";
				cin>>n;
				cin.ignore(1000,'\n');
				if(taskslist.size()==0){
					cout<<" Please enter a task before hand there is no task here:  "<<"\n";
					cout<<"Returning to menu"<<"\n";
					sleep(1);
					cout<<"3"<<"\n";
					sleep(1);
					cout<<"2"<<"\n";
					sleep(1);
					cout<<"1"<<"\n";
					system("cls");
					break;
				}
				if(n<0 || (n>taskslist.size()&&taskslist.size()>1)){
					cout<<"Please enter the correct section that is available";
					sleep(3);
					system("cls");
					continue;
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
}


