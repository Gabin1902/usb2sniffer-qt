#include "usbpacket.h"

USBPacket::USBPacket(const quint64 timestamp,
                     const quint8 pid,
                     const quint8 dev,
                     const quint8 endpoint,
                     const quint16 crc,
                     const quint16 frameNumber,
                     const quint32 dataLen,
                     const QByteArray &data)
{

    m_Timestamp = timestamp;
    m_Pid = pid;
    m_Dev = dev;
    m_Endpoint = endpoint;
    m_CRC = crc;
    m_FrameNumber = frameNumber;
    m_DataLen = dataLen;
    m_Data = data;
}

const QVector<QString> USBPacket::pidStr = {
    "RESERVED",
    "OUT",
    "ACK",
    "DATA0",
    "PING",
    "SOF",
    "NYET",
    "DATA2",
    "SPLIT",
    "IN",
    "NAK",
    "DATA1",
    "ERR/PRE",
    "SETUP",
    "STALL",
    "MDATA"
};

QString USBPacket::getPidStr()
{
    return pidStr[(m_Pid & 0xf)];
}