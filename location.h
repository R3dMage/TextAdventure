#ifndef LOCATION_H
#define LOCATION_H

#include <string>

class Location{
public:
	Location();
	void SetIsMapChange(bool);
	void SetIsShop(bool);
	void SetHasPlot(bool);
	void SetPositionX(int);
	void SetPositionY(int);
	void SetNeoX(int);
	void SetNeoY(int);
	void SetMapChangeName(std::string);
	void SetShopName(std::string);
	void SetDescription(std::string);
	void SetSummary(std::string);
	void SetPlotText(std::string);
	bool GetIsMapChange();
	bool GetIsShop();
	bool GetHasPlot();
	int GetPositionX();
	int GetPositionY();
	int GetNeoX();
	int GetNeoY();
	std::string GetMapChangeName();
	std::string GetShopName();
	std::string GetDescription();
	std::string GetSummary();
	std::string GetPlotText();

private:
	bool IsMapChange;
	bool IsShop;
	bool HasPlot;
	int PositionX;
	int PositionY;
	int NeoX;
	int NeoY;
	std::string MapChangeName;
	std::string ShopName;
	std::string Description;
	std::string Summary;
	std::string PlotText;
	std::string szChng;
	std::string DisplayValue;
};
#endif