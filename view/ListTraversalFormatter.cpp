#include <iomanip>
#include <sstream>

#include "ListTraversalFormatter.h"

namespace view
{

ListTraversalFormatter::ListTraversalFormatter()
{
}

ListTraversalFormatter::~ListTraversalFormatter()
{
}

string ListTraversalFormatter::formatPrice(int price) const
{
    stringstream stream;

    stream.imbue(locale(""));
    stream << showbase << put_money(price * 100);

    return stream.str();
}

string ListTraversalFormatter::formatCard(const BaseballCard& card) const
{
    stringstream stream;

    stream << left << setw(16) << (card.getFirstName() + " " + card.getLastName())
           << left << setw(8) << card.getYear()
           << left << setw(8) << card.getCondition()
           << right << setw(16) << this->formatPrice(card.getPrice()) << endl;

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
