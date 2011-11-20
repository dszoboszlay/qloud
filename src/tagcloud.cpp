#include "../include/common.hpp"
#include "../include/clouddef.hpp"
#include "../include/tagcloud.hpp"

TagCloud::TagCloud(QObject* parent) :
  QObject(parent)
{
}

QGraphicsItem* TagCloud::renderItem(const CloudDef& def) const
{
  QGraphicsItemGroup* result = new QGraphicsItemGroup();

  /* TODO: set modes from def for
     - text
     - font
     - size
     - color
     - orientation
     - placement
     - word order
   */

  QRegion filledArea;
  WordList words(def.words());
  foreach(const PropSet* word, words) {
    QTransform transf;
    QGraphicsSimpleTextItem* item = new QGraphicsSimpleTextItem();
    item->setBoundingRegionGranularity(1.0);

    // TODO: set the properties of item & transf
    item->setText(word->get<QString>("text", QString("")));

    filledArea += item->boundingRegion(transf);
    item->setTransform(transf);
    result->addToGroup(item);
  }

  return result;
}

QGraphicsScene* TagCloud::renderScene(const CloudDef& def) const
{
  QGraphicsScene* result = new QGraphicsScene();
  result->addItem(renderItem(def));

  /* TODO: set from def
     - bg brush
     - viewport
  */
  return result;
}
