//	Project:	ExampleApp.
//	ExampleGui.cpp	--	Implmentation of the CExampleGui class.
//	Revisions:
//	2018-10-31	--	F.R. van der Meulen	--	Created.

//	Include files.
#include "ExampleGui.h"
#include <iostream>

//	Constructor.
//	Parameters:	none.
CExampleGui::CExampleGui() {
	//	Create app & window.
	app = Gtk::Application::create();
	m_window = new Gtk::Window();
	
	//	Configure window.
	m_window->set_title("Example app");
	m_window->set_default_size(800, 600);
	m_window->set_resizable(false);
	m_window->show_all_children();
}

//	Destructor.
//	Parameters:	none.
CExampleGui::~CExampleGui() {
	//	Delete app objects.
	delete m_window;
}

//	start	--	Starts application
//	Parameters:	none.
//	Returns:	void.
void CExampleGui::start() {
	app->run(*m_window);
}

//	clearWindow	--	Clears app window.
//	Parameters:	none.
//	Returns:	void.
void CExampleGui::clearWindow() {
	m_window->remove();
}

//	testFunc	--	Function in Gui class to call from Screen member Button.
//	Parameters:	none.
//	Returns:	void.
void CExampleGui::testFunc() {
	std::cout << "Test succesful!!" << std::endl;
}

//	getWindow	--	Returns pointer to window.
//	Parameters:	none.
//	Returns:	pointer to app window.
Gtk::Window* CExampleGui::getWindow() {
	return m_window;
}

//	getStartScreen	--	Returns pointer to start screen.
//	Parameters:	none.
//	Returns:	pointer to start screen.
CStartScreen* CExampleGui::getStartScreen() {
	return m_startScreen;
}

//	getExampleScreen	--	Returns pointer to example screen.
//	Parameters:	none.
//	Returns:	pointer to example screen.
CExampleScreen* CExampleGui::getExampleScreen() {
	return m_exampleScreen;
}

//	setStartScreen	--	Sets gui start screen.
//	Parameters:
//		start	--	Pointer to start screen object.
//	Returns:	void.
void CExampleGui::setStartScreen(CStartScreen* start) {
	m_startScreen = start;
	m_window->show_all_children();
}

//	setExampleScreen	--	Sets gui example screen.
//	Parameters:
//		test	--	Pointer to example screen object.
//	Returns:	void.
void CExampleGui::setExampleScreen(CExampleScreen* example) {
	m_exampleScreen = example;
	m_window->show_all_children();
}