#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include <iostream>
using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

void handle_get(http_request request) {
    request.reply(status_codes::OK, U("Received GET Request"));
}

int main() {
    http_listener listner(U("http://localhost:8082"));
    listner.support(methods::GET, handle_get);

    try {
        listner.open()
            .then([&listner]() {std::cout<<"Starting server";})
            .wait();
        while(true);
    } catch(std::exception const& e) {
        std::cerr<<"Error: "<<e.what()<<std::endl; 
    }
    return 0;
}