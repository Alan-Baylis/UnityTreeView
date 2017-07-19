#pragma once

#include <string>
#include <windows.h>

namespace UnityTreeView {
	public ref class Extras {
		public: static std::string GetExecutablePath()
		{
			char result[MAX_PATH];
			std::string pathName (result, GetModuleFileNameA(NULL, result, MAX_PATH));
			return pathName.substr(0, pathName.find_last_of("/\\"));
		}

		public: static std::string ReplaceAll(std::string str, const std::string& from, const std::string& to) {
			size_t start_pos = 0;
			while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
				str.replace(start_pos, from.length(), to);
				start_pos += to.length();
			}
			return str;
		}
	};
}