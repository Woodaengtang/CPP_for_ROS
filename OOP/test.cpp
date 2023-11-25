#include <iostream>
#include <Windows.h>
#include <regex>

int main() {
    // 사용 가능한 시리얼 포트의 이름 가져오기
    DWORD bufferSize = 4096; // 충분한 크기로 조절
    char* deviceNames = new char[bufferSize];

    while (true) {
        DWORD result = QueryDosDeviceA(nullptr, deviceNames, bufferSize);

        if (result == 0) {
            DWORD error = GetLastError();
            if (error == ERROR_INSUFFICIENT_BUFFER) {
                // 버퍼 크기 부족
                delete[] deviceNames;
                bufferSize *= 2; // 현재 크기의 두 배로 증가
                deviceNames = new char[bufferSize];
            }
            else {
                std::cerr << "장치 이름을 가져오는 중 오류 발생. 오류 코드: " << error << std::endl;
                delete[] deviceNames;
                return 1;
            }
        }
        else {
            break; // 성공적으로 장치 이름을 가져옴
        }
    }

    // 정규 표현식을 사용하여 COM 포트를 필터링
    std::regex comPortRegex("COM\\d+");

    // 장치 이름을 구문 분석하고 출력
    std::cout << "사용 가능한 시리얼 포트:" << std::endl;

    char* deviceName = deviceNames;
    while (*deviceName != '\0') {
        std::string name = deviceName;
        if (std::regex_match(name, comPortRegex)) {
            std::cout << name << std::endl;
        }
        deviceName += strlen(deviceName) + 1;
    }

    delete[] deviceNames;

    return 0;
}\