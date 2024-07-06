#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Items{
    public:
       int id;
       string name;
       int quantity;
    Items(int id, string name, int quantity){
        this->id = id;
        this->name = name;
        this->quantity = quantity;
    }
};

class Inventory{
   private: 
   vector<Items> items;
   
   public:
    void addItems(Items item){
        items.push_back(item);
    }
    void displayItems(){
         if (items.empty()) {
            cout << "No items in inventory." <<endl;
            return;
        }

        cout<<"---------- Inventory List: ----------"<<endl;
        for(int i = 0; i < items.size(); i++){
            cout << "Item ID: " << items[i].id <<endl;
            cout << "Item Name: " << items[i].name <<endl;
            cout << "Item Quantity: " << items[i].quantity << endl <<endl;
        }
    }
    void searchByName(string name){
        bool found = false;
        for(int i = 0; i < items.size(); i++){
            if(items[i].name == name){
                cout << "Found item - ID: " << items[i].id << ", Name: " << items[i].name << ", Quantity: " << items[i].quantity <<endl;
                found = true;
                break;
            }
        }
        if(!found){
            cout << "No item found with the name '" << name << "'." <<endl;
        }
    }
    
    void searchById(int id){
        bool found = false;
        for(int i = 0; i < items.size(); i++){
            if(items[i].id == id){
                cout << "Found item - ID: " << items[i].id << ", Name: " << items[i].name << ", Quantity: " << items[i].quantity <<endl;
                found = true;
                break;
            }
        }
        if(!found){
            cout << "No item found with the ID '" << id << "'." <<endl;
        }
    }
};

int main(){  
   Inventory inventory;
   int choice;

    do{
     cout << "\n-------------Inventory Management System Menu:-------------"<<endl;;
        cout<<"1. Add Item"<<endl;
        cout<<"2. Display Items"<<endl;
        cout<<"3. Search for Item by Name"<<endl;
        cout<<"4. Search for Item by ID"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter your choice (1-5): "<<endl;
        cin>>choice;

    switch(choice){
    case 1:{
        int id, quantity;
        string name;
        cout << "Enter item ID: "<<endl;
        cin >> id;
        cout << "Enter item name: "<<endl;
        cin.ignore();  // To ignore the newline character left in the buffer
        getline(cin, name);
        cout << "Enter item quantity: "<<endl;
        cin >> quantity;
        inventory.addItems(Items(id, name, quantity));
        break; 
    }
    case 2:{
        inventory.displayItems();
        break;
    }
    case 3:{
        // Search for Item by Name
        string name;
        cout << "Enter item name to search: "<<endl;
        cin.ignore();  // To ignore the newline character left in the buffer
        getline(cin, name);
        inventory.searchByName(name);
        break;
    }
    case 4: {
        // Search for Item by ID
        int id;
        cout << "Enter item ID to search: "<<endl;
        cin >> id;
        inventory.searchById(id);
        break;
    }
    case 5:{
        cout << "Exiting the program." <<endl;
        break;
    }
    default:{
        cout << "Invalid choice. Please enter a number between 1 and 5."<<endl;
        break; 
    }          
    }
  }while(choice != 5);

   return 0;
}