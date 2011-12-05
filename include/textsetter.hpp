#ifndef __textsetter_hpp_included__
#define __textsetter_hpp_included__

#include <QString>
#include "../include/setter.hpp"

class TextSetter : public Setter
{
  Q_OBJECT

public:
  TextSetter(QObject* parent = 0);
};

class BasicTextSetter : public TextSetter
{
  Q_OBJECT

public:
  static const char textProp[];

  BasicTextSetter(QObject* parent = 0);

  virtual void init(const CloudDef& cloud);

  virtual void apply(const PropSet& word,
		     QGraphicsSimpleTextItem& item,
		     QTransform& transform,
		     const QRegion& filledArea);

private:
  QString _default;
};

#endif
