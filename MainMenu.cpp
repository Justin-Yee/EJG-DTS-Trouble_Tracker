#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;
/*
	MAIN MENU (After Login):
		1. Home
			a. Upcoming Reports (What's due within the next n-days)
			b. Change Password
			c. About
		2. Reports
			a. Submit Report
			b. Existing Reports
			c. Historical Data
		3. Contact
		4. Logout
*/

// For changing passwords (dummy in this case, will be connected to Database in real-use case
string database[100] =
{ "kpatel@ejgallo.com", "bkandler@ejgallo.com", "markmcc2950@ejgallo.com", "jyee@ejgallo.com", "test@ejgallo.com" };
string passwords[100] =
{ "password", "password1", "password2", "password3" };
// String variable for encoding
string encoded;

// Top bar checks and their associated checks
bool running = true;															// While active, program runs. Return 0 once it's inactive
bool selectHome = true, urgReport = false, passChange = false; abt = false;
bool selectReports = false, subReport = false, exReport = false;
bool selectLogout = false;
bool selectContacts = false;

int his = 0, maxHistory = 10;													// his keeps track of which buttons pushed, maxHistory is amount of history kept
string history[1];

void debug(string dbg) { cout << "DEBUG: " << dbg << endl; }					// Debug statements
void error(string err) { cout << "ERROR: " << err << endl; }					// Error statements

// For encoding passwords and checking against stored passwords (a = 7, b = 23, m = 89)
string affine_encode(string plaintext) {
	int a = 7;
	int b = 23;
	int m = 89;
	// Convert string to const char and find the size
	string text = plaintext.data();
	int size = text.length();
	encoded.resize(size);

	int intText[size];
	int encText[size];

	for (int i = 0; i < size; i++) {
		if (text[i] != ' ') {
			encText[i] = ((((int(text[i]) - 33) * a + b) % m) + 33);
		}
		else {
			encText[i] = text[i];
		}
	}
	char encrypted[size];

	for (int i = 0; i < size; i++) {
		encrypted[i] = char(encText[i]);
		encoded[i] = encrypted[i];
	}

	return encrypted;
}
void home() {
	string selectionTopBar;														// Top Bar selections (Home, Reports, About, Contact)
	cout << "\nTOP BAR:\n1. Home (Selected)\n\ta. Upcoming Reports\n\tc. About\n2. Reports\n3. Contact\n4. Logout\n";
	while (selectHome) {
		// UPCOMING REPORTS
		if (urgReport) {
			debug("List of Top 3 Upcoming Reports Here...");
			/*
				We'll declare our report-specific variables here.
				When we reach the end, we'll have a confirmation option to confirm the report has been filled out as desired.
				Once confirmed, subReport = false and we print out the selectHome selection menu again.
			*/
			urgReport = false;
			history[his] = "1"; his = (his + 1) % maxHistory;
			cout << "\nTOP BAR:\n1. Home (Selected)\n\ta. Upcoming Reports\n\tb. Change Password\n\tc. About\n2. Reports\n3. Contact\n4. Logout\n";
		}
		// CHANGE PASSWORD
		else if (passChange) {
			string change;
			debug("Change your password...");
			cout << "Would you like to change your password? (Y/N)" << endl;
			cin >> change;
			if (change == "Y" || change == "y") {
				string password;
				string password2;
				string password3;
				debug("Changing password!");
				cout << "Please enter current password:\t";
				cin >> password;
				affine_encode(password);
				password = encoded;
				bool passMatch = false;
				if (passwords[i] == password) {
					debug("Password match!");
					passMatch = true;
					if (passMatch) {
						cout << "Please enter your new password:\t";
						cin >> password2;
						cout << "Please re-enter your new password:\t";
						cin >> password3;
						if (password2 == password3) {
							affine_encode(password2);
							password2 = encoded;
							password2 = passwords[index];
						}
					}
				}				
			}
			else if (change == "N" || change == "n") {
				debug("Not changing password...");
				passChange = false;
				cout << "\nTOP BAR:\n1. Home (Selected)\n\ta. Upcoming Reports\n\tb. Change Password\n\tc. About\n2. Reports\n3. Contact\n4. Logout\n";
			}
		}
		// ABOUT INFORMATION
		else if (abt) {
			debug("About information...");
			/*
				We'll discuss what to put here.
				Some version number, company name, not much to put here.
			*/
			abt = false;
			history[his] = "1"; his = (his + 1) % maxHistory;
			cout << "\nTOP BAR:\n1. Home (Selected)\n\ta. Upcoming Reports\n\tb. Change Password\n\tc. About\n2. Reports\n3. Contact\n4. Logout\n";
		}

		// User input of where to navigate to
		cout << "\t\t\t";
		cin >> selectionTopBar;
		// TOP BAR SELECTION (Home, Reports, Contacts, Logout)
		// Home
		if (selectionTopBar == "1") { error("Home currently selected."); }
		// Reports
		else if (selectionTopBar == "2") { selectHome = false;	selectReports = true;	history[his] = selectionTopBar; his = (his + 1) % maxHistory; }
		// Contacts
		else if (selectionTopBar == "3") { selectHome = false;	selectContacts = true;	history[his] = selectionTopBar; his = (his + 1) % maxHistory; }
		// Logout
		else if (selectionTopBar == "4") { selectHome = false;	selectLogout = true; }

		// HOME SCREEN SELECTION (Submit Report, Existing Reports, About) [UNSURE IF WE NEED HISTORY FOR THESE]
		else if (selectionTopBar == "a") { urgReport = true;							history[his] = selectionTopBar; his = (his + 1) % maxHistory; }
		else if (selectionTopBar == "b") { passChange = true;							history[his] = selectionTopBar; his = (his + 1) % maxHistory; }
		else if (selectionTopBar == "c") { abt = true;									history[his] = selectionTopBar; his = (his + 1) % maxHistory; }
		// Invalid Input
		else { error("Invalid Input"); }
	}
}

void reports() {
	string selectionTopBar;														// Top Bar selections (Home, Reports, About, Contact)
	cout << "\nTOP BAR:\n1. Home\n2. Reports (Selected)\n\ta. Submit Report\n\tb. Existing Reports\n3. Contact\n4. Logout\n";
	while (selectReports) {
		// SUBMIT REPORTS
		if (subReport) {
			debug("Fill in New Reports Here...");
			/*
				We'll declare our report-specific variables here.
				When we reach the end, we'll have a confirmation option to confirm the report has been filled out as desired.
				Once confirmed, subReport = false and we print out the selectHome selection menu again.
			*/
			subReport = false;
			history[his] = "2"; his = (his + 1) % maxHistory;
			cout << "\nTOP BAR:\n1. Home\n2. Reports (Selected)\n\ta. Submit Report\n\tb. Existing Reports\n3. Contact\n4. Logout\n";
		}
		// EXISTING REPORTS
		else if (exReport) {
			debug("History of Reports Show Here...");
			/*
				This is where our history of reports will show up.
				We will have a list of size n shown at any time. Initially will be reports 0 through n.
					If we hit a 'next' button, it will move to reports n+1 through n+n.
					We can keep hitting next until we reach the end.
						|| if (n+n > total list size) {
						|| 	 Gray out 'next' button
						|| }
					We can maybe keep track of the amount of "next" buttons hit, with each button push, nextButtonPushes++, then...
						|| if (n * nextButtonPushes > total list size) {
						|| 	 Gray out 'next' button
						|| }
					We can also have a previous button that lights up once we hit next the first time
						With each push, nextButtonPushes--;
						|| if (nextButtonPushes == 0) {
						||	 Gray out 'previous' button
						|| }
				Once we're done, at any point we can push an 'exit' button to go back to the selectHome selection menu again
			*/
			exReport = false;
			history[his] = "2"; his = (his + 1) % maxHistory;
			cout << "\nTOP BAR:\n1. Home\n2. Reports (Selected)\n\ta. Submit Report\n\tb. Existing Reports\n3. Contact\n4. Logout\n";
		}
		cout << "\t\t\t";
		cin >> selectionTopBar;
		// TOP BAR SELECTION (Home, Reports, Contacts, Logout)
		// Home
		if (selectionTopBar == "1") { selectReports = false;	selectHome = true;		history[his] = selectionTopBar; his = (his + 1) % maxHistory; }
		// Reports
		else if (selectionTopBar == "2") { error("Reports currently selected."); }
		// Contacts
		else if (selectionTopBar == "3") { selectReports = false;	selectContacts = true;	history[his] = selectionTopBar; his = (his + 1) % maxHistory; }
		// Logout
		else if (selectionTopBar == "4") { selectReports = false;	selectLogout = true; }
		// REPORTS SCREEN (Submit Reports, Existing Reports)
		else if (selectionTopBar == "a") { subReport = true;							history[his] = selectionTopBar;	his = (his + 1) % maxHistory; }
		else if (selectionTopBar == "b") { exReport = true;								history[his] = selectionTopBar; his = (his + 1) % maxHistory; }
		// Invalid Input
		else { error("Invalid Input"); }
	}
}

void contact() {
	string selectionTopBar;														// Top Bar selections (Home, Reports, About, Contact)
	cout << "\nTOP BAR:\n1. Home\n2. Reports\n3. Contact (Selected)\n4. Logout\n";
	while (selectContacts) {
		cout << "\t\t\t";
		cin >> selectionTopBar;
		// TOP BAR SELECTION (Home, Reports, Contacts, Logout)
		// Home
		if (selectionTopBar == "1") { selectContacts = false;	selectHome = true;		history[his] = selectionTopBar; his = (his + 1) % maxHistory; }
		// Reports
		else if (selectionTopBar == "2") { selectContacts = false;	selectReports = true;	history[his] = selectionTopBar; his = (his + 1) % maxHistory; }
		// Contacts
		else if (selectionTopBar == "3") { error("Contacts currently selected."); }
		// Logout
		else if (selectionTopBar == "4") { selectContacts = false;	selectLogout = true; }
		// Invalid Input
		else { error("Invalid Input"); }
	}
}

void logout() {
	string logout;														// Top Bar selections (Home, Reports, About, Contact)
	cout << "\nAre you sure you would like to Log Out? (Y/N)\n";
	while (selectLogout) {
		cout << "\t\t\t";
		cin >> logout;
		if (logout == "Y" || logout == "y") {
			debug("Successfully Logged Out!");
			selectLogout = false;
			running = false;
		}
		else if (logout == "N" || logout == "n") {
			debug("Not logging out");
			if (his == 0) {
				his = maxHistory - 1;
			}
			else {
				his--;
			}
			if (history[his] == "1") { selectLogout = false; selectHome = true; debug("Going to Home"); }
			else if (history[his] == "2") { selectLogout = false; selectReports = true; debug("Going to Reports"); }
			else if (history[his] == "3") { selectLogout = false; selectContacts = true; debug("Going to Contacts"); }
			else { error("No history found."); }
		}
		// Invalid Input
		else { error("Invalid Input"); }
	}
}

int main(void) {
	while (running) {
		if (selectHome) { home(); }
		else if (selectReports) { reports(); }
		else if (selectContacts) { contact(); }
		else if (selectLogout) { logout(); }
	}
	return 0;
}