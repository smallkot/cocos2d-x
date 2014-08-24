#include "CCSpriteLoader.h"

using namespace cocos2d;

#define PROPERTY_FLIP "flip"
#define PROPERTY_DISPLAYFRAME "displayFrame"
#define PROPERTY_SPRITEFRAME "spriteFrame"
#define PROPERTY_BLENDFUNC "blendFunc"

namespace cocosbuilder {

void SpriteLoader::onHandlePropTypeSpriteFrame(Node * pNode, Node * pParent, const char * pPropertyName, SpriteFrame * pSpriteFrame, CCBReader * ccbReader) {
    if((strcmp(pPropertyName, PROPERTY_DISPLAYFRAME) == 0)||(strcmp(pPropertyName, PROPERTY_SPRITEFRAME) == 0)) {
        if(pSpriteFrame != nullptr) {
            ((Sprite *)pNode)->setSpriteFrame(pSpriteFrame);
        } else {
            CCLOG("ERROR: SpriteFrame nullptr");
        }
    } else {
        NodeLoader::onHandlePropTypeSpriteFrame(pNode, pParent, pPropertyName, pSpriteFrame, ccbReader);
    }
}

void SpriteLoader::onHandlePropTypeFlip(Node * pNode, Node * pParent, const char * pPropertyName, bool * pFlip, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_FLIP) == 0) {
        ((Sprite *)pNode)->setFlippedX(pFlip[0]);
        ((Sprite *)pNode)->setFlippedY(pFlip[1]);
    } else {
        NodeLoader::onHandlePropTypeFlip(pNode, pParent, pPropertyName, pFlip, ccbReader);
    }
}

void SpriteLoader::onHandlePropTypeBlendFunc(Node * pNode, Node * pParent, const char * pPropertyName, BlendFunc pBlendFunc, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_BLENDFUNC) == 0) {
        ((Sprite *)pNode)->setBlendFunc(pBlendFunc);
    } else {
        NodeLoader::onHandlePropTypeBlendFunc(pNode, pParent, pPropertyName, pBlendFunc, ccbReader);
    }
}

}
