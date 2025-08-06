#include <iostream>
#include <string>
#include <filesystem>
#include <iomanip>   // for setw and setfill
#include <sstream>   // for ostringstream
#include <map>

using namespace std;
namespace fs = filesystem;
map<string,bool> namedata;

int main() {
    namedata["KM"]=true;
    namedata["JS"]=true;
    namedata["JY"]=true;
    namedata["MJ"]=true;
    string name;
    while(1){
        cout << "Name? (EX:KM,JS,JY,MJ): ";
        cin>>name;
        if(namedata[name]) break;
        else{
            cout<<"name err\n";
        }
    }
    int week;
    cout << "WEEK? (EX: 1 - WEEK01): ";
    cin >> week;

    // WEEK 폴더 이름 만들기
    ostringstream weekFolder;
    weekFolder << "WEEK" << setw(2) << setfill('0') << week;
    fs::path sourceDir;
    // 경로 설정
    if(name=="KM"){
        sourceDir = "C:/algorithm-study/baekjoon";
    }
    else{
        cout << "sourceDir( ex)C:/algorithm-study/baekjoon ) :";
        cin >> sourceDir;
    }
    fs::path targetDir;
    if(name=="KM"){
        targetDir = fs::path("C:/G4algorithm/Algorithm") / weekFolder.str() / name;
    }
    else{
        cout << "targetDir( ex)C:/G4algorithm/Algorithm ) :";
        cin >> targetDir;
        targetDir=fs::path(targetDir) / weekFolder.str() / name;
    }
    // 디렉토리 존재 확인 및 생성
    if (!fs::exists(targetDir)) {
        fs::create_directories(targetDir);
        cout << "Folder create finish: " << targetDir << '\n';
    }
    else {
        cout << "Folder Exist: " << targetDir << '\n';
    }

    cout << "name.cpp\n input name (-1 :exit):\n";

    while (true) {
        string filename;
        cin >> filename;

        if (filename == "-1") {
            cout << "exit.\n";
            break;
        }
        filename.append(".cpp");
        fs::path sourceFile = sourceDir / filename;
        fs::path targetFile = targetDir / filename;

        if (fs::exists(sourceFile)) {
            try {
                fs::copy_file(sourceFile, targetFile, fs::copy_options::overwrite_existing);
                cout << filename << " complete!\n";
            }
            catch (fs::filesystem_error& e) {
                cerr << "error: " << e.what() << '\n';
            }
        }
        else {
            cerr << "can't find: " << sourceFile << '\n';
        }
    }

    return 0;
}
