#ifndef DIR_COMPARE_H
#define DIR_COMPARE_H


#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

bool compareFiles(filesystem::path& path1, filesystem::path& path2);

void listFiles(filesystem::path& dir, std::unordered_map<string, filesystem::path>& files);

void generateFile(string fileName, vector<string> files);

void validateDirectory(string& dir);

void generateInput(string& dir1, string& dir2);

void generateFileLists(vector<string>& sameFiles, vector<string>& dirA, vector<string>& dirB, 
					   unordered_map<string, filesystem::path> files1, unordered_map<string, filesystem::path> files2);

#endif // DIR_COMPARE_H