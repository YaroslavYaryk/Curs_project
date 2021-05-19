#include <chrono>
#include "head.h" //include header file
using namespace chrono;

int main(){
    system("cls"); //clean buffer
    auto begin = steady_clock::now(); //start our timer
    Treasure_box obj; //create an object if class 
    int result; //result variable
    int choicen = 1; //try again variable

    while (choicen == 1){ //while wanna play 
        print_start(); //call start function
        cin >> result;//input result
        if (cin){
            if (result == 1)
                input(obj);//fill on our own
            else if(result == 2)     
                obj.randoma(); //random filling
            else if(result == 3)
                obj.set_default(); // default matrix
            else if (result == 4)
                break; //quit
            else{ //other
                cout << "\a\x1B[31mWrong answer\033[0m\n";
                continue; //ask again
            }
        }
        else{
            cout << "\a\x1B[31mwrong type of value, try again\033[0m" << endl; //try again
            cin.clear();//clear buffer
            fflush(stdin);
            continue;
        }
       

        auto begin = steady_clock::now();// start timer of worhing of the program
        if (obj.is_true() ){ //if there is a treasure element
            if (obj.find_special_element("check")) //if we can get to it
                obj.find_special_element(); //call function that find
            else{//can't get to element 
                cout << endl <<"\x1B[36msorry but  can't find way to treasure element\033[0m" << endl; 
            }    
        }
        else{ // there is no such an element
            cout << endl <<"\x1B[36msorry but  there is no treasure element\033[0m" << endl;

        }
        auto end = steady_clock::now(); //stop the second timer
        auto elapsed_ms = duration_cast<milliseconds>(end - begin); //get time
        cout <<  "\x1B[35m| time is : " <<  elapsed_ms.count() << "ms |\033[0m\n"; //print time
               
        while(true){//try again
            print_again();
            try{
                cin >> choicen; //continue playing or quit
                if (cin){ //check if it's integer
                    if (choicen == 1 || choicen == 2) // 1 or 2
                        break; //we entered correct answer (up to choice)  
                    else{//not 1 or 2
                        throw 505; //error
                    }    
                }
                else{//not integer
                    throw 505;//error
                }
            }
            catch(int i){ //except errors
                cout << "\a\x1B[31mWrong answer\033[0m" << endl;
                cin.clear(); //clear buffer
                fflush(stdin);
            }
        }
	}    

    cout << "\x1B[32mThat was  pleasure to work with you, good luck, buddy\033[0m" << endl;//print text (diff color)
    auto end = steady_clock::now();//stop timer
    auto elapsed_ms = duration_cast<seconds>(end - begin);//get time from it
    cout << "\x1B[35m| total time is : " << elapsed_ms.count() << " s |\033[0m" << endl;//print time
}


