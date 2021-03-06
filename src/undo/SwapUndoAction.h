/*
 * Xournal++
 *
 * Undo page swap action
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "UndoAction.h"
#include "model/PageRef.h"

class Control;

class SwapUndoAction : public UndoAction
{
public:
	SwapUndoAction(size_t pageNr, bool moveUp, PageRef swapped_page, PageRef other_page);

	virtual ~SwapUndoAction();

public:
	virtual bool undo(Control* control);
	virtual bool redo(Control* control);
	XojPage** getPages();
	virtual string getText();

private:
	void swap(Control* control);

private:
	XOJ_TYPE_ATTRIB;

	size_t pageNr;
	PageRef swapped_page, other_page;
	bool moveUp;
};
