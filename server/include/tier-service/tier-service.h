#pragma once
#include <string>

class TireService {
public:
    TireService(std::string id, std::string title, double price,
                int durationMinutes, int slotsTotal);

    const std::string& id()    const noexcept { return id_; }
    const std::string& title() const noexcept { return title_; }
    double price()             const noexcept { return price_; }
    int durationMinutes()      const noexcept { return durationMinutes_; }
    int slotsTotal()           const noexcept { return slotsTotal_; }
    int slotsAvailable()       const noexcept { return slotsAvailable_; }

    bool bookSlot();     // false, если свободных слотов нет
    void releaseSlot();  // исключение, если все слоты уже свободны
    std::string describe() const;

private:
    void validate() const;

    std::string id_;
    std::string title_;
    double price_ = 0.0;
    int durationMinutes_ = 0;
    int slotsTotal_ = 0;
    int slotsAvailable_ = 0;
};