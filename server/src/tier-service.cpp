#include "../include/tier-service/tier-service.h"
#include <sstream>
#include <stdexcept>
#include <utility>

TireService::TireService(std::string id, std::string title, double price,
                         int durationMinutes, int slotsTotal)
    : id_(std::move(id)),
      title_(std::move(title)),
      price_(price),
      durationMinutes_(durationMinutes),
      slotsTotal_(slotsTotal),
      slotsAvailable_(slotsTotal) {
    validate();
}

void TireService::validate() const {
    if (id_.empty())
        throw std::invalid_argument("ID услуги не задан");
    if (title_.empty())
        throw std::invalid_argument("Название услуги не задано");
    if (price_ <= 0.0)
        throw std::invalid_argument("Цена должна быть больше 0");
    if (durationMinutes_ < 5 || durationMinutes_ > 480)
        throw std::invalid_argument("Длительность должна быть от 5 до 480 минут");
    if (slotsTotal_ < 1)
        throw std::invalid_argument("Количество слотов должно быть не меньше 1");
}

bool TireService::bookSlot() {
    if (slotsAvailable_ == 0) return false;
    --slotsAvailable_;
    return true;
}

void TireService::releaseSlot() {
    if (slotsAvailable_ == slotsTotal_)
        throw std::logic_error("Все слоты по этой услуге уже свободны");
    ++slotsAvailable_;
}

std::string TireService::describe() const {
    std::ostringstream out;
    out << title_ << " — " << price_ << " руб., "
        << durationMinutes_ << " мин. (свободно слотов: "
        << slotsAvailable_ << " из " << slotsTotal_ << ")";
    return out.str();
}