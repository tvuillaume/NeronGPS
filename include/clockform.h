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

#ifndef CLOCKFORM_H
#define CLOCKFORM_H

#include <QTimer>
#include <QDateTime>

#include "ui_clockform.h"

class TClockForm : public QWidget
{
	Q_OBJECT

	public:
		TClockForm(QWidget *parent = 0, Qt::WFlags f = 0);
		virtual ~TClockForm();
		
	public slots:
		void slotClock(QDateTime time);
		void slotTimer();

	private:
		Ui::ClockForm ui;

		QTimer _timer;
		QDateTime _lastGPSTime;
		QTime _lastGPSTimeValidity;
};

#endif
