#include <string>
#include <map>
#include <utility>
#include "resource_list.h"

ResourceList::ResourceList() {}

void ResourceList::operator()(std::string name, std::string content) {
    this->resources.insert(std::pair<std::string, std::string>(name, content));
}

std::string ResourceList::operator()(std::string name) {
    std::map<std::string, std::string>::iterator resource =
            this->resources.find(name);
    if (resource == this->resources.end())
        return "";
    return resource->second;
}

ResourceList::~ResourceList() {}
