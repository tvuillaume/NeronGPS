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

#ifndef TILEHTTPWHEEL_H
#define TILEHTTPWHEEL_H

#include <QObject>
#include <QHttp>
#include <QMutex>
#include <QFile>

#include "include/tilehttp.h"
#include "include/settings.h"
#include "include/tileref.h"
#include "include/tiletransaction.h"

class TTileHttpWheel : public QObject
{
	Q_OBJECT
	public:
		TTileHttpWheel();
		~TTileHttpWheel();

		void configure(TSettings &settings, const QString &section, const QString type);
		void load(TTileTransaction *trans);

		const QString &name() const { return _name; }

	signals:
		void signalNewTile(TTileTransaction *trans);

	public slots:
		void slotNewTile(TTileTransaction *trans);

	private:
		QString _name;
		QList<TTileHttp *> _servers;
		int _next;
};

#endif

