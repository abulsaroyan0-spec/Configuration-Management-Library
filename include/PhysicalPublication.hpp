#pragma once

#include "Publication.hpp"

class PhysicalPublication : public Publication {
public:
    using Publication::Publication;

    bool isAvailable() const noexcept override;
    void borrow() override;
    void giveBack() override;

private:
    bool available_ = true;
};
