// newhost.cpp

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	// Get project root file name
	string dir_name;
	cout << "Project name (/var/www/html/[name].local): ";
	getline( cin, dir_name );

	// Get public web root
	string web_root;
	cout << "Enter web root (leave blank for public_html): ";
	getline( cin, web_root );
	if (web_root.empty())
		web_root = "public_html";

	// Get the OK to proceed
	string verify;
	cout << "Create /var/www/html/" << dir_name << "/" << web_root << "? (y/n) ";
	getline( cin, verify );

	string yes = "y";
	if ( verify == yes )
	{
		// Setup host
		
		string str1;
		// Create project folder/directory in apache html root
		str1 = "mkdir \"/var/www/html/" + dir_name + "\"";
		system(str1.c_str());

		// Create logs directory
		str1 = "mkdir \"/var/www/html/" + dir_name + "/logs\"";
		system(str1.c_str());

		// Create web root directory
		str1 = "mkdir \"/var/www/html/" + dir_name + "/" + web_root + "\"";
		system(str1.c_str());

		// Create web root file on server
		str1 = "touch /var/www/html/" + dir_name + "/" + web_root + "/index.php";
		system(str1.c_str());

		// Set user
		str1 = "chown -R $USER:www-data /var/www/html/" + dir_name;
		system(str1.c_str());
		
		// TODO: Create apache config entry
		// at /etc/apache2/sites-available/[name].conf
		/*
		str1 = "/var/www/html/" + dir_name + "/" + web_root + "/index.php";
		ofstream file;
		file.open(str1);
		file << "<?php\n echo \"Hello, World\"\n ?>\n";
		file.close();
		*/

		/*
		<Directory /var/www/html/drupal8/web>
        	AllowOverride All
		</Directory>
		<VirtualHost *:80>
				ServerName drupal8.local
				ServerAlias www.drupal8.local
				ServerAdmin webmaster@localhost
				DocumentRoot /var/www/html/drupal8/web
				ErrorLog /var/www/html/drupal8/logs/error.log
				CustomLog /var/www/html/drupal8/logs/access.log combined
		</VirtualHost>
		*/

		// Enable new apache host
		//str1 = "sudo a2ensite " + dir_name + ".local.conf";
		//system(str1.c_str());
	
		// Restart apache
		//str1 = "sudo systemctl reload apache2";
		//system(str1.c_str());

		// TODO: Update hosts file 
		// at /etc/hosts 
	
		// Display server location and completion message
		cout << "Your new host has been created.\n";
		cout << "http://" << dir_name << ".local\n";
	}
	else
	{
		// Do nothing and quit
		cout << "Program exit. No host created.\n";
	}
}
