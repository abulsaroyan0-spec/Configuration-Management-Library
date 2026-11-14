#include "PublicationFactory.hpp"

#include "Book.hpp"
#include "DigitalBook.hpp"
#include "Magazine.hpp"

#include <stdexcept>

PublicationFactory::PublicationFactory() {
    registerType("Book", [](const std::string& id, const std::string& title,
                            int year, const std::vector<std::string>& extra) {
        const std::string author = extra.empty() ? "Unknown" : extra.at(0);
        return std::make_unique<Book>(id, title, year, author);
    });

    registerType("Magazine", [](const std::string& id, const std::string& title,
                                int year, const std::vector<std::string>& extra) {
        const int issue = extra.empty() ? 1 : std::stoi(extra.at(0));
        return std::make_unique<Magazine>(id, title, year, issue);
    });

    registerType("DigitalBook", [](const std::string& id, const std::string& title,
                                   int year, const std::vector<std::string>&) {
        return std::make_unique<DigitalBook>(id, title, year);
    });
}

std::unique_ptr<Publication> PublicationFactory::create(
    const std::string& type, const std::string& id,
    const std::string& title, int year,
    const std::vector<std::string>& extra) const {
    const auto it = creators_.find(type);
    if (it == creators_.end()) {
        throw std::invalid_argument("Unknown publication type: " + type);
    }
    return it->second(id, title, year, extra);
}

void PublicationFactory::registerType(const std::string& type, Creator creator) {
    if (type.empty() || !creator) {
        throw std::invalid_argument("Invalid factory registration.");
    }
    creators_[type] = std::move(creator);
}
