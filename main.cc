#include <crow.h>
#include <string>
#include "fn.h"

int main() {
    crow::App<> app;
    app.loglevel(crow::LogLevel::Warning);

    CROW_ROUTE(app, "/string/<string>")
    ([](const std::string& name){
        auto page = crow::mustache::load("index.html");
        crow::mustache::context ctx = generateUserContext(name);
        return page.render(ctx);
    });

    app.port(18080);
    app.multithreaded();
    app.run();
}
