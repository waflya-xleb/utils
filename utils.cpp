#include "utils.hpp"

namespace su {
	custom_exception::custom_exception( std::string type, std::string msg, uint16_t code ) {
		this->type = type;
		this->msg = msg;
		this->code = code;
	}// constructor custom_exception

	std::string custom_exception::getType() {
		return type;
	}// getType()

	std::string custom_exception::getMsg() {
		return msg;
	}// getMsg()

	uint16_t custom_exception::getCode() {
		return code;
	}// getCode()

	void arg_function( const uint16_t argc, const char* argv[] ) {
		for ( uint16_t i = 0; i < argc; i++ ) {
			if ( std::string( argv[1] ) == "--help" || std::string( argv[1] ) == "-h" ) {
				std::cout << "-a, --arg <---- показать передаваемые аргументы\n-h, --help <---- показать список команд\n";
				exit( 0 );
			}
			if ( std::string( argv[i] ) == "--arg" || std::string( argv[i] ) == "-a" ) {
				std::cout << BLUE << "\ninput arguments when running the " << argv[0] << ": " << argc << "\n\n";
				for ( uint16_t j = 0; j < argc; j++ ) {
					std::cout << MAGNETA << "argument " << j << ": " << argv[j] << "\n";
				}
				std::cout << "\n";
			}
		}
	}// arg_foo()


	void write_obj( const std::string& path, Voxel vx[] ) {
		std::ofstream fout;
		fout.open( path );

		if ( !fout.is_open() ) {
			throw std::runtime_error( "\nfailed to write obj!\n" );
		} else {
			for ( int i = 0; i < 2; i++ ) {
				fout << "v ";
				for ( int j = 0; j < 3; j++ ) {
					fout << vx[i].xyz[j] << " ";
				}
				fout << "\n";
			}
		}
		fout.close();
	}// write_obj()

	void log_save_new( const std::string& path, const std::string& msg, bool rewrite ) {
		std::ofstream fout;
		if ( !rewrite ) {
			fout.open( path, std::ofstream::app );
		} else {
			fout.open( path );
		}

		if ( !fout.is_open() ) {
			throw std::runtime_error( "\nfailed to save log!\n" );
		} else {
			std::time_t now_time = std::chrono::system_clock::to_time_t( std::chrono::system_clock::now() );
			std::string str = std::ctime( &now_time );

			str.erase( remove( str.begin(), str.end(), ' ' ), str.end() );

			std::string year;
			std::string month;
			std::string day;
			std::string time;
			// current_thread = 'M' main, 'G' graphics, 'ML' main loop, 'MTH' math, etc.

			for ( int i = 3; i < 6; i++ ) {
				month.push_back( str[i] );
			}
			for ( int i = 6; i < 8; i++ ) {
				day.push_back( str[i] );
			}
			for ( int i = 8; i < 16; i++ ) {
				time.push_back( str[i] );
			}
			for ( int i = 16; i < str.size() - 1; i++ ) {
				year.push_back( str[i] );
			}

			if ( month == "Mar" ) {
				month = "03";
			}

			fout << "[" << year << "." << month << "." << day << " " << time << "]   " << msg << "\n";
		}
		fout.close();
	}// log_save_new()

	void log_save_new( const std::string& path, const std::string& current_thread, const int current_tick, const std::string& current_file, const std::string& action, const std::string& msg, const std::chrono::duration<float> program_time ) {
		std::ofstream fout;
		fout.open( path, std::ofstream::app );

		if ( !fout.is_open() ) {
			throw std::runtime_error( "\nfailed to save log!\n" );
		} else {
			std::time_t now_time = std::chrono::system_clock::to_time_t( std::chrono::system_clock::now() );
			std::string str = std::ctime( &now_time );

			str.erase( remove( str.begin(), str.end(), ' ' ), str.end() );

			std::string year;
			std::string month;
			std::string day;
			std::string time;
			uint8_t tab_space_size = 35;
			std::string tab_space;
			// current_thread = 'M' main, 'G' graphics, 'ML' main loop, 'MTH' math, etc.

			for ( int i = 3; i < 6; i++ ) {
				month.push_back( str[i] );
			}
			for ( int i = 6; i < 8; i++ ) {
				day.push_back( str[i] );
			}
			for ( int i = 8; i < 16; i++ ) {
				time.push_back( str[i] );
			}
			for ( int i = 16; i < str.size() - 1; i++ ) {
				year.push_back( str[i] );
			}

			if ( month == "Mar" ) {
				month = "03";
			}

			tab_space_size = ( tab_space_size - current_file.size() ) - action.size();
			for ( int i = 0; i < tab_space_size; i++ ) {
				tab_space.push_back( ' ' );
			}

			fout << "[" << current_thread << "] " << year << "." << month << "." << day << " " << time << " " << current_tick << " [ " << current_file << "\t" << action << tab_space << " ] -" << msg << "\n";

		}
		fout.close();
	}// log_save_new()

	void log_save( const std::string& path, warning_struct warning_list, const std::string& error_text, std::chrono::duration<float> program_time ) {
		std::ofstream fout;
		fout.open( path );

		if ( !fout.is_open() ) {
			throw std::runtime_error( "\nfailed to save log!\n" );
		} else {
			fout << "<====================-LOG-FILE-====================>\n\n";
			fout <<	"PROGRAM STATUS: end are success!\n\n";
			fout <<	"=====================-DATE-=====================\n\n";
			std::time_t now_time = std::chrono::system_clock::to_time_t( std::chrono::system_clock::now() );
			fout << std::ctime( &now_time ) << "\n";
			fout <<	"=====================-WARNING-=====================\n\n";
			fout << "warning count: " << warning_list.warning.size() << "\n";
			fout << "---------------------\n";
			for ( uint16_t i = 0; i < warning_list.warning.size(); i++ ) {
				fout << "warning: " << warning_list.warning[i] << "\n";
			}
			fout << "\n";

			fout << "=====================-WARNING_L2-=====================\n\n";
			fout << "warning_L2 count: " << warning_list.warning_L2.size() << "\n";
			fout << "---------------------\n";
			for ( uint16_t i = 0; i < warning_list.warning_L2.size(); i++ ) {
				fout << "warning_L2: " << warning_list.warning_L2[i] << "\n";
			}
			fout << "\n";

			fout <<	"=====================-ERROR-=====================\n\n";
			fout << error_text << "\n\n";
			fout <<	"=====================-ABOUT-PROGRAM-=====================\n\n";
			fout << "program time: " << program_time << "\n\n";
			fout << "<====================-END-FILE-====================>\n";
		}
		fout.close();
	}// log_save()

	void error_log_save( const std::string& path, warning_struct warning_list, const std::string& error_text, std::chrono::duration<float> program_time ) {
		std::ofstream fout;
		fout.open( path );

		if ( !fout.is_open() ) {
			throw std::runtime_error( "\nfailed to save log!\n" );
		} else {
			fout << "<====================-LOG-FILE-====================>\n\n";
			fout <<	"PROGRAM STATUS: the program has stopped.\n\n";
			fout <<	"=====================-DATE-=====================\n\n";
			std::time_t now_time = std::chrono::system_clock::to_time_t( std::chrono::system_clock::now() );
			fout << std::ctime( &now_time ) << "\n";
			fout <<	"=====================-WARNING-=====================\n\n";
			fout << "warning count: " << warning_list.warning.size() << "\n";
			fout << "---------------------\n";
			for ( uint16_t i = 0; i < warning_list.warning.size(); i++ ) {
				fout << "warning: " << warning_list.warning[i] << "\n";
			}
			fout << "\n";

			fout << "=====================-WARNING_L2-=====================\n\n";
			fout << "warning_L2 count: " << warning_list.warning_L2.size() << "\n";
			fout << "---------------------\n";
			for ( uint16_t i = 0; i < warning_list.warning_L2.size(); i++ ) {
				fout << "warning_L2: " << warning_list.warning_L2[i] << "\n";
			}
			fout << "\n";

			fout <<	"=====================-ERROR-=====================\n\n";
			fout << error_text << "\n\n";
			fout <<	"=====================-ABOUT-PROGRAM-=====================\n\n";
			fout << "program time: " << program_time << "\n\n";
			fout << "<====================-END-FILE-====================>\n";
		}
		fout.close();
	}// error_log_save()

	std::chrono::time_point<std::chrono::high_resolution_clock> timer_start() {
		std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
		return start;
	}// timer_start()

	std::chrono::duration<float> timer_end( std::chrono::time_point<std::chrono::high_resolution_clock>& start ) {
		std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> duration = end - start;
		return duration;
	}// timer_end()

}// namespace su ( special utils )
