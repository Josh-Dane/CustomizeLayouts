#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <tuple> 

using namespace std;

// Helper function to truncate strings that are too long
string truncate(const string& str, size_t width) {
    if (str.length() > width) {
        return str.substr(0, width - 3) + "...";
    }
    return str;
}

void printHeader() {
    cout << "+-----------------------------------------------------------------------------+\n";
    cout << "| NVIDIA-SMI 551.86       Driver Version: 551.86       CUDA Version: 12.4     |\n";
    cout << "+-------------------------------+----------------------+----------------------+\n";
}

void printGpuSummary() {
    cout << "| GPU  Name        TCC/WDDM     | Bus-Id        Disp.A | Volatile Uncorr. ECC|\n";
    cout << "| Fan  Temp  Perf  Pwr:Usage/Cap| Memory-Usage         | GPU-Util  Compute M. |\n";
    cout << "|===============================+======================+======================|\n";
    cout << "|  0   GeForce GTX 1080 WDDM    | 00000000:26:00.0  On | N/A                  |\n";
    cout << "| 28%  37C   P8    11W / 180W   | 701MiB / 8192MiB     | 0%       Default     |\n";
    cout << "+-------------------------------+----------------------+----------------------+\n";
}

void printProcessList() {
    cout << "| Processes:                                                        GPU Memory |\n";
    cout << "|    GPU   PID   Type   Process name                          Usage            |\n";
    cout << "|=============================================================================|\n";

    vector<tuple<int, int, string, string>> processes = {
        make_tuple(0, 1111, "C+G", "System.exe"),
        make_tuple(0, 2222, "C+G", "GameOverlayUI.exe"),
        make_tuple(0, 3333, "C+G", "Discord.exe"),
        make_tuple(0, 4444, "C+G", "ChromeWithVeryLongProcessNameThatWillBeTruncated.exe"),
        make_tuple(0, 5555, "C+G", "VRAMMonitorTool.exe")
    };

    for (const auto& p : processes) {
        int gpu, pid;
        string type, name;
        tie(gpu, pid, type, name) = p;

        cout << "| " << setw(6) << gpu
            << setw(6) << pid
            << setw(7) << type
            << setw(35) << left << truncate(name, 34)
            << setw(18) << right << "150 MiB" << "|\n";
    }

    cout << "+=============================================================================+\n";
}

int main() {
    printHeader();
    printGpuSummary();
    printProcessList();
    return 0;
}
