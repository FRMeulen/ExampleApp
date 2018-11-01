//	Project:	ExampleApp.
//	StartScreen.h	--	Interface for the CStartScreen class.
//	Revisions:
//	2018-10-31	--	F.R. van der Meulen	--	Created.

//	Pragma.
#pragma once

//	Include files.
#include <gtkmm-3.0/gtkmm.h>
#include "ExampleGui.h"
#include "ExampleScreen.h"

//	Class interface.
class CStartScreen {
protected:
	//	Gui pointer.
	CExampleGui* m_gui;

	//	Child widget pointers.
	Gtk::Box *m_startMainBox;
		Gtk::Label *m_startScreenLabel;
		Gtk::Button *m_toExampleButton;
public:
	//	Constructors & destructor.
	CStartScreen(CExampleGui parmGui);
	virtual ~CStartScreen();

	//	Methods.
	void swapScreen(std::string newScreen);
};