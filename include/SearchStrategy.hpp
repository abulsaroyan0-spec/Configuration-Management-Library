#pragma once

#include "Publication.hpp"

#include <memory>
#include <string>
#include <vector>

class SearchStrategy {
public:
    virtual ~SearchStrategy() = default;

    virtual std::vector<const Publication*> search(
        const std::vector<std::unique_ptr<Publication>>& publications,
        const std::string& query) const = 0;
};

class SearchByTitle final : public SearchStrategy {
public:
    std::vector<const Publication*> search(
        const std::vector<std::unique_ptr<Publication>>& publications,
        const std::string& query) const override;
};

class SearchByYear final : public SearchStrategy {
public:
    std::vector<const Publication*> search(
        const std::vector<std::unique_ptr<Publication>>& publications,
        const std::string& query) const override;
};
