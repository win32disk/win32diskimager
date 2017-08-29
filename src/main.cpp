/**********************************************************************
 *  This program is free software; you can redistribute it and/or     *
 *  modify it under the terms of the GNU General Public License       *
 *  as published by the Free Software Foundation; either version 2    *
 *  of the License, or (at your option) any later version.            *
 *                                                                    *
 *  This program is distributed in the hope that it will be useful,   *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of    *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the     *
 *  GNU General Public License for more details.                      *
 *                                                                    *
 *  You should have received a copy of the GNU General Public License *
 *  along with this program; if not, see http://gnu.org/licenses/     *
 *  ---                                                               *
 *  Copyright (C) 2009, Justin Davis <tuxdavis@gmail.com>             *
 *  Copyright (C) 2009-2017 ImageWriter developers                    *
 *                 https://sourceforge.net/projects/win32diskimager/  *
 **********************************************************************/

#ifndef WINVER
#define WINVER 0x0601
#endif

#include <QApplication>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include <winioctl.h>
#include "disk.h"
#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationDisplayName(VER);
    app.setAttribute(Qt::AA_UseDesktopOpenGL);
    app.setAttribute(Qt::AA_EnableHighDpiScaling);

    QTranslator translator;
    translator.load("translations/diskimager_" + QLocale::system().name());
    app.installTranslator(&translator);

    MainWindow* mainwindow = MainWindow::getInstance();
    mainwindow->show();
    return app.exec();
}
