#include "../include/common.hpp"
#include "../include/clouddef.hpp"
#include "../include/cloudgen.hpp"
#include "../include/simplesetter.hpp"

template <class T>
Setter* setterFact() {
  return new T();
};

template <class T>
SetterDef setterDef() {
  return SetterDef(typeid(T).name(),
		   setterFact<T>);
}

CloudGen::CloudGen(QObject* parent) :
  QObject(parent)
{
  SetterDef d;

  // Create text setter factories
  d = setterDef<SimpleSetter<QString> >();
  SetterFactory textSetters("text_setter", d);
  textSetters.set("text", d);

  _setterFactories << textSetters;

  // Create font setter factories
  d = setterDef<SimpleSetter<QFont> >();
  SetterFactory fontSetters("font_setter", d);
  fontSetters.set("font", d);

  _setterFactories << fontSetters;

  // Create color setter factories
  d = setterDef<SimpleSetter<QColor> >();
  SetterFactory colorSetters("color_setter", d);
  colorSetters.set("color", d);

  _setterFactories << colorSetters;

  // Create size setter factories
  d = setterDef<SimpleSetter<qreal> >();
  SetterFactory sizeSetters("size_setter", d);
  sizeSetters.set("size", d);

  _setterFactories << sizeSetters;

  /* TODO: add factories for
     - weight-scaled size
     - orientation
     - placement
     - word order
   */
}

QGraphicsItem* CloudGen::renderItem(const CloudDef& def) const
{
  QGraphicsItemGroup* result = new QGraphicsItemGroup();

  // Create CloudDef specific setter factories
  // by taking the default value from the CloudDef
  SetterFactories setterFactories;
  SetterDict setters;
  foreach (const SetterFactory& setterFactory, _setterFactories) {
    SetterAndDef setterAndDef =
      getSetterAndDef(def, def, setterFactory, setters);
    setterFactories << SetterFactory(setterFactory, setterAndDef.second);
  }

  QRegion filledArea;
  WordList words(def.words());
  foreach (const PropSet* word, words) {
    QTransform transf;
    QGraphicsSimpleTextItem* item = new QGraphicsSimpleTextItem();
#if QT_VERSION >= 0x040400
    item->setBoundingRegionGranularity(1.0);
#endif

    // Set the properties of item & transf
    foreach (const SetterFactory& setterFactory, setterFactories) {
      Setter* setter =
	getSetterAndDef(*word, def, setterFactory, setters).first;
      setter->apply(*word, *item, transf, filledArea);
    }

#if QT_VERSION >= 0x040400
    filledArea += item->boundingRegion(transf);
#else
    filledArea += transf.mapToPolygon(item->boundingRect().toRect());
#endif
    item->setTransform(transf);
    result->addToGroup(item);
  }

  // Delete unneeded setters
  foreach (Setter* setter, setters)
    delete setter;

  return result;
}

QGraphicsScene* CloudGen::renderScene(const CloudDef& def,
				      QObject* parent) const
{
  QGraphicsScene* result = new QGraphicsScene(parent);
  result->addItem(renderItem(def));

  /* TODO: set from def
     - bg brush
     - viewport
  */
  return result;
}

SetterAndDef CloudGen::getSetterAndDef(const PropSet& props,
				       const CloudDef& cloud,
				       const SetterFactory& setterFactory,
				       SetterDict& setters) const
{
  SetterDef def =
    props.getIndirect<SetterDef, SetterFactory>(setterFactory.name(),
						setterFactory);
  Setter* setter;

  const SetterDict::const_iterator it = setters.find(def.first);
  if (it == setters.constEnd()) {
    setter = (def.second)();
    setter->init(cloud);
    setters.insert(def.first, setter);
  }
  else {
    setter = it.value();
  }

  return SetterAndDef(setter, def);
}
