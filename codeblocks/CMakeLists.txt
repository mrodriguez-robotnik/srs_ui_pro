cmake_minimum_required(VERSION 2.4.6)
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)

# Set the build type.  Options are:
#  Coverage       : w/ debug symbols, w/o optimization, w/ code-coverage
#  Debug          : w/ debug symbols, w/o optimization
#  Release        : w/o debug symbols, w/ optimization
#  RelWithDebInfo : w/ debug symbols, w/ optimization
#  MinSizeRel     : w/o debug symbols, w/ optimization, stripped binaries
#set(ROS_BUILD_TYPE RelWithDebInfo)


#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ../${PROJECT_SOURCE_DIR}/bin)
#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ../${PROJECT_SOURCE_DIR}/lib)


#srs_ui_pro:
find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})
include_directories(${wxWidgets_INCLUDE_DIRS})

set(SKYPE_KIT_PATH $ENV{SKYPE_KIT_PATH})
set(INC_DEBUG ${SKYPE_KIT_PATH}interfaces/skype/cpp_embedded/src/api ${SKYPE_KIT_PATH}interfaces/skype/cpp_embedded/src/ipc ${SKYPE_KIT_PATH}interfaces/skype/cpp_embedded/src/types ${SKYPE_KIT_PATH}interfaces/skype/cpp_embedded/src/platform/threading ${SKYPE_KIT_PATH}ipc/cpp ${SKYPE_KIT_PATH}ipc/cpp/platform/se ${SKYPE_KIT_PATH}ipc/cpp/ssl/cyassl/include ${SKYPE_KIT_PATH}ipc/cpp/ssl/cyassl/ctaocrypt/include ${SKYPE_KIT_PATH}ipc/cpp/ssl/cyassl/include/openssl ${SKYPE_KIT_PATH}interfaces/skype/cpp_embedded/src/platform/threading/pthread ${SKYPE_KIT_PATH}examples/cpp/tutorial/keypair)
include_directories(${INC_DEBUG})

set(LIBDIR_DEBUG -L${SKYPE_KIT_PATH}interfaces/skype/cpp_embedded/build -L${SKYPE_KIT_PATH}bin/linux-x86)
set(LIB_DEBUG ${SKYPE_KIT_PATH}interfaces/skype/cpp_embedded/build/libskypekit-cppwrapper_2_lib.a ${SKYPE_KIT_PATH}interfaces/skype/cpp_embedded/build/libskypekit-cyassl_lib.a)
set(SKYPE_LFLAGS ${LIBDIR_DEBUG} ${LIB_DEBUG})


rosbuild_add_executable(srs_ui_pro ../src/GUI/srs_ui_proApp.cpp ../src/GUI/srs_ui_proMain.cpp ../src/GUI/ObjectInfo.cpp ../src/GUI/RosInterface.cpp ../src/GUI/ProcessManager.cc ../src/GUI/SkypeFunctions.cpp ../src/GUI/SkypeWindow.cpp ../src/GUI/SkypeWindow2.cpp)
target_link_libraries(srs_ui_pro ${wxWidgets_LIBRARIES} ${SKYPE_LFLAGS})
      
