#ifndef _CCB_CCPROGRESSTIMERLOADER_H_
#define _CCB_CCPROGRESSTIMERLOADER_H_

#include "CCNodeLoader.h"
#include "CCProgressTimer.h"

namespace cocosbuilder {
    
/* Forward declaration. */
class CCBReader;

class ProgressTimerLoader : public NodeLoader {
public:
    virtual ~ProgressTimerLoader() {};
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ProgressTimerLoader, loader);
    
protected:
    //CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(CCSprite);
    
    virtual cocos2d::ProgressTimer* createNode(cocos2d::Node * pParent, CCBReader * pCCBReader) override
    {
        return cocos2d::ProgressTimer::create(cocos2d::Sprite::create());
    }
    
    virtual void onStarPropertiesParsing(cocos2d::Node * pNode, CCBReader * ccbReader) override;
    virtual void onEndPropertiesParsing(cocos2d::Node * pNode, CCBReader * ccbReader) override;
    
    virtual void onHandlePropTypeColor3(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::Color4B pCCColor4B, CCBReader * pCCBReader) override;
    virtual void onHandlePropTypeByte(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, unsigned char pByte, CCBReader * pCCBReader) override;
    virtual void onHandlePropTypeBlendFunc(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::BlendFunc pCCBBlendFunc, CCBReader * pCCBReader) override;
    virtual void onHandlePropTypeSpriteFrame(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::SpriteFrame * pCCSpriteFrame, CCBReader * pCCBReader) override;
    virtual void onHandlePropTypeFlip(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, bool * pFlip, CCBReader * pCCBReader) override;
    virtual void onHandlePropTypeIntegerLabeled(cocos2d::Node *pNode, cocos2d::Node *pParent, const char *pPropertyName, int pIntegerLabeled, CCBReader *pCCBReader) override;
    virtual void onHandlePropTypePoint(cocos2d::Node *pNode, cocos2d::Node * pParent, const char *pPropertyName, cocos2d::Point pPoint, CCBReader * pCCBReader) override;
    virtual void onHandlePropTypeFloat(cocos2d::Node *pNode, cocos2d::Node *pParent, const char *pPropertyName, float pFloat, CCBReader *pCCBReader) override;
    virtual void onHandlePropTypeCheck(cocos2d::Node *pNode, cocos2d::Node *pParent, const char *pPropertyName, bool pCheck, CCBReader *pCCBReader) override;
    
private:
    float _percentage;
};
    
}

#endif
