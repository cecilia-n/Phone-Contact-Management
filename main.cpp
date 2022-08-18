#include <iostream>
#define MAX 200 //can change to what we want, define variable
#include <limits> //for the age replacement

//fix looping when age not number
//fix when menu choice not 0-6 (DONE)

/*Am giving users a secondchance to fix their input errors*/


using namespace std;

    struct contacts //Put all the variables (created a type with struct)
    {
        string name;
        string phone;
        string address;
        string email;
        int age;
    };

     struct addressBook //address put list/array of contacts
    {
        contacts contactsArray[MAX]; //from struct type contacts, "list of contacts", data member of contacts
        int counter; //want to keep track of max

    };

    void showMenu(addressBook* book){
    cout<<" "<<1<< " Add Contact"<<endl;
    cout<<" "<<2<< " Delete All Contacts"<<endl;
    cout<<" "<<3<< " Delete One Contact"<<endl;
    cout<<" "<<4<< " Get Contact"<<endl;
    cout<<" "<<5<< " Modify Contact"<<endl;
    cout<<" "<<6<< " Show Contact"<<endl;
    cout<<" "<<0<< " To get out of the Menu \n"<<endl; //need to end while loop called in main later

};


        //"initalizing pointer object, just one entry (want a list of these pointer/s (objects))
    void addContact(addressBook* book){ // point to struct address Book; which has contacts array which points to,contacts, use pointer can point to  NULL, or say when reach NULL

        if(book->counter == MAX){ //our array of pointer book assigned to counter //check base case if reach our "max" , access our counter through pointer/object
             cout<<"cannot add. reached max."<<endl;//do not add
        }
        else{
             string cname;
             string cphone;
             string caddress;
             string cemail;
             unsigned short int cage;
             unsigned short int  newcage;

             cout <<"What is your name:"<<endl;
             cin>>cname;
             book -> contactsArray[book->counter].name = cname; //adding counter in address book array, to reach 200 mark; then increment later

             cout <<"What is your phone number:"<<endl;
             cin>>cphone;
             book -> contactsArray[book->counter].phone = cphone;

             cout <<"What is your address:"<<endl;
             cin>>caddress;
             book -> contactsArray[book->counter].address = caddress;

             cout <<"What is your email:"<<endl;
             cin>>cemail;
             book -> contactsArray[book->counter].email = cemail;


             cout <<"What is your age:"<<endl;
             cin>>cage;


             //while((cout <<"What is your age:"<<endl) && (cin>>cage) ){

                 if (cage ){

                     cout<<"Contact Added Successfully \n"<<endl;
                     book -> contactsArray[book->counter].age = cage;
                     book->counter+=1;//increment by 1
                     //break;


                }else{

                     cin.clear();
                     cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input//                    bool cinState = false;
//                      cin>>cage;
//                      cin.clear();
//                      cin>>cage;



                      cout<<"Cannot Add the Contact \n"<<endl;
                      cout<<"Please Choose a Positive Number Value for Age: "<<endl;
                      cin>>cage;


                      book -> contactsArray[book->counter].age = cage;
                      book->counter+=1;//increment by 1
                      //exit(cage);
                      //break;

                      }




           // }


        }

};

//listing contacts
void showContacts(addressBook* book){  //can name this array of pointers/objects/contacts anything, but keep consistent
    //for loop the array
    for(int i=0; i<book->counter; i++){
        cout<<"\n"<<book->contactsArray[i].name<<endl;  //accessing the contacts array "properties" by pointing/assigning book to each contactArray(calling struct from another struct)
        cout<<book->contactsArray[i].phone<<endl;
        cout<<book->contactsArray[i].address<<endl;
        cout<<book->contactsArray[i].email<<endl;
        cout<<book->contactsArray[i].age<< "\n"<<endl;
    }

};

//deletecontact//person->counter-=1
void deleteContact(addressBook* book){
    //try asking for phone number since it's unique compared to names
       string cphone;
       string cname;
       string caddress;
       string cemail;

       cout<<"Please enter the contact's phone # to delete Contact:"<<endl;
       cin>> cphone;
       cout<<"\n";

       for (int i=0; i< book->counter;i++){ //want to go through array to stop before counter (like index)
           if (book->contactsArray[i].phone == cphone){
               book->contactsArray[i]; //identify which contact to delete
               delete book; //Delete is an operator that is used to destroy array and non-array(pointer)
                                               //access the contacts array through pointer, delete each pointer in array
               cout<<"Contact is Deleted \n"<<endl;

               book->counter-=1; //remember to update the index
            }
    }
};
//deleteall or clearcontacts, empty it out
void deleteAll(addressBook* book){
    //remember to put type before
    for (int i=0; i<book->counter;i++){ //want to go through array to stop before counter (like index)
        book->contactsArray[i];
        delete book; //Delete is an operator that is used to destroy array and non-array(pointer)
                                       //access the contacts array through pointer, delete each pointer in array
        cout<<"Contacts All Deleted"<<endl;

        }
};

//modifycontact
void modifyContact(addressBook* book){
    string cname;
    string caddress;
    string cphone;
    string cemail;
    int cage;
    int num_input;

    cout<<"Please enter the contact's phone # to get Contact:"<<endl;
    cin>> cphone;
    cout<<"\n";
    for (int i=0; i< book->counter;i++){ //want to go through array to stop before counter (like index)
           if (book->contactsArray[i].phone == cphone){
                book->contactsArray[i]; //identify which contact to change
                cout<<"Please enter the # which you would like to modify: /n 1 for name, 2 for phone, 3 for address, 4 for email, 5 for age: /n"<<endl;
               cin>> num_input;
                //switch assign it to the contacts name, phone, address, email
               switch(num_input)
               {
                   case 1:
                        cout<< "Please enter the new name: "<<endl;
                        cin>>cname;
                        book -> contactsArray[i].name = cname; //assigning input to our contacts variable
                        break;
                   case 2:
                        cout<< "Please enter the new phone number: "<<endl;
                        cin>>cphone;
                        book -> contactsArray[i].phone = cphone;
                        break;
                   case 3:
                        cout<< "Please enter the new address: "<<endl;
                        cin>>caddress;
                        book -> contactsArray[i].address = caddress;
                        break;
                   case 4:
                        cout<< "Please enter the new email: "<<endl;
                        cin>>cemail;
                        book -> contactsArray[i].email = cemail;
                        break;
                   case 5:
                        cout<< "Please enter the new age: "<<endl;
                        cin>>cage;
                        book -> contactsArray[i].age = cage;
                        break;

               }


//    identify which contact it is, which part they want to change
//    then use switch statement to modify the value (phone, ) the contact we want to change

//like make variable that is all string, and another specifying phone
        }
    }
};


//getcontact
void getContact(addressBook* book){
       string cphone;
       cout<<"Please enter the contact's phone # to get Contact:"<<endl;
       cin>> cphone;
       cout<<"\n";

       for (int i=0; i< book->counter;i++){ //want to go through array to stop before counter (like index)
           if (book->contactsArray[i].phone == cphone){
               cout<<"Got Contact: \n"<<endl;
               book->contactsArray[i];
               cout<<book->contactsArray[i].name<<endl;  //accessing the contacts array "properties" by pointing/assigning book to each contactArray(calling struct from another struct)
               cout<<book->contactsArray[i].phone<<endl;
               cout<<book->contactsArray[i].address<<endl;
               cout<<book->contactsArray[i].email<<endl;
               cout<<book->contactsArray[i].age<< "\n"<<endl;

                //Delete is an operator that is used to destroy array and non-array(pointer)
                                               //access the contacts array through pointer, delete each pointer in array


               book->counter+=1; //remember to update the index
            }
       }

};


main(){
// checking addContacts
// abs.counter = 0;  //set counter/start to 0
// addContact(&abs);  //getting variable already made, "display value"/calling the address we made with *
// addContact(&abs);  //we will see that we add contacts twice in the showContacts
// showContacts(&abs);
  addressBook abs;
  showMenu(&abs);
  unsigned short int numSelect = 0;

  cout<<"Please Choose a Number for Contact Management: "<<endl;
  cin>> numSelect;

//Showing menu, keep showing until user press 0
while(true){ //runs without conditions until break statement executed,  //write while loop to ask ppl to get more contacts
 //keep relaunching showMenu until show 0

                //switch assign it to the contacts name, phone, address, email
               switch(numSelect)
               {
                   case 1:
                        addContact(&abs); //add multiple contacts
                        showContacts(&abs); //check if added
                        //cout<<"in case 1"<<endl; //print to make sure out of the while loop

                        break;

                   case 2:
                        cout<<"Showing Contacts before Delete All"<<endl;
                        cout<<"Showing Contacts after Delete All"<<endl;
                        deleteAll(&abs);
                        showContacts(&abs);

                        break;

                   case 3:
                        cout<<"Showing Contacts before Deleting Contact We Want:"<<endl;
                        showContacts(&abs);

                        cout<<"Showing Contacts after Deleting Contact We Want:"<<endl;
                        deleteContact(&abs);
                        showContacts(&abs);

                        break;

                   case 4:
                        getContact(&abs);
                        showContacts(&abs);
                        break;

                   case 5:
                        modifyContact(&abs);
                        showContacts(&abs);

                        break;
                   case 6:
                        showContacts(&abs);
                        break;

                   case 0:
                       cout<<"Out of the main menu"<<endl;
                       return 0; //to stop while loop
                       break;


               }
                    //cout<<"out of switch"<<endl;  //out of while loop, if the numSelect isn't those choices
                    cout<<"Please enter positive numbers from 0-6: "<<endl;
                    cin>>numSelect;
                    continue; //go to front of loop
                    break; //break out of while

        }


//
//

//
//  cout<<"out of while"<<endl;

// //Delete All Contacts
// cout<<"Showing Contacts before Delete All"<<endl;
// showContacts(&abs);
//
//
// cout<<"Showing Contacts after Delete All"<<endl;
// deleteAll(&abs);
// showContacts(&abs);

// //Delete A Contact
// cout<<"Showing Contacts before Deleting Contact We Want:"<<endl;
// showContacts(&abs);
//
//
// cout<<"Showing Contacts after Deleting Contact We Want:"<<endl;
// deleteContact(&abs);
// showContacts(&abs);

//getting Contact
//getContact(&abs);

//modifyContact(&abs);
//showContacts(&abs);

};





