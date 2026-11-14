#pragma once

#include "PhysicalPublication.hpp"

class Magazine final : public PhysicalPublication {
public:
    Magazine(std::string id, std::string title, int year, int issueNumber = 1);

    PublicationType getType() const noexcept override;
    std::string getTypeName() const override;
    void display(std::ostream& out) const override;

    int getIssueNumber() const noexcept;

private:
    int issueNumber_;
};
