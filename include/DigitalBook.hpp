#pragma once

#include "Publication.hpp"

class DigitalBook final : public Publication {
public:
    using Publication::Publication;

    PublicationType getType() const noexcept override;
    std::string getTypeName() const override;
    bool isAvailable() const noexcept override;
    void borrow() override;
    void giveBack() override;
};
