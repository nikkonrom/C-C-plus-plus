#pragma once

#ifdef IO_EXPORTS  
#define IO_API __declspec(dllexport)   
#else  
#define IO_API __declspec(dllimport)   
#endif 

#include <boost/lockfree/queue.hpp>
#include <string>
#include <vector>
#include <Windows.h>

namespace io
{
	class io_async
	{
		boost::lockfree::queue<std::string*, boost::lockfree::capacity<50>> * queue_;

		std::vector<std::string> filenames_;
		std::string source_folder_path_;
		std::string output_file_path_;

		HANDLE reader_thread_handle_;
		HANDLE writer_thread_handle_;

		HANDLE data_to_write_exists_event_;
		HANDLE reading_complete_event_;

		HANDLE * events_for_waiting;

		static DWORD WINAPI begin_read(LPVOID parameter);
		static DWORD WINAPI begin_write(LPVOID parameter);

	public:
		IO_API io_async();
		IO_API int concat_files(std::string source_folder_path, std::string output_file_path);
	};
}


