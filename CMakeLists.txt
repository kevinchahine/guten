cmake_minimum_required(VERSION 3.20)

# --- Set project name to GutenDriver ---
set(PROJECT_NAME "GutenDriver")
project(${PROJECT_NAME})

add_subdirectory(Guten)

# --- Specify Header Files ---
set(SOURCE_FILES
	${PROJECT_NAME}/Source.cpp
	${PROJECT_NAME}/examples_boarders.cpp
	${PROJECT_NAME}/examples_boarders.h
	${PROJECT_NAME}/examples_checker_board.cpp
	${PROJECT_NAME}/examples_checker_board.h
	${PROJECT_NAME}/examples.cpp
	${PROJECT_NAME}/examples_draw_functions.cpp
	${PROJECT_NAME}/examples_draw_functions.h
	${PROJECT_NAME}/examples_glyphs.cpp
	${PROJECT_NAME}/examples_glyphs.h
	${PROJECT_NAME}/examples.h
	${PROJECT_NAME}/examples_progress_bar.cpp
	${PROJECT_NAME}/examples_progress_bar.h
)

set(TEXT_FILES
	${PROJECT_NAME}/DrawFunctions.txt
	${PROJECT_NAME}/Letters.txt
	${PROJECT_NAME}/Matrix.txt
	${PROJECT_NAME}/ProgressBars.txt
	${PROJECT_NAME}/termcolor.txt
)

# --- Establish the executable and specify which files will be used to create it ---
add_executable(${PROJECT_NAME}
	${SOURCE_FILES}
	${TEXT_FILES}
)	

# --- Link Libraries ---
target_link_libraries(${PROJECT_NAME} PUBLIC
	Guten
)

target_include_directories(${PROJECT_NAME} PUBLIC
	../Guten/
)

