/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -i QtGui/private/qspi_struct_marshallers_p.h -p bus_interface.h:bus_interface.cpp /home/qt/work/qt/qtbase/src/gui/accessible/linux/dbusxml/Bus.xml
 *
 * qdbusxml2cpp is Copyright (C) The Qt Company Ltd. and other contributors.
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef BUS_INTERFACE_H
#define BUS_INTERFACE_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>
#include "QtGui/private/qspi_struct_marshallers_p.h"

/*
 * Proxy class for interface org.a11y.Bus
 */
class OrgA11yBusInterface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.a11y.Bus"; }

public:
    OrgA11yBusInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = nullptr);

    ~OrgA11yBusInterface();

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<QString> GetAddress()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("GetAddress"), argumentList);
    }

Q_SIGNALS: // SIGNALS
};

/*
 * Proxy class for interface org.a11y.Status
 */
class OrgA11yStatusInterface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.a11y.Status"; }

public:
    OrgA11yStatusInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = nullptr);

    ~OrgA11yStatusInterface();

    Q_PROPERTY(bool IsEnabled READ isEnabled WRITE setIsEnabled)
    inline bool isEnabled() const
    { return qvariant_cast< bool >(property("IsEnabled")); }
    inline void setIsEnabled(bool value)
    { setProperty("IsEnabled", QVariant::fromValue(value)); }

    Q_PROPERTY(bool ScreenReaderEnabled READ screenReaderEnabled WRITE setScreenReaderEnabled)
    inline bool screenReaderEnabled() const
    { return qvariant_cast< bool >(property("ScreenReaderEnabled")); }
    inline void setScreenReaderEnabled(bool value)
    { setProperty("ScreenReaderEnabled", QVariant::fromValue(value)); }

public Q_SLOTS: // METHODS
Q_SIGNALS: // SIGNALS
};

namespace org {
  namespace a11y {
    using Bus = ::OrgA11yBusInterface;
    using Status = ::OrgA11yStatusInterface;
  }
}
#endif
