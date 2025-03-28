#include "terminal.hpp"

namespace su {
	void terminal() {
		std::vector< std::string > arguments;
		std::string str = "";
		std::string buffer = "";
		std::string cli_user_name = "user";
		std::string terminal_name = "terminal";
		std::string terminal_version = "0.0.2";
		while( true ) {

			std::cout << MAGNETA << cli_user_name << RESET << "@" << BLUE << terminal_name << ": " << CYAN;
			std::getline(std::cin, str);
			str += " ";
			//std::cin >> str;

			for ( int i = 0; i < str.size(); i++ ) {
				if ( str[i] == ' ' && buffer != ""  ) {
					arguments.push_back( buffer );
					buffer = "";
				}
				if ( str[i] == ' ' ) {
					continue;
				}
				buffer += str[i];
			}

			if ( arguments.empty() ) {
				arguments.push_back( "" );
			}

			//for ( int i = 0; i < arguments.size(); i++ ) {
			//	std::cout << MAGNETA << arguments[i] << RESET << "\n";
			//}

			if ( arguments[0] == "mkdir" ) {
				if ( arguments.size() >= 2 ) {
					if ( mkdir( arguments[1].c_str(), 0777) == 0 ) {
						std::cout << GREEN << "new directory created successfully!\n";
					} else {
						std::cout << YELLOW << "failed to create new directory.\n";
					}
				}
				arguments.erase( arguments.begin(), arguments.end() );
				arguments[0] = "";

			} else if ( arguments[0] == "rmdir" ) {
				if ( arguments.size() >= 2 ) {
					if ( rmdir( arguments[1].c_str() ) == 0 ) {
						std::cout << GREEN << "directory remove successfully!\n";
					} else {
						std::cout << YELLOW << "failed to remove directory.\n";
					}
				}
				arguments.erase( arguments.begin(), arguments.end() );
				arguments[0] = "";

			} else if ( arguments[0] == "rm" ) {
				if ( arguments.size() >= 2 ) {
					if ( remove( arguments[1].c_str() ) == 0 ) {
						std::cout << GREEN << "file remove successfully!\n";
					} else {
						std::cout << YELLOW << "failed to remove file.\n";
					}
				}
				arguments.erase( arguments.begin(), arguments.end() );
				arguments[0] = "";

			} else if ( arguments[0] == "mv" ) {
				if ( arguments.size() >= 3 ) {
					if ( rename( arguments[1].c_str(), arguments[2].c_str() ) == 0 ) {
						std::cout << GREEN << "file renamed successfully!\n";
					} else {
						std::cout << YELLOW << "failed to rename file.\n";
					}
				}
				arguments.erase( arguments.begin(), arguments.end() );
				arguments[0] = "";

			} else if ( arguments[0] == "cat" ) {
				if ( arguments.size() >= 2 ) {
					std::ifstream fin;
					fin.open( arguments[1] );

					if ( fin.is_open() ) {
						char ch;
						while ( fin.get( ch ) ) {
							std::cout << ch;
						}
						std::cout << "\n";
						std::cout << GREEN << "file read successfully!\n";
					} else {
						std::cout << YELLOW << "failed to read file.\n";
					}
					fin.close();
				}
				arguments.erase( arguments.begin(), arguments.end() );
				arguments[0] = "";

			} else if ( arguments[0] == "createFile" ) {
				if ( arguments.size() >= 3 ) {
					std::ofstream fout;
					fout.open( arguments[1] );

					if ( fout.is_open() ) {
						for ( int i = 2; i < arguments.size(); i++ ) {
							fout << arguments[i] << " ";
						}
						std::cout << GREEN << "file write successfully!\n";
					} else {
						std::cout << YELLOW << "failed to write file.\n";
					}
					fout.close();
				}
				arguments.erase( arguments.begin(), arguments.end() );
				arguments[0] = "";

			} else if ( arguments[0] == "cd" ) {
				if ( arguments.size() >= 2 ) {
					if ( chdir( arguments[1].c_str() ) == 0 ) {
						std::cout << GREEN << "directory change\n";
					} else {
						std::cout << YELLOW << "failed to change directory.\n";
					}
				}
				arguments.erase( arguments.begin(), arguments.end() );
				arguments[0] = "";

			} else if ( arguments[0] == "ls" ) {
				std::cout << YELLOW << "\r" << std::flush;
				system("dir");
				arguments.erase( arguments.begin(), arguments.end() );
				arguments[0] = "";

			} else if ( arguments[0] == "clear" || arguments[0] == "cls" ) {
				system("clear");
				arguments.erase( arguments.begin(), arguments.end() );
				arguments[0] = "";

			} else if ( arguments[0] == "echo" ) {
				if ( arguments.size() >= 2 ) {
					for ( int i = 1; i < arguments.size(); i++ ) {
						std::cout << RESET << arguments[i] << "\n";
					}
				}
				arguments.erase( arguments.begin(), arguments.end() );
				arguments[0] = "";

			} else if ( arguments[0] == "set" ) {
				if ( arguments.size() >= 3 && arguments[1] == "userName" ) {
					cli_user_name = arguments[2];
				}
				arguments.erase( arguments.begin(), arguments.end() );
				arguments[0] = "";

			} else if ( arguments[0] == "fetch" ) {
				std::cout << "   ╱|、     " << MAGNETA << cli_user_name << RESET << "@" << BLUE << terminal_name << "\n";
				std::cout << "  (˚ˎ 。7   -------------\n";
				std::cout << "   |、˜〵   terminal v" << terminal_version << "\n";
				std::cout << "   じしˍ,)ノdevice: name\n";

				arguments.erase( arguments.begin(), arguments.end() );
				arguments[0] = "";

			} else if ( arguments[0] == "version" ) {
				std::cout << "terminal version: " << terminal_version << "\n";

				arguments.erase( arguments.begin(), arguments.end() );
				arguments[0] = "";

			} else if ( arguments[0] == "exit" ) {
				arguments.erase( arguments.begin(), arguments.end() );
				arguments[0] = "";
				break;

			} else if ( arguments[0] == "" ) {
				arguments.erase( arguments.begin(), arguments.end() );
				arguments[0] = "";
				continue;

			} else {
				std::cout << "unknown command\n";
				arguments.erase( arguments.begin(), arguments.end() );
				arguments[0] = "";
			}
		}// while
	}// terminal()
}
