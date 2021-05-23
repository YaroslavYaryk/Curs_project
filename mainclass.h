#include "ckecker.cpp"

using namespace std;
#define ROW 5 //num of rows
#define COL 5//num of cols
class Treasure_box : public Storage{ //main class
    friend void input(Treasure_box & obj); //friend function of filling arrat
private:
    int box[ROW][COL]; //our private array
public:
    Treasure_box();
    bool is_true();
    void set_default();
    void randoma();
    bool find_special_element(string operation);
    ~Treasure_box();
    void input(Treasure_box & obj);
};    
