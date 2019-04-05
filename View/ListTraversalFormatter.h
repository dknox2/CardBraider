#ifndef LISTTRAVERSALFORMATTER_H
#define LISTTRAVERSALFORMATTER_H

#include <string>
#include <vector>

#include "BaseballCard.h"

using namespace model;

namespace view
{

/// Formats braided list traversals for display in the UI.
class ListTraversalFormatter
{
    const string formatCard(const BaseballCard& card) const;

public:
    /// Instantiates a new ListTraversalFormatter.
    ///
    /// @pre none
    /// @post none
    ListTraversalFormatter();

    /// Default virtual destructor for the ListTraversalFormatter class.
    virtual ~ListTraversalFormatter();

    /// Formats the given collection of BaseballCards for display.
    ///
    /// @pre none
    /// @post none
    ///
    /// @return a formatted string representation of the collection of BaseballCards
    const string formatTraversal(const vector<BaseballCard>& traversal) const;
};
}


#endif // LISTTRAVERSALFORMATTER_H
