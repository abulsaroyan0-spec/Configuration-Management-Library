#include "Publication.hpp"

#include <stdexcept>
#include <utility>

Publication::Publication(std::string id, std::string title, int year)
    : id_(std::move(id)), title_(std::move(title)), year_(year) {
    if (id_.empty()) {
        throw std::invalid_argument("Publication ID cannot be empty.");
    }
    if (title_.empty()) {
        throw std::invalid_argument("Publication title cannot be empty.");
    }
    if (year_ <= 0) {
        throw std::invalid_argument("Publication year must be positive.");
    }
}

const std::string& Publication::getId() const noexcept { return id_; }
const std::string& Publication::getTitle() const noexcept { return title_; }
int Publication::getYear() const noexcept { return year_; }

void Publication::display(std::ostream& out) const {
    out << getId() << " | " << getTitle() << " | " << getYear()
        << " | " << getTypeName()
        << " | " << (isAvailable() ? "Available" : "Borrowed");
}

std::ostream& operator<<(std::ostream& out, const Publication& publication) {
    publication.display(out);
    return out;
}
