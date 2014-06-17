#ifndef _CCB_CCBUTTONLOADER_H_
#define _CCB_CCBUTTONLOADER_H_

#include "CCControlLoader.h"
#include "extensions/GUI/CCControlExtension/CCButton.h"

namespace cocosbuilder {

/* Forward declaration. */
class CCBReader;

class ButtonLoader : public ControlLoader {
    public:
        /**
         * @js NA
         * @lua NA
         */
        virtual ~ButtonLoader() {};
        /**
         * @js NA
         * @lua NA
         */
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ButtonLoader, loader);

    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(cocos2d::extension::Button);
    
        virtual void onStarPropertiesParsing(cocos2d::Node * pNode, CCBReader * ccbReader) override;
        virtual void onEndPropertiesParsing(cocos2d::Node * pNode, CCBReader * ccbReader) override;
    
        virtual void onHandlePropTypeBlock(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, BlockData * pBlockData, CCBReader * ccbReader) override;

        virtual void onHandlePropTypeCheck(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, bool pCheck, CCBReader * ccbReader) override;
        virtual void onHandlePropTypeString(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, const char * pString, CCBReader * ccbReader) override;
        virtual void onHandlePropTypeText(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, const char * pString, CCBReader * ccbReader) override;
        virtual void onHandlePropTypeFontTTF(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, const char * pFontTTF, CCBReader * ccbReader) override;
        virtual void onHandlePropTypeFloat(cocos2d::Node * pNode, cocos2d::Node * pParent, const char* pPropertyName, float pFloat, CCBReader * ccbReader) override;
        virtual void onHandlePropTypeFloatScale(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, float pFloatScale, CCBReader * ccbReader) override;
        virtual void onHandlePropTypePoint(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::Point pPoint, CCBReader * ccbReader) override;
        virtual void onHandlePropTypeSize(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::Size pSize, CCBReader * ccbReader) override;
        virtual void onHandlePropTypeSpriteFrame(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::SpriteFrame * pSpriteFrame, CCBReader * ccbReader) override;
        virtual void onHandlePropTypeColor3(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::Color4B pColor4B, CCBReader * ccbReader) override;
        virtual void onHandlePropTypeColor4(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::Color4B pColor4B, CCBReader * ccbReader) override;
        virtual void onHandlePropTypePosition(cocos2d::Node * pNode, cocos2d::Node * pParent, const char* pPropertyName, cocos2d::Point pPosition, CCBReader * pCCBReader) override;
    
    private:
        cocos2d::Rect _margins;
        cocos2d::Color4B _outlineColor;
        cocos2d::Color4B _shadowColor;
        float _outlineWidth;
        float _shadowBlurRadius;
        cocos2d::Size _shadowOffset;
    
};

}

#endif
