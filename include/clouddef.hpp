#ifndef __clouddef_hpp_included__
#define __clouddef_hpp_included__

#include <QList>
#include "../include/propset.hpp"

typedef QList<PropSet*> WordList;

class CloudDef : public PropSet
{
  Q_OBJECT

public:
  static CloudDef* create(const QString& iniFile, QObject* parent = 0);

  CloudDef(QSettings& initFrom, QObject* parent = 0);

  const WordList& words() const
  {
    return _words;
  }

private:
  WordList _words;
};

#endif
