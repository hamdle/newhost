// hello.cpp

#include <iostream>
#include <string>
using namespace std;

int main()
{
	// Get project root file name
	string project_name;
	cout << "Project name (/var/www/html/[name].local): ";
	getline( cin, project_name );

	// Get public web root
	string web_root;
	cout << "Enter web root (hit enter/leave blank for public_html): ";
	getline( cin, web_root );
	if (web_root.empty())
		web_root = "public_html";

	// Verify or retry
	string verify;
	cout << "Create /var/www/html/" << project_name << "/" << web_root << "? (y/n) ";
	getline( cin, verify );

	string yes = "y";
	if ( verify == yes )
	{
		// Create file on server
		
		// Create web root file on server
		
		// Add default file to serve

		// Create apache config entry
		// and write to /etc/apache2/sites-available/[name].conf
	
		// Enable new apache config file
		// run command a2ensite [name].conf
	
		// Restart apache
		// systemctl reload apache2

		// Update hosts file at /etc/hosts
		// Add name entry to end of file 
	
		// Display server location and completion message
		cout << "Your new host has been created.\n";
		cout << "http://" << project_name << ".local\n";
	}
	else
	{
		cout << "Program exit. No host created.\n";
	}
}
