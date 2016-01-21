/*
 * Element.h
 *
 * (c) 2016 Sofian Audry -- info(@)sofianaudry(.)com
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ELEMENT_H_
#define ELEMENT_H_

#include <QtGlobal>
#include <QObject>
#include <QIcon>

#include "UidAllocator.h"

Q_DECLARE_METATYPE(uid)

class Element : public QObject
{
  Q_OBJECT

  Q_PROPERTY(uid     id      READ getId)
  Q_PROPERTY(QString name    READ getName    WRITE setName RESET unsetName)
  Q_PROPERTY(bool    locked  READ isLocked   WRITE setLocked)
  Q_PROPERTY(float   opacity READ getOpacity WRITE setOpacity)
  Q_PROPERTY(QIcon   icon    READ getIcon)

public:
  Element(uid id, UidAllocator* allocator);
  virtual ~Element();

  uid getId() const { return _id; }

  void setName(const QString& name) { _name = name; }
  QString getName() const { return _name; }
  virtual void unsetName() { _name = _id; }

  float getOpacity() const { return _opacity; }
  void setOpacity(float opacity) {
    _opacity = qBound(opacity, 0.0f, 1.0f);
  }

  bool isLocked() const    { return _isLocked; }
  void setLocked(bool locked)    { _isLocked = locked; }
  void toggleLocked()  { _isLocked = !_isLocked; }

  virtual void build() {}

  virtual QIcon getIcon() const { return QIcon(); }

private:
  uid _id;
  QString _name;
  bool _isLocked;
  float _opacity;
  UidAllocator* _allocator;
};

#endif /* MOBJECT_H_ */