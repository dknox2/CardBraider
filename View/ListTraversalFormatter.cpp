#include <iomanip>
#include <sstream>

#include "ListTraversalFormatter.h"

namespace view
{

ListTraversalFormatter::ListTraversalFormatter()
{
    //ctor
}

ListTraversalFormatter::~ListTraversalFormatter()
{
    //dtor
}

const string ListTraversalFormatter::formatCard(const BaseballCard& card) const
{
    stringstream stream;

    stream << left << setw(16) << (card.getFirstName() + " " + card.getLastName())
           << left << setw(8) << card.getYear()
           << left << setw(8) << card.getCondition()
           << right << setw(16) << card.getPrice() << endl;

    return stream.str();
}

const string ListTraversalFormatter::formatTraversal(const vector<BaseballCard>& traversal) const
{
    stringstream stream;

    for (auto& card : traversal)
    {
        stream << this->formatCard(card);
    }

    return stream.str();
}
}
