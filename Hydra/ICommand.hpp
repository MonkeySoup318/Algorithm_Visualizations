#pragma once

#include <iostream>

class ICommand {
public:
	virtual ~ICommand() = default;
	virtual void Execute() = 0;
};