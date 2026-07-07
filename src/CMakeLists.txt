# Core lib
set(CORE_HEADER_LIST "${particleLife_SOURCE_DIR}/include/particleLife/core/temp.hpp")

add_library(core_library 
            core/temp.cpp 
            ${CORE_HEADER_LIST})

target_include_directories(core_library PUBLIC ../include)
target_compile_features(core_library PUBLIC cxx_std_23)
enable_clang_coverage(core_library)

# Render lib
set(RENDER_HEADER_LIST "${particleLife_SOURCE_DIR}/include/particleLife/render/temp1.hpp")

add_library(render_library
            render/temp1.cpp
            ${RENDER_HEADER_LIST})

target_include_directories(render_library PUBLIC ../include)
target_compile_features(render_library PUBLIC cxx_std_23)
enable_clang_coverage(render_library)

# UI lib
set(UI_HEADER_LIST "${particleLife_SOURCE_DIR}/include/particleLife/ui/temp2.hpp")

add_library(ui_library
            ui/temp2.cpp
            ${UI_HEADER_LIST})

target_include_directories(ui_library PUBLIC ../include)
target_compile_features(ui_library PUBLIC cxx_std_23)
enable_clang_coverage(ui_library)