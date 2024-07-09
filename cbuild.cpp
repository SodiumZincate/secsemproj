#define CBUILD_IMPLEMENTATION
#include "cbuild.h"

#include <fstream>

void copy_file(const std::string& to, const std::string& from) {
	std::ifstream  src(from, std::ios::binary);
	std::ofstream  dst(to, std::ios::binary);
	dst << src.rdbuf();
	dst.close();

	LOG("Copying file from %s -> %s", from.c_str(), to.c_str());
}

bool file_exists(const std::string& path) {
	std::ifstream f(path);
	return f.good();
}

void copy_dlls() {
#ifdef _WIN32
	std::filesystem::create_directories("bin/platforms");

	copy_file("bin/platforms/qwindows.dll", "requisite/qt/lib/windows/platforms/qwindows.dll");
	copy_file("bin/Qt6Core.dll",            "requisite/qt/lib/windows/Qt6Core.dll");
	copy_file("bin/Qt6Widgets.dll",         "requisite/qt/lib/windows/Qt6Widgets.dll");
	copy_file("bin/Qt6Gui.dll",             "requisite/qt/lib/windows/Qt6Gui.dll");
	copy_file("bin/sqlite3.dll",             "requisite/server/lib/windows/sqlite3.dll");
#elif defined(__linux__)
	copy_file("bin/libQt6Core.so.6",    "requisite/qt/lib/linux/libQt6Core.so.6");
	copy_file("bin/libQt6Widgets.so.6", "requisite/qt/lib/linux/libQt6Widgets.so.6");
	copy_file("bin/libQt6Gui.so.6",     "requisite/qt/lib/linux/libQt6Gui.so.6");
#endif
}

void build(char** argv) {
	CBuild cbuild("g++");
	cbuild
		.out("bin", "league")
		.flags({
			"-fPIC -Wl,-rpath='$ORIGIN'", "-std=c++17"
		})
		.inc_paths({
			"requisite/qt/include",
            "requisite/server/include",
			"src"
		})

#ifdef _WIN32
		.lib_paths({
			"requisite/qt/lib/windows",
			"requisite/server/lib/windows"
		})
#elif defined(__linux__)
		.lib_paths({
			"requisite/qt/lib/linux"
		})
#endif
		.libs({
			"Qt6Widgets",
			"Qt6Core",
			"Qt6Gui",
			"sqlite3",
			#ifdef _WIN32
<<<<<<< HEAD
            "ws2_32", // Requrired for server
			#endif
		})
		.src({
			"src/loginUI.cpp",
			"src/main.cpp",
			"src/loginWidget.cpp",
			"src/db.cpp"
=======
            "ws2_32", // Requrired for server on windows
			#endif
		})
		.src({
			// "src/loginUI.cpp",
			"src/main.cpp",
			// "src/practice.cpp"
			// "src/loginWidget.cpp",
			// "src/db.cpp"
>>>>>>> 150b05b6863b4c005ecd88bdc99fd3aa85762c80
		})
		.moc_src({
			"src/loginUI.h"
		})
		.build_moc()  // Generate .moc.cpp files
        .compile()    // Compile all source files
		.build()
		.clean();

	copy_dlls();
	cbuild.run();
}

int main(int argc, char** argv) {
    cbuild_rebuild(argc, argv);
    build(argv);
    return 0;
}
