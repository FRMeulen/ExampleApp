//	Project:	ExampleApp.
//	StartScreen.cpp	--	Implementation of the CStartScreen class.
//	Revisions:
//	2018-10-31	--	F.R. van der Meulen	--	Created.

//	Include files.
#include "StartScreen.h"

//	Constructor
//	Parameters:
//		parmGui	--	Gui containing this screen.
CStartScreen::CStartScreen(CExampleGui parmGui) : m_gui(&parmGui) {
	//	Make self known to Gui.
	m_gui->setStartScreen(this);

	//	Build child widgets.
	m_mainBox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
		m_startScreenLabel = new Gtk::Label("This is the start screen!");
		m_toExampleButton = new Gtk::Button("To Example!");

	//	Build screen.
	m_mainBox->pack_start(*m_startScreenLabel, Gtk::PACK_EXPAND_WIDGET, 10);
	m_mainBox->pack_start(*m_toExampleButton, Gtk::PACK_EXPAND_WIDGET, 10);

	//	Signal handlers.
	m_toExampleButton->signal_clicked().connect(sigc::bind<std::string>(sigc::mem_fun(*this, &CStartScreen::swapScreen), "examplescreen"));
}

//	Destructor.
//	Parameters:	none.
CStartScreen::~CStartScreen() {
	m_gui->setStartScreen(NULL);
	delete m_startScreenLabel;
	delete m_toExampleButton;
	delete m_mainBox;
}

//	show	--	Tells window to display this screen.
//	Parameters:	none.
//	Returns:	void.
void CStartScreen::show() {
	m_gui->clearWindow();
	m_gui->getWindow()->add(*m_mainBox);
}

//	swapScreen	--	Tells window to switch screens.
//	Parameters:
//		newScreen	--	String of new screen name.
//	Returns:	void.
void CStartScreen::swapScreen(std::string newScreen) {
	if (newScreen == "startscreen")
		m_gui->getStartScreen()->show();
	else if (newScreen == "examplescreen")
		m_gui->getExampleScreen()->show();
}