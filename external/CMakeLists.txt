include(FetchContent)

FetchContent_Declare(
    google_test
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.0
)
FetchContent_MakeAvailable(google_test)
