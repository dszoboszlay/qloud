#ifndef __simplesetter_hpp_included__
#define __simplesetter_hpp_included__

#include <QBrush>
#include <QColor>
#include <QFont>
#include <QGraphicsSimpleTextItem>
#include <QString>
#include "../include/clouddef.hpp"
#include "../include/propset.hpp"
#include "../include/setter.hpp"

// Default property handlers
template <class T>
const char* getPropName()
{
  throw "Not implemented";
}

template <class T>
void applyPropValue(QGraphicsSimpleTextItem&, const T&)
{
  throw "Not implemented";
}

// QString = text
template <>
const char* getPropName<QString>()
{
  return "text";
}

template <>
void applyPropValue<QString>(QGraphicsSimpleTextItem& item,
                             const QString& value)
{
  item.setText(value);
}

// QFont = font
template <>
const char* getPropName<QFont>()
{
  return "font";
}

template <>
void applyPropValue<QFont>(QGraphicsSimpleTextItem& item,
                           const QFont& value)
{
  QFont f(value);
  f.setPointSizeF(item.font().pointSizeF());
  item.setFont(f);
}

// QColor = color
template <>
const char* getPropName<QColor>()
{
  return "color";
}

template <>
void applyPropValue<QColor>(QGraphicsSimpleTextItem& item,
                            const QColor& value)
{
  item.setBrush(QBrush(value));
}

// qreal = size
template <>
const char* getPropName<qreal>()
{
  return "size";
}

template <>
void applyPropValue<qreal>(QGraphicsSimpleTextItem& item,
                            const qreal& value)
{
  QFont f(item.font());
  f.setPointSizeF(value);
  item.setFont(f);
}

// The generic setter implementation
template <class T>
class SimpleSetter : public Setter
{
public:
  virtual void init(const CloudDef& cloud)
  {
    _default = cloud.get<T>(getPropName<T>(), _default);
  }

  virtual void apply(const PropSet& word,
                     QGraphicsSimpleTextItem& item,
		     QTransform&,
		     const QRegion&)
  {
    applyPropValue<T>(item, word.get<T>(getPropName<T>(), _default));
  }

private:
  T _default;
};

#endif
