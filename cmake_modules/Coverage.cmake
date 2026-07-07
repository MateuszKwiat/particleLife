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

function(add_coverage_target)

    if(ENABLE_COVERAGE)

        execute_process(
            COMMAND xcrun --find llvm-profdata
            OUTPUT_VARIABLE LLVM_PROFDATA
            OUTPUT_STRIP_TRAILING_WHITESPACE
        )

        execute_process(
            COMMAND xcrun --find llvm-cov
            OUTPUT_VARIABLE LLVM_COV
            OUTPUT_STRIP_TRAILING_WHITESPACE
        )

        add_custom_target(coverage
            COMMAND ${CMAKE_COMMAND} -E env
                LLVM_PROFILE_FILE=coverage.profraw
                $<TARGET_FILE:unit_tests>

            COMMAND ${LLVM_PROFDATA}
                merge
                -sparse
                coverage.profraw
                -o coverage.profdata
            
            COMMAND ${LLVM_COV}
                show
                $<TARGET_FILE:unit_tests>
                -instr-profile=coverage.profdata
                -format=html
                -output-dir=coverage

            DEPENDS unit_tests

            WORKING_DIRECTORY ${CMAKE_BINARY_DIR}

            COMMENT "Generating coverage report"
        )

    endif()

endfunction()