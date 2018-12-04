//	Project:	ExampleApp.
//	ExampleScreen.h	--	Interface for the CExampleScreen class.
//	Revisions:
//	2018-10-31	--	F.R. van der Meulen	--	Created.

//	Pragma.
#pragma once

//	Include files.
#include <gtkmm-3.0/gtkmm.h>
#include "ExampleGui.h"
#include "StartScreen.h"

//	Class interface.
class CExampleScreen {
protected:
	//	Gui pointer.
	CExampleGui* m_gui;

	//	Child widget pointers.
	Gtk::Box *m_exampleMainBox;
		Gtk::Label *m_exampleScreenLabel;
		Gtk::Button *m_toStartButton;
public:
	//	Constructors & destructor.
	CExampleScreen(CExampleGui *parmGui);
	virtual ~CExampleScreen();

	//	Methods.
	void swapScreen(std::string newScreen);
};