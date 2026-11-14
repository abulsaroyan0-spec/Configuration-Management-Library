#pragma once

#include <iostream>
#include <string>

enum class PublicationType {
    Book,
    Magazine,
    DigitalBook
};

class Publication {
public:
    Publication(std::string id, std::string title, int year);
    virtual ~Publication() = default;

    Publication(const Publication&) = default;
    Publication& operator=(const Publication&) = default;

    const std::string& getId() const noexcept;
    const std::string& getTitle() const noexcept;
    int getYear() const noexcept;

    virtual PublicationType getType() const noexcept = 0;
    virtual std::string getTypeName() const = 0;
    virtual bool isAvailable() const noexcept = 0;
    virtual void borrow() = 0;
    virtual void giveBack() = 0;
    virtual void display(std::ostream& out) const;

private:
    std::string id_;
    std::string title_;
    int year_;
};

std::ostream& operator<<(std::ostream& out, const Publication& publication);
