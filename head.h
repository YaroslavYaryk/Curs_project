#include "head_head.h"

class Treasure_box { //main class
    friend void input(Treasure_box & obj); //friend function of filling arrat
private:
    int box[ROW][COL]; //our private array

public:
    bool is_true(){ //fonction checks if it is treasure
        for (int i = 0; i < ROW; i++){   
            for (int j = 0; j <COL; j++){
                if (box[i][j] == (i+1)*10 + (j+1)){
                    return true; //if it is 
                }  
            }      
        }
        //otherwise 
        printer(box); //print array
        return false;//return false
    }


    void set_default(){ //fill our matrix by default elements
        int index = 0;//as it's said in the example
        for(int i = 0; i< ROW; i++){
            for(int j = 0; j < COL; j++){
                this->box[i][j] = defaulter[index]; //array default elements
                index+=1;
            }
        }
    }


    void randoma(){//filling random elements
        srand(time(NULL)); //generate of random symbols
        for (int i=0; i< ROW; i++){
            for (int j = 0; j <COL; j++){
                int elem  = rand() % 25; // from 0 to 25 
                this -> box[i][j] = valuable_integers[elem]; //get  element from  
            } //array of valuable integers
        }
    }


    //function can work in two modes (work and check)
    //if it's check wy try to find element if it's 
    //possible - return true
    //if "work" it show all way
    bool find_special_element(string operation = "work"){ // main function
        int start = box[0][0]; //firts element 
        int des_pos = (int)start/10;//get decimal position
        int od_pos = start%10; //get single position
        int count = 0; //counter

        if (operation == "work"){ 
            if (box[des_pos-1][od_pos-1] == 11){ //if first elem is treasure
                printa(box,0, 0); //print array
                cout << ("\x1B[33mfound it  11 ") ;
                cout << endl <<"make 1 step\033[0m" <<endl; //count of steps
                return true; //return true
            }
            //else
            printa(box,0, 0); //print first step
            printa(box,des_pos-1, od_pos-1); //print second steo
            count +=1; //add 1 to couner
    
        }
        while (box[des_pos-1][od_pos-1] != des_pos*10 + od_pos ){ //while it's not treasure
            start = box[des_pos-1][od_pos-1]; //get element to 'new' start
            des_pos = (int)start/10;//get decimal position
            od_pos = start%10;//get single position
            count+=1;//add 1 to couner
            if (operation == "check"){
                if (count == 26){ // if count is 26 (max possible can be 25) so we cnt 
                //fint it anyway
                    printer(box); //print array
                    return false;
                }
            }        
            else if (operation == "work")  { //if it's work
                printa(box, des_pos-1, od_pos-1); // select this step
            } 
        } 

        //we found theasure
        if (operation == "check")
            return true ;  //return   
        //else     
        cout << "\x1B[33mFound it ";
        cout << (box[des_pos-1][od_pos-1]);  //select treause
        cout << endl <<"make " << count+1 << " steps\033[0m" <<endl;//show count of steps
        return true;
    }

};


void input(Treasure_box & obj){ //function of filling array 
    cout << "make sure that element you're entering bigger than 11 and lowwer then 55"<< endl;
    for (int i = 0; i< 5 ; i++){ //go througt array
        for (int j = 0; j <5; j++){//...
            int elem;
            while (true){ //in order to catch the mistake of input
                cout << "Box[" << i+1 << "]["<< j+1<< "]"; 
                try{
                    cin >> elem; //try to input element
                    if (cin){ //check if we entered exactly integer
                        if (check_in_array(valuable_integers, elem) ){ //if it's appropiarite integer
                            obj.box[i][j] = (int)elem; //we add it to our array
                            break;
                        }
                        else{
                            throw 505 ; //if it's not in valuable integer throw an error
                        }
                    }
                    else{
                        throw 505 ; //if it's not ineger
                    } 
                }    
                catch(int n){
                    cout << "\a\x1B[31mwrong type of element, try again\033[0m" << endl; //try again
                    cin.clear();//clear buffer
                    fflush(stdin);
                }
            }
        }
    }
}

