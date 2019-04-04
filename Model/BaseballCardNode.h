#ifndef BASEBALLCARDNODE_H
#define BASEBALLCARDNODE_H

#include "BaseballCard.h"

namespace model
{

class BaseballCardNode
{
    BaseballCard card;

    BaseballCardNode* nextName;
    BaseballCardNode* nextYear;

public:
    BaseballCardNode(const BaseballCard& card);
    virtual ~BaseballCardNode();

    BaseballCardNode* getNextName() const;
    void setNextName(BaseballCardNode* node);

    BaseballCardNode* getNextYear() const;
    void setNextYear(BaseballCardNode* node);

    BaseballCard getCard() const;
};
}


#endif // BASEBALLCARDNODE_H
