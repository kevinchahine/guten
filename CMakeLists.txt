# --- Guten Library Project ---

cmake_minimum_required(VERSION 3.20)

set(LIBRARY_NAME "guten")
project (${LIBRARY_NAME})

# --- Set Preprocessor Macros ---
add_compile_definitions(GUTEN_EXPORTS)	# same as '#define GUTEN_EXPORTS'

# --- Get name of each source file ---

set (LIB_FILES
	guten/dllmain.cpp
	guten/framework.h
	guten/guten.hpp
	guten/GutenExports.h
	guten/GutenExports.cpp
	guten/pch.h
	guten/pch.cpp
)

set (BARS
	guten/bars/BlockBar.cpp
	guten/bars/BlockBar.h
	guten/bars/ProgressBar.cpp
	guten/bars/ProgressBar.h
)

set (BLOCKS
	guten/blocks/BlockChar.cpp
	guten/blocks/BlockChar.h
)

set (BOARDERS
	guten/boarders/Boarder.cpp
	guten/boarders/Boarder.h
)

set (BOARDS
	guten/boards/CheckerBoard.cpp
	guten/boards/CheckerBoard.h
)

set (COLOR
	guten/color/Color.h
	guten/color/Color.cpp
	guten/color/ColorHelpers.cpp
	guten/color/ColorHelpers.h
)

set (CORE
	guten/core/Character.cpp
	guten/core/Character.h
	guten/core/ColoredChar.cpp
	guten/core/ColoredChar.h
	guten/core/helpers.cpp
	guten/core/helpers.h
	guten/core/Matrix.cpp
	guten/core/Matrix.h
	guten/core/Point.cpp
	guten/core/Point.h
	guten/core/Size.cpp
	guten/core/Size.h
)

set (DRAW 
	guten/draw/DrawFunctions.cpp
	guten/draw/DrawFunctions.h
)

set (GLYPHS
	guten/glyphs/Glyphs.cpp
	guten/glyphs/Glyphs.h
	guten/glyphs/Letter.cpp
	guten/glyphs/Letter.h
)

set (LINES
	guten/lines/LineChar.cpp
	guten/lines/LineChar.h
)

set (SPINNERS
	guten/spinners/FlatSpinner.cpp
	guten/spinners/FlatSpinner.h
	guten/spinners/LineSpinner.cpp
	guten/spinners/LineSpinner.h
	guten/spinners/SpinnerBase.cpp
	guten/spinners/SpinnerBase.h
	guten/spinners/spinners.hpp
)

set (VIEW
	guten/view/AlignedView.cpp
	guten/view/AlignedView.h
	guten/view/ConstrainedLayout.cpp
	guten/view/ConstrainedLayout.h
	guten/view/GridView.cpp
	guten/view/GridView.h
	guten/view/HorizontalView.cpp
	guten/view/HorizontalView.h
	guten/view/LinearLayout.cpp
	guten/view/LinearLayout.h
	guten/view/RelativeLayout.cpp
	guten/view/RelativeLayout.h
	guten/view/TextView.cpp
	guten/view/TextView.h
	guten/view/VerticalView.cpp
	guten/view/VerticalView.h
	guten/view/View.cpp
	guten/view/ViewGroup.cpp
	guten/view/ViewGroup.h
	guten/view/View.h
)

set (OTHER_FILES
	guten/framework.h
	guten/guten.hpp
	guten/GutenExports.cpp
	guten/GutenExports.h
	guten/pch.cpp
	guten/pch.h
)

# --- Combine Source files into a library ---

add_library(${LIBRARY_NAME} STATIC 
	${LIB_FILES}
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

source_group(${LIBRARY_NAME} FILES ${LIB_FILES})
source_group(${LIBRARY_NAME} FILES ${BARS})
source_group(${LIBRARY_NAME} FILES ${BLOCKS})
source_group(${LIBRARY_NAME} FILES ${BOARDERS})
source_group(${LIBRARY_NAME} FILES ${BOARDS})
source_group(${LIBRARY_NAME} FILES ${COLOR})
source_group(${LIBRARY_NAME} FILES ${CORE})
source_group(${LIBRARY_NAME} FILES ${DRAW})
source_group(${LIBRARY_NAME} FILES ${GLYPHS})
source_group(${LIBRARY_NAME} FILES ${LINES})
source_group(${LIBRARY_NAME} FILES ${SPINNERS})
source_group(${LIBRARY_NAME} FILES ${VIEW})

target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
