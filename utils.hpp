#pragma once
#ifndef _UTILS_HPP_
#define _UTILS_HPP_

#include "integrated_cxx_libs.hpp"
#include "colors.hpp"
#include "terminal.hpp"

namespace su {
	struct warning_struct {
		std::vector< std::string > warning;
		std::vector< std::string > warning_L2;
	};

	class custom_exception {
		public:
			custom_exception( std::string type, std::string msg, uint16_t code );
			std::string getType();
			std::string getMsg();
			uint16_t getCode();
		private:
			std::string type;
			std::string msg;
			uint16_t code;
	};

	void arg_function( const uint16_t argc, const char* argv[] );

	/*void write_obj( const std::string& path, Voxel vx[] );*/

	void action_log_save( const std::string& path, const std::string& msg, bool rewrite );

	void action_log_save_new( const std::string& path, const std::string& current_thread, const int current_tick, const std::string& current_file, const std::string& action, const std::string& msg, const std::chrono::duration<float> program_time );

	void error_log_save( const std::string& path, warning_struct warning_list, const std::string& error_text, std::chrono::duration<float> program_time );

	std::chrono::time_point<std::chrono::high_resolution_clock> timer_start();

	std::chrono::duration<float> timer_end( std::chrono::time_point<std::chrono::high_resolution_clock>& start );

}// namespace su ( special utils )

#endif
