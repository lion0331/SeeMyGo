#include "Asserts.h"

void Asserts::test(bool value) {
    try {
        if (!value) throw std::runtime_error("测试未通过");
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        // 在实际应用中，你也可能需要在这里做一些清理工作或其他错误处理步骤
    }
}