#ifndef __factory_hpp_included__
#define __factory_hpp_included__

#include <QHash>
#include <QString>

template <class T>
class Factory
{
public:
  Factory(const char* name, const T& defaultValue) :
    _name(name),
    _default(defaultValue)
  {}

  Factory(const Factory<T>& orig, const T& defaultValue) :
    _name(orig._name),
    _default(defaultValue),
    _options(orig._options)
  {}

  const char* name() const
  {
    return _name;
  }

  T get() const
  {
    return _default;
  }

  T get(const QString& value) const
  {
    return _options.value(value, _default);
  }

  void set(const QString& key, const T& value)
  {
    _options.insert(key, value);
  }

private:
  const char* _name;
  T _default;
  QHash<QString, T> _options;
};

#endif
