
void print_start(){//start menu
    string tabs = " ---------------------------------"; 
    cout << " _________________________________" << endl;
    cout << "| which one you wanna add element |" << endl;
    cout << tabs << endl; 
    cout << "| 1) On your own                  |" <<endl;
    cout << tabs << endl; 
    cout << "| 2) Random matrix                |" <<endl;
    cout << tabs << endl; 
    cout << "| 3) Default one                  |" <<endl;
    cout << tabs << endl; 
    cout << "| 4) quit                         |" <<endl;
    cout << tabs << endl; 
}


void print_again(){ //ask try again
    string tabs = " ------------------------"; 
    cout << " ________________________" << endl;
    cout << "| What should we do now? |" <<endl;
    cout << tabs << endl;
    cout << "| 1) Play one more time  |" <<endl;
    cout << tabs << endl;
    cout << "| 2) just quit           |" <<endl;
    cout << tabs << endl;
}

int get_result_to_try_again(int choicen){
     while(true){//try again
        print_again();
        try{
            cin >> choicen; //continue playing or quit
            if (cin){ //check if it's integer
                if (choicen == 1 || choicen == 2) // 1 or 2
                    return choicen; //we entered correct answer (up to choice)  
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
            continue;
        }
        return 0;
    }    
}
