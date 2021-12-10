/*
 * Name -> Ashutosh Pandey
 * Roll No. -> 196320027
 * Branch and Sem -> ECE , Vth sem
 * Assignment - 08
 * CPP
 */


/*
 * Header files :
 * These files contain the set of predefined standard library functions.
 */
#include <iostream>
/*
*The using namespace statement just means that in the scope it is present, 
    make all the things under the std namespace available without having to prefix std:: 
    before each of them
*/
using namespace std;
/*
 * class BaseClass to demonstrate the use of default , parameterized 
 * inheritance and friend function !
 */
class BaseClass
{
/* 
  * private varibles (members) --> (Encapsulation)
  * So that no one can access it from outside
  * Use getters and setter to access them from outside class !
  * */
private:
    string name;
    string address;
    string phoneNumber;

public:
    /*
     * Default constructor 
     * It is called automatically while creating class object !
     * It also assign value into name .
     */
    BaseClass(){
        name = "Jitendra kumar Sharma";
        address = "Haridwar, FET";
        phoneNumber = "9898765435";
    }
    /*
     * Parameterized constructor 
     * It is called when parameters are passed while creating object!
     * It also assign the same like the address paramter into address variable and same for other!
     * this-> (Keyword) It is a reference of class .
     * this->name means we are assigning value in name variable of class !
     * we don't need (this) if we pass different name inside parameters than class variable names.
     * 
     * */
    BaseClass(string name , string address, string phoneNumber){
        this->name = name;
        this->address = address;
        this->phoneNumber = phoneNumber;
    }
    /*
    *   Getters and Setters
    *   To get and set the fields of class.
    *   They are made public so that we can access it from outSide.
    *   We are using getters and setters so that no one can directly access our members.
    *   We restrict the user in getter and setter by applying some conditions !
    *   Like set only we it contains 10 digits of mobile numbers other wise show some message to user.
    */
    string getName(){
        return name;
    }
    string getAddress(){
        return address;
    }
    string getPhoneNumber(){
        return phoneNumber;
    }
    void setName(string Name){
        name = Name;
    }
    void setAdress(string Address){
        address = Address;
    }
    void setPhoneNumber(string number){
        phoneNumber = number;
    }
    /*
    * Function to print Details of student !
    */
    void printDetails(){
        cout << endl << "My Name is : " << name << endl 
                <<"My Address is : " << address << endl
                <<"My Phone Number is : " << phoneNumber << endl;
    }
    /*
    * This is for inheritance Demonstration !
    */
   void printBase(){
       cout<<"I am from BaseClass ! "<<endl;
   }
   /*
   *This is for friend function !
   */
  friend string printName(BaseClass);
};
/*
* Student class is a derived class from base , This class is for demonstration purpose !
*/
class Student : public BaseClass{
    private :
    int rollNo;
    int studClass;
    char section;
    public :
    Student(){
        rollNo = 196320027;
        studClass = 12;
        section = 'A';
    }
    Student(int rollno, int studClass, char section){
        this->rollNo = rollno;
        this->studClass = studClass;
        this->section = section;
    }
    int getRollNo(){
        return rollNo;
    }
    /*
    * This function is to print student details
    */
    void printStudent(){
        cout<<endl<<getName()<<endl;
        printBase();
        cout<<endl<< "My Roll no. is : "<<rollNo <<endl
            <<"My class is : "<<studClass << endl
            <<"My section is : " << section<<endl;
        cout<<"I am from Student class, derived From Base Class !"<<endl;
    }
};
string printName(BaseClass b){
    cout<<"Name is :: "<<b.getName()<<endl;
    return "";
}
int main()
{   
    /*
    *  Creating normal object , so that it can call defautl constructor !
    */
    BaseClass s1;
    // s1.printDetails();
    // printName(s1);
    cout<<endl;
    /*
    * Creating another object , for parameterized constructor !
    */
    BaseClass s2("Maya Bhai","Lucknow","9898776643");
    s2.printDetails();
    cout<<endl;
    /*
    * Creating object of derived class , to demonstrate inheritance !
    */
   Student s3;
   s3.printDetails();
   s3.printStudent();
   s3.printBase();
   /*
   * with constructor parameters !
   */
   Student s4(196320028, 10, 'B');
   s4.printDetails();
   s4.printStudent();
   s4.printBase();
    
    return 0;
}