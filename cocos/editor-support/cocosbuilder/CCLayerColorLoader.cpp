#include "CCLayerColorLoader.h"

using namespace cocos2d;

namespace cocosbuilder {

#define PROPERTY_BLENDFUNC "blendFunc"
    
void LayerColorLoader::onStarPropertiesParsing(cocos2d::Node * pNode, CCBReader * ccbReader)
{
    pNode->setOpacity(255);
}

void LayerColorLoader::onHandlePropTypeBlendFunc(Node * pNode, Node * pParent, const char * pPropertyName, BlendFunc pBlendFunc, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_BLENDFUNC) == 0) {
        ((LayerColor *)pNode)->setBlendFunc(pBlendFunc);
    } else {
        LayerLoader::onHandlePropTypeBlendFunc(pNode, pParent, pPropertyName, pBlendFunc, ccbReader);
    }
}

}
