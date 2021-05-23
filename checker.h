#include <iostream>
#include <cstdlib>//include libraries
using namespace std;
#define ROW 5 //num of rows
#define COL 5//num of cols

int defaulter[] = {34,21,32,41,25,14,42,43,14,31,54,45,52,42,23,33,15,51,31,35,21,52,33,13,23};
//default array of integers
int valuable_integers[] = {11,12,13,14,15,21,22,23,24,25,31,32,33,34,35,41,42,43,44,45,51,52,53,54,55};
//integers that we can use(appropiarite to aur array)
class Storage{
public:
    void printa(int box[ROW][COL],int des, int od);
    void printer(int box[ROW][COL]);
    bool check_in_array(int arr[25], int elem);
};