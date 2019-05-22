/* Webcamoid, webcam capture application.
 * Copyright (C) 2016  Gonzalo Exequiel Pedone
 *
 * Webcamoid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Webcamoid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Webcamoid. If not, see <http://www.gnu.org/licenses/>.
 *
 * Web-Site: http://webcamoid.github.io/
 */

#ifndef MULTISRCELEMENTSETTINGS_H
#define MULTISRCELEMENTSETTINGS_H

#include <QObject>

class MultiSrcElementSettings: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString codecLib
               READ codecLib
               WRITE setCodecLib
               RESET resetCodecLib
               NOTIFY codecLibChanged)
    Q_PROPERTY(QStringList subModules
               READ subModules
               NOTIFY subModulesChanged)

    public:
        MultiSrcElementSettings(QObject *parent=nullptr);

        Q_INVOKABLE QString codecLib() const;
        Q_INVOKABLE QStringList subModules() const;

    signals:
        void codecLibChanged(const QString &codecLib);
        void subModulesChanged(const QStringList &subModules);

    public slots:
        void setCodecLib(const QString &codecLib);
        void resetCodecLib();
};

#endif // MULTISRCELEMENTSETTINGS_H
