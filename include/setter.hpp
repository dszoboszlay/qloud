#ifndef __setter_hpp_included__
#define __setter_hpp_included__

#include <QObject>

class QRegion;
class QTransform;
class PropSet;
class WordList;

class Setter : public QObject
{
  Q_OBJECT

public:
  Setter(QObject* parent = 0);

  virtual void init(const WordList& words) = 0;

  virtual void apply(PropSet& word,
		     QTransform& transform,
		     QRegion& filledArea) = 0;
};

#endif
