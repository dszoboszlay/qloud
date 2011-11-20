#include "../include/common.hpp"
#include "../include/propset.hpp"

PropSet::PropSet(const QSettings& settings, QObject* parent) :
  QObject(parent)
{
  foreach (const QString& propName, settings.childKeys())
    setProperty(propName.toUtf8(), settings.value(propName));
}
