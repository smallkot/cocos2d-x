#ifndef _CCB_CCSCALE9SPRITELOADER_H_
#define _CCB_CCSCALE9SPRITELOADER_H_

#include "CCNodeLoader.h"
#include "CCScale9SpriteLoader.h"
#include "extensions/GUI/CCControlExtension/CCScale9Sprite.h"

namespace cocosbuilder {

/* Forward declaration. */
class CCBReader;

class Scale9SpriteLoader : public NodeLoader {
public:
    /**
     * @js NA
     * @lua NA
     */
    virtual ~Scale9SpriteLoader() {};
    /**
     * @js NA
     * @lua NA
     */
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(Scale9SpriteLoader, loader);

protected:
    
    virtual void onStarPropertiesParsing(cocos2d::Node * pNode, CCBReader * ccbReader) override;
    virtual void onEndPropertiesParsing(cocos2d::Node * pNode, CCBReader * ccbReader) override;
    
    /**
     * @js NA
     * @lua NA
     */
    virtual cocos2d::extension::Scale9Sprite * createNode(cocos2d::Node * pParent, cocosbuilder::CCBReader * ccbReader) {
        cocos2d::extension::Scale9Sprite* pNode = cocos2d::extension::Scale9Sprite::create();
        
        pNode->setAnchorPoint(cocos2d::Vec2::ZERO);
        
        return pNode;
    };
    /**
     * @js NA
     * @lua NA
     */
    virtual void onHandlePropTypeBlendFunc(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::BlendFunc pBlendFunc, CCBReader * ccbReader) override;
    
    /**
     * @js NA
     * @lua NA
     */
    virtual void onHandlePropTypeSpriteFrame(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::SpriteFrame * pSpriteFrame, CCBReader * ccbReader) override;
    /**
     * @js NA
     * @lua NA
     */
    virtual void onHandlePropTypeSize(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, const cocos2d::Size &pSize, CCBReader * ccbReader) override;
    /**
     * @js NA
     * @lua NA
     */
    virtual void onHandlePropTypeFloat(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, float pFloat, CCBReader * ccbReader);
private:
    cocos2d::Rect _margins;
    cocos2d::Size _size;
};

}

#endif
