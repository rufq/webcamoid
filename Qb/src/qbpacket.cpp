/* Webcamod, webcam capture plasmoid.
 * Copyright (C) 2011-2013  Gonzalo Exequiel Pedone
 *
 * Webcamod is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Webcamod is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Webcamod. If not, see <http://www.gnu.org/licenses/>.
 *
 * Email     : hipersayan DOT x AT gmail DOT com
 * Web-Site 1: http://github.com/hipersayanX/Webcamoid
 * Web-Site 2: http://kde-apps.org/content/show.php/Webcamoid?content=144796
 */

#include "qbpacket.h"

QbPacket::QbPacket(QObject *parent): QObject(parent)
{
    this->resetCaps();
    this->resetBuffer();
    this->resetBufferSize();
    this->resetPts();
    this->resetDuration();
    this->resetTimeBase();
    this->resetIndex();
}

QbPacket::QbPacket(const QbCaps &caps,
                   const QbBufferPtr &buffer,
                   ulong bufferSize,
                   int64_t pts,
                   int duration,
                   const QbFrac &timeBase,
                   int index)
{
    this->setCaps(caps);
    bool isValid = this->caps().isValid();
    this->setBuffer(isValid? buffer: QbBufferPtr());
    this->setBufferSize(isValid? bufferSize: 0);
    this->setPts(isValid? pts: 0);
    this->setDuration(isValid? duration: 0);
    this->setTimeBase(isValid? timeBase: QbFrac());
    this->setIndex(isValid? index: -1);
}

QbPacket::QbPacket(const QbPacket &other):
    QObject(other.parent()),
    m_caps(other.m_caps),
    m_data(other.m_data),
    m_buffer(other.m_buffer),
    m_bufferSize(other.m_bufferSize),
    m_pts(other.m_pts),
    m_duration(other.m_duration),
    m_timeBase(other.m_timeBase),
    m_index(other.m_index)
{
}

QbPacket::~QbPacket()
{
}

QbPacket &QbPacket::operator =(const QbPacket &other)
{
    if (this != &other)
    {
        this->m_caps = other.m_caps;
        this->m_data = other.m_data;
        this->m_buffer = other.m_buffer;
        this->m_bufferSize = other.m_bufferSize;
        this->m_pts = other.m_pts;
        this->m_duration = other.m_duration;
        this->m_timeBase = other.m_timeBase;
        this->m_index = other.m_index;
    }

    return *this;
}

QString QbPacket::toString() const
{
    QString packetInfo;
    QDebug debug(&packetInfo);

    debug.nospace() << "Caps       : "
                    << this->caps().toString().toStdString().c_str()
                    << "\n";

    debug.nospace() << "Data       : "
                    << this->data()
                    << "\n";

    debug.nospace() << "Buffer Size: "
                    << this->bufferSize()
                    << "\n";

    debug.nospace() << "Pts        : "
                    << this->pts() * this->timeBase().value()
                    << "\n";

    debug.nospace() << "Duration   : "
                    << this->duration() * this->timeBase().value()
                    << "\n";

    debug.nospace() << "Time Base  : "
                    << this->timeBase().toString().toStdString().c_str()
                    << "\n";

    debug.nospace() << "Index      : "
                    << this->index();

    return packetInfo;
}

QbCaps QbPacket::caps() const
{
    return this->m_caps;
}

QVariant QbPacket::data() const
{
    return this->m_data;
}

QbBufferPtr QbPacket::buffer() const
{
    return this->m_buffer;
}

ulong QbPacket::bufferSize() const
{
    return this->m_bufferSize;
}

int64_t QbPacket::pts() const
{
    return this->m_pts;
}

int QbPacket::duration() const
{
    return this->m_duration;
}

QbFrac QbPacket::timeBase() const
{
    return this->m_timeBase;
}

int QbPacket::index() const
{
    return this->m_index;
}

void QbPacket::setCaps(const QbCaps &mimeType)
{
    this->m_caps = mimeType;
}

void QbPacket::setData(const QVariant &data)
{
    this->m_data = data;
}

void QbPacket::setBuffer(const QbBufferPtr &buffer)
{
    this->m_buffer = buffer;
}

void QbPacket::setBufferSize(ulong bufferSize)
{
    this->m_bufferSize = bufferSize;
}

void QbPacket::setPts(int64_t pts)
{
    this->m_pts = pts;
}

void QbPacket::setDuration(int duration)
{
    this->m_duration = duration;
}

void QbPacket::setTimeBase(const QbFrac &timeBase)
{
    this->m_timeBase = timeBase;
}

void QbPacket::setIndex(int index)
{
    this->m_index = index;
}

void QbPacket::resetCaps()
{
    this->setCaps(QbCaps());
}

void QbPacket::resetData()
{
    this->setData(QVariant());
}

void QbPacket::resetBuffer()
{
    this->setBuffer(QbBufferPtr());
}

void QbPacket::resetBufferSize()
{
    this->setBufferSize(0);
}

void QbPacket::resetPts()
{
    this->setPts(0);
}

void QbPacket::resetDuration()
{
    this->setDuration(0);
}

void QbPacket::resetTimeBase()
{
    this->setTimeBase(QbFrac());
}

void QbPacket::resetIndex()
{
    this->setIndex(-1);
}

QDebug operator <<(QDebug debug, const QbPacket &packet)
{
    debug.nospace() << packet.toString().toStdString().c_str();

    return debug.space();
}