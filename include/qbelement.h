/* Webcamod, webcam capture plasmoid.
 * Copyright (C) 2011-2012  Gonzalo Exequiel Pedone
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

#ifndef QBELEMENT_H
#define QBELEMENT_H

#include "qbpacket.h"

/// Plugin template.
class QbElement: public QObject
{
    Q_OBJECT
    Q_ENUMS(ElementState)
    Q_PROPERTY(ElementState state READ state WRITE setState RESET resetState)
    Q_PROPERTY(QList<QbElement *> srcs READ srcs WRITE setSrcs RESET resetSrcs)
    Q_PROPERTY(QList<QbElement *> sinks READ sinks WRITE setSinks RESET resetSinks)

    public:
        enum ElementState
        {
            ElementStateNull,
            ElementStateReady,
            ElementStatePaused,
            ElementStatePlaying
        };

        Q_INVOKABLE virtual ElementState state() = 0;
        Q_INVOKABLE virtual QList<QbElement *> srcs() = 0;
        Q_INVOKABLE virtual QList<QbElement *> sinks() = 0;

    protected:
        ElementState m_state;
        QList<QbElement *> m_srcs;
        QList<QbElement *> m_sinks;

    signals:
        void oStream(const QbPacket &packet);

    public slots:
        virtual void iStream(const QbPacket &packet) = 0;
        virtual void setState(ElementState state) = 0;
        virtual void setSrcs(QList<QbElement *> srcs) = 0;
        virtual void setSinks(QList<QbElement *> sinks) = 0;
        virtual void resetState() = 0;
        virtual void resetSrcs() = 0;
        virtual void resetSinks() = 0;
};

#endif // QBELEMENT_H
