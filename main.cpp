#include<iostream>
#include<string>
using namespace std; 

//CONTACT CLASS
class Contact{
    public:
    int key; 
    string name; 
    int age; 
    int phoneNumber; 
    string address; 
    Contact *next; //to point to the next contact object

   Contact(){ //default constructor 
    key, phoneNumber, age = 0; 
    name, address = " "; 
    next = NULL; 
   } 

   Contact(int k, string n, int a, int pN, string add){  // 
    key = k; 
    name = n; 
    age = a; 
    phoneNumber = pN; 
    address = add; 
   }
};


//AdressBook class to link all contacts together
class orderedAddressBook{
    public:
    Contact *head; //points first contact object
       orderedAddressBook(){
        head = NULL; //initially points to nothing since address book is empty
      }

      orderedAddressBook(Contact *n){ 
        head = n; //head address==node address
      }

      //WE HAVE TO CREATE A FUNCTION TO CHECK FOR EXISTING KEY ENTRIES FIRST
     Contact* nodeExists(int k){ //returns a pointer to the contact object of that key
     Contact* temp = NULL; 
     Contact* ptr = head; //store the head node address in ptr to use for traversing

       while(ptr!=NULL){ //TRAVERSAL
       if(ptr->key==k){ //if the ptr pointer points to a node with key value equal to the key value inputted
         temp = ptr; //store that contact bode adress in temp
       }
       ptr = ptr->next;//else, continue traversing

       }
       return temp; //will return NULL if node does not exist
    }

    void addContact(Contact* n){
        //ensure the key of this object doesnt exist
        if(nodeExists(n->key)!=NULL){
            cout<<"Contact with such key already exists!: "<<n->key<< endl; 
        }

        else{
         //CASE1 : ADDRESS BOOK IS EMPTY 
         if(head == NULL){
           head = n; //head now points to first node added 
           cout<<"  Contact added at the beginning!"<<endl; 
        }
          
        //CASE 2: ADDRESS BOOK NOT EMPTY
        else
        {
            Contact *current = head; //to traverse
            while(current->next!=NULL){ 
                current = current->next; 
            }
            current->next = n; 
            cout<<"Contact added successfully!"<<endl; 
        }
       }
    }

    void displayContacts(){
      //check if list is empty 
      if(head==NULL){
        cout<<"No contact available. You have no friends :)"<<endl; 
      }

      else{
        //traverse the list with a temp poinetr
        Contact* temp = head;
        cout<<"Contact list: "<<endl; 
        while(temp!=NULL){
          cout<<"Contact Name: "<< temp->name<< "--"<<"Age: "<<temp->age<<"--"<<"Address: "<<temp->address<<"--"<<"Phone numeber: "<<temp->phoneNumber<<endl; 
          temp = temp->next; 
        }
      }
    }

  void modifyContact(int key){
    Contact* ptr = nodeExists(key); //ptr holds adres of node with that key value
    if(ptr==NULL){
      cout<<"No Contact exists with that key"<<endl; 
      return; 
    }
    int optionx; 
    string name, adress; int age, pN; 
    cout<<"What parameter would you like to changed?"<<endl; 
    cout<<"select 1 for name\n 2 for age\n3 for adress\n4 for phonenumber"<<endl; 
    cin>>optionx;
    switch(optionx)
    {
    case 1:
      cout<<"Enter the modified name"<<endl; 
      cin.ignore();
      getline(cin, name);
      ptr->name = name; 
      break;

      case 2:
      cout<<"Enter the modified age"<<endl; 
      cin>>age; 
      ptr->age = age; 
      break;

      case 3:
      cout<<"Enter the modified adress"<<endl; 
      cin.ignore();
      getline(cin, adress);
      ptr->address = adress; 
      break;

      case 4:
      cout<<"Enter the modified phone nmber"<<endl; 
      cin>>pN; 
      ptr->phoneNumber = pN; 
      break;
    
    default:
      break;
    }
    cout<<"Contact successfully modified"<<endl; 
  }

  void deleteContact(int key){
     Contact* ptr = nodeExists(key); 

     if(head==NULL){
      cout<<"Address Book Already Empty"<<endl; 
     }

    else if(ptr==NULL){
      cout<<"No Contact exists with that key value"<<endl;  
    }

    else{
      //CASE 1: DELETING THE HEAD NODE.
     if(head->key == key){
      head = head->next; // simply make the head point to the next node
     }
    //CASE 2: DELETING AFTER THE HEAD NODE
     else {
      //entire list has to be traveresed to ge to that node
      //plus we need access to the two nodes to connect in ordder to delete the target center node
      //we need two pointers
       Contact* temp = NULL; 
       Contact* prevptr = head; //to begin traversal from first node 
       Contact* currentptr = head->next; //points to the node after the header

        while(currentptr != NULL){ //TRAVERSAL
          if(currentptr->key == key ){ //if theres's a match
            temp = currentptr; //store the adress of that currentptr in temp pointer
            currentptr = NULL; //so that you can exit the while loop
          }

            else{//continue traversal
            prevptr = prevptr->next; 
            currentptr = currentptr->next; 
          }
     }

     //outside the while loop
      prevptr->next = temp->next; //the link field of the previous node is now the adress in the link field of the target node
                                   //thus the previous node and next node is connected and target node is deleeted
        cout<<"Contact UNLINKED with keys value: "<<key<<endl; 
     }
    }
  }

  void countContacts(){
    int count = 0; 
    Contact *ptr = head;
    while(ptr!=NULL){
      count+=1;
      ptr=ptr->next; 
    }
    cout<<"You have "<<count<<" contact(s) in your address book!"<<endl; 
  }
};



int main(){
      orderedAddressBook A1; 
      int option, key, phoneNumber, age; 
      string name, address;
      int mkey; 

    do{
    cout<<"Welcome to the menu. Enter 0 to exit."<<endl; 
    cout<<"1, Add contact()"<<endl; 
       cout<<"2, Display contact()"<<endl; 
          cout<<"3, Modify a contact()"<<endl; 
             cout<<"4, Delete a contact()"<<endl; 
                cout<<"5, Count contacts()"<<endl; 
                   cout<<"6, Clear Screen()"<<endl; 

                      cin>>option;
                      Contact* mycon = new Contact(); 
                      switch(option){
                        case 0:
                        break; 

                        case 1:
                        cout<<"Enter contact key"<<endl; 
                        cin>>key; 
                       
                        cout<<"Enter contact name"<<endl; 
                         cin.ignore();
                        getline(cin, name); 
                       cout<<"Enter contact phneNumber"<<endl; 
                        cin>>phoneNumber;
                        cout<<"Enter contact age"<<endl; 
                        cin>>age; 
                        cout<<"Enter contact adress"<<endl;
                        cin>>address; 
                         mycon->age = age; 
                        mycon->address = address; mycon->phoneNumber = phoneNumber;
                        mycon->key = key;  mycon->name = name; 
                         A1.addContact(mycon); 
                        break; 
 
                     case 2:
                     A1.displayContacts();
                      break;

                      case 3:
                      cout<<"enter the key of the contact you want to modify"<<endl; 
                      cin>>mkey;
                      A1.modifyContact(mkey);  
                        break;

                      case 4:
                      cout<<"Enter the key of the cantact to be deleted"<<endl; 
                      cin>>key; 
                      A1.deleteContact(key);
                      break;

                      case 5:
                      A1.countContacts();
                      break; 

                      case 6:
                      system("cls");
                      break;

                      default:
                      cout<<"Enter proper option number"<<endl; 
                      break;           
                 };
                                    
    }while(option!=0);  
};
