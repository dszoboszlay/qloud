#ifndef __cloudgen_hpp_included__
#define __cloudgen_hpp_included__

#include <QHash>
#include <QList>
#include <QObject>
#include <QPair>
#include "../include/factory.hpp"

class CloudDef;
class PropSet;
class Setter;

typedef Setter* (*SetterInstanceFactory)();
typedef QPair<const char*, SetterInstanceFactory> SetterDef;
typedef QPair<Setter*, SetterDef> SetterAndDef;

class CloudGen : public QObject
{
  Q_OBJECT

  typedef Factory<SetterDef> SetterFactory;
  typedef QList<SetterFactory> SetterFactories;
  typedef QHash<const char*, Setter*> SetterDict;

public:
  CloudGen(QObject* parent = 0);

  QGraphicsItem* renderItem(const CloudDef& def) const;

  QGraphicsScene* renderScene(const CloudDef& def, QObject* parent = 0) const;

private:
  SetterFactories _setterFactories;

  SetterAndDef getSetterAndDef(const PropSet& props,
			       const CloudDef& cloud,
			       const SetterFactory& setterFactory,
			       SetterDict& setters) const;
};

#endif
