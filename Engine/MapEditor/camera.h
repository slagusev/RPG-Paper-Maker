/*
    RPG Paper Maker Copyright (C) 2017 Marie Laporte

    This file is part of RPG Paper Maker.

    RPG Paper Maker is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    RPG Paper Maker is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CAMERA_H
#define CAMERA_H

#include <QVector3D>
#include <QMatrix4x4>
#include "cursor.h"

// -------------------------------------------------------
//
//  CLASS Camera
//
//  The camera of the map editor.
//
// -------------------------------------------------------

class Camera
{
public:
    Camera();
    static int defaultDistance;
    static int defaultHeight;

    QMatrix4x4 view() const;
    void setProjection(int width, int height);
    QMatrix4x4 projection() const;
    float positionX() const;
    float positionY() const;
    float positionZ() const;
    double horizontalAngle() const;
    int distance() const;
    int height() const;
    void setDistance(int d);
    void setHeight(int h);
    void addDistance(int d);
    void addHeight(int h);
    void update(Cursor* cursor, int squareSize);
    void zoomPlus(int gridHeight);
    void zoomLess(int gridHeight);
    void onMouseWheelPressed(QPoint& mouse, QPoint& mouseBeforeUpdate);

private:
    int m_distance;
    int m_height;
    double m_horizontalAngle;
    QVector3D m_position;
    QVector3D m_target;
    QVector3D m_up;
    QMatrix4x4 m_projection;
    QMatrix4x4 m_world;
};

#endif // CAMERA_H
