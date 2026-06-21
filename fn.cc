#include "fn.h"

crow::mustache::context generateUserContext(const std::string& name) {
    crow::json::wvalue ctx;

    ctx["unit"] = name;

    if (name == "Admin" || name == "admin") {
        ctx["message"] = "Режим администратора. Доступ разрешен.";
        ctx["status_class"] = "admin-mode";
    } 
    else if (name == "Banned" || name == "banned") {
        ctx["message"] = "Внимание: Ваш аккаунт заблокирован!";
        ctx["status_class"] = "error";
    } 
    else {
        ctx["message"] = "Приветствуем в тестовой зоне Grape Space!";
        ctx["status_class"] = "user-mode";
    }

    return ctx;
}
