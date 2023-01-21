# for now, it's not work, because I don't use ./relase as release build folder like tutorial, I use ../Step12_build_release
include("release/CPackConfig.cmake")

set(CPACK_INSTALL_CMAKE_PROJECTS
        "debug;Tutorial;all;/"
        "release;Tutorial;all;/"
        )