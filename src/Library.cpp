#include "Library.hpp"

#include <algorithm>
#include <stdexcept>

void Library::add(std::unique_ptr<Publication> publication) {
    if (!publication) {
        throw std::invalid_argument("Cannot add a null publication.");
    }

    const auto duplicate = std::find_if(
        publications_.begin(), publications_.end(),
        [&publication](const auto& current) {
            return current->getId() == publication->getId();
        });

    if (duplicate != publications_.end()) {
        throw std::logic_error("A publication with this ID already exists.");
    }

    publications_.push_back(std::move(publication));
}

void Library::remove(const std::string& id) {
    const auto it = std::find_if(
        publications_.begin(), publications_.end(),
        [&id](const auto& publication) {
            return publication->getId() == id;
        });

    if (it == publications_.end()) {
        throw std::out_of_range("Publication not found.");
    }

    publications_.erase(it);
}

const Publication& Library::find(const std::string& id) const {
    for (const auto& publication : publications_) {
        if (publication->getId() == id) {
            return *publication;
        }
    }
    throw std::out_of_range("Publication not found.");
}

Publication& Library::find(const std::string& id) {
    for (const auto& publication : publications_) {
        if (publication->getId() == id) {
            return *publication;
        }
    }
    throw std::out_of_range("Publication not found.");
}

std::vector<const Publication*> Library::getAll() const {
    std::vector<const Publication*> result;
    result.reserve(publications_.size());

    for (const auto& publication : publications_) {
        result.push_back(publication.get());
    }
    return result;
}

std::vector<const Publication*> Library::search(
    const SearchStrategy& strategy, const std::string& query) const {
    return strategy.search(publications_, query);
}

LibraryStatistics Library::getStatistics() const {
    LibraryStatistics stats;
    stats.total = publications_.size();

    for (const auto& publication : publications_) {
        switch (publication->getType()) {
            case PublicationType::Book:
                ++stats.books;
                break;
            case PublicationType::Magazine:
                ++stats.magazines;
                break;
            case PublicationType::DigitalBook:
                ++stats.digitalBooks;
                break;
        }

        if (publication->getType() != PublicationType::DigitalBook) {
            if (publication->isAvailable()) {
                ++stats.availablePhysical;
            } else {
                ++stats.borrowedPhysical;
            }
        }
    }

    return stats;
}
