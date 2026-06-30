#include<iostream>
#include<fstream>
using namespace std;

struct karbar{
	string username;
	string password;
	float balance = 100;
};

struct admins{
	string username;
	string password;
};

struct items{
	string name;
	int quantity;
	int price;
};



int maxofusers = 2;
int maxofadmins = 2;
int maxofitems = 10;


karbar users[3] ={ {"ayda" , "403123" , 100 } , {"ayda" ,"580201" , 100 } , { "sam" , "234567" , 100 } };
admins admin[2] = {{"aylin" , "ay2006" } ,{"aram" , "324321" }};
items item[10] =  {{"banana" , 10 , 20},{"tomato" , 8 , 10},{"carrot" , 5 , 30},{"watermelon" , 2 , 50},{"potato" , 8 , 15},{"apple" , 10 , 24},{"pineapple" , 12 , 30},{"berry" , 15 , 40},{"strawberry" , 10 , 60},{"orange" , 18 , 70}};


void readItemfromFile(){
	ifstream file("sole.txt");
	if(!file){
		ofstream newfile("sole.txt");
		newfile << "banana 10 20"<<endl<<"tomato 8 10"<<endl<<"carrot 5 30"<<endl<<"watermelon 2 50"<<endl<<"potato 8 15"<<endl<<"apple 10 24"<<endl<<"pineapple 12 30"<<endl<<"berry 15 40"<<endl<<"strawberry 10 60"<<endl<<"orange 18 70";
		newfile.close();
	}
	file.open("sole.txt");
}

void saveItemtoFile(){
	ofstream file("sole.txt");
	for(int i = 0 ; i < 10 ; i++){
	file << item[i].name << " " << item[i].quantity << " " << item[i].price << endl;
	}
	file.close();
}


bool who_is_user(string username , string password){
	
	for(int i =0 ; i<maxofusers  ; i++){
	
		if(users[i].username == username && users[i].password == password){
			cout << "# Welcome user, " << username << "!" << endl;
			return true;
		}
		}
		return false;
	}
	
	bool is_user(string username, string password) {
    for (int i = 0; i < maxofusers; i++) {
        if (users[i].username == username && users[i].password == password) {
            return true;
        }
    }
    return false;
}
	
	
	
bool who_is_admin(string username , string password){
	for(int i = 0 ; i<maxofadmins ; i++){
		if(admin[i].username == username  && admin[i].password == password ){
			cout << "$ Welcome admin, "<< username<< "!" <<endl;
			return true;
		}
	}
	return false;
}


bool is_admin(string username, string password) {
    for (int i = 0; i < maxofadmins; i++) {
        if (admin[i].username == username && admin[i].password == password) {
            return true;
        }
    }
    return false;
}




void show(){
	cout<<"# Available items:"<<endl;
	for(int i =0 ; i<10 ; i++){
		cout<<" * "<< item[i].name <<endl;
	}
}

void show_items(string item_name){
	for(int i = 0 ; i<10 ; i++){
		if(item_name == item[i].name){
			cout<<"# item name ====>"<<item_name<<endl;
			cout<<"# price ====>"<<item[i].price<<endl<<"-----------------------------------------------------------"<<endl;
			return;
		}
	}
	cout << "# item not found!" << endl;
}

void buy_item(string itemname , int quantity){
	for(int i = 0 ; i<10 ; i++){
		if(itemname == item[i].name){
			if(quantity > 0 && users[maxofusers].balance >= (item[i].price*quantity)){
				item[i].quantity = item[i].quantity - 1 ;
				users[maxofusers].balance -= item[i].price;
				cout<<"# Bought successfully "<<itemname<<"!" << endl <<"---------------------------------"<< endl << "# New balance====>" << users[maxofusers].balance << endl;
				saveItemtoFile();	
				return;
			}
		}
	}
	cout<<"# There is not enough money..."<<endl;
	saveItemtoFile();
}


void balance()
{
	cout<<users[maxofusers].balance << endl;
}

void helpCommand(){
	cout << "# Commands:" << endl;
	cout << " - show : see all items." << endl;
	cout << " - show_items : see all items with detail." << endl;
	cout << " - buy_item : buy items." << endl;
	cout << "- balance : see balance of user." << endl;
	cout << " - exit : exit the program." << endl;

}



void price(int newprice , string itemname){
	for(int i = 0 ; i<10 ; i++){
		if(itemname == item[i].name){
			item[i].price = newprice;
			cout << " $ New price ====> " << item[i].price << endl;
			saveItemtoFile();
			return;
		}
	}
cout<<"$ Item not found !"<<endl;
saveItemtoFile();	
}

void add_item(){
	string item_name;
	int item_quantity;
	int item_price;
	cout << "$ Enter the name of the new item: " << endl;
	cin >> item_name;
	cout << "$ Enter the quantity of the item: " << endl;
	 cin >> item_quantity;
	 cout << "$ Enter the price of the item: " << endl;
     cin >> item_price;
	 
    if(item_quantity <= 0) {
    	cout << "$ please enter a positive quantity..." <<endl;
    }
    if(item_price <= 0) {
    	cout << "$ please enter a positive price..." << endl;
    }

    
    item[maxofitems].name = item_name;
    item[maxofitems].quantity = item_quantity;
    item[maxofitems].price = item_price;
    maxofitems++;
    
    saveItemtoFile();
    return; 
    
    cout << "$ Item added successfully!" << endl;
    saveItemtoFile();
}


void remove_item(){
	string item_name;
	cout << "$ Enter the name of the item to remove: ";
	cin >> item_name;
	for (int i = 0; i < maxofitems; i++) {
        if (item[i].name == item_name) {
        	maxofitems = maxofitems - 1;
        	cout << "$ maxofitems:" << maxofitems << endl;
        		saveItemtoFile();
        }
    }
}

void rename_item(string oldname , string newname){
	for(int i = 0 ; i < maxofitems ; i++){
		if(item[i].name == oldname){
			newname = item[i].name;
			cout << "$ New name : " << newname << endl;
			saveItemtoFile();
			return;
		}
	}
	cout << "$ item not found!" ;
		saveItemtoFile();
}

void credit_user(string username , int amount){
	for(int i = 0 ; i < 3 ; i++){
		if(users[i].username == username){
			users[maxofusers].balance += amount;
			cout << "$ New balance : " << users[maxofusers].balance << endl;
			saveItemtoFile();
			return;
		}
	}
	cout << "$ user not found!" << endl;
	saveItemtoFile();
}


//user command function
void user_commands(string cmd){
	bool notdone = false;
if(cmd == "show"){
	show();
	notdone = true ;
}

 if(cmd == "show_item"){
	string itemname;
	cout << "# please enter itemname:" << endl;
	cin >> itemname;
	show_items(itemname);
	notdone = true ;
}

 if(cmd == "buy_item"){
	
		string itemname;
		cout << "# please enter itemname:" << endl;
		cin >> itemname;
		cout << "# please enter the quantity:" << endl;
		int quantity;
		cin >> quantity ;
		buy_item(itemname , quantity);
		notdone = true ;
	}
	
 if(cmd == "balance"){
	balance();
	notdone = true ;
}
if(cmd == "help"){
	 helpCommand();
	 notdone = true;
}
if(!notdone){
	cout << "it is not valid for a user..." << endl;
}


}

// admin command function
void admin_commands(string cmd){
	bool notdone = false;
	if(cmd == "price"){
		cout << "$ please enter itemname:" << endl;
		string itemname;
		cin >> itemname;
		cout << "$ please enter newprice:" << endl;
		int newprice;
		cin >> newprice;
		price(newprice , itemname);
		notdone = true;
	}

if(cmd == "add_item"){
 	add_item();
 	notdone = true;
 }
 
 if(cmd == "remove_item"){
 	remove_item();
 	notdone = true;
 }
 
 if(cmd == "rename_item"){
 	cout << "$ please enter itemname:" << endl;
 	string itemname;
 	cin >> itemname;
 	cout << "$ please enter newname:" << endl;
 	string newname;
 	cin >> newname;
 	rename_item(itemname , newname);
 	notdone = true;
 }
 
 if(cmd == "credit_user"){
 	cout << "# please enter username:" << endl;
 	string username;
 	cin >> username;
 	cout << "# please enter amount:" << endl;
 	int amount;
 	cin >> amount;
 	credit_user(username , amount);
 	notdone = true;
 }
 if(!notdone){
 	cout << "it is not valid for an admin..." << endl;
 }

}


int main()
{
	readItemfromFile();
		
	cout << "welcome to WMS!" << endl;
	cout  <<"Enter your username:" << endl;
	string username;
	cin >> username;
	
	cout << "Enter your password:" << endl;
	string password;
	cin >> password;
	
	if (!who_is_user(username, password) && !who_is_admin(username , password)) {
        cout << "User not found!" << endl;
        return 0;
    }
    
    cout << "You can type 'help' to see all commands." << endl;
	
	cout<<"if you want to leave , type exit."<<endl;
	
		while(true){
			cout << "Enter command: " << endl;
		string cmd;
		cin >> cmd;
		
		
		if(cmd == "exit"){
			cout << "Goodbye! Have a good day!" << endl;
			break;
		}
	if (is_user(username , password)) {
            user_commands(cmd);
        } else if (is_admin(username , password)) {
            admin_commands(cmd);
        }
	}
	
	return 0;
}








	
	
	
