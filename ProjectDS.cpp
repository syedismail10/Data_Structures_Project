#include <fstream>
#include <cstring>
#include <limits>
#define alphabets 26
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<windows.h>
#include<process.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>
using namespace std;
class LinkNode;
class LinkedData;
class Word{
	char word[10];
	char meaning[50];
	char type[30];
	char Sen1[100];
	char Sen2[100];
	friend class LinkNode;
	friend class LinkedData;
	friend class Dictionary;
	public:
		void setword(string x){
				strcpy(word,x.c_str());
			}
		void setmeaning(string x){
				strcpy(meaning,x.c_str());
			}	
		void settype(string x){
				strcpy(type,x.c_str());
			}		
		void setSen1(string x){
				strcpy(Sen1,x.c_str());
			}	
		void setSen2(string x){
				strcpy(Sen2,x.c_str());
			}		
			char* getWord(){
				char* str;
				str = new char[10];
				str = word;
				return str;
			}
			char* getMeaning(){
				char* str;
				str = new char[30];
				str = meaning;
				return str;
			}
			char* getType(){
				char* str;
				str = new char[10];
				str = type;
				return str;
			}
			char* getSen1(){
				char* str;
				str = new char[50];
				str = Sen1;
				return str;
			}
			char* getSen2(){
				char* str;
				str = new char[50];
				str = Sen2;
				return str;
			}
			void display(){
				cout<<word<<endl;
				cout<<meaning<<endl;
				cout<<type<<endl;
				cout<<Sen1<<endl;
				cout<<Sen2<<endl;
			}
};
class DataNode{
	DataNode *children[alphabets];
	Word w;
	bool isEnd;
	friend class Dictionary;
		public:
			Word getword(){
				return w;
			}
			DataNode(){
				for (int i =0 ; i<alphabets;i++){
					children[i]=NULL;
				}
				isEnd = false;
			}
//			void ReadingFromFile(){
//				ifstream obj;
//				Word temp;
//			//	obj.open("testtrie.txt",ios::in);
//				obj.open("testingintrie.txt",ios::in);
//				while(obj.read((char*)&temp,sizeof(temp))){
//					//reference to add the data into structure
//					AddWord(w);
//					//reference ends
//					w.display();
//					cout<<endl;
//					}
//				obj.close();
//			}
//			void ModifyRecord(char modifydata[]){
//				ifstream obj;
//				ofstream output;
//				obj.open("testtrie.txt",ios::in);
//				output.open("testclass2.txt",ios::out);
//				while(obj.read((char*)this,sizeof(*this))){
//					if (strcmp(word,modifydata)==0){
//						cout<<"Enter all information"<<endl;
//						cin.getline(word,sizeof(word));
//						cin.getline(meaning,sizeof(meaning));
//						cin.getline(type,sizeof(type));
//						cin.getline(Sen1,sizeof(Sen1));
//						cin.getline(Sen2,sizeof(Sen2));
//						//cin>>a>>b>>c;
//						output.write((char*)this,sizeof(*this));
//					}
//					else
//						output.write((char*)this,sizeof(*this));
//					}
//				obj.close();
//				output.close();
//				remove("testtrie.txt");
//				rename("testclass2.txt","testtrie.txt");
//			}
//			void DeleteRecord(char deletekey[]){
//				ifstream obj;
//				ofstream output;
//				obj.open("testtrie.txt",ios::in);
//				output.open("testclass2.txt",ios::out);
//				while(obj.read((char*)this,sizeof(*this))){
//					if (strcmp(word,deletekey)!=0)
//					//cin>>a>>b>>c;
//						output.write((char*)this,sizeof(*this));
//				}
//				obj.close();
//				output.close();
//				remove("testtrie.txt");
//				rename("testclass2.txt","testtrie.txt");
//			}	
};
class LinkNode{
	public:
		int key;
		LinkNode *next;
		Word w;
		LinkNode(){
			next = NULL;
		}
		LinkNode(Word a,int k){
			strcpy(w.word,a.word);
			strcpy(w.meaning,a.meaning);
			strcpy(w.type,a.type);
			strcpy(w.Sen1,a.Sen1);
			strcpy(w.Sen2,a.Sen2);
			key = k;
			next = NULL;
		}
};
class LinkedData{
	public:
		LinkNode *head;
		static int k;
		LinkedData(){
			head = NULL;
		}
		void DeleteList(){
			LinkNode *x;
			x = head;
			head = NULL;
			free(x);
		}
//		LinkedData(LinkNode *n(k)){
//			k++;
//			head = n;
//		}
//		void AutoComplete(string word){
//			LinkNode*temp;
//			
//		}
		void InsertNode(DataNode *temp){
			k++;
			if (head == NULL){
        		LinkNode *nn = new LinkNode(temp->getword(),k);
				head = nn;
//        		cout << "Node Appended" << endl;
      		} else {
        		LinkNode * ptr = head;
        		while (ptr -> next != NULL) {
					ptr = ptr -> next;
        		}
       		 ptr -> next = new LinkNode(temp->getword(),k);
//        	cout << "Node Appended" << endl;
      }
		}
		void Searchkey(int val){
			LinkNode *curr = head;
			while(curr != NULL){
				if (curr->key == val){
					cout << curr -> w.word << ", meaning " << curr -> w.meaning << "--> ";
        		cout << "Type of Speech " <<curr -> w.type << ", Sentence 1 " << curr -> w.Sen1 << "--> ";
 		        cout << "Sentence 2"<<curr -> w.Sen2 << endl;
 		        return;
				}
				else{
					curr = curr->next;
				}
		}
}
		
		void printList(){
    		if (head == NULL) {
      		cout << "No matches found";
    		} else {
      			LinkNode * temp = head;
    		while (temp != NULL) {
				
				cout << temp->key << " "<<temp -> w.word << endl;
				temp = temp -> next;
      }
    }
  }
};
int LinkedData::k=0;
class Dictionary{
	friend class LinkedData;
	public:
		DataNode *root;
		Dictionary(){
			root = new DataNode();	
		}
		void ReadingFromFile(){
				ifstream obj;
				Word temp;
			//	obj.open("testtrie.txt",ios::in);
				obj.open("testingintrie.txt",ios::in);
				while(obj.read((char*)&temp,sizeof(temp))){
					//reference to add the data into structure
					AddWord(temp);
					//reference ends
//					temp.display();
//					cout<<endl;
					}
				obj.close();
			}
		bool SearchEntry(string word){
			int index;
			DataNode *temp = root;
			for (int i = 0 ; i <word.length();i++){
				index = word[i]-'a';
				if (temp->children[index]!=NULL)
					temp = temp->children[index];
			}
			return (temp->isEnd);
		}
		void SearchWord(string word){
			int index;
			DataNode *temp = root;
			for (int i = 0 ; i <word.length();i++){
				index = word[i]-'a';
				if (temp->children[index]!=NULL)
					temp = temp->children[index];
			}
			if (temp->isEnd){
				cout<<"Word is "<<word<<endl;
				cout<<temp->w.meaning<<endl;
				cout<<temp->w.type<<endl;
				cout<<temp->w.Sen1<<endl;
				cout<<temp->w.Sen2<<endl;
			}		
		}
		
		DataNode* xyz(string word) {
			int index;
			DataNode *temp = root;
			for (int i = 0 ; i <word.length();i++){
				index = word[i]-'a';
				if (temp->children[index]!=NULL)
					temp = temp->children[index];
			}
			return temp;
		}
		void WritingtoFile(Word temp){
			ofstream obj;
			obj.open("testingintrie.txt",ios::app);
			obj.write((char*)&temp,sizeof(temp));		
			obj.close();
			}
		void ModifyRecord(char modifydata[]){
			ifstream obj;
			ofstream output;
			Word temp;
			DataNode* change=xyz(modifydata);
			obj.open("testingintrie.txt",ios::in);
			output.open("testclass2.txt",ios::out);
			while(obj.read((char*)&temp,sizeof(temp))){
				if (strcmp(temp.word,modifydata)==0){						
					cout<<"Enter all information"<<endl;
					cin.getline(temp.meaning,sizeof(temp.meaning));
					cin.getline(temp.type,sizeof(temp.type));
					cin.getline(temp.Sen1,sizeof(temp.Sen1));
					cin.getline(temp.Sen2,sizeof(temp.Sen2));// modifying the record like above
						//cin>>a>>b>>c;
					output.write((char*)&temp,sizeof(temp));
					strcpy(change->w.meaning,temp.meaning);
					strcpy(change->w.type,temp.type);						
					strcpy(change->w.Sen1,temp.Sen1);
					strcpy(change->w.Sen2,temp.Sen2);
					}
					else
						output.write((char*)&temp,sizeof(temp));
					}
			obj.close();
			output.close();
			remove("testingintrie.txt");
			rename("testclass2.txt","testingintrie.txt");
			}
			void DeleteRecord(char deletekey[]){
				ifstream obj;
				ofstream output;
				Word temp;
				obj.open("testingintrie.txt",ios::in);
				output.open("testclass2.txt",ios::out);
				while(obj.read((char*)&temp,sizeof(temp))){
					if (strcmp(temp.word,deletekey)!=0)
						output.write((char*)&temp,sizeof(temp));
				}
				obj.close();
				output.close();
				remove("testingintrie.txt");
				rename("testclass2.txt","testingintrie.txt");
			}
		void AddWord(Word a){
			int index;
			DataNode *temp = root;
			for (int i = 0 ; i<strlen(a.word) ;i++){
				index = a.word[i]-'a';
				if (temp->children[index]==NULL)
					temp->children[index] = new DataNode();
				temp= temp->children[index];
			}
			temp->isEnd=true;
			strcpy(temp->w.word,a.word);
			strcpy(temp->w.meaning,a.meaning);
			strcpy(temp->w.type,a.type);
			strcpy(temp->w.Sen1,a.Sen1);
			strcpy(temp->w.Sen2,a.Sen2);}
		void AddWord(string a,string b,string c,string d,string e){
			//Start of insertion in trie
			int i, index;
			Word store;
			if(SearchEntry(a)){
				cout<<"Word already exists!"<<endl;
				return;	
			}
			DataNode *temp = root;
			for (i=0 ; i<a.length();i++){
				index = a[i]-'a';
				if (temp->children[index]==NULL)
					temp->children[index] = new DataNode();
				temp= temp->children[index];
			}
			temp->isEnd=true;
			strcpy(temp->w.word,a.c_str());
			strcpy(temp->w.meaning,b.c_str());
			strcpy(temp->w.type,c.c_str());
			strcpy(temp->w.Sen1,d.c_str());
			strcpy(temp->w.Sen2,e.c_str());
			store.setword(temp->w.word);
			store.setmeaning(temp->w.meaning);
			store.settype(temp->w.type);
			store.setSen1(temp->w.Sen1);
			store.setSen2(temp->w.Sen2);
			//end of insertion
			WritingtoFile(store);
		}
		DataNode* removeUtil(DataNode*temp,string word,int depth=0){
			if(depth==word.length()){
				if(isLastNode(temp)){
					delete(temp);
					temp=NULL;
			}
				return temp;
			}
			int index=word[depth]-'a';
			temp->children[index]=removeUtil(temp->children[index],word, depth+1);
			if(isLastNode(temp) && temp->isEnd == false){
				delete temp;
				temp=NULL;
				}
			return temp;
		}
   		void removeword(string word){
			char temp[100];
	    	strcpy(temp,word.c_str());
			DeleteRecord(temp);
			removeUtil(root,word);
	    	cout<<"The word "<<word<<" has been deleted!"<<endl;
   		}
		bool isLastNode(DataNode *root){
			for(int i = 0 ; i < alphabets;i++){
				if (root->children[i])
					return 0;
			}
			return 1;
		}
		void suggestrec(DataNode *root,string curr,LinkedData &temp){
			if (root->isEnd)
				temp.InsertNode(root);
			
			for (int i = 0; i < alphabets; i++)
			if (root->children[i]) {
				// child node character value
				char child = 'a' + i;
				suggestrec(root->children[i],
							curr + child,temp);
			}		
		}
		int printAutoSuggestions(DataNode* root, const string query,LinkedData &temp){
			DataNode* pCrawl = root;
			for (char c : query) {
			int ind = CHAR_TO_INDEX(c);

			// no string in the Trie has this prefix
			if (!pCrawl->children[ind])
				return 0;

			pCrawl = pCrawl->children[ind];
			}
			// If prefix is present as a word, but
			// there is no subtree below the last
		// matching node.
			if (isLastNode(pCrawl)) {
				// Create node
			//cout << query << endl;
				return -1;
			}
			suggestrec(pCrawl, query,temp);
			return 1;
		}
};
int main()
{
    string a,b,c,d,e,s;
    int val;
	char search[30];
	Dictionary dictionary;
	dictionary.ReadingFromFile();
    LinkedData l;
	system("COLOR 2E");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t  --------------DSA PROJECT 2022----------";
    cout<<"\n\t\t\t\t  ----------------------------------------";
    cout<<"\n\t\t\t\t  COURSE INSTRUCTOR:- Sir Shoaib Rauf";
    cout<<"\n\t\t\t\t  ----------------------------------------";
    cout<<"\n\n\t\t\t\t   TITLE:- Search-Engine Based Dictionary";
    cout<<"\n\t\t\t\t  ----------------------------------------";
    Sleep(1000);
    system("cls");
    for(int i=1;i<=50;++i)
    {
                       Sleep(50);
                       system("cls");
                       cout<<"\n\n\t\t\t\t\t\t\t\t\t\t DIGITAL DICTIONARY ";
                       cout<<"\n\n\n\n\n\n\n\n\n";
                       cout<<"\n\n\t\t\t\t\t\t\t\tPROJECT CONTRIBUTORS:-\n\n";
                       cout<<"\n\t\t\t\t\t\t\t\t1.FIZZA RASHID 21K-3390";
					   cout<<"\n\t\t\t\t\t\t\t\t2.M.TALHA 21K-3288";
					   cout<<"\n\t\t\t\t\t\t\t\t3.SYED M.ISMAIL UL HAQ 21K-4571";
					   cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tLOADING DICTIONARY....";
                       if(i==50)
                       Sleep(50);
    }
    system("cls");

    
    cout<<"\t\t\t\t\t\t\t            o    o            \n";
    cout<<"\t\t\t\t\t\t\t             o  o             \n";
    cout<<"\t\t\t\t\t\t\t              oo              \n";
    cout<<"\t\t\t\t\t\t\to----------------------------o\n";
    cout<<"\t\t\t\t\t\t\to----------------------------o\n";
    cout<<"\n\t\t\t\t\t\t\t|     DIGITAL DICTIONARY     |\n";
    cout<<"\t\t\t\t\t\t\to----------------------------o\n";
    cout<<"\t\t\t\t\t\t\to----------------------------o\n";
    cout<<"\n\n\t\t\t\t\t\t ----- RULES TO USE DIGITAL DICTIONARY ----- "<<"\n\n";
    cout<<"\n\t\t\t\t\t\t (1) You can add word to Dictionary. ";
    cout<<"\n\t\t\t\t\t\t (2) You can search word from Dictionary. ";
    cout<<"\n\t\t\t\t\t\t (3) You can delete word from Dictionary. "<<endl<<endl<<endl;
    
	
	
    system("PAUSE");
    mainmenu:
    system("cls");
    
    cout<<"\t\t\t\t\t\t\t            o    o            \n";
    cout<<"\t\t\t\t\t\t\t             o  o             \n";
    cout<<"\t\t\t\t\t\t\t              oo              \n";
    cout<<"\t\t\t\t\t\t\to----------------------------o\n";
    cout<<"\t\t\t\t\t\t\to----------------------------o\n";
    cout<<"\n\t\t\t\t\t\t\t|     DIGITAL DICTIONARY     |\n";
    cout<<"\t\t\t\t\t\t\to----------------------------o\n";
    cout<<"\t\t\t\t\t\t\to----------------------------o\n";
    
    cout<<"\n\n\n\t\t\t\t\t\t PRESS THE KEY ACCORDING TO GIVEN INSTRUCTIONS "<<endl<<endl;
    cout<<"\n\t\t\t\t\t\t\t [PRESS '1']--> ADD WORD";
    cout<<"\n\t\t\t\t\t\t\t [PRESS '2']--> SEARCH WORD";
    cout<<"\n\t\t\t\t\t\t\t [PRESS '3']--> DELETE WORD";
    cout<<"\n\t\t\t\t\t\t\t [PRESS '4']--> EXIT\n\n\n\n";
    
    int userchoice;
    cout<<"Enter your choice here:- ";
    cin>>userchoice;
    
	switch(userchoice){
		case 1:
			system("cls");
			cout<<"\n\n\t\t\t\t\tADD WORD"<<endl;
			cout<<"Enter word"<<endl;
			cin>>a;
			if(dictionary.SearchEntry(a)){
				cout<<"Word already exists!"<<endl;
			}else{
				cout<<"Enter meaning"<<endl;
				fflush(stdin);
				getline(cin,b);
				cout<<"Enter type"<<endl;
				cin>>c;
				fflush(stdin);
				cout<<"Enter Sen1"<<endl;
				getline(cin,d);
				cout<<"Enter Sen2"<<endl;
				fflush(stdin);
				getline(cin,e);
				dictionary.AddWord(a,b,c,d,e);
				a.clear();
				b.clear();
				c.clear();
				d.clear();
				e.clear();
				s.clear();	
			}
			break;
		case 2:
			system("cls");
			cout<<"\n\n\t\t\t\t\tSEARCH WORD"<<endl;
			cout<<"Enter your word ";
			cin>>s;
			if(dictionary.SearchEntry(s)){
				dictionary.SearchWord(s);
			}else{
				dictionary.printAutoSuggestions(dictionary.root,s,l);
				if (l.head==NULL){
					cout<<"No matches found!"<<endl;
				}else{
					l.printList();
					cout<<"Select your word ";
					cin>>val;
					l.Searchkey(val);	
					}
			
			}
			s.clear();
			break;
		case 3:
			system("cls");
			cout<<"\n\n\t\t\t\t\tDELETE WORD"<<endl;
			cout<<"Enter your word ";
			cin>>s;
			dictionary.removeword(s);
			s.clear();
			break;
		case 4:
			exit(0);
		default:
			system("cls");
			cout<<"\t\t\t\t\tWrong choice entered\n\t\t\t\t\tTry Again ...."<<endl;
	}
	l.DeleteList();
	getch();
	goto mainmenu;
}
