#include "Invoker.hpp"

void Invoker::SetCommand(ICommand* cmd) {
	m_command = cmd;
}

void Invoker::ExecuteCommand() {
	if (m_command) {
		m_command->Execute();
	}
}
	
