#ifndef RESOURCE_LIST_H
#define RESOURCE_LIST_H

#include <string>
#include <map>

/**
 * The resource list.
 * Handles the files in each resource.
 */
class ResourceList {
public:
    /**
     * Creates the resource list.
     */
    ResourceList();

    /**
     * Adds the content in the resource with name @name
     * @param name: the resource name
     * @param content: the content to add
     */
    void operator()(const std::string &name, const std::string &content);

    /**
     * Returns the resource contained in @name
     * @param name: the resource name
     * @return the content in resource (empty string if non existing)
     */
    std::string operator()(const std::string &name);

    /**
     * Resource list destructor.
     */
    ~ResourceList();

private:
    std::map <std::string, std::string> resources;
};

#endif //RESOURCE_LIST_H
