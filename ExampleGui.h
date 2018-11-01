//	Project:	ExampleApp.
//	ExampleGui.h	--	Interface for the CExampleGui class.
//	Revisions:
//	2018-10-31	--	F.R. van der Meulen	--	Created.

//	Pragma.
#pragma once

//	Include files.
#include <gtkmm-3.0/gtkmm.h>

//	Predefinitions.
class CStartScreen;
class CExampleScreen;

//	Class interface.
class CExampleGui {
protected:
	//	App-required pointers.
	Glib::RefPtr<Gtk::Application> app;
	Gtk::Window *m_window;
	Gtk::Notebook *m_pages;

	//	Screen object pointers.
	CExampleScreen *m_exampleScreen;
	CStartScreen *m_startScreen;
public:
	//	Constructors & destructor.
	CExampleGui();
	virtual ~CExampleGui();

	//	Methods.
	void start();
	void swapScreen(std::string newScreen);

	//	Getters.
	Gtk::Window* getWindow();
	Gtk::Notebook* getNotebook();
	CStartScreen* getStartScreen();
	CExampleScreen* getExampleScreen();

	//	Setters.
	void setExampleScreen(CExampleScreen *example);
	void setStartScreen(CStartScreen *start);
};