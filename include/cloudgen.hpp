#ifndef __cloudgen_hpp_included__
#define __cloudgen_hpp_included__

#include <QObject>
#include "../include/factory.hpp"

class CloudDef;

class CloudGen : public QObject
{
  Q_OBJECT

public:
  CloudGen(QObject* parent = 0);

  QGraphicsItem* renderItem(const CloudDef& def) const;

  QGraphicsScene* renderScene(const CloudDef& def, QObject* parent = 0) const;

private:
};

#endif
