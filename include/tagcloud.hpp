#ifndef __tagcloud_hpp_included__
#define __tagcloud_hpp_included__

#include <QObject>
#include "../include/factory.hpp"

class CloudDef;

class TagCloud : public QObject
{
  Q_OBJECT

public:
  TagCloud(QObject* parent = 0);

  QGraphicsItem* renderItem(const CloudDef& def) const;

  QGraphicsScene* renderScene(const CloudDef& def) const;

private:
};

#endif
