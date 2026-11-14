#include "PhysicalPublication.hpp"

#include <stdexcept>

bool PhysicalPublication::isAvailable() const noexcept {
    return available_;
}

void PhysicalPublication::borrow() {
    if (!available_) {
        throw std::logic_error("Publication is already borrowed.");
    }
    available_ = false;
}

void PhysicalPublication::giveBack() {
    if (available_) {
        throw std::logic_error("Publication has not been borrowed.");
    }
    available_ = true;
}
