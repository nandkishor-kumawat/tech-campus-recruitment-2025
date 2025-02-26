#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

void extractLogs(const string &logFilePath, const string &date)
{
    ifstream logFile(logFilePath);
    if (!logFile)
    {
        cerr << "Error: Unable to open log file: " << logFilePath << endl;
        return;
    }

    string outputDir = "output";
    if (!fs::exists(outputDir))
    {
        fs::create_directory(outputDir);
    }

    string outputFilePath = outputDir + "/output_" + date + ".txt";
    ofstream outputFile(outputFilePath);
    if (!outputFile)
    {
        cerr << "Error: Unable to create output file: " << outputFilePath << endl;
        return;
    }

    string line;
    while (getline(logFile, line))
    {
        if (line.substr(0, 10) == date)
        {
            outputFile << line << endl;
        }
    }

    logFile.close();
    outputFile.close();

    cout << "Logs for " << date << " have been saved to: " << outputFilePath << endl;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cerr << "Usage: ./extract_logs <log_file> <YYYY-MM-DD>\n";
        return 1;
    }

    string logFile = argv[1];
    string date = argv[2];

    extractLogs(logFile, date);

    return 0;
}