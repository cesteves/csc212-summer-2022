#pragma once

#include "Item.hpp"

class Grenade : public Item
{

    private:


    public:
        Grenade();
        void activate(Entity* target);
};