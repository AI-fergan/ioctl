#include "visual.h"
#include "communicator.h"
#include "pch.h"

int main(void){
    int option;
    bool result;
    do{
        system("clear");
        creatorSign();
        option = options();
        result = communicator(option - 1, getPid());
        cout << "result: " << result << endl;
        cout << "press any key to continue" << endl;
        getchar();        
    } while (option != -1);
    return 0;
}