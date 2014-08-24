#include "CCScale9SpriteLoader.h"

using namespace cocos2d;
using namespace cocos2d::extension;

#define PROPERTY_CONTENTSIZE "contentSize"
#define PROPERTY_DISPLAYFRAME "displayFrame"
#define PROPERTY_SPRITEFRAME "spriteFrame"
#define PROPERTY_BLENDFUNC "blendFunc"
#define PROPERTY_PREFEREDSIZE "preferedSize" // TODO Should be "preferredSize". This is a typo in cocos2d-iphone, cocos2d-x and CocosBuilder!
#define PROPERTY_INSETLEFT "insetLeft"
#define PROPERTY_INSETTOP "insetTop"
#define PROPERTY_INSETRIGHT "insetRight"
#define PROPERTY_INSETBOTTOM "insetBottom"

#define PROPERTY_MARGIN_LEFT "marginLeft"
#define PROPERTY_MARGIN_TOP "marginTop"
#define PROPERTY_MARGIN_RIGHT "marginRight"
#define PROPERTY_MARGIN_BOTTOM "marginBottom"

namespace cocosbuilder {

void Scale9SpriteLoader::onStarPropertiesParsing(cocos2d::Node * pNode, CCBReader * ccbReader)
{
    _margins=Rect::ZERO;
    _size=Size::ZERO;
}

void Scale9SpriteLoader::onEndPropertiesParsing(cocos2d::Node * pNode, CCBReader * ccbReader)
{
     ((Scale9Sprite *)pNode)->setPreferredSize(_size);
    if(ccbReader->getVersion()>5)
    {
        Rect margin(_margins.origin.x,_margins.origin.y,1.0-_margins.size.width-_margins.origin.x,1.0-_margins.size.height-_margins.origin.y);
        Size size = ((Scale9Sprite *)pNode)->getOriginalSize();
        ((Scale9Sprite *)pNode)->setCapInsets(Rect(margin.origin.x*size.width,margin.origin.y*size.height,margin.size.width*size.width,margin.size.height*size.height));
    }
}

void Scale9SpriteLoader::onHandlePropTypeSpriteFrame(Node * pNode, Node * pParent, const char * pPropertyName, SpriteFrame * pSpriteFrame, CCBReader * ccbReader) {
    if((strcmp(pPropertyName, PROPERTY_SPRITEFRAME) == 0)||(strcmp(pPropertyName, PROPERTY_DISPLAYFRAME) == 0)) {
        ((Scale9Sprite *)pNode)->setSpriteFrame(pSpriteFrame);
    } else {
        NodeLoader::onHandlePropTypeSpriteFrame(pNode, pParent, pPropertyName, pSpriteFrame, ccbReader);
    }
}

void Scale9SpriteLoader::onHandlePropTypeBlendFunc(Node * pNode, Node * pParent, const char * pPropertyName, BlendFunc pBlendFunc, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_BLENDFUNC) == 0) {
        // TODO Not exported by CocosBuilder yet!
        //((Scale9Sprite *)pNode)->setBlendFunc(pBlendFunc);
    } else {
        NodeLoader::onHandlePropTypeBlendFunc(pNode, pParent, pPropertyName, pBlendFunc, ccbReader);
    }
}

void Scale9SpriteLoader::onHandlePropTypeSize(Node * pNode, Node * pParent, const char * pPropertyName, const Size &pSize, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_CONTENTSIZE) == 0) {
        _size = pSize;
    } else if(strcmp(pPropertyName, PROPERTY_PREFEREDSIZE) == 0) {
        _size = pSize;
    } else {
        NodeLoader::onHandlePropTypeSize(pNode, pParent, pPropertyName, pSize, ccbReader);
    }
}

void Scale9SpriteLoader::onHandlePropTypeFloat(Node * pNode, Node * pParent, const char * pPropertyName, float pFloat, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_INSETLEFT) == 0) {
        ((Scale9Sprite *)pNode)->setInsetLeft(pFloat);
    } else if(strcmp(pPropertyName, PROPERTY_INSETTOP) == 0) {
        ((Scale9Sprite *)pNode)->setInsetTop(pFloat);
    } else if(strcmp(pPropertyName, PROPERTY_INSETRIGHT) == 0) {
        ((Scale9Sprite *)pNode)->setInsetRight(pFloat);
    } else if(strcmp(pPropertyName, PROPERTY_INSETBOTTOM) == 0) {
        ((Scale9Sprite *)pNode)->setInsetBottom(pFloat);
    } else if(strcmp(pPropertyName, PROPERTY_MARGIN_LEFT) == 0) {
        _margins.origin.x = pFloat;
    } else if(strcmp(pPropertyName, PROPERTY_MARGIN_TOP) == 0) {
        _margins.origin.y = pFloat;
    } else if(strcmp(pPropertyName, PROPERTY_MARGIN_RIGHT) == 0) {
        _margins.size.width = pFloat;
    } else if(strcmp(pPropertyName, PROPERTY_MARGIN_BOTTOM) == 0) {
        _margins.size.height = pFloat;
    } else {
        NodeLoader::onHandlePropTypeFloat(pNode, pParent, pPropertyName, pFloat, ccbReader);
    }
}

}
