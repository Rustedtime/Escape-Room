#include "item.h"
#include "ostream"

// Default constructor
Item::Item()
{
    keyId = 0;
    description = "undefined_description";
    name = "undefined_item";
}

// Non-default constructor
Item::Item(int keyId, std::string name, std::string description)
{
    this->keyId = keyId;
    this->name = name;
    this->description = description;
}

// Use an item on a container
void Item::use(Container & target)
{
    target.unlock(keyId);
}

void Item::use()
{
    std::cout << "Nothing interesting happens.\n";
}

// Describe the object
void Item::look()
{
    std::cout << description << std::endl;
}