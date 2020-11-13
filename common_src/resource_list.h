#ifndef RESOURCE_LIST_H
#define RESOURCE_LIST_H

#include <string>
#include <map>

class ResourceList {
public:
    ResourceList();

    void operator()(std::string name, std::string content);

    std::string operator()(std::string name);

    ~ResourceList();

private:
    std::map <std::string, std::string> resources;
};

#endif //RESOURCE_LIST_H
