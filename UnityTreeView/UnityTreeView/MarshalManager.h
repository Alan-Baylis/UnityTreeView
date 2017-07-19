#pragma once

#include <stdio.h>
#include <string>
#include <msclr\marshal_cppstd.h>

namespace UnityTreeView {
	using namespace msclr::interop;
	public ref class MarshalManager
	{
		public: static System::String^ StdToSys(std::string string) {
			return gcnew System::String(string.c_str());
		}
		public: static System::String^ StdToSys(char* string) {
			return gcnew System::String(string);
		}
		public: static std::string SysToStd(System::String^ string) {
			return marshal_as<std::string>(string);
		}
	};
}

