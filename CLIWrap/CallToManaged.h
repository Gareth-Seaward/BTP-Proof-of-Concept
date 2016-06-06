#ifndef CALLTOMANAGED_H
#define CALLTOMANAGED_H

using namespace System;

#include "stdafx.h"
#include <vcclr.h>


public ref class CallbackManager
{
public:
	delegate bool delOnEnum(int h);
	delOnEnum ^pE;
	event delOnEnum ^OnEnum {
		void add(delOnEnum^ p) {
			pE = static_cast<delOnEnum^> (Delegate::Combine(pE, p));
		}
		void remove(delOnEnum^ p) {
			pE = static_cast<delOnEnum^> (Delegate::Remove(pE, p));
		}
		bool raise(int h) {
			if (pE != nullptr)
				return pE->Invoke(h);

			return false;
		}
	}

	virtual bool handler(int h);
	void RaiseEvent(int h);

	CallbackManager();
};

#endif
