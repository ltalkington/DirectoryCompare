#include "DirCompare.h"

int main()
{
    //GenerateFile("common.txt");
    // Retrieve the inputs for the directories
    string dir1;
    string dir2;
    generateInput(dir1, dir2);
    filesystem::path dirPath1 = dir1;
    filesystem::path dirPath2 = dir2;
    unordered_map<string, filesystem::path> files1;
    unordered_map<string, filesystem::path> files2;
    // get all items from that path
    listFiles(dirPath1, files1);
    listFiles(dirPath2, files2);

    vector<string> sameFiles;
    vector<string> dirAOnly;
    vector<string> dirBOnly;

    generateFileLists(sameFiles, dirAOnly, dirBOnly, files1, files2);

    generateFile("common.txt", sameFiles);
    generateFile("a_only.txt", dirAOnly);
    generateFile("b_only.txt", dirBOnly);
}
