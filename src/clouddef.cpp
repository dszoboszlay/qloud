#include "../include/common.hpp"
#include "../include/clouddef.hpp"

CloudDef* CloudDef::create(const QString& iniFile, QObject* parent)
{
  QSettings ini(iniFile, QSettings::IniFormat);
  ini.setIniCodec(QTextCodec::codecForName("UTF-8"));

  return new CloudDef(ini, parent);
}

CloudDef::CloudDef(QSettings& settings, QObject* parent) :
  PropSet(settings, parent)
{
  foreach (const QString& group, settings.childGroups()) {
    settings.beginGroup(group);
    _words << new PropSet(settings, this);
    settings.endGroup();
  }
}
