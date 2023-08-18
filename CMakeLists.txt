
cmake_minimum_required	(VERSION 3.1)

message(STATUS "*** Building Indie Studio version ${VERSION_STRING} // ALLAH's Bomberman! ***")

project(indie_studio) #NOM DU PROJET

set			(IRRLICHT Irrlicht)
set 		(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}")

#set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE}) #LA Où ON VEUT SORTIR LE BINAIRE (facultatif)
#set(SFML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/cmake/SFML2/lib/cmake/SFML")
#set(CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/SFML2/lib/cmake/SFML")
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/SFML2/lib/cmake/SFML")
#find_package(SFML 2.5.1 REQUIRED audio graphics system)
file(
    GLOB_RECURSE
    sources_files #Nom de la Variable contenant les Dossiers
    src/* #Dossier contenant des fichiers( "*" pour dire tous les fichiers)
)
file(
    GLOB_RECURSE
    dll_sfml #Nom de la Variable contenant les Dossiers
    cmake/SFML2/bin/* #Dossier contenant des fichiers( "*" pour dire tous les fichiers)
	cmake/SFML2/lib/*.lib
)

add_executable(
    bomberman #Nom de l'executable
    ${sources_files} #Variable contenant les Dossiers qui eux contiennes des fichiers
)
include_directories	(include)
include_directories	(include/Menu)
include_directories	(include/Game)
include_directories	(include/Map)
include_directories	(include/Interfaces)
include_directories	(include/Interfaces/Irrlicht)
include_directories	(include/Bonus)
include_directories	(include/Ia)
include_directories	(include/Save)
include_directories(cmake/SFML2/include)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")


if(WIN32)
	set(SHAREDIR ".")
	set(BINDIR "bin")
	set(CMAKE_CXX_FLAGS "-EHsc")
	set(SFML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/cmake/SFML2/lib/cmake/SFML")
	find_package(SFML 2.5.1 REQUIRED audio graphics system)



elseif(UNIX)
	set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}")
	set(SHAREDIR ".")
	set(BINDIR "bin")
	set(CMAKE_CXX_FLAGS "-W -Wextra -Werror")
	set(IRRLICHT_DEPENDENCIES Irrlicht X11 Xxf86vm pthread GL)
	set(SFML_AUDIO_DEPENDENCIES sfml-audio)
	install(DIRECTORY ${CMAKE_SOURCE_DIR}/cmake/lib/irrlicht-includes 
		DESTINATION /usr/include
		FILE_PERMISSIONS WORLD_READ WORLD_WRITE
	)
	install(FILES ${CMAKE_SOURCE_DIR}/cmake/lib/Unix/libIrrlicht.a
		DESTINATION /usr/lib
	)
	add_custom_target (fclean @echo cleaning for source distribution)
	add_custom_command(
		COMMENT "CLEAN DIRECTORY"
		COMMAND make
        # ARGS -C ${CMAKE_CURRENT_BINARY_DIR} clean
        COMMAND find
        ARGS ${CMAKE_CURRENT_BINARY_DIR} -name "CMakeCache.txt" | xargs rm -rf
        COMMAND find
        ARGS ${CMAKE_CURRENT_BINARY_DIR} -name "CMakeFiles" | xargs rm -rf
        COMMAND find
        # ARGS ${CMAKE_CURRENT_BINARY_DIR} -name "Makefile" | xargs rm -rf
        # COMMAND find
        ARGS ${CMAKE_CURRENT_BINARY_DIR} -name "*.cmake" | xargs rm -rf
        TARGET  fclean
	)
endif()

find_package(Irrlicht)

if(IRRLICHT_FOUND)
	message(STATUS "*** Irrlicht ***")
	
	if(WIN32)
		message(STATUS "WINOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoo")
		include_directories(${IRRLICHT_INCLUDE_DIR})
		target_link_libraries(bomberman
					${IRRLICHT_DEPENDENCIES}
					${IRRLICHT_LIBRARY}
					sfml-graphics 
					sfml-audio
					)
		file(COPY ${IRRLICHT_DLL} DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/")
		file(COPY ${IRRLICHT_LIBRARY} DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/")	
		file(COPY ${dll_sfml} DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/")
	else()
		include_directories(${IRRLICHT_INCLUDE_DIR})
		target_link_libraries(bomberman
					${IRRLICHT_DEPENDENCIES}
					${IRRLICHT_LIBRARY}
					${SFML_AUDIO_DEPENDENCIES}
					)
	endif()

	set_property		(TARGET bomberman PROPERTY CXX_STANDARD 11)
	message(STATUS "*** Successfully generated ALLAH's Bomberman project! ***")
else()
	message(WARNING "*** Irrlicht not found, build failed! ***")
endif()
include_directories(${IRRLICHT_INCLUDE_DIR})