# TODO 5: add MakeTable
add_executable(MakeTable MakeTable.cxx)
add_custom_command(OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/Table.h"
        COMMAND MakeTable "${CMAKE_CURRENT_BINARY_DIR}/Table.h"
        DEPENDS MakeTable)

# TODO 6: let MathFunctions use Table.h
#add_library(MathFunctions mysqrt.cxx)
add_library(MathFunctions mysqrt.cxx ${CMAKE_CURRENT_BINARY_DIR}/Table.h)

# TODO 7: include Table.h
# state that anybody linking to us needs to include the current source dir
# to find MathFunctions.h, while we don't.
#target_include_directories(MathFunctions
#          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
#          )
message("CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR}")
target_include_directories(MathFunctions
        INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
        PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
        )

# link our compiler flags interface library
target_link_libraries(MathFunctions tutorial_compiler_flags)

# TODO 4: remove check for log and exp
# does this system provide the log and exp functions?
#include(CheckCXXSourceCompiles)
#check_cxx_source_compiles("
#  #include <cmath>
#  int main() {
#    std::log(1.0);
#    return 0;
#  }
#" HAVE_LOG)
#check_cxx_source_compiles("
#  #include <cmath>
#  int main() {
#    std::exp(1.0);
#    return 0;
#  }
#" HAVE_EXP)
#
## add compile definitions
#if(HAVE_LOG AND HAVE_EXP)
#  target_compile_definitions(MathFunctions
#                             PRIVATE "HAVE_LOG" "HAVE_EXP")
#endif()

# install libs
set(installable_libs MathFunctions tutorial_compiler_flags)
install(TARGETS ${installable_libs} DESTINATION lib)
# install include headers
install(FILES MathFunctions.h DESTINATION include)
