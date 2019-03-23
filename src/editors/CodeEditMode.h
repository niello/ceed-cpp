#ifndef CODEEDITMODE_H
#define CODEEDITMODE_H

#include "src/editors/MultiModeEditor.h"
#include "qtextedit.h"

// This is the most used alternative editing mode that allows you to edit raw code.
// Raw code is mostly XML in CEGUI formats but can be anything else in a generic sense.

class CodeEditMode : public QTextEdit, public IEditMode
{
public:

    CodeEditMode(MultiModeEditor& editor);

    virtual void activate() override;
    virtual bool deactivate() override;

    // Returns native source code from your editor implementation
    virtual QString getNativeCode() = 0;
    // Synchronizes your editor implementation with given native source code
    virtual bool propagateNativeCode(const QString& code) = 0;

    bool propagateToVisual();
    void setCodeWithoutUndoHistory(const QString& code);

protected slots:

    void slot_contentsChange(int position, int charsRemoved, int charsAdded);

protected:

    MultiModeEditor& _editor; //???to base edit mode (IEditMode)?
    bool ignoreUndoCommands = false;
    QString lastUndoText;
};

// Undo command for code edit mode.
// TODO: Extremely memory hungry implementation for now, I have to figure out how to use my own
// QUndoStack with QTextDocument in the future to fix this.
class CodeEditModeCommand : public QUndoCommand
{
public:

    CodeEditModeCommand(CodeEditMode& owner, const QString& oldText, const QString& newText, int totalChange);

    virtual void undo() override;
    virtual void redo() override;
    virtual int id() const override;
    virtual bool mergeWith(const QUndoCommand* other) override;

    void refreshText();

protected:

    CodeEditMode& _owner;
    QString _oldText;
    QString _newText;
    int _totalChange;
    bool _dryRun = true;
};

#endif // CODEEDITMODE_H
