#ifndef __propset_hpp_included__
#define __propset_hpp_included__

#include <QObject>
#include <QVariant>

class QSettings;

class PropSet : public QObject
{
  Q_OBJECT

public:
  PropSet(QObject* parent = 0) : QObject(parent)
  {
  }

  PropSet(const QSettings& initFrom, QObject* parent = 0);

  template <class T>
  T get(const char* propName, T defaultValue) const
  {
    QVariant prop(property(propName));
    if (prop.isValid() && prop.canConvert<T>())
      return prop.value<T>();

    return defaultValue;
  }

  template <class T, class F>
  T getIndirect(const char* propName, const F& factory) const
  {
    QVariant prop(property(propName));
    if (prop.isValid() && prop.canConvert<QString>())
      return factory.get(prop.value<QString>());

    return factory.get();
  }
};

#endif
