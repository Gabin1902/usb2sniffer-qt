#include "usbproxy.h"
#include "usbitem.h"

USBProxy::USBProxy(QObject *parent)
    : QSortFilterProxyModel (parent)
{
    setRecursiveFilteringEnabled(true);
}

void USBProxy::setFilter(const USBProxyFilter *filter)
{
    m_filter = filter;
    invalidateFilter();
}

bool USBProxy::filterAcceptsRow(int sourceRow,
        const QModelIndex &sourceParent) const
{
    QModelIndex index = sourceModel()->index(sourceRow, RECORD_NAME, sourceParent);

    if (!m_filter) {
        return true;
    }

    /* Search inside record name: SOF */

    if (sourceModel()->data(index).toString().contains("SOF")) { // FIXME check pid type instead of string matching
        return m_filter->sof;
    }

    /* Search inside record name: SPLIT */

    if (sourceModel()->data(index).toString().contains("SPLIT")) { // FIXME check pid type instead of string matching
        return true; // XXX FIXME SPLIT filter not yet implemented
    }

    /* Search inside record status */

    /* Accept if parent transaction is selected */

    if (sourceParent.isValid()) {
        USBItem *item = static_cast<USBItem*>(sourceParent.internalPointer());
        QString status = item->data(RECORD_STATUS).toString();
        if (status.contains("NAK") || status.contains("Incomplete")) {
            if (item->data(RECORD_NAME).toString().contains("IN")) {
                return m_filter->nakIn;
            } else if (item->data(RECORD_NAME).toString().contains("OUT")) {
                return m_filter->nakOut;
            } else if (item->data(RECORD_NAME).toString().contains("SETUP")) {
                return m_filter->nakSetup;
            } else {
                return true;
            }
        } else {
            return true;
        }
    }

    return false;
}
