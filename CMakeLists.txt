cmake_minimum_required(VERSION 2.4.6)
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)

# Set the build type.  Options are:
#  Coverage       : w/ debug symbols, w/o optimization, w/ code-coverage
#  Debug          : w/ debug symbols, w/o optimization
#  Release        : w/o debug symbols, w/ optimization
#  RelWithDebInfo : w/ debug symbols, w/ optimization
#  MinSizeRel     : w/o debug symbols, w/ optimization, stripped binaries
#set(ROS_BUILD_TYPE RelWithDebInfo)
add_definitions (-fpermissive)

rosbuild_find_ros_package(srs_assisted_grasping_ui)
rosbuild_find_ros_package(srs_assisted_arm_navigation_ui)
rosbuild_find_ros_package(rviz)
rosbuild_find_ros_package(actionlib_msgs)

include(${actionlib_msgs_PACKAGE_PATH}/cmake/actionbuild.cmake)
genaction()
rosbuild_init()

#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set the default path for built libraries to the "lib" directory
#set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

#uncomment if you have defined messages
rosbuild_genmsg()
#uncomment if you have defined services
rosbuild_gensrv()


# ---------- wxWidgets ---------- #
find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})
include_directories(${wxWidgets_INCLUDE_DIRS})


# ------------ SKYPE ------------ #
set(INC_DEBUG 	$ENV{SKYPE_KIT_PATH}/interfaces/skype/cpp_embedded/src/api 
		$ENV{SKYPE_KIT_PATH}/interfaces/skype/cpp_embedded/src/ipc
		$ENV{SKYPE_KIT_PATH}/interfaces/skype/cpp_embedded/src/types
		$ENV{SKYPE_KIT_PATH}/interfaces/skype/cpp_embedded/src/platform/threading
		$ENV{SKYPE_KIT_PATH}/ipc/cpp
		$ENV{SKYPE_KIT_PATH}/ipc/cpp/platform/se
		$ENV{SKYPE_KIT_PATH}/ipc/cpp/ssl/cyassl/include
		$ENV{SKYPE_KIT_PATH}/ipc/cpp/ssl/cyassl/ctaocrypt/include 
		$ENV{SKYPE_KIT_PATH}/ipc/cpp/ssl/cyassl/include/openssl 
		$ENV{SKYPE_KIT_PATH}/interfaces/skype/cpp_embedded/src/platform/threading/pthread 
		$ENV{SKYPE_KIT_PATH}/examples/cpp/tutorial/keypair)
include_directories(${INC_DEBUG})

set(LIBDIR_DEBUG -L$ENV{SKYPE_KIT_PATH}/interfaces/skype/cpp_embedded/build -L$ENV{SKYPE_KIT_PATH}/bin/linux-x86)
set(LIB_DEBUG $ENV{SKYPE_KIT_PATH}/interfaces/skype/cpp_embedded/build/libskypekit-cppwrapper_2_lib.a $ENV{SKYPE_KIT_PATH}/interfaces/skype/cpp_embedded/build/libskypekit-cyassl_lib.a)
set(SKYPE_LFLAGS ${LIBDIR_DEBUG} ${LIB_DEBUG})



# ---------- srs_ui_pro --------- #
#set(INCLUDE_DIRECTORIES ${srs_assisted_arm_navigation_ui_PACKAGE_PATH}/include
			#${srs_assisted_grasping_ui_PACKAGE_PATH}/include)

#set(LIB_DIRECTORIES ${srs_assisted_arm_navigation_ui_PACKAGE_PATH}/lib
			#${srs_assisted_grasping_ui_PACKAGE_PATH}/lib)

#include_directories(${INCLUDE_DIRECTORIES} ${LIB_DIRECTORIES} ${rviz_PACKAGE_PATH})
#include_directories(${rviz_PACKAGE_PATH})



set(SOURCE_FILES src/GUI/srs_ui_proApp.cpp 
		src/GUI/LogginScreen.cpp 
		src/GUI/srs_ui_proMain.cpp 
		src/GUI/ObjectInfo.cpp 
		src/GUI/RosInterface.cpp 
		#src/GUI/RvizInterface.cpp 
		src/GUI/ProcessManager.cc 
		src/GUI/SkypeFunctions.cpp 
		src/GUI/SkypeWindow.cpp 
		src/GUI/SkypeWindow2.cpp
		src/GUI/DM_window.cpp)

#set(EXT_SOURCE_FILES ${srs_assisted_grasping_ui_PACKAGE_PATH}/src/grasping_display.cpp
			#${srs_assisted_grasping_ui_PACKAGE_PATH}/src/grasping_controls.cpp
			#${srs_assisted_arm_navigation_ui_PACKAGE_PATH}/src/arm_navigation_display.cpp
			#${srs_assisted_arm_navigation_ui_PACKAGE_PATH}/src/arm_navigation_controls.cpp
			#${rviz_PACKAGE_PATH}/src/rviz/default_plugin/grid_display.cpp
			#${rviz_PACKAGE_PATH}/src/rviz/default_plugin/camera_display.cpp
			#${rviz_PACKAGE_PATH}/src/rviz/default_plugin/grid_cells_display.cpp
			#${rviz_PACKAGE_PATH}/src/rviz/default_plugin/map_display.cpp
			#${rviz_PACKAGE_PATH}/src/rviz/default_plugin/marker_display.cpp
			#${rviz_PACKAGE_PATH}/src/rviz/default_plugin/point_cloud2_display.cpp
			#${rviz_PACKAGE_PATH}/src/rviz/default_plugin/robot_model_display.cpp
#)



set(FLAGS ${wxWidgets_LIBRARIES} ${SKYPE_LFLAGS})
#set(LIBS default_plugin but_assisted_plugins but_assisted_grasping_plugin but_gui but_env_model_gui)
#set(SOURCE_FILES ${SOURCE_FILES})# ${EXT_SOURCE_FILES})

rosbuild_add_executable(srs_ui_pro ${SOURCE_FILES})
target_link_libraries(srs_ui_pro  ${FLAGS} ${LIBS})

