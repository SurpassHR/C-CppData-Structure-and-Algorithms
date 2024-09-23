#include <bits/stdc++.h>
#include <string>
using namespace std;

const char* getFileName(const char* path) {
    const char* fileName = path;
    for (const char* p = path; *p; p++) {
        if (*p == '/' || *p == '\\') {
            fileName = p + 1;
        }
    }
    return fileName;
}

void log(const std::string& file, int line, const char* format, ...)
{
    const int BUFFER_SIZE = 1024;
    char buffer[BUFFER_SIZE];

    va_list args;
    va_start(args, format);
    vsnprintf(buffer, BUFFER_SIZE, format, args);
    va_end(args);

    std::string message(buffer);

    printf("[%s:%d]: %s\n", getFileName(file.c_str()), line, message.c_str());
}
#define LOG(format, ...) log(__FILE__, __LINE__, format, ##__VA_ARGS__)

#include <iostream>

class LogicCompModuleCtrlBase {
public:
    LogicCompModuleCtrlBase() {}
    virtual ~LogicCompModuleCtrlBase() {}
    std::string test()
    {
        return "asdasd";
    }
};

typedef unsigned int           VOS_UINT32;

enum CompModuleCtrlObjType : VOS_UINT32 {
    COMPRESSOR_MODULE_CTRL_OBJ_STOP = 0,
    COMPRESSOR_MODULE_CTRL_OBJ_DMD_CTRL,
    COMPRESSOR_MODULE_CTRL_OBJ_VACU_STOP,
    COMPRESSOR_MODULE_CTRL_OBJ_JOG_START,
    COMPRESSOR_MODULE_CTRL_OBJ_EMERG_STOP,
    COMPRESSOR_MODULE_CTRL_OBJ_NUM,
    COMPRESSOR_MODULE_CTRL_OBJ_INVALID
};

class LogicCompModule {
public:
    LogicCompModule() {}
    void Init()
    {
        for (int i = 0; i < COMPRESSOR_MODULE_CTRL_OBJ_NUM; ++i) {
            m_compModuleCtrl[i] = new LogicCompModuleCtrlBase;
        }
    }

    // 默认的析构函数
    ~LogicCompModule() {
        std::cout << "LogicCompModule destructed" << std::endl;
        for (int i = 0; i < COMPRESSOR_MODULE_CTRL_OBJ_NUM; ++i) {
            if (m_compModuleCtrl[i] != nullptr) {
                delete m_compModuleCtrl[i];
                m_compModuleCtrl[i] = nullptr;
            }
        }
    }
    LogicCompModuleCtrlBase *m_compModuleCtrl[COMPRESSOR_MODULE_CTRL_OBJ_NUM]{ nullptr };
};

struct LogicCompSysCtrlData {
    LogicCompModule compModule;
};

void func(LogicCompSysCtrlData& compSysData) {
    auto compModule = compSysData.compModule;  // 浅拷贝
    std::cout << "In func: " << &compModule << std::endl;
    // compModule 的 data 指向同一个内存
}

int main() {
    LogicCompSysCtrlData system;
    system.compModule.Init();
    func(system);
    // 离开 func 后，compModule 离开作用域被析构，导致 system.compModule.data 成为悬空指针

    std::cout << "In main: " << system.compModule.m_compModuleCtrl[0]->test() << std::endl; // 未定义行为，可能会崩溃
    return 0;
}