#include "checker.h"
using namespace std;
#define ROW 5 //num of rows
#define COL 5//num of cols

void Storage:: printa(int box[ROW][COL],int des, int od){ //print array and element
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


void Storage:: printer(int box[ROW][COL]){ //show only array
    cout <<("\n+----++----++----++----++----+\n");    
    for (int i = 0; i <ROW; i++){ //go though array
        for (int j = 0; j <COL; j++){
            cout << "| " <<box[i][j] <<" |" ;//show each element
        }        
        cout <<("\n+----++----++----++----++----+\n");
    }
}


//check if element is in some array
bool Storage:: check_in_array(int arr[25], int elem){ 
    int i;
    bool f; 
    f = false;
    for (i=0; i<25; i++) //go though array
        if (arr[i]==elem) //if elemnt one of it
            f = true; // return true
    return f;        //otherwise return false
}

    
