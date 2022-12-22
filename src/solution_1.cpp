#include <iostream>
#include <cpr/cpr.h>
#include "use_lib.h"
using namespace std;

void solution_1() {
    setlocaleRus();

    cout << "\n**************** SOLUTION #1 ******************\n" << endl;

    string comm;
    do {
        clearStdin();
        cout << "\nENTER command (get, post, delete, patch, put, exit): ";
        comm = getCommand();
        if (comm == "get")
        {
            // получение данных - secure
            cpr::Response response = cpr::Get
                    (
                    cpr::Url{"https://httpbin.org/get"},
                    cpr::Parameters{{"id","100"},{"name","Zorro"}}
                    );
            cout << "RESPONSE STATUS: " << response.status_code << endl;
            cout << response.text << endl;
        } else if (comm == "post") {
            // добавление данных - non secure
            c
//            cpr::Response response = cpr::Post
//                    (
//                    cpr::Url{"https://httpbin.org/post"},
//                    cpr::Parameters{{"hello","world"}},
//                    cpr::Payload{{"name", "Chilly Palmer"},{"city", "Los Angeles"}},
//                    cpr::Header{{"user-agent", "Mozilla/5.0 (Windows NT 10.0; rv:108.0) Gecko/20100101 Firefox/108.0"}}
//                    );
//            cout << "RESPONSE STATUS: " << response.status_code << endl;
            cout << response.text << endl;
        }



    } while (comm != "exit");

}
