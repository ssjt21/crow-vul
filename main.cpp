#define CROW_MAIN
//#define CROW_STATIC_DIRECTORY "static/"
//#define CROW_STATIC_ENDPOINT "/tmp/static"
//#define CROW_DISABLE_STATIC_DIR
#include <iostream>
#include "crow.h"
//g++ main.cpp -o main -lboost_system -lboost_filesystem -lpthread
int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([](){
        return "Hello world are you ok ";
    });
        CROW_ROUTE(app, "/index")([](const crow::request& req){ 
        crow::mustache::context x; 
        x["src"] = req.url_params.get("src"); 
        auto page = crow::mustache::load("index.html"); 
        return page.render(x); 
    });	

    app.port(18080).multithreaded().run();
}


