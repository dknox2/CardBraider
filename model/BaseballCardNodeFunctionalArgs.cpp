#include "BaseballCardNodeFunctionalArgs.h"

#include <iostream>

using namespace std;

namespace model
{

BaseballCardNode* BaseballCardNodeFunctionalArgs::getNextName(const BaseballCardNode* node)
{
    return node->getNextName();
}

void BaseballCardNodeFunctionalArgs::setNextName(BaseballCardNode* node, BaseballCardNode* toSet)
{
    node->setNextName(toSet);
}

bool BaseballCardNodeFunctionalArgs::compareByName(const BaseballCard& card0, const BaseballCard& card1)
{
    string card0Name = card0.getLastName() + card0.getFirstName();
    string card1Name = card1.getLastName() + card1.getFirstName();

    return card0Name <= card1Name;
}

BaseballCardNode* BaseballCardNodeFunctionalArgs::getNextYear(const BaseballCardNode* node)
{
    return node->getNextYear();
}

void BaseballCardNodeFunctionalArgs::setNextYear(BaseballCardNode* node, BaseballCardNode* toSet)
{
    node->setNextYear(toSet);
}

bool BaseballCardNodeFunctionalArgs::compareByYear(const BaseballCard& card0, const BaseballCard& card1)
{
    return card0.getYear() <= card1.getYear();
}

BaseballCardNode* BaseballCardNodeFunctionalArgs::getNextCondition(const BaseballCardNode* node)
{
    return node->getNextCondition();
}

void BaseballCardNodeFunctionalArgs::setNextCondition(BaseballCardNode* node, BaseballCardNode* toSet)
{
    node->setNextCondition(toSet);
}

bool BaseballCardNodeFunctionalArgs::compareByCondition(const BaseballCard& card0, const BaseballCard& card1)
{
    BaseballCardCondition condition0 = card0.getCondition();
    BaseballCardCondition condition1 = card1.getCondition();

    if (condition0 == condition1)
    {
        return compareByName(card0, card1);
    }

    return condition0 < condition1;
}

}
