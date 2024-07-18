// DirCompare.cpp : This file compares two directories and will output three files 
//                  (common.txt, a_only.txt, and b_only.txt) resulting from scanning the directories.
//
#include "DirCompare.h"

void generateFileLists(vector<string>& sameFiles, vector<string>& dirAOnly, vector<string>& dirBOnly, unordered_map<string, filesystem::path> files1, unordered_map<string, filesystem::path> files2)
{
    for (auto& [filename, path] : files1)
    {
        if (files2.find(filename) != files2.end()) {
            if (compareFiles(path, files2[filename])) {
                sameFiles.push_back(filename);
            }
            else
            {
                dirAOnly.push_back(filename);
            }
            
        }
        else
        {
            dirAOnly.push_back(filename);
        }
    }

    for (auto& [filename, path] : files2)
    {
        if (find(sameFiles.begin(), sameFiles.end(), filename) == sameFiles.end() )
        {
            dirBOnly.push_back(filename);
        }
    }
}
bool compareFiles(filesystem::path& path1, filesystem::path& path2)
{
    ifstream file1(path1, ios::binary);
    ifstream file2(path2, ios::binary);

    if (!file1.is_open())
    {
        cerr << "Couldn't open up the first file" << endl;
        return false;
    }
    if (!file2.is_open())
    {
        cerr << "Couldn't open up the second file" << endl;
        return false;
    }

    istreambuf_iterator<char> begin1(file1), end1;
    istreambuf_iterator<char> begin2(file2), end2;
    return equal(begin1, end1, begin2, end2);
}

void listFiles(filesystem::path& dir, std::unordered_map<string, filesystem::path>& files)
{
    for (const auto& entry : filesystem::recursive_directory_iterator(dir))
    {
        if (filesystem::is_regular_file(entry.path()))
        {
            files[entry.path().filename().string()] = entry.path();
        }
    }

}

void generateFile(string fileName, vector<string> files)
{
    ofstream outfile(fileName);

    if (!outfile)
    {
        cout << "File was not made" << endl;
    }
    for (const auto& file : files)
    {
        outfile << file << endl;
    }

    outfile.close();
    cout << fileName << " has been created" << endl;

}

void validateDirectory(string& dir)
{
    bool dirExists = false;
    while (!dirExists)
    {
        cin >> dir;
        dirExists = filesystem::exists(dir) && filesystem::is_directory(dir);
        if (dirExists)
        {
            cout << "Thank you.." << endl;
        }
        else
        {
            cout << "Please try again that last directory was invalid: " << endl;
        }
    }
}

void generateInput(string& dir1, string& dir2)
{
    cout << "Enter the first directory: ";
    validateDirectory(dir1);

    cout << "Enter the second directory: ";
    validateDirectory(dir2);
}