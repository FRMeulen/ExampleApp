//	Project	--	ExampleApp
//	ExampleScreen.cpp	--	Implementation of the CExampleScreen class.
//	Revisions:
//	2018-10-31	--	F.R. van der Meulen	--	Created.

//	Include files.
#include "ExampleScreen.h"
#include <iostream>

//	Definitions.
#define examplePageNum 1

//	Constructor.
//	Parameters:
//		parmGui	--	Gui containing this screen.
CExampleScreen::CExampleScreen(CExampleGui parmGui) : m_gui(&parmGui) {
	//	Build child widgets.
	m_exampleMainBox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
		m_exampleScreenLabel = new Gtk::Label("This is the example screen!");
		m_toStartButton = new Gtk::Button("To Start!");

	//	Build screen.
	m_exampleMainBox->pack_start(*m_exampleScreenLabel, Gtk::PACK_SHRINK, 10);
	m_exampleMainBox->pack_start(*m_toStartButton, Gtk::PACK_SHRINK, 10);

	//	Signal handlers.
	m_toStartButton->signal_clicked().connect(sigc::bind<std::string>(sigc::mem_fun(*this, &CExampleScreen::swapScreen), "startscreen"));

	//	Make self known to Gui.
	m_gui->setExampleScreen(this);
	m_gui->getNotebook()->append_page(*m_exampleMainBox);
}

//	Destructor.
//	Parameters:	none.
CExampleScreen::~CExampleScreen() {
	m_gui->setExampleScreen(NULL);
	delete m_exampleScreenLabel;
	delete m_toStartButton;
	delete m_exampleMainBox;
}

//	show	--	Tells window to display this screen.
//	Parameters:	none.
//	Returns:	void.
void CExampleScreen::show() {
	m_gui->getNotebook()->set_current_page(0);
}

//	swapScreen	--	Tells window to switch screens.
//	Parameters:
//		newScreen	--	String of new screen name.
//	Returns:	void.
void CExampleScreen::swapScreen(std::string newScreen) {
	if (newScreen == "startscreen")
		m_gui->getStartScreen()->show();
	else if (newScreen == "examplescreen")
		m_gui->getExampleScreen()->show();
}