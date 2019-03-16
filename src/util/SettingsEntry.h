#ifndef SETTINGSENTRY_H
#define SETTINGSENTRY_H

#include "qstring.h"

// Is the value itself, inside a section. This is what's directly used when
// accessing settings.
// - value represents the current value to use
// - editedValue represents the value user directly edits
// (it is applied - value = editedValue - when user applies the settings)

class SettingsEntry
{
public:

    SettingsEntry();

    const QString& getName() const { return _name; }

protected:

    QString _name;
};

#endif // SETTINGSENTRY_H
