//
// Created by napbad on 9/26/24.
//

#ifndef HIERARCHY_H
#define HIERARCHY_H
#include <string>
#include <vector>

/**
 * @enum HierarchyType
 * @brief Enumerates different types of hierarchy nodes.
 */
enum class HierarchyType
{
    ROOT, //!< Root node
    PACKAGE, //!< Package or module
    FILE, //!< File
    FILE_CLASS, //!< Class within a file
    FILE_FUN, //!< Function within a file
    FILE_CLASS_FUN, //!< Function within a class
    FILE_CLASS_FUN_BLOCK, //!< Block within a function
    FILE_VAR //!< Variable within a file
};

/**
 * @class Hierarchy
 * @brief Represents a node in a hierarchical structure.
 */
class Hierarchy
{
    std::string _name; //!< Name of the hierarchy node
    HierarchyType _type; //!< Type of the hierarchy node
    Hierarchy* _parent; //!< Pointer to the parent node
    std::vector<Hierarchy*>* _children; //!< Vector of child nodes

public:
    /**
     * Constructs a new hierarchy node with a given class_name, type, and parent.
     *
     * This constructor initializes a new hierarchy node with the specified class_name, type, and parent node.
     * It also associates the node with a list of children nodes.
     *
     * @param name The name of the node.
     * @param type The type of the node.
     * @param parent The parent node.
     * @param children The list of children nodes associated with this node.
     */
    Hierarchy(std::string name, HierarchyType type, Hierarchy* parent, std::vector<Hierarchy*>* children);


    /**
     * @brief Adds a child node to this hierarchy node.
     *
     * @param hierarchy The child node to add.
     */
    void add_child(Hierarchy* hierarchy) const;


    /**
     * Find a child by class_name
     *
     * This function searches for the first matching child element using the provided class_name string within the current object's children.
     * If a matching child is found, it returns a pointer to that child; otherwise, it returns a null pointer.
     *
     * @param name The name of the child element to search for
     * @return A constant pointer to the found child element, or a null pointer if not found
     */
    [[nodiscard]] Hierarchy* find_child_by_name(const std::string& name) const;


    /**
     * Sets the parent hierarchy for the current object.
     *
     * This function is useful for establishing a parent-child relationship in data structures such as trees or scene graphs.
     *
     * @param hierarchy A pointer to the target parent hierarchy. This parameter allows the current object to be attached to another object, forming a hierarchical relationship.
     */
    void set_parent(Hierarchy* hierarchy);


    /**
     * @brief Merges a package hierarchy into the root hierarchy.
     *
     * @param root The root hierarchy globally.
     * @param package The package hierarchy to merge into the main hierarchy (root).
     *
     * @return The lowest hierarchy node of the package.
     */
    static Hierarchy* merge_hierarchy(Hierarchy* root, Hierarchy* package);

    /**
     * @brief Creates and returns the root hierarchy node.
     *
     * @return A pointer to the root hierarchy node.
     */
    static Hierarchy* root_hierarchy();

    /**
     * @brief Creates and returns a hierarchy node representing a file.
     *
     * @param file_name The name of the file.
     *
     * @return A pointer to the file hierarchy node.
     */
    static Hierarchy* file_hierarchy(const std::string& file_name);

    /**
     * @brief Adds a package hierarchy as a child node.
     *
     * @param value A vector of strings representing the package hierarchy.
     */
    void add_child_pkg_hierarchy(std::vector<std::string>& value);

    /**
     * @brief Returns a child node by index.
     *
     * @param i The index of the child node.
     *
     * @return A pointer to the child node.
     */
    [[nodiscard]] Hierarchy* get_child(int i) const;

    /**
     * @brief Returns the parent node.
     *
     * @return A pointer to the parent node.
     */
    [[nodiscard]] Hierarchy* parent() const;

    /**
     * @brief Returns the name of the node.
     *
     * @return The name of the node.
     */
    [[nodiscard]] std::string name() const;

    /**
     * @brief Returns the type of the node.
     *
     * @return The type of the node.
     */
    [[nodiscard]] HierarchyType type() const;

    /**
     * @brief Checks if a child node exists.
     *
     * @param hierarchy The child node to check for existence.
     *
     * @return True if the child node exists, false otherwise.
     */
    [[nodiscard]] bool exist_child(const Hierarchy* hierarchy) const;
};

#endif //HIERARCHY_H
