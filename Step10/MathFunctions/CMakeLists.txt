add_library(MathFunctions
        MathFunctions.cxx
        )

option(USE_MYMATH "Use tutorial provided math implementation" ON)

if(USE_MYMATH)
  target_compile_definitions(MathFunctions PRIVATE "USE_MY_PATH")
  add_executable(MakeTable MakeTable.cxx)

  # add the command to generate the source code
  add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
    COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
    DEPENDS MakeTable
    )

  # add the main library

  add_library(SqrtLibrary STATIC mysqrt.cxx)

  # state that anybody linking to us needs to include the current source dir
  # to find MathFunctions.h, while we don't.
  # state that we depend on our binary dir to find Table.h
  target_link_libraries(SqrtLibrary
          PUBLIC tutorial_compiler_flags)
  target_include_directories(SqrtLibrary PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

  target_link_libraries(MathFunctions PRIVATE SqrtLibrary)
  target_include_directories(MathFunctions
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
else()
  # link our compiler flags interface library
  target_link_libraries(MathFunctions tutorial_compiler_flags)
endif()


# install libs
set(installable_libs MathFunctions tutorial_compiler_flags)
install(TARGETS ${installable_libs} DESTINATION lib)
# install include headers
install(FILES MathFunctions.h DESTINATION include)
