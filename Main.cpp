#include "ExampleGui.h"
#include "StartScreen.h"
#include "ExampleScreen.h"

int main() {
	CExampleGui *m_gui = new CExampleGui();
	CStartScreen *m_start = new CStartScreen(*m_gui);
	CExampleScreen *m_screen = new CExampleScreen(*m_gui);
	m_gui->start();
}