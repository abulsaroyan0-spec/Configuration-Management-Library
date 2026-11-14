#pragma once

#include "PhysicalPublication.hpp"

class Book final : public PhysicalPublication {
public:
    Book(std::string id, std::string title, int year, std::string author = "Unknown");

    PublicationType getType() const noexcept override;
    std::string getTypeName() const override;
    void display(std::ostream& out) const override;

    const std::string& getAuthor() const noexcept;

private:
    std::string author_;
};
