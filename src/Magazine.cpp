#include "Magazine.hpp"

#include <stdexcept>

Magazine::Magazine(std::string id, std::string title, int year, int issueNumber)
    : PhysicalPublication(std::move(id), std::move(title), year),
      issueNumber_(issueNumber) {
    if (issueNumber_ <= 0) {
        throw std::invalid_argument("Magazine issue number must be positive.");
    }
}

PublicationType Magazine::getType() const noexcept { return PublicationType::Magazine; }
std::string Magazine::getTypeName() const { return "Magazine"; }
int Magazine::getIssueNumber() const noexcept { return issueNumber_; }

void Magazine::display(std::ostream& out) const {
    Publication::display(out);
    out << " | Issue: " << issueNumber_;
}
