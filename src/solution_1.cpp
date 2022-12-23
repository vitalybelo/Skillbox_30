#include <iostream>
#include <cpr/cpr.h>
#include "use_lib.h"
using namespace std;

/**
 * Задание №1
 * Реализованы HTTP запросы: GET, POST, PUT, PATCH, DELETE
 */
void solution_1() {

    cout << "\n**************** SOLUTION #1 ******************\n" << endl;

    string comm;
    do {
        clearStdin();
        cout << "\nENTER command (get, post, delete, patch, put, exit): ";
        comm = getCommand();
        if (comm == "get") // ********** GET
        {
            cpr::Response response = cpr::Get
                    (
                    cpr::Url{"https://httpbin.org/get"},
                    cpr::Parameters{{"id","100"},{"name","Sita"}}
                    );
            cout << "\nRESPONSE STATUS: " << response.status_code << endl;
            cout << response.text << endl;
        }
        else if (comm == "post") // ******** POST
        {
            cpr::Response response = cpr::Post
                    (
                    cpr::Url{"https://httpbin.org/post"},
                    cpr::Payload{{"name", "Palmer"},{"age", "55"}}
                    );
            cout << "\nRESPONSE STATUS: " << response.status_code << endl;
            cout << response.text << endl;
        }
        else if (comm == "put") // *********** PUT
        {
            cpr::Response response = cpr::Put
                    (
                    cpr::Url{"https://httpbin.org/put"},
                    cpr::Payload{{"name", "Zuckerman"}, {"skill", "Senior"}}
                    );
            cout << "\nRESPONSE STATUS: " << response.status_code << endl;
            cout << response.text << endl;
        }
        else if (comm == "patch") // ********** PATCH
        {
            cpr::Response response = cpr::Patch
                    (
                    cpr::Url{"https://httpbin.org/patch"},
                    cpr::Payload{{"name", "Zuckerman"}, {"skill", "TeamLeader"}}
                    );
            cout << "\nRESPONSE STATUS: " << response.status_code << endl;
            cout << response.text << endl;
        }
        else if (comm == "delete")
        {
            cpr::Response response = cpr::Delete
                    (
                    cpr::Url{"https://httpbin.org/delete"},
                    cpr::Parameters{{"id", "100"}}
                    );
            cout << "\nRESPONSE STATUS: " << response.status_code << endl;
            cout << response.text << endl;
        }

    } while (comm != "exit");

}
