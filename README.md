# DirectoryCompare
This application is meant to compare two directories and output the following items:
1. Common Files
2. Files in DirectoryA
3. Files in DirectoryB

The file has an input of two directories and the user will be prompted for that information before any comparison starts. After that validation, the two directories will be compared based on a binary difference of the files in question. Lastly, the three files that are listed below will be created. 
1. common.txt
2. a_only.txt
3. b_only.txt

# How to Build/run
This code is generated via a MakeFile that is stored in this repository. It has the following commands below. 

1. `make -f MakeFile clean` (this cleans the bin/obj folders)
2. `make -f MakeFile build` (this will build the main application)
3. `make -f MakeFile build_tests`(This will build the tests for this application)
4. `make -f MakeFile run` (This will run the main application)
5. `make -f MakeFile tests` (This will run the tests)

Further information: This code was built and tested in Windows and uses C++17. This code was not tested on Linux or UNIX (MacOS)

# Testing Decisions
This code was tested under the following ideals:
1. Test the major functions of this application on two file sets (same file, not same file) and assert that the return is what is expected.
2. Throughput test, ensure the test can handle over 10k files in a directory and still outputs what is expected.
3. Tested Manually with multiple different directories. 

Other considerations but not applied:
1. Test each function output individually. This could have been applied and roughly was but if the output is what is to be expected then each item should be working.
2. Tested the actual output file line by line with a file that should be the same. 
