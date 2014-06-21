#ifndef _CCB_CCSCROLLLISTVIEW_H_
#define _CCB_CCSCROLLLISTVIEW_H_

#include "extensions/GUI/CCScrollView/CCScrollView.h"
#include "CCBMemberVariableAssigner.h"
#include "CCBSelectorResolver.h"
#include "CCBReader.h"
#include "base/CCRef.h"

//#include "cocos-ext.h"

typedef void (cocos2d::Ref::*SEL_ListView)(const std::string&,const std::string&);

namespace cocosbuilder {

class ScrollListView : public cocos2d::extension::ScrollView, public cocosbuilder::CCBMemberVariableAssigner,public cocosbuilder::CCBSelectorResolver
{
public:
    struct ItemStruct
    {
        cocos2d::Node* item;
        std::map<std::string,cocos2d::Node*> variables;
        std::vector<cocos2d::Node*> selectors;
    };
    void setTarget(Ref *rec, SEL_ListView selector);
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(ScrollListView, create);
    virtual bool init();
    ScrollListView();
    ~ScrollListView();
    ItemStruct *addElement(const std::string &name);
    bool removeElement(const std::string &name);
    void clear();
    void move(int elements);
    void prepare();
private:
    struct IndexItem
    {
        std::string item;
        std::string selector;
    };
    std::list<int> _movement;
    bool _inMove;
    std::map<std::string, ItemStruct> _items;
    std::map<cocos2d::Node*,IndexItem> _selectorIndex;
    std::map<std::string, ItemStruct>::iterator _curitem;
    
    cocos2d::Data _data;
    
    void moveContent(cocos2d::Point offset, float dt);
    void stoppedMove();
    void internalMove(int elements);

    
    cocos2d::Ref *_pListener;
    SEL_ListView _pfnSelector;
    
    virtual bool onAssignCCBMemberVariable(cocos2d::Ref* pTarget, const char* pMemberVariableName, cocos2d::Node* pNode) override;
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::Ref * pTarget, const char* pSelectorName, cocos2d::Node* pNode) override;
    virtual cocos2d::extension::Control::Handler onResolveCCBCCControlSelector(cocos2d::Ref * pTarget, const char* pSelectorName, cocos2d::Node* pNode) override;
    
    virtual void visit(cocos2d::Renderer* renderer, const cocos2d::Mat4 &parentTransform, bool parentTransformUpdated) override;
    
    void RecalcPositions();
    
    void OnChildMenuSelector(cocos2d::Ref* pSender);
    void OnChildControlSelector(cocos2d::Ref* pSender, cocos2d::extension::Control::EventType event);
    
    CC_PROPERTY_PASS_BY_REF(std::string, _template, Template);
    CC_PROPERTY(bool, _horizontal, Horizontal);
    CC_PROPERTY(cocos2d::TextVAlignment, _verticalTextAlignment, VerticalTextAlignment);
    CC_PROPERTY(cocos2d::TextHAlignment, _textAlignment, TextAlignment);
};
    
}


#endif
