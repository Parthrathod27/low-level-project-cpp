// Online C++ compiler to run C++ program online
#include <iostream>
#include<iomanip>
#include <unistd.h> 
#include<fstream>

using namespace std;

void loading(string text) {
    cout << "\n" << text;
    for (int i = 0; i < 3; i++) {
        cout << ".";
        cout.flush();
        sleep(1);
    }
    cout << "\n";
}

void clear() {
    cout << "\033[2J\033[1;1H"; // screen clear rehne do (color nahi hai)
}

class studentmanager{
    private:
       int rollno;
       string name;
       int age;
       string course;
    public:
        void userdetails(int rollno,string name,int age,string course){
            this->rollno=rollno;
            this->name=name;
            this->age=age;
            this->course=course;
        }
        void saveToFile() {
        ofstream file("students.txt", ios::app); // append mode
        file << rollno << " "
             << name << " "
             << age << " "
             << course << endl;
        file.close();
        }
        
        void displayFromFile() {
        ifstream file("students.txt");
        
        if(!file){
            cout << "File not found!\n";
            return;
        }

        cout << "\nROLL  NAME  AGE  COURSE\n";
        cout << "------------------------\n";

        while(file >> rollno >> name >> age >> course) {
            cout << rollno << "   "
                 << name << "   "
                 << age << "   "
                 << course << endl;
        }
        file.close();
        } 
        
        void searchStudent(int n){
            ifstream file("students.txt");
            if (!file) {
               cout << "File not found!\n";
               return;
            }
            bool found=false;
            while(file >> rollno >> name >> age >> course) {
                 if(n==rollno){
                     cout << rollno << "   "
                          << name << "   "
                          << age << "   "
                          << course << endl;
                          found=true;
                          break;
                  }
            }
            if(found==false){
                cout<<"Record not found\n";
            }
            file.close();
        }
        
         void updateStudent(int n){
             ifstream infile("students.txt");
             
             if (!infile) {
               cout << "File not found!\n";
               return;
            }
            
            ofstream tempfile("temp.txt");
            bool found=false;
            
            while(infile >> rollno >> name >> age >> course) {
                if(n==rollno){
                    found=true;
                    
                    cout << "\nENTER NAME OF THE STUDENT: ";
                    cin.ignore();
                    getline(cin, name);

                    cout << "\nENTER AGE OF THE STUDENT: ";
                    cin >> age;

                    cout << "\nENTER COURSE OF THE STUDENT: ";
                    cin.ignore();
                    getline(cin, course);
               
                    loading("updating record");
     
                
                    tempfile << rollno << " "
                             << name << " "
                             << age << " "
                             << course << endl;
                }
                    else{
                    tempfile << rollno << " "
                        << name << " "
                        << age << " "
                        << course << endl;
                    }
                }
                 infile.close();
                 tempfile.close();

                if (found) {
                   remove("students.txt");
                   rename("temp.txt", "students.txt");
                   cout << "\nStudent record updated successfully!\n";
                }
                else {
                   remove("temp.txt");
                   cout << "\nStudent not found!\n";
                }
            }
            
            void deleteStudent(int n){
                ifstream infile("students.txt");
             
                if (!infile) {
                   cout << "File not found!\n";
                return;
                }
                
                ofstream tempfile("temp.txt");
                bool found=false;
                
                while(infile>>rollno>>name>>age>>course){
                    if(rollno==n){
                    found = true;
                     continue;
                    }
                tempfile << rollno << " "
                         << name << " "
                         << age << " "
                         << course << endl;
                 }

                infile.close();
                tempfile.close();

                if (found) {
                   remove("students.txt");
                   rename("temp.txt", "students.txt");
                   cout << "\nStudent record deleted successfully!\n";
                }
               else {
                  remove("temp.txt");
                  cout << "\nStudent not found!\n";
                }
            }
};




void header() {
    cout <<setw(50)<<"================================";
    cout << "\n" << setw(47) << "STUDENT RECORD MANAGEMENT" << "\n";
    cout << setw(51)<<"================================\n";
}


void menu() {
    cout << "\n========== RECORD MENU ==========\n";
    cout << "1. ADD NEW STUDENT\n";
    cout << "2. VIEW ALL STUDENT\n";
    cout << "3. SEARCH STUDENT ( by roll number)\n";
    cout << "4. UPDATE STUDENT RECORD\n";
    cout << "5. DELETE STUDENT RECORD\n";
    cout << "6. EXIT\n";
    cout << "================================\n";
}

int main(){
    clear();
    header();
    studentmanager user;
    int n;
    
    cout<<"\nDO YOU WANT TO CONTINUE WITH STUDENT RECORD MANAGEMENT ? \n";
    cout<<"(PRESS 0 FOR YESS , 1 FOR EXIT!) :";cin>>n;
    
    
    if(n==1){
        cout<<endl;
        cout << "\n" << setw(45) << "THANK YOU, VISIT AGAIN :)" << "\n";
        return 0;
    }
       int rollno;
       string name;
       int age;
       string course;
    
       cout<<"\nENTER ROLL NUMBER OF THE STUDENT : \n";cin>>rollno;
            cout<<"\nENTER NAME OF THE STUDENT : \n";
            cin.ignore();            
            getline(cin, name);      
            cout<<"\nENTER AGE OF THE STUDENT : \n";cin>>age;
            cout<<"\nENTER COURSE OF THE STUDENT : \n";
            cin.ignore();            
            getline(cin, course);
    
       loading("Creating your account");
     
       user.userdetails(rollno,name,age,course);
       user.saveToFile(); 
    
       cout << "\nUSER DETAILS STORED SUCCESSFULLY!\n";
    
       sleep(1);
       clear();
       header();
    
    while(true){
        menu();
        
        int choice;
        cout << "\nEnter Your Choice: ";
        cin >> choice;
        
        if(choice==1){
            cout<<"\nENTER ROLL NUMBER OF THE STUDENT : \n";cin>>rollno;
            cout<<"\nENTER NAME OF THE STUDENT : \n";
            cin.ignore();            
            getline(cin, name);      
            cout<<"\nENTER AGE OF THE STUDENT : \n";cin>>age;
            cout<<"\nENTER COURSE OF THE STUDENT : \n";
            cin.ignore();            
            getline(cin, course);
    
            loading("Creating your account");
     
            user.userdetails(rollno,name,age,course);
            user.saveToFile(); 
    
            cout << "\nUSER DETAILS STORED SUCCESSFULLY!\n";
        }
        
        else if(choice==2){
            user.displayFromFile();
            
        }
        
        else if(choice==3){
            int x;
            cout<<"ENTER THE ROLL NO OF THE STUDENT : ";cin>>x;
            user.searchStudent(x);
        }
        
        else if(choice==4){
            int y;
            cout<<"ENTER THE ROLL NO FOR UPDATE STUDENT RECORD   :\n";cin>>y;
            user.updateStudent(y);
        }
        
        else if(choice==5){
            int t;
            cout<<"ENTER ROLL NO TO DELETE STUDENT DETAILS : ";
            cin>>t;
            user.deleteStudent(t);
        }
        
        else if (choice == 6) {
            cout << "\n" << setw(45) << "THANK YOU FOR USING STUDENT RECORD MANAGEMENT :)" << "\n";
            break;
        }
        else {
            cout << "Invalid Choice! Try Again.\n";
        }
        
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
        clear();
        header();
    }
    
    return 0;
}

