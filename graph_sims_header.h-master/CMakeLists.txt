
cmake_minimum_required(VERSION 3.23)
project (graphe_sims C)

set(CMAKE_C_STANDARD 23)

add_executable(graphe_sims main.c graph_sims_fonctions.c graph_sims_header.h)

target_link_libraries(graphe_sims -lmingw32 -lalleg44)