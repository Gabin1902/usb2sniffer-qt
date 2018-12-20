#ifndef USBITEM_H
#define USBITEM_H

#include <QList>
#include <QString>
#include <QVector>
#include <QBrush>
#include <QFont>

#include "usbrecord.h"

class USBItem
{
public:
    explicit USBItem(USBRecord* record, USBItem *parentItem = nullptr);
    ~USBItem();

    void appendChild(USBItem *child);
    USBItem *child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant headerData(int column) const;
    int row() const;
    USBItem *parentItem();

    QVariant data(int column) const;
    QBrush background() const;
    QFont font(int column) const;
    const QString asciiData();
    const QString asciiPacket();
    const QString details();

private:
    QList<USBItem*> m_childItems;
    USBItem *m_parentItem;
    USBRecord *m_record;
};

#endif // USBITEM_H
