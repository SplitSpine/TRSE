/*
 * Turbo Rascal Syntax error, “;” expected but “BEGIN” (TRSE, Turbo Rascal SE)
 * 8 bit software development IDE for the Commodore 64
 * Copyright (C) 2018  Nicolaas Ervik Groeneboom (nicolaas.groeneboom@gmail.com)
 *
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program (LICENSE.txt).
 *   If not, see <https://www.gnu.org/licenses/>.
*/


#include "mainwindow.h"
#include <QApplication>
#include <QStyleFactory>

void ConvertPerlin(QString input, QString out, float div) {
    QImage img;
    img.load(input);

    QByteArray a;
    int xw = img.width()/div;
    int xh = img.height()/div;
    a.resize(xw*xh);

    qDebug() << xw;
//    qDebug() << "Converting file: " << xw;

    for (int x=0;x<xw;x++)
        for (int y=0;y<xh;y++) {

            a[x + y*xw]=QColor(img.pixel(x*div, y*div)).red();
//            if (rand()%100>98)
  //              qDebug() << a[x + y*xw];
        }

    QFile f(out);
    f.open(QFile::WriteOnly);
    f.write(a);
    f.close();
}


void CreateBinaryFile(QString fn) {
    QFile f(fn);
    f.open(QFile::WriteOnly);

    uchar data[] = {
       212, 203, 195, 183, 0, 0, 0, 0, 0, 0, 0, 1, 219, 0, 0, 0, 0, 1, 0, 0, 219, 0, 1, 0, 235, 232, 183, 0, 0, 0, 0, 0, 0, 0, 0, 0, 219, 0, 0, 0, 0, 0, 1, 0, 0, 212, 203, 195, 183, 0, 0, 0, 0, 0, 0, 0, 183, 0, 1, 0, 219, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 225, 231, 235, 225, 231, 235, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 225, 231, 235, 225, 1, 0, 0, 0, 0, 0, 0, 0, 225, 228, 233, 225, 1, 0, 0, 0, 0, 0, 0, 225, 228, 1, 0, 225, 231, 235, 225, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 221, 219, 0, 1, 227, 225, 0, 0, 0, 0, 0, 0, 229, 228, 0, 0, 232, 231, 0, 0, 0, 0, 1, 0, 232, 233, 235, 0, 0, 0, 0, 0, 0, 0, 236, 235, 233, 235, 236, 235, 232, 231, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0
       ,0, 0, 0, 1, 219, 0, 1, 0, 235, 232, 183, 0, 0, 0, 0, 0, 0, 0, 1, 0, 219, 0, 0, 0, 0, 0, 0, 1, 183, 0, 1, 0, 217, 209, 201, 191, 0, 0, 0, 0, 0, 0, 0, 1, 223, 0, 0, 0, 0, 1, 0, 0, 223, 0, 1, 0, 235, 232, 191, 0, 0, 0, 0, 0, 231, 235, 1, 0, 0, 0, 0, 0, 225, 231, 235, 225, 231, 235, 1, 0, 225, 228, 233, 225, 228, 233, 225, 228, 233, 225, 228, 233, 1, 0, 0, 0, 228, 233, 237, 228, 233, 237, 1, 0, 0, 0, 0, 0, 228, 233, 237, 228, 233, 237, 1, 0, 0, 0, 0, 0, 228, 233, 237, 228, 233, 237, 228, 233, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 228, 229, 231, 0, 0, 0, 0, 0, 1, 0, 0, 0, 229, 228, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0, 239, 1, 0, 0, 239, 0, 1, 0, 239, 1, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0
        ,0, 0, 0, 0, 223, 0, 0, 0, 0, 0, 1, 0, 0, 219, 215, 209, 207, 0, 0, 0, 0, 0, 0, 0, 207, 0, 1, 0, 231, 0, 0, 0, 0, 0, 0, 1, 231, 0, 1, 0, 235, 232, 207, 0, 0, 0, 0, 0, 0, 0, 1, 0, 231, 0, 0, 0, 0, 0, 0, 1, 207, 0, 1, 0, 237, 228, 233, 237, 1, 0, 0, 0, 0, 0, 0, 0, 223, 228, 236, 223, 228, 236, 223, 228, 236, 223, 1, 0, 223, 228, 1, 0, 223, 228, 237, 223, 228, 237, 1, 0, 0, 0, 0, 0, 223, 228, 237, 223, 228, 237, 1, 0, 223, 228, 236, 223, 228, 236, 223, 228, 236, 1, 0, 0, 0, 0, 0, 0, 227, 225, 0, 0, 221, 219, 0, 0, 0, 0, 1, 0, 225, 227, 228, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 229, 1, 232, 231, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 229, 228, 0, 0, 0, 1, 0, 0, 227, 225, 0, 0, 221, 219, 0, 0, 0, 0, 1, 0, 217, 215, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 0, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0, 239, 1, 0, 0, 239, 0, 1, 0, 239, 1, 0, 0, 239, 1, 0, 0
        ,212, 203, 195, 183, 0, 0, 0, 0, 0, 0, 0, 1, 219, 0, 0, 0, 0, 1, 0, 0, 219, 0, 1, 0, 235, 232, 183, 0, 0, 0, 0, 0, 0, 0, 0, 0, 219, 0, 0, 0, 0, 0, 1, 0, 0, 212, 203, 195, 183, 0, 0, 0, 0, 0, 0, 0, 183, 0, 1, 0, 219, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 225, 231, 235, 225, 231, 235, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 225, 231, 235, 225, 1, 0, 0, 0, 0, 0, 0, 0, 225, 228, 233, 225, 1, 0, 0, 0, 0, 0, 0, 225, 228, 1, 0, 225, 231, 235, 225, 227, 228, 0, 0, 0, 0, 0, 0, 229, 228, 227, 228, 227, 225, 0, 0, 0, 0, 0, 0, 221, 219, 0, 0, 0, 0, 217, 215, 212, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0
        ,0, 0, 0, 1, 219, 0, 1, 0, 235, 232, 183, 0, 0, 0, 0, 0, 0, 0, 1, 0, 219, 0, 0, 0, 0, 0, 0, 1, 183, 0, 1, 0, 217, 209, 201, 191, 0, 0, 0, 0, 0, 0, 0, 1, 223, 0, 0, 0, 0, 1, 0, 0, 223, 0, 1, 0, 235, 232, 191, 0, 0, 0, 0, 0, 231, 235, 1, 0, 0, 0, 0, 0, 225, 231, 235, 225, 231, 235, 1, 0, 225, 228, 233, 225, 228, 233, 225, 228, 233, 225, 228, 233, 1, 0, 0, 0, 228, 233, 237, 228, 233, 237, 1, 0, 0, 0, 0, 0, 228, 233, 237, 228, 233, 237, 1, 0, 0, 0, 0, 0, 228, 233, 237, 228, 233, 237, 228, 233, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0, 239, 1, 0, 0, 239, 0, 1, 0, 239, 1, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0
        ,0, 0, 0, 0, 223, 0, 0, 0, 0, 0, 1, 0, 0, 219, 215, 209, 207, 0, 0, 0, 0, 0, 0, 0, 207, 0, 1, 0, 231, 0, 0, 0, 0, 0, 0, 1, 231, 0, 1, 0, 235, 232, 207, 0, 0, 0, 0, 0, 0, 0, 1, 0, 231, 0, 0, 0, 0, 0, 0, 1, 207, 0, 1, 0, 237, 228, 233, 237, 1, 0, 0, 0, 0, 0, 0, 0, 223, 228, 236, 223, 228, 236, 223, 228, 236, 223, 1, 0, 223, 228, 1, 0, 223, 228, 237, 223, 228, 237, 1, 0, 0, 0, 0, 0, 223, 228, 237, 223, 228, 237, 1, 0, 223, 228, 236, 223, 228, 236, 223, 228, 236, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 0, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0, 239, 1, 0, 0, 239, 0, 1, 0, 239, 1, 0, 0, 239, 1, 0, 0
        ,0, 0, 0, 0, 223, 0, 0, 0, 0, 0, 1, 0, 0, 225, 219, 212, 207, 0, 0, 0, 0, 0, 0, 0, 207, 0, 1, 0, 231, 0, 0, 0, 0, 0, 0, 1, 231, 0, 1, 0, 235, 232, 207, 0, 0, 0, 0, 0, 0, 0, 1, 0, 231, 0, 0, 0, 0, 0, 0, 1, 207, 0, 1, 0, 237, 228, 233, 237, 1, 0, 0, 0, 0, 0, 0, 0, 223, 228, 236, 223, 228, 236, 223, 228, 236, 223, 1, 0, 223, 228, 1, 0, 223, 228, 237, 223, 228, 237, 1, 0, 0, 0, 0, 0, 223, 228, 237, 223, 228, 237, 1, 0, 223, 228, 236, 223, 228, 236, 223, 228, 236, 1, 0, 0, 0, 0, 0, 0, 227, 225, 0, 0, 221, 219, 0, 0, 0, 0, 1, 0, 225, 227, 228, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 229, 1, 232, 231, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 229, 228, 0, 0, 0, 1, 0, 0, 227, 225, 0, 0, 229, 228, 0, 0, 0, 0, 1, 0, 232, 231, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 0, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0, 239, 1, 0, 0, 239, 0, 1, 0, 239, 1, 0, 0, 239, 1, 0, 0
        ,0, 0, 0, 0, 223, 0, 0, 0, 0, 0, 1, 0, 0, 225, 219, 212, 207, 0, 0, 0, 0, 0, 0, 0, 235, 232, 207, 1, 225, 219, 212, 159, 0, 0, 0, 0, 0, 0, 1, 0, 235, 232, 175, 0, 0, 0, 0, 0, 0, 0, 1, 0, 235, 232, 179, 0, 0, 0, 0, 1, 235, 232, 1, 0, 237, 228, 233, 237, 1, 0, 0, 0, 0, 0, 0, 0, 223, 228, 236, 223, 228, 236, 223, 228, 236, 223, 1, 0, 223, 228, 1, 0, 223, 228, 237, 223, 228, 237, 1, 0, 0, 0, 0, 0, 223, 228, 237, 223, 228, 237, 1, 0, 0, 0, 0, 0, 223, 228, 236, 223, 228, 236, 223, 228, 236, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 225, 0, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0, 225, 0, 0, 1
        ,212, 203, 195, 183, 0, 0, 0, 0, 0, 0, 0, 1, 219, 0, 0, 0, 0, 1, 0, 0, 219, 0, 1, 0, 235, 232, 183, 0, 0, 0, 0, 0, 0, 0, 0, 0, 219, 0, 0, 0, 0, 0, 1, 0, 0, 212, 203, 195, 183, 0, 0, 0, 0, 0, 0, 0, 183, 0, 1, 0, 219, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 225, 231, 235, 225, 231, 235, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 225, 231, 235, 225, 1, 0, 0, 0, 0, 0, 0, 0, 225, 228, 233, 225, 1, 0, 0, 0, 0, 0, 0, 225, 228, 1, 0, 225, 231, 235, 225, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 221, 219, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 227, 225, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 229, 228, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 228, 229, 231, 0, 0, 0, 0, 0, 0, 1, 0, 0, 229, 228, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0
        ,0, 0, 0, 1, 219, 0, 1, 0, 235, 232, 183, 0, 0, 0, 0, 0, 0, 0, 1, 0, 219, 0, 0, 0, 0, 0, 0, 1, 183, 0, 1, 0, 217, 209, 201, 191, 0, 0, 0, 0, 0, 0, 0, 1, 223, 0, 0, 0, 0, 1, 0, 0, 223, 0, 1, 0, 235, 232, 191, 0, 0, 0, 0, 0, 231, 235, 1, 0, 0, 0, 0, 0, 225, 231, 235, 225, 231, 235, 1, 0, 225, 228, 233, 225, 228, 233, 225, 228, 233, 225, 228, 233, 1, 0, 0, 0, 228, 233, 237, 228, 233, 237, 1, 0, 0, 0, 0, 0, 228, 233, 237, 228, 233, 237, 1, 0, 0, 0, 0, 0, 228, 233, 237, 228, 233, 237, 228, 233, 0, 0, 0, 1, 227, 225, 0, 1, 229, 228, 0, 0, 0, 0, 0, 1, 227, 225, 0, 1, 221, 219, 0, 0, 0, 0, 0, 1, 217, 215, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 221, 219, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 209, 207, 0, 1, 217, 215, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0, 239, 1, 0, 0, 239, 0, 1, 0, 239, 1, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0
        ,0, 0, 0, 0, 223, 0, 0, 0, 0, 0, 1, 0, 0, 225, 219, 212, 207, 0, 0, 0, 0, 0, 0, 0, 207, 0, 1, 0, 231, 0, 0, 0, 0, 0, 0, 1, 231, 0, 1, 0, 235, 232, 207, 0, 0, 0, 0, 0, 0, 0, 1, 0, 231, 0, 0, 0, 0, 0, 0, 1, 207, 0, 1, 0, 237, 228, 233, 237, 1, 0, 0, 0, 0, 0, 0, 0, 223, 228, 236, 223, 228, 236, 223, 228, 236, 223, 1, 0, 223, 228, 1, 0, 223, 228, 237, 223, 228, 237, 1, 0, 0, 0, 0, 0, 223, 228, 237, 223, 228, 237, 1, 0, 223, 228, 236, 223, 228, 236, 223, 228, 236, 1, 0, 0, 0, 0, 0, 0, 209, 207, 0, 1, 221, 219, 0, 0, 0, 0, 0, 1, 219, 217, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 219, 217, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 209, 207, 0, 1, 219, 217, 0, 0, 0, 0, 0, 1, 221, 219, 0, 1, 219, 221, 223, 0, 0, 0, 0, 0, 0, 221, 219, 217, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 0, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0, 239, 1, 0, 0, 239, 0, 1, 0, 239, 1, 0, 0, 239, 1, 0, 0
        ,212, 203, 195, 183, 0, 0, 0, 0, 0, 0, 0, 1, 219, 0, 0, 0, 0, 1, 0, 0, 219, 0, 1, 0, 235, 232, 183, 0, 0, 0, 0, 0, 0, 0, 0, 0, 219, 0, 0, 0, 0, 0, 1, 0, 0, 212, 203, 195, 183, 0, 0, 0, 0, 0, 0, 0, 183, 0, 1, 0, 219, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 225, 231, 235, 225, 231, 235, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 225, 231, 235, 225, 1, 0, 0, 0, 0, 0, 0, 0, 225, 228, 233, 225, 1, 0, 0, 0, 0, 0, 0, 225, 228, 1, 0, 225, 231, 235, 225, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 225, 223, 227, 225, 0, 0, 0, 0, 1, 0, 0, 0, 225, 223, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 217, 215, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 209, 207, 0, 0, 0, 0, 0, 0, 203, 201, 199, 1, 199, 195, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0
        ,0, 0, 0, 1, 219, 0, 1, 0, 235, 232, 183, 0, 0, 0, 0, 0, 0, 0, 1, 0, 219, 0, 0, 0, 0, 0, 0, 1, 183, 0, 1, 0, 217, 209, 201, 191, 0, 0, 0, 0, 0, 0, 0, 1, 223, 0, 0, 0, 0, 1, 0, 0, 223, 0, 1, 0, 235, 232, 191, 0, 0, 0, 0, 0, 231, 235, 1, 0, 0, 0, 0, 0, 225, 231, 235, 225, 231, 235, 1, 0, 225, 228, 233, 225, 228, 233, 225, 228, 233, 225, 228, 233, 1, 0, 0, 0, 228, 233, 237, 228, 233, 237, 1, 0, 0, 0, 0, 0, 228, 233, 237, 228, 233, 237, 1, 0, 0, 0, 0, 0, 228, 233, 237, 228, 233, 237, 228, 233, 0, 0, 0, 0, 203, 201, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 199, 195, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 201, 0, 203, 0, 207, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 209, 0, 207, 0, 203, 0, 207, 0, 209, 0, 207, 0, 203, 0, 207, 0, 209, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0, 239, 1, 0, 0, 239, 0, 1, 0, 239, 1, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0
        ,/*13*/0, 0, 0, 0, 223, 0, 0, 0, 0, 0, 1, 0, 0, 225, 219, 212, 207, 0, 0, 0, 0, 0, 0, 0, 207, 0, 1, 0, 231, 0, 0, 0, 0, 0, 0, 1, 231, 0, 1, 0, 235, 232, 207, 0, 0, 0, 0, 0, 0, 0, 1, 0, 231, 0, 0, 0, 0, 0, 0, 1, 207, 0, 1, 0, 237, 228, 233, 237, 1, 0, 0, 0, 0, 0, 0, 0, 223, 228, 236, 223, 228, 236, 223, 228, 236, 223, 1, 0, 223, 228, 1, 0, 223, 228, 237, 223, 228, 237, 1, 0, 0, 0, 0, 0, 223, 228, 237, 223, 228, 237, 1, 0, 223, 228, 236, 223, 228, 236, 223, 228, 236, 1, 0, 0, 0, 0, 0, 0, 0, 207, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 236, 219, 217, 0, 0, 0, 0, 0, 0, 0, 1, 0, 219, 217, 1, 0, 236, 219, 217, 0, 0, 0, 0, 0, 0, 1, 0, 0, 237, 221, 219, 0, 0, 0, 0, 0, 1, 0, 0, 0, 239, 225, 223, 0, 0, 0, 0, 0, 221, 219, 217, 1, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 0, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0, 239, 1, 0, 0, 239, 0, 1, 0, 239, 1, 0, 0, 239, 1, 0, 0
        ,212, 203, 195, 183, 0, 0, 0, 0, 0, 0, 0, 1, 219, 0, 0, 0, 0, 1, 0, 0, 219, 0, 1, 0, 235, 232, 183, 0, 0, 0, 0, 0, 0, 0, 0, 0, 219, 0, 0, 0, 0, 0, 1, 0, 0, 212, 203, 195, 183, 0, 0, 0, 0, 0, 0, 0, 183, 0, 1, 0, 219, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 225, 231, 235, 225, 231, 235, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 225, 231, 235, 225, 1, 0, 0, 0, 0, 0, 0, 0, 225, 228, 233, 225, 1, 0, 0, 0, 0, 0, 0, 225, 228, 1, 0, 225, 231, 235, 225, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 225, 223, 227, 225, 0, 0, 0, 0, 1, 0, 0, 0, 225, 223, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 227, 225, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 229, 228, 0, 0, 0, 0, 0, 0, 227, 0, 225, 1, 227, 225, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0
        ,0, 0, 0, 1, 219, 0, 1, 0, 235, 232, 183, 0, 0, 0, 0, 0, 0, 0, 1, 0, 219, 0, 0, 0, 0, 0, 0, 1, 183, 0, 1, 0, 217, 209, 201, 191, 0, 0, 0, 0, 0, 0, 0, 1, 223, 0, 0, 0, 0, 1, 0, 0, 223, 0, 1, 0, 235, 232, 191, 0, 0, 0, 0, 0, 231, 235, 1, 0, 0, 0, 0, 0, 225, 231, 235, 225, 231, 235, 1, 0, 225, 228, 233, 225, 228, 233, 225, 228, 233, 225, 228, 233, 1, 0, 0, 0, 228, 233, 237, 228, 233, 237, 1, 0, 0, 0, 0, 0, 228, 233, 237, 228, 233, 237, 1, 0, 0, 0, 0, 0, 228, 233, 237, 228, 233, 237, 228, 233, 0, 0, 0, 0, 229, 228, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 232, 231, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 232, 233, 235, 0, 0, 0, 0, 0, 233, 232, 231, 1, 232, 231, 0, 1, 236, 235, 0, 0, 0, 0, 0, 1, 232, 231, 0, 1, 235, 236, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0, 239, 1, 0, 0, 239, 0, 1, 0, 239, 1, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0
        ,0, 0, 0, 0, 223, 0, 0, 0, 0, 0, 1, 0, 0, 225, 219, 212, 207, 0, 0, 0, 0, 0, 0, 0, 207, 0, 1, 0, 231, 0, 0, 0, 0, 0, 0, 1, 231, 0, 1, 0, 235, 232, 207, 0, 0, 0, 0, 0, 0, 0, 1, 0, 231, 0, 0, 0, 0, 0, 0, 1, 207, 0, 1, 0, 237, 228, 233, 237, 1, 0, 0, 0, 0, 0, 0, 0, 223, 228, 236, 223, 228, 236, 223, 228, 236, 223, 1, 0, 223, 228, 1, 0, 223, 228, 237, 223, 228, 237, 1, 0, 0, 0, 0, 0, 223, 228, 237, 223, 228, 237, 1, 0, 223, 228, 236, 223, 228, 236, 223, 228, 236, 1, 0, 0, 0, 0, 0, 0, 236, 235, 0, 1, 232, 231, 0, 0, 0, 0, 0, 1, 229, 228, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 227, 225, 0, 1, 229, 228, 0, 0, 0, 0, 0, 1, 227, 225, 0, 1, 228, 229, 231, 0, 0, 0, 0, 0, 229, 228, 0, 1, 227, 225, 0, 0, 0, 0, 0, 0, 223, 221, 219, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 0, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0, 239, 1, 0, 0, 239, 0, 1, 0, 239, 1, 0, 0, 239, 1, 0, 0
        ,227, 221, 215, 209, 0, 0, 0, 0, 0, 0, 0, 1, 232, 0, 0, 0, 0, 1, 0, 0, 232, 0, 1, 0, 235, 232, 209, 0, 0, 0, 0, 0, 0, 0, 0, 0, 232, 0, 0, 0, 0, 0, 1, 0, 0, 223, 217, 209, 201, 0, 0, 0, 0, 0, 0, 0, 201, 0, 1, 0, 228, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 225, 232, 237, 225, 232, 237, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 225, 232, 237, 225, 1, 0, 0, 0, 0, 0, 0, 0, 225, 232, 237, 225, 1, 0, 0, 0, 0, 0, 0, 225, 228, 1, 0, 225, 232, 237, 225, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 209, 207, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 217, 215, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 221, 219, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 227, 225, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 225, 223, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0
        ,0, 0, 0, 1, 228, 0, 1, 0, 235, 232, 201, 0, 0, 0, 0, 0, 0, 0, 1, 0, 195, 0, 0, 0, 0, 0, 0, 1, 225, 0, 1, 0, 217, 209, 201, 191, 0, 0, 0, 0, 0, 0, 0, 1, 223, 0, 0, 0, 0, 1, 0, 0, 223, 0, 1, 0, 235, 232, 191, 0, 0, 0, 0, 0, 232, 237, 1, 0, 0, 0, 0, 0, 225, 232, 237, 225, 232, 237, 1, 0, 225, 232, 237, 225, 232, 237, 225, 232, 237, 225, 232, 237, 1, 0, 0, 0, 228, 233, 237, 228, 233, 237, 1, 0, 0, 0, 0, 0, 228, 233, 237, 228, 233, 237, 1, 0, 0, 0, 0, 0, 228, 233, 237, 228, 233, 237, 228, 233, 0, 0, 0, 0, 1, 227, 225, 0, 0, 0, 0, 1, 0, 0, 0, 0, 228, 229, 231, 0, 0, 0, 0, 0, 1, 0, 0, 0, 231, 229, 228, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 229, 0, 228, 0, 227, 0, 228, 0, 229, 0, 228, 0, 227, 0, 228, 0, 229, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0, 239, 1, 0, 0, 239, 0, 1, 0, 239, 1, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0
        ,0, 0, 0, 0, 223, 0, 0, 0, 0, 0, 1, 0, 0, 219, 215, 209, 207, 0, 0, 0, 0, 0, 0, 0, 231, 0, 1, 0, 219, 215, 209, 159, 0, 0, 0, 0, 0, 0, 1, 0, 235, 232, 175, 0, 0, 0, 0, 0, 0, 0, 1, 0, 235, 232, 179, 0, 0, 0, 0, 1, 235, 232, 1, 0, 237, 228, 233, 237, 1, 0, 0, 0, 0, 0, 0, 0, 223, 228, 236, 223, 228, 236, 223, 228, 236, 223, 1, 0, 223, 228, 1, 0, 223, 228, 236, 223, 228, 236, 1, 0, 0, 0, 0, 0, 223, 228, 237, 223, 228, 237, 1, 0, 0, 0, 0, 0, 228, 236, 239, 228, 236, 239, 228, 236, 239, 1, 0, 0, 0, 228, 0, 227, 1, 0, 0, 0, 0, 0, 0, 0, 236, 219, 217, 236, 219, 217, 236, 219, 217, 236, 1, 0, 217, 183, 1, 0, 236, 219, 217, 236, 219, 217, 1, 0, 0, 0, 0, 0, 237, 221, 219, 237, 221, 219, 1, 0, 0, 0, 0, 0, 239, 225, 223, 239, 225, 223, 239, 225, 223, 1, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 0, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0, 225, 0, 0, 1
        ,212, 203, 195, 183, 0, 0, 0, 0, 0, 0, 0, 1, 219, 0, 0, 0, 0, 1, 0, 0, 219, 0, 1, 0, 235, 232, 183, 0, 0, 0, 0, 0, 0, 0, 0, 0, 219, 0, 0, 0, 0, 0, 1, 0, 0, 212, 203, 195, 183, 0, 0, 0, 0, 0, 0, 0, 183, 0, 1, 0, 219, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 225, 231, 235, 225, 231, 235, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 225, 231, 235, 225, 1, 0, 0, 0, 0, 0, 0, 0, 225, 228, 233, 225, 1, 0, 0, 0, 0, 0, 0, 225, 228, 1, 0, 225, 231, 235, 225, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 225, 223, 227, 225, 0, 0, 0, 1, 225, 223, 0, 1, 227, 225, 0, 0, 0, 0, 0, 1, 229, 228, 0, 1, 232, 231, 0, 0, 0, 0, 0, 1, 236, 235, 0, 1, 238, 237, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 236, 235, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0
        ,212, 203, 195, 183, 0, 0, 0, 0, 0, 0, 0, 1, 219, 0, 0, 0, 0, 1, 0, 0, 219, 0, 1, 0, 235, 232, 183, 0, 0, 0, 0, 0, 0, 0, 0, 0, 219, 0, 0, 0, 0, 0, 1, 0, 0, 212, 203, 195, 183, 0, 0, 0, 0, 0, 0, 0, 183, 0, 1, 0, 219, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 225, 231, 235, 225, 231, 235, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 225, 231, 235, 225, 1, 0, 0, 0, 0, 0, 0, 0, 225, 228, 233, 225, 1, 0, 0, 0, 0, 0, 0, 225, 228, 1, 0, 225, 231, 235, 225, 227, 228, 0, 0, 0, 0, 0, 0, 229, 228, 227, 228, 227, 225, 0, 0, 0, 0, 0, 0, 221, 219, 0, 0, 0, 0, 217, 215, 212, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0
        ,0, 0, 0, 1, 219, 0, 1, 0, 235, 232, 183, 0, 0, 0, 0, 0, 0, 0, 1, 0, 219, 0, 0, 0, 0, 0, 0, 1, 183, 0, 1, 0, 217, 209, 201, 191, 0, 0, 0, 0, 0, 0, 0, 1, 223, 0, 0, 0, 0, 1, 0, 0, 223, 0, 1, 0, 235, 232, 191, 0, 0, 0, 0, 0, 231, 235, 1, 0, 0, 0, 0, 0, 225, 231, 235, 225, 231, 235, 1, 0, 225, 228, 233, 225, 228, 233, 225, 228, 233, 225, 228, 233, 1, 0, 0, 0, 228, 233, 237, 228, 233, 237, 1, 0, 0, 0, 0, 0, 228, 233, 237, 228, 233, 237, 1, 0, 0, 0, 0, 0, 228, 233, 237, 228, 233, 237, 228, 233, 0, 0, 0, 0, 0, 0, 1, 0, 232, 231, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 229, 228, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 227, 225, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 227, 0, 225, 0, 223, 0, 225, 0, 227, 0, 225, 0, 223, 0, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0, 239, 1, 0, 0, 239, 0, 1, 0, 239, 1, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0
        ,0, 0, 0, 0, 223, 0, 0, 0, 0, 0, 1, 0, 0, 225, 219, 212, 207, 0, 0, 0, 0, 0, 0, 0, 207, 0, 1, 0, 231, 0, 0, 0, 0, 0, 0, 1, 231, 0, 1, 0, 235, 232, 207, 0, 0, 0, 0, 0, 0, 0, 1, 0, 231, 0, 0, 0, 0, 0, 0, 1, 207, 0, 1, 0, 237, 228, 233, 237, 1, 0, 0, 0, 0, 0, 0, 0, 223, 228, 236, 223, 228, 236, 223, 228, 236, 223, 1, 0, 223, 228, 1, 0, 223, 228, 237, 223, 228, 237, 1, 0, 0, 0, 0, 0, 223, 228, 237, 223, 228, 237, 1, 0, 223, 228, 236, 223, 228, 236, 223, 228, 236, 1, 0, 0, 0, 0, 0, 0, 229, 228, 0, 1, 227, 225, 0, 0, 0, 0, 1, 0, 225, 223, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 221, 219, 0, 1, 219, 217, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 221, 219, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 225, 223, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 0, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0, 239, 1, 0, 0, 239, 0, 1, 0, 239, 1, 0, 0, 239, 1, 0, 0
        ,212, 203, 195, 183, 0, 0, 0, 0, 0, 0, 0, 1, 219, 0, 0, 0, 0, 1, 0, 0, 219, 0, 1, 0, 235, 232, 183, 0, 0, 0, 0, 0, 0, 0, 0, 0, 219, 0, 0, 0, 0, 0, 1, 0, 0, 212, 203, 195, 183, 0, 0, 0, 0, 0, 0, 0, 183, 0, 1, 0, 219, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 225, 231, 235, 225, 231, 235, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 225, 231, 235, 225, 1, 0, 0, 0, 0, 0, 0, 0, 225, 228, 233, 225, 1, 0, 0, 0, 0, 0, 0, 225, 228, 1, 0, 225, 231, 235, 225, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 227, 225, 0, 0, 0, 0, 0, 1, 229, 228, 0, 1, 232, 231, 0, 0, 0, 0, 0, 1, 236, 235, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 221, 219, 0, 1, 227, 225, 0, 0, 0, 0, 0, 1, 229, 228, 0, 1, 232, 231, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0
        ,0, 0, 0, 1, 219, 0, 1, 0, 235, 232, 183, 0, 0, 0, 0, 0, 0, 0, 1, 0, 219, 0, 0, 0, 0, 0, 0, 1, 183, 0, 1, 0, 217, 209, 201, 191, 0, 0, 0, 0, 0, 0, 0, 1, 223, 0, 0, 0, 0, 1, 0, 0, 223, 0, 1, 0, 235, 232, 191, 0, 0, 0, 0, 0, 231, 235, 1, 0, 0, 0, 0, 0, 225, 231, 235, 225, 231, 235, 1, 0, 225, 228, 233, 225, 228, 233, 225, 228, 233, 225, 228, 233, 1, 0, 0, 0, 228, 233, 237, 228, 233, 237, 1, 0, 0, 0, 0, 0, 228, 233, 237, 228, 233, 237, 1, 0, 0, 0, 0, 0, 228, 233, 237, 228, 233, 237, 228, 233, 0, 0, 0, 1, 236, 235, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 232, 231, 0, 1, 236, 235, 0, 0, 0, 0, 0, 1, 235, 236, 237, 0, 0, 0, 0, 0, 236, 235, 0, 1, 232, 231, 0, 1, 236, 235, 0, 1, 232, 231, 0, 1, 229, 228, 0, 1, 232, 231, 0, 1, 229, 228, 0, 1, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0, 239, 1, 0, 0, 239, 0, 1, 0, 239, 1, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0
        ,0, 0, 0, 0, 223, 0, 0, 0, 0, 0, 1, 0, 0, 225, 219, 212, 207, 0, 0, 0, 0, 0, 0, 0, 207, 0, 1, 0, 231, 0, 0, 0, 0, 0, 0, 1, 231, 0, 1, 0, 235, 232, 207, 0, 0, 0, 0, 0, 0, 0, 1, 0, 231, 0, 0, 0, 0, 0, 0, 1, 207, 0, 1, 0, 237, 228, 233, 237, 1, 0, 0, 0, 0, 0, 0, 0, 223, 228, 236, 223, 228, 236, 223, 228, 236, 223, 1, 0, 223, 228, 1, 0, 223, 228, 237, 223, 228, 237, 1, 0, 0, 0, 0, 0, 223, 228, 237, 223, 228, 237, 1, 0, 223, 228, 236, 223, 228, 236, 223, 228, 236, 1, 0, 0, 0, 0, 0, 0, 227, 225, 0, 1, 229, 228, 0, 1, 227, 225, 0, 1, 221, 219, 0, 1, 209, 207, 0, 0, 0, 0, 1, 0, 217, 215, 0, 1, 221, 219, 0, 0, 0, 0, 1, 0, 227, 225, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 225, 223, 0, 1, 221, 219, 0, 0, 0, 0, 0, 217, 0, 215, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 0, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0, 239, 1, 0, 0, 239, 0, 1, 0, 239, 1, 0, 0, 239, 1, 0, 0
        ,227, 221, 215, 201, 0, 0, 0, 0, 0, 0, 0, 1, 228, 0, 0, 0, 0, 1, 0, 0, 228, 0, 1, 0, 235, 232, 201, 0, 0, 0, 0, 0, 0, 0, 0, 0, 207, 0, 0, 0, 0, 0, 1, 0, 0, 228, 223, 217, 209, 0, 0, 0, 0, 0, 0, 0, 209, 0, 1, 0, 232, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 225, 232, 237, 225, 232, 237, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 225, 232, 237, 225, 1, 0, 0, 0, 0, 0, 0, 0, 225, 232, 237, 225, 1, 0, 0, 0, 0, 0, 0, 225, 228, 1, 0, 225, 232, 237, 225, 217, 0, 219, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 217, 215, 0, 1, 221, 219, 0, 0, 0, 0, 0, 1, 223, 0, 225, 0, 0, 0, 0, 0, 0, 0, 0, 0, 223, 0, 0, 1, 209, 207, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0
        ,0, 0, 0, 1, 232, 0, 1, 0, 235, 232, 209, 0, 0, 0, 0, 0, 215, 0, 0, 1, 195, 0, 0, 0, 0, 0, 0, 0, 191, 0, 0, 1, 217, 209, 201, 183, 0, 0, 0, 0, 0, 0, 0, 1, 219, 0, 0, 0, 0, 1, 0, 0, 219, 0, 1, 0, 235, 232, 183, 0, 0, 0, 0, 0, 232, 237, 1, 0, 0, 0, 0, 0, 225, 232, 237, 225, 232, 237, 1, 0, 225, 232, 237, 225, 232, 237, 225, 232, 237, 225, 232, 237, 1, 0, 0, 0, 225, 231, 235, 225, 231, 235, 1, 0, 0, 0, 0, 0, 225, 231, 235, 225, 231, 235, 1, 0, 0, 0, 0, 0, 225, 231, 235, 225, 231, 235, 225, 231, 0, 0, 0, 0, 0, 1, 0, 0, 217, 215, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 219, 217, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 215, 0, 217, 0, 219, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 221, 0, 219, 0, 217, 0, 219, 0, 221, 0, 219, 0, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0, 239, 1, 0, 0, 239, 0, 1, 0, 239, 1, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0
        ,0, 0, 0, 0, 219, 0, 0, 0, 0, 0, 1, 0, 0, 219, 215, 209, 183, 0, 0, 0, 0, 0, 0, 0, 219, 0, 1, 0, 219, 215, 209, 159, 0, 0, 0, 0, 0, 0, 1, 0, 235, 232, 175, 0, 0, 0, 0, 0, 0, 0, 1, 0, 235, 232, 179, 0, 0, 0, 0, 1, 235, 232, 1, 0, 235, 225, 231, 235, 1, 0, 0, 0, 0, 0, 0, 0, 225, 228, 233, 225, 228, 233, 225, 228, 233, 225, 1, 0, 225, 228, 1, 0, 225, 231, 235, 225, 231, 235, 1, 0, 0, 0, 0, 0, 225, 231, 235, 225, 231, 235, 1, 0, 0, 0, 0, 0, 225, 228, 233, 225, 228, 233, 225, 228, 233, 1, 0, 0, 217, 0, 219, 0, 221, 0, 219, 0, 217, 0, 219, 0, 221, 0, 219, 0, 217, 0, 219, 0, 221, 0, 219, 0, 217, 0, 219, 217, 215, 212, 209, 207, 203, 201, 199, 195, 191, 187, 183, 179, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 0, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0, 225, 0, 0, 1
        ,212, 203, 195, 163, 0, 0, 0, 0, 0, 0, 0, 1, 209, 0, 0, 0, 0, 1, 0, 0, 209, 0, 1, 0, 235, 232, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 209, 0, 0, 0, 0, 0, 1, 0, 0, 212, 203, 195, 163, 0, 0, 0, 0, 0, 0, 0, 163, 0, 1, 0, 209, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 225, 231, 237, 225, 231, 237, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 225, 231, 237, 225, 1, 0, 0, 0, 0, 0, 0, 0, 225, 231, 235, 225, 1, 0, 0, 0, 0, 0, 0, 225, 231, 1, 0, 225, 231, 237, 225, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 217, 215, 0, 221, 219, 0, 0, 0, 0, 0, 0, 0, 227, 225, 0, 0, 0, 0, 0, 0, 219, 1, 0, 0, 219, 0, 0, 0, 0, 0, 0, 0, 225, 1, 0, 0, 225, 223, 227, 225, 0, 0, 0, 0, 0, 223, 0, 221, 219, 0, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0
        ,0, 0, 0, 1, 209, 0, 1, 0, 235, 232, 163, 0, 0, 0, 0, 0, 0, 0, 1, 0, 209, 0, 0, 0, 0, 0, 0, 1, 183, 0, 1, 0, 217, 209, 201, 175, 0, 0, 0, 0, 0, 0, 0, 1, 215, 0, 0, 0, 0, 1, 0, 0, 215, 0, 1, 0, 235, 232, 175, 0, 0, 0, 0, 0, 231, 237, 1, 0, 0, 0, 0, 0, 225, 231, 237, 225, 231, 237, 1, 0, 225, 231, 235, 225, 231, 235, 225, 231, 235, 225, 231, 235, 1, 0, 0, 0, 228, 235, 239, 228, 235, 239, 1, 0, 0, 0, 0, 0, 228, 235, 239, 228, 235, 239, 1, 0, 0, 0, 0, 0, 228, 235, 239, 228, 235, 239, 228, 235, 0, 0, 0, 0, 227, 225, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 229, 231, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 231, 229, 228, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 229, 0, 228, 0, 227, 0, 228, 0, 229, 0, 228, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0, 239, 1, 0, 0, 239, 0, 1, 0, 239, 1, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0
        ,0, 0, 0, 0, 215, 0, 0, 0, 0, 0, 1, 0, 0, 225, 219, 212, 183, 0, 0, 0, 0, 0, 0, 0, 183, 0, 1, 0, 219, 0, 0, 0, 0, 0, 0, 1, 219, 0, 1, 0, 235, 232, 183, 0, 0, 0, 0, 0, 0, 0, 1, 0, 219, 0, 0, 0, 0, 0, 0, 1, 183, 0, 1, 0, 239, 228, 235, 239, 1, 0, 0, 0, 0, 0, 0, 0, 225, 231, 237, 225, 231, 237, 225, 231, 237, 225, 1, 0, 225, 231, 1, 0, 225, 231, 237, 225, 231, 237, 1, 0, 0, 0, 0, 0, 225, 231, 235, 225, 231, 235, 1, 0, 225, 231, 237, 225, 231, 237, 225, 231, 237, 1, 0, 0, 0, 0, 0, 0, 227, 225, 0, 1, 225, 223, 0, 0, 0, 0, 0, 1, 227, 225, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 223, 0, 221, 219, 0, 0, 0, 0, 0, 0, 0, 209, 207, 0, 1, 217, 215, 0, 0, 0, 0, 0, 0, 221, 219, 0, 1, 227, 225, 0, 0, 0, 0, 1, 0, 221, 219, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 0, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0, 239, 1, 0, 0, 239, 0, 1, 0, 239, 1, 0, 0, 239, 1, 0, 0
        ,212, 203, 195, 163, 0, 0, 0, 0, 0, 0, 0, 1, 209, 0, 0, 0, 0, 1, 0, 0, 209, 0, 1, 0, 235, 232, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 209, 0, 0, 0, 0, 0, 1, 0, 0, 212, 203, 195, 163, 0, 0, 0, 0, 0, 0, 0, 163, 0, 1, 0, 209, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 225, 231, 237, 225, 231, 237, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 225, 231, 237, 225, 1, 0, 0, 0, 0, 0, 0, 0, 225, 231, 235, 225, 1, 0, 0, 0, 0, 0, 0, 225, 231, 1, 0, 225, 231, 237, 225, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 221, 0, 219, 0, 217, 0, 219, 0, 221, 0, 219, 0, 1, 0, 0, 0, 0, 0, 0, 0, 217, 215, 0, 1, 212, 209, 0, 0, 0, 0, 0, 1, 209, 207, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 203, 201, 0, 1, 199, 195, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 225, 0, 0, 0, 0, 0, 1, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0, 0, 0, 0, 0, 239, 1, 0, 0, 239, 0, 1, 0
    };
    QByteArray b = QByteArray::fromRawData(reinterpret_cast<char*>(data),32*256);
    f.write(b);
    f.close();


}

void SineTable(QString fn) {
    QFile f(fn);
    f.open(QFile::WriteOnly);
    QByteArray b;
    for (int i=0;i<256;i++)
        b.append(sin((i/256.0)*3.14159265*2)*127+128);
    f.write(b);
    f.close();

}



int main(int argc, char *argv[])
{

/*   #pragma omp for

    for (int i=0;i<19;i++)
        i=0;*/
    QApplication a(argc, argv);
    a.setStyle(QStyleFactory::create("Fusion"));
    //CIniFile ini;

//    SetMongisPalette(a);

//    CreateBinaryFile("music.bin");
    SineTable("sine.bin");

//    ConvertPerlin("/home/leuat/Pictures/Perlin.jpg", "/home/leuat/Dropbox/TRSE/VICDemo/data/perlin22.dat", 23.25);
  //  exit(1);


/*    QFile f("random.bin");
    QByteArray arr;
    for (int i=0;i<256;i++)
        arr.append(rand()%256);

    f.open(QFile::WriteOnly);
    f.write(arr);
    f.close();
*/

    MainWindow w;
    w.show();

    return a.exec();
}
