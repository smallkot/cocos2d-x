//
//  RjScrollListView.cpp
//  inferno
//
//  Created by user-i121 on 03.07.13.
//
//

#include "CCScrollListView.h"
#include "platform/CCFileUtils.h"
#include "2d/CCActionInterval.h"
#include "2d/CCActionInstant.h"
#include "CCNodeLoaderLibrary.h"
#include "base/CCDirector.h"

USING_NS_CC;
USING_NS_CC_EXT;

#define PROPERTY_TEMPLATE   "template"
#define PROPERTY_HORIZONTAL "horizontal"
#define PROPERTY_VERTALIGN  "verticalTextAlignment"
#define PROPERTY_HORIZALIGN "textAlignment"
#define SCROLL_MOVE_ELEMENTS    1

namespace cocosbuilder {

const std::string& ScrollListView::getTemplate(void) const
{
    return _template;
}

void ScrollListView::setTemplate(const std::string& var)
{
    _template = var;
    std::string strPath = FileUtils::getInstance()->fullPathForFilename(_template);
    _data = FileUtils::getInstance()->getDataFromFile(strPath);
}

void ScrollListView::visit(Renderer* renderer, const Mat4 &parentTransform, bool parentTransformUpdated)
{
    for (auto node : getContainer()->getChildren())
    {
        if((node->getPosition().x+node->getContentSize().width)<-getContainer()->getPosition().x)
            node->setVisible(false);
        else if((node->getPosition().x)>(getViewSize().width-getContainer()->getPosition().x))
            node->setVisible(false);
        else
            node->setVisible(true);
    }
    ScrollView::visit(renderer, parentTransform, parentTransformUpdated);
}

void ScrollListView::prepare()
{
    //ScrollView::visit();
}

void ScrollListView::RecalcPositions()
{
    if(getContainer()->getChildren().empty())
        return;
    size_t num=0;
    size_t count = getContainer()->getChildren().size();
    Node *node =getContainer()->getChildren().at(0);
    Size contentsize = node->getContentSize();
    Size viewsize = getViewSize();
    
    float yoffset = 0;
    switch (_verticalTextAlignment) {
        case TextVAlignment::TOP:
        {
            yoffset = 0;
            break;
        }
        case TextVAlignment::BOTTOM:
        {
            if (_horizontal) {
                yoffset = viewsize.height - contentsize.height;
            }
            else {
                yoffset = contentsize.height*count/2;
            }
            break;
        }
        case TextVAlignment::CENTER:
        {
            if (_horizontal) {
                yoffset = viewsize.height/2 - contentsize.height/2;
            }
            else {
                yoffset = viewsize.height/2 - contentsize.height*count/2;
            }
            break;
        }
        default:
            break;
    }
    
    if(_horizontal)
    {
        float containerSize = 0;
        for (auto pChild : getContainer()->getChildren())
        {
            pChild->setPosition(Point(pChild->getContentSize().width*num,0));
            containerSize += pChild->getContentSize().width;
            ++num;
        }
        
        float xoffset = 0;
        switch (_textAlignment) {
            case TextHAlignment::CENTER:
            {
                xoffset = viewsize.width/2 - containerSize/2;
                break;
            }
            case TextHAlignment::LEFT:
            {
                xoffset = 0;
                break;
            }
            case TextHAlignment::RIGHT:
            {
                xoffset = viewsize.width - contentsize.width;
                break;
            }
            default:
                break;
        }
        
        setContentOffset(Point(xoffset, (viewsize.height-contentsize.height) - yoffset), false);
        setContentSize(Size(std::max(contentsize.width*count,viewsize.width),std::max(contentsize.height,viewsize.height)));
        if((contentsize.width*count)<viewsize.width)
            setDirection(ScrollView::Direction::NONE);
        else
            setDirection(ScrollView::Direction::HORIZONTAL);
    }
    else
    {
        for (auto pChild : getContainer()->getChildren())
        {
            pChild->setPosition(Point(0,pChild->getContentSize().height*(count-num-1)));
            ++num;
        }
        
        float xoffset = 0;
        switch (_textAlignment) {
            case TextHAlignment::CENTER:
            {
                xoffset = viewsize.width/2 - contentsize.width/2;
                break;
            }
            case TextHAlignment::LEFT:
            {
                xoffset = 0;
                break;
            }
            case TextHAlignment::RIGHT:
            {
                xoffset = viewsize.width - contentsize.width;
                break;
            }
            default:
                break;
        }
        
        setContentOffset(Point(xoffset, (viewsize.height-contentsize.height*count) - yoffset), false);
        setContentSize(Size(std::max(contentsize.width,viewsize.width),std::max(contentsize.height*count,viewsize.height)));
        if((contentsize.height*count)<viewsize.height)
            setDirection(ScrollView::Direction::NONE);
        else
            setDirection(ScrollView::Direction::VERTICAL);
    }
}

void ScrollListView::setTarget(Ref *rec, SEL_ListView selector)
{
    _pListener = rec;
    _pfnSelector = selector;
}

bool ScrollListView::onAssignCCBMemberVariable(Ref* pTarget, const char* pMemberVariableName, Node* pNode)
{
    if((pTarget!=this)||(_curitem==_items.end()))
        return false;
    _curitem->second.variables[pMemberVariableName] = pNode;
    return true;
}
SEL_MenuHandler ScrollListView::onResolveCCBCCMenuItemSelector(Ref * pTarget, const char* pSelectorName, Node* pNode)
{
    if((pTarget!=this)||(_curitem==_items.end()))
        return NULL;
    IndexItem &indexItem=_selectorIndex[pNode];
    indexItem.item=_curitem->first;
    _curitem->second.selectors.push_back(pNode);
    indexItem.selector = pSelectorName;
    return cocos2d::SEL_MenuHandler(&ScrollListView::OnChildMenuSelector);
}
cocos2d::extension::Control::Handler ScrollListView::onResolveCCBCCControlSelector(Ref * pTarget, const char* pSelectorName, Node* pNode)
{
    if((pTarget!=this)||(_curitem==_items.end()))
        return NULL;
    IndexItem &indexItem=_selectorIndex[pNode];
    indexItem.item=_curitem->first;
    _curitem->second.selectors.push_back(pNode);
    indexItem.selector = pSelectorName;
    return cocos2d::extension::Control::Handler(&ScrollListView::OnChildControlSelector);
}
void ScrollListView::OnChildMenuSelector(Ref* pSender)
{
    auto it=_selectorIndex.find((Node*)pSender);
    if(it==_selectorIndex.end())
        return;
    if (_pListener && _pfnSelector)
    {
        (_pListener->*_pfnSelector)(it->second.item,it->second.selector);
    }

}
void ScrollListView::OnChildControlSelector(Ref* pSender, cocos2d::extension::Control::EventType event)
{
    auto it=_selectorIndex.find((Node*)pSender);
    if(it==_selectorIndex.end())
        return;
    if (_pListener && _pfnSelector)
    {
        (_pListener->*_pfnSelector)(it->second.item.c_str(),it->second.selector.c_str());
    }
}
ScrollListView::ScrollListView():_curitem(_items.end()),_pListener(NULL),_pfnSelector(NULL),_inMove(false)
,_textAlignment(cocos2d::TextHAlignment::LEFT)
,_horizontal(false)
{
}
ScrollListView::~ScrollListView()
{
}
bool ScrollListView::init()
{
    if(!ScrollView::init())
        return false;
    setDirection(ScrollView::Direction::VERTICAL);
    return true;
}
ScrollListView::ItemStruct *ScrollListView::addElement(const std::string &name)
{
    if(_items.find(name)!=_items.end())
        return NULL;
    _curitem = _items.insert(std::pair<std::string, ItemStruct>(name,ItemStruct())).first;
    
    cocosbuilder::CCBReader *reader = new cocosbuilder::CCBReader(NodeLoaderLibrary::getInstance());
    reader->autorelease();
    Node *node = reader->readNodeGraphFromData(_data, this, Director::getInstance()->getWinSize(), cocosbuilder::CCBReader::SceneScaleType::MAXSCALE);
    
    if(!node)
        return NULL;
    node->retain();
    _curitem->second.item=node;
    getContainer()->addChild(node);
    RecalcPositions();
    return &_curitem->second;
}
bool ScrollListView::removeElement(const std::string &name)
{
    auto elemIt=_items.find(name);
    if(elemIt==_items.end())
        return false;
    elemIt->second.item->removeFromParent();
    elemIt->second.item->release();
    for(auto it=elemIt->second.selectors.begin();it!=elemIt->second.selectors.end();++it)
    {
        auto selectorIt=_selectorIndex.find(*it);
        if(selectorIt!=_selectorIndex.end())
            _selectorIndex.erase(selectorIt);
    }
    _items.erase(elemIt);
    return true;
}

void ScrollListView::clear()
{
    for(auto it=_items.begin();it!=_items.end();++it)
    {
        it->second.item->removeFromParent();
        it->second.item->release();
    }
    _selectorIndex.clear();
    _items.clear();
}

void ScrollListView::setVerticalTextAlignment(cocos2d::TextVAlignment alignment)
{
    _verticalTextAlignment = alignment;
}

TextVAlignment ScrollListView::getVerticalTextAlignment()
{
    return _verticalTextAlignment;
}

void ScrollListView::setTextAlignment(cocos2d::TextHAlignment alignment)
{
    _textAlignment = alignment;
}

TextHAlignment ScrollListView::getTextAlignment()
{
    return _textAlignment;
}

bool ScrollListView::getHorizontal()
{
    return _horizontal;
}

void ScrollListView::setHorizontal(bool value)
{
    if(value)
        this->setDirection(ScrollView::Direction::HORIZONTAL);
    else
        this->setDirection(ScrollView::Direction::VERTICAL);
    _horizontal = value;
}

void ScrollListView::moveContent(cocos2d::Point offset, float dt)
{
    _scrollDistance = Point::ZERO;
    FiniteTimeAction *scroll, *expire;
    scroll = MoveBy::create(dt, offset);
    expire = CallFunc::create(std::bind(&ScrollListView::stoppedMove,this));
    _container->runAction(Sequence::create(scroll, expire, NULL));
}

void ScrollListView::stoppedMove()
{
    if(_movement.empty())
    {
        _inMove=false;
        return;
    }
    internalMove(_movement.front());
    _movement.pop_front();
}

void ScrollListView::internalMove(int elements)
{
    size_t count = getContainer()->getChildren().size();
    if(getContainer()->getChildren().empty())
        return;
    Node * node= getContainer()->getChildren().at(0);
    
    float offsetSize = node->getContentSize().width;
    if (!_horizontal)
        offsetSize = node->getContentSize().height;
    
    if(_horizontal && ((offsetSize*count) < getViewSize().width))
        return;
    
    if(!_horizontal && ((offsetSize*count) < getViewSize().height))
        return;
    
    Point offset = Point::ZERO;
    if (_horizontal)
        offset = Point(offsetSize, 0);
    else
        offset = Point(0, offsetSize);
    
    offset = offset * elements;
    offset = offset * -1.0f;
    
    if (-getContentOffset().x + getViewSize().width - offset.x > getContentSize().width)
        offset.x = -(getContentSize().width-getViewSize().width+getContentOffset().x);
    if (-getContentOffset().x -offset.x < 0)
        offset.x=-getContentOffset().x;
    
    int div = (int)(getContentOffset().x + offset.x) % (int) node->getContentSize().width;
    
    if (div) {
        if (offset.x < 0)
            offset.x -= div;
        if (offset.x > 0)
            offset.x -= div + node->getContentSize().width;
    }
    
    _inMove=true;
    
    this->moveContent(offset, 0.25f);
}

void ScrollListView::move(int elements)
{
    if(_inMove)
    {
        _movement.push_back(elements);
        return;
    }
    internalMove(elements);
}
    
}
