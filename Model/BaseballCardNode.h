#ifndef BASEBALLCARDNODE_H
#define BASEBALLCARDNODE_H

#include "BaseballCard.h"

namespace model
{

class BaseballCardNode
{
    BaseballCard card;

    BaseballCardNode* nextName;

public:
    BaseballCardNode(BaseballCard& card);
    virtual ~BaseballCardNode();

    void setNextName(BaseballCardNode* node);
    BaseballCardNode* getNextName();

    BaseballCard getCard() const;
};
}


#endif // BASEBALLCARDNODE_H
