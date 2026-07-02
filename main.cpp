#include <iostream>
#include <chrono>
#include <thread>

using namespace std;


string pass;
string name;
bool account = false;
string passguess;
string nameguess;
int guesses = 0;
bool signedin = false;
int balance = 0;

// Establishes the function mainloop()
void mainloop();


// function to create the account, stores the password in pass and username
// in name.
//
void createaccount(){
    cout << "What Is Your Username For Your Account \n";
    cin >> name;
    cout << "What Is Your Password For Your Account \n";
    cin >> pass;


    account = true;

    mainloop();
}
// sign in, uses pass and name to see if it matchs with nameguess
// and passguess

void signin(){
    if(account == true){
    for(guesses=0; guesses <= 3; guesses++){
        cout << "What is Your Username? \n";
        cin >> nameguess;
        cout << "What is your Password? \n";
        cin >> passguess;

        if(nameguess == name && pass == passguess){
            account = true;
            signedin = true;
            cout << "Welcome Back " << name << "\n" << "\n";
            mainloop();
            break;

        }
        else{
            while(guesses == 3){
            cout << "Due To Suspicious Activity In Your Account Wait 10 Seconds \n";
            this_thread::sleep_for(chrono::seconds(10));
;

            guesses = 0;
            }
        }

    }
}
    else{
        cout << "Account Not Found Please Register With One \n";
        this_thread::sleep_for(chrono::seconds(2));
    }
}
// deposits money into the users account
void deposit(){

    if(!account){
        cout << "Please Make A Account To Use This Program";
    }

    else{

    int amount;

    cout << "How Much Do You Want To Deposit? \n";
    cin >> amount;

    if(amount <= 0){
        cout << "Please Do A Vaild Number \n";
    }
    else{
    cout << "Your New Balance Is  " << balance + amount << "\n";
    balance = balance + amount;

    mainloop();

}
}
}

void withdrawl(){
    int amount;

if(!account){
    cout << "Please Make A Account To Use This Program";
}




else{
    cout << "How Much Would You Like To Withdrawl \n";
    cin >> amount;

    if(amount <= 0 || amount > balance){
        cout << "Trying To Withdrawl More Then You Own?!!! How Greedy \n";



    }
    else{
        cout << "You Have Successfully Withdrawled " << amount << "Your New Balance Is \n" << balance;
        balance = balance - amount;

        mainloop();



    }
}
}

void mainloop(){
    int option;


    cout << "====== Banking Program ====== \n";
    cout << "1. Create Account \n";
    cout << "2. Sign Into Account \n";
    cout << "3. Deposit Money \n";
    cout << "4. Withdrawl Money \n";

    cin >> option;

    if(option == 1){
        createaccount();
    }
    else if(option == 2){
        signin();
    }
    else if(option == 3){
        deposit();
    }
    else if(option == 4){
        withdrawl();
    }
    else{
        cout << "Invalid Option";
    }
}


int main(){
    mainloop();
}
