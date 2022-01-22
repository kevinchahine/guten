cmake_minimum_required(VERSION 3.20)

set(LIBRARY_NAME "Guten")
project (${LIBRARY_NAME})

# --- Get name of each source file ---

set (BARS
	bars/BlockBar.cpp
	bars/BlockBar.h
	bars/ProgressBar.cpp
	bars/ProgressBar.h
)

set (BLOCKS
	blocks/BlockChar.cpp
	blocks/BlockChar.h
)

set (BOARDERS
	boarders/Boarder.cpp
	boarders/Boarder.h
)

set (BOARDS
	boards/CheckerBoard.cpp
	boards/CheckerBoard.h
)

set (COLOR
	color/ColorHelpers.cpp
	color/ColorHelpers.h
)

set (CORE
	core/Character.cpp
	core/Character.h
	core/ColoredChar.cpp
	core/ColoredChar.h
	core/helpers.cpp
	core/helpers.h
	core/Matrix.cpp
	core/Matrix.h
	core/Point.cpp
	core/Point.h
	core/Size.cpp
	core/Size.h
)

set (DRAW 
	draw/DrawFunctions.cpp
	draw/DrawFunctions.h
)

set (GLYPHS
	glyphs/Glyphs.cpp
	glyphs/Glyphs.h
	glyphs/Letter.cpp
	glyphs/Letter.h
)

set (LINES
	lines/LineChar.cpp
	lines/LineChar.h
)

set (SPINNERS
	spinners/FlatSpinner.cpp
	spinners/FlatSpinner.h
	spinners/LineSpinner.cpp
	spinners/LineSpinner.h
	spinners/SpinnerBase.cpp
	spinners/SpinnerBase.h
	spinners/spinners.hpp
)

set (VIEW
	view/AlignedView.cpp
	view/AlignedView.h
	view/ConstrainedLayout.cpp
	view/ConstrainedLayout.h
	view/GridView.cpp
	view/GridView.h
	view/HorizontalView.cpp
	view/HorizontalView.h
	view/LinearLayout.cpp
	view/LinearLayout.h
	view/RelativeLayout.cpp
	view/RelativeLayout.h
	view/TextView.cpp
	view/TextView.h
	view/VerticalView.cpp
	view/VerticalView.h
	view/View.cpp
	view/ViewGroup.cpp
	view/ViewGroup.h
	view/View.h
)

set (OTHER_FILES
	framework.h
	guten.hpp
	GutenExports.cpp
	GutenExports.h
	pch.cpp
	pch.h
)

# --- 3rd Party Libraries ---

find_package(Boost REQUIRED COMPONENTS
	#variant
)

message(STATUS "--- Boost ---")
message(STATUS "Include dirs ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost libraries ${Boost_LIBRARIES}")

#target_link_libraries(${LIBRARY_NAME} PUBLIC
#	#Boost::variant
#)

#target_include_directories(${LIBRARY_NAME} PUBLIC
#	${BOOST_INCLUDE_DIRS}
#)

# --- Combine Source files into a library ---

add_library(${LIBRARY_NAME} STATIC 
	${BARS}
	${BLOCKS}
	${BOARDERS}
	${BOARDS}
	${COLOR}
	${CORE}
	${DRAW}
	${GLYPHS}
	${LINES}
	${SPINNERS}
	${VIEW}
)
