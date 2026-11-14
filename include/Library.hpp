#pragma once

#include "Publication.hpp"
#include "SearchStrategy.hpp"

#include <cstddef>
#include <memory>
#include <string>
#include <vector>

struct LibraryStatistics {
    std::size_t total = 0;
    std::size_t books = 0;
    std::size_t magazines = 0;
    std::size_t digitalBooks = 0;
    std::size_t availablePhysical = 0;
    std::size_t borrowedPhysical = 0;
};

class Library {
public:
    void add(std::unique_ptr<Publication> publication);
    void remove(const std::string& id);
    const Publication& find(const std::string& id) const;
    Publication& find(const std::string& id);

    std::vector<const Publication*> getAll() const;
    std::vector<const Publication*> search(const SearchStrategy& strategy,
                                           const std::string& query) const;
    LibraryStatistics getStatistics() const;

private:
    std::vector<std::unique_ptr<Publication>> publications_;
};
