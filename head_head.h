#include <iostream>
#include <cstring>
#include <cstdlib>//include libraries
using namespace std;
#define ROW 5 //num of rows
#define COL 5//num of cols

int defaulter[] = {34,21,32,41,25,14,42,43,14,31,54,45,52,42,23,33,15,51,31,35,21,52,33,13,23};
//default array of integers
int valuable_integers[] = {11,12,13,14,15,21,22,23,24,25,31,32,33,34,35,41,42,43,44,45,51,52,53,54,55};
//integers that we can use(appropiarite to aur array)

void printa(int box[ROW][COL],int des, int od){ //print array and element
    cout <<("\n\x1B[36m+----++----++----++----++----+\n");//use different color  
    for (int i = 0; i <ROW; i++){ //go through array
        for (int j = 0; j <COL; j++){
            if (i == des && j == od){ //if value == row*10 + col 
                cout << "|\033[0m" << "\x1B[33m "<< box[i][j] <<" \033[0m" << "\x1B[36m|";
                continue;//select it
            }    
            else
                cout << "| " <<box[i][j] <<" |" ; //shoe other element
        }        
        cout <<("\n+----++----++----++----++----+\n");
    }
    cout <<"\033[0m";
}


void printer(int box[ROW][COL]){ //show only array
    cout <<("\n+----++----++----++----++----+\n");    
    for (int i = 0; i <ROW; i++){ //go though array
        for (int j = 0; j <COL; j++){
            cout << "| " <<box[i][j] <<" |" ;//show each element
        }        
        cout <<("\n+----++----++----++----++----+\n");
    }
}

//check if element is in some array
bool check_in_array(int arr[25], int elem){ 
    int i;
    bool f; 
    f = false;
    for (i=0; i<25; i++) //go though array
        if (arr[i]==elem) //if elemnt one of it
            f = true; // return true
    return f;        //otherwise return false
}

    
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