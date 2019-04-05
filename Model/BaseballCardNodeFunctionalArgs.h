#ifndef BASEBALLCARDNODEFUNCTIONALARGS_H
#define BASEBALLCARDNODEFUNCTIONALARGS_H

#include "BaseballCardNode.h"

namespace model
{

/// Function pointer that calls and returns the getter for the given BaseballCardNode.
typedef BaseballCardNode* (*BaseballCardNodeGetter)(const BaseballCardNode*);

/// Function pointer that calls the setter for a next node on the first card, setting it to the second card.
typedef void (*BaseballCardNodeSetter)(BaseballCardNode*, BaseballCardNode*);

/// Function pointer that compares two given BaseballCards, and returns true if the first card is less than or equal to the second card.
typedef bool (*BaseballCardCompare)(const BaseballCard&, const BaseballCard&);

/// Class that holds static function pointers to be used in insertions, deletions, and traversals in the BaseballCardBraidedList class to allow for code reuse.
class BaseballCardNodeFunctionalArgs
{
public:

    /// Returns the pointer to the next node on the name braid of the given node.
    ///
    /// @param node the node to obtain the next node from
    ///
    /// @pre none
    /// @post none
    ///
    /// @return the pointer to the next node on the name braid of the given node
    static BaseballCardNode* getNextName(const BaseballCardNode* node);

    /// Sets the next node on the name braid of the first card to the second card.
    ///
    /// @param node the node to set the next node of
    /// @param toSet the node to which node will be pointing
    ///
    /// @pre none
    /// @post node->getNextName() == toSet
    static void setNextName(BaseballCardNode* node, BaseballCardNode* toSet);

    /// Returns true if card0's name is less than or equal to card1's name, lexicographically by last name, then first name.
    /// False otherwise.
    ///
    /// @param card0 the first card to compare
    /// @param card1 the card to compare to
    ///
    /// @return true if card0's name is less than or equal to card1's name, lexicographically by last name, then first name
    static bool compareByName(const BaseballCard& card0, const BaseballCard& card1);

    /// Returns the pointer to the next node on the year braid of the given node.
    ///
    /// @param node the node to obtain the next node from
    ///
    /// @pre none
    /// @post none
    ///
    /// @return the pointer to the next node on the year braid of the given node
    static BaseballCardNode* getNextYear(const BaseballCardNode* node);

    /// Sets the next node on the year braid of the first card to the second card.
    ///
    /// @param node the node to set the next node of
    /// @param toSet the node to which node will be pointing
    ///
    /// @pre none
    /// @post node->getNextYear() == toSet
    static void setNextYear(BaseballCardNode* node, BaseballCardNode* toSet);

    /// Returns true if card0's year of printing is less than or equal to card1.
    /// False otherwise.
    ///
    /// @param card0 the first card to compare
    /// @param card1 the card to compare to
    ///
    /// @return true if card0's year of printing is less than or equal to card1, false otherwise
    static bool compareByYear(const BaseballCard& card0, const BaseballCard& card1);
};
}


#endif // BASEBALLCARDNODEFUNCTIONALARGS_H
