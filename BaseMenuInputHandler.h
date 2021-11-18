#pragma once
class BaseMenuInputHandler
{
public:
	virtual void DisplayMenu(int currentY);
	virtual void OnKeyDown();
	virtual void OnKeyUp();
	virtual void OnKeyLeft();
	virtual void OnKeyRight();
	virtual void OnSelect();
	virtual void OnEscape();
	virtual void OnChoiceMade(int currentY);
};