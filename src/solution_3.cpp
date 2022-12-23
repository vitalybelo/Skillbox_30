#include <cpr/cpr.h>
#include <iostream>
#include <vector>
#include <random>
#include "use_lib.h"
using namespace std;

static void displayHelp();
static cpr::Response mappingGet();
static cpr::Response mappingPost();
static vector<cpr::Pair> generatePairs(bool genId);
static void displayResponse(const cpr::Response& response);

void solution_3()
{
    setlocaleRus();
    setlocale1251();
    cout << "\n**************** SOLUTION #3 ******************\n" << endl;

    string comm;
    displayHelp();
    do {
        clearStdin();
        cout << "¬ведите команду: ";
        comm = getCommand();
        if (comm == "?" || comm == "help") {
            displayHelp();
        } else if (comm == "post") {
            cpr::Response response = mappingPost();
            displayResponse(response);
        } else if (comm == "get") {
            cpr::Response response = mappingGet();
            displayResponse(response);
        }
    } while (comm != "exit");
}

static cpr::Response mappingGet()
{
    // данные дл€ генерации запроса
    vector<cpr::Pair> pairs = generatePairs(true);
    string url_string("https://www.httpbin.org/get");
    if (!pairs.empty()) {
        url_string += "?" + pairs.at(0).key + "=" + pairs.at(0).value;
    }
    for (int i = 1; i < pairs.size(); i++) {
        url_string += "&" + pairs.at(i).key + "=" + pairs.at(i).value;
    }
    cpr::Url url = cpr::Url(url_string);

    cpr::Session session;
    session.SetUrl(url);
    session.SetUserAgent("Mozilla/5.0 (Windows NT 10.0; rv:108.0) Gecko/20100101 Firefox/108.0");
    session.SetHeader({{"host","google.com"}});

    return session.Get();
}

static cpr::Response mappingPost()
{
    // данные дл€ генерации запроса
    vector<cpr::Pair> pairs = generatePairs(false);
    cpr::Payload payload = cpr::Payload(pairs.begin(), pairs.end());

    cpr::Session session;
    session.SetUrl("https://www.httpbin.org/post");
    session.SetUserAgent("Mozilla/5.0 (Windows NT 10.0; rv:108.0) Gecko/20100101 Firefox/108.0");
    session.SetHeader({{"host","google.com"}});
    session.SetPayload(payload);

    return session.Post();
}

static void displayResponse(const cpr::Response& response)
{
    cout << "Request code: " << response.status_code << endl;
    cout << "Request took: " << response.elapsed << " sec" << endl;
    cout << "Body:" << endl;
    cout << response.text << endl;
}

static void displayHelp()
{
    cout << "ƒанные в задании будут создаватьс€ автоматически из массива 8-ми сотрудников\n";
    cout << "јвтоматически будут выбиратьс€ имена, возраст, опыт и т.п., всего 5 параметров\n";
    cout << "ќбъем данных запроса также будет выбиратьс€ автоматически от 1 до 5 параметров\n";
    cout << "¬аш набор команд: post, get, exit\nѕогнали\n\n";
}

static vector<cpr::Pair> generatePairs(bool genId)
{
    vector<cpr::Pair> pairs; //{{"name", "Alex"}, {"age", "33"}};
    // данные дл€ генерации сотрудника: имена, возраст, опыт, зарплата, стаж работы
    string keys[5]{"name","age","test","salary","experience"};
    string args[5][8]
            {
                    {"Alex","Victor","Maria","David","Chilly","Andre","Piter", "Isaak"}, // имена
                    {"33","38","45","52","41","44","55","60"}, // возраст
                    {"Good","Nice","Middle","HiRes","Talent","Low","Best","OverGood"}, // опыт
                    {"75.000","95.000","134.000","148.000","87.000","96.000","120.000","78.000"}, // зарплата
                    {"12","2","15","7","10","9","22","18"} // стаж работы
            };
    // инициализаци€ генератора выбора
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> params_dist(1,5);
    uniform_int_distribution<> employ_dist(0,7);

    if (genId) {
        pairs.emplace_back("id", to_string(employ_dist(gen) + 1));
    }
    int n_params = params_dist(gen);
    for (int i = 0; i < n_params; i++) {
        pairs.emplace_back(keys[i],args[i][employ_dist(gen)]);
    }
    return pairs;
}
