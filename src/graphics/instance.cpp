
#include "instance.hpp"

Instance::Instance()
{
    createInstance();
}


Instance::~Instance()
{
}


VkInstance Instance::getInstance()
{
    return instance;
}

void Instance::createInstance()
{
}
