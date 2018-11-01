//	Project:	ExampleApp.
//	ExampleGui.cpp	--	Implmentation of the CExampleGui class.
//	Revisions:
//	2018-10-31	--	F.R. van der Meulen	--	Created.

//	Include files.
#include "ExampleGui.h"

//	Definitions.
#define startScreenPage 0
#define exampleScreenPage 1

//	Constructor.
//	Parameters:	none.
CExampleGui::CExampleGui() {
	//	Create app & window.
	app = Gtk::Application::create();
	m_window = new Gtk::Window();
	m_pages = new Gtk::Notebook();
	
	//	Configure window.
	m_window->set_title("Example app");
	m_window->set_default_size(800, 600);
	m_window->set_resizable(false);
	m_window->add(*m_pages);
	m_window->show_all_children();

	//	Configure notebook.
	m_pages->set_show_tabs(false);
}

//	Destructor.
//	Parameters:	none.
CExampleGui::~CExampleGui() {
	
}

//	start	--	Starts application
//	Parameters:	none.
//	Returns:	void.
void CExampleGui::start() {
	m_pages->set_current_page(startScreenPage);
	m_window->show_all_children();
	app->run(*m_window);
}

//	swapScreen	--	Switches active screen.
//	Parameters:
//		newScreen	--	String of screen name.
//	Returns:	void.
void CExampleGui::swapScreen(std::string newScreen) {
	if (newScreen == "startscreen")
		m_pages->set_current_page(startScreenPage);
	else if (newScreen == "examplescreen")
		m_pages->set_current_page(exampleScreenPage);
}

//	getWindow	--	Returns pointer to window.
//	Parameters:	none.
//	Returns:	pointer to app window.
Gtk::Window* CExampleGui::getWindow() {
	return m_window;
}

//	getNotebook	--	Returns pointer to notebook.
//	Parameters:	none.
//	Returns:	pointer to notebook containing screens.
Gtk::Notebook* CExampleGui::getNotebook() {
	return m_pages;
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
}

//	setExampleScreen	--	Sets gui example screen.
//	Parameters:
//		test	--	Pointer to example screen object.
//	Returns:	void.
void CExampleGui::setExampleScreen(CExampleScreen* example) {
	m_exampleScreen = example;
}