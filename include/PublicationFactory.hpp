#pragma once

#include "Publication.hpp"

#include <functional>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

class PublicationFactory {
public:
    using Creator = std::function<std::unique_ptr<Publication>(
        const std::string&, const std::string&, int, const std::vector<std::string>&)>;

    PublicationFactory();

    std::unique_ptr<Publication> create(
        const std::string& type,
        const std::string& id,
        const std::string& title,
        int year,
        const std::vector<std::string>& extra = {}) const;

    void registerType(const std::string& type, Creator creator);

private:
    std::unordered_map<std::string, Creator> creators_;
};
