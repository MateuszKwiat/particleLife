option(ENABLE_COVERAGE "Enable Clang coverage" OFF)

function(enable_clang_coverage target)

    if(NOT ENABLE_COVERAGE)
        return()
    endif()

    if(NOT CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
        message(FATAL_ERROR "Coverage requires Clang.")
    endif()

    target_compile_options(${target}
        PRIVATE
        -O0
        -g
        -fprofile-instr-generate
        -fcoverage-mapping
    )

    target_link_options(${target}
        PRIVATE
        -fprofile-instr-generate
    )

endfunction()
