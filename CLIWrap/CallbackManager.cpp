#include "stdafx.h"

#include "CallToManaged.h"


bool CallbackManager::handler(int h)
{
	System::Console::WriteLine("Found a new window {0}", h);
	return true;
}

CallbackManager::CallbackManager()
{
	OnEnum += gcnew delOnEnum(this, &CallbackManager::handler);
}

void CallbackManager::RaiseEvent(int h)
{
	OnEnum(h);
}