#ifndef __setter_hpp_included__
#define __setter_hpp_included__

class QGraphicsSimpleTextItem;
class QRegion;
class QTransform;
class CloudDef;
class PropSet;

class Setter
{
public:
  virtual void init(const CloudDef& cloud) = 0;

  virtual void apply(const PropSet& word,
		     QGraphicsSimpleTextItem& item,
		     QTransform& transform,
		     const QRegion& filledArea) = 0;
};

#endif
