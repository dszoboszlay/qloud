#ifndef __factory_hpp_included__
#define __factory_hpp_included__

#include <QHash>
#include <QString>

template <class T>
class Factory
{
public:
  Factory(const T& defaultValue) :
    _default(defaultValue)
  {}

  T get() const
  {
    return _default;
  }

  T get(const QString& value) const
  {
    return _options.value(value, _default);
  }

  void set(const QString& key, const T& value) const
  {
    _options.store(key, value);
  }

private:
  T _default;
  QHash<QString, T> _options;
};

#endif
