//	Project:	ExampleApp.
//	Main.cpp	--	Main class of ExampleApp.
//	Revisions:
//	2018-10-31	--	F.R. van der Meulen	--	Created.

//	Include files.
#include "ExampleGui.h"
#include "StartScreen.h"
#include "ExampleScreen.h"

//	Main method	--	Entry point for the ExammpleApp program.
//	Parameters:	none.
//	Returns:	int.
int main() {
	//	Create gui.
	CExampleGui *m_gui = new CExampleGui();
	
	//	Create screens.
	CStartScreen *m_start = new CStartScreen(*m_gui);
	CExampleScreen *m_screen = new CExampleScreen(*m_gui);
	
	//	Show start screen.
	m_start->show();

	//	Start gui.
	m_gui->start();

	//	Exit program.
	return 0;
}