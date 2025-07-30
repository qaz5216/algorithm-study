#include <iostream>
#include <string>
#include <filesystem>
#include <iomanip>   // for setw and setfill
#include <sstream>   // for ostringstream

namespace fs = std::filesystem;

int main() {
    int week;
    std::cout << "WEEK? (EX: 1 - WEEK01): ";
    std::cin >> week;

    // WEEK 폴더 이름 만들기
    std::ostringstream weekFolder;
    weekFolder << "WEEK" << std::setw(2) << std::setfill('0') << week;

    // 경로 설정
    fs::path sourceDir = "C:/algorithm-study/baekjoon";
    fs::path targetDir = fs::path("C:/G4algorithm/Algorithm") / weekFolder.str() / "KM";

    // 디렉토리 존재 확인 및 생성
    if (!fs::exists(targetDir)) {
        fs::create_directories(targetDir);
        std::cout << "Folder create finish: " << targetDir << '\n';
    }
    else {
        std::cout << "Folder Exist: " << targetDir << '\n';
    }

    std::cout << "name.cpp\n input name (-1 :exit):\n";

    while (true) {
        std::string filename;
        std::cin >> filename;

        if (filename == "-1") {
            std::cout << "exit.\n";
            break;
        }
        filename.append(".cpp");
        fs::path sourceFile = sourceDir / filename;
        fs::path targetFile = targetDir / filename;

        if (fs::exists(sourceFile)) {
            try {
                fs::copy_file(sourceFile, targetFile, fs::copy_options::overwrite_existing);
                std::cout << filename << " complete!\n";
            }
            catch (fs::filesystem_error& e) {
                std::cerr << "error: " << e.what() << '\n';
            }
        }
        else {
            std::cerr << "can't find: " << sourceFile << '\n';
        }
    }

    return 0;
}
