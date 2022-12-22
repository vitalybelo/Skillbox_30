#include <iostream>
#include <cpr/cpr.h>
#include "use_lib.h"
using namespace std;

int solution_1() {
    setlocaleRus();

    cout << "\n**************** SOLUTION #1 ******************\n\n" << endl;

    string comm;
    do {
        clearStdin();
        cout << "ENTER command (get, post, delete, patch, put, exit): ";
        comm = getCommand();

    } while (comm != "exit");

    //cpr::Response response = cpr::Get();



    return 0;
}
