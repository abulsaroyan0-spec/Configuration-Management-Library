#include "SearchStrategy.hpp"

#include <algorithm>
#include <stdexcept>

std::vector<const Publication*> SearchByTitle::search(
    const std::vector<std::unique_ptr<Publication>>& publications,
    const std::string& query) const {
    std::vector<const Publication*> results;

    for (const auto& publication : publications) {
        if (publication->getTitle().find(query) != std::string::npos) {
            results.push_back(publication.get());
        }
    }
    return results;
}

std::vector<const Publication*> SearchByYear::search(
    const std::vector<std::unique_ptr<Publication>>& publications,
    const std::string& query) const {
    std::vector<const Publication*> results;
    std::size_t processed = 0;
    int year = 0;

    try {
        year = std::stoi(query, &processed);
    } catch (const std::exception&) {
        throw std::invalid_argument("Search year must be a valid integer.");
    }

    if (processed != query.size()) {
        throw std::invalid_argument("Search year must contain digits only.");
    }

    for (const auto& publication : publications) {
        if (publication->getYear() == year) {
            results.push_back(publication.get());
        }
    }
    return results;
}
