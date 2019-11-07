#pragma once

#include "ViewReport.h"
#include "User.h"

#include <vector>
#include <string>
#include <ctime>

#include <Wt/Dbo/Dbo.h> // WebToolKit Connection for API Incorporation with SQL Database
namespace dbo = Wt::Dbo; // For controlling API functionality

using namespace std;

class ReportHistory
{
private:
	User curr;
	int currItem;
	vector<ViewReport> list;

public:

	ReportHistory(int currItemNum, User currUser);

	void printHistory();
};

