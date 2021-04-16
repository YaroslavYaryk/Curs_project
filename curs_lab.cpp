#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;
#define ROW 5
#define COL 5

int valuable_integers[] = {11,12,13,14,15,21,22,23,24,25,31,32,33,34,35,41,42,43,44,45,51,52,53,54,55};

class Treasure_box{
        friend istream &operator >>(istream &stream, Treasure_box &obj);

private:
    int box[ROW][COL] = {{34,21,32,41,25},  
                     {14,42,43,14,31},
                     {54,45,52,42,23},
                     {33,15,51,31,35},
                     {21,52,33,13,23}};

    

    void printa(int des, int od){

        cout <<("\n+----++----++----++----++----+\n");    
        for (int i = 0; i <ROW; i++){
            for (int j = 0; j <COL; j++){
                if (i == des && j == od){
                    cout << "|*"<< box[i][j] <<"*|";
                    continue;
                }    
                else
                    cout << "| " <<box[i][j] <<" |" ;
            }        
            cout <<("\n+----++----++----++----++----+\n");
        }
    }


    static bool check_in_array(int arr[25], int elem){
        int i;
        bool f; 
        f = false;
        for (i=0; i<10; i++)
            if (arr[i]==elem)
                f = true;
        return f;        
    }

public:

    bool is_true(){

        for (int i = 0; i < ROW; i++){
            for (int j = 0; j <COL; j++){
                if (box[i][j] == (i+1)*10 + (j+1)){
                    return true;
                }  
            }      
        }            
        return false;
    }

    void randoma(){
        srand(time(NULL));
        for (int i=0; i< ROW; i++){
            for (int j = 0; j <COL; j++){
                int elem  = rand() % 25;
                this -> box[i][j] = valuable_integers[elem];
            }
        }
    }

    bool find_special_element(string operation = "work"){
        int start = box[0][0];
        int des_pos = (int)start/10;
        int od_pos = start%10;
        if (operation == "work"){
            printa(0, 0);
            printa(des_pos-1, od_pos-1);
        }
        int count = 0;
        while (box[des_pos-1][od_pos-1] != des_pos*10 + od_pos ){
            start = box[des_pos-1][od_pos-1];
            des_pos = (int)start/10;
            od_pos = start%10;
            if (operation == "check"){
                count+=1;
                if (count == 100)
                    return false;
            }        
            else if (operation == "work")       
                printa( des_pos-1, od_pos-1);
        }        
        
        if (operation == "check")
            return true ;          
        cout << ("found it ") ;
        cout << (box[des_pos-1][od_pos-1]);  

    }
    void printer(){
        cout <<("\n+----++----++----++----++----+\n");    
        for (int i = 0; i <ROW; i++){
            for (int j = 0; j <COL; j++){
                
                cout << "| " <<box[i][j] <<" |" ;
            }        
            cout <<("\n+----++----++----++----++----+\n");
        }
    }
    
};


istream &operator >>(istream &stream, Treasure_box &obj){

    cout << "make sure that element you're entering bigger than 11 and lowwer then 55"<< endl;
    for (int i = 0; i< 5 ; i++){
        for (int j = 0; j <5; j++){
            int elem;
            while (true){
                cout << "Box[" << i+1 << "]["<< j+1<< "]";

                stream >> elem;
                try{
                    if (cin){
                        if ( obj.check_in_array(valuable_integers, elem) ){
                            obj.box[i][j] = (int)elem;
                            break;
                        }
                        else{
                            throw 505 ;
                            
                        }
                    }
                    else{
                        throw 505 ;
                    } 
                }    
                catch(int n){
                    cout << "wrong type of element, try again" << endl;
                    cin.clear();
                    fflush(stdin);

                }
            }
        }
    } 
    return stream;
}





int main(){
    Treasure_box obj;
    string choice;
    cout << "Wanna start? ";
    cin >> choice;
    if (choice == "yes" || choice == "Yes" || choice == "1"){
        cout << "which one you wanna add element?\n1)On your own\n2)random\n3)default matrix" << endl;
        string result;
        cin >> result;
        if (result == "1" || result == "first")
            cin >> obj;
        else if (result == "2" || result == "second"){
            obj.randoma();
        }
        else if (result == "3" || result == "third"){

        }    

        if (obj.is_true() && obj.find_special_element("check")){
            obj.find_special_element();
        }
        
        else{
            cout << "sorry but  can't find treasure element" << endl;
            obj.printer();
        }
    }
    else{
        cout << "good luck" << endl;
    }
    return 0;

}