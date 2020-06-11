#include <iostream>
#include <cstring> //strcpy and strlen
#include "Menu.h"

using namespace std;

namespace sdds
{
	//MenuItem default constructor
	MenuItem::MenuItem()
	{
		//set to empty state
		m_menuItem = nullptr;
	}

	//menuitem custom. copy
	MenuItem::MenuItem(const char* tempItem)
	{
		if (tempItem != nullptr)
		{
			//m_menuItem from MenuItem
			//allocate to memory
			m_menuItem = new char[strlen(tempItem) + 1];
			strcpy(m_menuItem, tempItem);
		}
		else //else empty state
		{
			m_menuItem = nullptr;
		}
	}

	//deallocate MenuItem()
	MenuItem::~MenuItem()
	{
		delete[] m_menuItem;
		m_menuItem = nullptr;
	}

	void MenuItem::display()
	{
		if (m_menuItem != nullptr)
		{
			cout << this->m_menuItem << endl << endl;
		}
	}

	//default constructor for Menu
	Menu::Menu()
	{
		//set to empty. pass 0 for indentation
		menuTitle = nullptr;
		//menuItem[0] = 0;

		//checking to make sure MAX_NO_OF_ITEMS/menuItem is set to empty if array index is 0
		for (int i = 0; i < MAX_NO_OF_ITEMS; i++)
		{
			menuItem[i] = nullptr;
		}

		menuIndentation = 0;
		menuIndex = 0;
	}

	Menu::Menu(const char* mTitle, int mInd) : Menu()
	{
		if (mTitle != nullptr)
		{
			menuTitle = new char[strlen(mTitle) + 1];
			strcpy(menuTitle, mTitle);
			menuIndentation = mInd;
		}
	}

	//objs from Menu()
	Menu::Menu(const Menu& m) : Menu()
	{
		*this = m;
	}

	//deallocate Menu
	Menu::~Menu()
	{
		delete[] menuTitle;
		menuTitle = nullptr;
	}

	//copy assignment operator
	Menu& Menu::operator=(const Menu& pmenu)
	{
		//self-assignment check for address of pmenu. Makes sure they are not the same object
		if (this != &pmenu) 
		{
			for (int i = 0; i < menuIndex; i++)
			{
				delete menuItem[i];
				menuItem[i] = nullptr;
			}

			//shallow copy
			menuIndentation = pmenu.menuIndentation;
			menuIndex = pmenu.menuIndex;

			//deep copying
			for (int i = 0; i < menuIndex; i++)
			{
				menuItem[i] = new MenuItem(pmenu.menuItem[i]->m_menuItem);
			}

			//allocate new memory if needed
			if (pmenu.menuTitle != nullptr) 
			{
				menuTitle = new char[strlen(pmenu.menuTitle) + 1];
				strcpy(menuTitle, pmenu.menuTitle);

			}
			else {
				menuTitle = nullptr;
			}
		}
		return *this; //returning this instance of Menu
	}

	//returns true is menu is invalid. false is valid and usable
	bool Menu::isEmpty() const
	{
		if (menuTitle == nullptr) //&& menuItem == 0 && menuIndentation == 0 && menuIndex == 0
		{
			return false;
		}
		else
		{
			return true;
		}
		
	}

	//display menu function
	void Menu::display() const
	{
		if (!isEmpty())
		{
			cout << "Invalid Menu!" << endl;
		}
		else if (this->menuItem[0] == nullptr)
		{
			cout.width(strlen(menuTitle) + 8); //what is this line doing?
			cout << this->menuTitle << endl;
			cout << "No Items to display!" << endl;
		}
		else
		{
			//display output example from PDF. ind 2
			if (menuIndentation == 1)
			{
				//make sure to reset the title of menu after newly assigned string
				cout.width(strlen(menuTitle) + 4);
				cout << menuTitle << endl;

				for (int i = 0; i < menuIndex; i++)
				{
					//format
					cout.width(5);
					cout << i + 1 << "- " << menuItem[i]->m_menuItem << endl;
				}
				cout.width(6);
				cout << "> ";
			}
			else if (menuIndentation == 2)
			{
				cout.width(strlen(menuTitle) + 8);
				cout << menuTitle << endl;

				for (int i = 0; i < menuIndex; i++)
				{
					//format
					cout.width(9);
					cout << i + 1 << "- " << menuItem[i]->m_menuItem << endl;
				}
				//more formatting
				cout.width(10);
				cout << "> ";
			}
			else
			{
				cout << menuTitle << endl;

				for (int i = 0; i < menuIndex; i++)
				{
					//format
					cout << i + 1 << "- " << menuItem[i]->m_menuItem << endl;
				}

				cout << "> ";
			}
		}
	}
	//bool cast overload
	//if menu is casted to a bool, return true. if menu is valid and usable, return false
	Menu::operator bool() const
	{
		if (isEmpty()) {
			return true;
		}
		else
			return false;
	}

	/*if string is invalid then set empty and nothing is added.
	create dynamic MenuItem and add to array (pointers). If full then the function should 
	ignore and exit menu
	*/
	void Menu::add(const char* tempMenuItem)
	{
		if (tempMenuItem != nullptr && menuIndex != MAX_NO_OF_ITEMS)
		{
			//don't forget it's of type MenuItem
			menuItem[menuIndex] = new MenuItem(tempMenuItem);
			this->menuIndex++;
		}
		else
		{
			*this = Menu();
		}
	}

	//insertion operator. Insert a const char into Menu as MenuItem. Works like the add function.
	//PDF format for display. basically same as above.
	//diff is it inserts to the Menu
	Menu& Menu::operator<<(const char* tempMenuItem)
	{
		if (tempMenuItem != nullptr && menuIndex != MAX_NO_OF_ITEMS)
		{
			menuItem[menuIndex] = new MenuItem(tempMenuItem);
			this->menuIndex++;
		}
		else
		{
			*this = Menu();
		}
		return *this;
	}

	//waits for user to select the option by entering the row number
	int Menu::run() const
	{
		int userchoice; //collect the user input
		display();

		if (menuIndex > 0 && isEmpty())
		{
			cin >> userchoice;
			cin.ignore(9000, '\n');

			while (true)
			{
				//if user enters non-integer value. wait for user's response
				if (cin.fail())
				{
					cout << "Invalid Integer, try again: ";
					cin.clear();
					cin.ignore(9000, '\n');
				}
				//input is int but out of boundary of the available options. wait for user
				else if (userchoice <= 0 || userchoice > menuIndex)
				{
					cout << "Invalid selection, try again: ";
				}
				else //valid option. return option
				{
					break;
				}
				cin >> userchoice;
				cin.ignore(9000, '\n');
			}
		}
		else { //if menu has no menuitems then 0 is returns with no user interaction
			userchoice = 0;
		}
		return userchoice;
	}


	Menu::operator int() const
	{
		//if Menu is casted to integer then call run() and it's value is reutrned as int cast value
		int mcast = run();
		return mcast;
	}
}