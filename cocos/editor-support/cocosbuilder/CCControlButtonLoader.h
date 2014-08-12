#ifndef _CCB_CCCONTROLBUTTONLOADER_H_
#define _CCB_CCCONTROLBUTTONLOADER_H_

#include "CCControlLoader.h"
#include "extensions//GUI/CCControlExtension/CCControlButton.h"

namespace cocosbuilder {

/* Forward declaration. */
class CCBReader;

class ControlButtonLoader : public ControlLoader {
    public:
        /**
         * @js NA
         * @lua NA
         */
        virtual ~ControlButtonLoader() {};
        /**
         * @js NA
         * @lua NA
         */
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ControlButtonLoader, loader);

    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(cocos2d::extension::ControlButton);

        virtual void onHandlePropTypeCheck(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, bool pCheck, CCBReader * ccbReader) override;
        virtual void onHandlePropTypeString(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, const char * pString, CCBReader * ccbReader) override;
        virtual void onHandlePropTypeFontTTF(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, const char * pFontTTF, CCBReader * ccbReader) override;
        virtual void onHandlePropTypeFloatScale(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, float pFloatScale, CCBReader * ccbReader) override;
        virtual void onHandlePropTypePoint(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::Point pPoint, CCBReader * ccbReader) override;
        virtual void onHandlePropTypeSize(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::Size pSize, CCBReader * ccbReader) override;
        virtual void onHandlePropTypeSpriteFrame(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::SpriteFrame * pSpriteFrame, CCBReader * ccbReader) override;
        virtual void onHandlePropTypeColor3(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::Color4B pColor4B, CCBReader * ccbReader) override;
};

}

#endif
