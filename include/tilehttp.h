/*
 * Copyright 2009, 2010 Thierry Vuillaume
 *
 * This file is part of NeronGPS.
 *
 * NeronGPS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * NeronGPS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with NeronGPS.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef TILEHTTP_H
#define TILEHTTP_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QMutex>
#include <QBuffer>

#include "include/tileref.h"
#include "include/tiletransaction.h"
#include "include/settings.h"

class TTileHttp : public QNetworkAccessManager
{
	Q_OBJECT
	public:
		TTileHttp();
		~TTileHttp();

		void setServer(TSettings &settings, const QString &section, const QString &serverURL);
		void load(TTileTransaction *trans);

	signals:
		void signalNewTile(TTileTransaction *trans);

	public slots:
		void slotFinished(QNetworkReply *reply);

	private:
		QMutex _mutex;
		QList<TTileTransaction *> _transactions;

		QString _template;
		int _rootLevel;
		bool _equatorCentric;
		bool _snailMode;

		QString getURL(const TTileRef &ref);

		static bool checkSignature(const QByteArray &data);
		static bool checkPNG(const QByteArray &data);
		static bool checkJPG(const QByteArray &data);
};

#endif

