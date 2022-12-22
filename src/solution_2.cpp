#include <iostream>
#include <cpr/cpr.h>
#include "use_lib.h"
using namespace std;

void solution_2() {

    cpr::Response response = cpr::Head(cpr::Url{"https://www.httpbin.org/get"});

    cout << response.text << endl;

}
