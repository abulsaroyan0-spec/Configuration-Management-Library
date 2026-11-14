#include "Book.hpp"

#include <utility>

Book::Book(std::string id, std::string title, int year, std::string author)
    : PhysicalPublication(std::move(id), std::move(title), year),
      author_(std::move(author)) {}

PublicationType Book::getType() const noexcept { return PublicationType::Book; }
std::string Book::getTypeName() const { return "Book"; }
const std::string& Book::getAuthor() const noexcept { return author_; }

void Book::display(std::ostream& out) const {
    Publication::display(out);
    out << " | Author: " << author_;
}
