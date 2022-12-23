#include <string>
#include <iostream>
#include <cpr/cpr.h>
using namespace std;

/**
 * Читаем страницу по адресу https://www.httpbin.org/html, находим заголовок и выводим в консоль
 */
void solution_2() {

    cout << "\n**************** SOLUTION #2 ******************\n" << endl;

    cpr::Response response = cpr::Get
            (
            cpr::Url{"https://www.httpbin.org/html"},
            cpr::Header{{"accept", "text/html"}}
            );
    //cout << response.text << endl;

    unsigned int start = response.text.find("<h1>",0) + 4;
    unsigned int finish = response.text.find("</h1>",start);
    string title = response.text.substr(start, finish - start);

    cout << "TITLE :: \"" << title << "\"" << endl;
}

