#include "CCNode+CCBRelativePositioning.h"
#include "CCBReader.h"

using namespace cocos2d;

namespace cocosbuilder {

void convertPosition(CCBReader::PositionType type, Point &pt, CCBReader::PositionReferenceCorner &corner, CCBReader::PositionUnit &xUnit, CCBReader::PositionUnit &yUnit)
{
    if (type == CCBReader::PositionType::RELATIVE_BOTTOM_LEFT)
    {
        corner = CCBReader::PositionReferenceCorner::BOTTOMLEFT;
        xUnit = CCBReader::PositionUnit::POINTS;
        yUnit = CCBReader::PositionUnit::POINTS;
    }
    else if (type == CCBReader::PositionType::RELATIVE_TOP_LEFT)
    {
        corner = CCBReader::PositionReferenceCorner::TOPLEFT;
        xUnit = CCBReader::PositionUnit::POINTS;
        yUnit = CCBReader::PositionUnit::POINTS;
    }
    else if (type == CCBReader::PositionType::RELATIVE_TOP_RIGHT)
    {
        corner = CCBReader::PositionReferenceCorner::TOPRIGHT;
        xUnit = CCBReader::PositionUnit::POINTS;
        yUnit = CCBReader::PositionUnit::POINTS;
    }
    else if (type == CCBReader::PositionType::RELATIVE_BOTTOM_RIGHT)
    {
        corner = CCBReader::PositionReferenceCorner::BOTTOMRIGHT;
        xUnit = CCBReader::PositionUnit::POINTS;
        yUnit = CCBReader::PositionUnit::POINTS;
    }
    else if (type == CCBReader::PositionType::PERCENT)
    {
        corner = CCBReader::PositionReferenceCorner::BOTTOMLEFT;
        xUnit = CCBReader::PositionUnit::NORMALIZED;
        yUnit = CCBReader::PositionUnit::NORMALIZED;
        pt.x /= 100.0f;
        pt.y /= 100.0f;
    }
    else if (type == CCBReader::PositionType::MULTIPLY_RESOLUTION)
    {
        corner = CCBReader::PositionReferenceCorner::BOTTOMLEFT;
        xUnit = CCBReader::PositionUnit::UIPOINTS;
        yUnit = CCBReader::PositionUnit::UIPOINTS;
    }
}

cocos2d::Size getRelativeScale(float mainScale, float additionalScale, float scaleX, float scaleY, unsigned int type, const std::string& propName)
{
    
    float scaleXCoef = 1.0;
    float scaleYCoef = 1.0;
    
    if (type & static_cast<int>(CCBReader::ScaleType::MULTIPLY_RESOURCES_SCALE))
    {
        scaleXCoef *= CCBReader::getResolutionScale();
        scaleYCoef *= CCBReader::getResolutionScale();
    }
    
    if (type & static_cast<int>(CCBReader::ScaleType::MULTIPLY_MAIN_SCALE))
    {
        scaleXCoef *= mainScale;
        scaleYCoef *= mainScale;
    }
    
    if (type & static_cast<int>(CCBReader::ScaleType::MULTIPLY_ADDITION_SCALE_X))
    {
        scaleXCoef *= additionalScale;
    }
    
    if (type & static_cast<int>(CCBReader::ScaleType::MULTIPLY_ADDITION_SCALE_Y))
    {
        scaleYCoef *= additionalScale;
    }
        
    if (type & static_cast<int>(CCBReader::ScaleType::INVERT_SCALE))
    {
        scaleXCoef = 1.0f/scaleXCoef;
        scaleYCoef = 1.0f/scaleYCoef;
    }
    
    return Size(scaleX*scaleXCoef,scaleY*scaleYCoef);
}

Point getAbsolutePosition(float mainScale, float additionalScale, const Point &pt, CCBReader::PositionReferenceCorner corner, CCBReader::PositionUnit xUnit, CCBReader::PositionUnit yUnit, const Size &containerSize, const char *pPropName)
{
    Point positionInPoints=Point(0,0);
    float x = 0;
    float y = 0;
    
    // Convert position to points
    if (xUnit == CCBReader::PositionUnit::POINTS) x = pt.x;
    else if (xUnit == CCBReader::PositionUnit::UIPOINTS) x = pt.x * CCBReader::getResolutionScale() * mainScale;
    else if (xUnit == CCBReader::PositionUnit::NORMALIZED) x = pt.x * containerSize.width;
    
    if (yUnit == CCBReader::PositionUnit::POINTS) y = pt.y;
    else if (yUnit == CCBReader::PositionUnit::UIPOINTS) y = pt.y * CCBReader::getResolutionScale() * mainScale;
    else if (yUnit == CCBReader::PositionUnit::NORMALIZED) y = pt.y * containerSize.height;
    
    // Account for reference corner
    //CCPositionReferenceCorner corner = type.corner;
    if (corner == CCBReader::PositionReferenceCorner::BOTTOMLEFT)
    {
        // Nothing needs to be done
    }
    else if (corner == CCBReader::PositionReferenceCorner::TOPLEFT)
    {
        // Reverse y-axis
        y = containerSize.height - y;
    }
    else if (corner == CCBReader::PositionReferenceCorner::TOPRIGHT)
    {
        // Reverse x-axis and y-axis
        x = containerSize.width - x;
        y = containerSize.height - y;
    }
    else if (corner == CCBReader::PositionReferenceCorner::BOTTOMRIGHT)
    {
        // Reverse x-axis
        x = containerSize.width - x;
    }
    
    positionInPoints.x = x;
    positionInPoints.y = y;
    
    return positionInPoints;
}

Size getAbsoluteSize(float mainScale, float additionalScale, const Size &contentSize, CCBReader::SizeUnit widthUnit, CCBReader::SizeUnit heightUnit, const Size &containerSize)
{
    Size size = Size::ZERO;
    
    // Width
    if (widthUnit == CCBReader::SizeUnit::POINTS)
    {
        size.width = contentSize.width;
    }
    else if (widthUnit == CCBReader::SizeUnit::UIPOINTS)
    {
        size.width = CCBReader::getResolutionScale() * mainScale * contentSize.width;
    }
    else if (widthUnit == CCBReader::SizeUnit::NORMALIZED)
    {
        size.width = contentSize.width * containerSize.width;
    }
    else if (widthUnit == CCBReader::SizeUnit::INSETPOINTS)
    {
        size.width = containerSize.width - contentSize.width;
    }
    else if (widthUnit == CCBReader::SizeUnit::INSETUIPOINTS)
    {
        size.width = containerSize.width - contentSize.width * CCBReader::getResolutionScale() * mainScale;
    }
        
    // Height
    if (heightUnit == CCBReader::SizeUnit::POINTS)
    {
        size.height = contentSize.height;
    }
    else if (heightUnit == CCBReader::SizeUnit::UIPOINTS)
    {
        size.height = CCBReader::getResolutionScale() * mainScale * contentSize.height;
    }
    else if (heightUnit == CCBReader::SizeUnit::NORMALIZED)
    {
        size.height = contentSize.height * containerSize.height;
    }
    else if (heightUnit == CCBReader::SizeUnit::INSETPOINTS)
    {
        size.height = containerSize.height - contentSize.height;
    }
    else if (heightUnit == CCBReader::SizeUnit::INSETUIPOINTS)
    {
        size.height = containerSize.height - contentSize.height * CCBReader::getResolutionScale() * mainScale;
    }
    
    return size;
}

}
