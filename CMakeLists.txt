cmake_minimum_required(VERSION 3.3)
project(QSysLinux
	VERSION 1.0.0
	DESCRIPTION "Library to retrieve Linux kernel version"
)
find_package(Qt5 REQUIRED Core)
include(GNUInstallDirs)  # REQUIRED TO INSTALL PKGCONFIG TO PROPER DIR!
include_directories(${PROJECT_SOURCE_DIR})
add_library(${PROJECT_NAME} INTERFACE
	qsyslinux.h
)
target_link_libraries(${PROJECT_NAME} INTERFACE Qt5::Core )

set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION}
	SOVERSION 1
)
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER qsyslinux.h)
configure_file(qsyslinux.pc.in qsyslinux.pc @ONLY)
install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
install(FILES ${CMAKE_BINARY_DIR}/qsyslinux.pc DESTINATION
	${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)

add_executable(qsyslinuxtest main.cpp)
target_link_libraries(qsyslinuxtest Qt5::Core ${PROJECT_NAME})
