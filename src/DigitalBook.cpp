#include "DigitalBook.hpp"

#include <stdexcept>

PublicationType DigitalBook::getType() const noexcept {
    return PublicationType::DigitalBook;
}

std::string DigitalBook::getTypeName() const {
    return "DigitalBook";
}

bool DigitalBook::isAvailable() const noexcept {
    return true;
}

void DigitalBook::borrow() {
    throw std::logic_error("Digital publications cannot be borrowed.");
}

void DigitalBook::giveBack() {
    throw std::logic_error("Digital publications cannot be returned.");
}
