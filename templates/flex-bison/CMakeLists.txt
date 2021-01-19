cmake_minimum_required(VERSION 3.0.0)
project(parser_template)

find_package(BISON)
find_package(FLEX)

BISON_TARGET(parser grammar.y ${CMAKE_CURRENT_BINARY_DIR}/parser.yy.c)
FLEX_TARGET(scanner lex.l ${CMAKE_CURRENT_BINARY_DIR}/parser.lex.c)
ADD_FLEX_BISON_DEPENDENCY(scanner parser)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(PARSER_SRC
	${BISON_parser_OUTPUTS}
	${FLEX_scanner_OUTPUTS}
	main.c
)

add_executable(parser ${PARSER_SRC})
