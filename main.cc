#include <crow.h>
#include <string>
#include "fn.h"

int main() {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/<string>")([](std::string name){
        auto page = crow::mustache::load("index.html");
        crow::mustache::context ctx = generateUserContext(name);
        return page.render(ctx);
    });

    app.port(18080)
        .multithreaded()
        .run();

    return 0;
}
