#pragma once

#include "ICommand.hpp"

class Invoker {
public:
	void SetCommand(ICommand* cmd);
	void ExecuteCommand();

private:
	ICommand* m_command;
};

