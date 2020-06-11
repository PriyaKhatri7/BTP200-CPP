#ifndef MENU_H
#define MENU_H

namespace sdds
{
	const int MAX_NO_OF_ITEMS = 10;

	class MenuItem
	{
		char* m_menuItem; //MenuItem with unknown lenght for content

	public:
		MenuItem(); //default constructor
		MenuItem(const char*); //
		~MenuItem(); //Destructor 

		void display(); //display menuItem
		MenuItem(const MenuItem&) = delete;
		MenuItem& operator=(const MenuItem&) = delete; //copy and assignment. =delete to prohibit copying. no implementation because we're prohibiting

		friend class Menu;

	};

	class Menu
	{
		//displays a menu title and serveral menu items with a row number attached to each
		char* menuTitle;
		MenuItem* menuItem[MAX_NO_OF_ITEMS];
		int menuIndentation; //indent the results
		int menuIndex;

	public:
		Menu();
		Menu(const char*, int indentation = 0);
		Menu(const Menu&); //copy constructor
		~Menu();

		Menu& operator=(const Menu&); //copy and assignment. Menu Should be safely copied and assigned to another menu.
		bool isEmpty() const; //returns true is menu is invalid. false is valid and usable
		void display() const; //display menu
		operator bool() const; //bool cast overload
		void add(const char*);
		Menu& operator<<(const char* tempMenuItem);
		int run() const; //display Menu and waits for user response
		operator int() const; //overload cast operator.
	};
}

#endif // !MENU_H
