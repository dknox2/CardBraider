#ifndef BASEBALLCARDNODE_H
#define BASEBALLCARDNODE_H

#include "BaseballCard.h"

namespace model
{

/// Node for a BaseballCardBraidedList that stores a BaseballCard and next pointers for the name, year, and condition braids.
class BaseballCardNode
{
    BaseballCard card;

    BaseballCardNode* nextName;
    BaseballCardNode* nextYear;
    BaseballCardNode* nextCondition;

public:

    /// Instantiates a new BaseballCardNode with the given card data.
    ///
    /// @param card the card to store data for
    ///
    /// @pre none
    /// @post getNextName() == nullptr && getNextYear() == nullptr && getNextCondition() == nullptr
    BaseballCardNode(const BaseballCard& card);

    /// Default virtual destructor for BaseballCardNode
    virtual ~BaseballCardNode();

    /// Returns the pointer to the next node on the name braid.
    ///
    /// @pre none
    /// @post none
    ///
    /// @return the pointer to the next node on the name braid
    BaseballCardNode* getNextName() const;

    /// Sets the pointer to the next node on the name braid to the given node.
    ///
    /// @param node the node to set the next name pointer to
    ///
    /// @pre none
    /// @post getNextName() == node
    void setNextName(BaseballCardNode* node);

    /// Returns the pointer to the next node on the year braid.
    ///
    /// @pre none
    /// @post none
    ///
    /// @return the pointer to the next node on the year braid
    BaseballCardNode* getNextYear() const;

    /// Sets the pointer to the next node on the year braid to the given node.
    ///
    /// @param node the node to set the next year pointer to
    ///
    /// @pre none
    /// @post getNextYear() == node
    void setNextYear(BaseballCardNode* node);

    /// Returns the pointer to the next node on the condition braid.
    ///
    /// @pre none
    /// @post none
    ///
    /// @return the pointer to the next node on the condition braid
    BaseballCardNode* getNextCondition() const;


    /// Sets the pointer to the next node on the condition braid to the given node.
    ///
    /// @param node the node to set the next condition pointer to
    ///
    /// @pre none
    /// @post getNextCondition() == node
    void setNextCondition(BaseballCardNode* condition);

    /// Gets the BaseballCard data stored by this node.
    ///
    /// @pre none
    /// @post none
    ///
    /// @return the BaseballCard data stored by this node
    BaseballCard getCard() const;
};
}


#endif // BASEBALLCARDNODE_H
