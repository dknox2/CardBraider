#ifndef LISTTRAVERSALFORMATTER_H
#define LISTTRAVERSALFORMATTER_H

#include <string>
#include <vector>

#include "BaseballCard.h"

using namespace model;

namespace view
{

class ListTraversalFormatter
{
    const string formatCard(const BaseballCard& card) const;

    public:
        ListTraversalFormatter();
        virtual ~ListTraversalFormatter();

    const string formatTraversal(const vector<BaseballCard>& traversal) const;
};
}


#endif // LISTTRAVERSALFORMATTER_H
