#include "../include/tier-service/tier-service.h"
#include <iostream>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#endif

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    std::vector<TireService> services;
    services.emplace_back("srv-1", "Сезонная замена шин R15-R17", 60.0, 40, 4);
    services.emplace_back("srv-2", "Сезонная замена шин R18+", 80.0, 50, 3);
    services.emplace_back("srv-3", "Балансировка 4 колёс", 30.0, 25, 5);
    services.emplace_back("srv-4", "Ремонт прокола жгутом", 20.0, 15, 6);
    services.emplace_back("srv-5", "Правка литого диска", 50.0, 45, 2);

    for (const auto& s : services)
        std::cout << s.describe() << '\n';

    std::cout << "\nЗапись на слот: "
              << (services[0].bookSlot() ? "успешно" : "нет свободных слотов")
              << '\n';
    std::cout << services[0].describe() << '\n';

    try {
        TireService invalid("", "Без ID", 50.0, 30, 1);
    } catch (const std::invalid_argument& e) {
        std::cout << "Ожидаемая ошибка: " << e.what() << '\n';
    }

    return 0;
}
