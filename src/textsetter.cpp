#include "../include/common.hpp"
#include "../include/clouddef.hpp"
#include "../include/propset.hpp"
#include "../include/textsetter.hpp"

TextSetter::TextSetter(QObject* parent) :
  Setter(parent)
{
}

BasicTextSetter::BasicTextSetter(QObject* parent) :
  TextSetter(parent)
{
}

const char BasicTextSetter::textProp[] = "text";

void BasicTextSetter::init(const CloudDef& cloud)
{
  _default = cloud.get<QString>(textProp, _default);
}

void BasicTextSetter::apply(const PropSet& word,
			    QGraphicsSimpleTextItem& item,
			    QTransform&,
			    const QRegion&)
{
  item.setText(word.get<QString>(textProp, _default));
}
